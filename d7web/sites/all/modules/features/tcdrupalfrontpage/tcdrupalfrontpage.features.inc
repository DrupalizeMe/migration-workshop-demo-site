<?php
/**
 * @file
 * tcdrupalfrontpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tcdrupalfrontpage_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tcdrupalfrontpage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function tcdrupalfrontpage_image_default_styles() {
  $styles = array();

  // Exported image style: frontpage_featured.
  $styles['frontpage_featured'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'frontpage_featured',
  );

  return $styles;
}
