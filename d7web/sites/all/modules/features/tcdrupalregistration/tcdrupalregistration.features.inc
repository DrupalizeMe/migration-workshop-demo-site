<?php
/**
 * @file
 * tcdrupalregistration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tcdrupalregistration_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tcdrupalregistration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tcdrupalregistration_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product Display'),
      'base' => 'node_content',
      'description' => t('Generic content type for adding commerce products.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_registration_state().
 */
function tcdrupalregistration_default_registration_state() {
  $items = array();
  $items['canceled'] = entity_import('registration_state', '{
    "name" : "canceled",
    "label" : "Canceled",
    "description" : "Registration was cancelled",
    "default_state" : "0",
    "active" : "0",
    "held" : "0",
    "show_on_form" : "0",
    "weight" : "1"
  }');
  $items['complete'] = entity_import('registration_state', '{
    "name" : "complete",
    "label" : "Complete",
    "description" : "Registration has been completed.",
    "default_state" : "0",
    "active" : "1",
    "held" : "0",
    "show_on_form" : "0",
    "weight" : "1"
  }');
  $items['pending'] = entity_import('registration_state', '{
    "name" : "pending",
    "label" : "Pending",
    "description" : "Registration is pending.",
    "default_state" : "1",
    "active" : "0",
    "held" : "0",
    "show_on_form" : "0",
    "weight" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function tcdrupalregistration_default_registration_type() {
  $items = array();
  $items['free_event'] = entity_import('registration_type', '{
    "name" : "free_event",
    "label" : "Free Event",
    "locked" : "0",
    "default_state" : null,
    "data" : null,
    "weight" : "0"
  }');
  $items['paid_event'] = entity_import('registration_type', '{
    "name" : "paid_event",
    "label" : "Paid Event",
    "locked" : "0",
    "default_state" : null,
    "data" : null,
    "weight" : "0"
  }');
  return $items;
}
