<?php

/**
 * Implements hook_views_data_alter().
 */
function commerce_reports_stock_views_data_alter(&$data) {
  $data['commerce_product']['stocklifetime'] = array(
    'title' => t('Stock lifetime'),
    'help' => t('The expected stock lifetime (commerce_reports_stock).'),
    'field' => array(
      'handler' => 'commerce_reports_stock_handler_field_stocklifetime',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'commerce_reports_stock_handler_sort_stocklifetime',
    ),
  );

  $data['commerce_product']['monthlysales'] = array(
    'title' => t('Monthly sales'),
    'help' => t('Product monthly sales (commerce_reports_stock).'),
    'field' => array(
      'handler' => 'commerce_reports_stock_handler_field_monthlysales',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'commerce_reports_stock_handler_sort_monthlysales',
    ),
  );

  $data['commerce_product']['weeklysales'] = array(
    'title' => t('Weekly sales'),
    'help' => t('Product weekly sales (commerce_reports_stock).'),
    'field' => array(
      'handler' => 'commerce_reports_stock_handler_field_weeklysales',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'commerce_reports_stock_handler_sort_weeklysales',
    ),
  );
}
