<?php
/**
 * @file
 * tcdrupaltraining.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tcdrupaltraining_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__event';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'product:field_registration' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'product:commerce_stock' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_stock_override' => array(
          'default' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
        ),
        'flag_my_schedule' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'product:field_size' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_event';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_event';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_event';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_event';
  $strongarm->value = '0';
  $export['node_preview_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_event';
  $strongarm->value = 0;
  $export['node_submitted_event'] = $strongarm;

  return $export;
}
