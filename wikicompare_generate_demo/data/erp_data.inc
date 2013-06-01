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
$compareds['new-3415'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V4';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3415'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3416'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V4 Community modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3416'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3417'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3416'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3419'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V5';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3415'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3420'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V5 Community modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3421'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V5 Official modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3422'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V6';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3415'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3423'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V6 Community modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3423'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3424'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'OpenERP V6 Official modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-3423'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-3425'] = $node->nid;

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
$features['new-3426'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3426'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3438'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Due date management';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3438'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3449'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Create one account move for each due date, with different date';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3449'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '4';
node_save($node);
$features['new-3460'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Writing the date in an invoice field';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3449'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3471'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'CRM';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3614'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Document management';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3625'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Internal Communication';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3636'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Comment record';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3636'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3647'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Being able to comment any record';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3647'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3658'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'See all interesting comment in the home page of the ERP';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3647'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3669'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Internal Message';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3636'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3680'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Being able to attach link to record in message';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3680'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3702'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Being able to send message to other ERP user';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3680'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3691'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Number of unread message visible at all time';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3680'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3713'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Sales';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3603'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Stock';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3592'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Technical';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3482'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Main concepts manage by framework';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3482'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3493'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Interface';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3493'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3504'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Access Rights';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3504'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3515'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Form definition';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3504'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3526'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Menu';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3504'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3537'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Modules';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3493'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3548'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'ORM (Database and object management)';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3493'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3559'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Programming language';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3482'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3570'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Object-oriented language';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-3570'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-3581'] = $node->nid;

if (module_exists('wikicompare_needs')) {

$needs = array();
}

$implementation_id = wikicompare_get_implementation_id($compareds['new-3419'], $features['new-3460']);
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
