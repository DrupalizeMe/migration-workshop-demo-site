#!/usr/bin/env bash

echo "Drupal 9 site is available at: $(gp url 8080)"
gp preview "$(gp url 8080)"
