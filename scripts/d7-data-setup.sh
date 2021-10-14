#!/usr/bin/env bash

# Import the D7 database into ddev.
echo "Importing D7 database from d7data/d7site.sql.gz"
ddev import-db --src=d7data/d7site.sql.gz --target-db=d7

echo "Extracting D7 codebase from d7data/d7web.tar.gz into /var/www/html/d7web"
ddev exec tar xzf d7data/d7web.tar.gz --directory=/var/www/html

echo "Extracting D7 content files from d7data/d7file.tar.gz into /var/www/html/d7web/sites/default/files"
ddev exec tar xzf d7data/d7files.tar.gz --directory=/var/www/html/d7web

echo "Done!"
