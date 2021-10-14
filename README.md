# Drupalize.Me Migrations Workshop Environment

This repository contains scaffolding for a demo environment to use during the Drupalize.Me Drupal-to-Drupal migration workshop. And some dummy data (database and files) that replicate a production Drupal 7 site to serve as the migration source data.

It contains configuration to run Drupal locally in [DDEV](https://github.com/drud/ddev) or in the cloud on [Gitpod](https://www.gitpod.io/).

## DDEV - localhost setup

Assuming you have [Docker installed](https://ddev.readthedocs.io/en/stable/users/docker_installation/), and [DDEV-Local installed](https://ddev.readthedocs.io/en/stable/#installation).

- Clone this repo
- Run `ddev start` in the root directory of the project
- Proceed to the Initial setup for workshop section below

Once set up locally you can use whatever IDE or editor you want.

## GitPod - Cloud setup

Click the button below to start a new development environment on GitPod:

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/DrupalizeMe/migration-workshop-demo-site)

After the workspace is set up you can use VS Code in the cloud to edit your project and execute terminal commands.

Once the workspace has started you'll need to run the setup script to launch DDEV.

Run `./.gitpod/gitpod-setup-ddev.sh` from the VS Code terminal in the GitPod workspace.

**Tip**: Sometimes when restarting the project you may need to run the above script again. For example if the host IP address changes. If DDEV starts, but you can't acces your Drupal site in the preview browser try running the script again.

## Initial setup for workshop

Once DDEV is up and running on GitPod there are a few additional things you'll need to do to prepare for the workshop:

**Copy paste and execute**: `./scripts/d7-data.setup.sh; ./scripts/d9-empty-install.sh`

Or do it manually:

- Install Drupal and dependencies `ddev composer install`
- Import the D7 database into ddev with `ddev import-db --src=d7data/d7site.sql.gz --target-db=d7`
- Unzip the D7 files archive `ddev exec tar xvzf d7data/d7files.tar.gz --directory=d7data/`
- Install Drupal

## Helper Scripts

#### Drupal 7 source data setup

```shell
./scripts/d7-data-setup.sh
```

#### (re)Install Drupal core and contributed modules

```shell
./scripts/d9-empty-install.sh
```

#### Whipe migrate_plus.* migrations from configuration

Useful if you want to whipe the results of `drush migrate:upgrade --configure-only` and try again.

```shell
./scripts/reset.sh
```

## Special thanks

Thanks to [Ofer Shaal](https://github.com/shaal) for his work on DrupalPod which inspired this setup - Thank you 🙏!
