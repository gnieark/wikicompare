<?php
//READY

/**
 * @file
 * Fonctions and hooks which manages the actions relatives to the nodes CRUD and cache management.
 */



/**
 * Implements hook_insert().
 * Executed each time a feature node is created.
 *
 * @param $node
 *   The node object which was created.
 */
function feature_insert($node) {

  //Call the type-agnostic function.
  wikicompare_insert_node('feature', $node);

}



/**
 * Implements hook_insert().
 * Executed each time a compared node is created.
 *
 * @param $node
 *   The node object which was created.
 */
function compared_insert($node) {

  //Call the type-agnostic function.
  wikicompare_insert_node('compared', $node);

}



/**
 * Type-agnostic function which will proceed all actions which happen when we insert a node.
 * Essentially, we need to insert new entries in wikicompare caches and create the new implementations for each existing compared or feature.
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

  //Find the countertype of the created node, compared for feature and feature for compared.
  $countertype = '';
  if ($type == 'compared') {
    $countertype = 'feature';
  } elseif ($type == 'feature') {
    $countertype = 'compared';
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
    wikicompare_update_cache_users($node->nid, $parent_id, $type, $node->vid);

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

  //Feature specific fields.
  if ($type == 'feature') {
    $fields['type'] = $node->wikicompare_type['und'][0]['value'];
    $fields['weight'] = $node->wikicompare_weight['und'][0]['value'];
  }


  if (module_exists('wikicompare_inherit_compared')) {
    //Inherit compared specific field.
    wikicompare_inherit_compared_cache_insert_fields($fields, $type, $node);
  }

  //Insert in wikicompare cache table.
  db_insert('cache_' . $type)
    ->fields($fields)
    ->execute();



  /*
   * Create the new implementations.
   */

  //Only the compareds and features create new implementations.
  if (in_array($type, array('compared', 'feature'))) {

    // Find all countertype node of the main language.
    // We don't use cache table because node is more reliable for such important task and there is no performance worries here.
    $counternodes = array();
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('fp', 'wikicompare_parent_id_target_id', 'parent_id');
    $query->leftjoin('field_revision_wikicompare_parent_id', 'fp', 'n.vid = fp.revision_id');
    $query->condition('n.type', $countertype);
    $query->condition('n.language', language_default('language'));
    $result = $query->execute();
    foreach ($result as $record) {
      $counternodes[$record->nid] = $record;
    }

    //Create a new implementation node for each countertype nodes
    foreach ($counternodes as $counternode){
      $node_implementation = new stdClass();
      $node_implementation->type = 'implementation';
      // Add default parameters
      node_object_prepare($node_implementation);
      //Implementations has no title, we insert Implementation here because this title will be visible in the dashboard, so we can identify them more easily.
      $node_implementation->title = 'Implementation';
      $node_implementation->language = language_default('language');
      //The implementation has both a feature_id and a compared_id
      if ($type == 'compared') {
        $node_implementation->wikicompare_feature_id['und'][0]['target_id'] = $counternode->nid;
        $node_implementation->wikicompare_feature_id['und'][0]['target_type'] = "node";
        $node_implementation->wikicompare_compared_id['und'][0]['target_id'] = $node->nid;
        $node_implementation->wikicompare_compared_id['und'][0]['target_type'] = "node";
      } else {
        $node_implementation->wikicompare_compared_id['und'][0]['target_id'] = $counternode->nid;
        $node_implementation->wikicompare_compared_id['und'][0]['target_type'] = "node";
        $node_implementation->wikicompare_feature_id['und'][0]['target_id'] = $node->nid;
        $node_implementation->wikicompare_feature_id['und'][0]['target_type'] = "node";
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Inherit compared specific field.
        wikicompare_inherit_compared_insert_implementation($node_implementation);
      }

      //Save the implementation node in database.
      node_save($node_implementation);

      //Prepare to add the new record in wikicompare cache table.
      $cache_implementation = array(
        'nid' => $node_implementation->nid,
        'vid' => $node_implementation->vid,
        'feature_id' => $node_implementation->wikicompare_feature_id['und'][0]['target_id'],
        'compared_id' => $node_implementation->wikicompare_compared_id['und'][0]['target_id'],
        'support' => 0,
      );

      if (module_exists('wikicompare_inherit_compared')) {
        //Inherit compared specific field.
        wikicompare_inherit_compared_cache_implementation_fields($cache_implementation, $node_implementation);
      }

      //Add the prepared implementation fields in array so we can insert them all at once later.
      $cache_implementations[] = $cache_implementation;


    }

    //Prepare the header for the mass insert in implementation cache table.
    $header = array('nid', 'vid', 'feature_id', 'compared_id', 'support');

    if (module_exists('wikicompare_inherit_compared')) {
      //Inherit compared specific field.
      wikicompare_inherit_compared_cache_fields_header($header, 'implementation');
    }

    //Insert the created implementation in their caches.
    if (!empty($cache_implementation)) {
      $query = db_insert('cache_implementation')->fields($header);
      foreach ($cache_implementations as $implementation) {
        $query->values($implementation);
      }
      $query->execute();
    }

    //Force the update of the compare tree, starting from the created node. It's a node without children on compared and feature axis because it's a just created node.
    wikicompare_update_compare_tree($type, array($node->nid));
  }

}





/**
 * Implements hook_delete().
 * Executed each time a feature is deleted.
 *
 * @param $node
 *   The node object which will be deleted.
 */
function feature_delete($node) {

  //Call the type-agnostic function.
  wikicompare_delete_node('feature', $node);

}



/**
 * Implements hook_delete().
 * Executed each time a compared is deleted.
 *
 * @param $node
 *   The node object which will be deleted.
 */
function compared_delete($node) {

  //Call the type-agnostic function.
  wikicompare_delete_node('compared', $node);

}



/**
 * Implements hook_delete().
 * Executed each time an implementation is deleted.
 *
 * @param $node
 *   The node object which will be deleted.
 */
function implementation_delete($node) {

  if (module_exists('wikicompare_translation')) {
    //Delete the translation nodes of the deleted node.
    wikicompare_translation_delete_after($node);
  }

}


/**
 * Type-agnostic function which will proceed all actions which happen when we delete a node.
 * Essentially, we need to remove the entries in wikicompare caches and delete the implementations linked the deleted compared or feature.
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
  wikicompare_update_cache_users($node->nid);

  //Only compareds and features are linked to implementations.
  if (in_array($type, array('compared', 'feature'))) {

    //Find all implementation nodes.
    //We can use field_data* field because this field should not be modified so nor have revision. We don't use cache table because field_data* is more reliable.
    $implementation_ids = array();
    $query = db_select('field_data_wikicompare_' . $type . '_id', 'c');
    $query->addField('c', 'entity_id', 'entity_id');
    $query->condition('c.wikicompare_' . $type . '_id_target_id', $node->nid, '=');
    $result = $query->execute();
    foreach ($result as $record) {
      $implementation_ids[$record->entity_id] = $record->entity_id;
    }

    // Delete all implementations found.
    node_delete_multiple($implementation_ids);

    //Delete them in the wikicompare cache.
    if (!empty($implementation_ids)) {
      db_delete('cache_comparative_table')
        ->condition('nid', $implementation_ids, 'in')
        ->execute();

      db_delete('cache_implementation')
        ->condition('nid', $implementation_ids, 'in')
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

  if (module_exists('wikicompare_inherit_compared')) {
    //Update the compared which was inheriting the deleted compared.
    wikicompare_inherit_compared_cache_compared_delete($node);
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
    if (in_array($type, array('compared', 'feature'))) {
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
    $types = array('compared', 'feature', 'implementation');

    if (module_exists('wikicompare_needs')) {
      //Add need type.
      wikicompare_needs_node_types($types);
    }

    //Verify that the node must be checked, based on his type.
    if (in_array($node_revision->type, $types)) {

      $to_update = array();

      //$node_revision contain the new data, with this load we recover the old data actually saved in database.
      //This way we will be able to know which value was changed, and so know what to do. If a node is updated but no critical value is changed, then no update on the compare tree will be done.
      $current_node = node_load($node_revision->nid);

      //Types which must check their parent_id. All types defined by wikicompare module are concerned, except implementation which does not have parent_id field.
      $types = array('compared', 'feature');

      if (module_exists('wikicompare_needs')) {
        //Add need type.
        wikicompare_needs_node_types($types);
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
            //Update the has_children flag. The update of this flag is the only reason why we let need nodes go until here.
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
          if (in_array($node_revision->type, array('compared', 'feature'))) {
            $to_update[$node_revision->nid] = $node_revision->nid;
            $to_update[$node_revision_parent] = $node_revision_parent;
            $to_update[$current_node_parent] = $current_node_parent;
          }

        }
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Trigger tree update if inherit_compared has changed.
        wikicompare_inherit_compared_preupdate_compared($to_update, $node_revision, $current_node);
      }

      //Tests based on feature specific fields.
      if ($node_revision->type == 'feature') {
        if (($node_revision->wikicompare_type['und'][0]['value'] != $current_node->wikicompare_type['und'][0]['value']) || ($node_revision->wikicompare_weight['und'][0]['value'] != $current_node->wikicompare_weight['und'][0]['value']) || ($node_revision->wikicompare_state['und'][0]['value'] != $current_node->wikicompare_state['und'][0]['value'])) {
          $to_update[$node_revision->nid] = $node_revision->nid;
        }
      }

      //Tests based on implementation specific fields.
      if ($node_revision->type == 'implementation') {
        if ($node_revision->wikicompare_support['und'][0]['value'] != $current_node->wikicompare_support['und'][0]['value']) {
          $to_update[$node_revision->nid] = $node_revision->nid;
        }
        if (module_exists('wikicompare_inherit_compared')) {
          //Trigger tree update if use_from_inherit has changed.
          wikicompare_inherit_compared_preupdate_implementation($to_update, $node_revision, $current_node);
        }
      }

      //If any of the critical field have changed.
      if (!empty($to_update)) {
        //Only the type related to the compare tree need to be mark for update.
        if (in_array($node_revision->type, array('compared', 'feature', 'implementation'))) {
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
    $types = array('compared', 'feature', 'implementation');

    if (module_exists('wikicompare_needs')) {
      //Add need type.
      wikicompare_needs_node_types($types);
    }

    //Verify that the node must be checked, based on his type.
    if (in_array($node_revision->type, $types)) {

      //Prepare the data to update the wikicompare cache of the updated node.
      $fields = array(
        'vid' => $node_revision->vid,
      );

      //Common field to all nodes, except implementation.
      if ($node_revision->type != 'implementation') {

        $fields['title'] = $node_revision->title;
        $parent_id = NULL;
        if (isset($node_revision->wikicompare_parent_id['und'][0])) {
          $parent_id = $node_revision->wikicompare_parent_id['und'][0]['target_id'];
        }
        $fields['parent_id'] = $parent_id;
        $fields['sequence'] = $node_revision->wikicompare_sequence['und'][0]['value'];
        $fields['state'] = $node_revision->wikicompare_state['und'][0]['value'];
        //Update the power users on the node and his children.
        wikicompare_update_cache_users($node_revision->nid, $parent_id, $node_revision->type, $node_revision->vid);

      //Implementation specific fields.
      } else {
        $fields['support']= $node_revision->wikicompare_support['und'][0]['value'];
      }

      //Feature specific fields.
      if ($node_revision->type == 'feature') {
        $fields['type'] = $node_revision->wikicompare_type['und'][0]['value'];
        $fields['weight'] = $node_revision->wikicompare_weight['und'][0]['value'];
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Inherit compared module specific fields.
        wikicompare_inherit_compared_cache_update_fields($fields, $node_revision);
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
    $query->condition('n.to_update', 1, '=');
    $result = $query->execute();
    foreach($result as $item) {
      $node_nids[$item->nid] = $item->nid;
    }

    //Trigger a tree update on all the marked nodes.
    if ($node_nids) {
      //Trigger the tree update.
      wikicompare_update_compare_tree($node_revision->type, $node_nids);
      //Unmark the nodes.
      db_update('cache_' . $node_revision->type)
        ->fields(array(
          'to_update' => 0,
        ))
        ->condition('nid', $node_nids, 'IN')
        ->execute();
    }

    if (module_exists('wikicompare_needs')) {
      //Update the need_features many2many cache table.
      wikicompare_needs_after_update_fields($node_revision);
    }

  }
}





/**
 * Function which will update the power users of the specified node with the power users from his parent.
 * This function is a recursive function, which will then update the power users of his children.
 *
 * @param $nid
 *   The nid of the node to update.
 *
 * @param $parent_id
 *   The parent_id of the node, used to find the power users of the parent.
 *
 * @param $type
 *   The type of the node.
 *
 * @param $vid
 *   The vid of the active revision, used to find the power users of the good revision.
 */
function wikicompare_update_cache_users($nid, $parent_id=NULL, $type=NULL, $vid=NULL) {

  //Users from parent field are only filled by this function, so we flush it before rebuild it.
  db_delete('field_data_wikicompare_user_from_parent_ids')
    ->condition('entity_id', $nid)
    ->execute();
  db_delete('field_revision_wikicompare_user_from_parent_ids')
    ->condition('entity_id', $nid)
    ->execute();

  //We can only get users from parent node if there is a parent node.
  if ($parent_id != NULL) {
    //Get the users of the parent node.
    $users = wikicompare_test_access_node('get_users', $parent_id);

    //If there is users in the parent node.
    if (!empty($users)) {

      //The table we want to update is a Drupal table, so we need to give his required fields.
      foreach ($users as $uid => $user) {
        $users[$uid]['bundle'] = $type;
        $users[$uid]['entity_id'] = $nid;
        $users[$uid]['revision_id'] = $vid;
      }

      //Insert the users from parents in the tables.
      $query = db_insert('field_data_wikicompare_user_from_parent_ids')->fields(array('entity_type', 'bundle', 'deleted', 'entity_id', 'revision_id', 'language', 'delta', 'wikicompare_user_from_parent_ids_target_id'));
      foreach ($users as $user) {
        $query->values($user);
      }
      $query->execute();
      $query = db_insert('field_revision_wikicompare_user_from_parent_ids')->fields(array('entity_type', 'bundle', 'deleted', 'entity_id', 'revision_id', 'language', 'delta', 'wikicompare_user_from_parent_ids_target_id'));
      foreach ($users as $user) {
        $query->values($user);
      }
      $query->execute();

    }
  }

  //Find all children of the updated node, and launch the recursive function to update them.
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'vid', 'vid');
  $query->leftjoin('field_revision_wikicompare_parent_id', 'f', 'n.vid = f.revision_id');
  $query->condition('f.wikicompare_parent_id_target_id', $nid);
  $result = $query->execute();
  foreach ($result as $record) {
    //Launch the recursive function.
    wikicompare_update_cache_users($record->nid, $nid, $type, $record->vid);
  }

}

?>
