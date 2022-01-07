<?php

/**
 * @file
 * Create a CSV file with fields for every Drupal 7 entity type / bundle.
 *
 * Usage:
 * drush scr field_list.php
 * 
 * Will output a directory named 'entity_fields/' with a CSV file for each
 * entity + bundle combo.
 */

$directory = __DIR__ . '/entity_fields';
if (!is_dir($directory)) {
  mkdir($directory);
}

$types = entity_get_info();

foreach ($types as $entity_type => $info) {
  print 'Export info for ' . $info['label'] . ' (' . $entity_type .')' . PHP_EOL;

  foreach ($info['bundles'] as $bundle => $bundle_info) {
    $fields = [];
    $fields[] = [
      'Machine name', 'Label', 'Type', 'Widget'
    ];

    $field_info = field_info_fields($entity_type, $bundle);
    $instances = field_info_instances($entity_type, $bundle);
    $extra_fields = field_info_extra_fields($entity_type, $bundle, 'form');

    // Base fields.
    foreach ($info['base table field types'] as $name => $type) {
      $fields[] = [
        'name' => $name,
        'title' => $name,
        'field_type' => $type,
        'widget' => 'base field',
      ];
    }

    // Field API fields.
    foreach ($instances as $name => $instance) {
      $field = field_info_field($instance['field_name']);
      $fields[] = [
        'name' => $instance['field_name'],
        'title' => $instance['label'],
        'field_type' => $field_info[$name]['type'],
        'widget' => $instance['widget']['type'],
      ];
    }
    
    // Non-field elements.
    foreach ($extra_fields as $name => $extra_field) {
      $fields[] = [
        'name' => $name,
        'title' => $extra_field['label'],
        'field_type' => '',
        'widget' => '',
      ];
    }

    $filename = $directory . '/' . $entity_type . '-' . $bundle . '.csv';
    $fp = fopen($filename, 'w');
    foreach ($fields as $row) {
      fputcsv($fp, $row);
    }
    fclose($fp);
    print 'Wrote data to file: ' . $filename . PHP_EOL;
  }
}
