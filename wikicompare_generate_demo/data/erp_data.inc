<?php

function wikicompare_generate_erp_data() {

  $lang = language_default('language');

  $compared = array();


  $node = new stdClass();
  $node->type = 'compared';
  $node->language = $lang;
  $node->title = 'OpenERP';
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-root'] = $node->nid;


  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V4';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-root'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v4'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V4 Official modules';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-v4'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v4-official'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V4 Community modules';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-v4'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v4-community'] = $node->nid;



  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V5';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-root'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v5'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V5 Official modules';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-v5'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v5-official'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V5 Community modules';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-v5'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v5-community'] = $node->nid;



  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V6';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-root'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v6'] = $node->nid;


  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V6 Official modules';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-v6'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v6-official'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V6 Community modules';
  $node->language = $lang;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $compared['openerp-v6'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  node_save($node);
  $compared['openerp-v6-community'] = $node->nid;




  $feature = array();


  $node = new stdClass();
  $node->type = 'feature';
  $node->language = $lang;
  $node->title = 'Accounting';
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  $node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
  $node->wikicompare_weight['und'][0]['value'] = 1;
  node_save($node);
  $feature['accounting'] = $node->nid;



  $node = new stdClass();
  $node->type = 'feature';
  $node->language = $lang;
  $node->title = 'Invoicing';
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  $node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
  $node->wikicompare_weight['und'][0]['value'] = 1;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $feature['accounting'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  node_save($node);
  $feature['invoicing'] = $node->nid;



  $node = new stdClass();
  $node->type = 'feature';
  $node->language = $lang;
  $node->title = 'Due date management';
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  $node->wikicompare_type['und'][0]['value'] = 'parent-highest-percentage';
  $node->wikicompare_weight['und'][0]['value'] = 1;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $feature['invoicing'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  node_save($node);
  $feature['due-date'] = $node->nid;



  $node = new stdClass();
  $node->type = 'feature';
  $node->language = $lang;
  $node->title = 'Writing the date in an invoice field';
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  $node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
  $node->wikicompare_weight['und'][0]['value'] = 1;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $feature['due-date'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  node_save($node);
  $feature['due-date-field'] = $node->nid;


  $node = new stdClass();
  $node->type = 'feature';
  $node->language = $lang;
  $node->title = 'Create one account move for each due date, with different date';
  $node->wikicompare_sequence['und'][0]['value'] = 1;
  $node->wikicompare_state['und'][0]['value'] = 'published';
  $node->wikicompare_type['und'][0]['value'] = 'parent-weighted-average';
  $node->wikicompare_weight['und'][0]['value'] = 4;
  $node->wikicompare_parent_id['und'][0]['target_id'] = $feature['due-date'];
  $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
  node_save($node);
  $feature['due-date-moves'] = $node->nid;



  $implementation_id = wikicompare_get_implementation_id($compared['openerp-v4-official'], $feature['due-date-moves']);
  $node = node_load($implementation_id);
  $node->wikicompare_support['und'][0]['value'] = 1;
  $node->revision = TRUE;
  $node->revision_moderation = TRUE;
  node_save($node);
  _revisioning_publish_latest_revision($node);



}

?>
