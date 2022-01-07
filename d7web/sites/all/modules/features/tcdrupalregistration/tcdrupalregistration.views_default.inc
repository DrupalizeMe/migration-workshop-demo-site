<?php
/**
 * @file
 * tcdrupalregistration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tcdrupalregistration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_commerce_order_coupon_use';
  $view->description = 'Used to determine who has used a particular coupon code, which can then be reported to the coupon purchaser.';
  $view->tag = 'tcdrupalregistration, admin, registration, coupon';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Coupons used';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Coupon use';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any commerce_order entity of bundle commerce_order';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Date registered';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: User: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['relationship'] = 'uid';
  /* Filter criterion: Commerce Line Item: Label */
  $handler->display->display_options['filters']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['filters']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['filters']['line_item_label']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['line_item_label']['operator'] = 'contains';
  $handler->display->display_options['filters']['line_item_label']['exposed'] = TRUE;
  $handler->display->display_options['filters']['line_item_label']['expose']['operator_id'] = 'line_item_label_op';
  $handler->display->display_options['filters']['line_item_label']['expose']['label'] = 'Coupon code ';
  $handler->display->display_options['filters']['line_item_label']['expose']['operator'] = 'line_item_label_op';
  $handler->display->display_options['filters']['line_item_label']['expose']['identifier'] = 'line_item_label';
  $handler->display->display_options['filters']['line_item_label']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Commerce Line Item: Label */
  $handler->display->display_options['filters']['line_item_label_1']['id'] = 'line_item_label_1';
  $handler->display->display_options['filters']['line_item_label_1']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['line_item_label_1']['field'] = 'line_item_label';
  $handler->display->display_options['filters']['line_item_label_1']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['line_item_label_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['line_item_label_1']['value'] = 'coupon';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/commerce/coupons/used';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Coupon uses';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_commerce_order_coupon_use'] = $view;

  $view = new view();
  $view->name = 'admin_registrations';
  $view->description = 'Admin listing of all registration entities.';
  $view->tag = 'admin';
  $view->base_table = 'registration';
  $view->human_name = 'Admin: Registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin: Registration entities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer registration';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'registration_id' => 'registration_id',
    'entity_id' => 'entity_id',
    'entity_type' => 'entity_type',
    'state' => 'state',
    'user' => 'user',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'registration_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user' => array(
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
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'registration';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Bulk operations: Registration */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'registration';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '50';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  /* Field: Registration: Host entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'registration';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['separator'] = '';
  /* Field: Registration: Host entity type */
  $handler->display->display_options['fields']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['fields']['entity_type']['table'] = 'registration';
  $handler->display->display_options['fields']['entity_type']['field'] = 'entity_type';
  /* Field: Registration: State entity */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'registration';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['user']['id'] = 'user';
  $handler->display->display_options['fields']['user']['table'] = 'registration';
  $handler->display->display_options['fields']['user']['field'] = 'user';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Registration: Host entity type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['group'] = 1;
  $handler->display->display_options['filters']['entity_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_type']['expose']['operator_id'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['label'] = 'Host entity type';
  $handler->display->display_options['filters']['entity_type']['expose']['operator'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['identifier'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['entity_type']['group_info']['label'] = 'Host entity type';
  $handler->display->display_options['filters']['entity_type']['group_info']['identifier'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Node',
      'operator' => '=',
      'value' => 'node',
    ),
    2 => array(
      'title' => 'Commerce Product',
      'operator' => '=',
      'value' => 'commerce_product',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
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
  $handler->display->display_options['filters']['entity_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/registrations/manage';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Admin listing';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['admin_registrations'] = $view;

  $view = new view();
  $view->name = 'badges';
  $view->description = '';
  $view->tag = 'tcdrupalregistration, admin, registration, export';
  $view->base_table = 'registration';
  $view->human_name = 'Camp registrations: exports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Camp Registration Exports';
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
    'field_registration_do_username' => 'field_registration_do_username',
    'mail' => 'mail',
    'field_attend_party_saturday' => 'field_attend_party_saturday',
    'field_attend_sprint' => 'field_attend_sprint',
    'field_reg_shirt_size' => 'field_reg_shirt_size',
    'entity_id' => 'entity_id',
    'edit_order' => 'edit_order',
    'created' => 'created',
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
    'field_registration_do_username' => array(
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
    'field_attend_party_saturday' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attend_sprint' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reg_shirt_size' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_order' => array(
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
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '16 = Regular Camp Registrations
17 = Community Sponsor Registrations';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No registrations found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Registration: Author entity author_uid */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'registration';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  $handler->display->display_options['relationships']['author']['label'] = 'Purchaser';
  /* Relationship: Registration: Commerce Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'registration';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'registration';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['label'] = 'Resgistered User';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'user';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'user';
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
  /* Field: Registration: I plan to attend the Saturday evening party */
  $handler->display->display_options['fields']['field_attend_party_saturday']['id'] = 'field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['table'] = 'field_data_field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['field'] = 'field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['label'] = 'I plan to attend the party on Friday evening';
  /* Field: Registration: I plan to attend the sprint on Sunday */
  $handler->display->display_options['fields']['field_attend_sprint']['id'] = 'field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['table'] = 'field_data_field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['field'] = 'field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['type'] = 'list_key';
  /* Field: Registration: Shirt Size */
  $handler->display->display_options['fields']['field_reg_shirt_size']['id'] = 'field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['table'] = 'field_data_field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['field'] = 'field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['type'] = 'list_key';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['path'] = 'registration/[registration_id]';
  /* Field: Registration: Host entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'registration';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['edit_order']['label'] = 'Order link';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'edit order';
  $handler->display->display_options['fields']['edit_order']['text'] = 'edit order';
  /* Sort criterion: Registration: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'registration';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['operator'] = 'between';
  $handler->display->display_options['filters']['entity_id']['value']['min'] = '16';
  $handler->display->display_options['filters']['entity_id']['value']['max'] = '17';
  $handler->display->display_options['filters']['entity_id']['expose']['operator_id'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['label'] = 'Host entity ID';
  $handler->display->display_options['filters']['entity_id']['expose']['operator'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['identifier'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Registration: User_uid */
  $handler->display->display_options['fields']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['fields']['user_uid']['table'] = 'registration';
  $handler->display->display_options['fields']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['fields']['user_uid']['label'] = '';
  $handler->display->display_options['fields']['user_uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['user_uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['user_uid']['separator'] = '';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'user/[user_uid]';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'user';
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
  /* Field: Registration: I plan to attend the Saturday evening party */
  $handler->display->display_options['fields']['field_attend_party_saturday']['id'] = 'field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['table'] = 'field_data_field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['field'] = 'field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['label'] = 'I plan to attend the party on Friday evening';
  /* Field: Registration: I plan to attend the sprint on Sunday */
  $handler->display->display_options['fields']['field_attend_sprint']['id'] = 'field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['table'] = 'field_data_field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['field'] = 'field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['type'] = 'list_key';
  /* Field: Registration: Shirt Size */
  $handler->display->display_options['fields']['field_reg_shirt_size']['id'] = 'field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['table'] = 'field_data_field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['field'] = 'field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['type'] = 'list_key';
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Register Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Registration: Host entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'registration';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['edit_order']['label'] = 'Order link';
  $handler->display->display_options['fields']['edit_order']['alter']['text'] = 'edit order';
  $handler->display->display_options['fields']['edit_order']['text'] = 'edit order';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['operator'] = 'between';
  $handler->display->display_options['filters']['entity_id']['value']['min'] = '16';
  $handler->display->display_options['filters']['entity_id']['value']['max'] = '17';
  $handler->display->display_options['filters']['entity_id']['expose']['operator_id'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['label'] = 'Host entity ID';
  $handler->display->display_options['filters']['entity_id']['expose']['operator'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['identifier'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['status_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    'canceled' => 'canceled',
  );
  $handler->display->display_options['path'] = 'admin/registrations/export';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Export Registration Info';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export (CSV) */
  $handler = $view->new_display('views_data_export', 'Data export (CSV)', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/content/registration/export/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: Data export (XLS) */
  $handler = $view->new_display('views_data_export', 'Data export (XLS)', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/content/registration/export/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['badges'] = $view;

  $view = new view();
  $view->name = 'camp_registrations';
  $view->description = '';
  $view->tag = 'tcdrupalregistration, admin, registration';
  $view->base_table = 'registration';
  $view->human_name = 'Camp registrations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Camp registrations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'name' => 'name',
    'field_registration_do_username' => 'field_registration_do_username',
    'field_company' => 'field_company',
    'field_attend_party_saturday' => 'field_attend_party_saturday',
    'field_attend_sprint' => 'field_attend_sprint',
    'url' => 'url',
    'created' => 'created',
    'commerce_order_total' => 'commerce_order_total',
    'edit_order' => 'edit_order',
    'views_bulk_operations_1' => 'views_bulk_operations_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
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
    'field_registration_do_username' => array(
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
    'field_attend_party_saturday' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_attend_sprint' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
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
    'commerce_order_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_order' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'There are @total registrations which match this criteria';
  /* Relationship: Registration: Author entity author_uid */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'registration';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  $handler->display->display_options['relationships']['author']['label'] = 'Purchaser';
  /* Relationship: Registration: Commerce Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'registration';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['relationship'] = 'order_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['label'] = 'Line Item';
  /* Relationship: Commerce Line item: Referenced products */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Field: Bulk operations: Registration */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'registration';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = 'Reg ID';
  $handler->display->display_options['fields']['registration_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Count';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'author';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'author';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['relationship'] = 'author';
  /* Field: User: Company/Organization */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['relationship'] = 'author';
  $handler->display->display_options['fields']['field_company']['label'] = 'Company';
  /* Field: Registration: I plan to attend the Friday evening party */
  $handler->display->display_options['fields']['field_attend_party_friday']['id'] = 'field_attend_party_friday';
  $handler->display->display_options['fields']['field_attend_party_friday']['table'] = 'field_data_field_attend_party_friday';
  $handler->display->display_options['fields']['field_attend_party_friday']['field'] = 'field_attend_party_friday';
  $handler->display->display_options['fields']['field_attend_party_friday']['label'] = 'Friday party';
  $handler->display->display_options['fields']['field_attend_party_friday']['type'] = 'list_key';
  /* Field: Registration: I plan to attend the Saturday evening party */
  $handler->display->display_options['fields']['field_attend_party_saturday']['id'] = 'field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['table'] = 'field_data_field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['field'] = 'field_attend_party_saturday';
  $handler->display->display_options['fields']['field_attend_party_saturday']['label'] = 'Saturday Party';
  $handler->display->display_options['fields']['field_attend_party_saturday']['type'] = 'list_key';
  /* Field: Registration: I plan to attend the sprint on Sunday */
  $handler->display->display_options['fields']['field_attend_sprint']['id'] = 'field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['table'] = 'field_data_field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['field'] = 'field_attend_sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['label'] = 'Sunday Sprint';
  $handler->display->display_options['fields']['field_attend_sprint']['type'] = 'list_key';
  /* Field: Registration: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_registration';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Registration';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Registration: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'registration';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/j/Y';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['edit_order']['label'] = 'Order';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id_1']['id'] = 'registration_id_1';
  $handler->display->display_options['fields']['registration_id_1']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id_1']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id_1']['label'] = 'Registration';
  $handler->display->display_options['fields']['registration_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id_1']['alter']['text'] = 'edit';
  $handler->display->display_options['fields']['registration_id_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['registration_id_1']['alter']['path'] = 'registration/[registration_id_1]/edit';
  $handler->display->display_options['fields']['registration_id_1']['separator'] = '';
  /* Sort criterion: Registration: Registration ID */
  $handler->display->display_options['sorts']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['sorts']['registration_id']['table'] = 'registration';
  $handler->display->display_options['sorts']['registration_id']['field'] = 'registration_id';
  /* Filter criterion: Registration: Registration type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'registration';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'paid_event' => 'paid_event',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by first name, last name, company or D.O user name.';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_registration_do_username' => 'field_registration_do_username',
    'field_company' => 'field_company',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['status']['value'] = array(
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Registration: I plan to attend the Saturday evening party (field_attend_party_saturday) */
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['id'] = 'field_attend_party_saturday_value';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['table'] = 'field_data_field_attend_party_saturday';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['field'] = 'field_attend_party_saturday_value';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['expose']['operator_id'] = 'field_attend_party_saturday_value_op';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['expose']['label'] = 'Party?';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['expose']['operator'] = 'field_attend_party_saturday_value_op';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['expose']['identifier'] = 'field_attend_party_saturday_value';
  $handler->display->display_options['filters']['field_attend_party_saturday_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );
  /* Filter criterion: Registration: Registration type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'registration';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'paid_event' => 'paid_event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/registrations/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Camp Registrations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Registrations';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['camp_registrations'] = $view;

  $view = new view();
  $view->name = 'registration_state';
  $view->description = 'This block displays on the "Register" page to indicate if the user has already registered themselves.';
  $view->tag = 'tcdrupalregistration, admin, registration';
  $view->base_table = 'registration';
  $view->human_name = 'Camp Registration: register page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Registration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="messages messages--status">Looks like you\'re already registered. That\'s awesome! If you would like to register on behalf of other people now, please purchase <a href="/register/coupons">registration vouchers</a> instead.</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = '<!-- intentionally left blank -->';
  $handler->display->display_options['fields']['registration_id']['alter']['path'] = 'registration/[registration_id]';
  $handler->display->display_options['fields']['registration_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['registration_id']['separator'] = '';
  /* Contextual filter: Registration: User_uid */
  $handler->display->display_options['arguments']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['table'] = 'registration';
  $handler->display->display_options['arguments']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['arguments']['user_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['user_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '16';
  $handler->display->display_options['filters']['entity_id']['group'] = 1;
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id_1']['id'] = 'entity_id_1';
  $handler->display->display_options['filters']['entity_id_1']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id_1']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id_1']['value']['value'] = '17';
  $handler->display->display_options['filters']['entity_id_1']['group'] = 1;
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );
  $handler->display->display_options['filters']['state']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['registration_state'] = $view;

  $view = new view();
  $view->name = 'registrations_for_me';
  $view->description = 'Block that shows on the User page to indicate if they have registered for camp.';
  $view->tag = 'tcdrupalregistration, registration';
  $view->base_table = 'registration';
  $view->human_name = 'Camp registration: user page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Camp Registration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>You are <strong>not yet registered</strong> for Twin Cities Drupal Camp. <a href="/register">Register now!</a></p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['label'] = '';
  $handler->display->display_options['fields']['registration_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['registration_id']['alter']['text'] = 'You are already registered for Twin Cities Drupal Camp 2017. Hooray!';
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
    'paid_event' => 'paid_event',
  );
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['registrations_for_me'] = $view;

  $view = new view();
  $view->name = 'tcdc_tshirts';
  $view->description = 'admin view of T-Shirt orders.';
  $view->tag = 'tcdrupalregistration, admin, shirt';
  $view->base_table = 'registration';
  $view->human_name = 'T-Shirts: Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'T-Shirts';
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
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_reg_shirt_size',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'registration_id' => 'registration_id',
    'field_reg_shirt_size' => 'field_reg_shirt_size',
    'user_uid' => 'user_uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'registration_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reg_shirt_size' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'user_uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'name' => array(
      'sortable' => 0,
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
  /* Relationship: Registration: Author entity author_uid */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'registration';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  /* Field: Registration: Shirt Size */
  $handler->display->display_options['fields']['field_reg_shirt_size']['id'] = 'field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['table'] = 'field_data_field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['field'] = 'field_reg_shirt_size';
  $handler->display->display_options['fields']['field_reg_shirt_size']['type'] = 'list_key';
  /* Field: Registration: User_uid */
  $handler->display->display_options['fields']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['fields']['user_uid']['table'] = 'registration';
  $handler->display->display_options['fields']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['fields']['user_uid']['separator'] = '';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'author';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Registration: Host entity ID */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'registration';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );
  /* Filter criterion: Registration: Shirt Size (field_reg_shirt_size) */
  $handler->display->display_options['filters']['field_reg_shirt_size_value']['id'] = 'field_reg_shirt_size_value';
  $handler->display->display_options['filters']['field_reg_shirt_size_value']['table'] = 'field_data_field_reg_shirt_size';
  $handler->display->display_options['filters']['field_reg_shirt_size_value']['field'] = 'field_reg_shirt_size_value';
  $handler->display->display_options['filters']['field_reg_shirt_size_value']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/registrations/t-shirts';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'T-Shirt Counts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['tcdc_tshirts'] = $view;

  $view = new view();
  $view->name = 'voucher_orders';
  $view->description = 'Admin list of coupon voucher orders.';
  $view->tag = 'tcdrupalregistration, admin, registration, coupon';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Coupon Voucher Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Voucher Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any commerce_order entity';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_id' => 'order_id',
    'line_item_label' => 'line_item_label',
    'quantity' => 'quantity',
    'status' => 'status',
    'mail' => 'mail',
    'changed' => 'changed',
    'edit_order' => 'edit_order',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'quantity' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
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
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_order' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No orders found.';
  $handler->display->display_options['empty']['area']['format'] = 'script';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Field: Commerce Line Item: Label */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['relationship'] = 'commerce_line_items_line_item_id';
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  $handler->display->display_options['fields']['quantity']['separator'] = '';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Order updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  /* Filter criterion: Commerce Line Item: Label */
  $handler->display->display_options['filters']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['filters']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['line_item_label']['field'] = 'line_item_label';
  $handler->display->display_options['filters']['line_item_label']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['line_item_label']['operator'] = 'starts';
  $handler->display->display_options['filters']['line_item_label']['value'] = 'BULK';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/voucher-orders';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Voucher Orders';
  $handler->display->display_options['menu']['name'] = 'management';
  $export['voucher_orders'] = $view;

  $view = new view();
  $view->name = 'who_is_coming';
  $view->description = 'Page and block showing users who are registered for camp.';
  $view->tag = 'tcdrupal_registration';
  $view->base_table = 'users';
  $view->human_name = 'Who is Coming';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Who is Coming?';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '42';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'clearfix';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['registration_user_uid']['id'] = 'registration_user_uid';
  $handler->display->display_options['relationships']['registration_user_uid']['table'] = 'users';
  $handler->display->display_options['relationships']['registration_user_uid']['field'] = 'registration_user_uid';
  $handler->display->display_options['relationships']['registration_user_uid']['label'] = 'Registration';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="http://2013.tcdrupal.org/sites/2013.tcdrupal.org/files/user-default.png" alt="user icon" />';
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_thumb';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: Drupal.org Username */
  $handler->display->display_options['fields']['field_registration_do_username']['id'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['field'] = 'field_registration_do_username';
  $handler->display->display_options['fields']['field_registration_do_username']['label'] = '';
  $handler->display->display_options['fields']['field_registration_do_username']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registration_do_username']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_registration_do_username']['empty'] = '[name]';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_registration_do_username]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Drupal.org Username (field_registration_do_username) */
  $handler->display->display_options['sorts']['field_registration_do_username_value']['id'] = 'field_registration_do_username_value';
  $handler->display->display_options['sorts']['field_registration_do_username_value']['table'] = 'field_data_field_registration_do_username';
  $handler->display->display_options['sorts']['field_registration_do_username_value']['field'] = 'field_registration_do_username_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Hide Profile From Public Display? (field_hide_public_display_) */
  $handler->display->display_options['filters']['field_hide_public_display__value']['id'] = 'field_hide_public_display__value';
  $handler->display->display_options['filters']['field_hide_public_display__value']['table'] = 'field_data_field_hide_public_display_';
  $handler->display->display_options['filters']['field_hide_public_display__value']['field'] = 'field_hide_public_display__value';
  $handler->display->display_options['filters']['field_hide_public_display__value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_public_display__value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['relationship'] = 'registration_user_uid';
  $handler->display->display_options['filters']['entity_id']['operator'] = 'between';
  $handler->display->display_options['filters']['entity_id']['value']['min'] = '15';
  $handler->display->display_options['filters']['entity_id']['value']['max'] = '18';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '609';
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'registration_user_uid';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>See who\'s coming to this year\'s DrupalCamp! If you wish to hide your name from this list, simply edit your user profile.</p>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['path'] = 'who-is-coming';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="view-all"><a href="who-is-coming">View All</a></span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Hide Profile From Public Display? (field_hide_public_display_) */
  $handler->display->display_options['filters']['field_hide_public_display__value']['id'] = 'field_hide_public_display__value';
  $handler->display->display_options['filters']['field_hide_public_display__value']['table'] = 'field_data_field_hide_public_display_';
  $handler->display->display_options['filters']['field_hide_public_display__value']['field'] = 'field_hide_public_display__value';
  $handler->display->display_options['filters']['field_hide_public_display__value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_hide_public_display__value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Registration: Host entity ID */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'registration';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['relationship'] = 'registration_user_uid';
  $handler->display->display_options['filters']['entity_id']['operator'] = 'between';
  $handler->display->display_options['filters']['entity_id']['value']['min'] = '15';
  $handler->display->display_options['filters']['entity_id']['value']['max'] = '18';
  $handler->display->display_options['filters']['entity_id']['value']['value'] = '609';
  /* Filter criterion: User: Picture */
  $handler->display->display_options['filters']['picture']['id'] = 'picture';
  $handler->display->display_options['filters']['picture']['table'] = 'users';
  $handler->display->display_options['filters']['picture']['field'] = 'picture';
  $handler->display->display_options['filters']['picture']['value'] = '1';
  /* Filter criterion: Registration: State entity */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'registration';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'registration_user_uid';
  $handler->display->display_options['filters']['state']['value'] = array(
    'complete' => 'complete',
  );
  $export['who_is_coming'] = $view;

  return $export;
}
