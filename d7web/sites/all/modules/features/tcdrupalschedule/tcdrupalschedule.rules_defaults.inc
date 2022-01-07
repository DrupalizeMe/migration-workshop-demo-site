<?php
/**
 * @file
 * tcdrupalschedule.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function tcdrupalschedule_default_rules_configuration() {
  $items = array();
  $items['rules_emails_when_sessions_are_submitted'] = entity_import('rules_config', '{ "rules_emails_when_sessions_are_submitted" : {
      "LABEL" : "Emails when sessions are submitted",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "session" : "session" } } } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "contact@tcdrupal.org",
            "subject" : "New Session: [node:title]",
            "message" : "Submitted by: [node:author]\\r\\nSession length: [node:field_session_length]\\r\\nTrack: [node:field-session-track] \\r\\nExperience level: [node:field-session-experience-level]\\r\\n\\r\\n[node:body]\\r\\n\\r\\nView the session onilne: [node:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_session_submission_confirmation_message'] = entity_import('rules_config', '{ "rules_session_submission_confirmation_message" : {
      "LABEL" : "Session submission confirmation message",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "session" : "session" } } } },
        { "AND" : [] },
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "2" : "2" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "content\\/thanks-proposing-session" } } ]
    }
  }');
  return $items;
}
