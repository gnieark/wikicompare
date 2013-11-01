<?php

/**
 * @file
 * Fonctions and hooks which manages the actions relatives to the nodes CRUD and cache management.
 */

require_once drupal_get_path('module', 'wikicompare') . '/wikicompare.module';



/**
 * Implements hook_insert().
 * Executed each time a criterion node is created.
 *
 * @param $node
 *   The node object which was created.
 */
function criterion_insert($node) {

  //Call the type-agnostic function.
  wikicompare_insert_node('criterion', $node);

}



/**
 * Implements hook_insert().
 * Executed each time a product node is created.
 *
 * @param $node
 *   The node object which was created.
 */
function product_insert($node) {

  //Call the type-agnostic function.
  wikicompare_insert_node('product', $node);

}



/**
 * Type-agnostic function which will proceed all actions which happen when we insert a node.
 * Essentially, we need to insert new entries in wikicompare caches and create the new evaluations for each existing product or criterion.
 *
 * @param $type
 *   The type of the created node.
 *
 * @param $node
 *   The node object which was created.
 */
function wikicompare_insert_node($type, $node) {

  //Theses actions happen only for the main language node. No action for the translation nodes.
  if ($node->language != language_default('language')) {
    return;
  }



  /*
   * Insert a new record in wikicompare cache table for the created node.
   */

  //Find the parent_id of the node and ensure that the parent know he has now children.
  $parent_id = NULL;
  if (isset($node->wikicompare_parent_id['und'][0])) {
    $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];
    //Making sure that the parent know it has children.
    db_update('cache_' . $type)
      ->fields(array(
        'has_children' => 1,
      ))
      ->condition('nid', $parent_id)
      ->execute();

    //Update the created node with the powered users from his parent.
    wikicompare_update_cache_users(array(array('nid' => $node->nid)));

  }

  //Prepare the data to insert the new record in wikicompare cache table.
  $fields = array(
      'nid' => $node->nid,
      'vid' => $node->vid,
      'title' => $node->title,
      'parent_id' => $parent_id,
      'sequence' => $node->wikicompare_sequence['und'][0]['value'],
      'state' => $node->wikicompare_state['und'][0]['value'],
      'has_children' => 0,
  );

  //Product specific fields.
  if ($type == 'product') {
    $fields['short_description'] = $node->wikicompare_short_description['und'][0]['value'];
    $fields['comparable'] = $node->wikicompare_comparable['und'][0]['value'];
  }

  //Criterion specific fields.
  if ($type == 'criterion') {
    $fields['type'] = $node->wikicompare_type['und'][0]['value'];
    $fields['weight'] = $node->wikicompare_weight['und'][0]['value'];
    $fields['suggest'] = $node->wikicompare_suggest['und'][0]['value'];
  }


  if (module_exists('wikicompare_inherit_product')) {
    //Inherit product specific field.
    wikicompare_inherit_product_cache_insert_fields($fields, $type, $node);
  }

  //Insert in wikicompare cache table.
  db_insert('cache_' . $type)
    ->fields($fields)
    ->execute();



  //For product and criterion, create the new evaluations if the created node is published.
  if (in_array($type, array('product', 'criterion'))) {
    wikicompare_create_evaluations($node, $type);
  }

}





/**
 * Implements hook_delete().
 * Executed each time a criterion is deleted.
 *
 * @param $node
 *   The node object which will be deleted.
 */
function criterion_delete($node) {

  //Call the type-agnostic function.
  wikicompare_delete_node('criterion', $node);

}



/**
 * Implements hook_delete().
 * Executed each time a product is deleted.
 *
 * @param $node
 *   The node object which will be deleted.
 */
function product_delete($node) {

  //Call the type-agnostic function.
  wikicompare_delete_node('product', $node);

}



/**
 * Implements hook_delete().
 * Executed each time an evaluation is deleted.
 *
 * @param $node
 *   The node object which will be deleted.
 */
function evaluation_delete($node) {

  if (module_exists('wikicompare_translation')) {
    //Delete the translation nodes of the deleted node.
    wikicompare_translation_delete_after($node);
  }

}


/**
 * Type-agnostic function which will proceed all actions which happen when we delete a node.
 * Essentially, we need to remove the entries in wikicompare caches and delete the evaluations linked the deleted product or criterion.
 *
 * @param $type
 *   The type of the deleted node.
 *
 * @param $node
 *   The node object which was deleted.
 */
function wikicompare_delete_node($type, $node) {

  //Theses actions happen only for the main language node. No action for the translation nodes.
  if ($node->language != language_default('language')) {
    return;
  }

  //At this time, the node is deleted in Drupal but not in the cache table, which means the users of the deleted nodes are deleted but not the link with his children. So we launch the update users function to update the children users before updating the cache.
  wikicompare_update_cache_users(array(array('nid' => $node->nid)));

  //Only products and criterions are linked to evaluations.
  if (in_array($type, array('product', 'criterion'))) {

    //Find all evaluation nodes.
    //We can use field_data* field because this field should not be modified so nor have revision. We don't use cache table because field_data* is more reliable.
    $evaluation_ids = array();
    $query = db_select('field_data_wikicompare_' . $type . '_id', 'c');
    $query->addField('c', 'entity_id', 'entity_id');
    $query->condition('c.wikicompare_' . $type . '_id_target_id', $node->nid, '=');
    $result = $query->execute();
    foreach ($result as $record) {
      $evaluation_ids[$record->entity_id] = $record->entity_id;
    }

    // Delete all evaluations found.
    node_delete_multiple($evaluation_ids);

    //Delete them in the wikicompare cache.
    if (!empty($evaluation_ids)) {
      db_delete('cache_evaluation')
        ->condition('nid', $evaluation_ids, 'in')
        ->execute();
    }

  }

  //Delete the node in the wikicompare cache.
  db_delete('cache_' . $type)
    ->condition('nid', $node->nid)
    ->execute();

  //Update cache so all children are now without parent.
  db_update('cache_' . $type)
    ->fields(array(
      'parent_id' => NULL,
    ))
    ->condition('parent_id', $node->nid)
    ->execute();

  if (module_exists('wikicompare_inherit_product')) {
    //Update the product which was inheriting the deleted product.
    wikicompare_inherit_product_cache_product_delete($node);
  }

  //If the deleted node had parent, we will check if the parent must keep his has_children flag or not.
  if (isset($node->wikicompare_parent_id['und'][0])) {

    //Get all current children of the parent node.
    $childs = array();
    $query = db_select('cache_' . $type, 'c');
    $query->addField('c', 'nid', 'nid');
    $query->condition('c.parent_id', $node->wikicompare_parent_id['und'][0], '=');
    $result = $query->execute();
    foreach ($result as $record) {
      $childs[$record->nid] = $record->nid;
    }

    //If the parent has no children anymore, we update his has_children flag.
    if (empty($childs)) {
      db_update('cache_' . $type)
        ->fields(array(
          'has_children' => 0,
        ))
        ->condition('nid', $node->wikicompare_parent_id['und'][0])
        ->execute();
    }

    //We launch the tree update on the parent node, so it can recompute his new data.
    if (in_array($type, array('product', 'criterion'))) {
      wikicompare_update_compare_tree($type, array($node->wikicompare_parent_id['und'][0]['target_id']));
    }
  }

  if (module_exists('wikicompare_translation')) {
    //Delete the translation nodes of the deleted node.
    wikicompare_translation_delete_after($node);
  }

}


/**
 * Implements hook_revisionapi() provided by revisionning module.
 * Executed two time when a node is published, before and after the publishing. This function is type-agnostic.
 * We'll use this hook to update the compare tree and the caches when some value is changed in the wikicompare nodes.
 *
 * @param $op
 *   Flag allowing us to know when the hook was invoked.
 *
 * @param $node_revision
 *   The node revision which will be published.
 */
function wikicompare_revisionapi($op, $node_revision) {

  //Theses actions happen only for the main language node. No action for the translation nodes.
  if ($node_revision->language != language_default('language')) {
    return;
  }

  /*
   * Action to do before a node is published.
   */
  if ($op == 'pre publish') {

    //Types which must be checked by the function. All types defined by wikicompare module are concerned.
    $types = array('product', 'criterion', 'evaluation');

    if (module_exists('wikicompare_profiles')) {
      //Add profile type.
      wikicompare_profiles_node_types($types);
    }

    //Verify that the node must be checked, based on his type.
    if (in_array($node_revision->type, $types)) {

      $to_update = array();

      //$node_revision contain the new data, with this load we recover the old data actually saved in database.
      //This way we will be able to know which value was changed, and so know what to do. If a node is updated but no critical value is changed, then no update on the compare tree will be done.
      $current_node = node_load($node_revision->nid);

      //Types which must check their parent_id. All types defined by wikicompare module are concerned, except evaluation which does not have parent_id field.
      $types = array('product', 'criterion');

      if (module_exists('wikicompare_profiles')) {
        //Add profile type.
        wikicompare_profiles_node_types($types);
      }

      //Verify that the parent_id field must be checked, based on his type.
      if (in_array($node_revision->type, $types)) {

        //Recover old and new parent_id value.
        $node_revision_parent = NULL;
        $current_node_parent = NULL;
        if ($node_revision->wikicompare_parent_id) {
          $node_revision_parent = $node_revision->wikicompare_parent_id['und'][0]['target_id'];
        }
        if ($current_node->wikicompare_parent_id) {
          $current_node_parent = $current_node->wikicompare_parent_id['und'][0]['target_id'];
        }

        //If the parent has changed. This is quite a big change so many things will happen.
        if ($node_revision_parent != $current_node_parent) {

          //Making sure that the new parent know it has children.
          if ($node_revision_parent != NULL) {
            db_update('cache_' . $node_revision->type)
              ->fields(array(
                'has_children' => 1,
              ))
              ->condition('nid', $node_revision_parent)
              ->execute();
          }

          //If the old parent has no children anymore, we update his has_children flag
          if ($current_node_parent != NULL) {
            //Get all remaining children.
            $childs = array();
            $query = db_select('cache_' . $node_revision->type, 'c');
            $query->addField('c', 'nid', 'nid');
            $query->condition('c.parent_id', $current_node_parent, '=');
            $result = $query->execute();
            foreach ($result as $record) {
              //The revision isn't published yet, so Drupal think that the updated node is still one of the children, we must not take it into account.
              if ($node_revision->nid != $record->nid) {
                $childs[$record->nid] = $record->nid;
              }
            }
            //Update the has_children flag. The update of this flag is the only reason why we let profile nodes go until here.
            if (empty($childs)) {
              db_update('cache_' . $node_revision->type)
                ->fields(array(
                  'has_children' => 0,
                ))
                ->condition('nid', $current_node_parent)
                ->execute();
            }
          }

          //We will trigger a tree update on both the old parent and the new parent, because their values may change because of the change in their children.
          if (in_array($node_revision->type, array('product', 'criterion'))) {
            $to_update[$node_revision->nid] = $node_revision->nid;
            $to_update[$node_revision_parent] = $node_revision_parent;
            $to_update[$current_node_parent] = $current_node_parent;

            //Mark the modified node so his evaluations will be updated with his new evaluations parents on product and criterion axis.
            db_update('cache_' . $node_revision->type)
              ->fields(array(
                'parent_changed' => 1,
              ))
              ->condition('nid', $node_revision->nid)
              ->execute();
          }

        }
      }

      if (module_exists('wikicompare_inherit_product')) {
        //Trigger tree update if inherit_product has changed.
        wikicompare_inherit_product_preupdate_product($to_update, $node_revision, $current_node);
      }

      //Tests based on product specific fields.
      if ($node_revision->type == 'product') {
        if ($node_revision->wikicompare_state['und'][0]['value'] != $current_node->wikicompare_state['und'][0]['value']) {
          $to_update[$node_revision->nid] = $node_revision->nid;
        }
      }

      //Tests based on criterion specific fields.
      if ($node_revision->type == 'criterion') {
        if (($node_revision->wikicompare_type['und'][0]['value'] != $current_node->wikicompare_type['und'][0]['value']) || ($node_revision->wikicompare_weight['und'][0]['value'] != $current_node->wikicompare_weight['und'][0]['value']) || ($node_revision->wikicompare_state['und'][0]['value'] != $current_node->wikicompare_state['und'][0]['value']) || ($node_revision->wikicompare_suggest['und'][0]['value'] != $current_node->wikicompare_suggest['und'][0]['value'])) {
          $to_update[$node_revision->nid] = $node_revision->nid;
        }
      }

      //Tests based on evaluation specific fields.
      if ($node_revision->type == 'evaluation') {
        if ($node_revision->wikicompare_support['und'][0]['value'] != $current_node->wikicompare_support['und'][0]['value']) {
          $to_update[$node_revision->nid] = $node_revision->nid;
        }
        if (module_exists('wikicompare_inherit_product')) {
          //Trigger tree update if use_from_inherit has changed.
          wikicompare_inherit_product_preupdate_evaluation($to_update, $node_revision, $current_node);
        }
      }

      //If any of the critical field have changed.
      if (!empty($to_update)) {
        //Only the type related to the compare tree need to be mark for update.
        if (in_array($node_revision->type, array('product', 'criterion', 'evaluation'))) {
          //We mark the marked nodes, his old parent and his new parent for update
          db_update('cache_' . $node_revision->type)
            ->fields(array(
              'to_update' => 1,
            ))
            ->condition('nid', $to_update, 'IN')
            ->execute();
        }
      }

    }

  }



  /*
   * Action to do after a node is published
   */
  if ($op == 'post publish') {

    //Types which must be checked by the function. All types defined by wikicompare module are concerned.
    $types = array('product', 'criterion', 'evaluation');

    if (module_exists('wikicompare_profiles')) {
      //Add profile type.
      wikicompare_profiles_node_types($types);
    }

    //Verify that the node must be checked, based on his type.
    if (in_array($node_revision->type, $types)) {

      //Prepare the data to update the wikicompare cache of the updated node.
      $fields = array(
        'vid' => $node_revision->vid,
      );

      //Common field to all nodes, except evaluation.
      if ($node_revision->type != 'evaluation') {

        $fields['title'] = $node_revision->title;
        $parent_id = NULL;
        if (isset($node_revision->wikicompare_parent_id['und'][0])) {
          $parent_id = $node_revision->wikicompare_parent_id['und'][0]['target_id'];
        }
        $fields['parent_id'] = $parent_id;
        $fields['sequence'] = $node_revision->wikicompare_sequence['und'][0]['value'];
        $fields['state'] = $node_revision->wikicompare_state['und'][0]['value'];
        //Update the power users on the node and his children.
        wikicompare_update_cache_users(array(array('nid' => $node_revision->nid)));

      //evaluation specific fields.
      } else {
        $fields['support']= $node_revision->wikicompare_support['und'][0]['value'];
      }

      //Product specific fields.
      if ($node_revision->type == 'product') {
        $fields['short_description'] = $node_revision->wikicompare_short_description['und'][0]['value'];
        $fields['comparable'] = $node_revision->wikicompare_comparable['und'][0]['value'];
      }

      //Criterion specific fields.
      if ($node_revision->type == 'criterion') {
        $fields['type'] = $node_revision->wikicompare_type['und'][0]['value'];
        $fields['weight'] = $node_revision->wikicompare_weight['und'][0]['value'];
        $fields['suggest'] = $node_revision->wikicompare_suggest['und'][0]['value'];
      }

      if (module_exists('wikicompare_inherit_product')) {
        //Inherit product module specific fields.
        wikicompare_inherit_product_cache_update_fields($fields, $node_revision);
      }

      //Update the wikicompare cache with the new data.
      db_update('cache_' . $node_revision->type)
          ->fields($fields)
          ->condition('nid', $node_revision->nid)
          ->execute();

    }

    //Get all the node to update
    $node_nids = array();
    $query = db_select('cache_' . $node_revision->type, 'n');
    $query->addField('n', 'nid', 'nid');
    if (in_array($node_revision->type, array('product', 'criterion'))) {
      $query->addField('n', 'parent_changed', 'parent_changed');
    }
    if (module_exists('wikicompare_inherit_product')) {
      //Update the query to get inherit_changed flag.
      wikicompare_inherit_product_get_inherit_changed($query, $node_revision->type);
    }
    $query->condition('n.to_update', 1, '=');
    $result = $query->execute();
    foreach($result as $record) {
      $node_nids[$record->nid] = $record->nid;
      $nodes[$record->nid] = $record;
    }

    //Trigger a tree update on all the marked nodes.
    if ($node_nids) {
      //If the parent product of criterion have change, we need to update the parent evaluations through product or criterion axis.
      foreach ($nodes as $node) {

        //Update the cache_evaluation with the new structural fields, needed for the percent computation.
        if (in_array($node_revision->type, array('product', 'criterion'))) {

          //Create the missing evaluations if the node is published without being published before.
          wikicompare_create_evaluations($node_revision, $node_revision->type);

          $fields = array();
          $query = db_select('cache_' . $node_revision->type, 'n');
          $query->addField('n', 'parent_id', 'parent_id');
          $query->addField('n', 'state', 'state');
          $query->addField('n', 'has_children', 'has_children');
          if ($node_revision->type == 'criterion') {
            $query->addField('n', 'type', 'type');
            $query->addField('n', 'weight', 'weight');
          }
          $query->condition('n.nid', $node->nid);
          $result = $query->execute();
          foreach($result as $record) {
            $fields[$node_revision->type . '_parent_id'] = $record->parent_id;
            $fields[$node_revision->type . '_state'] = $record->state;
            $fields[$node_revision->type . '_has_children'] = $record->has_children;
            if ($node_revision->type == 'criterion') {
              $fields['criterion_type'] = $node_revision->wikicompare_type['und'][0]['value'];
              $fields['criterion_weight'] = $node_revision->wikicompare_weight['und'][0]['value'];
            }
          }

          db_update('cache_evaluation')
              ->fields($fields)
              ->condition($node_revision->type . '_id', $node->nid)
              ->execute();
        }

        if (in_array($node_revision->type, array('product', 'criterion'))) {
          if ($node->parent_changed) {
            wikicompare_update_parent_link($node_revision->type, $node_revision->nid);
            db_update('cache_' . $node_revision->type)
              ->fields(array(
                'parent_changed' => 0
              ))
              ->condition('nid', $node->nid)
              ->execute();
          }

          if (module_exists('wikicompare_inherit_product')) {
            //Update the parent_through_inherit fields in evaluation.
            wikicompare_inherit_product_update_parent_evaluations($node, $node_revision->type);
          }

        }
      }
      //Trigger the tree update.
      wikicompare_update_compare_tree($node_revision->type, $node_nids);
      //Unmark the nodes.
      db_update('cache_' . $node_revision->type)
        ->fields(array(
          'to_update' => 0
        ))
        ->condition('nid', $node_nids, 'IN')
        ->execute();
    }

    if (module_exists('wikicompare_profiles')) {
      //Update the profile_criterions many2many cache table.
      wikicompare_profiles_after_update_fields($node_revision);
    }

  }
}



/**
 * Create the new evaluations.
 *
 * @param $node
 *   The node which was created/modified.
 *
 * @param $type
 *   The type of the node.
 */
function wikicompare_create_evaluations($node, $type) {

  //We create the evaluations only if the node is published.
  if (!in_array($node->wikicompare_state['und'][0]['value'], unserialize(WIKICOMPARE_STATE_PUBLISHED))) {
    return;
  }

  //Find the countertype of the created node, product for criterion and criterion for product.
  $countertype = '';
  if ($type == 'product') {
    $countertype = 'criterion';
  } elseif ($type == 'criterion') {
    $countertype = 'product';
  }

  $parent_id = NULL;
  if (isset($node->wikicompare_parent_id['und'][0])) {
    $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];
  }

  // Find all countertype node of the main language.
  // We don't use cache table because node is more reliable for such important task and there is no performance worries here.
  $counternodes = array();
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('cache', 'parent_id', 'parent_id');
  if ($countertype == 'criterion') {
    $query->addField('cache', 'type', 'type');
    $query->addField('cache', 'weight', 'weight');
  }
  $query->addField('cache', 'state', 'state');
  $query->addField('cache', 'has_children', 'has_children');
  $query->addField('ni', 'nid', 'evaluation_nid');
  $query->leftjoin('cache_' . $countertype, 'cache', 'n.nid = cache.nid');
  /*
   * I don't like at all using the table cache for the evaluation creation because they are less reliable than node/fields table. Unfortunately, using node/fields table would mean using at least four more join and I believe it would really cost us too much on the perf side.
   * The main problem which can happen is that an implemention doesn't exist in cache but exist in node, and so another evaluation will be created for the same couple product/criterion. If this situation happenned too often, we'll need to add a list in administration with all the duplicated evaluation, so the admin can chose which one should be deleted.
   */
  $query->leftjoin('cache_evaluation', 'ni', 'n.nid = ni.' . $countertype . '_id AND ni.' . $type . '_id = ' . $node->nid);
  $query->condition('n.type', $countertype);
  $query->condition('n.language', language_default('language'));
  $query->condition('cache.state', unserialize(WIKICOMPARE_STATE_PUBLISHED), 'in');
  $result = $query->execute();
  foreach ($result as $record) {
    //Check if the evaluation is already created.
    if (!$record->evaluation_nid) {
      $counternodes[$record->nid] = $record;
    }
  }

  //Create a new evaluation node for each countertype nodes
  foreach ($counternodes as $counternode){
    $node_evaluation = new stdClass();
    $node_evaluation->type = 'evaluation';
    // Add default parameters
    node_object_prepare($node_evaluation);
    //evaluations has no title, we insert evaluation here because this title will be visible in the dashboard, so we can identify them more easily.
    $node_evaluation->title = 'evaluation';
    $node_evaluation->language = language_default('language');

    //The evaluation has both a criterion_id and a product_id
    $node_evaluation->{'wikicompare_' . $type . '_id'}['und'][0]['target_id'] = $node->nid;
    $node_evaluation->{'wikicompare_' . $type . '_id'}['und'][0]['target_type'] = "node";
    $node_evaluation->{'wikicompare_' . $countertype . '_id'}['und'][0]['target_id'] = $counternode->nid;
    $node_evaluation->{'wikicompare_' . $countertype . '_id'}['und'][0]['target_type'] = "node";

    if (module_exists('wikicompare_inherit_product')) {
      //Inherit product specific field.
      wikicompare_inherit_product_insert_evaluation($node_evaluation);
    }

    //Save the evaluation node in database.
    node_save($node_evaluation);

    if ($type == 'criterion') {
      $criterion_type = $node->wikicompare_type['und'][0]['value'];
      $criterion_weight = $node->wikicompare_weight['und'][0]['value'];
    } else {
      $criterion_type = $counternode->type;
      $criterion_weight = $counternode->weight;
    }

    //Prepare to add the new record in wikicompare cache table.
    $cache_evaluation = array(
      'nid' => $node_evaluation->nid,
      'vid' => $node_evaluation->vid,
      'criterion_id' => $node_evaluation->wikicompare_criterion_id['und'][0]['target_id'],
      'product_id' => $node_evaluation->wikicompare_product_id['und'][0]['target_id'],
      'support' => 0,
      $type . '_parent_id' => $parent_id,
      $type . '_state' => $node->wikicompare_state['und'][0]['value'],
      $type . '_has_children' => 0,
      $countertype . '_parent_id' => $counternode->parent_id,
      $countertype . '_state' => $counternode->state,
      $countertype . '_has_children' => $counternode->has_children,
      'criterion_type' => $criterion_type,
      'criterion_weight' => $criterion_weight,
    );

    if (module_exists('wikicompare_inherit_product')) {
      //Inherit product specific field.
      wikicompare_inherit_product_cache_evaluation_fields($cache_evaluation, $node_evaluation);
    }

    //Add the prepared evaluation fields in array so we can insert them all at once later.
    $cache_evaluations[] = $cache_evaluation;

  }

  //Insert the created evaluation in their caches.
  if (!empty($cache_evaluation)) {

    //Prepare the header for the mass insert in evaluation cache table.
    $header = array('nid', 'vid', 'criterion_id', 'product_id', 'support', $type . '_parent_id', $type . '_state', $type . '_has_children', $countertype . '_parent_id', $countertype . '_state', $countertype . '_has_children', 'criterion_type', 'criterion_weight');

    if (module_exists('wikicompare_inherit_product')) {
      //Inherit product specific field.
      wikicompare_inherit_product_cache_fields_header($header, 'evaluation');
    }

    $query = db_insert('cache_evaluation')->fields($header);
    foreach ($cache_evaluations as $evaluation) {
      $query->values($evaluation);
    }
    $query->execute();

    //Update parent_through_product_id and parent_through_criterion_id field in cache_evaluation. We can't make it at the evaluation creation because the parent through counternode axis are created at the same time.
    wikicompare_update_parent_link($type, $node->nid);

    if (module_exists('wikicompare_inherit_product')) {
      //Update parent_through_inherit_id.
      wikicompare_inherit_product_insert_parent_inherit($node);
    }

    //Force the update of the compare tree, starting from the created node. It's a node without children on product and criterion axis because it's a just created node.
    wikicompare_update_compare_tree($type, array($node->nid));

  }

}



/**
 * Function which will update the parent though product and criterion fields in cache_evaluation. Theses fields are important for the percentage computation.
 *
 * @param $nid
 *   The nid of the product or criterion which we need to update the evaluation. If empty, all evaluation will be updated.
 */
function wikicompare_update_parent_link($type=NULL, $nid=NULL) {

  if (Database::getConnection()->databaseType() == 'mysql') {
    $query = 'UPDATE cache_evaluation n
           INNER JOIN cache_product product ON n.product_id = product.nid
           LEFT JOIN cache_evaluation ncp ON (product.parent_id = ncp.product_id AND n.criterion_id = ncp.criterion_id)
           INNER JOIN cache_criterion criterion ON n.criterion_id = criterion.nid
           LEFT JOIN cache_evaluation nfp ON (criterion.parent_id = nfp.criterion_id AND n.product_id = nfp.product_id)
           SET n.parent_through_product_id = ncp.nid, n.parent_through_criterion_id = nfp.nid';
    if ($nid != NULL) {
      $query = $query . ' WHERE ' . $type . '.nid = ' . $nid;
    }
  } else {
    $query = 'UPDATE cache_evaluation
      SET parent_through_product_id = ncp.nid,
          parent_through_criterion_id = nfp.nid
      FROM cache_evaluation n
      INNER JOIN cache_product product ON n.product_id = product.nid
      LEFT JOIN cache_evaluation ncp ON (product.parent_id = ncp.product_id AND n.criterion_id = ncp.criterion_id)
      INNER JOIN cache_criterion criterion ON n.criterion_id = criterion.nid
      LEFT JOIN cache_evaluation nfp ON (criterion.parent_id = nfp.criterion_id AND n.product_id = nfp.product_id)
      WHERE cache_evaluation.nid = n.nid';
    if ($nid != NULL) {
      $query = $query . ' AND ' . $type . '.nid = ' . $nid;
    }
  }

  db_query($query);

}





/**
 * Function which will update the power users of the specified node with the power users from his parent.
 * This function is a recursive function, which will then update the power users of his children.
 *
 * @param $nodes
 *   The array containing the nodes we want to update the power users from parents.
 */
function wikicompare_update_cache_users($nodes) {

  $parent_ids = array();
  $nids = array();
  foreach ($nodes as $node) {
    if (isset($node['parent_id'])) {
      $parent_ids[$node['parent_id']] = $node['parent_id'];
    }
    $nids[$node['nid']] = $node['nid'];
  }

  //Users from parent field are only filled by this function, so we flush it before rebuild it.
  db_delete('field_data_wikicompare_user_from_parent_ids')
    ->condition('entity_id', $nids, 'in')
    ->execute();
  db_delete('field_revision_wikicompare_user_from_parent_ids')
    ->condition('entity_id', $nids, 'in')
    ->execute();

  //We can only get users from parent node if there is a parent node.
  if (!empty($parent_ids)) {
    //Get the users of the parent node.
    $users = wikicompare_test_access_node('get_users', $parent_ids);

    //The table we want to update is a Drupal table, so we need to give his required fields.
    $to_insert = array();
    foreach ($nodes as $node) {
      if (isset($node['parent_id'])) {
        if (isset($users[$node['parent_id']])) {
          foreach ($users[$node['parent_id']] as $user) {
            $field = $user;
            $field['entity_id'] = $node['nid'];
            $field['revision_id'] = $node['vid'];
            $to_insert[] = $field;
          }
        }
      }
    }

    if (!empty($to_insert)) {
      //Insert the users from parents in the tables.
      $query = db_insert('field_data_wikicompare_user_from_parent_ids')->fields(array('entity_type', 'bundle', 'deleted', 'entity_id', 'revision_id', 'language', 'delta', 'wikicompare_user_from_parent_ids_target_id'));
      foreach ($to_insert as $insert) {
        $query->values($insert);
      }
      $query->execute();
      $query = db_insert('field_revision_wikicompare_user_from_parent_ids')->fields(array('entity_type', 'bundle', 'deleted', 'entity_id', 'revision_id', 'language', 'delta', 'wikicompare_user_from_parent_ids_target_id'));
      foreach ($to_insert as $insert) {
        $query->values($insert);
      }
      $query->execute();
    }
  }

  //Find all children of the updated node, and launch the recursive function to update them.
  $children = array();
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'vid', 'vid');
  $query->addField('f', 'wikicompare_parent_id_target_id', 'parent_id');
  $query->leftjoin('field_revision_wikicompare_parent_id', 'f', 'n.vid = f.revision_id');
  $query->condition('f.wikicompare_parent_id_target_id', $nids, 'in');
  $result = $query->execute();
  foreach ($result as $record) {
    $children[$record->nid]['nid'] = $record->nid;
    $children[$record->nid]['vid'] = $record->vid;
    $children[$record->nid]['parent_id'] = $record->parent_id;
  }

  if (!empty($children)) {
    //Launch the recursive function.
    wikicompare_update_cache_users($children);
  }

}

?>
