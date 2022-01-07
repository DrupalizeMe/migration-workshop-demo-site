<?php
/**
 * @file
 * tcdrupalregistration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tcdrupalregistration_default_rules_configuration() {
  $items = array();
  $items['rules_add_to_cart_redirect_anon'] = entity_import('rules_config', '{ "rules_add_to_cart_redirect_anon" : {
      "LABEL" : "Add to Cart redirect for anonymous users",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : [ "commerce_cart_product_add" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "Before you can continue with your purchase, you must first create a user account for yourself. If you already have a user account, \\u003Ca href=\\u0022\\/user\\/login?destination=checkout\\u0022\\u003Elog in here\\u003C\\/a\\u003E.",
            "repeat" : 0
          }
        },
        { "redirect" : { "url" : "user\\/register?destination=checkout" } }
      ]
    }
  }');
  $items['rules_add_to_cart_redirect_auth'] = entity_import('rules_config', '{ "rules_add_to_cart_redirect_auth" : {
      "LABEL" : "Add to Cart redirect for authenticated users",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : [ "commerce_cart_product_add" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "2" : "2" } }
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "checkout" } } ]
    }
  }');
  $items['rules_clear_carts_before_adding_items'] = entity_import('rules_config', '{ "rules_clear_carts_before_adding_items" : {
      "LABEL" : "Clear carts before adding items",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_cart" ],
      "ON" : [ "commerce_cart_product_prepare" ],
      "DO" : [
        { "commerce_cart_empty" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  $items['rules_emails_when_vouchers_are_purchased'] = entity_import('rules_config', '{ "rules_emails_when_vouchers_are_purchased" : {
      "LABEL" : "Emails when vouchers are purchased",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "9",
      "TAGS" : [ "email" ],
      "REQUIRES" : [ "commerce_order", "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "OR" : [
            { "commerce_order_contains_product" : {
                "commerce_order" : [ "commerce_order" ],
                "product_id" : "VOUCHER",
                "operator" : "\\u003E=",
                "value" : "1"
              }
            },
            { "commerce_order_contains_product" : {
                "commerce_order" : [ "commerce_order" ],
                "product_id" : "VOUCHER_SPONSOR",
                "operator" : "\\u003E=",
                "value" : "1"
              }
            }
          ]
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "contact@tcdrupal.org",
            "subject" : "A new voucher order has been placed",
            "message" : "Voucher orders were purchased.\\r\\n\\r\\nPurchaser: \\r\\n[commerce-order:owner]\\r\\n[commerce-order:mail]\\r\\n\\r\\n[commerce-order:admin-url]\\r\\n\\r\\nItems: [commerce-order:commerce_line_items]\\r\\nTotal: [commerce-order:commerce_order_total]\\r\\n",
            "from" : "contact@tcdrupal.org",
            "language" : [ "commerce-order:state" ]
          }
        }
      ]
    }
  }');
  $items['rules_registration_email'] = entity_import('rules_config', '{ "rules_registration_email" : {
      "LABEL" : "Registration email",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "commerce_line_item" : { "label" : "Commerce Line Item", "type" : "commerce_line_item" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "commerce_product" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "registration_product"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "tim@politalk.org, \\r\\nkeri@triangleparkcreative.com",
            "subject" : "TEST TCDC: notification of registration purchase",
            "message" : "[site:current-user] just purchased a registration. The order number is [commerce-line-item:order].",
            "language" : [ "commerce-line-item:type" ]
          }
        }
      ]
    }
  }');
  $items['rules_zero_out_negative_balance'] = entity_import('rules_config', '{ "rules_zero_out_negative_balance" : {
      "LABEL" : "Zero out Negative balance",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "commerce_payment", "rules", "entity" ],
      "ON" : [ "commerce_order_presave" ],
      "IF" : [
        { "commerce_payment_order_balance_comparison" : {
            "commerce_order" : [ "commerce_order" ],
            "operator" : "\\u003C",
            "value" : "0"
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "commerce-order:commerce-order-total" ],
            "value" : { "value" : { "amount" : "0", "currency_code" : "USD" } }
          }
        }
      ]
    }
  }');
  return $items;
}
