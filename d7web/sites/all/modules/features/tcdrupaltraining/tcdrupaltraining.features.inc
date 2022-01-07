<?php
/**
 * @file
 * tcdrupaltraining.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tcdrupaltraining_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tcdrupaltraining_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tcdrupaltraining_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Registerable Event'),
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

/**
 * Implements hook_default_registration_type().
 */
function tcdrupaltraining_default_registration_type() {
  $items = array();
  $items['training'] = entity_import('registration_type', '{
    "name" : "training",
    "label" : "Training",
    "locked" : "0",
    "default_state" : null,
    "data" : null,
    "weight" : "0"
  }');
  return $items;
}
