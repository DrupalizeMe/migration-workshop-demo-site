<?php
/**
 * @file
 * tcdrupalsponsors.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tcdrupalsponsors_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'sponsoradmin';
  $view->description = '';
  $view->tag = 'tcdrupalsponsors, admin';
  $view->base_table = 'commerce_line_item';
  $view->human_name = 'Sponsor Order Admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sponsor Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'line_item_id' => 'line_item_id',
    'field_upload_sponsor_logo' => 'field_upload_sponsor_logo',
    'field_sponsor_contact_email' => 'field_sponsor_contact_email',
    'field_sponsor_contact_name' => 'field_sponsor_contact_name',
    'field_sponsor_contact_phone' => 'field_sponsor_contact_phone',
    'field_sponsor_url_1' => 'field_sponsor_url_1',
    'line_item_label' => 'line_item_label',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'line_item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_upload_sponsor_logo' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sponsor_contact_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sponsor_contact_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sponsor_contact_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sponsor_url_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'line_item_label' => array(
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
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="http://goo.gl/8fDGY5" target="_blank">Sponsor Spreadsheet</a><br><a href="/admin/content">Update or add Sponsors.</a><br>Maintain <a href="/admin/commerce/coupons/list">Sponsor Coupon Codes</a> here!<br>View <a href="/sponsors/information">Sponsor Benefit Grid</a> here!
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No orders yet, perhaps YOU can be the first?';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Commerce Line Item: Order ID */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  /* Field: Commerce Line Item: Line item ID */
  $handler->display->display_options['fields']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['fields']['line_item_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['line_item_id']['element_type'] = 'h2';
  $handler->display->display_options['fields']['line_item_id']['separator'] = '';
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id_1']['id'] = 'order_id_1';
  $handler->display->display_options['fields']['order_id_1']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id_1']['field'] = 'order_id';
  /* Field: Commerce Line item: Upload Organization Sponsor Logo */
  $handler->display->display_options['fields']['field_upload_sponsor_logo']['id'] = 'field_upload_sponsor_logo';
  $handler->display->display_options['fields']['field_upload_sponsor_logo']['table'] = 'field_data_field_upload_sponsor_logo';
  $handler->display->display_options['fields']['field_upload_sponsor_logo']['field'] = 'field_upload_sponsor_logo';
  $handler->display->display_options['fields']['field_upload_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload_sponsor_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'file',
  );
  /* Field: Commerce Line item: Sponsor Contact Email */
  $handler->display->display_options['fields']['field_sponsor_contact_email']['id'] = 'field_sponsor_contact_email';
  $handler->display->display_options['fields']['field_sponsor_contact_email']['table'] = 'field_data_field_sponsor_contact_email';
  $handler->display->display_options['fields']['field_sponsor_contact_email']['field'] = 'field_sponsor_contact_email';
  $handler->display->display_options['fields']['field_sponsor_contact_email']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_contact_email']['element_label_colon'] = FALSE;
  /* Field: Commerce Line item: Sponsor Contact Phone */
  $handler->display->display_options['fields']['field_sponsor_contact_phone']['id'] = 'field_sponsor_contact_phone';
  $handler->display->display_options['fields']['field_sponsor_contact_phone']['table'] = 'field_data_field_sponsor_contact_phone';
  $handler->display->display_options['fields']['field_sponsor_contact_phone']['field'] = 'field_sponsor_contact_phone';
  $handler->display->display_options['fields']['field_sponsor_contact_phone']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_contact_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_contact_phone']['element_label_colon'] = FALSE;
  /* Field: Commerce Line item: Sponsor URL */
  $handler->display->display_options['fields']['field_sponsor_url_1']['id'] = 'field_sponsor_url_1';
  $handler->display->display_options['fields']['field_sponsor_url_1']['table'] = 'field_data_field_sponsor_url_1';
  $handler->display->display_options['fields']['field_sponsor_url_1']['field'] = 'field_sponsor_url_1';
  $handler->display->display_options['fields']['field_sponsor_url_1']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_url_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_url_1']['element_label_colon'] = FALSE;
  /* Field: Commerce Line item: Sponsor Contact Name */
  $handler->display->display_options['fields']['field_sponsor_contact_name']['id'] = 'field_sponsor_contact_name';
  $handler->display->display_options['fields']['field_sponsor_contact_name']['table'] = 'field_data_field_sponsor_contact_name';
  $handler->display->display_options['fields']['field_sponsor_contact_name']['field'] = 'field_sponsor_contact_name';
  $handler->display->display_options['fields']['field_sponsor_contact_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_contact_name']['alter']['text'] = '[field_sponsor_contact_name]<br>[field_sponsor_contact_phone]<br>[field_sponsor_contact_email]<br>[field_sponsor_url_1]';
  /* Field: Commerce Line Item: Label */
  $handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
  $handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
  /* Field: Commerce Line Item: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Order ';
  $handler->display->display_options['fields']['order_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['order_id']['alter']['text'] = '<a href="/admin/commerce/orders/[order_id]/edit">Edit Order [order_id]</a>';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'order_id';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['created']['label'] = 'Order date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Commerce Line Item: Created date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Line Item date';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['created_1']['second_date_format'] = 'long';
  /* Sort criterion: Commerce Line Item: Line item ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['order'] = 'DESC';
  /* Filter criterion: Commerce Line Item: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor_info' => 'sponsor_info',
  );
  /* Filter criterion: Commerce Order revision: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order_revision';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'order_id';
  $handler->display->display_options['filters']['status']['value'] = array(
    'completed' => 'completed',
    'reconciled' => 'reconciled',
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
  $handler->display->display_options['path'] = 'admin/sponsors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sponsor Orders';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['sponsoradmin'] = $view;

  $view = new view();
  $view->name = 'sponsors';
  $view->description = '';
  $view->tag = 'tcdrupalsponsors';
  $view->base_table = 'node';
  $view->human_name = 'Sponsors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_sponsor_level',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Gold Sponsors</h2>';
  $handler->display->display_options['header']['area']['format'] = 'script';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<p>&nbsp;</p>
';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_sponsor_url']['id'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['table'] = 'field_data_field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['field'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_url']['element_label_colon'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_url]';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'sponsor',
    'image_link' => '',
  );
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_sponsor_level']['id'] = 'field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['field'] = 'field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_level']['element_label_colon'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
    'sponsor' => 'sponsor',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<p>Interested in becoming a sponsor and seeing your name in stars? <a href="/sponsors/information">Find out more here</a>.</p>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Level (field_sponsor_level) */
  $handler->display->display_options['sorts']['field_sponsor_level_value']['id'] = 'field_sponsor_level_value';
  $handler->display->display_options['sorts']['field_sponsor_level_value']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['sorts']['field_sponsor_level_value']['field'] = 'field_sponsor_level_value';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Level (field_sponsor_level) */
  $handler->display->display_options['filters']['field_sponsor_level_value']['id'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['filters']['field_sponsor_level_value']['field'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['value'] = array(
    5 => '5',
    10 => '10',
    15 => '15',
  );
  $handler->display->display_options['path'] = 'sponsors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sponsors';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block - Platinum Sponsors */
  $handler = $view->new_display('block', 'Block - Platinum Sponsors', 'block_1');
  $handler->display->display_options['display_description'] = 'For the front page';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<p style="text-align: center;">Want to join this list? <a href="/sponsors/information">Become a sponsor today!</a></p>';
  $handler->display->display_options['footer']['area']['format'] = 'script';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'no results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Want to join this list? <a href="/sponsors/information">Become a sponsor today!</a>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_sponsor_url']['id'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['table'] = 'field_data_field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['field'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_url']['element_label_colon'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_url]';
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'sponsor',
    'image_link' => '',
  );
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Level (field_sponsor_level) */
  $handler->display->display_options['filters']['field_sponsor_level_value']['id'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['filters']['field_sponsor_level_value']['field'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['value'] = array(
    5 => '5',
  );

  /* Display: Gold Sponsor - Attachment */
  $handler = $view->new_display('attachment', 'Gold Sponsor - Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Thanks to Last Year\'s Gold Sponsors';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-list clearfix';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_sponsor_url']['id'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['table'] = 'field_data_field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['field'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_url']['element_label_colon'] = FALSE;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_url]';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'sponsor-gold',
    'image_link' => '',
  );
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_sponsor_level']['id'] = 'field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['field'] = 'field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_level']['element_label_colon'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Level (field_sponsor_level) */
  $handler->display->display_options['filters']['field_sponsor_level_value']['id'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['filters']['field_sponsor_level_value']['field'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Individual sponsor - Attachment */
  $handler = $view->new_display('attachment', 'Individual sponsor - Attachment', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<br />&nbsp;<br />';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_sponsor_url']['id'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['table'] = 'field_data_field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['field'] = 'field_sponsor_url';
  $handler->display->display_options['fields']['field_sponsor_url']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_url']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '<a href="[field_sponsor_url]">[picture]</a>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_thumb';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_sponsor_logo']['id'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['table'] = 'field_data_field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['field'] = 'field_sponsor_logo';
  $handler->display->display_options['fields']['field_sponsor_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['path'] = '[field_sponsor_url]';
  $handler->display->display_options['fields']['field_sponsor_logo']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponsor_logo']['settings'] = array(
    'image_style' => 'sponsor',
    'image_link' => '',
  );
  /* Field: Content: Level */
  $handler->display->display_options['fields']['field_sponsor_level']['id'] = 'field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['field'] = 'field_sponsor_level';
  $handler->display->display_options['fields']['field_sponsor_level']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_level']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_level']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Level (field_sponsor_level) */
  $handler->display->display_options['filters']['field_sponsor_level_value']['id'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['filters']['field_sponsor_level_value']['field'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Sprint sponsor - Attachment */
  $handler = $view->new_display('attachment', 'Sprint sponsor - Attachment', 'attachment_3');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Level (field_sponsor_level) */
  $handler->display->display_options['filters']['field_sponsor_level_value']['id'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['table'] = 'field_data_field_sponsor_level';
  $handler->display->display_options['filters']['field_sponsor_level_value']['field'] = 'field_sponsor_level_value';
  $handler->display->display_options['filters']['field_sponsor_level_value']['value'] = array(
    25 => '25',
  );
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['sponsors'] = $view;

  return $export;
}
