<?php
/**
 * @file
 * tcdrupalschedule.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tcdrupalschedule_taxonomy_default_vocabularies() {
  return array(
    'room' => array(
      'name' => 'room',
      'machine_name' => 'room',
      'description' => 'Room',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
