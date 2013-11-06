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
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34357'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34357'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34358'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34357'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34360'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34362'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34362'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34363'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34362'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34365'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34367'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34367'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
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
$products['new-34368'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34368'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34369'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34368'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34371'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34367'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
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
$products['new-34373'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34373'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34374'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34373'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34376'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34367'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
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
$products['new-34378'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34378'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34379'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34378'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34381'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34367'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
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
$products['new-34383'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34383'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34384'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34383'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34386'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34388'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-34388'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_short_description['und'][0]['value'] = 'This is a short description of the product. Go in the page to change it.';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
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
$products['new-34389'] = $node->nid;

$criterions = array();

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Accounting";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '1';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34390'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34390'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34413'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34413'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34436'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34413'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34459'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34459'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34482'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34459'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '25';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34505'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34390'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34528'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34528'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34551'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34528'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34574'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34390'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34597'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34597'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34620'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34597'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34643'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34666'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sellers can manage their cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34666'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34688'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34666'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34711'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34666'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34734'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '1';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34757'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34757'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34780'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34780'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34803'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34780'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34826'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34757'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34849'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34849'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34872'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34849'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34895'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34849'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34918'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '1';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34941'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Stock move management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34941'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34963'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34941'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-34986'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-34941'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35009'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35009'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35032'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35009'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35055'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 5;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35078'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35078'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35101'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35078'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35124'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35078'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35147'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 6;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35170'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35170'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35193'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35193'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35216'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35193'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35239'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35170'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35262'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35262'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35285'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35262'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35308'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35262'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35331'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 7;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '1';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35354'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35354'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35377'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35377'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35400'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35377'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35423'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35423'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35445'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35423'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35467'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access Rights";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35423'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35489'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35377'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35512'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Programming language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35354'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35534'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-35534'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-35557'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-34436'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-34505'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-34872'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-34895'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-34918'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-34803'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-34963'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-35580'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-35580'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-35582'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-35580'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-34551'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-34574'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-34482'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-34505'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-34620'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-34643'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-34711'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->wikicompare_criterions['und'][7]['target_id'] = $criterions['new-34734'];
$node->wikicompare_criterions['und'][7]['target_type'] = 'node';
$node->wikicompare_criterions['und'][8]['target_id'] = $criterions['new-34688'];
$node->wikicompare_criterions['und'][8]['target_type'] = 'node';
$node->wikicompare_criterions['und'][9]['target_id'] = $criterions['new-34826'];
$node->wikicompare_criterions['und'][9]['target_type'] = 'node';
$node->wikicompare_criterions['und'][10]['target_id'] = $criterions['new-34986'];
$node->wikicompare_criterions['und'][10]['target_type'] = 'node';
$node->wikicompare_criterions['und'][11]['target_id'] = $criterions['new-35032'];
$node->wikicompare_criterions['und'][11]['target_type'] = 'node';
$node->wikicompare_criterions['und'][12]['target_id'] = $criterions['new-35055'];
$node->wikicompare_criterions['und'][12]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-35584'] = $node->nid;

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
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-35586'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-35586'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-35147'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-35124'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-35101'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-35588'] = $node->nid;

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
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-35586'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->status = 1;
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-35590'] = $node->nid;

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

$node = node_load($products['new-34374']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-34369'];
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

$node = node_load($products['new-34376']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-34371'];
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

$node = node_load($products['new-34379']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-34374'];
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

$node = node_load($products['new-34381']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-34376'];
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

$node = node_load($products['new-34384']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-34379'];
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

$node = node_load($products['new-34386']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-34381'];
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

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-34436']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34436']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34436']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34436']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34482']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34482']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34482']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-34505']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34358'], $criterions['new-34551']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34363'], $criterions['new-34551']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34551']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34551']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34358'], $criterions['new-34574']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34363'], $criterions['new-34574']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34574']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34574']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34363'], $criterions['new-34620']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34620']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34620']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34358'], $criterions['new-34643']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34363'], $criterions['new-34643']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34643']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34643']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34688']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34688']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34688']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34376'], $criterions['new-34711']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34711']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34734']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-34803']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34803']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34803']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34803']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34826']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34374'], $criterions['new-34826']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34826']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-34872']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34872']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34872']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34872']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-34895']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34895']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34895']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34895']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34918']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34918']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34918']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-34963']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34963']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34963']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34963']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-34986']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-34986']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-34986']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34360'], $criterions['new-35032']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-35032']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35032']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35032']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-35055']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35055']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35055']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34365'], $criterions['new-35101']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35101']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35101']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35124']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35124']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34376'], $criterions['new-35147']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34381'], $criterions['new-35216']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34386'], $criterions['new-35216']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34386'], $criterions['new-35239']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34376'], $criterions['new-35285']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35285']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34376'], $criterions['new-35308']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34376'], $criterions['new-35331']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35331']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35400']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35400']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35445']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35445']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35467']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35467']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35489']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35489']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35512']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35512']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34371'], $criterions['new-35557']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-34389'], $criterions['new-35557']);
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