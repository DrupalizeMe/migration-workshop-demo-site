<?php
/**
 * @file
 * tcdrupalsponsors.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tcdrupalsponsors_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tcdrupalsponsors_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function tcdrupalsponsors_image_default_styles() {
  $styles = array();

  // Exported image style: sponsor.
  $styles['sponsor'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 190,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => 'ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 200,
            'height' => 200,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'sponsor',
  );

  // Exported image style: sponsor-gold.
  $styles['sponsor-gold'] = array(
    'label' => 'sponsor-gold',
    'effects' => array(
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      10 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => 'ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 115,
            'height' => 115,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function tcdrupalsponsors_node_info() {
  $items = array(
    'sponsor' => array(
      'name' => t('Sponsor'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'sponsorship_display' => array(
      'name' => t('Sponsorship Display'),
      'base' => 'node_content',
      'description' => t('The product display for each sponsorship level'),
      'has_title' => '1',
      'title_label' => t('Sponsorship'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
