#!/usr/bin/env bash

drush php:eval "\Drupal::state()->set('source_db', ['key' => 'migrate','target' => 'default',]);"
drush php:eval "\Drupal::state()->set('migrate.fallback_state_key', 'source_db');"
