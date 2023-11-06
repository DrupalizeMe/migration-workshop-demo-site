# Upgrade Status Documentation

## Usage

Go to Administer >> Reports >> Available updates >> Upgrade status and check the status of your installed modules there. If you've checked some of your projects out from Git, you will need the Git Deploy (http://drupal.org/project/git_deploy) module in order for this module to be
able to read versions of those projects.

## Summary

Upgrade Status module was designed to help with moving from Drupal 7 to Drupal 8. The module will compile a list of your projects along with a status, which can be one of the following:

* Available: A stable release of this project is available.
* In development: A development release of this project is available, which can be installed for testing purposes.
* Not ported yet: There are no releases available for this project.
* Replaced by: A list of other modules that have superseded this one.

Clicking on any of the modules' boxes will expand the area and show you more information.

If one or more of your installed modules are not yet ported to the selected new Drupal
major version, you should

1. Search the modules' issue queue for already existing issues that might contain a patch, and test that patch yourself. See https://drupal.org/patch/apply for further information.
1. Use the Drupal Module Upgrader module (https://www.drupal.org/project/drupalmoduleupgrader) for migrating a module to the new Drupal version, create a patch, and file a new issue against that project with your patch attached. See https://drupal.org/patch for further information.

For bug reports and feature suggestions, see the issue queue at https://www.drupal.org/project/issues/upgrade_status?version=any_7.x-