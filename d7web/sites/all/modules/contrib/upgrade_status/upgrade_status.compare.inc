<?php

/**
 * @file
 * Code required only when comparing available updates to existing data.
 */

include_once 'lib/vendor/autoload.php';
module_load_include('inc', 'update', 'update.compare');

use Composer\Semver\Semver;

/**
 * Calculates the current update status of all projects on the site.
 *
 * The results of this function are expensive to compute, especially on sites
 * with lots of modules or themes, since it involves a lot of comparisons and
 * other operations. Therefore, we cache the results into the {cache_update}
 * table using the 'update_project_data' cache ID. However, since this is not
 * the data about available updates fetched from the network, it is ok to
 * invalidate it somewhat quickly. If we keep this data for very long, site
 * administrators are more likely to see incorrect results if they upgrade to a
 * newer version of a module or theme but do not visit certain pages that
 * automatically clear this cache.
 *
 * @param array $available
 *   Data about available project releases.
 *
 * @return
 *   An array of installed projects with current update status information.
 *
 * @see upgrade_status_get_available()
 * @see update_get_projects()
 * @see update_process_project_info()
 * @see update_project_cache()
 */
function upgrade_status_calculate_project_data($available) {
  // Retrieve the projects from cache, if present.
#  $projects = update_project_cache('upgrade_status_project_data');
  // US: Directly use private cache getter to skip Update's cache invalidation.
  $projects = _update_cache_get('upgrade_status_project_data');
  // If $projects is empty, then the cache must be rebuilt.
  // Otherwise, return the cached data and skip the rest of the function.
  if (!empty($projects)) {
    // US: Return only the data part, not entire $projects array.
    return $projects->data;
  }
  $projects = update_get_projects();

  // US: Handle obsolete projects.
  foreach ($projects as $key => $project) {
    if (upgrade_status_obsolete($projects, $key)) {
      // Add the project that makes this one obsolete to the list of those to
      // grab information about.
      foreach ($projects[$key]['replaced_by'] as $replacement) {
        $projects[$replacement['name']] = $available[$replacement['name']];
        $projects[$replacement['name']]['info'] = array();
      }
    }
  }

  update_process_project_info($projects);
  foreach ($projects as $project => $project_info) {
    if (isset($available[$project])) {
      upgrade_status_calculate_project_update_status($project, $projects[$project], $available[$project]);
    }
    // US: Check if the project is obsolete.
    elseif (upgrade_status_obsolete($projects, $project)) {
      $projects[$project]['status'] = UPGRADE_STATUS_OBSOLETE;
      $projects[$project]['reason'] = t('Made obsolete by');
    }
    else {
      $projects[$project]['status'] = UPDATE_UNKNOWN;
      $projects[$project]['reason'] = t('No available releases found');
    }
  }
  // Give other modules a chance to alter the status (for example, to allow a
  // contrib module to provide fine-grained settings to ignore specific
  // projects or releases).
  drupal_alter('update_status', $projects);

  // US: Same for us, afterwards.
  drupal_alter('upgrade_status', $projects);

  // Cache the site's update status for at most 1 hour.
  _update_cache_set('upgrade_status_project_data', $projects, REQUEST_TIME + 3600);
  return $projects;
}

/**
 * Calculates the current upgrade status of a specific project.
 *
 * @param string $project
 *   Project name to check.
 * @param array $project_data
 *   An array containing information about a specific project.
 * @param array $available
 *   Data about available project releases of a specific project.
 */
function upgrade_status_calculate_project_update_status($project, &$project_data, $available) {
  foreach (array('title', 'link') as $attribute) {
    if (!isset($project_data[$attribute]) && isset($available[$attribute])) {
      $project_data[$attribute] = $available[$attribute];
    }
  }

  // If the project status is marked as something bad, there's nothing else
  // to consider.
  if (isset($available['project_status'])) {
    switch ($available['project_status']) {
      case 'insecure':
        $project_data['status'] = UPDATE_NOT_SECURE;
        if (empty($project_data['extra'])) {
          $project_data['extra'] = array();
        }
        $project_data['extra'][] = array(
          'class' => array('project-not-secure'),
          'label' => t('Project not secure'),
          'data' => t('This project has been labeled insecure by the Drupal security team, and is no longer available for download. Immediately disabling everything included by this project is strongly recommended!'),
        );
        break;
      // US: Maintainers are doing lots of nightmares with in development
      // releases, so we have to take unpublished, revoked, and unsupported
      // into account.
      case 'unpublished':
      case 'revoked':
      case 'unsupported':
        break;
      case 'not-fetched':
        $project_data['status'] = UPDATE_NOT_FETCHED;
        $project_data['reason'] = t('Failed to get available update data.');
        break;

      default:
        // Assume anything else (e.g. 'published') is valid and we should
        // perform the rest of the logic in this function.
        break;
    }
  }

  if (!empty($project_data['status'])) {
    // We already know the status for this project, so there's nothing else to
    // compute. Record the project status into $project_data and we're done.
    $project_data['project_status'] = $available['project_status'];
    return;
  }

  // If the project is marked as UPDATE_FETCH_PENDING, it means that the
  // data we currently have (if any) is stale, and we've got a task queued
  // up to (re)fetch the data. In that case, we mark it as such, merge in
  // whatever data we have (e.g. project title and link), and move on.
  if (!empty($available['fetch_status']) && $available['fetch_status'] == UPDATE_FETCH_PENDING) {
    $project_data['status'] = UPDATE_FETCH_PENDING;
    $project_data['reason'] = t('No available update data');
    $project_data['fetch_status'] = $available['fetch_status'];
  }

  if (empty($available['releases'])) {
    $available['releases'] = array();
  }

  $target_core = variable_get('upgrade_status_core_version', UPGRADE_STATUS_CORE_VERSION);
  $target_core_contrib = str_replace('x', '100', $target_core);
  $target_core_core = str_replace('.x', '', $target_core);
  foreach ($available['releases'] as $version => $release) {
    if ($project == 'drupal') {
      // Core versions are matched from the version value directly.
      if (!Semver::satisfies($release['version'], '~' . $target_core_core)) {
        continue;
      }
    }
    elseif (empty($release['core_compatibility']) || !Semver::satisfies($target_core_contrib, $release['core_compatibility'])) {
      // Contrib versions are matched from core_compatibility.
      continue;
    }
    $project_data['releases'][$version] = $release;

     if (!strpos($release['version'], '-dev') && !strpos($release['version'], '-alpha') && !strpos($release['version'], '-beta') && !isset($project_data['recommended'])) {
      // Latest compatible RC or stable version is considered recommended.
      $project_data['recommended'] = $version;
    }

    // Look for the 'latest version' if we haven't found it yet. Latest is
    // defined as the most recent version for the target major version.
    if (!isset($project_data['latest_version'])) {
      $project_data['latest_version'] = $version;
    }
  }

  // If we were unable to find a recommended version, then make the latest
  // version the recommended version, if we have one.
  if (!isset($project_data['recommended']) && isset($project_data['latest_version'])) {
    $project_data['recommended'] = $project_data['latest_version'];
    // US: No recommended version means there's a dev snapshot.
    $project_data['status'] = UPGRADE_STATUS_DEVELOPMENT;
    $project_data['reason'] = t('In development');
  }

  if (!isset($project_data['recommended'])) {
    $project_data['status'] = UPGRADE_STATUS_UNAVAILABLE;
    $project_data['reason'] = t('No compatible release. Yet(?)');
  }

  //
  // Check to see if we need an update or not.
  //

  // US: Skip security update status handling.

  // US: Check new Drupal core improvements, regardless of what's figured out
  // below.
  if (upgrade_status_moved_into_core($projects, $project)) {
    $project_data += $projects[$project];
    $project_data['status'] = UPGRADE_STATUS_CORE;
    $project_data['reason'] = t('In core');
  }

  if (isset($project_data['status'])) {
    // If we already know the status, we're done.
    return;
  }

  // If we don't know what to recommend, there's nothing we can report.
  // Bail out early.
  // US: Commenting this out causes core to work again. Hm.
#  if (!isset($project_data['recommended'])) {
#    $project_data['status'] = UPDATE_UNKNOWN;
#    $project_data['reason'] = t('No available releases found');
#    return;
#  }

  // US: Ignore dev snapshot handling.

  // Figure out the status, based on what we've seen and the install type.
  // US: If we were not yet able to assign a status, this project already
  // provides a stable release, so remove handling of official and dev releases.
  switch ($project_data['install_type']) {
    case 'official':
    case 'dev':
      $project_data['status'] = UPGRADE_STATUS_STABLE;
      $project_data['reason'] = t('Available');
      break;

    default:
      // US: A project without releases may be in core.
      if (upgrade_status_moved_into_core($projects, $project)) {
        $project_data['status'] = UPGRADE_STATUS_CORE;
        $project_data['reason'] = t('In core');
      }
      else {
        $project_data['status'] = UPDATE_UNKNOWN;
        $project_data['reason'] = t('Invalid info');
      }
  }
}

/**
 * Return status and notice about modules that have been made obsolete.
 *
 * Assign custom upgrade information for certain modules.
 *
 * @param array $projects
 *   Array of projects from upgrade_status_calculate_project_data().
 * @param string $project
 *   Project name to check.
 * @return
 *   TRUE if module has been made obsolete by an alternative.
 */
function upgrade_status_obsolete(&$projects, $project) {
  $obsolete = TRUE;

  switch ($project) {
    case 'addressfield':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'address';
      break;

    case 'admin_menu':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'admin_toolbar';
      break;

    case 'auto_nodetitle':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'auto_entitylabel';
      break;

    case 'better_formats':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'allowed_formats';
      break;

    case 'bundle_copy':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'field_tools';
      break;

    case 'calendar':
    case 'fullcalendar':
    case 'fullcalendar_create':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'fullcalendar_view';
      break;

    case 'cnr':
    case 'nodereferrer':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'cer';
      break;

    case 'colors':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'colorapi';
      break;

    case 'data_export_import':
    case 'node_export':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'content_sync';
      break;

    case 'ddf':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'conditional_fields';
      $projects[$project]['replaced_by'][1]['name'] = 'business_rules';
      $projects[$project]['replaced_by'][2]['name'] = 'field_states_ui';
      $projects[$project]['replaced_by'][3]['name'] = 'fico';
      break;

    case 'editableviews':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'views_entity_form_field';
      break;

    case 'entityreference_filter':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'verf';
      break;

    case 'entityreference_prepopulate':
    case 'nodereference_url':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'prepopulate';
      $projects[$project]['replaced_by'][1]['name'] = 'referer_to_entity_reference';
      break;

    case 'entityreference_view_widget':
    case 'references_dialog':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'entity_browser';
      $projects[$project]['replaced_by'][1]['name'] = 'inline_entity_form';
      $projects[$project]['replaced_by'][2]['name'] = 'entityconnect';
      break;

    case 'facetapi':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'facets';
      break;

    case 'field_collection':
    case 'field_collection_views':
    case 'multifield':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'paragraphs';
      break;

    case 'field_conditional_state':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'conditional_fields';
      break;

    case 'form_save':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'hotkeys_for_save';
      break;

    case 'global_filter':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'simple_global_filter';
      break;

    case 'google_chart_tools':
    case 'charts_graphs':
    case 'charts_graphs_flot':
    case 'highcharts':
    case 'visualization':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'charts';
      break;

    case 'hierarchical_select':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'cshs';
      $projects[$project]['replaced_by'][1]['name'] = 'menu_link_weight';
      $projects[$project]['replaced_by'][2]['name'] = 'shs';
      break;

    case 'jqeasing':
    case 'jquery_plugin':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'libraries';
      break;

    case 'location':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'address';
      $projects[$project]['replaced_by'][1]['name'] = 'geofield';
      $projects[$project]['replaced_by'][2]['name'] = 'geocoder';
      $projects[$project]['replaced_by'][3]['name'] = 'geolocation';
      break;

    case 'megamenu':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'menu_item_extras';
      $projects[$project]['replaced_by'][1]['name'] = 'we_megamenu';
      $projects[$project]['replaced_by'][2]['name'] = 'tb_megamenu';
      $projects[$project]['replaced_by'][3]['name'] = 'ultimenu';
      $projects[$project]['replaced_by'][4]['name'] = 'simple_megamenu';
      break;

    case 'messaging':
    case 'notifications':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'courier';
      break;

    case 'menu_item_visibility':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'menu_link_content_visibility';
      break;

    case 'node_convert':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'convert_bundles';
      break;

    case 'node_clone':
    case 'replicate':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'entity_clone';
      break;

    case 'nodeaccess_userreference':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'access_by_ref';
      break;

    case 'og':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'group';
      break;

    case 'panels_extra_styles':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'panels_extra_styles_d8';
      break;

    case 'print':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'entity_print';
      $projects[$project]['replaced_by'][1]['name'] = 'printable';
      break;

    case 'responsive_dropdown_menus':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'responsive_menu';
      break;

    case 'search_api_db':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'search_api';
      break;

    case 'taxonomy_csv':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'term_csv_export_import';
      $projects[$project]['replaced_by'][1]['name'] = 'taxonomy_manager';
      $projects[$project]['replaced_by'][2]['name'] = 'migrate_source_csv';
      $projects[$project]['replaced_by'][3]['name'] = 'taxonomy_import';
      $projects[$project]['replaced_by'][4]['name'] = 'hti';
      $projects[$project]['replaced_by'][5]['name'] = 'term_csv_tree_import';
      break;

    case 'textformatter':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'list_formatter';
      break;

    case 'track_field_changes':
    case 'nodechanges':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'changed_fields';
      break;

    case 'user_dashboard':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'homebox';
      break;

    case 'views_arguments_extras':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'views_arg_order_sort';
      break;

    case 'views_export_xls':
    case 'views_data_export_phpexcel':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'xls_serialization';
      $projects[$project]['replaced_by'][1]['name'] = 'vbo_export';
      break;

    case 'wikitools':
      $projects[$project]['obsolete_since'] = '8.x';
      $projects[$project]['replaced_by'][0]['name'] = 'freelinking';
      break;

    default:
      $obsolete = FALSE;
  }

  return $obsolete;
}

/**
 * Return status and notice about modules moved into Core.
 *
 * Assign custom upgrade information for certain modules.
 *
 * @param array $projects
 *   Array of projects from upgrade_status_calculate_project_data(). This
 *   parameter is passed by reference, and metadata for the project can added
 *   to the $projects[$project] array for use later. Three additional keys are
 *   supported:
 *   - in_core_since: The major version since which the module is in core.
 *   - in_core_complete: Boolean flag indicating whether the complete
 *     functionality of the project is in core. Set this to FALSE when the core
 *     replacement does not include the full functionality of the project.
 *   - in_core_note: Note to display to the user. This should be succinct and
 *     describe:
 *     - What core module or API replaces the project, if the module was not
 *       moved directly into core with the same name.
 *     - What functionality of the project is not included in core, if the
 *       'in_core_complete' flag is false.
 * @param string $project
 *   Project name to check.
 *
 * @return
 *   TRUE if module has been moved into core.
 */
function upgrade_status_moved_into_core(&$projects, $project) {

  // Only include in core statuses for the configured major version and below.
  // Set the oldest version's data first, so that the latest version of core may
  // update the previous version's information.
  // @todo What about modules moved into core and then back out?
  $core_version = variable_get('upgrade_status_core_version', UPGRADE_STATUS_CORE_VERSION);

  switch ($core_version) {
    case '8.9.x':
    case '9.5.x':
    case '10.0.x':
      return _upgrade_status_d8_core($projects, $project);
      break;
  }

  return $core;
}

/**
 * Modules in core in Drupal 8.
 *
 * @see upgrades_status_moved_into_core()
 */
function _upgrade_status_d8_core(&$projects, $project) {

  // Specifying a case for the module in this switch statement will mark it as
  // included in core on the status report.
  $core = TRUE;
  switch ($project) {

    case 'admin_language':
    case 'entity_translation':
    case 'fallback_language_negotiation':
    case 'i18n':
    case 'i18nviews':
    case 'l10n_install':
    case 'l10n_update':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by core localization functionality, the core Language module, and the core Configuration, Content, and Interface Translation modules.');
      break;

    case 'admin_views':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('Integrated with the core Views module.');
      break;

    case 'bean':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by the core Custom Block module.');
      break;

    case 'breakpoint':
    case 'breakpoints':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'cachetags':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by core APIs.');
      break;

    case 'caption_filter':
    case 'float_filter':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by functionality in the core Editor module.');
      break;

    case 'ckeditor':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'ctools':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('Mostly replaced by core APIs, including modal dialogs, exportables, and plugins. Excludes <a href="@url">Page Manager</a> and Form Wizard.', array(
        '@url' => 'https://www.drupal.org/project/page_manager',
      ));
      break;

    case 'date':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('No recurring dates support. See <a href="@extras">Datetime Extras: Provide a field for repeating / recuring dates</a> and <a href="@field">Recurring Dates Field</a>', array(
        '@extras' => 'https://www.drupal.org/project/datetime_extras/issues/2775249',
        '@field' => 'https://www.drupal.org/project/date_recur',
      ));
      break;

    case 'date_popup_authored':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'edit':
    case 'quickedit':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'email':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('E-mail address contact forms are not supported by core.');
      break;

    case 'entityreference':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'entity':
    case 'entity_view_mode':
    case 'file_entity':
    case 'title':
    case 'user_picture_field':
    case 'uuid':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by core Entity system functionality.');
      break;

    case 'features':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('The original intended functionality of the Features module is not provided by core, but the core Configuration system provides support for importing, exporting, and overriding site configuration.');
      break;

    case 'field_extrawidgets':
    case 'hidden_field':
    case 'field_hidden':
    case 'hidden_widget':
    case 'formfilter':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('Fields can be hidden natively from the Form Display configuration. To make fields read-only, use the <a href="@url">Read-only Field Widget</a> module.', array(
        '@url' => 'https://www.drupal.org/project/readonly_field_widget',
      ));
      break;

    case 'field_formatter_settings':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'fieldable_panels_panes':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('Custom block types provide all of the functionality that is necessary.');
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'link':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('No support for internal links.');
      break;

    case 'migrate':
    case 'migrate_d2d':
    case 'migrate_drupal':
      $projects[$project]['in_core_since'] = '8.x';
      break;

    case 'module_filter':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('A search functionality is included on the core modules page. The re-designed modules page in the 2.x branch is not in core.');
      break;

    case 'navbar':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by the updated core Toolbar module.');
      break;

    case 'options_element':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Taxonomy Term Reference fields have much better usability with fewer drawbacks.');
      break;

    case 'panels':
    case 'panelizer':
      $projects[$project]['in_core_since'] = '8.5';
      $projects[$project]['in_core_complete'] = TRUE;
       $projects[$project]['in_core_note'] = t('Use the Layout Builder core module.');
      break;

    case 'phone':
    case 'telephone':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'picture':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by the core Responsive Image module.');
      break;

    case 'elements':
    case 'placeholder':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by HTML5 form API functionality.');
      break;

    case 'references':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'restws':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by the core REST module.');
      break;

    case 'schemaorg':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('The default RDF mappings of Drupal core have been updated to include schema.org in Drupal 8. Also, a lot of the backend code of this module was ported into Drupal 8 core. The user interface that allows one to set the mappings now lives in the <a href="@url">RDF UI</a> module.', array(
        '@url' => 'https://www.drupal.org/project/rdfui',
      ));
      break;

    case 'services':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('The core REST module provides most of the functionality from previous versions of the Services module. JSON API is also supported in core.');
      break;

    case 'stringoverrides':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('The core Interface Translation module allows custom translations to be provided for strings in any language, including English.');
      break;

    case 'transliteration':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('Replaced by core APIs. No direct support for transliterating path aliases or file names.');
      break;

    case 'variable':
    case 'defaultconfig':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Replaced by the core Configuration system.');
      break;

    case 'views':
    case 'extra_columns':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'views_bulk_operations':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('The core Views module provides bulk operations on simple actions only. No support for batch operations or configurable actions.');
      break;

    case 'views_datasource':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('The basic functionality is in core, but some advanced features (such as outputting a Views attachment as JSON) are not.');
      break;

    case 'views_between_dates_filter':
      $projects[$project]['in_core_since'] = '8.6';
      $projects[$project]['in_core_note'] = t('While <a href="@change_record">Views integration for the Datetime Range module</a> is now in core, <a href="@granularity">Views Date Filter Datetime Granularity Option</a> is still missing.', array(
        '@change_record' => 'https://www.drupal.org/node/2857691',
        '@granularity' => 'https://www.drupal.org/project/drupal/issues/2868014',
      ));
      break;

    case 'views_filters_populate':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('When adding a filter, select Combine Fields Filter from the Global category.');
      break;

    case 'views_responsive_grid':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('This module will not be ported to Drupal 8. Views grids in core have been replaced with DIVs.');
      break;

    case 'wysiwyg':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('API support added to the core "Editor" module. No support for multiple text editors per text format.');
      break;

    case 'workflow':
    case 'revisioning':
    case 'workbench_files':
    case 'workbench_media':
    case 'workbench_moderation':
      $projects[$project]['in_core_since'] = '8.5';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('See the <a href="@url">Content Moderation documentation</a>.', array(
        '@url' => 'https://www.drupal.org/docs/8/core/modules/content-moderation/overview',
      ));
      break;

    case 'workspace':
      $projects[$project]['in_core_since'] = '8.6';
      $projects[$project]['in_core_note'] = t('Renamed to <a href="@workspaces">Workspaces</a>.', array(
        '@workspaces' => 'https://www.drupal.org/node/2968491',
      ));
      break;

    case 'wysiwyg_filter':
      $projects[$project]['in_core_since'] = '8.0';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('See the <a href="@url">Text Editor documentation</a>.', array(
        '@url' => 'https://www.drupal.org/docs/8/core/modules/editor/overview',
      ));
      break;

    case 'advuser':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'content_dependency':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      $projects[$project]['in_core_note'] = t('Use the Relationship feature in Views.');
      break;

    case 'ife':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'jquery_update':
    case 'jqmulti':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_note'] = t('No longer needed in Drupal 8 onwards, which ships with the latest version of the library. The shipped version is updated, with backwards compatibility, in minor releases.');
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'media':
      $projects[$project]['in_core_since'] = '8.4';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    case 'multiupload_filefield_widget':
      $projects[$project]['in_core_since'] = '8.x';
      $projects[$project]['in_core_complete'] = TRUE;
      break;

    default:
      // Any other module is not included in core.
      $core = FALSE;
  }
  return $core;
}
