<?php
/**
 * @file
 * tcdrupalsponsors.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tcdrupalsponsors_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__sponsor';
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
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__sponsor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__sponsorship_display';
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
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'product:field_logo' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'product:field_organization_name' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'product:field_bio' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
        'product:field_sponsor_url' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
        'product:field_registration' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'product:field_sponsorship_level' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_stock' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_stock_override' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__sponsorship_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_sponsor';
  $strongarm->value = array();
  $export['menu_options_sponsor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_sponsorship_display';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_sponsorship_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_sponsor';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_sponsor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_sponsorship_display';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_sponsorship_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_sponsor';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_sponsor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_sponsorship_display';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_sponsorship_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_sponsor';
  $strongarm->value = '0';
  $export['node_preview_sponsor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_sponsorship_display';
  $strongarm->value = '1';
  $export['node_preview_sponsorship_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_sponsor';
  $strongarm->value = 0;
  $export['node_submitted_sponsor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_sponsorship_display';
  $strongarm->value = 0;
  $export['node_submitted_sponsorship_display'] = $strongarm;

  return $export;
}
