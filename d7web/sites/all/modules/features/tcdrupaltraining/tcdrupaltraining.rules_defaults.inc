<?php
/**
 * @file
 * tcdrupaltraining.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tcdrupaltraining_default_rules_configuration() {
  $items = array();
  $items['rules_training_registrations_should_be_auto_confirmed'] = entity_import('rules_config', '{ "rules_training_registrations_should_be_auto_confirmed" : {
      "LABEL" : "Training registrations should be auto-confirmed",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "registration" ],
      "ON" : [ "registration_insert" ],
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "registration:entity" ], "type" : "node" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "registration:state" ], "value" : "complete" } }
      ]
    }
  }');
  return $items;
}
