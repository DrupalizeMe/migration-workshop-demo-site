<?php
/**
 * @file
 * tcdrupalbase.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function tcdrupalbase_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'pathologic' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'proto-rel',
          'local_paths_exploded' => array(
            0 => array(
              'path' => '/',
            ),
            1 => array(
              'path' => '/',
              'host' => '2017.tcdrupal.dev',
            ),
          ),
          'base_url_host' => '2017.tcdrupal.dev',
          'docroot' => '/Users/les/Sites/tcdrupal2017',
        ),
      ),
      'filter_html' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <br>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'image_resize_filter' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'link' => 0,
          'link_class' => '',
          'link_rel' => '',
          'image_locations' => array(
            'local' => 'local',
            'remote' => 0,
          ),
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(
      'filter_url' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'pathologic' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'proto-rel',
        ),
      ),
      'filter_autop' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'image_resize_filter' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'link' => 0,
          'link_class' => '',
          'link_rel' => '',
          'image_locations' => array(
            'local' => 'local',
            'remote' => 0,
          ),
        ),
      ),
      'filter_html' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <p> <table> <tbody> <thead> <tr> <td> <th> <h2> <h3> <h4> <h5> <h6>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => 10,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Script.
  $formats['script'] = array(
    'format' => 'script',
    'name' => 'Script',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
