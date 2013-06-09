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




  wikicompare_insert_node('feature', $node);


  

}

/**
 * Implements hook_insert().
 * Executed each time a compared node is created.
 * When a new compared is created, we also create all the implementation needed, so one for each feature to cross with the compared created
 */
function compared_insert($node) {


dpm($node);
  wikicompare_insert_node('compared', $node);
}


function wikicompare_insert_node($type, $node) {

  if ($node->language != language_default('language')) {
    return;
  }

  $countertype = '';
  if ($type == 'compared') {
    $countertype = 'feature';
  } elseif ($type == 'feature') {
    $countertype = 'compared';
  }

  /*
   * Create a new implementation for all countertype node
   */

  //Create the new record in the cache table
  $parent_id = NULL;
  if (isset($node->wikicompare_parent_id['und'][0])) {
    $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];
    //Making sure that the parent know it has children
    db_update('cache_' . $type)
      ->fields(array(
        'has_children' => 1,
      ))
      ->condition('nid', $parent_id)
      ->execute();

    wikicompare_update_cache_users($node->nid, $parent_id, $type, $node->vid);

  }

  $fields = array(
      'nid' => $node->nid,
      'vid' => $node->vid,
      'title' => $node->title,
      'parent_id' => $parent_id,
      'sequence' => $node->wikicompare_sequence['und'][0]['value'],
      'state' => $node->wikicompare_state['und'][0]['value'],
      'has_children' => 0,
  );

  if ($type == 'feature') {
    $fields['type'] = $node->wikicompare_type['und'][0]['value'];
    $fields['weight'] = $node->wikicompare_weight['und'][0]['value'];
  }


  if (module_exists('wikicompare_inherit_compared')) {
    wikicompare_inherit_compared_cache_insert_fields($fields, $type, $node);
  }

  db_insert('cache_' . $type)
    ->fields($fields)
    ->execute();


  if (in_array($type, array('compared', 'feature'))) {
    // Find all countertype node. We don't use cache table because node is more reliable for such important task and there is no performance problem here.
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('fp', 'wikicompare_parent_id_target_id', 'parent_id');
    $query->leftjoin('field_revision_wikicompare_parent_id', 'fp', 'n.vid = fp.revision_id');
    $query->condition('n.type', $countertype);
    $query->condition('n.language', language_default('language'));
    $result = $query->execute();

    $nids = array();
    foreach ($result as $record) {
      $nids[] = $record;
    }


    $implementation_to_insert = array();
    $to_update = array();
    //Create a new implementation node for each countertype node
    foreach ($nids as $counternode){
      $node_implementation = new stdClass();
      $node_implementation->type = 'implementation';
      // Add default parameters
      node_object_prepare($node_implementation);
      $node_implementation->title = 'Implementation';

      $node_implementation->language = language_default('language');
      //Filling entity reference field
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
        wikicompare_inherit_compared_insert_implementation($node_implementation);
      }


      //Save the implementation node in database
      node_save($node_implementation);

      //Prepare to add the implementation in cache table
      $cache_implementation = array(
        'nid' => $node_implementation->nid,
        'vid' => $node_implementation->vid,
        'feature_id' => $node_implementation->wikicompare_feature_id['und'][0]['target_id'],
        'compared_id' => $node_implementation->wikicompare_compared_id['und'][0]['target_id'],
        'support' => 0,
      );

      if (module_exists('wikicompare_inherit_compared')) {
        wikicompare_inherit_compared_cache_implementation_fields($cache_implementation, $node_implementation);
      }

      $cache_implementations[] = $cache_implementation;
    

    }

    //If some fields for implementation cache are defined in other module, then we need to modify the header before the mass insert
    $header = array('nid', 'vid', 'feature_id', 'compared_id', 'support');

    if (module_exists('wikicompare_inherit_compared')) {
      wikicompare_inherit_compared_cache_fields_header($header, 'implementation');
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
    wikicompare_update_compare_tree($type, array($node->nid));
  }

}




/**
 * Implements hook_delete().
 * Executed each time a node is deleted.
 * We'll use this hook to delete all the implementation linked to the feature, and force an update on implementation parent on feature axis
 */
function feature_delete($node) {

  wikicompare_delete_node('feature', $node);


}

/**
 * Implements hook_delete().
 * Executed each time a node is deleted.
 * We'll use this hook to delete all the implementation linked to the compared, and force an update on implementation parent on compared axe
 */
function compared_delete($node) {

  wikicompare_delete_node('compared', $node);
}

function implementation_delete($node) {


  if (module_exists('wikicompare_translation')) {
    wikicompare_translation_wikicompare_delete_after($node);
  } 

}

function wikicompare_delete_node($type, $node) {

  /*
   * Delete all implementation linked to the node
   */

  if ($node->language != language_default('language')) {
    return;
  }

  wikicompare_update_cache_users($node->nid);

  if (in_array($type, array('compared', 'feature'))) {
    // Find all implementation node. We can use field_data* field because this field should not be modified so nor have revision. We don't use cache table because field_data* is more reliable.
    $query = db_select('field_data_wikicompare_' . $type . '_id', 'c');
    $query->addField('c', 'entity_id', 'entity_id');
    $query->condition('c.wikicompare_' . $type . '_id_target_id', $node->nid, '=');
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
  }

  //Delete the compared in the compared cache
  db_delete('cache_' . $type)
    ->condition('nid', $node->nid)
    ->execute();

  //Update cache so all children feature are now without parent
  db_update('cache_' . $type)
    ->fields(array(
      'parent_id' => NULL,
    ))
    ->condition('parent_id', $node->nid)
    ->execute();



  if (module_exists('wikicompare_inherit_compared')) {
    wikicompare_inherit_compared_cache_compared_delete($node);
  }

  if (isset($node->wikicompare_parent_id['und'][0])) {

    $query = db_select('cache_' . $type, 'c');
    $query->addField('c', 'nid', 'nid');
    $query->condition('c.parent_id', $node->wikicompare_parent_id['und'][0], '=');
    $result = $query->execute();

    $childs = array();
    foreach ($result as $record) {
      $childs[$record->nid] = $record->nid;
    }

    //If the parent has no children anymore, we update his children flag
    if (empty($childs)) {
      db_update('cache_' . $type)
        ->fields(array(
          'has_children' => 0,
        ))
        ->condition('nid', $node->wikicompare_parent_id['und'][0])
        ->execute();
    }

    if (in_array($type, array('compared', 'feature'))) {
      //Update the compare tree
      wikicompare_update_compare_tree($type, array($node->wikicompare_parent_id['und'][0]['target_id']));
    }
  }


  if (module_exists('wikicompare_translation')) {
    wikicompare_translation_wikicompare_delete_after($node);
  } 

}


/**
 * Implements hook_revisionapi() provided by revisionning module
 * Executed two time when a node is published, before and after the publishing
 * We'll use this hook to update the compare tree when some value is changed in feature, compared of implementation note
 */
function wikicompare_revisionapi($op, $node_revision) {



  if ($node_revision->language != language_default('language')) {
    return;
  }

  /*
   * Action to do before a node is published
   */
  if ($op == 'pre publish') {



    $types = array('compared', 'feature', 'implementation');


    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_wikicompare_node_types($types);
    }

    if (in_array($node_revision->type, $types)) {

      $test = false;

      $to_update = array($node_revision->nid);


      //$node_revision contain the new value, with this load we recover the old value. This way we will be able to know which value was changed, and so know what to do. If a compared node is updated but no critical value is changed, then no update on the compare tree will be done.
      $current_node = node_load($node_revision->nid);


      $types = array('compared', 'feature');


      if (module_exists('wikicompare_needs')) {
        wikicompare_needs_wikicompare_node_types($types);
      }

      if (in_array($node_revision->type, $types)) {

        $node_revision_parent = NULL;
        $current_node_parent = NULL;

        if ($node_revision->wikicompare_parent_id) {
          $node_revision_parent = $node_revision->wikicompare_parent_id['und'][0]['target_id'];
        }

        if ($current_node->wikicompare_parent_id) {
          $current_node_parent = $current_node->wikicompare_parent_id['und'][0]['target_id'];
        }
      
     

        //If the field parent of the node was changed, then this is a big part of the compare tree which was changed. We will have to update the previous implementation parent on the countertype axis after the leave of the node child.
        if ($node_revision_parent != $current_node_parent) {

          //Updating the has_children in parent node.
  
          //Making sure that the parent know it has children
          if ($node_revision_parent != NULL) {
            db_update('cache_' . $node_revision->type)
              ->fields(array(
                'has_children' => 1,
              ))
              ->condition('nid', $node_revision_parent)
              ->execute();
          }

          //If the old parent has no children anymore, we update his children flag
          if ($current_node_parent != NULL) {
            $query = db_select('cache_' . $node_revision->type, 'c');
            $query->addField('c', 'nid', 'nid');
            $query->condition('c.parent_id', $current_node_parent, '=');
            $result = $query->execute();
            $childs = array();
            foreach ($result as $record) {
              if ($node_revision->nid != $record->nid) {
                $childs[$record->nid] = $record->nid;
              }
            }
            if (empty($childs)) {
              db_update('cache_' . $node_revision->type)
                ->fields(array(
                  'has_children' => 0,
                ))
                ->condition('nid', $current_node_parent)
                ->execute();
            }
          }

          $to_update[] = $node_revision_parent;
          $to_update[] = $current_node_parent;

          $test = true;
        }
      }

      if ($node_revision->type == 'compared') {
        //Allow others modules to make check and mark to update following other fields in the compared. We unfortunately can't directly use invoke_all with reference, so we use this workaround. Will maybe be corrected in Drupal 8. 

        if (module_exists('wikicompare_inherit_compared')) {
          wikicompare_inherit_compared_preupdate_compared($test, $node_revision, $current_node);
        }

      }


      if ($node_revision->type == 'feature') {
        if (($node_revision->wikicompare_type['und'][0]['value'] != $current_node->wikicompare_type['und'][0]['value']) || ($node_revision->wikicompare_weight['und'][0]['value'] != $current_node->wikicompare_weight['und'][0]['value']) || ($node_revision->wikicompare_state['und'][0]['value'] != $current_node->wikicompare_state['und'][0]['value'])) {
          $test = true;
        }
      }

      if ($node_revision->type == 'implementation') {
        if ($node_revision->wikicompare_support['und'][0]['value'] != $current_node->wikicompare_support['und'][0]['value']) {
          $test = true;
        }

        if (module_exists('wikicompare_inherit_compared')) {
          wikicompare_inherit_compared_preupdate_implementation($test, $node_revision, $current_node);
        }

      }

      //If any of the critical field is changed
      if ($test) {



        
        if (in_array($node_revision->type, array('compared', 'feature', 'implementation'))) {
          //We mark the updated node, his old parent and his new parent for update
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

    $types = array('compared', 'feature', 'implementation');


    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_wikicompare_node_types($types);
    }
    if (in_array($node_revision->type, $types)) {


      $fields = array(
        'vid' => $node_revision->vid,
      );

      if ($node_revision->type != 'implementation') {
        $fields['title'] = $node_revision->title;
        $parent_id = NULL;


        if (isset($node_revision->wikicompare_parent_id['und'][0])) {
          $parent_id = $node_revision->wikicompare_parent_id['und'][0]['target_id'];
        }
        $fields['parent_id'] = $parent_id;
        $fields['sequence'] = $node_revision->wikicompare_sequence['und'][0]['value'];
        $fields['state'] = $node_revision->wikicompare_state['und'][0]['value'];

        wikicompare_update_cache_users($node_revision->nid, $parent_id, $node_revision->type, $node_revision->vid);

      } else {
        $fields['support']= $node_revision->wikicompare_support['und'][0]['value'];

        //Update other fields from others modules
        foreach (module_implements('wikicompare_cache_implementation_fields') as $module) {
          $function = $module . '_wikicompare_cache_implementation_fields';
          $function($fields, $node_revision);
        }

      }

      if ($node_revision->type == 'feature') {
        $fields['type'] = $node_revision->wikicompare_type['und'][0]['value'];
        $fields['weight'] = $node_revision->wikicompare_weight['und'][0]['value'];
      }


      if (module_exists('wikicompare_needs')) {
        wikicompare_needs_wikicompare_cache_update_fields($fields, $node_revision);
      }

      if (module_exists('wikicompare_inherit_compared')) {
        wikicompare_inherit_compared_cache_update_fields($fields, $node_revision);
      }



      db_update('cache_' . $node_revision->type)
          ->fields($fields)
          ->condition('nid', $node_revision->nid)
          ->execute();

    }

    $types = array('compared', 'feature', 'implementation');

    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_wikicompare_node_types($types);
    }


    foreach($types as $type) {
      //Get all the node to update
      $query = db_select('cache_' . $type, 'n');
      $query->addField('n', 'nid', 'nid');
      $query->condition('n.to_update', 1, '=');
      $result = $query->execute();

      $node_nids = array();
      foreach($result as $item) {
        $node_nids[$item->nid] = $item->nid;
      }
      //Update all the feature marked. We force the update of the parent because in case of an update thanks to a parent feature change, the implementation percent may not have change but we still need to update their parent.
      if ($node_nids) {
        wikicompare_update_compare_tree($type, $node_nids);
        db_update('cache_' . $type) 
          ->fields(array(
            'to_update' => 0,
          ))
          ->condition('nid', $node_nids, 'IN')
          ->execute();
      }

    }


    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_wikicompare_cache_after_update_fields($fields, $node_revision);
    }

  }
}

function wikicompare_update_cache_users($nid, $parent_id=NULL, $type=NULL, $vid=NULL) {


  db_delete('field_data_wikicompare_user_from_parent_ids')
    ->condition('entity_id', $nid)
    ->execute();

  db_delete('field_revision_wikicompare_user_from_parent_ids')
    ->condition('entity_id', $nid)
    ->execute();

  if ($parent_id != NULL) {

    $users = wikicompare_test_access_node('get_users', $parent_id);



    if (!empty($users)) {

      foreach ($users as $key => $user) {
        $users[$key]['bundle'] = $type;
        $users[$key]['entity_id'] = $nid;
        $users[$key]['revision_id'] = $vid;
      }


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

  
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'vid', 'vid');
  $query->leftjoin('field_revision_wikicompare_parent_id', 'f', 'n.vid = f.revision_id');
  $query->condition('f.wikicompare_parent_id_target_id', $nid);
  $result = $query->execute();
  foreach ($result as $record) {
    wikicompare_update_cache_users($record->nid, $nid, $type, $record->vid);
  } 



}

?>
