#!/usr/bin/env bash
set -ex

echo "Creating a database snapshot in ./backup.sql.gz"

ddev export-db --file=backup.sql.gz
