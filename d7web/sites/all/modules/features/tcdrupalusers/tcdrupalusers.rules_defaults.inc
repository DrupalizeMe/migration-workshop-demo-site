<?php
/**
 * @file
 * tcdrupalusers.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tcdrupalusers_default_rules_configuration() {
  $items = array();
  $items['rules_tcdrupaluser_delete_spam_accounts'] = entity_import('rules_config', '{ "rules_tcdrupaluser_delete_spam_accounts" : {
      "LABEL" : "Immediately delete spam user accounts",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "tcdrupaluser" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "OR" : [
            { "text_matches" : { "text" : [ "account:mail" ], "match" : "drupaler.org" } },
            { "text_matches" : { "text" : [ "account:mail" ], "match" : "mailcatch.com" } },
            { "data_is" : {
                "data" : [ "account:field-first-name" ],
                "value" : [ "account:field-last-name" ]
              }
            }
          ]
        }
      ],
      "DO" : [ { "entity_delete" : { "data" : [ "account" ] } } ]
    }
  }');
  return $items;
}
