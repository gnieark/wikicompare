<?php

function wikicompare_generate_test_data() {

$compareds = array();

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.1';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26660'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26660'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26684'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26660'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26708'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.1.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26708'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26732'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.1.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.1.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26708'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26756'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.1.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26780'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26780'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26804'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26804'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26828'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26804'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26852'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.1.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26804'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26876'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.1.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26780'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26900'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26900'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26924'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26900'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26948'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26900'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26972'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26780'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-26996'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26996'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27020'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.2.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-26996'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27044'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.2.3.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27068'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27068'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27092'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27092'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27116'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27092'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27140'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3.1.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27092'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27164'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3.1.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27068'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27188'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 20.3.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27068'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-27212'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 20.3.3 fr';
node_save($node);
}

}

$features = array();

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.1';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-26616'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26616'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-26618'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26616'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-26620'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.1.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26616'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '2';
node_save($node);
$features['new-26622'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.1.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-26624'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26624'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '50';
node_save($node);
$features['new-26626'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26626'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-26628'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26626'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-26630'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.1.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26626'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-26632'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.1.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26624'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
node_save($node);
$features['new-26634'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26624'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '100';
node_save($node);
$features['new-26636'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26636'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
node_save($node);
$features['new-26638'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.2.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26636'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '33';
node_save($node);
$features['new-26640'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.2.3.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-26642'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26642'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '2';
node_save($node);
$features['new-26644'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26644'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '50';
node_save($node);
$features['new-26646'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26644'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '50';
node_save($node);
$features['new-26648'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.1.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26644'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '50';
node_save($node);
$features['new-26650'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.1.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26642'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-26652'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26642'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-26654'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26654'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-26656'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 20.3.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-26654'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-26658'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 20.3.3.2 fr';
node_save($node);
}

}

if (module_exists('wikicompare_needs')) {

$needs = array();

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 20.1';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-27236'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 20.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 20.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-27236'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-26620'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-26630'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-26646'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
node_save($node);
$needs['new-27238'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 20.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 20.2';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-27240'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 20.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 20.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-27240'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-26634'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-26646'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-26658'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
node_save($node);
$needs['new-27242'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 20.2.1 fr';
node_save($node);
}

}
}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-27044']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-26732'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-26828']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-27188'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$implementation_id = wikicompare_get_implementation_id($compareds['new-26684'], $features['new-26634']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-26756'], $features['new-26620']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-26924'], $features['new-26634']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-27020'], $features['new-26622']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-27116'], $features['new-26650']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-27188'], $features['new-26658']);
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
