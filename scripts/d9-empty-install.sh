#!/usr/bin/env bash

set -ex

# Install Drupal and dependencies.
ddev composer install

echo "Installing Drupal core"
ddev drush si --yes --account-pass="admin" standard

echo "Installing contributed modules"
ddev drush en --yes address admin_toolbar honeypot image_resize_filter migrate_plus migrate_upgrade paragraphs pathauto recaptcha token webform
