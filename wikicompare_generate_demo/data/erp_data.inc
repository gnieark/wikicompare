<?php

function wikicompare_generate_erp_data() {

  $compared = array();


  $node = new stdClass();
  $node->type = 'compared';
  $node->language = LANGUAGE_NONE;
  $node->title = 'OpenERP';
  node_save($node);
  $compared['openerp-root'] = $node->nid;


  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V4';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-root'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v4'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V4 Official modules';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-v4'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v4-official'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V4 Community modules';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-v4'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v4-community'] = $node->nid;



  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V5';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-root'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v5'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V5 Official modules';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-v5'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v5-official'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V5 Community modules';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-v5'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v5-community'] = $node->nid;



  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V6';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-root'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v6'] = $node->nid;


  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V6 Official modules';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-v6'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v6-official'] = $node->nid;

  $node = new stdClass();
  $node->type = 'compared';
  $node->title = 'OpenERP V6 Community modules';
  $node->language = LANGUAGE_NONE;
  $node->compared_parent_compared[$node->language][0]['target_id'] = $compared['openerp-v6'];
  $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
  node_save($node);
  $compared['openerp-v6-community'] = $node->nid;




  $feature = array();


  $node = new stdClass();
  $node->type = 'feature';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Accounting';
  $node->feature_state[$node->language][0]['value'] = 'Published';
  $node->feature_type[$node->language][0]['value'] = 'parent-weighted-average';
  $node->feature_weight[$node->language][0]['value'] = 1;
  node_save($node);
  $feature['accounting'] = $node->nid;



  $node = new stdClass();
  $node->type = 'feature';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Invoicing';
  $node->feature_state[$node->language][0]['value'] = 'Published';
  $node->feature_type[$node->language][0]['value'] = 'parent-weighted-average';
  $node->feature_weight[$node->language][0]['value'] = 1;
  $node->feature_parent_feature[$node->language][0]['target_id'] = $feature['accounting'];
  $node->feature_parent_feature[$node->language][0]['target_type'] = "node";
  node_save($node);
  $feature['invoicing'] = $node->nid;



  $node = new stdClass();
  $node->type = 'feature';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Due date management';
  $node->feature_state[$node->language][0]['value'] = 'Published';
  $node->feature_type[$node->language][0]['value'] = 'parent-highest-percentage';
  $node->feature_weight[$node->language][0]['value'] = 1;
  $node->feature_parent_feature[$node->language][0]['target_id'] = $feature['invoicing'];
  $node->feature_parent_feature[$node->language][0]['target_type'] = "node";
  node_save($node);
  $feature['due-date'] = $node->nid;



  $node = new stdClass();
  $node->type = 'feature';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Writing the date in an invoice field';
  $node->feature_state[$node->language][0]['value'] = 'Published';
  $node->feature_type[$node->language][0]['value'] = 'parent-weighted-average';
  $node->feature_weight[$node->language][0]['value'] = 1;
  $node->feature_parent_feature[$node->language][0]['target_id'] = $feature['due-date'];
  $node->feature_parent_feature[$node->language][0]['target_type'] = "node";
  node_save($node);
  $feature['due-date-field'] = $node->nid;


  $node = new stdClass();
  $node->type = 'feature';
  $node->language = LANGUAGE_NONE;
  $node->title = 'Create one account move for each due date, with different date';
  $node->feature_state[$node->language][0]['value'] = 'Published';
  $node->feature_type[$node->language][0]['value'] = 'parent-weighted-average';
  $node->feature_weight[$node->language][0]['value'] = 4;
  $node->feature_parent_feature[$node->language][0]['target_id'] = $feature['due-date'];
  $node->feature_parent_feature[$node->language][0]['target_type'] = "node";
  node_save($node);
  $feature['due-date-moves'] = $node->nid;



  $implementation_id = wikicompare_get_implementation_id($compared['openerp-v4-official'], $feature['due-date-moves']);
  $node = node_load($implementation_id);
  $node->implementation_support[LANGUAGE_NONE][0]['value'] = 1;
  $node->revision = TRUE;
  $node->revision_moderation = TRUE;
  node_save($node);
  _revisioning_publish_latest_revision($node);



}

?>
