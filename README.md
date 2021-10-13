# Drupalize.Me Migrations Workshop Environment

This repository contains scaffolding for a demo environment to use during the Drupalize.Me Drupal-to-Drupal migration workshop. And some dummy data (database and files) that replicate a production Drupal 7 site to serve as the migration source data.

It contains configuration to run Drupal in [DDEV](https://github.com/drud/ddev) of for development environments on [Gitpod](https://www.gitpod.io/). It can be used in one of two ways:

## localhost

Assuming you have DDEV-Local installed.

- Clone this repo
- Run `ddev start` in the root directory of the project
- Install Drupal and dependencies `ddev composer install`
- Import the D7 database into ddev with `ddev import-db --src=d7data/d7site.sql.gz --target-db=d7`
- Unzip the D7 files archive `tar xvzf d7data/d7files.tar.gz --directory=d7data/`

## GitPod - Cloud

Click the button below to start a new development environment on GitPod:

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/DrupalizeMe/migration-workshop-demo-site)

Once the workspace has started you'll need to run the setup script once. Though it won't hurt if you run it again:

Run `./.gitpod/gitpod-setup-ddev.sh` from the VS Code terminal in the GitPod workspace.

## Special thanks

Thanks to [Ofer Shaal](https://github.com/shaal) for his work on DrupalPod which inspired this setup - Thank you 🙏!
