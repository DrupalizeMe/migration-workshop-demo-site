#!/usr/bin/env bash

# Install Drupal and dependencies.
ddev composer install

echo "Installing Drupal core"
ddev drush si --yes --site-name=\"Drupalize.Me Migration Workshop Demo Site\" --account-pass=\"admin\"

echo "Installing contributed modules"
ddev drush en --yes address admin_toolbar honeypot image_resize_filter migrate_plus migrate_upgrade pathauto recaptcha token webform
