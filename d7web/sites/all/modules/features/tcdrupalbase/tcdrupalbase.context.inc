<?php
/**
 * @file
 * tcdrupalbase.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tcdrupalbase_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tcdrupal_not_front';
  $context->description = 'Everything but the front page (and sponsor page).';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~sponsors' => '~sponsors',
        '~admin*' => '~admin*',
        '~batch*' => '~batch*',
        '~node/add/*' => '~node/add/*',
        '~node/*/edit' => '~node/*/edit',
        '~user/*/edit' => '~user/*/edit',
        '~user/*/cancel' => '~user/*/cancel',
        '~media/*' => '~media/*',
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-sponsors-block_1' => array(
          'module' => 'views',
          'delta' => 'sponsors-block_1',
          'region' => 'bottom',
          'weight' => '-37',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Everything but the front page (and sponsor page).');
  $export['tcdrupal_not_front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tcdrupal_sitewide';
  $context->description = 'Site wide - All Users';
  $context->tag = 'tcdrupal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~node/*/registrations' => '~node/*/registrations',
        '~users/*' => '~users/*',
        '~user/*' => '~user/*',
        '~user*' => '~user*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-14' => array(
          'module' => 'block',
          'delta' => '14',
          'region' => 'bottom',
          'weight' => '-10',
        ),
        'block-15' => array(
          'module' => 'block',
          'delta' => '15',
          'region' => 'bottom',
          'weight' => '-9',
        ),
        'block-17' => array(
          'module' => 'block',
          'delta' => '17',
          'region' => 'bottom',
          'weight' => '-8',
        ),
        'block-16' => array(
          'module' => 'block',
          'delta' => '16',
          'region' => 'bottom',
          'weight' => '-7',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'menu-menu-secondary-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary-menu',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-13' => array(
          'module' => 'block',
          'delta' => '13',
          'region' => 'footer',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Site wide - All Users');
  t('tcdrupal');
  $export['tcdrupal_sitewide'] = $context;

  return $export;
}
