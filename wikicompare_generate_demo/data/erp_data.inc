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
node_save($node);
$compareds['new-8598'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Ciel Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8598'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8599'] = $node->nid;

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
$node->title = "Ciel Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8598'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8600'] = $node->nid;

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
node_save($node);
$compareds['new-8614'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8614'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8615'] = $node->nid;

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
$node->title = "Sage Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8614'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8616'] = $node->nid;

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
node_save($node);
$compareds['new-8601'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8601'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8602'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8602'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8603'] = $node->nid;

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
$node->title = "OpenERP V4 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8602'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8604'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8601'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8605'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8605'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8606'] = $node->nid;

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
$node->title = "OpenERP V5 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8605'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8607'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8601'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8608'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8608'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8609'] = $node->nid;

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
$node->title = "OpenERP V6 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8608'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8610'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8601'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8611'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8611'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8612'] = $node->nid;

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
$node->title = "OpenERP V7 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8611'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8613'] = $node->nid;

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
node_save($node);
$compareds['new-8617'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-8617'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
node_save($node);
$compareds['new-8618'] = $node->nid;

$features = array();

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Accounting";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8619'] = $node->nid;

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
$node->title = "Invoicing";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8619'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8711'] = $node->nid;

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
$node->title = "Invoice include the detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8711'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8803'] = $node->nid;

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
$node->title = "Due date management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8711'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8734'] = $node->nid;

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
$node->title = "Create one account move for each due date, with different date";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8734'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
node_save($node);
$features['new-8757'] = $node->nid;

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
$node->title = "Writing the date in an invoice field";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8734'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '25';
node_save($node);
$features['new-8780'] = $node->nid;

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
$node->title = "Account move";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8619'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8642'] = $node->nid;

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
$node->title = "An account move include several account move line";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8642'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8665'] = $node->nid;

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
$node->title = "Can't validate account move is sum credit different sum debit";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8642'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8688'] = $node->nid;

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
$node->title = "Reporting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8619'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8826'] = $node->nid;

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
$node->title = "Consult account chart in the ERP interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8826'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8849'] = $node->nid;

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
$node->title = "Print general ledger";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8826'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8872'] = $node->nid;

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
node_save($node);
$features['new-8895'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Sellers can manage their cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8895'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8963'] = $node->nid;

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
$node->title = "Being able to send mail through the case interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8895'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8917'] = $node->nid;

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
$node->title = "New emails create new cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8895'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8940'] = $node->nid;

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
$node->title = "Sales";
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9262'] = $node->nid;

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
$node->title = "Sale order management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9262'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9377'] = $node->nid;

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
$node->title = "Contain order detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9377'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9400'] = $node->nid;

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
$node->title = "Contain payment method";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9377'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9423'] = $node->nid;

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
$node->title = "Possible processus at order confirmation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9262'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9285'] = $node->nid;

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
$node->title = "Create invoice, then after payment create picking order";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9285'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9308'] = $node->nid;

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
$node->title = "Create picking order, then after shipping create invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9285'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9331'] = $node->nid;

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
$node->title = "Create picking, create manually the invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9285'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9354'] = $node->nid;

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
node_save($node);
$features['new-9446'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Stock move management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9446'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9560'] = $node->nid;

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
$node->title = "Double-entry stock management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9446'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9468'] = $node->nid;

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
$node->title = "Location management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9446'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9491'] = $node->nid;

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
$node->title = "Being able to manage location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9491'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9514'] = $node->nid;

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
$node->title = "Manage hierachical location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9491'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9537'] = $node->nid;

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
$node->title = "Document management";
$node->wikicompare_sequence['und'][0]['value'] = 5;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-8986'] = $node->nid;

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
$node->title = "Store document in ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8986'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9055'] = $node->nid;

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
$node->title = "Being able to attach document to record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8986'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9032'] = $node->nid;

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
$node->title = "Access document through a virtual FTP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-8986'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9009'] = $node->nid;

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
$node->title = "Internal Communication";
$node->wikicompare_sequence['und'][0]['value'] = 6;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9078'] = $node->nid;

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
$node->title = "Comment record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9078'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9101'] = $node->nid;

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
$node->title = "Being able to comment any record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9101'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9124'] = $node->nid;

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
$node->title = "See all interesting comment in the home page of the ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9101'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9147'] = $node->nid;

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
$node->title = "Internal Message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9078'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9170'] = $node->nid;

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
$node->title = "Being able to send message to other ERP user";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9170'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9216'] = $node->nid;

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
$node->title = "Being able to attach link to record in message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9170'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9193'] = $node->nid;

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
$node->title = "Number of unread message visible at all time";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9170'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9239'] = $node->nid;

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
$node->title = "Technical";
$node->wikicompare_sequence['und'][0]['value'] = 7;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9583'] = $node->nid;

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
$node->title = "Main concepts manage by framework";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9583'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9606'] = $node->nid;

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
$node->title = "ORM (Database and object management)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9606'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9740'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9606'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9629'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9629'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9674'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9629'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9696'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Access Rights";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9629'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9651'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9606'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9718'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Programming language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9583'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9763'] = $node->nid;

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
$node->title = "Object-oriented language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-9763'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
node_save($node);
$features['new-9786'] = $node->nid;

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
$node->title = "Domain : Retail";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-8803'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-8780'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-9308'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-9331'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
$node->wikicompare_features['und'][4]['target_id'] = $features['new-9354'];
$node->wikicompare_features['und'][4]['target_type'] = 'node';
$node->wikicompare_features['und'][5]['target_id'] = $features['new-9400'];
$node->wikicompare_features['und'][5]['target_type'] = 'node';
$node->wikicompare_features['und'][6]['target_id'] = $features['new-9560'];
$node->wikicompare_features['und'][6]['target_type'] = 'node';
node_save($node);
$needs['new-9812'] = $node->nid;

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
$node->title = "Retail, simple needs";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-9812'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-9814'] = $node->nid;

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
$node->title = "Retail, complex needs";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-9812'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-8665'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-8688'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-8757'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-8780'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
$node->wikicompare_features['und'][4]['target_id'] = $features['new-8849'];
$node->wikicompare_features['und'][4]['target_type'] = 'node';
$node->wikicompare_features['und'][5]['target_id'] = $features['new-8872'];
$node->wikicompare_features['und'][5]['target_type'] = 'node';
$node->wikicompare_features['und'][6]['target_id'] = $features['new-8917'];
$node->wikicompare_features['und'][6]['target_type'] = 'node';
$node->wikicompare_features['und'][7]['target_id'] = $features['new-8940'];
$node->wikicompare_features['und'][7]['target_type'] = 'node';
$node->wikicompare_features['und'][8]['target_id'] = $features['new-8963'];
$node->wikicompare_features['und'][8]['target_type'] = 'node';
$node->wikicompare_features['und'][9]['target_id'] = $features['new-9423'];
$node->wikicompare_features['und'][9]['target_type'] = 'node';
$node->wikicompare_features['und'][10]['target_id'] = $features['new-9468'];
$node->wikicompare_features['und'][10]['target_type'] = 'node';
$node->wikicompare_features['und'][11]['target_id'] = $features['new-9514'];
$node->wikicompare_features['und'][11]['target_type'] = 'node';
$node->wikicompare_features['und'][12]['target_id'] = $features['new-9537'];
$node->wikicompare_features['und'][12]['target_type'] = 'node';
node_save($node);
$needs['new-9813'] = $node->nid;

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
$node->title = "Specific needs";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-9809'] = $node->nid;

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
$node->title = "Document management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-9809'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-9009'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-9032'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-9055'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
node_save($node);
$needs['new-9811'] = $node->nid;

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
$node->title = "Internal communication";
$node->wikicompare_parent_id['und'][0]['target_id'] = $needs['new-9809'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
node_save($node);
$needs['new-9810'] = $node->nid;

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

$node = node_load($compareds['new-8606']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-8603'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-8607']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-8604'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-8609']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-8606'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-8610']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-8607'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-8612']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-8609'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-8613']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-8610'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$implementation_id = wikicompare_get_implementation_id($compareds['new-8599'], $features['new-8665']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8665']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8615'], $features['new-8665']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8665']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8599'], $features['new-8688']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8688']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8615'], $features['new-8688']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8688']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8757']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-8757']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8757']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-8780']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-8803']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8803']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-8803']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8803']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8849']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8615'], $features['new-8849']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8849']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8599'], $features['new-8872']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8872']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8615'], $features['new-8872']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8872']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8607'], $features['new-8917']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8917']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8940']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-8963']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-8963']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-8963']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8607'], $features['new-9009']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9032']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9032']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9055']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9055']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9055']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8610'], $features['new-9124']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8613'], $features['new-9124']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8613'], $features['new-9147']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8607'], $features['new-9193']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8607'], $features['new-9216']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9216']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8607'], $features['new-9239']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9239']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-9308']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9308']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9308']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9308']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-9331']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9331']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9331']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9331']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9354']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9354']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9354']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-9400']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9400']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9400']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9400']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8606'], $features['new-9423']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9423']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9423']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9468']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9468']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9468']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-9514']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9514']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9514']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9514']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9537']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9537']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9537']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8600'], $features['new-9560']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9560']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8616'], $features['new-9560']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9560']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9651']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9651']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9674']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9674']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9696']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9696']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9718']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9718']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9740']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9740']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8604'], $features['new-9786']);
$node = node_load($implementation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$implementation_id = wikicompare_get_implementation_id($compareds['new-8618'], $features['new-9786']);
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
