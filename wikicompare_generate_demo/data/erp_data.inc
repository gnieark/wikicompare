<?php

function wikicompare_generate_erp_data() {

$language_list = array();
foreach (language_list() as $key => $lang) {
$language_list[$key] = $key;
}

$compareds = array();

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2352'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V4';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2352'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2353'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V4 Community modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2353'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2354'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'OpenERP V4 Modules communautaires';
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V4 Official modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2353'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2356'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V5';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2352'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2357'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V5 Community modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2357'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2358'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V5 Official modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2357'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2359'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V6';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2352'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2360'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V6 Community modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2360'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2361'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V6 Official modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-2360'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-2362'] = $node->nid;

$features = array();

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Accounting';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2363'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Comptabilite';
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Invoicing';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2363'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2375'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Due date management';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2375'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2386'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Create one account move for each due date, with different date';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2386'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '4';
node_save($node);
$features['new-2397'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Writing the date in an invoice field';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2386'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2408'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Technical';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2419'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Main concepts manage by framework';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2419'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2430'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Interface';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2430'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2441'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Access Rights';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2441'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2452'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Form definition';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2441'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2463'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Menu';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2441'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2474'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2430'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2518'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'ORM (Database and object management)';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2430'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2485'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Programming language';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2419'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2496'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Object-oriented language';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-2496'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-2507'] = $node->nid;

if (module_exists('wikicompare_needs')) {

$needs = array();
}

$implementation_id = wikicompare_get_implementation_id($compareds['new-2356'], $features['new-2397']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

?>
