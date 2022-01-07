<?php
/**
 * @file
 * tcdrupalschedule.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tcdrupalschedule_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tcdrupalschedule_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tcdrupalschedule_node_info() {
  $items = array(
    'schedule_item' => array(
      'name' => t('Schedule Item'),
      'base' => 'node_content',
      'description' => t('Add a non-session item to the schedule.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'session' => array(
      'name' => t('Session'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Session Title'),
      'help' => t('<p>Submit your proposal below and our elite team of camp organizers will pick sessions which benefit and excite attendees from the Drupal community, from all topics of interest and skill levels.</p>

<p>You can submit either a 60-minute session or a 30-minute session. Each room will have projectors, so plan accordingly.</p>'),
    ),
    'timeslot' => array(
      'name' => t('Timeslot'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
