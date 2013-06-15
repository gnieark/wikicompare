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
$node->title = "Ciel";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-1'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Ciel Comptabilite";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-1'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-2'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Comptabilite";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Ciel Gestion commerciale";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-1'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-4'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Gestion commerciale";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-6'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage Comptabilite";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-6'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-7'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Comptabilite";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage Gestion commerciale";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-6'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-9'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Gestion commerciale";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP";
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-11'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-11'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-12'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4 Modules communautaires";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-12'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-13'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules communautaires";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4 Modules officiels";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-12'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-15'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules officiels";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-11'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-17'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5 Modules communautaires";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-17'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-18'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules communautaires";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5 Modules officiels";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-17'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-20'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules officiels";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-11'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-22'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6 Modules communautaires";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-22'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-23'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules communautaires";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6 Modules officiels";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-22'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-25'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules officiels";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-11'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-27'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7 Modules communautaires";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-28'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules communautaires";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7 Modules officiels";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-27'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-30'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules officiels";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "SAP";
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-32'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-32'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->comment = 2;
node_save($node);
$compareds['new-33'] = $node->nid;

$features = array();

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Comptabilite";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-34'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Comptabilite";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Facturation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-34'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-57'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Facturation";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "La facture contient les details (produits, prix, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-57'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-80'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "La facture contient les details (produits, prix, etc...)";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gestion de la date d'echeance";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-57'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-103'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion de la date d'echeance";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Creer une ecriture pour chaque date d'echeance";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-103'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
$node->comment = 2;
node_save($node);
$features['new-126'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer une ecriture pour chaque date d'echeance";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Ecrire la date dans un champ de la facture";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-103'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '25';
$node->comment = 2;
node_save($node);
$features['new-149'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ecrire la date dans un champ de la facture";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Mouvements comptables";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-34'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-172'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Mouvements comptables";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Un mouvement comptable peut inclure plusieurs ecritures comptables";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-172'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-195'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Un mouvement comptable peut inclure plusieurs ecritures comptables";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Impossible de valider une piece comptable si la somme des debits est different de la somme des credits";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-172'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-218'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Impossible de valider une piece comptable si la somme des debits est different de la somme des credits";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Rapports";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-34'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-241'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Rapports";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Consulter le plan comptable depuis l'ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-241'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-264'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Consulter le plan comptable depuis l'ERP";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Imprimer le grand livre";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-241'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-287'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Imprimer le grand livre";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "CRM";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-310'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Les commerciaux peuvent suivre leurs dossiers";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-310'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-332'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les commerciaux peuvent suivre leurs dossiers";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Etre capable d'envoyer des mails depuis l'interface du dossier";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-310'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-355'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'envoyer des mails depuis l'interface du dossier";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Les nouveaux emails generent de nouveaux dossiers";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-310'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-378'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les nouveaux emails generent de nouveaux dossiers";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Ventes";
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-401'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ventes";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gestion des commandes";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-401'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-424'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des commandes";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Contient les details de la commande (produits, prix, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-424'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-447'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Contient les details de la commande (produits, prix, etc...)";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Contient la methode de paiement";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-424'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-470'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Contient la methode de paiement";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Processus possibles a la confirmation de la commande";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-401'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-493'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Processus possibles a la confirmation de la commande";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Creer la facture, et apres le paiement creer l'ordre de livraison";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-493'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-516'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer la facture, et apres le paiement creer l'ordre de livraison";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Creer l'ordre de livraison, et apres l'expedition creer la facture";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-493'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-539'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer l'ordre de livraison, et apres l'expedition creer la facture";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Creer l'ordre de livraison, creer la facture manuellement";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-493'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-562'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer l'ordre de livraison, creer la facture manuellement";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Stock";
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-585'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gestion des mouvements de stock";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-585'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-607'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des mouvements de stock";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gestion de stock a double entree";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-585'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-630'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion de stock a double entree";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gestion des emplacements";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-585'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-653'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des emplacements";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Etre capable de gerer les emplacements";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-653'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-676'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable de gerer les emplacements";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gerer les emplacement de maniere hierarchique";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-653'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-699'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gerer les emplacement de maniere hierarchique";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Gestion des documents";
$node->wikicompare_sequence['und'][0]['value'] = 5;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-722'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des documents";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Les documents sont stockes dans l'ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-722'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-745'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les documents sont stockes dans l'ERP";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Etre capacle d'attacher les documents aux pieces";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-722'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-768'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capacle d'attacher les documents aux pieces";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Acceder aux document depuis un FTP virtuel";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-722'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-791'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Acceder aux document depuis un FTP virtuel";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Communication interne";
$node->wikicompare_sequence['und'][0]['value'] = 6;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-814'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Communication interne";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Commenter les pieces";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-814'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-837'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Commenter les pieces";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Etre capable de commenter n'importe quelle piece";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-837'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-860'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable de commenter n'importe quelle piece";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Voir tous les commentaires interessants sur la page d'accueil de l'ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-837'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-883'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Voir tous les commentaires interessants sur la page d'accueil de l'ERP";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Messages internes";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-814'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-906'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Messages internes";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Etre capable d'envoyer des messages aux autres utilisateurs de l'ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-906'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-929'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'envoyer des messages aux autres utilisateurs de l'ERP";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Etre capable d'attacher un lien vers les pieces dans les messages";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-906'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-952'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'attacher un lien vers les pieces dans les messages";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Le nombre de messages non-lus est visible en permanence";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-906'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-975'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Le nombre de messages non-lus est visible en permanence";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Technique";
$node->wikicompare_sequence['und'][0]['value'] = 7;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-998'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Technique";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Les principaux concept gere par le framework";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-998'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1021'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les principaux concept gere par le framework";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "ORM (Gestion des objets et de la base de donnees)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1021'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1044'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "ORM (Gestion des objets et de la base de donnees)";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1021'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1067'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1067'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1089'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1067'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1111'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Droits d'acces";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1067'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1133'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Droits d'acces";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1021'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1156'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Language de programmation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-998'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1178'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Language de programmation";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Language oriente-objet";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-1178'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->comment = 2;
node_save($node);
$features['new-1201'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Language oriente-objet";
node_save($tnode);
}

}

if (module_exists('wikicompare_needs')) {

$needs = array();

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = "Secteur d'activite : Distribution";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-80'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-149'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-516'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-539'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
$node->wikicompare_features['und'][4]['target_id'] = $features['new-562'];
$node->wikicompare_features['und'][4]['target_type'] = 'node';
$node->wikicompare_features['und'][5]['target_id'] = $features['new-447'];
$node->wikicompare_features['und'][5]['target_type'] = 'node';
$node->wikicompare_features['und'][6]['target_id'] = $features['new-607'];
$node->wikicompare_features['und'][6]['target_type'] = 'node';
$node->comment = 2;
node_save($node);
$needs['new-1224'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Secteur d'activite : Distribution";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = "Distribution, besoins simples";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-1224'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->comment = 2;
node_save($node);
$needs['new-1226'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Distribution, besoins simples";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = "Distribution, besoins complexes";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-1224'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-195'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-218'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-126'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-149'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
$node->wikicompare_features['und'][4]['target_id'] = $features['new-264'];
$node->wikicompare_features['und'][4]['target_type'] = 'node';
$node->wikicompare_features['und'][5]['target_id'] = $features['new-287'];
$node->wikicompare_features['und'][5]['target_type'] = 'node';
$node->wikicompare_features['und'][6]['target_id'] = $features['new-355'];
$node->wikicompare_features['und'][6]['target_type'] = 'node';
$node->wikicompare_features['und'][7]['target_id'] = $features['new-378'];
$node->wikicompare_features['und'][7]['target_type'] = 'node';
$node->wikicompare_features['und'][8]['target_id'] = $features['new-332'];
$node->wikicompare_features['und'][8]['target_type'] = 'node';
$node->wikicompare_features['und'][9]['target_id'] = $features['new-470'];
$node->wikicompare_features['und'][9]['target_type'] = 'node';
$node->wikicompare_features['und'][10]['target_id'] = $features['new-630'];
$node->wikicompare_features['und'][10]['target_type'] = 'node';
$node->wikicompare_features['und'][11]['target_id'] = $features['new-676'];
$node->wikicompare_features['und'][11]['target_type'] = 'node';
$node->wikicompare_features['und'][12]['target_id'] = $features['new-699'];
$node->wikicompare_features['und'][12]['target_type'] = 'node';
$node->comment = 2;
node_save($node);
$needs['new-1228'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Distribution, besoins complexes";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = "Besoins specifiques";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->comment = 2;
node_save($node);
$needs['new-1230'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Besoins specifiques";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = "Gestion des documents";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-1230'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-791'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-768'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-745'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->comment = 2;
node_save($node);
$needs['new-1232'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des documents";
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'need';
$node->language = 'en';
$node->title = "Communications internes";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-1230'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->comment = 2;
node_save($node);
$needs['new-1234'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'need';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Communications internes";
node_save($tnode);
}

}
}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-18']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-13'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-20']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-15'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-23']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-18'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-25']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-20'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-28']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-23'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-30']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-25'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-80']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-80']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-80']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-80']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-126']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-126']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-126']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-149']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-2'], $features['new-195']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-7'], $features['new-195']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-195']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-195']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-2'], $features['new-218']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-7'], $features['new-218']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-218']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-218']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-7'], $features['new-264']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-264']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-264']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-2'], $features['new-287']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-7'], $features['new-287']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-287']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-287']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-332']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-332']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-332']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-20'], $features['new-355']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-355']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-378']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-447']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-447']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-447']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-447']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-470']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-18'], $features['new-470']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-470']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-516']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-516']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-516']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-516']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-539']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-539']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-539']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-539']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-562']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-562']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-562']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-607']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-607']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-607']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-607']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-630']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-630']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-630']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-4'], $features['new-676']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-676']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-676']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-676']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-699']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-699']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-699']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-9'], $features['new-745']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-745']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-745']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-768']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-768']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-20'], $features['new-791']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-25'], $features['new-860']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-30'], $features['new-860']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-30'], $features['new-883']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-20'], $features['new-929']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-929']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-20'], $features['new-952']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-20'], $features['new-975']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-975']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-1044']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-1044']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-1089']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-1089']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-1111']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-1111']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-1133']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-1133']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-1156']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-1156']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-15'], $features['new-1201']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-33'], $features['new-1201']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

?>
