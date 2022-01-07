<?php
/**
 * @file
 * tcdrupaltraining.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tcdrupaltraining_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'export_class_data';
  $view->description = '';
  $view->tag = 'tcdrupalregistration, admin, registration, training, export';
  $view->base_table = 'registration';
  $view->human_name = 'Training registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Training registrations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_company' => 'field_company',
    'mail' => 'mail',
    'created' => 'created',
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_company' => array(
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
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
  $handler->display->display_options['empty']['area']['content'] = '<em>No signups yet.</em>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Registration: Author entity author_uid */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'registration';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'registration';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['label'] = 'Resgistered User';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'user';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'user';
  /* Field: User: Company/Organization */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_company']['label'] = 'Company';
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['relationship'] = 'user';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'user';
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Signup date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: User: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['relationship'] = 'author';
  /* Sort criterion: User: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['relationship'] = 'author';
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['group'] = 1;
  $handler->display->display_options['filters']['entity_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_id']['expose']['operator_id'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['label'] = 'Host entity ID';
  $handler->display->display_options['filters']['entity_id']['expose']['operator'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['identifier'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['entity_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['entity_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['entity_id']['group_info']['label'] = 'Select a training';
  $handler->display->display_options['filters']['entity_id']['group_info']['identifier'] = 'group';
  $handler->display->display_options['filters']['entity_id']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['entity_id']['group_info']['default_group'] = '1';
  $handler->display->display_options['filters']['entity_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Higher Education Summit',
      'operator' => '=',
      'value' => array(
        'value' => '900',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Build A Module Training',
      'operator' => '=',
      'value' => array(
        'value' => '201',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Drupal 8 Module Building',
      'operator' => '=',
      'value' => array(
        'value' => '897',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => 'Intro to Backdrop CMS',
      'operator' => '=',
      'value' => array(
        'value' => '200',
        'min' => '',
        'max' => '',
      ),
    ),
    5 => array(
      'title' => 'Drupal Development Best Practices & Building Sites on Pantheon',
      'operator' => '=',
      'value' => array(
        'value' => '290',
        'min' => '',
        'max' => '',
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'user';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'user';
  /* Field: User: Company/Organization */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_company']['label'] = 'Company';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'user';
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Signup date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user';
  $handler->display->display_options['path'] = 'admin/registrations/classes-export';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Trainings';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export (CSV) */
  $handler = $view->new_display('views_data_export', 'Data export (CSV)', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/content/registration/classes-export/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export (XLS) */
  $handler = $view->new_display('views_data_export', 'Data export (XLS)', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/content/registration/classes-export/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['export_class_data'] = $view;

  $view = new view();
  $view->name = 'training_for_me';
  $view->description = 'User page block that indicates the user\'s Thursday training, if registered. If not registered, lists trainings to register for.';
  $view->tag = 'tcdrupalregistration';
  $view->base_table = 'registration';
  $view->human_name = 'Training: user page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Thursday Event';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<span></span>';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Contextual filter: Registration: User_uid */
  $handler->display->display_options['arguments']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['table'] = 'registration';
  $handler->display->display_options['arguments']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user_uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['user_uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['user_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Registration: Registration type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'registration';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training' => 'training',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Thursday trainings/summits have not yet been announced. Check back soon!</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';

  /* Display: Attachment: 201 */
  $handler = $view->new_display('attachment', 'Attachment: 201', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<p>You are currently registered for the "Build a Module Workshop" training. <a href="/registration/[registration_id]/delete?destination=user">You may cancel this registration</a> and register for a different training.</p>';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '201';
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachment: 200 */
  $handler = $view->new_display('attachment', 'Attachment: 200', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<p>You are currently registered for the "Intro to Backdrop CMS" training. <a href="/registration/[registration_id]/delete?destination=user">You may cancel this registration</a> and register for a different training.</p>';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '200';
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachment: 290 */
  $handler = $view->new_display('attachment', 'Attachment: 290', 'attachment_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<p>You are currently registered for the "Drupal Development Best Practices & Building Sites on Pantheon" training. <a href="/registration/[registration_id]/delete?destination=user">You may cancel this registration</a> and register for a different training.</p>';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '290';
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachment: 897 */
  $handler = $view->new_display('attachment', 'Attachment: 897', 'attachment_4');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<p>You are currently registered for the "Drupal 8 Module Building" training. <a href="/registration/[registration_id]/delete?destination=user">You may cancel this registration</a> and register for a different training.</p>';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '897';
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Attachment: 900 */
  $handler = $view->new_display('attachment', 'Attachment: 900', 'attachment_5');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<p>You are currently registered for the Higher Education Summit. <a href="/registration/[registration_id]/delete?destination=user">You may cancel this registration</a> and register for a Thursday training instead.</p>';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '900';
  $handler->display->display_options['displays'] = array(
    'block' => 'block',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['training_for_me'] = $view;

  return $export;
}
