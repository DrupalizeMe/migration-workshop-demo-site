<?php

/**
 * Stock lifetime
 */
class commerce_reports_stock_handler_field_weeklysales extends views_handler_field_custom {
  function query() {
    if (!isset($this->view->commerce_reports_stock_data)) {
      $this->view->commerce_reports_stock_data = _commerce_reports_stock_calculate_dataset();
    }
  }

  function render($values) {
    $sku = $values->commerce_product_sku;
    return $this->view->commerce_reports_stock_data[$sku]['weeklysales'];
  }
}
