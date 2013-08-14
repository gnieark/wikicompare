<?php

/**
 * @file
 * Define the main functions, like the recursive function which update the compare tree, the one which refresh the cache and the generic request db function.
 */

require_once drupal_get_path('module', 'wikicompare') . '/wikicompare.module';



/**
 * The main function to update the percent and css_class for each evaluation
 * It'll find all children on compared and feature axis for the ids passed in argument, compute the percent thanks to theses informations and feature type, and finally if the percent changed it'll update the parents on feature and compared axis.
 * This is a recursive function, which will call itself on parent if the percent computed change in both the feature and compared axis.
 *
 * @param $type
 *   The type of the node to update. Only the evaluation are updated at the end, but specifying compared or feature allow to directly update all their evaluations.
 *
 * @param $nids
 *   The nids of the nodes to update.
 *
 * @return array
 *   An array containing the evaluations updated by the function.
 */
function wikicompare_update_compare_tree($type, $nids) {

  if (!variable_get('wikicompare_computation_status', 1)) {
    return;
  }

  $nodes = array();
  if (!empty($nids)) {

    //Recover the details of the targeted evaluations.
    $query = db_select('cache_evaluation', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'feature_id', 'fid');
    $query->addField('n', 'compared_id', 'cid');
    $query->addField('n', 'support', 'support');
    $query->addField('n', 'feature_type', 'type');
    $query->addField('n', 'percent', 'old_percent');
    $query->addField('n', 'css_class', 'old_css_class');
    $query->addField('n', 'parent_through_compared_id', 'parent_through_compared_id');
    $query->addField('n', 'parent_through_feature_id', 'parent_through_feature_id');

    //If possible, we search directly through feature or compared id to compute the sql request faster.
    switch ($type) {
      case "evaluation":
        $query->condition('n.nid', $nids, 'IN');
        break;
      case "feature":
        $query->condition('n.compared_has_children', 0); //Only the evaluation without children on compared axis need to be updated, because they will update their parent on compared axis anyway.
        $query->condition('n.feature_id', $nids, 'IN');
        break;
      case "compared":
        $query->condition('n.feature_has_children', 0); //Only the evaluation without children on feature axis need to be updated, because they will update their parent on feature axis anyway.
        $query->condition('n.compared_id', $nids, 'IN');
        break;
    }

    if (module_exists('wikicompare_inherit_compared')) {
      //Add the requests to recover the inherited evaluation.
      wikicompare_inherit_compared_update_main_query($query);
    }

    $result = $query->execute();

    //Build the variables needed for later computations.
    foreach($result as $record) {
      //Using $record->nid as key allow deduplication of the id in argument array.
      $nodes[$record->nid] = $record;
    }

    //Get the children on feature axis.
    $through_feature_childs = array();
    //We don't need the children through feature axis in case of type = 'compared'.
    if ($type != 'compared') {
      //Get children evaluation through feature axis
      $query = db_select('cache_evaluation', 'n');
      $query->addField('n', 'nid', 'nid');
      $query->addField('n', 'feature_id', 'fid');
      $query->addField('n', 'compared_id', 'cid');
      $query->addField('n','feature_parent_id', 'parent_fid');
      $query->addField('n', 'percent', 'percent');
      $query->addField('n', 'feature_weight', 'weight');
      switch ($type) {
        case "evaluation":
          //We keep only the evaluation of the child feature node which has the same compared than the evaluation. Which mean it's the children evaluation on the feature axis.
          $query->condition('parent_through_feature_id', $nids, 'IN');
          break;
        case "feature":
          $query->condition('n.feature_parent_id', $nids, 'IN');
          break;
      }

      //Only published features are used in their parent computation.
      $query->condition('n.feature_state', unserialize(WIKICOMPARE_STATE_PUBLISHED), 'in');
      $result = $query->execute();

      //We assign the children evaluation in a array with fid and cid as key so their parents can recover them with fid and cid key.
      $through_feature_childs = array();
      foreach($result as $record) {
        $through_feature_childs[$record->parent_fid][$record->cid][$record->nid] = $record;
      }
    }

    //Get the children on feature axis.
    $through_compared_childs = array();
    //We don't need the children through compared child in case of type = 'feature'.
    if ($type != 'feature') {
      //Get children evaluation through feature axis.
      $query = db_select('cache_evaluation', 'n');
      $query->addField('n', 'nid', 'nid');
      $query->addField('n', 'feature_id', 'fid');
      $query->addField('n', 'compared_id', 'cid');
      $query->addField('n','compared_parent_id', 'parent_cid');
      $query->addField('n', 'percent', 'percent');
      $query->addField('n', 'css_class', 'css_class');

      switch ($type) {
        case "evaluation":
          //We keep only the evaluation of the child compared node which has the same feature than the evaluation. Which mean it's the children evaluation on the compared axis.
          $query->condition('parent_through_compared_id', $nids, 'IN');
          break;
        case "compared":
          $query->condition('n.compared_parent_id', $nids, 'IN');
          break;
      }

      //Only published compareds are used in their parent computation.
      $query->condition('n.compared_state', unserialize(WIKICOMPARE_STATE_PUBLISHED), 'in');
      $result = $query->execute();

      //We assign the children evaluation in a array with fid and cid as key so they parent can recover them with fid and cid key
      $through_compared_childs = array();
      foreach($result as $record) {
        $through_compared_childs[$record->parent_cid][$record->fid][$record->nid] = $record;
      }
    }

    //Assign children to each node to compute.
    foreach($nodes as $node) {
      $node->through_feature_childs = array();
      if (isset($through_feature_childs[$node->fid][$node->cid])) {
        //Assign the children thanks to fid and cid key.
        $node->through_feature_childs = $through_feature_childs[$node->fid][$node->cid];
      }
      $node->through_compared_childs = array();
      if (isset($through_compared_childs[$node->cid][$node->fid])) {
        //Assign the children thanks to fid and cid key.
        $node->through_compared_childs = $through_compared_childs[$node->cid][$node->fid];
      }
    }

    if (module_exists('wikicompare_inherit_compared')) {
      //Compute the inherited evaluation if not already done, and get inheriting children.
      wikicompare_inherit_compared_update_comparative_table_preparation($nodes, $type, $nids);
    }

  }



  /*
   * Now we'll compute the percent and css_class of each nids in function argument.
   */
  $to_update = array();
  $cache_to_update = array();
  $res = array();
  $update_compared_flag = variable_get('wikicompare_update_compared', 'no-update');
  foreach($nodes as $node) {

    //We update only if the update parent isn't set and there is no children on compared axis.
    if (($update_compared_flag == 'no-update') && !empty($node->through_compared_childs)) {
      continue;
    }

    //If any misconfiguration, it'll always return 0.
    $node->new_percent = 0;
    $node->new_css_class = 'cell-support-no';

    //The support field is used only if the evaluation is the deepest in the tree, on both the feature and compared axis.
    if (empty($node->through_feature_childs) && empty($node->through_compared_childs)) {
      if ($node->support == 1) {
        $node->new_percent = 100;
        $node->new_css_class = 'cell-support-complete';
      } else {
        $node->new_percent = 0;
        $node->new_css_class = 'cell-support-no';
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Return the data computed according to the inherited evaluation.
        wikicompare_inherit_compared_from_other_support($node);
      }
    //Use the children through feature axis to compute the percent.
    } else {
      $node = wikicompare_compute_percent($node, $node->through_feature_childs);
    }

    //If a children through compared axis is higher than the value computed, then it'll be used instead.
    foreach($node->through_compared_childs as $child) {
      if ($child->percent >= $node->new_percent) {
        $node->new_percent = $child->percent;
        $node->new_css_class = $child->css_class;
      }
    }

    //Update the value computed in database, only if the value has changed.
    if ((($node->old_percent != $node->new_percent) || ($node->old_css_class != $node->new_css_class))) {
        //We regroup all the same percent in a table to update them all at the same time.
      $cache_to_update[$node->new_css_class][$node->new_percent][$node->nid] = $node->nid;

      //Update the parent though feature and compared axis if the value changed.
      if ($node->parent_through_feature_id) {
        $to_update[$node->parent_through_feature_id] = $node->parent_through_feature_id;
      }

      if ($update_compared_flag != 'no-update') {
        if ($node->parent_through_compared_id) {
          $to_update[$node->parent_through_compared_id] = $node->parent_through_compared_id;
        }
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Add in the evaluation to update the evaluation which inherit the current evaluation.
        wikicompare_inherit_compared_update_comparative_table_post($to_update, $node);
      }

    }

    //Fill the res variable the function will return.
    $res[$node->nid]['percent'] = $node->new_percent;
    $res[$node->nid]['css_class'] = $node->new_css_class;

  }

  //Update the percentages. Data are regrouped by css and percent to try to make as few query as possible.
  foreach($cache_to_update as $key_css_class => $css_class) {
    foreach($cache_to_update[$key_css_class] as $key_percent => $percent) {
        db_update('cache_evaluation')
          ->fields(array(
            'percent' => $key_percent,
            'css_class' => $key_css_class,
          ))
          ->condition('nid', $cache_to_update[$key_css_class][$key_percent], 'IN')
          ->execute();
    }
  }

  //Update the parent marked.
  if (!empty($to_update)) {
    wikicompare_update_compare_tree('evaluation', $to_update);
  }

  return $res;

}



/**
 * Function which compute the percent of a node thanks to his settings and his children.
 * This function is called by the main recursive update_compare_tree function, but also by the comparative table if it is computed.
 *
 * @param $node
 *   The object node we need to compute.
 *
 * @param $through_feature_childs
 *   The children of the node.
 *
 * @return $node
 *   The object node completed with the computed value.
 */
function wikicompare_compute_percent($node, $through_feature_childs) {

    if ($node->type == 'parent-weighted-average') {

      $total = 0;
      $count = 0;
      foreach($through_feature_childs as $child) {
        $total += $child->percent * $child->weight;
        $count += $child->weight;
      }

      //Security to avoid the divided by 0
      if ($count == 0) {
        $count = 1;
      }

      //Compute the value. We round the percent to 4 because it's the precision in database.
      $node->new_percent = round(($total / $count),4);

    //If the feature is of type highest percentage, it'll take the maximum value of the children.
    } elseif ($node->type == 'parent-highest-percentage') {
      $node->new_percent = 0;
      $node->new_css_class = 'cell-support-no';
      foreach($through_feature_childs as $child) {

          //Security if weight field is misconfigured.
          if ($child->weight > 100) {
            $child->weight = 100;
          }

          //Compute the value for this children. We round the percent to 4 because it's the precision in database.
          $child_percent = round(($child->percent * $child->weight / 100), 4);
          //If percent for this children is highter, then it'll be the value computed.
          if ($child_percent >= $node->new_percent) {
            $node->new_percent = $child_percent;
          }

      }

      //Find the css class based on the percentage value.
      if ($node->new_percent ==0) {
        $node->new_css_class = 'cell-support-no';
      } elseif (($node->new_percent > 0) && ($node->new_percent < 10)) {
        $node->new_css_class = 'cell-support-partial-0-10';
      } elseif (($node->new_percent >= 10) && ($node->new_percent < 20)) {
        $node->new_css_class = 'cell-support-partial-10-20';
      } elseif (($node->new_percent >= 20) && ($node->new_percent < 30)) {
        $node->new_css_class = 'cell-support-partial-20-30';
      } elseif (($node->new_percent >= 30) && ($node->new_percent < 40)) {
        $node->new_css_class = 'cell-support-partial-30-40';
      } elseif (($node->new_percent >= 40) && ($node->new_percent < 50)) {
        $node->new_css_class = 'cell-support-partial-40-50';
      } elseif (($node->new_percent >= 50) && ($node->new_percent < 60)) {
        $node->new_css_class = 'cell-support-partial-50-60';
      } elseif (($node->new_percent >= 60) && ($node->new_percent < 70)) {
        $node->new_css_class = 'cell-support-partial-60-70';
      } elseif (($node->new_percent >= 70) && ($node->new_percent < 80)) {
        $node->new_css_class = 'cell-support-partial-70-80';
      } elseif (($node->new_percent >= 80) && ($node->new_percent < 90)) {
        $node->new_css_class = 'cell-support-partial-80-90';
      } elseif (($node->new_percent >= 90) && ($node->new_percent < 100)) {
        $node->new_css_class = 'cell-support-partial-90-100';
      } elseif (($node->new_percent == 100)) {
        $node->new_css_class = 'cell-support-complete';
      }
    }

    return $node;
}





/**
 * Function which refresh all wikicompare cache tables. It will truncate the tables and then rebuild them based on the information in tables node and field_revisions_*.
 * We should use it if for any reason some nodes were miscalculated.
 */
function wikicompare_refresh_caches() {

  global $language;

  //We put the site in maintenance, and check if it was already in maintenance to know if we shall reactive the website after the operation.
  $was_in_maintenance = FALSE;
  if (variable_get('maintenance_mode', 0) == 1) {
    $was_in_maintenance = TRUE;
  } else {
    //Activate maintenance mode.
    variable_set('maintenance_mode', 1);
  }

  $types = array('compared', 'feature', 'evaluation');
  if (module_exists('wikicompare_profiles')) {
    //Add profile type.
    wikicompare_profiles_node_types($types);
  }

  foreach ($types as $type) {
    //Delete all data in the type cache.
    db_delete('cache_' . $type)
      ->execute();
  }

  foreach ($types as $type) {

    //Get all data from node and field_revision_* tables.
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'vid', 'vid');
    if ($type != 'evaluation') {
      $query->addField('n', 'title', 'title');
      $query->addField('npf', 'wikicompare_parent_id_target_id', 'parent_id');
      $query->addField('nse', 'wikicompare_sequence_value', 'sequence');
      $query->addField('ns', 'wikicompare_state_value', 'state');
      $query->leftjoin('field_revision_wikicompare_parent_id', 'npf', 'n.vid = npf.revision_id');
      $query->leftjoin('field_revision_wikicompare_sequence', 'nse', 'n.vid = nse.revision_id');
      $query->leftjoin('field_revision_wikicompare_state', 'ns', 'n.vid = ns.revision_id');
    } else {
      $query->addField('nf', 'wikicompare_feature_id_target_id', 'feature_id');
      $query->addField('nc', 'wikicompare_compared_id_target_id', 'compared_id');
      $query->addField('ns', 'wikicompare_support_value', 'support');
      $query->leftjoin('field_revision_wikicompare_feature_id', 'nf', 'n.vid = nf.revision_id');
      $query->leftjoin('field_revision_wikicompare_compared_id', 'nc', 'n.vid = nc.revision_id');
      $query->leftjoin('field_revision_wikicompare_support', 'ns', 'n.vid = ns.revision_id');
    }
    if ($type == 'feature') {
      $query->addField('nt', 'wikicompare_type_value', 'type');
      $query->addField('nw', 'wikicompare_weight_value', 'weight');
      $query->leftjoin('field_revision_wikicompare_type', 'nt', 'n.vid = nt.revision_id');
      $query->leftjoin('field_revision_wikicompare_weight', 'nw', 'n.vid = nw.revision_id');
    }
    $query->condition('n.type', $type);
    //Only the main language nodes are concerned.
    $query->condition('n.language', language_default('language'));
    if (module_exists('wikicompare_inherit_compared')) {
      //Search for the inhehrit compared specific fields in the flush tables function.
      wikicompare_inherit_compared_flush_select($query, $type);
    }
    $result = $query->execute();

    $parent_array = array();
    $to_insert = array();
    $header = array();
    foreach($result as $record) {
      //Insert all record in an array to insert them later.
      $to_insert[$record->nid]['nid'] = $record->nid;
      $to_insert[$record->nid]['vid'] = $record->vid;
      if ($type != 'evaluation') {
        $to_insert[$record->nid]['title'] = $record->title;
        $to_insert[$record->nid]['parent_id'] = $record->parent_id;
        $to_insert[$record->nid]['sequence'] = $record->sequence;
        $to_insert[$record->nid]['state'] = $record->state;
        $to_insert[$record->nid]['has_children'] = 0;
        if ($record->parent_id) {
          $parent_array[$record->parent_id][$record->nid] = $record->nid;
        }
      } else {
        $support = 0;
        if ($record->support == 1) {
          $support = 1;
        }
        $to_insert[$record->nid]['support'] = $support;
        $to_insert[$record->nid]['compared_id'] = $record->compared_id;
        $to_insert[$record->nid]['feature_id'] = $record->feature_id;
      }
      if ($type == 'feature') {
        $to_insert[$record->nid]['type'] = $record->type;
        $to_insert[$record->nid]['weight'] = $record->weight;
      }
      if (module_exists('wikicompare_inherit_compared')) {
        //Prepare the inherit compared specific fields in the flush tables function.
        wikicompare_inherit_compared_flush_cache($to_insert, $record, $type);
      }
    }

    if ($type != 'evaluation') {
      //Set has_children flag.
      foreach ($parent_array as $pid => $parent) {
        $to_insert[$pid]['has_children'] = 1;
      }

      if ($type == 'feature') {
        //Later, we will launch the update_compare_table with only the feature without children, this will be enough to compute the whole tree.
        $feature_without_children = array();
        foreach ($to_insert as $node) {
          if ($node['has_children'] == 0) {
            $feature_without_children[$node['nid']] = $node['nid'];
          }
        }
      }
    }

    //Build header for the insert.
    $header = array('nid', 'vid');
    if ($type != 'evaluation') {
      $header[] = 'title';
      $header[] = 'parent_id';
      $header[] = 'sequence';
      $header[] = 'state';
      $header[] = 'has_children';
    } else {
      $header[] = 'compared_id';
      $header[] = 'feature_id';
      $header[] = 'support';
    }
    if ($type == 'feature') {
      $header[] = 'type';
      $header[] = 'weight';
    }
    if (module_exists('wikicompare_inherit_compared')) {
      //Add inherit compared specific headers.
      wikicompare_inherit_compared_cache_fields_header($header, $type);
    }

    //Insert the data into the wikicompare cache table.
    $query = db_insert('cache_' . $type)->fields($header);
    foreach ($to_insert as $values) {
      $query->values($values);
    }
    $query->execute();

  }

  //Update parent_through_compared_id and parent_through_feature_id field in cache_evaluation.
  wikicompare_update_parent_link();

  //Update the structural fields from compared and feature in evaluation.
  if (Database::getConnection()->databaseType() == 'mysql') {
    db_query('UPDATE cache_evaluation n
           INNER JOIN cache_compared nc ON n.compared_id = nc.nid
           INNER JOIN cache_feature nf ON n.feature_id = nf.nid
           SET n.compared_parent_id = nc.parent_id, n.compared_state = nc.state, n.compared_has_children = nc.has_children,
           n.feature_parent_id = nf.parent_id, n.feature_state = nf.state, n.feature_has_children = nf.has_children, n.feature_type = nf.type, n.feature_weight = nf.weight');
  } else {
    db_query('UPDATE cache_evaluation
           SET compared_parent_id = nc.parent_id, compared_state = nc.state, compared_has_children = nc.has_children,
           feature_parent_id = nf.parent_id, feature_state = nf.state, feature_has_children = nf.has_children, feature_type = nf.type, feature_weight = nf.weight
           FROM cache_evaluation n
           INNER JOIN cache_compared nc ON n.compared_id = nc.nid
           INNER JOIN cache_feature nf ON n.feature_id = nf.nid
           WHERE cache_evaluation.nid = n.nid');
  }

  if (module_exists('wikicompare_inherit_compared')) {
    //Update parent_through_inherit_id in cache_evaluation.
    wikicompare_inherit_compared_update_parent_link();
  }

  //Update compatative table cache. We begin the update at the base of the feature tree and at the base of the compared tree.
  wikicompare_update_compare_tree('feature', $feature_without_children);

  //We only reactive the website if it wasn't in maintenance at the beginning.
  if ($was_in_maintenance == FALSE) {
    variable_set('maintenance_mode', 0);
  }

}


/**
 * Function to easily find the evaluation id with the compared and the feature.
 *
 * @param $compared_id
 *   The compared id of the evaluation to find.
 *
 * @param $feature_id
 *   The feature id of the evaluation to find.
 *
 * @return $nid
 *   The id of the evaluation.
 */
function wikicompare_get_evaluation_id($compared_id, $feature_id) {

  $query = db_select('cache_evaluation', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->condition('compared_id', $compared_id);
  $query->condition('feature_id', $feature_id);
  $result = $query->execute();
  foreach ($result as $record) {
    $nid = $record->nid;
  }

  return $nid;

}



/**
 * Function to stop any future update in the wikicompare cache table. Useful when we want to stop the percent computation, for exemple when we insert massive amount of data.
 */
function wikicompare_stop_computation() {

  db_update('cache_evaluation')
    ->fields(array(
      'percent' => NULL,
      'css_class' => '',
    ))
    ->execute();

  variable_set('wikicompare_computation_status', 0);

}


/**
 * Function to restart the updates in wikicompare cache table.
 */
function wikicompare_start_computation() {

  variable_set('wikicompare_computation_status', 1);

  wikicompare_refresh_caches();

}





/**
 * Generic function which will build the data needed, based on the information in the wikicompare caches.
 *
 * @param $type
 *   The type of the nodes to find.
 *
 * @param $db_settings
 *   An associative array containing the specific informations to build the database query.
 *     - nids: The nids are directly specified.
 *     - parent_id: We'll find the nodes by the parent id.
 *     - compared_id: We'll find the evaluations nodes with the compareds and feature ids.
 *     - feature_id: We'll find the evaluations nodes with the compareds and feature ids.
 *
 * @param $settings
 *   An associative array containing the informations about the context of the query, theses informations are often not only used in this function.
 *     - states: An array containing the state of the record to return.
 *     - fastaction: If the fastaction mode is activated on the wikicompare table.
 *
 * @return $res
 *   An array containing all the nodes found in database.
 *     - An array containing the details of the node.
 *       - data: The object containing the field of the node in table.
 *       - no-edit: Flag indicated that the user has no right to fastedit the node in wikicompare table.
 *       - no-remove: Flag indicated that the user has no right to fastremove the node in wikicompare table.
 */
function request_db($type, $db_settings = array(), $settings=array()) {

  //Start build the request.
  $query = db_select('cache_' . $type, 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'nid', 'tnid');

  //Non evaluation specific fields.
  if ($type != 'evaluation') {
    $query->addField('n', 'title', 'title');
    $query->addField('n', 'sequence', 'sequence');
    $query->addField('n', 'state', 'state');
    $query->addField('n', 'has_children', 'has_children');
    $query->addField('n', 'parent_id', 'parent_id');
    //If the nodes to recover are not specify by the nids in argument, then it means we need to use the parent_id.
    if (!isset($db_settings['nids'])) {
      $query->condition('n.parent_id', $db_settings['parent_id']);
      //By default, only published node are return, unless specify in the settings.
      $state = unserialize(WIKICOMPARE_STATE_PUBLISHED);
      if (isset($settings['states']['draft'])) {
        $state = array_merge($state, array('new', 'incomplete', 'submitted'));
      }
      if (isset($settings['states']['closed'])) {
        $state = array_merge($state, array('rejected', 'disactivated'));
      }
      $query->condition('n.state', $state, 'in');
    }
    //The returned nodes are ordered by the sequence field.
    $query->orderby('n.sequence, n.title');
  //evaluation specific fields.
  } else {
    $query->addField('n', 'feature_id', 'feature_id');
    $query->addField('n', 'compared_id', 'compared_id');
    $query->addField('n', 'percent', 'percent');
    $query->addField('n', 'css_class', 'css_class');
    //If the nodes to recover are not specify by the nids in argument, then it means we need to find them thanks to the compareds and features ids.
    if (!isset($db_settings['nids'])) {
      $query->condition("n.compared_id", $db_settings['compared_ids'], 'in');
      $query->condition("n.feature_id", $db_settings['feature_ids'], 'in');
    }
  }

  //If we didn't used another method to recover the nids.
  if (isset($db_settings['nids'])) {
    $query->condition('n.nid', $db_settings['nids'], 'in');
  }

  //Feature specific fields.
  if ($type == 'feature') {
    $query->addField('n', 'type', 'type');
    $query->addField('n', 'weight', 'weight');
  }

  //If fastaction mode is triggered, then we need to recover all the revision of the nodes to test if the user is the author of all the revisions. Otherwise, he will not be able to fastedit the node.
  if (isset($settings['fastaction'])) {
    if ($settings['fastaction'] == 1) {
      $query->addField('r', 'uid', 'uid');
      $query->leftjoin('node_revision', 'r', 'n.nid = r.nid');
    }
  }

  if (module_exists('wikicompare_inherit_compared')) {
    //Add inherit compared specific fields.
    wikicompare_inherit_compared_request_db($query, $type);
  }

  if (module_exists('wikicompare_translation')) {
    //Add the lines in the database request to recover the translated title, based on the information of the translated nodes.
    wikicompare_translation_request_db($query, $type, $db_settings, $settings);
  }

  if (module_exists('wikicompare_profiles')) {
    //Need specific fields.
    wikicompare_profiles_request_db($query, $type);
  }

  //Launch the request
  $result = $query->execute();


  $res = array();
  $profile_features = array();
  foreach ($result as $record) {

    //Start building the ressource which will be returned for this node.
    $node_array = array(
      //All data returned by the request are stored in this object.
      'data' => $record,
      'children' => array(),
    );

    if (module_exists('wikicompare_profiles')) {
      //Recover all profile_features in an array to use them later.
      wikicompare_profiles_request_db_build($node_array, $profile_features, $record, $type);
    }

    if ($settings['fastaction'] == 1) {
      //If the node was created by or have some revision from other users, current user will not be able to fastaction it.
      if ($GLOBALS['user']->uid != $record->uid) {
        $node_array['no-edit'] = True;
        $node_array['no-remove'] = True;
      }

      if (module_exists('wikicompare_translation')) {
        //Test if the translation node can be fastedit
        wikicompare_translation_request_db_fastaction($node_array, $record, $type, $db_settings);
      }
    }

    if (module_exists('wikicompare_translation')) {
      //Replace the title from db by the translated title
      wikicompare_translation_request_db_build($node_array, $record);
    }

    //Assign the node_array to $res with the nid as key, except it's an evaluation we found thanks to the compared and feature ids.
    if ($type != 'evaluation' || isset($db_settings['nids'])) {
      $res[$record->nid] = $node_array;
    } else {
      $res[$record->feature_id][$record->compared_id] = $node_array;
    }

  }

  if (module_exists('wikicompare_profiles')) {
    //Assign node features to the $res. We couldn't do it  while we were parsing the records.
    wikicompare_profiles_request_db_after($res, $profile_features);
  }

  return $res;

}

?>
