#!/usr/bin/env bash

echo "Deleting all artifacts from drush migrate:upgrade --configure-only"

drush sqlq 'delete from config where name like "migrate_plus.migration.%"'
drush php:eval "\Drupal::state()->set('source_db', ['key' => 'migrate','target' => 'default',]);"
drush php:eval "\Drupal::state()->set('migrate.fallback_state_key', 'source_db');"
drush cr -y
