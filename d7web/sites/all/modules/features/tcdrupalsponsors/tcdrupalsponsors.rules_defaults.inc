<?php
/**
 * @file
 * tcdrupalsponsors.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tcdrupalsponsors_default_rules_configuration() {
  $items = array();
  $items['rules_email_when_a_sponsorship_is_purchased'] = entity_import('rules_config', '{ "rules_email_when_a_sponsorship_is_purchased" : {
      "LABEL" : "Emails when a sponsorship is purchased",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "9",
      "REQUIRES" : [ "commerce_order", "rules", "commerce_checkout" ],
      "ON" : [ "commerce_checkout_complete" ],
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce_order" ],
            "product_type" : { "value" : { "sponsorship" : "sponsorship" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "contact@tcdrupal.org",
            "subject" : "A new sponsorship has been purchased",
            "message" : "A new sponsorship has been purchased.\\r\\n\\r\\nPurchaser: \\r\\n[commerce-order:owner]\\r\\n[commerce-order:mail]\\r\\n\\r\\n[commerce-order:admin-url]\\r\\n\\r\\nItems: [commerce-order:commerce_line_items]\\r\\nTotal: [commerce-order:commerce_order_total]\\r\\n",
            "from" : "contact@tcdrupal.org",
            "language" : [ "commerce-order:state" ]
          }
        },
        { "mail" : {
            "to" : "[commerce-order:mail]",
            "subject" : "Thanks for sponsoring Twin Cities Drupal Camp!",
            "message" : "It\\u0027s with your help that Twin Cities Drupal Camp remains one of the nation\\u0027s most anticipated Drupal events. We can\\u0027t wait to see you!\\r\\n\\r\\nWe\\u0027ll soon be sending you a coupon code for redeeming your complimentary camp registrations. We\\u0027ll also follow up with you about getting your logo, twitter handles, and other sponsorship goodies. If you have any questions, please feel free to get in touch with us at contact@tcdrupal.org.",
            "language" : [ "commerce-order:state" ]
          }
        }
      ]
    }
  }');
  $items['rules_sponsorship_email'] = entity_import('rules_config', '{ "rules_sponsorship_email" : {
      "LABEL" : "Sponsorship email",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "commerce_line_item" : { "label" : "Commerce Line Item", "type" : "commerce_line_item" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "commerce-line-item" ], "field" : "commerce_product" } },
        { "data_is" : {
            "data" : [ "commerce-line-item:commerce-product:type" ],
            "value" : "sponsorship"
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "tim@politalk.org, \\r\\nkeri@triangleparkcreative.com",
            "subject" : "TEST: notification of sponsorship purchase",
            "message" : "[site:current-user] just purchased a sponsorship. The order number is [commerce-line-item:order].",
            "language" : [ "commerce-line-item:type" ]
          }
        }
      ]
    }
  }');
  return $items;
}
