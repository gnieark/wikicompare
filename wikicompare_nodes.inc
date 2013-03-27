<?php


/**
 * Implements hook_insert().
 * Executed each time a feature node is created.
 * When a new feature is created, we also create all the implementation needed, so one for each compared to cross with the feature created
 */
function feature_insert($node) {


  /*
   * Create a new implementation for all compared node
   */

  //Create the new feature in the cache table
  $feature_parent_feature = NULL;
  if (isset($node->feature_parent_feature['und'][0])) {
    $feature_parent_feature = $node->feature_parent_feature['und'][0]['target_id'];
    //Making sure that the parent know it has children
    db_update('cache_feature')
      ->fields(array(
        'has_children' => 1,
      ))
      ->condition('nid', $feature_parent_feature)
      ->execute();
  }
  db_insert('cache_feature')
    ->fields(array(
      'nid' => $node->nid,
      'vid' => $node->vid,
      'title' => $node->title,
      'parent_feature_id' => $feature_parent_feature,
      'type' => $node->feature_type['und'][0]['value'],
      'weight' => $node->feature_weight['und'][0]['value'],
      'state' => $node->feature_state['und'][0]['value'],
      'has_children' => 0,
    ))
    ->execute();

  // Find all compared node. We don't use cache table because node is more reliable for such important task and there is no performance problem here.
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('cp', 'compared_parent_compared_target_id', 'parent_id');
  $query->leftjoin('field_revision_compared_parent_compared', 'cp', 'n.vid = cp.revision_id');
  $query->condition('n.type', 'compared', '=');
  $result = $query->execute();

  $nids = array();
  foreach ($result as $record) {
    $nids[] = $record;
  }

  $cache_implementations = array();
  $to_update = array();
  //Create a new implementation node for each compared node
  foreach ($nids as $compared){
    $node_implementation = new stdClass();
    $node_implementation->type = 'implementation';
    // Add default parameters
    node_object_prepare($node_implementation);
    $node_implementation->language = LANGUAGE_NONE;
    //Filling entity reference field
    $node_implementation->implementation_feature[$node_implementation->language][]['target_id'] = $node->nid;
    $node_implementation->implementation_feature[$node_implementation->language][]['target_type'] = "node";
    $node_implementation->implementation_compared[$node_implementation->language][]['target_id'] = $compared->nid;
    $node_implementation->implementation_compared[$node_implementation->language][]['target_type'] = "node";

    //Allow others modules to modify the implrmentation to insert
    foreach (module_implements('wikicompare_insert_implementation') as $module) {
      $function = $module . '_wikicompare_insert_implementation';
      $function($node_implementation);
    }

    node_save($node_implementation);

    //Prepare to add the implementation in cache table
    $cache_implementation = array(
      'nid' => $node_implementation->nid,
      'vid' => $node_implementation->vid,
      'feature_id' => $node_implementation->implementation_feature['und'][0]['target_id'],
      'compared_id' => $node_implementation->implementation_compared['und'][0]['target_id'],
      'support' => 0,
    );

    //Allow others modules to modify the cache implrmentation to insert
    foreach (module_implements('wikicompare_cache_implementation_fields') as $module) {
      $function = $module . '_wikicompare_cache_implementation_fields';
      $function($cache_implementation, $node_implementation);
    }


    $cache_implementations[] = $cache_implementation;

  }

  //If some fields for implementation cache are defined in other module, then we need to modify the header before the mass insert
  $header = array('nid', 'vid', 'feature_id', 'compared_id', 'support');
  foreach (module_implements('wikicompare_cache_implementation_fields_header') as $module) {
    $function = $module . '_wikicompare_cache_implementation_fields_header';
    $function($header);
  }

  //Update the cache_implementation table before the compare tree computation
  if (!empty($cache_implementations)) {
    $query = db_insert('cache_implementation')->fields($header);
    foreach ($cache_implementations as $record) {
      $query->values($record);
    }
    $query->execute();
  }

  //Update the compare tree with the new data
  wikicompare_update_compare_tree('feature', array($node->nid));

}

/**
 * Implements hook_insert().
 * Executed each time a compared node is created.
 * When a new compared is created, we also create all the implementation needed, so one for each feature to cross with the compared created
 */
function compared_insert($node) {


  /*
   * Create a new implementation for all feature node
   */

  //Create the new compared in the cache table
  $compared_parent_compared = NULL;
  if (isset($node->compared_parent_compared['und'][0])) {
    $compared_parent_compared = $node->compared_parent_compared['und'][0]['target_id'];
    //Making sure that the parent know it has children
    db_update('cache_compared')
      ->fields(array(
        'has_children' => 1,
      ))
      ->condition('nid', $compared_parent_compared)
      ->execute();
  }

  $fields = array(
      'nid' => $node->nid,
      'vid' => $node->vid,
      'title' => $node->title,
      'parent_compared_id' => $compared_parent_compared,
      'has_children' => 0,
  );

  //Allow to insert other field from other modules. The $fields variable will be modified in other module by reference.
  foreach (module_implements('wikicompare_cache_compared_fields') as $module) {
    $function = $module . '_wikicompare_cache_compared_fields';
    $function($fields, $node);
  }

  db_insert('cache_compared')
    ->fields($fields)
    ->execute();

  // Find all feature node. We don't use cache table because node is more reliable for such important task and there is no performance problem here.
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('fp', 'feature_parent_feature_target_id', 'parent_id');
  $query->leftjoin('field_revision_feature_parent_feature', 'fp', 'n.vid = fp.revision_id');
  $query->condition('n.type', 'feature', '=');
  $result = $query->execute();

  $nids = array();
  foreach ($result as $record) {
    $nids[] = $record;
  }


  $implementation_to_insert = array();
  $to_update = array();
  //Create a new implementation node for each feature node
  foreach ($nids as $feature){
    $node_implementation = new stdClass();
    $node_implementation->type = 'implementation';
    // Add default parameters
    node_object_prepare($node_implementation);
    $node_implementation->language = LANGUAGE_NONE;
    //Filling entity reference field
    $node_implementation->implementation_feature[$node_implementation->language][0]['target_id'] = $feature->nid;
    $node_implementation->implementation_feature[$node_implementation->language][0]['target_type'] = "node";
    $node_implementation->implementation_compared[$node_implementation->language][0]['target_id'] = $node->nid;
    $node_implementation->implementation_compared[$node_implementation->language][0]['target_type'] = "node";

    //Allow others modules to modify the implrmentation to insert
    foreach (module_implements('wikicompare_insert_implementation') as $module) {
      $function = $module . '_wikicompare_insert_implementation';
      $function($node_implementation);
    }

    //Save the implementation node in database
    node_save($node_implementation);

    //Prepare to add the implementation in cache table
    $cache_implementation = array(
      'nid' => $node_implementation->nid,
      'vid' => $node_implementation->vid,
      'feature_id' => $node_implementation->implementation_feature['und'][0]['target_id'],
      'compared_id' => $node_implementation->implementation_compared['und'][0]['target_id'],
      'support' => 0,
    );

    //Allow others modules to modify the cache implrmentation to insert
    foreach (module_implements('wikicompare_cache_implementation_fields') as $module) {
      $function = $module . '_wikicompare_cache_implementation_fields';
      $function($cache_implementation, $node_implementation);
    }


    $cache_implementations[] = $cache_implementation;

  }

  //If some fields for implementation cache are defined in other module, then we need to modify the header before the mass insert
  $header = array('nid', 'vid', 'feature_id', 'compared_id', 'support');
  foreach (module_implements('wikicompare_cache_implementation_fields_header') as $module) {
    $function = $module . '_wikicompare_cache_implementation_fields_header';
    $function($header);
  }

  //Update the cache_implementation table before the compare tree computation
  if (!empty($cache_implementation)) {
    $query = db_insert('cache_implementation')->fields($header);
    foreach ($cache_implementations as $record) {
      $query->values($record);
    }
    $query->execute();
  }

  //Update the compare tree with the new data
  wikicompare_update_compare_tree('compared', array($node->nid));

}

/**
 * Implements hook_delete().
 * Executed each time a node is deleted.
 * We'll use this hook to delete all the implementation linked to the feature, and force an update on implementation parent on feature axis
 */
function feature_delete($node) {


  /*
   * Delete all implementation linked to the feature
   */

  // Find all implementation node. We can use field_data* field because this field should not be modified so nor have revision. We don't use the cache table because field_data is more reliable.
  $query = db_select('field_data_implementation_feature', 'f');
  $query->addField('f', 'entity_id', 'entity_id');
  $query->condition('f.implementation_feature_target_id', $node->nid, '=');
  $result = $query->execute();

  $nids = array();
  foreach ($result as $record) {
    $nids[] = $record->entity_id;
  }

  // Delete all implementation found
  node_delete_multiple($nids);

  //Delete them in the implementation cache
  if (!empty($nids)) {
    db_delete('cache_comparative_table')
      ->condition('nid', $nids, 'in')
      ->execute();

    db_delete('cache_implementation')
      ->condition('nid', $nids, 'in')
      ->execute();
  }

  //Delete the feature in the feature cache
  db_delete('cache_feature')
    ->condition('nid', $node->nid)
    ->execute();

  //Update cache so all children feature are now without parent
  db_update('cache_feature')
    ->fields(array(
      'parent_feature_id' => NULL,
    ))
    ->condition('parent_feature_id', $node->nid)
    ->execute();

  if (isset($node->feature_parent_feature['und'][0])) {
    $query = db_select('cache_feature', 'f');
    $query->addField('f', 'nid', 'nid');
    $query->condition('f.parent_feature_id', $node->feature_parent_feature['und'][0], '=');
    $result = $query->execute();

    $childs = array();
    foreach ($result as $record) {
      $childs[$record->nid] = $record->nid;
    }

    //If the parent feature has no children anymore, we update his children flag
    if (empty($childs)) {
      db_update('cache_feature')
        ->fields(array(
          'has_children' => 0,
        ))
        ->condition('nid', $node->feature_parent_feature['und'][0])
        ->execute();
    }


    //Update the compare tree
    wikicompare_update_compare_tree('feature', array($node->feature_parent_feature['und'][0]['target_id']));
  }

}

/**
 * Implements hook_delete().
 * Executed each time a node is deleted.
 * We'll use this hook to delete all the implementation linked to the compared, and force an update on implementation parent on compared axe
 */
function compared_delete($node) {


  /*
   * Delete all implementation linked to the compared
   */

  // Find all implementation node. We can use field_data* field because this field should not be modified so nor have revision. We don't use cache table because field_data* is more reliable.
  $query = db_select('field_data_implementation_compared', 'c');
  $query->addField('c', 'entity_id', 'entity_id');
  $query->condition('c.implementation_compared_target_id', $node->nid, '=');
  $result = $query->execute();

  $nids = array();
  foreach ($result as $record) {
    $nids[] = $record->entity_id;
  }

  // Delete all implementation found
  node_delete_multiple($nids);

  //Delete them in the implementation cache
  if (!empty($nids)) {
    db_delete('cache_comparative_table')
      ->condition('nid', $nids, 'in')
      ->execute();

    db_delete('cache_implementation')
      ->condition('nid', $nids, 'in')
      ->execute();
  }

  //Delete the compared in the compared cache
  db_delete('cache_compared')
    ->condition('nid', $node->nid)
    ->execute();

  //Update cache so all children feature are now without parent
  db_update('cache_compared')
    ->fields(array(
      'parent_compared_id' => NULL,
    ))
    ->condition('parent_compared_id', $node->nid)
    ->execute();

  //Hook to trigger action from other modules
  foreach (module_implements('wikicompare_cache_compared_delete') as $module) {
    $function = $module . '_wikicompare_cache_compared_delete';
    $function($node);
  }

  if (isset($node->compared_parent_compared['und'][0])) {

    $query = db_select('cache_compared', 'c');
    $query->addField('c', 'nid', 'nid');
    $query->condition('c.parent_compared_id', $node->compared_parent_compared['und'][0], '=');
    $result = $query->execute();

    $childs = array();
    foreach ($result as $record) {
      $childs[$record->nid] = $record->nid;
    }

    //If the parent compared has no children anymore, we update his children flag
    if (empty($childs)) {
      db_update('cache_compared')
        ->fields(array(
          'has_children' => 0,
        ))
        ->condition('nid', $node->compared_parent_compared['und'][0])
        ->execute();
    }


    //Update the compare tree
    wikicompare_update_compare_tree('compared', array($node->compared_parent_compared['und'][0]['target_id']));
  }

}

/**
 * Implements hook_revisionapi() provided by revisionning module
 * Executed two time when a node is published, before and after the publishing
 * We'll use this hook to update the compare tree when some value is changed in feature, compared of implementation note
 */
function wikicompare_revisionapi($op, $node_revision) {

  /*
   * Action to do before a node is published
   */
  if ($op == 'pre publish') {

    /*
     * If the node changed is a feature node
     */
    if ($node_revision->type == 'feature') {

      //$node_revision contain the new value, with this load we recover the old value. This way we will be able to know which value was changed, and so know what to do. If a feature node is updated but no critical value is changed, then no update on the compare tree will be done.
      $current_node = node_load($node_revision->nid);


      if ($node_revision->feature_parent_feature) {
        $node_revision_parent = $node_revision->feature_parent_feature['und'][0]['target_id'];
      } else {
        $node_revision_parent = NULL;
      }

      if ($current_node->feature_parent_feature) {
        $current_node_parent = $current_node->feature_parent_feature['und'][0]['target_id'];
      } else {
        $current_node_parent = NULL;
      }

      //If any of the critical field is changed
      if (($node_revision->feature_type['und'][0]['value'] != $current_node->feature_type['und'][0]['value']) || ($node_revision->feature_weight['und'][0]['value'] != $current_node->feature_weight['und'][0]['value']) || ($node_revision->feature_state['und'][0]['value'] != $current_node->feature_state['und'][0]['value']) || ($node_revision_parent != $current_node_parent)) {

        //We mark the feature for update
        db_update('cache_feature')
          ->fields(array(
            'to_update' => 1,
          ))
          ->condition('nid', $node_revision->nid, '=')
          ->execute();

        //If the field parent of the feature was changed, then this is a big part of the compare tree which was changed. We will have to update the previous implementation parent on the feature axis after the leave of the feature child
        if ($node_revision_parent != $current_node_parent) {

          //Updating the has_children in parent feature.

          //Making sure that the parent know it has children
          if ($node_revision_parent != NULL) {
            db_update('cache_feature')
              ->fields(array(
                'has_children' => 1,
              ))
              ->condition('nid', $node_revision_parent)
              ->execute();
          }

          //If the old parent feature has no children anymore, we update his children flag
          if ($current_node_parent != NULL) {
            $query = db_select('cache_feature', 'f');
            $query->addField('f', 'nid', 'nid');
            $query->condition('f.parent_feature_id', $current_node_parent, '=');
            $result = $query->execute();
            $childs = array();
            foreach ($result as $record) {
              if ($node_revision->nid != $record->nid) {
                $childs[$record->nid] = $record->nid;
              }
            }
            if (empty($childs)) {
              db_update('cache_feature')
                ->fields(array(
                  'has_children' => 0,
                ))
                ->condition('nid', $current_node_parent)
                ->execute();
            }
          }
        
          //We mark the old parent and the new parent of the feature for update
          db_update('cache_feature')
            ->fields(array(
              'to_update' => 1,
            ))
            ->condition('nid', array($node_revision_parent, $current_node_parent), 'IN')
            ->execute();

        }
      }
    }

    /*
     * If the node changed is a compared node
     */
    if ($node_revision->type == 'compared') {

      //$node_revision contain the new value, with this load we recover the old value. This way we will be able to know which value was changed, and so know what to do. If a compared node is updated but no critical value is changed, then no update on the compare tree will be done.
      $current_node = node_load($node_revision->nid);

      if ($node_revision->compared_parent_compared) {
        $node_revision_parent = $node_revision->compared_parent_compared['und'][0]['target_id'];
      } else {
        $node_revision_parent = NULL;
      }

      if ($current_node->compared_parent_compared) {
        $current_node_parent = $current_node->compared_parent_compared['und'][0]['target_id'];
      } else {
        $current_node_parent = NULL;
      }

      //If the field parent of the feature was changed, then this is a big part of the compare tree which was changed. We will have to update the previous implementation parent on the feature axis after the leave of the compared child.
      if ($node_revision_parent != $current_node_parent) {

        //Updating the has_children in parent compared.

        //Making sure that the parent know it has children
        if ($node_revision_parent != NULL) {
          db_update('cache_compared')
            ->fields(array(
              'has_children' => 1,
            ))
            ->condition('nid', $node_revision_parent)
            ->execute();
        }

        //If the old parent compared has no children anymore, we update his children flag
        if ($current_node_parent != NULL) {
          $query = db_select('cache_compared', 'c');
          $query->addField('c', 'nid', 'nid');
          $query->condition('c.parent_compared_id', $current_node_parent, '=');
          $result = $query->execute();
          $childs = array();
          foreach ($result as $record) {
            if ($node_revision->nid != $record->nid) {
              $childs[$record->nid] = $record->nid;
            }
          }
          if (empty($childs)) {
            db_update('cache_compared')
              ->fields(array(
                'has_children' => 0,
              ))
              ->condition('nid', $current_node_parent)
              ->execute();
          }
        }


        //We mark the updated compared, his old parent and his new parent for update
        db_update('cache_compared')
          ->fields(array(
            'to_update' => 1,
          ))
          ->condition('nid', array($node_revision->nid, $node_revision_parent, $current_node_parent) , 'IN')
          ->execute();

      }

      //Allow others modules to make check and mark to update following other fields in the compared. We unfortunately can't directly use invoke_all with reference, so we use this workaround. Will maybe be corrected in Drupal 8. 
      foreach (module_implements('wikicompare_preupdate_compared') as $module) {
        $function = $module . '_wikicompare_preupdate_compared';
        $function($node_revision, $current_node);
      }

    }

    /*
     * If the node changed is a implementation node
     */
    if ($node_revision->type == 'implementation') {

      //$node_revision contain the new value, with this load we recover the old value. This way we will be able to know which value was changed, and so know what to do. If a feature node is updated but no critical value is changed, then no update on the compare tree will be done.
      $current_node = node_load($node_revision->nid);

      //If the only critical value of a implementation node, the support value, changed, then we will mark this implementation for update
      if ($node_revision->implementation_support['und'][0]['value'] != $current_node->implementation_support['und'][0]['value']) {

          //Mark the implementation for update
          db_update('cache_implementation')
            ->fields(array(
              'to_update' => 1,
            ))
            ->condition('nid', $node_revision->nid, '=')
            ->execute();

      }

      //Allow others modules to make check and mark to update following other fields in the compared. We unfortunately can't directly use invoke_all with reference, so we use this workaround. Will maybe be corrected in Drupal 8. 
      foreach (module_implements('wikicompare_preupdate_implementation') as $module) {
        $function = $module . '_wikicompare_preupdate_implementation';
        $function($node_revision, $current_node);
      }


    }
  }

  /*
   * Action to do after a node is published
   */
  if ($op == 'post publish') {

    //Update the cache tables with the new values
    if ($node_revision->type == 'feature') {
        $feature_parent_feature = NULL;
        if (isset($node_revision->feature_parent_feature['und'][0])) {
          $feature_parent_feature = $node_revision->feature_parent_feature['und'][0]['target_id'];
        }
        db_update('cache_feature')
            ->fields(array(
              'vid' => $node_revision->vid,
              'title' => $node_revision->title,
              'parent_feature_id' => $feature_parent_feature,
              'type' => $node_revision->feature_type['und'][0]['value'],
              'weight' => $node_revision->feature_weight['und'][0]['value'],
              'state' => $node_revision->feature_state['und'][0]['value'],
            ))
            ->condition('nid', $node_revision->nid)
            ->execute();
    }

    if ($node_revision->type == 'compared') {
        $compared_parent_compared = NULL;
        if (isset($node_revision->compared_parent_compared['und'][0])) {
          $compared_parent_compared = $node_revision->compared_parent_compared['und'][0]['target_id'];
        }

        $fields = array(
          'vid' => $node_revision->vid,
          'title' => $node_revision->title,
          'parent_compared_id' => $compared_parent_compared,
        );

        //Update other fields from others modules
        foreach (module_implements('wikicompare_cache_compared_fields') as $module) {
          $function = $module . '_wikicompare_cache_compared_fields';
          $function($fields, $node_revision);
        }

        db_update('cache_compared')
            ->fields($fields)
            ->condition('nid', $node_revision->nid)
            ->execute();
    }

    if ($node_revision->type == 'implementation') {

      $fields = array(
        'vid' => $node_revision->vid,
        'support' => $node_revision->implementation_support['und'][0]['value'],
      );

      //Update other fields from others modules
      foreach (module_implements('wikicompare_cache_implementation_fields') as $module) {
        $function = $module . '_wikicompare_cache_implementation_fields';
        $function($fields, $node_revision);
      }

      db_update('cache_implementation')
          ->fields($fields)
          ->condition('nid', $node_revision->nid)
          ->execute();
    }

    //Get all the feature to update
    $query = db_select('cache_feature', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->condition('n.to_update', 1, '=');
    $result = $query->execute();

    $feature_nids = array();
    foreach($result as $item) {
      $feature_nids[$item->nid] = $item->nid;
    }
    //Update all the feature marked. We force the update of the parent because in case of an update thanks to a parent feature change, the implementation percent may not have change but we still need to update their parent.
    if ($feature_nids) {
      wikicompare_update_compare_tree('feature', $feature_nids);
    }

    //Get all the compared to update
    $query = db_select('cache_compared', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->condition('n.to_update', 1, '=');
    $result = $query->execute();

    $compared_nids = array();
    foreach($result as $item) {
      $compared_nids[$item->nid] = $item->nid;
    }

    //Update all the compared marked. We force the update of the parent because in case of an update thanks to a parent compared change, the implementation percent may not have change but we still need to update their parent.
    if ($compared_nids) {
      wikicompare_update_compare_tree('compared', $compared_nids);
    }

    //Get all the implementation to update
    $query = db_select('cache_implementation', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->condition('n.to_update', 1, '=');
    $result = $query->execute();

    $implementation_nids = array();
    foreach($result as $item) {
      $implementation_nids[$item->nid] = $item->nid;
    }

    //Update all the implementation marked. We force the update of the parent because in case of an update thanks to a parent feature or compared change, the implementation percent may not have change but we still need to update their parent.
    if ($implementation_nids) {
      wikicompare_update_compare_tree('implementation', $implementation_nids);
    }

    //Remove all update marks
    if (!empty($feature_nids)) {
      db_update('cache_feature')
        ->fields(array(
          'to_update' => 0,
        ))
        ->condition('nid', $feature_nids, 'IN')
        ->execute();
    }

    if (!empty($compared_nids)) {
      db_update('cache_compared')
        ->fields(array(
          'to_update' => 0,
        ))
        ->condition('nid', $compared_nids, 'IN')
        ->execute();
    }

    if (!empty($implementation_nids)) {
      db_update('cache_implementation')
        ->fields(array(
          'to_update' => 0,
        ))
        ->condition('nid', $implementation_nids, 'IN')
        ->execute();
    }

  }
}

?>
