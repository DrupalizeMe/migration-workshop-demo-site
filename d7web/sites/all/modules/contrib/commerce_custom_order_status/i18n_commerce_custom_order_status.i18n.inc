<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_object_info().
 */
function i18n_commerce_custom_order_status_i18n_object_info() {
  $info['commerce_order_status'] = array(
    'title' => t('Commerce Custom Order Status'),
    'class' => 'i18n_string_object_wrapper',
    'key' => 'name',
    'placeholders' => array(
      '%commerce_order_status' => 'name',
    ),
    'edit path' => 'admin/commerce/config/order/status/%commerce_order_status/edit',
    'string translation' => array(
      'textgroup' => 'commerce',
      'type' => 'custom_order_status',
      'translate path' => 'admin/commerce/config/order/status/%commerce_order_status/translate/%i18n_language',
      'properties' => array(
        'title' => t('Title'),
      ),
    ),
    'list callback' => 'commerce_custom_order_status_get_statuses',
  );
  return $info;
}

/**
 * Implements hook_i18n_string_info().
 */
function i18n_commerce_custom_order_status_i18n_string_info() {
  $groups['commerce_custom_order_status'] = array(
    'title' => t('Commerce Custom Order Status'),
    'description' => t('Commerce Custom Order Status strings translation.'),
    'format' => FALSE,
    'list' => TRUE,
  );
  return $groups;
}
