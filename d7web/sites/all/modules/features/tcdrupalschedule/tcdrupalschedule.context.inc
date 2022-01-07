<?php
/**
 * @file
 * tcdrupalschedule.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tcdrupalschedule_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tcdrupal_session_page';
  $context->description = 'Session nodes only.';
  $context->tag = 'tcdrupal';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'session' => 'session',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-session_speakers-block' => array(
          'module' => 'views',
          'delta' => 'session_speakers-block',
          'region' => 'sidebar_second',
          'weight' => '-33',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Session nodes only.');
  t('tcdrupal');
  $export['tcdrupal_session_page'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tcdrupal_user_page';
  $context->description = 'Only on user/* pages.';
  $context->tag = 'tcdrupal';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'current',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-registrations_for_me-block' => array(
          'module' => 'views',
          'delta' => 'registrations_for_me-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-training_for_me-block' => array(
          'module' => 'views',
          'delta' => 'training_for_me-block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-058afc2beaf171c712add80d321b959e' => array(
          'module' => 'views',
          'delta' => '058afc2beaf171c712add80d321b959e',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-3cab59979957a60818811bf5611ecffb' => array(
          'module' => 'views',
          'delta' => '3cab59979957a60818811bf5611ecffb',
          'region' => 'content',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Only on user/* pages.');
  t('tcdrupal');
  $export['tcdrupal_user_page'] = $context;

  return $export;
}
