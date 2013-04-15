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
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'wikicompare_compared_id' => 'wikicompare_compared_id',
  'wikicompare_feature_id' => 'wikicompare_feature_id',
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
  'wikicompare_compared_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'wikicompare_feature_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Comment: Comments of the node */
$handler->display->display_options['relationships']['cid']['id'] = 'cid';
$handler->display->display_options['relationships']['cid']['table'] = 'node';
$handler->display->display_options['relationships']['cid']['field'] = 'cid';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
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
/* Field: Content: State */
$handler->display->display_options['fields']['state']['id'] = 'state';
$handler->display->display_options['fields']['state']['table'] = 'node';
$handler->display->display_options['fields']['state']['field'] = 'state';
/* Field: Content: Last comment author */
$handler->display->display_options['fields']['last_comment_name']['id'] = 'last_comment_name';
$handler->display->display_options['fields']['last_comment_name']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_comment_name']['field'] = 'last_comment_name';
/* Field: Content: Last comment time */
$handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
$handler->display->display_options['fields']['last_comment_timestamp']['date_format'] = 'long';
/* Field: Content: Last edited by */
$handler->display->display_options['fields']['last_editor']['id'] = 'last_editor';
$handler->display->display_options['fields']['last_editor']['table'] = 'node';
$handler->display->display_options['fields']['last_editor']['field'] = 'last_editor';
/* Field: Content: New comments */
$handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
$handler->display->display_options['fields']['new_comments']['table'] = 'node';
$handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
/* Field: Content: Revisions */
$handler->display->display_options['fields']['number_of_revisions']['id'] = 'number_of_revisions';
$handler->display->display_options['fields']['number_of_revisions']['table'] = 'node';
$handler->display->display_options['fields']['number_of_revisions']['field'] = 'number_of_revisions';
/* Field: Content: Updated date */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'node';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'long';
/* Field: Content: Updated/commented date */
$handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
$handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
$handler->display->display_options['fields']['last_updated']['date_format'] = 'long';
/* Sort criterion: Comment: Post date */
$handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
$handler->display->display_options['sorts']['created_1']['table'] = 'comment';
$handler->display->display_options['sorts']['created_1']['field'] = 'created';
$handler->display->display_options['sorts']['created_1']['relationship'] = 'cid';
$handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'compared' => 'compared',
  'feature' => 'feature',
  'implementation' => 'implementation',
);
$handler->display->display_options['filters']['type']['exposed'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
$handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
  2 => '2',
  15 => '15',
  16 => '16',
  1 => 0,
);
$handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;

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
  t('Comments'),
  t('Title'),
  t('Type'),
  t('Compared'),
  t('Feature'),
  t('Post date'),
  t('State'),
  t('Last comment author'),
  t('Last comment time'),
  t('Last edited by'),
  t('New comments'),
  t('.'),
  t(','),
  t('Revisions'),
  t('Updated date'),
  t('Updated/commented date'),
  t('Page'),
);

$views[$view->name] = $view;
return $views;

}


?>