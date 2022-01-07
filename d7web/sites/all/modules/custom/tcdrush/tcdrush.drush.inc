<?php
/**
 * @file
 * Custom drush commands for tcdrupal.org sites.
 */

/**
 * Implements hook_drush_command().
 */
function tcdrush_drush_command() {
  $items = array();

  $items['tcdrush-purge'] = array(
    'description' => 'Purge all event specific content.',
    'callback' => '_drush_tcdrush_purge',
  );

  return $items;
}

/**
 * Callback; Command to delete all event specific content.
 */
function _drush_tcdrush_purge() {
  if (drush_confirm(dt('Do you really want to do this? Did you make a backup? This is destructive!'))) {
    // Delete nodes (articles, sessions, and sponsors).
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', array('article', 'session'), 'IN');
    $results = $query->execute();
    if (isset($results['node'])) {
      $nids = array_keys($results['node']);
      node_delete_multiple($nids);
    }

    // Unpublish all sponsors.
    db_query('UPDATE {node} SET status = 1 WHERE type = "sponsor"');

    // Delete registrations.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'registration');
    $results = $query->execute();
    if (isset($results['registration'])) {
      $ids = array_keys($results['registration']);
      registration_delete_multiple($ids);
    }

    // Delete orders.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'commerce_order');
    $results = $query->execute();
    if (isset($results['commerce_order'])) {
      $ids = array_keys($results['commerce_order']);
      commerce_order_delete_multiple($ids);
    }

    // Delete coupons.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'commerce_coupon');
    $results = $query->execute();
    if (isset($results['commerce_coupon'])) {
      $ids = array_keys($results['commerce_coupon']);
      commerce_coupon_delete_multiple($ids);
    }
  }
}
