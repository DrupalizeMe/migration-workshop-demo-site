<?php
/**
 * Copy this example file and rename it to "settings.local.php" to allow
 * for settings that only apply in your local environment.
 */ 

# Change the $databases settings below to match your local TC Drupal 
# database and credentials.
$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'd7_tcdrupal2017',
  'username' => 'DBUSER',
  'password' => 'DBPASS',
  'host' => 'localhost',
  'prefix' => '',
);

/**
 * Override local mail system so that all outgoing mail instead saves
 * to the temporary directory as a .txt file. Requires devel module.
 */
$conf['mail_system'] = array(
  'default-system' => 'MailsystemDelegateMailSystem',
);
$conf['mailsystem_delegate:default-system'] = array (
  'mail' => 'DevelMailLog',
  'format' => 'DevelMailLog',
);

# Override the configured tmp directory file.
$conf['file_temporary_path'] = '/tmp';

