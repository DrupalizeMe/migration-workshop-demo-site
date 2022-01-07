<?php
/**
 * @file
 * tcdrupalbase.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tcdrupalbase_ctools_plugin_api($module = NULL, $api = NULL) {
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
function tcdrupalbase_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function tcdrupalbase_image_default_styles() {
  $styles = array();

  // Exported image style: frontpage_thumb.
  $styles['frontpage_thumb'] = array(
    'label' => 'frontpage_thumb',
    'effects' => array(
      12 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 619,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: frontpage_thumb_cropped.
  $styles['frontpage_thumb_cropped'] = array(
    'label' => 'Frontpage Thumb Cropped',
    'effects' => array(
      13 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 619,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      15 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 619,
          'height' => 349,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: grid_3.
  $styles['grid_3'] = array(
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 180,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'grid_3',
  );

  // Exported image style: grid_9.
  $styles['grid_9'] = array(
    'label' => 'grid_9',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 700,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_thumb.
  $styles['user_thumb'] = array(
    'label' => 'user_thumb',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'anchor' => 'center-center',
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
function tcdrupalbase_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
