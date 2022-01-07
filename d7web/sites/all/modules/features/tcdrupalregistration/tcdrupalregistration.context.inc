<?php
/**
 * @file
 * tcdrupalregistration.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tcdrupalregistration_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tcdrupal_registration_page';
  $context->description = 'Only on the /register page.';
  $context->tag = 'tcdrupal';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'register' => 'register',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-registration_state-block' => array(
          'module' => 'views',
          'delta' => 'registration_state-block',
          'region' => 'content',
          'weight' => '-31',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Only on the /register page.');
  t('tcdrupal');
  $export['tcdrupal_registration_page'] = $context;

  return $export;
}
