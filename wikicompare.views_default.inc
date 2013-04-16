<?php


function wikicompare_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'wikicompare'),
  );
}


function wikicompare_views_default_views() {
$view = new view();
$view->name = 'wikicompare_dashboard';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'wikicompare_dashboard';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Dashboard';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '30';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'type' => 'type',
  'wikicompare_compared_id' => 'wikicompare_compared_id',
  'wikicompare_feature_id' => 'wikicompare_feature_id',
  'created_1' => 'created_1',
  'last_editor' => 'last_editor',
  'changed' => 'changed',
  'last_comment_name' => 'last_comment_name',
  'last_comment_timestamp' => 'last_comment_timestamp',
  'state' => 'state',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'wikicompare_compared_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'wikicompare_feature_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created_1' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'last_editor' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'last_comment_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'last_comment_timestamp' => array(
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
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['wikicompare_compared_id_target_id']['id'] = 'wikicompare_compared_id_target_id';
$handler->display->display_options['relationships']['wikicompare_compared_id_target_id']['table'] = 'field_data_wikicompare_compared_id';
$handler->display->display_options['relationships']['wikicompare_compared_id_target_id']['field'] = 'wikicompare_compared_id_target_id';
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['wikicompare_feature_id_target_id']['id'] = 'wikicompare_feature_id_target_id';
$handler->display->display_options['relationships']['wikicompare_feature_id_target_id']['table'] = 'field_data_wikicompare_feature_id';
$handler->display->display_options['relationships']['wikicompare_feature_id_target_id']['field'] = 'wikicompare_feature_id_target_id';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['path'] = '/node/%nid';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: Content: Compared */
$handler->display->display_options['fields']['wikicompare_compared_id']['id'] = 'wikicompare_compared_id';
$handler->display->display_options['fields']['wikicompare_compared_id']['table'] = 'field_data_wikicompare_compared_id';
$handler->display->display_options['fields']['wikicompare_compared_id']['field'] = 'wikicompare_compared_id';
$handler->display->display_options['fields']['wikicompare_compared_id']['settings'] = array(
  'link' => 0,
);
/* Field: Content: Feature */
$handler->display->display_options['fields']['wikicompare_feature_id']['id'] = 'wikicompare_feature_id';
$handler->display->display_options['fields']['wikicompare_feature_id']['table'] = 'field_data_wikicompare_feature_id';
$handler->display->display_options['fields']['wikicompare_feature_id']['field'] = 'wikicompare_feature_id';
$handler->display->display_options['fields']['wikicompare_feature_id']['settings'] = array(
  'link' => 0,
);
/* Field: Content: Post date */
$handler->display->display_options['fields']['created_1']['id'] = 'created_1';
$handler->display->display_options['fields']['created_1']['table'] = 'node';
$handler->display->display_options['fields']['created_1']['field'] = 'created';
$handler->display->display_options['fields']['created_1']['date_format'] = 'long';
/* Field: Content: Last edited by */
$handler->display->display_options['fields']['last_editor']['id'] = 'last_editor';
$handler->display->display_options['fields']['last_editor']['table'] = 'node';
$handler->display->display_options['fields']['last_editor']['field'] = 'last_editor';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'long';
/* Field: Content: Last comment author */
$handler->display->display_options['fields']['last_comment_name']['id'] = 'last_comment_name';
$handler->display->display_options['fields']['last_comment_name']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_comment_name']['field'] = 'last_comment_name';
/* Field: Content: Last comment time */
$handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['date_format'] = 'long';
/* Field: Content: State */
$handler->display->display_options['fields']['wikicompare_state']['id'] = 'wikicompare_state';
$handler->display->display_options['fields']['wikicompare_state']['table'] = 'field_data_wikicompare_state';
$handler->display->display_options['fields']['wikicompare_state']['field'] = 'wikicompare_state';
/* Field: Content: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'node';
$handler->display->display_options['fields']['state']['field'] = 'state';
$handler->display->display_options['fields']['state']['label'] = 'Revision State';
/* Sort criterion: Content: Updated/commented date */
$handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
$handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
$handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
$handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
$handler->display->display_options['sorts']['last_updated']['expose']['label'] = 'Updated/commented date';
$handler->display->display_options['filter_groups']['groups'] = array(
  1 => 'AND',
  2 => 'OR',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['group'] = 1;
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'compared' => 'compared',
  'feature' => 'feature',
  'implementation' => 'implementation',
);
$handler->display->display_options['filters']['type']['group'] = 1;
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title_1']['id'] = 'title_1';
$handler->display->display_options['filters']['title_1']['table'] = 'node';
$handler->display->display_options['filters']['title_1']['field'] = 'title';
$handler->display->display_options['filters']['title_1']['relationship'] = 'wikicompare_compared_id_target_id';
$handler->display->display_options['filters']['title_1']['operator'] = 'contains';
$handler->display->display_options['filters']['title_1']['group'] = 1;
$handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
$handler->display->display_options['filters']['title_1']['expose']['label'] = 'Compared';
$handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
$handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
$handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title_2']['id'] = 'title_2';
$handler->display->display_options['filters']['title_2']['table'] = 'node';
$handler->display->display_options['filters']['title_2']['field'] = 'title';
$handler->display->display_options['filters']['title_2']['relationship'] = 'wikicompare_feature_id_target_id';
$handler->display->display_options['filters']['title_2']['operator'] = 'contains';
$handler->display->display_options['filters']['title_2']['group'] = 1;
$handler->display->display_options['filters']['title_2']['exposed'] = TRUE;
$handler->display->display_options['filters']['title_2']['expose']['operator_id'] = 'title_2_op';
$handler->display->display_options['filters']['title_2']['expose']['label'] = 'Feature';
$handler->display->display_options['filters']['title_2']['expose']['operator'] = 'title_2_op';
$handler->display->display_options['filters']['title_2']['expose']['identifier'] = 'title_2';
$handler->display->display_options['filters']['title_2']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
/* Filter criterion: Content: Last comment time */
$handler->display->display_options['filters']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
$handler->display->display_options['filters']['last_comment_timestamp']['table'] = 'node_comment_statistics';
$handler->display->display_options['filters']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
$handler->display->display_options['filters']['last_comment_timestamp']['operator'] = 'between';
$handler->display->display_options['filters']['last_comment_timestamp']['group'] = 1;
$handler->display->display_options['filters']['last_comment_timestamp']['exposed'] = TRUE;
$handler->display->display_options['filters']['last_comment_timestamp']['expose']['operator_id'] = 'last_comment_timestamp_op';
$handler->display->display_options['filters']['last_comment_timestamp']['expose']['label'] = 'Last comment time';
$handler->display->display_options['filters']['last_comment_timestamp']['expose']['operator'] = 'last_comment_timestamp_op';
$handler->display->display_options['filters']['last_comment_timestamp']['expose']['identifier'] = 'last_comment_timestamp';
$handler->display->display_options['filters']['last_comment_timestamp']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
/* Filter criterion: Content: Updated date */
$handler->display->display_options['filters']['changed']['id'] = 'changed';
$handler->display->display_options['filters']['changed']['table'] = 'node';
$handler->display->display_options['filters']['changed']['field'] = 'changed';
$handler->display->display_options['filters']['changed']['operator'] = 'between';
$handler->display->display_options['filters']['changed']['group'] = 1;
$handler->display->display_options['filters']['changed']['exposed'] = TRUE;
$handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
$handler->display->display_options['filters']['changed']['expose']['label'] = 'Updated date';
$handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
$handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
$handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
/* Filter criterion: Content: State (wikicompare_state) */
$handler->display->display_options['filters']['wikicompare_state_value']['id'] = 'wikicompare_state_value';
$handler->display->display_options['filters']['wikicompare_state_value']['table'] = 'field_data_wikicompare_state';
$handler->display->display_options['filters']['wikicompare_state_value']['field'] = 'wikicompare_state_value';
$handler->display->display_options['filters']['wikicompare_state_value']['group'] = 1;
$handler->display->display_options['filters']['wikicompare_state_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['wikicompare_state_value']['expose']['operator_id'] = 'wikicompare_state_value_op';
$handler->display->display_options['filters']['wikicompare_state_value']['expose']['label'] = 'State';
$handler->display->display_options['filters']['wikicompare_state_value']['expose']['operator'] = 'wikicompare_state_value_op';
$handler->display->display_options['filters']['wikicompare_state_value']['expose']['identifier'] = 'wikicompare_state_value';
$handler->display->display_options['filters']['wikicompare_state_value']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['wikicompare_state_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  43 => 0,
  44 => 0,
);
/* Filter criterion: Content: State */
$handler->display->display_options['filters']['state']['id'] = 'state';
$handler->display->display_options['filters']['state']['table'] = 'node';
$handler->display->display_options['filters']['state']['field'] = 'state';
$handler->display->display_options['filters']['state']['group'] = 1;
$handler->display->display_options['filters']['state']['exposed'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['label'] = 'Revision State';
$handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
$handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
$handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  43 => 0,
  44 => 0,
);
/* Filter criterion: Content: Power users (wikicompare_user_ids:delta) */
$handler->display->display_options['filters']['delta']['id'] = 'delta';
$handler->display->display_options['filters']['delta']['table'] = 'field_data_wikicompare_user_ids';
$handler->display->display_options['filters']['delta']['field'] = 'delta';
$handler->display->display_options['filters']['delta']['value']['value'] = '%uid';
$handler->display->display_options['filters']['delta']['group'] = 2;
$handler->display->display_options['filters']['delta']['exposed'] = TRUE;
$handler->display->display_options['filters']['delta']['expose']['operator_id'] = 'delta_op';
$handler->display->display_options['filters']['delta']['expose']['label'] = 'Power users';
$handler->display->display_options['filters']['delta']['expose']['operator'] = 'delta_op';
$handler->display->display_options['filters']['delta']['expose']['identifier'] = 'delta';
$handler->display->display_options['filters']['delta']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
$handler->display->display_options['filters']['delta']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['delta']['group_info']['label'] = 'Power users';
$handler->display->display_options['filters']['delta']['group_info']['identifier'] = 'delta';
$handler->display->display_options['filters']['delta']['group_info']['group_items'] = array(
  1 => array(
    'title' => 'You',
    'operator' => '=',
    'value' => array(
      'value' => '%uid',
      'min' => '',
      'max' => '',
    ),
  ),
);
/* Filter criterion: Content: Power users from parents (wikicompare_user_from_parent_ids:delta) */
$handler->display->display_options['filters']['delta_1']['id'] = 'delta_1';
$handler->display->display_options['filters']['delta_1']['table'] = 'field_data_wikicompare_user_from_parent_ids';
$handler->display->display_options['filters']['delta_1']['field'] = 'delta';
$handler->display->display_options['filters']['delta_1']['value']['value'] = '%uid';
$handler->display->display_options['filters']['delta_1']['group'] = 2;
$handler->display->display_options['filters']['delta_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['delta_1']['expose']['operator_id'] = 'delta_1_op';
$handler->display->display_options['filters']['delta_1']['expose']['label'] = 'Power users from parents';
$handler->display->display_options['filters']['delta_1']['expose']['operator'] = 'delta_1_op';
$handler->display->display_options['filters']['delta_1']['expose']['identifier'] = 'delta_1';
$handler->display->display_options['filters']['delta_1']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  27 => 0,
  28 => 0,
);
$handler->display->display_options['filters']['delta_1']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['delta_1']['group_info']['label'] = 'Power users from parents';
$handler->display->display_options['filters']['delta_1']['group_info']['identifier'] = 'delta_1';
$handler->display->display_options['filters']['delta_1']['group_info']['group_items'] = array(
  1 => array(
    'title' => 'You',
    'operator' => '=',
    'value' => array(
      'value' => '%uid',
      'min' => '',
      'max' => '',
    ),
  ),
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'wikicompare-dashboard';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Dashboard';
$handler->display->display_options['menu']['name'] = 'main-menu';
$translatables['wikicompare_dashboard'] = array(
  t('Master'),
  t('Dashboard'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('Content entity referenced from wikicompare_compared_id'),
  t('Content entity referenced from wikicompare_feature_id'),
  t('Title'),
  t('Type'),
  t('Compared'),
  t('Feature'),
  t('Post date'),
  t('Last edited by'),
  t('Updated date'),
  t('Last comment author'),
  t('Last comment time'),
  t('State'),
  t('Revision State'),
  t('Updated/commented date'),
  t('Power users'),
  t('Power users from parents'),
  t('Page'),
);


$views[$view->name] = $view;
return $views;

}


?>