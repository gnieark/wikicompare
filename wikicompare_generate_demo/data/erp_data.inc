<?php

function wikicompare_generate_erp_data() {

wikicompare_stop_computation();

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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10892'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Ciel Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10892'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10893'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Comptabilite";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Ciel Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10892'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10895'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Gestion commerciale";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10897'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10897'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10898'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Comptabilite";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "Sage Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10897'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10900'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Gestion commerciale";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP";
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10902'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10902'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10903'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10903'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10904'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules communautaires";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V4 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10903'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10906'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules officiels";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10902'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10908'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10908'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10909'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules communautaires";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V5 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10908'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10911'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules officiels";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10902'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10913'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10913'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10914'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules communautaires";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V6 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10913'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10916'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules officiels";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10902'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10918'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10918'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10919'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules communautaires";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "OpenERP V7 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10918'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10921'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'compared';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules officiels";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "SAP";
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10923'] = $node->nid;

$node = new stdClass();
$node->type = 'compared';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $compareds['new-10923'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$compareds['new-10924'] = $node->nid;

$features = array();

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Accounting";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-10925'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Comptabilite";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Invoicing";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10925'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-10948'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Facturation";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Invoice include the detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10948'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-10971'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "La facture contient les details (produits, prix, etc...)";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Due date management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10948'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-10994'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion de la date d'echeance";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Create one account move for each due date, with different date";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10994'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11017'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer une ecriture pour chaque date d'echeance";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Writing the date in an invoice field";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10994'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '25';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11040'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ecrire la date dans un champ de la facture";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Account move";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10925'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11063'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Mouvements comptables";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "An account move include several account move line";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11063'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11086'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Un mouvement comptable peut inclure plusieurs ecritures comptables";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Can't validate account move is sum credit different sum debit";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11063'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11109'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Impossible de valider une piece comptable si la somme des debits est different de la somme des credits";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Reporting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-10925'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11132'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Rapports";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Consult account chart in the ERP interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11132'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11155'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Consulter le plan comptable depuis l'ERP";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Print general ledger";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11132'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11178'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Imprimer le grand livre";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11201'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Sellers can manage their cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11201'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11223'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les commerciaux peuvent suivre leurs dossiers";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Being able to send mail through the case interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11201'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11246'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'envoyer des mails depuis l'interface du dossier";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "New emails create new cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11201'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11269'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les nouveaux emails generent de nouveaux dossiers";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11292'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ventes";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Sale order management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11292'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11315'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des commandes";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Contain order detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11315'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11338'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Contient les details de la commande (produits, prix, etc...)";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Contain payment method";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11315'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11361'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Contient la methode de paiement";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Possible processus at order confirmation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11292'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11384'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Processus possibles a la confirmation de la commande";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Create invoice, then after payment create picking order";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11384'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11407'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer la facture, et apres le paiement creer l'ordre de livraison";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Create picking order, then after shipping create invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11384'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11430'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer l'ordre de livraison, et apres l'expedition creer la facture";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Create picking, create manually the invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11384'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11453'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer l'ordre de livraison, creer la facture manuellement";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11476'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Stock move management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11476'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11498'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des mouvements de stock";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Double-entry stock management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11476'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11521'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion de stock a double entree";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Location management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11476'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11544'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des emplacements";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Being able to manage location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11544'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11567'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable de gerer les emplacements";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Manage hierachical location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11544'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11590'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gerer les emplacement de maniere hierarchique";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11613'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des documents";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Store document in ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11613'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11636'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les documents sont stockes dans l'ERP";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Being able to attach document to record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11613'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11659'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capacle d'attacher les documents aux pieces";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Access document through a virtual FTP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11613'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11682'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Acceder aux document depuis un FTP virtuel";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11705'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Communication interne";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Comment record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11705'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11728'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Commenter les pieces";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Being able to comment any record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11728'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11751'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable de commenter n'importe quelle piece";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "See all interesting comment in the home page of the ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11728'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11774'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Voir tous les commentaires interessants sur la page d'accueil de l'ERP";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Internal Message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11705'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11797'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Messages internes";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Being able to send message to other ERP user";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11797'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11820'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'envoyer des messages aux autres utilisateurs de l'ERP";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Being able to attach link to record in message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11797'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11843'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'attacher un lien vers les pieces dans les messages";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Number of unread message visible at all time";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11797'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11866'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Le nombre de messages non-lus est visible en permanence";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11889'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Technique";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Main concepts manage by framework";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11889'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11912'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les principaux concept gere par le framework";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "ORM (Database and object management)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11912'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11935'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "ORM (Gestion des objets et de la base de donnees)";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11912'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11958'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11958'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-11980'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11958'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-12002'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Access Rights";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11958'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-12024'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Droits d'acces";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11912'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-12047'] = $node->nid;

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Programming language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-11889'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-12069'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Language de programmation";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'feature';
$node->language = 'en';
$node->title = "Object-oriented language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $features['new-12069'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$features['new-12092'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'feature';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Language oriente-objet";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

if (module_exists('wikicompare_profiles')) {

$profiles = array();

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Domain : Retail";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-10971'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-11040'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-11407'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-11430'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
$node->wikicompare_features['und'][4]['target_id'] = $features['new-11453'];
$node->wikicompare_features['und'][4]['target_type'] = 'node';
$node->wikicompare_features['und'][5]['target_id'] = $features['new-11338'];
$node->wikicompare_features['und'][5]['target_type'] = 'node';
$node->wikicompare_features['und'][6]['target_id'] = $features['new-11498'];
$node->wikicompare_features['und'][6]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-12115'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Secteur d'activite : Distribution";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, simple profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12115'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-12117'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Distribution, besoins simples";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, complex profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12115'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-11086'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-11109'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-11017'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->wikicompare_features['und'][3]['target_id'] = $features['new-11040'];
$node->wikicompare_features['und'][3]['target_type'] = 'node';
$node->wikicompare_features['und'][4]['target_id'] = $features['new-11155'];
$node->wikicompare_features['und'][4]['target_type'] = 'node';
$node->wikicompare_features['und'][5]['target_id'] = $features['new-11178'];
$node->wikicompare_features['und'][5]['target_type'] = 'node';
$node->wikicompare_features['und'][6]['target_id'] = $features['new-11246'];
$node->wikicompare_features['und'][6]['target_type'] = 'node';
$node->wikicompare_features['und'][7]['target_id'] = $features['new-11269'];
$node->wikicompare_features['und'][7]['target_type'] = 'node';
$node->wikicompare_features['und'][8]['target_id'] = $features['new-11223'];
$node->wikicompare_features['und'][8]['target_type'] = 'node';
$node->wikicompare_features['und'][9]['target_id'] = $features['new-11361'];
$node->wikicompare_features['und'][9]['target_type'] = 'node';
$node->wikicompare_features['und'][10]['target_id'] = $features['new-11521'];
$node->wikicompare_features['und'][10]['target_type'] = 'node';
$node->wikicompare_features['und'][11]['target_id'] = $features['new-11567'];
$node->wikicompare_features['und'][11]['target_type'] = 'node';
$node->wikicompare_features['und'][12]['target_id'] = $features['new-11590'];
$node->wikicompare_features['und'][12]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-12119'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Distribution, besoins complexes";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Specific profiles";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-12121'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Besoins specifiques";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Document management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12121'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->wikicompare_features['und'][0]['target_id'] = $features['new-11682'];
$node->wikicompare_features['und'][0]['target_type'] = 'node';
$node->wikicompare_features['und'][1]['target_id'] = $features['new-11659'];
$node->wikicompare_features['und'][1]['target_type'] = 'node';
$node->wikicompare_features['und'][2]['target_id'] = $features['new-11636'];
$node->wikicompare_features['und'][2]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-12123'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des documents";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Internal communication";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12121'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_features['und'] = array();
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-12125'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Communications internes";
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}
}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-10909']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-10904'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-10911']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-10906'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-10914']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-10909'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-10916']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-10911'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-10919']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-10914'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_compared')) {

$node = node_load($compareds['new-10921']);
$node->wikicompare_inherit_compared_id['und'][0]['target_id'] = $compareds['new-10916'];
$node->wikicompare_inherit_compared_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-10971']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-10971']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-10971']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-10971']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11017']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11017']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11017']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-11040']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10893'], $features['new-11086']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10898'], $features['new-11086']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11086']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11086']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10893'], $features['new-11109']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10898'], $features['new-11109']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11109']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11109']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10898'], $features['new-11155']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11155']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11155']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10893'], $features['new-11178']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10898'], $features['new-11178']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11178']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11178']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11223']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11223']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11223']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10911'], $features['new-11246']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11246']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11269']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-11338']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11338']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11338']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11338']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11361']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10909'], $features['new-11361']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11361']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-11407']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11407']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11407']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11407']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-11430']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11430']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11430']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11430']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11453']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11453']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11453']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-11498']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11498']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11498']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11498']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11521']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11521']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11521']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10895'], $features['new-11567']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11567']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11567']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11567']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11590']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11590']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11590']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10900'], $features['new-11636']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11636']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11636']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11659']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11659']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10911'], $features['new-11682']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10916'], $features['new-11751']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10921'], $features['new-11751']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10921'], $features['new-11774']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10911'], $features['new-11820']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11820']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10911'], $features['new-11843']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10911'], $features['new-11866']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11866']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11935']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11935']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-11980']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-11980']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-12002']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-12002']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-12024']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-12024']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-12047']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-12047']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10906'], $features['new-12092']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($compareds['new-10924'], $features['new-12092']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_compared')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

wikicompare_start_computation();

}

?>
