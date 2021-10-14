#!/usr/bin/env bash

# Import the D7 database into ddev.
ddev import-db --src=d7data/d7site.sql.gz --target-db=d7

# Unzip the D7 files archive.
tar xvzf d7data/d7files.tar.gz --directory=d7data/
