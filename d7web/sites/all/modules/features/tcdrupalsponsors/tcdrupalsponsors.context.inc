<?php
/**
 * @file
 * tcdrupalsponsors.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function tcdrupalsponsors_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sponsor_purchase_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sponsors/become-sponsor' => 'sponsors/become-sponsor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'commerce_cart-cart' => array(
          'module' => 'commerce_cart',
          'delta' => 'cart',
          'region' => 'sidebar_second',
          'weight' => '-35',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['sponsor_purchase_page'] = $context;

  return $export;
}
