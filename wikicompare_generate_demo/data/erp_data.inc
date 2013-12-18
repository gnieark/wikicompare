<?php

function wikicompare_generate_erp_data() {

wikicompare_stop_computation();

$language_list = array();
foreach (language_list() as $key => $lang) {
$language_list[$key] = $key;
}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'development_method';
$settings['title'] = 'Development Method';
$settings['type'] = 'select';
$settings["allowed_values"] = "Proprietary\nOpen-source";
$settings['sequence'] = '5';
$settings['is_required'] = '1';
$settings['is_active'] = '1';
$settings['is_home'] = '0';
$settings['is_filter'] = '1';
$settings['filter_type'] = 'select';
$settings['category'] = 'Development';
$settings['category_sequence'] = '2';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "development_method", "translation" => "Methode de developpement"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'nb_developers';
$settings['title'] = 'Number of developers';
$settings['type'] = 'number';
$settings["allowed_values"] = "";
$settings['sequence'] = '2';
$settings['is_required'] = '0';
$settings['is_active'] = '1';
$settings['is_home'] = '0';
$settings['is_filter'] = '0';
$settings['filter_type'] = 'select';
$settings['category'] = 'Development';
$settings['category_sequence'] = '2';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "nb_developers", "translation" => "Nombre de developpeurs"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'editor_capital';
$settings['title'] = 'Capital';
$settings['type'] = 'number';
$settings["allowed_values"] = "";
$settings['sequence'] = '1';
$settings['is_required'] = '0';
$settings['is_active'] = '1';
$settings['is_home'] = '0';
$settings['is_filter'] = '0';
$settings['filter_type'] = 'select';
$settings['category'] = 'Editor';
$settings['category_sequence'] = '3';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "editor_capital", "translation" => "Capital"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'editor_country';
$settings['title'] = 'Editor Country';
$settings['type'] = 'select';
$settings["allowed_values"] = "USA\nEngland\nGermany\nBelgium";
$settings['sequence'] = '6';
$settings['is_required'] = '1';
$settings['is_active'] = '1';
$settings['is_home'] = '0';
$settings['is_filter'] = '1';
$settings['filter_type'] = 'checkboxes';
$settings['category'] = 'Editor';
$settings['category_sequence'] = '3';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "editor_country", "translation" => "Pays de l'editeur"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'society';
$settings['title'] = 'Society';
$settings['type'] = 'text';
$settings["allowed_values"] = "";
$settings['sequence'] = '1';
$settings['is_required'] = '1';
$settings['is_active'] = '1';
$settings['is_home'] = '1';
$settings['is_filter'] = '0';
$settings['filter_type'] = 'select';
$settings['category'] = 'General';
$settings['category_sequence'] = '1';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "society", "translation" => "Societe"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'nb_installations';
$settings['title'] = 'Number of installations / Year';
$settings['type'] = 'number';
$settings["allowed_values"] = "";
$settings['sequence'] = '2';
$settings['is_required'] = '1';
$settings['is_active'] = '1';
$settings['is_home'] = '1';
$settings['is_filter'] = '1';
$settings['filter_type'] = 'select';
$settings['category'] = 'General';
$settings['category_sequence'] = '1';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "nb_installations", "translation" => "Nb installations / an"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'release_year';
$settings['title'] = 'Release Year';
$settings['type'] = 'number';
$settings["allowed_values"] = "";
$settings['sequence'] = '3';
$settings['is_required'] = '1';
$settings['is_active'] = '1';
$settings['is_home'] = '1';
$settings['is_filter'] = '1';
$settings['filter_type'] = 'select';
$settings['category'] = 'General';
$settings['category_sequence'] = '1';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "release_year", "translation" => "Annee de sortie"))
->execute();
}

}

$settings = array();
$settings['context'] = 'add';
$settings['name'] = 'licence_cost';
$settings['title'] = 'Licence cost / year';
$settings['type'] = 'number';
$settings["allowed_values"] = "";
$settings['sequence'] = '4';
$settings['is_required'] = '1';
$settings['is_active'] = '1';
$settings['is_home'] = '1';
$settings['is_filter'] = '1';
$settings['filter_type'] = 'select';
$settings['category'] = 'General';
$settings['category_sequence'] = '1';
wikicompare_admin_infofield_modify($settings);

if (module_exists('wikicompare_translation')) {

if (in_array('fr', $language_list)) {
db_insert('wikicompare_infofields_translations')
->fields(array("language" => "fr", "infofield" => "licence_cost", "translation" => "Cout de licence / an"))
->execute();
}

}

$products = array();

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel";
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '1000000';
$node->wikicf_release_year['und'][0]['value'] = '1990';
$node->wikicf_licence_cost['und'][0]['value'] = '300';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11110'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11110'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '1000000';
$node->wikicf_release_year['und'][0]['value'] = '1990';
$node->wikicf_licence_cost['und'][0]['value'] = '300';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11111'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Comptabilite";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11110'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '700000';
$node->wikicf_release_year['und'][0]['value'] = '1998';
$node->wikicf_licence_cost['und'][0]['value'] = '800';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11113'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Gestion commerciale";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage";
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '500000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->wikicf_society['und'][0]['value'] = 'Sage';
$node->wikicf_nb_installations['und'][0]['value'] = '300000';
$node->wikicf_release_year['und'][0]['value'] = '1992';
$node->wikicf_licence_cost['und'][0]['value'] = '5000';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11115'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11115'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '300000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '300000';
$node->wikicf_release_year['und'][0]['value'] = '1992';
$node->wikicf_licence_cost['und'][0]['value'] = '3000';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11116'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Comptabilite";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11115'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '500000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->wikicf_society['und'][0]['value'] = 'Sage';
$node->wikicf_nb_installations['und'][0]['value'] = '200000';
$node->wikicf_release_year['und'][0]['value'] = '1999';
$node->wikicf_licence_cost['und'][0]['value'] = '5000';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11118'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Gestion commerciale";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP";
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11120'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11120'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11121'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11121'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11122'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules communautaires";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11121'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11124'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules officiels";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11120'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11126'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11126'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11122'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11127'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules communautaires";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11126'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11124'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11129'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules officiels";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11120'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11131'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11131'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11127'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11132'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules communautaires";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11131'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11129'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11134'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules officiels";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11120'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11136'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "";
$tnode->wikicompare_short_description["und"][0]["value"] = "Ceci est une description courte";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11136'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11132'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11138'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules communautaires";
$tnode->wikicompare_short_description["und"][0]["value"] = "";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11136'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11134'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11140'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules officiels";
$tnode->wikicompare_short_description["und"][0]["value"] = "Ceci est une description courte";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "SAP";
$node->wikicompare_sequence['und'][0]['value'] = "4";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '40000';
$node->wikicf_editor_capital['und'][0]['value'] = '900000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Germany';
$node->wikicf_society['und'][0]['value'] = 'SAP';
$node->wikicf_nb_installations['und'][0]['value'] = '6000000';
$node->wikicf_release_year['und'][0]['value'] = '1970';
$node->wikicf_licence_cost['und'][0]['value'] = '5000000';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11142'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-11142'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '40000';
$node->wikicf_editor_capital['und'][0]['value'] = '900000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Germany';
$node->wikicf_society['und'][0]['value'] = 'SAP';
$node->wikicf_nb_installations['und'][0]['value'] = '6000000';
$node->wikicf_release_year['und'][0]['value'] = '1970';
$node->wikicf_licence_cost['und'][0]['value'] = '5000000';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$products['new-11143'] = $node->nid;

$criterions = array();

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Accounting";
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "1";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11144'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Comptabilite";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Invoicing";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11144'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11167'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Facturation";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Invoice include the detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11167'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11190'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "La facture contient les details (produits, prix, etc...)";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Due date management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11167'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-highest-percentage";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11213'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion de la date d'echeance";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create one account move for each due date, with different date";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11213'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "100";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11236'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer une ecriture pour chaque date d'echeance";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Writing the date in an invoice field";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11213'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "25";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11259'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ecrire la date dans un champ de la facture";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Account move";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11144'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11282'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Mouvements comptables";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "An account move include several account move line";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11282'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11305'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Un mouvement comptable peut inclure plusieurs ecritures comptables";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Can't validate account move is sum credit different sum debit";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11282'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11328'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Impossible de valider une piece comptable si la somme des debits est different de la somme des credits";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Reporting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11144'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11351'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Rapports";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Consult account chart in the ERP interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11351'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11374'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Consulter le plan comptable depuis l'ERP";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Print general ledger";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11351'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11397'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Imprimer le grand livre";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "CRM";
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11420'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sellers can manage their cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11442'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les commerciaux peuvent suivre leurs dossiers";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to send mail through the case interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11465'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'envoyer des mails depuis l'interface du dossier";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "New emails create new cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11488'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les nouveaux emails generent de nouveaux dossiers";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sales";
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "1";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11511'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ventes";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sale order management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11511'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11534'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des commandes";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Contain order detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11534'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11557'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Contient les details de la commande (produits, prix, etc...)";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Contain payment method";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11534'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11580'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Contient la methode de paiement";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Possible processus at order confirmation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11511'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11603'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Processus possibles a la confirmation de la commande";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create invoice, then after payment create picking order";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11603'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11626'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer la facture, et apres le paiement creer l'ordre de livraison";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create picking, create manually the invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11603'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11649'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer l'ordre de livraison, creer la facture manuellement";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create picking order, then after shipping create invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11603'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11672'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Creer l'ordre de livraison, et apres l'expedition creer la facture";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Stock";
$node->wikicompare_sequence['und'][0]['value'] = "4";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "1";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11695'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Stock move management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11695'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11717'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des mouvements de stock";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Double-entry stock management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11695'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11740'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion de stock a double entree";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Location management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11695'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11763'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des emplacements";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to manage location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11763'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11786'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable de gerer les emplacements";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Manage hierachical location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11763'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11809'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gerer les emplacement de maniere hierarchique";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Document management";
$node->wikicompare_sequence['und'][0]['value'] = "5";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11832'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des documents";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Store document in ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11832'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11855'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les documents sont stockes dans l'ERP";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to attach document to record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11832'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11878'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capacle d'attacher les documents aux pieces";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access document through a virtual FTP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11832'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11901'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Acceder aux document depuis un FTP virtuel";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Internal Communication";
$node->wikicompare_sequence['und'][0]['value'] = "6";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11924'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Communication interne";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Comment record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11924'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11947'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Commenter les pieces";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to comment any record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11947'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11970'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable de commenter n'importe quelle piece";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "See all interesting comment in the home page of the ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11947'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-11993'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Voir tous les commentaires interessants sur la page d'accueil de l'ERP";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Internal Message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-11924'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12016'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Messages internes";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to send message to other ERP user";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12016'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12039'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'envoyer des messages aux autres utilisateurs de l'ERP";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to attach link to record in message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12016'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12062'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Etre capable d'attacher un lien vers les pieces dans les messages";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Number of unread message visible at all time";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12016'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12085'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Le nombre de messages non-lus est visible en permanence";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Technical";
$node->wikicompare_sequence['und'][0]['value'] = "7";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "1";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12108'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Technique";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Main concepts manage by framework";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12108'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12131'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Les principaux concept gere par le framework";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "ORM (Database and object management)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12131'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12154'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "ORM (Gestion des objets et de la base de donnees)";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12131'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12177'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12177'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12199'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12177'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12221'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access Rights";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12177'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12243'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Droits d'acces";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12131'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "3";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12266'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Programming language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12108'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12288'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Language de programmation";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Object-oriented language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-12288'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_type['und'][0]['value'] = "parent-weighted-average";
$node->wikicompare_weight['und'][0]['value'] = "1";
$node->wikicompare_suggest['und'][0]['value'] = "0";
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$criterions['new-12311'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'criterion';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Language oriente-objet";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

if (module_exists('wikicompare_profiles')) {

$profiles = array();

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Domain : Retail";
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-11190'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-11259'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-11626'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-11672'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-11649'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-11557'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-11717'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$profiles['new-12334'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Secteur d'activite : Distribution";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, simple profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12334'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$profiles['new-12336'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Distribution, besoins simples";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, complex profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12334'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-11236'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-11259'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-11374'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-11397'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-11465'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-11305'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-11328'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->wikicompare_criterions['und'][7]['target_id'] = $criterions['new-11580'];
$node->wikicompare_criterions['und'][7]['target_type'] = 'node';
$node->wikicompare_criterions['und'][8]['target_id'] = $criterions['new-11740'];
$node->wikicompare_criterions['und'][8]['target_type'] = 'node';
$node->wikicompare_criterions['und'][9]['target_id'] = $criterions['new-11786'];
$node->wikicompare_criterions['und'][9]['target_type'] = 'node';
$node->wikicompare_criterions['und'][10]['target_id'] = $criterions['new-11809'];
$node->wikicompare_criterions['und'][10]['target_type'] = 'node';
$node->wikicompare_criterions['und'][11]['target_id'] = $criterions['new-11488'];
$node->wikicompare_criterions['und'][11]['target_type'] = 'node';
$node->wikicompare_criterions['und'][12]['target_id'] = $criterions['new-11442'];
$node->wikicompare_criterions['und'][12]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$profiles['new-12338'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Distribution, besoins complexes";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Specific profiles";
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$profiles['new-12340'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Besoins specifiques";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Document management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12340'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-11901'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-11878'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-11855'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$profiles['new-12342'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Gestion des documents";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Internal communication";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-12340'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
_revisioning_publish_latest_revision($node);
$profiles['new-12344'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'profile';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Communications internes";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
_revisioning_publish_latest_revision($tnode);
}

}
}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-11127']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11122'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-11132']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11127'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-11138']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11132'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-11129']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11124'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-11134']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11129'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-11140']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-11134'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12085']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11236']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11236']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11190']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11259']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11305']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11328']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11328']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11116'], $criterions['new-11374']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11127'], $criterions['new-11580']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11649']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11649']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11140'], $criterions['new-11993']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11129'], $criterions['new-12039']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-12199']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-12154']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12154']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-12221']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-12243']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12199']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12311']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-12311']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11190']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11236']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11116'], $criterions['new-11328']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11305']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11111'], $criterions['new-11305']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11116'], $criterions['new-11305']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11465']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11129'], $criterions['new-11465']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11557']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11580']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11557']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11557']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11626']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11626']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11649']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11786']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11740']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11786']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11786']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11809']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11809']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11809']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11374']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12221']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12243']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-12266']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12266']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11190']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11111'], $criterions['new-11328']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11111'], $criterions['new-11397']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11116'], $criterions['new-11397']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11397']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11374']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11397']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11488']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11557']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11580']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11626']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11626']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11672']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11717']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11786']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11740']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11855']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11878']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11855']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11855']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11878']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11129'], $criterions['new-11901']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11134'], $criterions['new-11970']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11140'], $criterions['new-11970']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-12039']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11129'], $criterions['new-12062']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11129'], $criterions['new-12085']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11672']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11124'], $criterions['new-11190']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11672']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11672']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11113'], $criterions['new-11717']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11717']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11118'], $criterions['new-11740']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-11143'], $criterions['new-11717']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

wikicompare_start_computation();

}

?>