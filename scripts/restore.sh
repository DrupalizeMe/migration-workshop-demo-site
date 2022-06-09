#!/usr/bin/env bash
set -ex

echo "Import database snapshot in ./backup.sql.gz"

ddev import-db --src=backup.sql.gz
ddev drush cr -y
