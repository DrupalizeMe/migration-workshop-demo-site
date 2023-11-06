<?php

/**
 * @file
 * Code required only when rendering the available updates report.
 */

module_load_include('inc', 'update', 'update.report');

/**
 * Page callback: Generates a page about the update status of projects.
 *
 * @see upgrade_status_menu()
 */
function upgrade_status_status() {
  // US: Don't pass TRUE to check cache only.
  if ($available = upgrade_status_get_available()) {
    module_load_include('inc', 'upgrade_status', 'upgrade_status.compare');
    $data = upgrade_status_calculate_project_data($available);
    return theme('upgrade_status_report', array('data' => $data));
  }
  else {
    // US: Inlined _update_no_data().
    // @todo: File an upstream patch for that.
    $destination = drupal_get_destination();
    $data = t('No upgrade information available.');
    return theme('upgrade_status_report', array('data' => $data));
  }
}

/**
 * Returns HTML for the project status report.
 *
 * @param array $variables
 *   An associative array containing:
 *   - data: An array of data about each project's status.
 *
 * @ingroup themeable
 */
function theme_upgrade_status_report($variables) {
  $data = $variables['data'];

  // US: Load Update module's data as a fallback in case there is no release info
  // for a project (so we can link to the project).
  $current_data = update_get_available(TRUE);

  // US: Add the core version selector form.
  $form = drupal_get_form('upgrade_status_core_version_form');
  $output = drupal_render($form);

  if (!is_array($data)) {
    $output .= '<p>' . $data . '</p>';
    return $output;
  }

  $header = array(t('Project'), t('Current version'), t('Latest upgrade available'));
  $rows = array();

  // US: We don't do anything with notifications in this module.
#  $notification_level = variable_get('update_notification_threshold', 'all');

  // Create an array of status values keyed by module or theme name, since
  // we'll need this while generating the report if we have to cross reference
  // anything (e.g. subthemes which have base themes missing an update).
  foreach ($data as $project) {
    if (empty($project['includes'])){
      $project['includes'] = array();
    }
    foreach ($project['includes'] as $key => $name) {
      $status[$key] = $project['status'];
    }
  }

  foreach ($data as $project) {
    // Handle projects with no includes element.
    if (empty($project['includes'])){
      $project['includes'] = array();
    }

    // Skip this module.
    if ($project['name'] == 'upgrade_status') {
      continue;
    }

    switch ($project['status']) {
      // US: Stable releases and projects moved into core are also good news.
      case UPDATE_CURRENT:
      case UPGRADE_STATUS_STABLE:
      case UPGRADE_STATUS_CORE:
      // @todo: Colour obsolete modules according to their replacement project
      // info in $data.
      case UPGRADE_STATUS_OBSOLETE:
        $class = 'ok';
        break;
      case UPDATE_UNKNOWN:
      case UPDATE_FETCH_PENDING:
      case UPDATE_NOT_FETCHED:
        $class = 'unknown';
        break;
      // US: Not used/not possible here.
      case UPDATE_NOT_SECURE:
      case UPDATE_REVOKED:
      case UPDATE_NOT_SUPPORTED:
      case UPGRADE_STATUS_UNAVAILABLE:
        $class = 'error';
        break;
      // US: It doesn't make sense to output a whole page of warning symbols,
      // so we just colorize as a warning without the icon. This allows us to
      // warn about projects moved into core and other important info.
      case UPGRADE_STATUS_DEVELOPMENT:
        $class = 'warning';
        break;
      case UPGRADE_STATUS_OBSOLETE:
        break;

      case UPDATE_NOT_CHECKED:
      case UPDATE_NOT_CURRENT:
      default:
        $class = 'warning';
        break;
    }

    $row = [];

    // PROJECT NAME ------------------------------------------------------------
    $project_label = '<strong>';
    if (isset($project['title'])) {
      if (isset($project['link'])) {
        $project_label .= l($project['title'], $project['link']);
      }
      else {
        $project_label .= check_plain($project['title']);
      }
    }
    // US: Couldn't find this project's data for the next version of Drupal core.
    // Let's try the current one instead.
    elseif (isset($current_data[$project['name']]) && isset($current_data[$project['name']]['title'])) {
      if (isset($current_data[$project['name']]['link'])) {
        $project_label .= l($current_data[$project['name']]['title'], $current_data[$project['name']]['link']);
      }
      else {
        $project_label .= check_plain($current_data[$project['name']]['title']);
      }
    }
    // Otherwise, just print the name.
    else {
      $project_label .= check_plain($project['name']);
    }
    $project_label .= '</strong>';

    $project_label .= '<div class="includes">';
    if (!empty($project['disabled'])) {
      sort($project['disabled']);
      // Make sure we start with a clean slate for each project in the report.
      $includes_items = array();
      $project_label .= t('Includes:');
      $includes_items[] = t('Enabled: %includes', array('%includes' => implode(', ', $project['includes'])));
      $includes_items[] = t('Disabled: %disabled', array('%disabled' => implode(', ', $project['disabled'])));
      $project_label .= theme('item_list', array('items' => $includes_items));
    }
    else {
      sort($project['includes']);
      $project_label .= t('Includes: %includes', array('%includes' => implode(', ', $project['includes'])));
    }
    $project_label .= "</div>\n";

    if (!empty($project['base_themes'])) {
      $project_label .= '<div class="basethemes">';
      asort($project['base_themes']);
      $base_themes = array();
      foreach ($project['base_themes'] as $base_key => $base_theme) {
        switch ($status[$base_key]) {
          case UPDATE_NOT_SECURE:
          case UPDATE_REVOKED:
          case UPDATE_NOT_SUPPORTED:
            $base_themes[] = t('%base_theme (!base_label)', array('%base_theme' => $base_theme, '!base_label' => theme('upgrade_status_status_label', array('status' => $status[$base_key]))));
            break;

          default:
            $base_themes[] = drupal_placeholder($base_theme);
        }
      }
      $project_label .= t('Depends on: !basethemes', array('!basethemes' => implode(', ', $base_themes)));
      $project_label .= "</div>\n";
    }
    if (!empty($project['sub_themes'])) {
      $project_label .= '<div class="subthemes">';
      sort($project['sub_themes']);
      $project_label .= t('Required by: %subthemes', array('%subthemes' => implode(', ', $project['sub_themes'])));
      $project_label .= "</div>\n";
    }
    $row[] = $project_label;

    // EXISTING VERSION --------------------------------------------------------
    $existing_version = check_plain($project['existing_version']);
    if ($project['install_type'] == 'dev' && !empty($project['datestamp'])) {
      $existing_version .= ' (' . format_date($project['datestamp'], 'custom', 'Y-M-d') . ')';
    }
    $row[] = $existing_version;

    // UPGRADE STATUS ----------------------------------------------------------
    $upgrade_status = !empty($project['reason']) ? $project['reason'] : t('Unknown');
    if (!empty($project['in_core_since'])) {
      $upgrade_status = '<p>'. t('In Drupal core since @version', array('@version' => $project['in_core_since'])) .'</p>';
      if (!empty($project['in_core_note'])) {
        $upgrade_status .= '<p>'. $project['in_core_note'] .'</p>';
      }
    }
    elseif (isset($project['replaced_by'])) {
      $replacements = array();
      foreach ($project['replaced_by'] as $replacement) {
        $replacements[] = t('!name @version', array('!name' => l($data[$replacement['name']]['title'], $data[$replacement['name']]['link']), '@version' => $data[$replacement['name']]['recommended']));
      }
      $replaced = implode(', ', $replacements);
      $upgrade_status = t('Replaced by: !replaced', array('!replaced' => $replaced));
    }
    elseif (isset($project['recommended'])) {
      $upgrade_status = $project['recommended'];
    }
    $row[] = $upgrade_status;

    if (!isset($rows[$project['project_type']])) {
      $rows[$project['project_type']] = array();
    }
    $row_key = isset($project['title']) ? drupal_strtolower($project['title']) : drupal_strtolower($project['name']);
    $rows[$project['project_type']][$row_key] = array(
      'class' => array($class),
      'data' => $row,
    );
  }

  $project_types = array(
    'core' => t('Drupal core'),
    'module' => t('Modules'),
    'theme' => t('Themes'),
    'module-disabled' => t('Disabled modules'),
    'theme-disabled' => t('Disabled themes'),
  );
  foreach ($project_types as $type_name => $type_label) {
    if (!empty($rows[$type_name])) {
      ksort($rows[$type_name]);
      $output .= "\n<h3>" . $type_label . "</h3>\n";
       $output .= theme('table', ['header' => $header, 'rows' => $rows[$type_name], 'attributes' => ['class' => ['upgrade-status-table']]]);
    }
  }
  drupal_add_css(drupal_get_path('module', 'update') . '/update.css');
  drupal_add_css(drupal_get_path('module', 'upgrade_status') . '/upgrade_status.css');
  return $output;
}

/**
 * Returns HTML for a label to display for a project's update status.
 *
 * @param array $variables
 *   An associative array containing:
 *   - status: The integer code for a project's current update status.
 *   // US: Add project data as well so we can determine type of release.
 *   // @todo File upstream patch?
 *   - project: Project data.
 *
 * @see update_calculate_project_data()
 * @ingroup themeable
 */
function theme_upgrade_status_status_label($variables) {
  $project = $variables['project'];

  switch ($variables['status']) {
    // US: Not applicable.
#    case UPDATE_NOT_SECURE:
#      return '<span class="security-error">' . t('Security update required!') . '</span>';

    // US: Not applicable.
#    case UPDATE_REVOKED:
#      return '<span class="revoked">' . t('Revoked!') . '</span>';

    // Although unsupported releases should actually be unsupported, we treat
    // them like development releases, since many maintainers merely use this
    // additional flag to hide the release from novice Drupal users.
    case UPGRADE_STATUS_DEVELOPMENT:
    case UPDATE_NOT_SUPPORTED:
#      return '<span class="not-supported">' . t('Not supported!') . '</span>';
      // US: Additionally output the "development stage" of a project; alpha,
      // beta, and RC are all treated as in development.
      $version = $project['releases'][$project['recommended']]['version'];
      return '<span class="not-current">'. t('In development: %version', array('%version' => $version)) .'</span>';

    // US: Not applicable.
#    case UPDATE_NOT_CURRENT:
#      return '<span class="not-current">' . t('Update available') . '</span>';

    // US: Good news for us means that a stable release is available...
#    case UPDATE_CURRENT:
#      return '<span class="current">' . t('Up to date') . '</span>';
    case UPGRADE_STATUS_STABLE:
      $version = $project['releases'][$project['recommended']]['version'];
      return '<span class="current">'. t('Available: %version', ['%version' => $version]) .'</span>';

    // US: ...or that a module's been moved into core.
    case UPGRADE_STATUS_CORE:
      return '<span class="current">'. t('In core') .'</span>';
  }
}
