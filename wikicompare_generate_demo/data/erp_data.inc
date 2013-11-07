<?php

function wikicompare_generate_erp_data() {

wikicompare_stop_computation();

$language_list = array();
foreach (language_list() as $key => $lang) {
$language_list[$key] = $key;
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

$products = array();

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel";
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '1000000';
$node->wikicf_release_year['und'][0]['value'] = '1990';
$node->wikicf_licence_cost['und'][0]['value'] = '300';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46711'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46711'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '1000000';
$node->wikicf_release_year['und'][0]['value'] = '1990';
$node->wikicf_licence_cost['und'][0]['value'] = '300';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46712'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Comptabilite";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46711'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '700000';
$node->wikicf_release_year['und'][0]['value'] = '1998';
$node->wikicf_licence_cost['und'][0]['value'] = '800';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46714'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Ciel Gestion commerciale";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
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
$node->wikicf_society['und'][0]['value'] = 'Sage';
$node->wikicf_nb_installations['und'][0]['value'] = '300000';
$node->wikicf_release_year['und'][0]['value'] = '1992';
$node->wikicf_licence_cost['und'][0]['value'] = '5000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '500000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46716'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46716'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '300000';
$node->wikicf_release_year['und'][0]['value'] = '1992';
$node->wikicf_licence_cost['und'][0]['value'] = '3000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '300000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46717'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Comptabilite";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46716'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'Sage';
$node->wikicf_nb_installations['und'][0]['value'] = '200000';
$node->wikicf_release_year['und'][0]['value'] = '1999';
$node->wikicf_licence_cost['und'][0]['value'] = '5000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_editor_capital['und'][0]['value'] = '500000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46719'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "Sage Gestion commerciale";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
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
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46721'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46721'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46722'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46722'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46723'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules communautaires";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46722'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46725'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V4 Modules officiels";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46721'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46727'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46727'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46723'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46728'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules communautaires";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46727'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46725'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46730'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V5 Modules officiels";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46721'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46732'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46732'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46728'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46733'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules communautaires";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46732'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46730'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46735'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V6 Modules officiels";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46721'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "always-combine";
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46737'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46737'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46733'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46738'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules communautaires";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
}

}

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46737'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46735'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46740'] = $node->nid;

if (module_exists('wikicompare_translation')) {

$node->tnid = $node->nid;
node_save($node);

if (in_array('fr', $language_list)) {
$tnode = new stdClass();
$tnode->type = 'product';
$tnode->language = 'fr';
$tnode->tnid = $node->nid;
$tnode->title = "OpenERP V7 Modules officiels";
$tnode->status = 1;
$tnode->promote = 0;
$tnode->sticky = 0;
$tnode->comment = 2;
node_save($tnode);
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
$node->wikicf_society['und'][0]['value'] = 'SAP';
$node->wikicf_nb_installations['und'][0]['value'] = '6000000';
$node->wikicf_release_year['und'][0]['value'] = '1970';
$node->wikicf_licence_cost['und'][0]['value'] = '5000000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '40000';
$node->wikicf_editor_capital['und'][0]['value'] = '900000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Germany';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46742'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-46742'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_short_description['und'][0]['value'] = "This is a short description of the product. Go in the page to change it.";
$node->wikicompare_comparable['und'][0]['value'] = "only-without-children";
$node->wikicf_society['und'][0]['value'] = 'SAP';
$node->wikicf_nb_installations['und'][0]['value'] = '6000000';
$node->wikicf_release_year['und'][0]['value'] = '1970';
$node->wikicf_licence_cost['und'][0]['value'] = '5000000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_nb_developers['und'][0]['value'] = '40000';
$node->wikicf_editor_capital['und'][0]['value'] = '900000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Germany';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-46743'] = $node->nid;

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
$criterions['new-46744'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Invoicing";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46744'];
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
$criterions['new-46767'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Invoice include the detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46767'];
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
$criterions['new-46790'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Due date management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46767'];
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
$criterions['new-46813'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create one account move for each due date, with different date";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46813'];
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
$criterions['new-46836'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Writing the date in an invoice field";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46813'];
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
$criterions['new-46859'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Account move";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46744'];
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
$criterions['new-46882'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "An account move include several account move line";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46882'];
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
$criterions['new-46905'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Can't validate account move is sum credit different sum debit";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46882'];
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
$criterions['new-46928'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Reporting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46744'];
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
$criterions['new-46951'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Consult account chart in the ERP interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46951'];
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
$criterions['new-46974'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Print general ledger";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-46951'];
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
$criterions['new-46997'] = $node->nid;

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
$criterions['new-47020'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sellers can manage their cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47020'];
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
$criterions['new-47042'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to send mail through the case interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47020'];
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
$criterions['new-47065'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "New emails create new cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47020'];
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
$criterions['new-47088'] = $node->nid;

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
$criterions['new-47111'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sale order management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47111'];
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
$criterions['new-47134'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Contain order detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47134'];
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
$criterions['new-47157'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Contain payment method";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47134'];
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
$criterions['new-47180'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Possible processus at order confirmation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47111'];
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
$criterions['new-47203'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create invoice, then after payment create picking order";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47203'];
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
$criterions['new-47226'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create picking order, then after shipping create invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47203'];
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
$criterions['new-47249'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create picking, create manually the invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47203'];
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
$criterions['new-47272'] = $node->nid;

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
$criterions['new-47295'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Stock move management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47295'];
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
$criterions['new-47317'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Double-entry stock management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47295'];
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
$criterions['new-47340'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Location management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47295'];
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
$criterions['new-47363'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to manage location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47363'];
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
$criterions['new-47386'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Manage hierachical location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47363'];
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
$criterions['new-47409'] = $node->nid;

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
$criterions['new-47432'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Store document in ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47432'];
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
$criterions['new-47455'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to attach document to record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47432'];
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
$criterions['new-47478'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access document through a virtual FTP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47432'];
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
$criterions['new-47501'] = $node->nid;

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
$criterions['new-47524'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Comment record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47524'];
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
$criterions['new-47547'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to comment any record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47547'];
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
$criterions['new-47570'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "See all interesting comment in the home page of the ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47547'];
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
$criterions['new-47593'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Internal Message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47524'];
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
$criterions['new-47616'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to send message to other ERP user";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47616'];
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
$criterions['new-47639'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to attach link to record in message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47616'];
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
$criterions['new-47662'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Number of unread message visible at all time";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47616'];
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
$criterions['new-47685'] = $node->nid;

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
$criterions['new-47708'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Main concepts manage by framework";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47708'];
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
$criterions['new-47731'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "ORM (Database and object management)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47731'];
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
$criterions['new-47754'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47731'];
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
$criterions['new-47777'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47777'];
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
$criterions['new-47799'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47777'];
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
$criterions['new-47821'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access Rights";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47777'];
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
$criterions['new-47843'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47731'];
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
$criterions['new-47866'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Programming language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47708'];
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
$criterions['new-47888'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Object-oriented language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-47888'];
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
$criterions['new-47911'] = $node->nid;

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
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-46790'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-46859'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-47226'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-47249'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-47272'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-47157'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-47317'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-47934'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, simple profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-47934'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-47936'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, complex profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-47934'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "2";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-46905'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-46928'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-46836'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-46859'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-46974'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-46997'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-47065'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->wikicompare_criterions['und'][7]['target_id'] = $criterions['new-47088'];
$node->wikicompare_criterions['und'][7]['target_type'] = 'node';
$node->wikicompare_criterions['und'][8]['target_id'] = $criterions['new-47042'];
$node->wikicompare_criterions['und'][8]['target_type'] = 'node';
$node->wikicompare_criterions['und'][9]['target_id'] = $criterions['new-47180'];
$node->wikicompare_criterions['und'][9]['target_type'] = 'node';
$node->wikicompare_criterions['und'][10]['target_id'] = $criterions['new-47340'];
$node->wikicompare_criterions['und'][10]['target_type'] = 'node';
$node->wikicompare_criterions['und'][11]['target_id'] = $criterions['new-47386'];
$node->wikicompare_criterions['und'][11]['target_type'] = 'node';
$node->wikicompare_criterions['und'][12]['target_id'] = $criterions['new-47409'];
$node->wikicompare_criterions['und'][12]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-47938'] = $node->nid;

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
$profiles['new-47940'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Document management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-47940'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-47501'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-47478'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-47455'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-47942'] = $node->nid;

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
}

}

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Internal communication";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-47940'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = "1";
$node->wikicompare_state['und'][0]['value'] = "published";
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-47944'] = $node->nid;

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
}

}
}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-46728']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46723'];
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

$node = node_load($products['new-46730']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46725'];
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

$node = node_load($products['new-46733']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46728'];
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

$node = node_load($products['new-46735']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46730'];
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

$node = node_load($products['new-46738']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46733'];
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

$node = node_load($products['new-46740']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-46735'];
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

$evaluation_id = wikicompare_get_evaluation_id($products['new-46712'], $criterions['new-46905']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46712'], $criterions['new-46928']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46712'], $criterions['new-46997']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-46790']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-46859']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-47157']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-47226']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-47249']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-47317']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46714'], $criterions['new-47386']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46717'], $criterions['new-46905']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46717'], $criterions['new-46928']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46717'], $criterions['new-46974']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46717'], $criterions['new-46997']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-46790']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-46836']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47042']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47157']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47180']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47226']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47249']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47272']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47317']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47340']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47386']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47409']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46719'], $criterions['new-47455']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-46790']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-46836']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-46905']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-46928']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-46974']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-46997']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47042']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47157']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47226']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47249']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47272']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47317']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47340']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47386']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47409']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47455']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47478']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47754']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47799']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47821']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47843']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47866']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46725'], $criterions['new-47911']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46728'], $criterions['new-47180']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46730'], $criterions['new-47065']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46730'], $criterions['new-47501']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46730'], $criterions['new-47639']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46730'], $criterions['new-47662']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46730'], $criterions['new-47685']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46735'], $criterions['new-47570']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46740'], $criterions['new-47570']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46740'], $criterions['new-47593']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-46790']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-46836']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-46905']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-46928']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-46974']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-46997']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47042']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47065']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47088']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47157']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47180']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47226']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47249']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47272']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47317']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47340']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47386']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47409']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47455']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47478']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47639']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47685']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47754']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47799']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47821']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47843']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47866']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-46743'], $criterions['new-47911']);
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