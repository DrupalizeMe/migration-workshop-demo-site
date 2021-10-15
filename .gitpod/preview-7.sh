#!/usr/bin/env bash

echo "Drupal 7 site is available at: $(gp url 8080)/_d7web/"
gp preview "$(gp url 8080)/_d7web/"
