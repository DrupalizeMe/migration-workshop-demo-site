<?php
/**
 * @file
 * tcdrupalfrontpage.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tcdrupalfrontpage_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tcdrupal_frontpage';
  $context->description = 'Frontpage only.';
  $context->tag = 'tcdrupal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'highlighted',
          'weight' => '-8',
        ),
        'views-whats_going_on-whats_going_on' => array(
          'module' => 'views',
          'delta' => 'whats_going_on-whats_going_on',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-sponsors-block_1' => array(
          'module' => 'views',
          'delta' => 'sponsors-block_1',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Frontpage only.');
  t('tcdrupal');
  $export['tcdrupal_frontpage'] = $context;

  return $export;
}
