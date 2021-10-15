#!/usr/bin/env bash
if [ -n "$DEBUG_DRUPALPOD" ]; then
    set -x
fi

# Create a phpstorm command
sudo ln -sf $GITPOD_REPO_ROOT/.gitpod/phpstorm.sh /usr/local/bin/phpstorm

# Create a preview command
sudo ln -sf $GITPOD_REPO_ROOT/.gitpod/preview-7.sh /usr/local/bin/preview7
sudo ln -sf $GITPOD_REPO_ROOT/.gitpod/preview.sh /usr/local/bin/preview
