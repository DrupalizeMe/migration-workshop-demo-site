<?php
/**
 * @file
 * tcdrupalusers.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function tcdrupalusers_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: not a spammer.
  $roles['not a spammer'] = array(
    'name' => 'not a spammer',
    'weight' => 5,
  );

  // Exported role: session manager.
  $roles['session manager'] = array(
    'name' => 'session manager',
    'weight' => 3,
  );

  return $roles;
}
