<?php
/**
 * @file
 * tcdrupalschedule.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tcdrupalschedule_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'booklet_export';
  $view->description = 'Buit to create Merge File for Camp NameTag/Booklet';
  $view->tag = 'tcdrupalschedule, admin';
  $view->base_table = 'node';
  $view->human_name = 'Booklet Schedule Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Booklet Export';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_timeslot_ref' => 'field_timeslot_ref',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_registration_do_username' => 'field_registration_do_username',
    'field_session_room_ref' => 'field_session_room_ref',
    'field_session_track' => 'field_session_track',
    'field_session_experience_level' => 'field_session_experience_level',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timeslot_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_registration_do_username' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_room_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_experience_level' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>Below is the data that can be exported for use with Design Tools to create non-Web versions of the entire Drupal Camp Schedule, in particular the Booklet that attaches to the Lanyard and doubles as a Name-Tag.</p><p>Please review the data before exporting and if there are any concerns, please ask for assistance.</p><p> Click here to export and save this table as Comma-Separated-Values<button>Save Export</button></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['id'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['field'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['label'] = 'Timeslot';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_session_speakers_target_id']['id'] = 'field_session_speakers_target_id';
  $handler->display->display_options['relationships']['field_session_speakers_target_id']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['relationships']['field_session_speakers_target_id']['field'] = 'field_session_speakers_target_id';
  /* Relationship: Content: Room (field_session_room_ref) */
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['id'] = 'field_session_room_ref_tid';
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['field'] = 'field_session_room_ref_tid';
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['label'] = 'Room';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'TItle';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_session_speakers_target_id';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_session_speakers_target_id';
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['relationship'] = 'field_session_speakers_target_id';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  /* Field: Content: Experience Level */
  $handler->display->display_options['fields']['field_session_experience_level']['id'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['field'] = 'field_session_experience_level';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot']['id'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot']['label'] = 'startDate';
  $handler->display->display_options['fields']['field_timeslot']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_1']['id'] = 'field_timeslot_1';
  $handler->display->display_options['fields']['field_timeslot_1']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot_1']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot_1']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot_1']['label'] = 'endDate';
  $handler->display->display_options['fields']['field_timeslot_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Timeslot -  start date (field_timeslot) */
  $handler->display->display_options['sorts']['field_timeslot_value']['id'] = 'field_timeslot_value';
  $handler->display->display_options['sorts']['field_timeslot_value']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['sorts']['field_timeslot_value']['field'] = 'field_timeslot_value';
  $handler->display->display_options['sorts']['field_timeslot_value']['relationship'] = 'field_timeslot_ref_target_id';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'schedule_item' => 'schedule_item',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_session_accepted_value']['group'] = 1;

  /* Display: Booklet Export Page */
  $handler = $view->new_display('page', 'Booklet Export Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Header';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>Below is the data that can be exported for use with Design Tools to create non-Web versions of the entire Drupal Camp Schedule, in particular the Booklet that attaches to the Lanyard and doubles as a Name-Tag.</p><p>Please review the data before exporting and if there are any concerns, please ask for assistance.</p><p> Click here to export and save this table as Comma-Separated-Values<a href="admin/booklet-export/csv"><button>Save Export(csv)</button></a></p><p> Click here to export and save this table as an Excel file<a href="admin/booklet-export/xls"><button>Save Export (xls)</button></a></p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'admin/booklet-export';

  /* Display: Export and Save (csv) */
  $handler = $view->new_display('views_data_export', 'Export and Save (csv)', 'views_data_export_1');
  $handler->display->display_options['display_description'] = 'Export and Save Data as CSV';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'TItle';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_session_speakers_target_id';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_session_speakers_target_id';
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['relationship'] = 'field_session_speakers_target_id';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  /* Field: Content: Experience Level */
  $handler->display->display_options['fields']['field_session_experience_level']['id'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['field'] = 'field_session_experience_level';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot']['id'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot']['label'] = 'startDate';
  $handler->display->display_options['fields']['field_timeslot']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_1']['id'] = 'field_timeslot_1';
  $handler->display->display_options['fields']['field_timeslot_1']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot_1']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot_1']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot_1']['label'] = 'endDate';
  $handler->display->display_options['fields']['field_timeslot_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['path'] = 'admin/booklet-export/csv';

  /* Display: Export and Save (xls) */
  $handler = $view->new_display('views_data_export', 'Export and Save (xls)', 'views_data_export_2');
  $handler->display->display_options['display_description'] = 'Export and Save Data as CSV';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-full.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'TItle';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_ref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_session_speakers_target_id';
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_session_speakers_target_id';
  $handler->display->display_options['fields']['field_last_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['relationship'] = 'field_session_speakers_target_id';
  $handler->display->display_options['fields']['field_registration_do_username']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_registration_do_username']['element_default_classes'] = FALSE;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_session_room_ref']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_session_track']['element_default_classes'] = FALSE;
  /* Field: Content: Experience Level */
  $handler->display->display_options['fields']['field_session_experience_level']['id'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['field'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_session_experience_level']['element_default_classes'] = FALSE;
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot']['id'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot']['label'] = 'startDate';
  $handler->display->display_options['fields']['field_timeslot']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_1']['id'] = 'field_timeslot_1';
  $handler->display->display_options['fields']['field_timeslot_1']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot_1']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot_1']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot_1']['label'] = 'endDate';
  $handler->display->display_options['fields']['field_timeslot_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['path'] = 'admin/booklet-export/xls';
  $export['booklet_export'] = $view;

  $view = new view();
  $view->name = 'proposed_sessions';
  $view->description = 'Public facing listings of sessions.';
  $view->tag = 'tcdrupalschedule, sessions';
  $view->base_table = 'node';
  $view->human_name = 'Sessions: Proposed & Accepted public pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Proposed Sessions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<em>No sessions have been submitted yet.  Make yours the first!</em>';
  $handler->display->display_options['empty']['area']['format'] = 'script';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = ' [body]';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<a>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  /* Field: Content: Session Length */
  $handler->display->display_options['fields']['field_session_length']['id'] = 'field_session_length';
  $handler->display->display_options['fields']['field_session_length']['table'] = 'field_data_field_session_length';
  $handler->display->display_options['fields']['field_session_length']['field'] = 'field_session_length';
  $handler->display->display_options['fields']['field_session_length']['label'] = 'Length';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page - Proposed */
  $handler = $view->new_display('page', 'Page - Proposed', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'sessions/proposed';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Proposed Sessions';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Schedule';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Page - Accepted */
  $handler = $view->new_display('page', 'Page - Accepted', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'sessions/accepted';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Accepted Sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Sessions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['proposed_sessions'] = $view;

  $view = new view();
  $view->name = 'schedule_table';
  $view->description = 'The main public Schedule page.';
  $view->tag = 'tcdrupalschedule';
  $view->base_table = 'node';
  $view->human_name = 'Schedule';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Schedule';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_day',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_timeslot_ref',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'path' => 'path',
    'field_session_track' => 'field_session_track',
    'title' => 'title',
    'field_session_track_1' => 'title',
    'field_session_speakers' => 'field_session_speakers',
    'field_timeslot_ref' => 'field_timeslot_ref',
    'field_session_room_ref' => 'field_session_room_ref',
    'ops' => 'ops',
    'field_day' => 'field_day',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'field_session_track_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_speakers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_timeslot_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_room_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_day' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['id'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['field'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['relationships']['field_timeslot_ref_target_id']['label'] = 'Timeslot';
  /* Relationship: Content: Room (field_session_room_ref) */
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['id'] = 'field_session_room_ref_tid';
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['field'] = 'field_session_room_ref_tid';
  $handler->display->display_options['relationships']['field_session_room_ref_tid']['label'] = 'Room';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['label'] = '';
  $handler->display->display_options['fields']['field_session_track']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_track']['element_label_colon'] = FALSE;
  /* Field: Track (Key) */
  $handler->display->display_options['fields']['field_session_track_1']['id'] = 'field_session_track_1';
  $handler->display->display_options['fields']['field_session_track_1']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track_1']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track_1']['ui_name'] = 'Track (Key)';
  $handler->display->display_options['fields']['field_session_track_1']['label'] = '';
  $handler->display->display_options['fields']['field_session_track_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_track_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session_track_1']['type'] = 'list_key';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Session';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[path]">[title]</a> <span class="track track-[field_session_track_1]">[field_session_track]</span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['label'] = 'Speaker(s)';
  $handler->display->display_options['fields']['field_session_speakers']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_session_speakers']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'My schedule';
  /* Sort criterion: Content: Timeslot -  start date (field_timeslot) */
  $handler->display->display_options['sorts']['field_timeslot_value']['id'] = 'field_timeslot_value';
  $handler->display->display_options['sorts']['field_timeslot_value']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['sorts']['field_timeslot_value']['field'] = 'field_timeslot_value';
  $handler->display->display_options['sorts']['field_timeslot_value']['relationship'] = 'field_timeslot_ref_target_id';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_session_room_ref_tid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'schedule_item' => 'schedule_item',
    'session' => 'session',
  );
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );

  /* Display: 2016 Schedule Page */
  $handler = $view->new_display('page', '2016 Schedule Page', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['label'] = '';
  $handler->display->display_options['fields']['field_session_track']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_track']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Schedule';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[path]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Track (Key) */
  $handler->display->display_options['fields']['field_session_track_1']['id'] = 'field_session_track_1';
  $handler->display->display_options['fields']['field_session_track_1']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track_1']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track_1']['ui_name'] = 'Track (Key)';
  $handler->display->display_options['fields']['field_session_track_1']['label'] = '';
  $handler->display->display_options['fields']['field_session_track_1']['element_label_colon'] = FALSE;
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['label'] = 'Speaker(s)';
  $handler->display->display_options['fields']['field_session_speakers']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_session_speakers']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_session_speakers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_session_speakers']['separator'] = '<br />';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['label'] = 'Location';
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Content: Day of week */
  $handler->display->display_options['fields']['field_day']['id'] = 'field_day';
  $handler->display->display_options['fields']['field_day']['table'] = 'field_data_field_day';
  $handler->display->display_options['fields']['field_day']['field'] = 'field_day';
  $handler->display->display_options['fields']['field_day']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_day']['label'] = '';
  $handler->display->display_options['fields']['field_day']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_day']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_day']['alter']['text'] = '<h2>[field_day-value]</h2>';
  $handler->display->display_options['fields']['field_day']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_day']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'schedule_item' => 'schedule_item',
    'session' => 'session',
  );
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = '2016-schedule';
  $handler->display->display_options['menu']['title'] = 'Schedule';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Schedule';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: 2017 Schedule */
  $handler = $view->new_display('page', '2017 Schedule', '2017_schedule');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = 'groupby: nid';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_day_of_week',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_timeslot',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'path' => 'path',
    'field_timeslot' => 'field_timeslot',
    'field_day_of_week' => 'field_day_of_week',
    'title' => 'title',
    'field_session_speakers' => 'field_session_speakers',
    'field_session_room_ref' => 'field_session_room_ref',
    'field_session_track' => 'field_session_track',
    'body' => 'body',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'path' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timeslot' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_day_of_week' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br/>',
      'empty_column' => 0,
    ),
    'field_session_speakers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_session_room_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_session_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Day of week */
  $handler->display->display_options['fields']['field_day_of_week']['id'] = 'field_day_of_week';
  $handler->display->display_options['fields']['field_day_of_week']['table'] = 'field_data_field_day_of_week';
  $handler->display->display_options['fields']['field_day_of_week']['field'] = 'field_day_of_week';
  $handler->display->display_options['fields']['field_day_of_week']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_day_of_week']['label'] = '';
  $handler->display->display_options['fields']['field_day_of_week']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_day_of_week']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_day_of_week']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_day_of_week']['hide_empty'] = TRUE;
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot']['id'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['field'] = 'field_timeslot';
  $handler->display->display_options['fields']['field_timeslot']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['fields']['field_timeslot']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="[path]">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['label'] = '';
  $handler->display->display_options['fields']['field_session_speakers']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_speakers']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_session_speakers']['alter']['text'] = '<span class="item">[field_session_speakers]</span>';
  $handler->display->display_options['fields']['field_session_speakers']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_session_speakers']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_session_speakers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_session_speakers']['separator'] = '';
  /* Field: Speaker Conditional */
  $handler->display->display_options['fields']['views_conditional']['id'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional']['ui_name'] = 'Speaker Conditional';
  $handler->display->display_options['fields']['views_conditional']['label'] = '';
  $handler->display->display_options['fields']['views_conditional']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_conditional']['if'] = 'field_session_speakers';
  $handler->display->display_options['fields']['views_conditional']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional']['then'] = '<li><span>Speaker(s): </span>[field_session_speakers]</li>';
  $handler->display->display_options['fields']['views_conditional']['strip_tags'] = 0;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['label'] = '';
  $handler->display->display_options['fields']['field_session_room_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_room_ref']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_session_room_ref']['alter']['text'] = '<span class="item">Room [field_session_room_ref]</span>';
  $handler->display->display_options['fields']['field_session_room_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_session_room_ref']['separator'] = '';
  /* Field: Location Conditional */
  $handler->display->display_options['fields']['views_conditional_1']['id'] = 'views_conditional_1';
  $handler->display->display_options['fields']['views_conditional_1']['table'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['field'] = 'views_conditional';
  $handler->display->display_options['fields']['views_conditional_1']['ui_name'] = 'Location Conditional';
  $handler->display->display_options['fields']['views_conditional_1']['label'] = '';
  $handler->display->display_options['fields']['views_conditional_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_conditional_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['views_conditional_1']['if'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['views_conditional_1']['condition'] = '6';
  $handler->display->display_options['fields']['views_conditional_1']['then'] = '<li><span>Location: </span>[field_session_room_ref]</li>';
  $handler->display->display_options['fields']['views_conditional_1']['strip_tags'] = 0;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['label'] = '';
  $handler->display->display_options['fields']['field_session_track']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_session_track']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_session_track']['alter']['text'] = '<li><span>Track:</span> [field_session_track]</li>';
  $handler->display->display_options['fields']['field_session_track']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<a><b><em><i><strong>';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3><a href="[path]">[title]</a></h3>
<ul>
[views_conditional]
[views_conditional_1]
[field_session_track]
</ul>
[body]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
    'schedule_item' => 'schedule_item',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_session_accepted_value']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Content: Track (field_session_track) */
  $handler->display->display_options['filters']['field_session_track_value']['id'] = 'field_session_track_value';
  $handler->display->display_options['filters']['field_session_track_value']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['filters']['field_session_track_value']['field'] = 'field_session_track_value';
  $handler->display->display_options['filters']['field_session_track_value']['group'] = 1;
  $handler->display->display_options['filters']['field_session_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_session_track_value']['expose']['operator_id'] = 'field_session_track_value_op';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['operator'] = 'field_session_track_value_op';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['identifier'] = 'field_session_track_value';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_session_track_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_session_track_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Day of week (field_day_of_week) */
  $handler->display->display_options['filters']['field_day_of_week_value']['id'] = 'field_day_of_week_value';
  $handler->display->display_options['filters']['field_day_of_week_value']['table'] = 'field_data_field_day_of_week';
  $handler->display->display_options['filters']['field_day_of_week_value']['field'] = 'field_day_of_week_value';
  $handler->display->display_options['filters']['field_day_of_week_value']['relationship'] = 'field_timeslot_ref_target_id';
  $handler->display->display_options['filters']['field_day_of_week_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_day_of_week_value']['expose']['operator_id'] = 'field_day_of_week_value_op';
  $handler->display->display_options['filters']['field_day_of_week_value']['expose']['label'] = 'Day';
  $handler->display->display_options['filters']['field_day_of_week_value']['expose']['operator'] = 'field_day_of_week_value_op';
  $handler->display->display_options['filters']['field_day_of_week_value']['expose']['identifier'] = 'field_day_of_week_value';
  $handler->display->display_options['filters']['field_day_of_week_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_day_of_week_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_day_of_week_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['path'] = 'schedule';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Schedule';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Schedule';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['schedule_table'] = $view;

  $view = new view();
  $view->name = 'session_admin';
  $view->description = 'Admin list of sessions.';
  $view->tag = 'tcdrupalschedule, admin, sessions';
  $view->base_table = 'node';
  $view->human_name = 'Session admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sessions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access content overview';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'body' => 'title',
    'name' => 'name',
    'mail' => 'mail',
    'field_session_speakers' => 'field_session_speakers',
    'field_session_track' => 'field_session_track',
    'field_session_experience_level' => 'field_session_experience_level',
    'created' => 'created',
    'field_timeslot_ref' => 'field_timeslot_ref',
    'field_session_room_ref' => 'field_session_room_ref',
    'edit_node' => 'edit_node',
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'field_session_accepted' => 'field_session_accepted',
    'field_session_confirmed' => 'field_session_confirmed',
  );
  $handler->display->display_options['style_options']['default'] = 'nid';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_speakers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_track' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_experience_level' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timeslot_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_room_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_accepted' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_confirmed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'session::field_timeslot_ref' => 'session::field_timeslot_ref',
          'session::field_session_track' => 'session::field_session_track',
          'session::field_session_accepted' => 'session::field_session_accepted',
          'session::field_session_room_ref' => 'session::field_session_room_ref',
          'session::field_session_confirmed' => 'session::field_session_confirmed',
        ),
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Count';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_session_speakers']['multi_type'] = 'ul';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'author';
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  /* Field: Content: Experience Level */
  $handler->display->display_options['fields']['field_session_experience_level']['id'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['field'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['label'] = 'Level';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Content: Accepted */
  $handler->display->display_options['fields']['field_session_accepted']['id'] = 'field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['field'] = 'field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_session_accepted']['type'] = 'list_key';
  /* Field: Content: Confirmed by presenter */
  $handler->display->display_options['fields']['field_session_confirmed']['id'] = 'field_session_confirmed';
  $handler->display->display_options['fields']['field_session_confirmed']['table'] = 'field_data_field_session_confirmed';
  $handler->display->display_options['fields']['field_session_confirmed']['field'] = 'field_session_confirmed';
  $handler->display->display_options['fields']['field_session_confirmed']['label'] = 'Confirmed';
  $handler->display->display_options['fields']['field_session_confirmed']['empty_zero'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Email';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Email template';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'admin/content/sessions/email/[nid]';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Experience Level (field_session_experience_level) */
  $handler->display->display_options['filters']['field_session_experience_level_value']['id'] = 'field_session_experience_level_value';
  $handler->display->display_options['filters']['field_session_experience_level_value']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['filters']['field_session_experience_level_value']['field'] = 'field_session_experience_level_value';
  $handler->display->display_options['filters']['field_session_experience_level_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_session_experience_level_value']['expose']['operator_id'] = 'field_session_experience_level_value_op';
  $handler->display->display_options['filters']['field_session_experience_level_value']['expose']['label'] = 'Experience Level';
  $handler->display->display_options['filters']['field_session_experience_level_value']['expose']['operator'] = 'field_session_experience_level_value_op';
  $handler->display->display_options['filters']['field_session_experience_level_value']['expose']['identifier'] = 'field_session_experience_level_value';
  $handler->display->display_options['filters']['field_session_experience_level_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Track (field_session_track) */
  $handler->display->display_options['filters']['field_session_track_value']['id'] = 'field_session_track_value';
  $handler->display->display_options['filters']['field_session_track_value']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['filters']['field_session_track_value']['field'] = 'field_session_track_value';
  $handler->display->display_options['filters']['field_session_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_session_track_value']['expose']['operator_id'] = 'field_session_track_value_op';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['operator'] = 'field_session_track_value_op';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['identifier'] = 'field_session_track_value';
  $handler->display->display_options['filters']['field_session_track_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_session_accepted_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['operator_id'] = 'field_session_accepted_value_op';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['label'] = 'Accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['operator'] = 'field_session_accepted_value_op';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['identifier'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Timeslot -  start date (field_timeslot) */
  $handler->display->display_options['filters']['field_timeslot_value']['id'] = 'field_timeslot_value';
  $handler->display->display_options['filters']['field_timeslot_value']['table'] = 'field_data_field_timeslot';
  $handler->display->display_options['filters']['field_timeslot_value']['field'] = 'field_timeslot_value';
  $handler->display->display_options['filters']['field_timeslot_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_timeslot_value']['expose']['operator_id'] = 'field_timeslot_value_op';
  $handler->display->display_options['filters']['field_timeslot_value']['expose']['label'] = 'Timeslot';
  $handler->display->display_options['filters']['field_timeslot_value']['expose']['operator'] = 'field_timeslot_value_op';
  $handler->display->display_options['filters']['field_timeslot_value']['expose']['identifier'] = 'field_timeslot_value';
  $handler->display->display_options['filters']['field_timeslot_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page: admin listing */
  $handler = $view->new_display('page', 'Page: admin listing', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/sessions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/content/sessions/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'tcdrupal_sessions.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Summary';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Experience Level */
  $handler->display->display_options['fields']['field_session_experience_level']['id'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['table'] = 'field_data_field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['field'] = 'field_session_experience_level';
  $handler->display->display_options['fields']['field_session_experience_level']['label'] = 'Level';
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/sessions/export-tabs';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Page: email template */
  $handler = $view->new_display('page', 'Page: email template', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['type'] = 'text_plain';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['label'] = '';
  $handler->display->display_options['fields']['field_timeslot_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timeslot_ref']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: Content: Accepted */
  $handler->display->display_options['fields']['field_session_accepted']['id'] = 'field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['field'] = 'field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['label'] = 'Body';
  $handler->display->display_options['fields']['field_session_accepted']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_session_accepted']['alter']['text'] = 'Hey [field_first_name],

I\'m please to tell you that after reviewing the 50+ sessions submitted for Twin Cities Drupal Camp on June 23-26, we\'ve settled on a schedule and your session was accepted. Yay!

Session: [title]
Time slot: [field_timeslot_ref]

What next?

First off, please reply ASAP to confirm that you can indeed present this session at the scheduled time. If there is a problem, we\'ll work with you to either re-schedule or find a replacement.

We would also really appreciate it if you could give your session description another look and make sure it\'s all up-to-snuff. Better descriptions will help us attract more people to the camp and help you to attract people to your session.

Here\'s a quick link for that: http://2016.tcdrupal.org/node/!1/edit

Once you\'ve done that, here are some other things you should do:

- Make sure you\'re registered for the camp! If you haven\'t registered for camp, use this coupon code: PURPLE2016

- If you\'ve already paid for your camp registration, we are willing to refund your registration fee. Shoot us an email and we’ll get the process started.

- Start working on your slides!

- We\'re hosting an appreciation dinner on Thursday, June 23 at 6:30PM at Town Hall Brewery, just a short walk from the venue. Please come! We\'ll send out an email with more details closer to the camp.

- Let us know if you have any questions or concerns: contact@tcdrupal.org

Don\'t know where to start preparing your presentation or just need some help brushing up? Here are some helpful resources:
http://2016.tcdrupal.org/speaker-resources

Note: For people who submitted a session with more than one speaker, we\'re only emailing the person who submitted the session. Coordinate with your cohorts as you will.

Again, on behalf of the whole Twin Cities Drupal Camp organizing team, thank you!

And please reach out if you\'ve got any questions at all. We\'ll do our best to answer them.

Best,
Les Lim
Twin Cities Drupal Camp';
  $handler->display->display_options['fields']['field_session_accepted']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_session_accepted']['element_type'] = '0';
  $handler->display->display_options['fields']['field_session_accepted']['empty'] = 'Hey, [field_first_name],

Just letting you know that we\'ve selected our sessions for Twin Cities Drupal Camp on June 23-26, and I\'m sorry to say that your submission didn\'t make the cut. 

We\'d like to thank you for being willing to commit your time and effort to making this year\'s camp the best it can be, so we\'re offering you a coupon code for $25 off the cost of registration:

TCDC25

I hope we see you this summer!

Les Lim
Twin Cities Drupal Camp';
  $handler->display->display_options['fields']['field_session_accepted']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_session_accepted']['type'] = 'list_key';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Subject';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'TC Drupal Camp Session Accepted: [title]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/content/sessions/email/%';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['session_admin'] = $view;

  $view = new view();
  $view->name = 'session_mailer';
  $view->description = 'A VBO for emailing people about their sessions being accepted or rejected.';
  $view->tag = 'tcdrupalschedule, admin, sessions';
  $view->base_table = 'node';
  $view->human_name = 'Session Selection Mailer';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Session Mailer';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'mail' => 'mail',
    'field_session_accepted' => 'field_session_accepted',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_accepted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Session';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Accepted */
  $handler->display->display_options['fields']['field_session_accepted']['id'] = 'field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['field'] = 'field_session_accepted';
  $handler->display->display_options['fields']['field_session_accepted']['label'] = 'Accepted?';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Submitter';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_session_accepted_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['operator_id'] = 'field_session_accepted_value_op';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['label'] = 'Accepted or Rejected';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['operator'] = 'field_session_accepted_value_op';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['identifier'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_session_accepted_value']['expose']['reduce'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/sessions/session-mailer';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Session Selection Mailer';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['session_mailer'] = $view;

  $view = new view();
  $view->name = 'session_speakers';
  $view->description = 'Display the lists of speakers associated with a given session.';
  $view->tag = 'tcdrupalschedule, sessions';
  $view->base_table = 'users';
  $view->human_name = 'Session Speakers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presenters';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_registration_do_username' => 'field_registration_do_username',
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_session_speakers_node']['id'] = 'reverse_field_session_speakers_node';
  $handler->display->display_options['relationships']['reverse_field_session_speakers_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_session_speakers_node']['field'] = 'reverse_field_session_speakers_node';
  $handler->display->display_options['relationships']['reverse_field_session_speakers_node']['label'] = 'Session';
  $handler->display->display_options['relationships']['reverse_field_session_speakers_node']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['text'] = '<label><strong>Name</strong></label>: [field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['label'] = 'Drupal';
  $handler->display->display_options['fields']['field_registration_do_username']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_registration_do_username']['hide_empty'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_session_speakers_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'session' => 'session',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['session_speakers'] = $view;

  $view = new view();
  $view->name = 'tcdrupalschedule_user_sessions';
  $view->description = 'Blocks for the user page showing sessions that the user has submitted.';
  $view->tag = 'tcdrupalschedule';
  $view->base_table = 'node';
  $view->human_name = 'Sessions: user page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>You have not proposed any sessions. <a href="/node/add/session?destination=user">Go submit one now!</a></p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Session Proposal';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_session_track']['id'] = 'field_session_track';
  $handler->display->display_options['fields']['field_session_track']['table'] = 'field_data_field_session_track';
  $handler->display->display_options['fields']['field_session_track']['field'] = 'field_session_track';
  /* Field: Content: Session Length */
  $handler->display->display_options['fields']['field_session_length']['id'] = 'field_session_length';
  $handler->display->display_options['fields']['field_session_length']['table'] = 'field_data_field_session_length';
  $handler->display->display_options['fields']['field_session_length']['field'] = 'field_session_length';
  $handler->display->display_options['fields']['field_session_length']['label'] = 'Length';
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'delete';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] | [delete_node]';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Proposed Sessions';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Block - Accepted */
  $handler = $view->new_display('block', 'Block - Accepted', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Session Proposal';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_session_speakers']['id'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['table'] = 'field_data_field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['field'] = 'field_session_speakers';
  $handler->display->display_options['fields']['field_session_speakers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_session_speakers']['delta_offset'] = '0';
  /* Field: Content: Timeslot */
  $handler->display->display_options['fields']['field_timeslot_ref']['id'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['table'] = 'field_data_field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['field'] = 'field_timeslot_ref';
  $handler->display->display_options['fields']['field_timeslot_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_timeslot_ref']['delta_offset'] = '0';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room_ref']['id'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['table'] = 'field_data_field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['field'] = 'field_session_room_ref';
  $handler->display->display_options['fields']['field_session_room_ref']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_session_room_ref']['delta_offset'] = '0';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_node']['text'] = 'delete';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] | [delete_node]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Accepted (field_session_accepted) */
  $handler->display->display_options['filters']['field_session_accepted_value']['id'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['table'] = 'field_data_field_session_accepted';
  $handler->display->display_options['filters']['field_session_accepted_value']['field'] = 'field_session_accepted_value';
  $handler->display->display_options['filters']['field_session_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'accepted sessions';
  $export['tcdrupalschedule_user_sessions'] = $view;

  return $export;
}
