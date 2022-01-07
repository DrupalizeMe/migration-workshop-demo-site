<?php
/**
 * @file
 * Displays a commerce coupon form field item on cart's form:
 */

class commerce_coupon_handler_area_cart_form extends views_handler_area {

  function construct() {
    parent::construct();
    $this->additional_fields['order_id'] = 'order_id';
  }

  function query() {
    $this->ensure_my_table();
    $fields = $this->additional_fields;


    // Rip off add_additional_fields method. Use it when
    // http://drupal.org/node/1321018 is fixed.
    $group_params = array();
    if ($this->options['group_type'] != 'group') {
      $group_params = array(
        'function' => $this->options['group_type'],
      );
    }
    if (!empty($fields) && is_array($fields)) {
      foreach ($fields as $identifier => $info) {
        if (is_array($info)) {
          if (isset($info['table'])) {
            $table_alias = $this->query->ensure_table($info['table'], $this->relationship);
          }
          else {
            $table_alias = $this->table_alias;
          }

          if (empty($table_alias)) {
            debug(t('Handler @handler tried to add additional_field @identifier but @table could not be added!', array('@handler' => $this->definition['handler'], '@identifier' => $identifier, '@table' => $info['table'])));
            $this->aliases[$identifier] = 'broken';
            continue;
          }

          $params = array();
          if (!empty($info['params'])) {
            $params = $info['params'];
          }

          $params += $group_params;
          $this->aliases[$identifier] = $this->query->add_field($table_alias, $info['field'], NULL, $params);
        }
        else {
          $this->aliases[$info] = $this->query->add_field($this->table_alias, $info, NULL, $group_params);
        }
      }
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['cart_coupon_view']['default'] = 'commerce_coupon_review_pane|checkout';
    $options['weight']['default'] = 99;

    return $options;
  }

  /**
   * Options form.
   */

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    unset($form['empty']);

    // Build an options array of Views available for the cart contents pane.
    $options = array();

    // Generate an option list from all user defined and module defined views.
    foreach (views_get_all_views() as $view_id => $view_value) {
      // Only include line item Views.
      if ($view_value->base_table == 'commerce_coupon') {
        foreach ($view_value->display as $display_id => $display_value) {
          $options[check_plain($view_id)][$view_id . '|' . $display_id] = check_plain($display_value->display_title);
        }
      }
    }
    $form['cart_coupon_view'] = array(
      '#type' => 'select',
      '#title' => t('Coupon view to display'),
      '#description' => t('Specify the View to use under the cart. Select \'none\' to not display anything.'),
      '#options' => array('none' => t('None')) + $options,
      '#default_value' => $this->options['cart_coupon_view'],
    );

    $form['weight'] = array(
      '#type' => 'textfield',
      '#title' => t('Form item weight'),
      '#description' => t('Sets the weight of the form so it\'s displayed at the bottom. Do not change this unless you have several forms in the same area'),
      '#default_value' => $this->options['weight'],
      '#required' => TRUE,
    );
  }

  function options_validate(&$form, &$form_state) {
    $weight = $form_state['values']['options']['weight'];
    // Weight must be an integer:
    if (!is_null($weight )&& (!is_numeric($weight)) || (int) $weight != $weight) {
      form_set_error('options][weight', t('!name field must be an integer.', array('!name' => $form['weight']['#title'])));
    }
  }


  function render($empty = NULL) {
    // Render a Views form item placeholder.
    // This causes Views to wrap the View in a form.
    // Render a Views form item placeholder.
    return '<!--form-item-' . $this->options['id'] . '-->';
  }

  /**
   * This handler never outputs data when the view is empty.
   */
  function views_form_empty($empty) {
    return $empty;
  }

  /**
   * Views form.
   */
  function views_form(&$form, &$form_state) {

    $form[$this->options['id']] = array(
      '#type' => 'container',
      '#prefix' => '<div class="commerce-coupon-handler-area-cart-form">',
      '#suffix' => '</div>',
      '#weight' => $this->options['weight'],
    );

    $form[$this->options['id']]['coupon_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Coupon code'),
      '#description' => t('Enter here your coupon code.'),
    );

    $form[$this->options['id']]['coupon_add'] = array(
      '#type' => 'submit',
      '#name' => 'coupon_add',
      '#value' => t('Add coupon'),
      '#validate' => array('commerce_coupon_handler_area_cart_form_validate'),
      '#submit' => array('commerce_coupon_handler_area_cart_form_submit'),
    );

    $orders = $this->view->query->get_result_entities($this->view->result);
    $order = reset($orders[1]);

    $cart_coupon_view = $this->options['cart_coupon_view'];
    if ($cart_coupon_view <> 'none') {
      list($view_id, $display_id) = explode('|', $cart_coupon_view);
      if (!empty($view_id) && !empty($display_id) && views_get_view($view_id)) {
        $form[$this->options['id']]['redeemed_coupons'] = array(
          '#type' => 'markup',
          '#markup' => commerce_embed_view($view_id, $display_id, array($order->order_id)),
        );
      }
    }
  }

}

/**
 * Validate: function commerce_coupon_handler_area_cart_form.
 */

function commerce_coupon_handler_area_cart_form_validate($form, &$form_state) {
  $code  = $form_state['values']['coupon_code'];
  $order = $form_state['order'];

  if (empty($code)) {
    form_set_error('coupon_code', t('Your coupon code is required.'));
  }
  elseif (!empty($order) && !commerce_coupon_code_is_valid($code, $order)) {
    form_set_error('coupon_code', t('Your coupon code is not valid.'));
  }
}

/**
 * Submit: function commerce_coupon_handler_area_cart_form.
 */

function commerce_coupon_handler_area_cart_form_submit($form, &$form_state) {
  $code  = $form_state['values']['coupon_code'];
  $order = $form_state['order'];

  $commerce_coupon = commerce_coupon_load_by_code($code);
  commerce_coupon_redeem_coupon($commerce_coupon, $order);
}
