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

$products = array();

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '1000000';
$node->wikicf_release_year['und'][0]['value'] = '1990';
$node->wikicf_licence_cost['und'][0]['value'] = '300';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14025'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14025'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '1000000';
$node->wikicf_release_year['und'][0]['value'] = '1990';
$node->wikicf_licence_cost['und'][0]['value'] = '300';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14026'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Ciel Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14025'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '700000';
$node->wikicf_release_year['und'][0]['value'] = '1998';
$node->wikicf_licence_cost['und'][0]['value'] = '800';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '200000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14027'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'Sage';
$node->wikicf_nb_installations['und'][0]['value'] = '300000';
$node->wikicf_release_year['und'][0]['value'] = '1992';
$node->wikicf_licence_cost['und'][0]['value'] = '5000';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '500000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14028'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Accounting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14028'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'Ciel';
$node->wikicf_nb_installations['und'][0]['value'] = '300000';
$node->wikicf_release_year['und'][0]['value'] = '1992';
$node->wikicf_licence_cost['und'][0]['value'] = '3000';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '300000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14029'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "Sage Commercial management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14028'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'Sage';
$node->wikicf_nb_installations['und'][0]['value'] = '200000';
$node->wikicf_release_year['und'][0]['value'] = '1999';
$node->wikicf_licence_cost['und'][0]['value'] = '5000';
$node->wikicf_nb_developers['und'][0]['value'] = '1500';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '500000000';
$node->wikicf_editor_country['und'][0]['value'] = 'England';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14030'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP";
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14031'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14031'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14032'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14032'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14033'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V4 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14032'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '4000';
$node->wikicf_release_year['und'][0]['value'] = '2007';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14034'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14031'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14035'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14035'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14036'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V5 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14035'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '7000';
$node->wikicf_release_year['und'][0]['value'] = '2009';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14037'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14031'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14038'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14038'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14039'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V6 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14038'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '10000';
$node->wikicf_release_year['und'][0]['value'] = '2011';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14040'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14031'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'always-combine';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14041'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Community modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14041'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14042'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "OpenERP V7 Official modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14041'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'OpenERP SA';
$node->wikicf_nb_installations['und'][0]['value'] = '15000';
$node->wikicf_release_year['und'][0]['value'] = '2012';
$node->wikicf_nb_developers['und'][0]['value'] = '200';
$node->wikicf_development_method['und'][0]['value'] = 'Open-source';
$node->wikicf_editor_capital['und'][0]['value'] = '5000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Belgium';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14043'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "SAP";
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'SAP';
$node->wikicf_nb_installations['und'][0]['value'] = '6000000';
$node->wikicf_release_year['und'][0]['value'] = '1970';
$node->wikicf_licence_cost['und'][0]['value'] = '5000000';
$node->wikicf_nb_developers['und'][0]['value'] = '40000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '900000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Germany';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14044'] = $node->nid;

$node = new stdClass();
$node->type = 'product';
$node->language = 'en';
$node->title = "SAP R/3";
$node->wikicompare_parent_id['und'][0]['target_id'] = $products['new-14044'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_comparable['und'][0]['value'] = 'only-without-children';
$node->wikicf_society['und'][0]['value'] = 'SAP';
$node->wikicf_nb_installations['und'][0]['value'] = '6000000';
$node->wikicf_release_year['und'][0]['value'] = '1970';
$node->wikicf_licence_cost['und'][0]['value'] = '5000000';
$node->wikicf_nb_developers['und'][0]['value'] = '40000';
$node->wikicf_development_method['und'][0]['value'] = 'Proprietary';
$node->wikicf_editor_capital['und'][0]['value'] = '900000000';
$node->wikicf_editor_country['und'][0]['value'] = 'Germany';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$products['new-14045'] = $node->nid;

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
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14046'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Invoicing";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14046'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14068'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Invoice include the detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14068'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14090'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Due date management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14068'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14112'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create one account move for each due date, with different date";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14112'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '100';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14134'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Writing the date in an invoice field";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14112'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '25';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14156'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Account move";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14046'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14178'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "An account move include several account move line";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14178'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14200'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Can't validate account move is sum credit different sum debit";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14178'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14222'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Reporting";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14046'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14244'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Consult account chart in the ERP interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14244'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14266'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Print general ledger";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14244'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14288'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "CRM";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14310'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sellers can manage their cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14310'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14332'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to send mail through the case interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14310'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14354'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "New emails create new cases";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14310'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14376'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sales";
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14398'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Sale order management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14398'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14420'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Contain order detail (product, price, etc...)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14442'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Contain payment method";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14420'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14464'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Possible processus at order confirmation";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14398'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14486'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create invoice, then after payment create picking order";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14486'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14508'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create picking order, then after shipping create invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14486'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14530'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Create picking, create manually the invoice";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14486'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14552'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Stock";
$node->wikicompare_sequence['und'][0]['value'] = 4;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14574'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Stock move management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14574'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14596'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Double-entry stock management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14574'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14618'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Location management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14574'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14640'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to manage location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14640'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14662'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Manage hierachical location";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14640'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14684'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Document management";
$node->wikicompare_sequence['und'][0]['value'] = 5;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14706'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Store document in ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14706'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14728'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to attach document to record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14706'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14750'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access document through a virtual FTP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14706'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14772'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Internal Communication";
$node->wikicompare_sequence['und'][0]['value'] = 6;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14794'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Comment record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14794'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14816'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to comment any record";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14816'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14838'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "See all interesting comment in the home page of the ERP";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14816'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14860'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Internal Message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14794'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14882'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to send message to other ERP user";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14882'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14904'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Being able to attach link to record in message";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14882'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14926'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Number of unread message visible at all time";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14882'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14948'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Technical";
$node->wikicompare_sequence['und'][0]['value'] = 7;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '2';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14970'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Main concepts manage by framework";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14970'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-14992'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "ORM (Database and object management)";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14992'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15014'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Interface";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14992'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15036'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Form definition";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-15036'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15058'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Menu";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-15036'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15080'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Access Rights";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-15036'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15102'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Modules";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14992'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 3;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15124'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Programming language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-14970'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15146'] = $node->nid;

$node = new stdClass();
$node->type = 'criterion';
$node->language = 'en';
$node->title = "Object-oriented language";
$node->wikicompare_parent_id['und'][0]['target_id'] = $criterions['new-15146'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
$node->wikicompare_weight['und'][0]['value'] = '1';
$node->wikicompare_suggest['und'][0]['value'] = '0';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$criterions['new-15168'] = $node->nid;

if (module_exists('wikicompare_profiles')) {

$profiles = array();

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Domain : Retail";
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-14090'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-14156'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-14508'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-14530'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-14552'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-14442'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-14596'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-15190'] = $node->nid;

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, simple profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-15190'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-15191'] = $node->nid;

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Retail, complex profiles";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-15190'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-14200'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-14222'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-14134'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->wikicompare_criterions['und'][3]['target_id'] = $criterions['new-14156'];
$node->wikicompare_criterions['und'][3]['target_type'] = 'node';
$node->wikicompare_criterions['und'][4]['target_id'] = $criterions['new-14266'];
$node->wikicompare_criterions['und'][4]['target_type'] = 'node';
$node->wikicompare_criterions['und'][5]['target_id'] = $criterions['new-14288'];
$node->wikicompare_criterions['und'][5]['target_type'] = 'node';
$node->wikicompare_criterions['und'][6]['target_id'] = $criterions['new-14354'];
$node->wikicompare_criterions['und'][6]['target_type'] = 'node';
$node->wikicompare_criterions['und'][7]['target_id'] = $criterions['new-14376'];
$node->wikicompare_criterions['und'][7]['target_type'] = 'node';
$node->wikicompare_criterions['und'][8]['target_id'] = $criterions['new-14332'];
$node->wikicompare_criterions['und'][8]['target_type'] = 'node';
$node->wikicompare_criterions['und'][9]['target_id'] = $criterions['new-14464'];
$node->wikicompare_criterions['und'][9]['target_type'] = 'node';
$node->wikicompare_criterions['und'][10]['target_id'] = $criterions['new-14618'];
$node->wikicompare_criterions['und'][10]['target_type'] = 'node';
$node->wikicompare_criterions['und'][11]['target_id'] = $criterions['new-14662'];
$node->wikicompare_criterions['und'][11]['target_type'] = 'node';
$node->wikicompare_criterions['und'][12]['target_id'] = $criterions['new-14684'];
$node->wikicompare_criterions['und'][12]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-15192'] = $node->nid;

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Specific profiles";
$node->wikicompare_sequence['und'][0]['value'] = 2;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-15193'] = $node->nid;

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Document management";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-15193'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->wikicompare_criterions['und'][0]['target_id'] = $criterions['new-14772'];
$node->wikicompare_criterions['und'][0]['target_type'] = 'node';
$node->wikicompare_criterions['und'][1]['target_id'] = $criterions['new-14750'];
$node->wikicompare_criterions['und'][1]['target_type'] = 'node';
$node->wikicompare_criterions['und'][2]['target_id'] = $criterions['new-14728'];
$node->wikicompare_criterions['und'][2]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-15194'] = $node->nid;

$node = new stdClass();
$node->type = 'profile';
$node->language = 'en';
$node->title = "Internal communication";
$node->wikicompare_parent_id['und'][0]['target_id'] = $profiles['new-15193'];
$node->wikicompare_parent_id['und'][0]['target_type'] = 'node';
$node->wikicompare_sequence['und'][0]['value'] = 1;
$node->wikicompare_state['und'][0]['value'] = 'published';
$node->wikicompare_criterions['und'] = array();
$node->promote = 0;
$node->sticky = 0;
$node->comment = 2;
node_save($node);
$profiles['new-15195'] = $node->nid;
}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-14036']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-14033'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-14037']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-14034'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-14039']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-14036'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-14040']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-14037'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-14042']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-14039'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

if (module_exists('wikicompare_inherit_product')) {

$node = node_load($products['new-14043']);
$node->wikicompare_inherit_product_id['und'][0]['target_id'] = $products['new-14040'];
$node->wikicompare_inherit_product_id['und'][0]['target_type'] = 'node';
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

}

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14090']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14090']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14090']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14090']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14134']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14134']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 1;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14134']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14156']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14026'], $criterions['new-14200']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14029'], $criterions['new-14200']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14200']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14200']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14026'], $criterions['new-14222']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14029'], $criterions['new-14222']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14222']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14222']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14029'], $criterions['new-14266']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14266']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14266']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14026'], $criterions['new-14288']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14029'], $criterions['new-14288']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14288']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14288']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14332']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14332']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14332']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14037'], $criterions['new-14354']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14354']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14376']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14442']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14464']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14036'], $criterions['new-14464']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14464']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14508']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14508']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14508']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14508']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14530']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14530']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14530']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14530']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14552']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14552']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14552']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14596']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14596']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14596']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14596']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14618']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14618']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14618']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14027'], $criterions['new-14662']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14662']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14662']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14662']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14684']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14684']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14684']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14030'], $criterions['new-14728']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14728']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14728']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-14750']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14750']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14037'], $criterions['new-14772']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14040'], $criterions['new-14838']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14043'], $criterions['new-14838']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14043'], $criterions['new-14860']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14037'], $criterions['new-14904']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14904']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14037'], $criterions['new-14926']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14037'], $criterions['new-14948']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-14948']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-15014']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-15014']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-15058']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-15058']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-15080']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-15080']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-15102']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-15102']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-15124']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-15124']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14034'], $criterions['new-15168']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
$node->wikicompare_use_from_inherit['und'][0]['value'] = 0;
}
$node->promote = 0;
$node->sticky = 0;
$node->revision = TRUE;
$node->revision_moderation = TRUE;
node_save($node);
_revisioning_publish_latest_revision($node);

$evaluation_id = wikicompare_get_evaluation_id($products['new-14045'], $criterions['new-15168']);
$node = node_load($evaluation_id);
$node->wikicompare_support['und'][0]['value'] = 1;
if (module_exists('wikicompare_inherit_product')) {
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
