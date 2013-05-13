<?php

function wikicompare_generate_test_data() {


$compareds = array();

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.1';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31101'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31101'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31119'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31101'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31137'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.1.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31137'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31155'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.1.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.1.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31137'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31173'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.1.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.2';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31191'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31191'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31209'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31191'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31227'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31191'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31245'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31263'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31263'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31281'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31263'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31299'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31299'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31317'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31299'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31335'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31299'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31353'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = 'Compared 33.3.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-31263'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-31371'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Compared 33.3.3 fr';
node_save($node);
}

}

$features = array();

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '2';
node_save($node);
$features['new-31069'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31069'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-31071'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31071'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
node_save($node);
$features['new-31073'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31071'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '100';
node_save($node);
$features['new-31075'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31069'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '2';
node_save($node);
$features['new-31077'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31069'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-31079'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31079'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-31081'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31079'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-31083'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.3.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.1.3.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31079'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-31085'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.1.3.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.2';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-31087'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31087'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-31089'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31087'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-31091'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31087'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-31093'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.3';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '3';
node_save($node);
$features['new-31095'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.3.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31095'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '50';
node_save($node);
$features['new-31097'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.3.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = 'Feature 33.3.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-31095'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '50';
node_save($node);
$features['new-31099'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Feature 33.3.2 fr';
node_save($node);
}

}

if (module_exists('wikicompare_needs')) {

$needs = array();

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-31389'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31389'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-31391'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31391'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31081'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31089'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31097'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-31099'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
node_save($node);
$needs['new-31393'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31391'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31075'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31081'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31089'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
node_save($node);
$needs['new-31395'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31389'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-31397'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31397'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31073'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31077'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31083'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-31089'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
node_save($node);
$needs['new-31399'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31397'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31077'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31089'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31091'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
node_save($node);
$needs['new-31401'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.2.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.1.2.3';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31397'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31073'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31081'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31083'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-31097'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
node_save($node);
$needs['new-31403'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.1.2.3 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.2';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-31405'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.2.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31405'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-31407'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.2.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.2.1.1';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31407'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31073'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31083'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31091'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
node_save($node);
$needs['new-31409'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.2.1.1 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.2.1.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31407'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31077'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31081'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31083'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-31093'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
node_save($node);
$needs['new-31411'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.2.1.2 fr';
node_save($node);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = 'Need 33.2.2';
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-31405'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-31073'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-31077'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-31083'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-31097'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
node_save($node);
$needs['new-31413'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', language_list())) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = 'Need 33.2.2 fr';
node_save($node);
}

}
}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-31155']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-31335'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$implementation_id = wikicompare_get_implementation_id($compareds['new-31173'], $features['new-31099']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-31209'], $features['new-31083']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-31227'], $features['new-31081']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-31227'], $features['new-31093']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-31245'], $features['new-31081']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-31317'], $features['new-31089']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-31371'], $features['new-31097']);
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
