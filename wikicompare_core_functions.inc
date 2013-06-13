<?php
//READY

/**
 * @file
 * Define the main functions, like the recursive function which update the compare tree, the one which refresh the cache and the generic request db function.
 */



/**
 * The main function to update the percent and css_class for each implementation
 * It'll find all children on compared and feature axis for the ids passed in argument, compute the percent thanks to theses informations and feature type, and finally if the percent changed it'll update the parents on feature and compared axis.
 * This is a recursive function, which will call itself on children side if a cache percent is missing and parent side if the percent computed change, and in both the feature and compared axis.
 * DISCLAIMER : Trying to read this function may cause important headeaches.
 *
 * @param $type
 *   The type of the node to update. Only the implementation are updated at the end, but specifying compared or feature allow to directly update all their implementations.
 *
 * @param $nids
 *   The nids of the nodes to update.
 *
 * @param $update_parent
 *   Flag which can block the recursivity of the function on parent. This allow to avoid updating parents if the function was recursively launched by the parents.
 *
 * @return array
 *   An array containing the implementations updated by the function. This is mainly used to recover the children when this function is recursively called by the parents.
 */
function wikicompare_update_compare_tree($type, $nids, $update_parent = NULL) {

  $nodes = array();
  if (!empty($nids)) {

    //Recover the details of the targeted implementations.
    $query = db_select('cache_implementation', 'fs');
    $query->addField('fs', 'nid', 'nid');
    $query->addField('fs', 'feature_id', 'fid');
    $query->addField('fs', 'compared_id', 'cid');
    $query->addField('fs', 'support', 'support');	
    $query->addField('nf', 'type', 'type');
    $query->addField('nf', 'parent_id', 'parent_id');
    $query->addField('nfpnf', 'nid', 'parent_fs_through_feature_nid');

    //Get parent implementation through feature axis.
    $query->join('cache_feature', 'nf', 'fs.feature_id = nf.nid'); //Get feature node.
    $query->leftjoin('cache_implementation', 'nfpnf', 'nf.parent_id = nfpnf.feature_id'); //Get implementation of the parent feature node.

    $query->where('nfpnf.compared_id = fs.compared_id OR nf.parent_id IS NULL'); //We keep only the implementation of the parent feature node which has the same compared than the implementation. Which mean it's the parent implementation on the feature axis.

    $query->join('cache_compared', 'nc', 'fs.compared_id = nc.nid'); //Get compared node.

    //Get parent implementation through compared axis, only if compared update is enabled.
    if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
      $query->addField('nc', 'parent_id', 'parent_id');
      $query->addField('ncpnc', 'nid', 'parent_fs_through_compared_nid');
      $query->leftjoin('cache_implementation', 'ncpnc', 'nc.parent_id = ncpnc.compared_id'); //Get implementation of the parent compared node.

      $query->where('ncpnc.feature_id = fs.feature_id OR nc.parent_id IS NULL'); //We keep only the implementation of the parent compared node which has the same feature than the implementation. Which mean it's the parent implementation on the compared axis.

    }

    //If possible, we search directly through feature or compared id to compute the sql request faster.
    switch ($type) {
      case "implementation":
        $query->condition('fs.nid', $nids, 'IN');
        break;
      case "feature":
        //Recover children of implementation on compared axis, because we will only update implementation which has no children on compared axis.
        $query->leftjoin('cache_compared', 'ncc', 'fs.compared_id = ncc.parent_id'); //Get compared node children.
        $query->where('ncc.nid IS NULL'); //Only the implementation without children on compared axis need to be updated, because they will update their parent on compared axis anyway.
        $query->condition('fs.feature_id', $nids, 'IN');
        break;
      case "compared":
        //Recover children of implementation on feature axis, because we will only update implementation which has no children on feature axis.
        $query->leftjoin('cache_feature', 'nfc', 'fs.feature_id = nfc.parent_id'); //Get feature node children.
        $query->where('nfc.nid IS NULL'); //Only the implementation without children on feature axis need to be updated, because they will update their parent on feature axis anyway.
        $query->condition('fs.compared_id', $nids, 'IN');
        break;
    }

    if (module_exists('wikicompare_inherit_compared')) {
      //Add the requests to recover the inherited implementation.
      wikicompare_inherit_compared_update_main_query($query);
    }

    $result = $query->execute();

    //Build the variables needed for later computations.
    $implementation_ids = array();
    $res_search_feature_children = '';
    $res_search_compared_children = '';
    foreach($result as $record) {
      //Using $record->nid as key allow deduplication of the id in argument array.
      $nodes[$record->nid] = $record;
      $implementation_ids[$record->nid] = $record->nid;

      //Build the where argument for the later get children query.
      if ($res_search_feature_children) {
        $res_search_feature_children = $res_search_feature_children . ',';
      }
      $res_search_feature_children = $res_search_feature_children . "('" . $record->fid . "','" . $record->cid . "')";

      if ($res_search_compared_children) {
        $res_search_compared_children = $res_search_compared_children . ',';
      }
      $res_search_compared_children = $res_search_compared_children . "('" . $record->cid . "','" . $record->fid . "')";
    }

    //Get the children on feature axis.
    $through_feature_childs = array();
    //We don't need the children through feature axis in case of type = 'compared'. Also, we should not call this function if $res_search_feature_children is used and null, otherwise it'll crash.
    if ($type == 'feature' || ($type == 'implementation' && $res_search_feature_children)) {
      //Get children implementation through feature axis
      $query = db_select('cache_implementation', 'fs');
      $query->addField('fs', 'nid', 'nid');
      $query->addField('fs', 'feature_id', 'fid');
      $query->addField('fs', 'compared_id', 'cid');
      $query->addField('nf','parent_id', 'parent_fid');
      $query->addField('ctc', 'nid', 'cache_nid');
      $query->addField('ctc', 'percent', 'percent');
      $query->addField('nf', 'weight', 'weight');

      //Get parent feature
      $query->leftjoin('cache_feature', 'nf', 'fs.feature_id = nf.nid');	

      //Get the percent computed of the children, if already computed
      $query->leftjoin('cache_comparative_table', 'ctc', 'fs.nid = ctc.nid');	

      switch ($type) {
        case "implementation":
          //We keep only the implementation of the child feature node which has the same compared than the implementation. Which mean it's the children implementation on the feature axis.
          $query->where('(nf.parent_id, fs.compared_id) IN (' . $res_search_feature_children . ')');
          break;
        case "feature":
          $query->condition('nf.parent_id', $nids, 'IN');
          break;
      }

      //Only published features are used in their parent computation.
      $query->condition('nf.state', array('published-incomplete', 'published-submitted', 'published'), 'in');
      $result = $query->execute();

      //We assign the children implementation in a array with fid and cid as key so their parents can recover them with fid and cid key.
      $through_feature_childs = array();
      foreach($result as $record) {
        $through_feature_childs[$record->parent_fid][$record->cid][$record->nid] = $record;
      }
    }

    //Get the children on feature axis.
    $through_compared_childs = array();
    //We don't need the children through compared child in case of type = 'feature'. Also, we should not call this function if $res_search_feature_children is used and null, otherwise it'll crash.
    if ($type == 'compared' || ($type == 'implementation' && $res_search_compared_children)) {
      //Get children implementation through feature axis.
      $query = db_select('cache_implementation', 'fs');
      $query->addField('fs', 'nid', 'nid');
      $query->addField('fs', 'feature_id', 'fid');
      $query->addField('fs', 'compared_id', 'cid');
      $query->addField('nc','parent_id', 'parent_cid');
      $query->addField('ctc', 'nid', 'cache_nid');
      $query->addField('ctc', 'percent', 'percent');
      $query->addField('ctc', 'css_class', 'css_class');

      //Get parent compared.
      $query->leftjoin('cache_compared', 'nc', 'fs.compared_id = nc.nid');

      //Get the percent computed of the children, if already computed.
      $query->leftjoin('cache_comparative_table', 'ctc', 'fs.nid = ctc.nid');

      switch ($type) {
        case "implementation":
          //We keep only the implementation of the child compared node which has the same feature than the implementation. Which mean it's the children implementation on the compared axis.
          $query->where('(nc.parent_id, fs.feature_id) IN (' . $res_search_compared_children . ')');
          break;
        case "compared":
          $query->condition('nc.parent_id', $nids, 'IN');
          break;
      }

      $result = $query->execute();

      //We assign the children implementation in a array with fid and cid as key so they parent can recover them with fid and cid key
      $through_compared_childs = array();
      foreach($result as $record) {
        $through_compared_childs[$record->parent_cid][$record->fid][$record->nid] = $record;
      }
    }

    //Assign children to each node to compute.
    $to_update = array();
    foreach($nodes as $node) {
      $node->through_feature_childs = array();
      if (isset($through_feature_childs[$node->fid][$node->cid])) {
        //Assign the children thanks to fid and cid key.
        $node->through_feature_childs = $through_feature_childs[$node->fid][$node->cid];
        foreach($through_feature_childs[$node->fid][$node->cid] as $child) {
          if (!$child->cache_nid) {
            //If the children isn't already computed, we mark it to update.
            $to_update_feature_childs[$child->nid] = $child->nid;
          }
        }
      }
      $node->through_compared_childs = array();
      if (isset($through_compared_childs[$node->cid][$node->fid])) {
        //Assign the children thanks to fid and cid key.
        $node->through_compared_childs = $through_compared_childs[$node->cid][$node->fid];
        foreach($through_compared_childs[$node->cid][$node->fid] as $child) {
          if (!$child->cache_nid) {
            //If the children isn't already computed, we mark it to update.
            $to_update_compared_childs[$child->nid] = $child->nid;
          }
        }
      }
    }

    //If some children through feature axis are not already computed.
    if (!empty($to_update_feature_childs)) {
      //Update the children on feature axis with the flag no-update-feature. This flag ensure it'll not try to update parent on the same axis than the one we use here.
      $res = wikicompare_update_compare_tree('implementation', $to_update_feature_childs, 'no-update-feature');
      foreach($nodes as $node) {
        foreach($node->through_feature_childs as $key => $child) {
          //Update_compare_tree function return percent and css_class value of the implementation computed in array, we use it to update our children.
          if (isset($res[$key])) {
            $child->percent = $res[$key]['percent'];
            $child->css_class = $res[$key]['css_class'];
          }
        }
      }
    }

    //If some children through compared axis are not already computed.
    if (!empty($to_update_compared_childs)) {
      //Update the children on compared axis with the flag no-update-compared. This flag ensure it'll not try to update parent on the same axis than the one we use here.
      $res = wikicompare_update_compare_tree('implementation', $to_update_compared_childs, 'no-update-compared');
      foreach($nodes as $node) {
        foreach($node->through_compared_childs as $key => $child) {
          //Update_compare_tree function return percent and css_class value of the implementation computed in array, we use it to update our children.
          if (isset($res[$key])) {
            $child->percent = $res[$key]['percent'];
            $child->css_class = $res[$key]['css_class'];
          }
        }
      }
    }

    if (module_exists('wikicompare_inherit_compared')) {
      //Compute the inherited implementation if not already done, and get inheriting children.
      wikicompare_inherit_compared_update_comparative_table_preparation($nodes, $type, $nids);
    }

    //Recover the existing cache value only now and not in the first SQL request, because their value may be updated during the children update.
    if ($implementation_ids) {
      $query = db_select('node', 'fs');
      $query->addField('fs', 'nid', 'nid');
      $query->addField('ctc', 'nid', 'cache_nid');
      $query->addField('ctc', 'percent', 'cache_percent');
      $query->addField('ctc', 'css_class', 'cache_css_class');
      $query->leftjoin('cache_comparative_table', 'ctc', 'fs.nid = ctc.nid');
      $query->condition('fs.nid', $implementation_ids, 'IN');
      $result = $query->execute();
      foreach($result as $record) {
        $nodes[$record->nid]->cache_nid = $record->cache_nid;
        $nodes[$record->nid]->cache_percent = $record->cache_percent;
        $nodes[$record->nid]->cache_css_class = $record->cache_css_class;
      }
    }

  }



  /*
   * Now we'll compute the percent and css_class of each nids in function argument.
   */
  $to_update = array();
  $cache_to_update = array();
  $cache_to_insert = array();
  $res = array();
  foreach($nodes as $node) {

    //We update only if the update parent isn't set and there is no children on compared axis.
    if ((variable_get('wikicompare_update_compared', 'no-update') == 'no-update') && !empty($node->through_compared_childs)) {
      continue;
    }

    //If any misconfiguration, it'll always return 0.
    $node->percent = 0;
    $node->css_class = 'cell-support-no';

    //The support field is used only if the implementation is the deepest in the tree, on both the feature and compared axis.
    if (empty($node->through_feature_childs) && empty($node->through_compared_childs)) {
      if ($node->support == 1) {
        $node->percent = 100;
        $node->css_class = 'cell-support-complete';
      } else {
        $node->percent = 0;
        $node->css_class = 'cell-support-no';
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Return the data computed according to the inherited implementation.
        wikicompare_inherit_compared_from_other_support($node);
      }
    //If the feature is of type weighted average, it'll use the children through feature axis to compute the percent
    } else {
      $node = wikicompare_compute_percent($node, $node->through_feature_childs);
    }

    //If a children through compared axis is higher than the value computed, then it'll be used instead.
    foreach($node->through_compared_childs as $child) {
      if ($child->percent >= $node->percent) {
        $node->percent = $child->percent;
        $node->css_class = $child->css_class;
      }
    }

    //Update the value computed in database, only if the value has changed.
    if ((($node->percent != $node->cache_percent) || ($node->css_class != $node->cache_css_class))) {
      if ($node->cache_nid) {
        //We regroup all the same percent in a table to update them all at the same time.
        $cache_to_update[$node->css_class][$node->percent][] = $node->nid;
      } else {
        //We regroup all the same percent in a table to insert them all at the same time.
        $cache_to_insert[$node->css_class][$node->percent][] = $node->nid;
      }
    }

    //Update the parent though feature and compared axis if the value changed. This ensure this comparison work correctly and don't update parent if unnecessary.
    //If the flag no-update is set, no update will be made.
    if (($node->percent != $node->cache_percent) || ($node->css_class != $node->cache_css_class)) {

      //We mark the parent id through feature axis to update if exist, unless we have the flag no-update-feature. This flag deny the parent update through feature axis if wikicompare_update_compare_tree was launched for a children computation.
      if (($node->parent_fs_through_feature_nid) && ($update_parent != 'no-update-feature')) {
        $to_update[$node->parent_fs_through_feature_nid] = $node->parent_fs_through_feature_nid;
      }

      //We mark the parent id through compared axis to update if exist, unless we have the flag no-update-compared. This flag deny the parent update through compared axis if wikicompare_update_compare_tree was launched for a children computation.
      if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
        if (($node->parent_fs_through_compared_nid) && ($update_parent != 'no-update-compared')) {
          $to_update[$node->parent_fs_through_compared_nid] = $node->parent_fs_through_compared_nid;
        }
      }

      if (module_exists('wikicompare_inherit_compared')) {
        //Add in the implementation to update the implementation which inherit the current implementation.
        wikicompare_inherit_compared_update_comparative_table_post($to_update, $node);
      }

    }

    //Fill the res variable the function will return.
    $res[$node->nid]['percent'] = $node->percent;
    $res[$node->nid]['css_class'] = $node->css_class;

  }

  //Insert the new records in database. Data are regrouped by css and percent to try to make as few query as possible.
  foreach($cache_to_insert as $key_css_class => $css_class) {
    foreach($cache_to_insert[$key_css_class] as $key_percent => $percent) {
      $query = db_insert('cache_comparative_table')->fields(array('nid', 'percent', 'css_class'));
      foreach ($cache_to_insert[$key_css_class][$key_percent] as $nid) {
        $query->values(array(
          'nid' => $nid,
          'percent' => $key_percent,
          'css_class' => $key_css_class,
        ));
      }
      $query->execute();
    }
  }
  //Update the old records. Data are regrouped by css and percent to try to make as few query as possible.
  foreach($cache_to_update as $key_css_class => $css_class) {
    foreach($cache_to_update[$key_css_class] as $key_percent => $percent) {
        db_update('cache_comparative_table')
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
    wikicompare_update_compare_tree('implementation', $to_update);
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
      $node->percent = round(($total / $count),4);

    //If the feature is of type highest percentage, it'll take the maximum value of the children.
    } elseif ($node->type == 'parent-highest-percentage') {
      $node->percent = 0;
      $node->css_class = 'cell-support-no';
      foreach($through_feature_childs as $child) {

          //Security if weight field is misconfigured.
          if ($child->weight > 100) {
            $child->weight = 100;
          }

          //Compute the value for this children. We round the percent to 4 because it's the precision in database.
          $child_percent = round(($child->percent * $child->weight / 100), 4);
          //If percent for this children is highter, then it'll be the value computed.
          if ($child_percent >= $node->percent) {
            $node->percent = $child_percent;
          }

      }

      //Find the css class based on the percentage value.
      if ($node->percent ==0) {
        $node->css_class = 'cell-support-no';
      } elseif (($node->percent > 0) && ($node->percent < 10)) {
        $node->css_class = 'cell-support-partial-0-10';
      } elseif (($node->percent >= 10) && ($node->percent < 20)) {
        $node->css_class = 'cell-support-partial-10-20';
      } elseif (($node->percent >= 20) && ($node->percent < 30)) {
        $node->css_class = 'cell-support-partial-20-30';
      } elseif (($node->percent >= 30) && ($node->percent < 40)) {
        $node->css_class = 'cell-support-partial-30-40';
      } elseif (($node->percent >= 40) && ($node->percent < 50)) {
        $node->css_class = 'cell-support-partial-40-50';
      } elseif (($node->percent >= 50) && ($node->percent < 60)) {
        $node->css_class = 'cell-support-partial-50-60';
      } elseif (($node->percent >= 60) && ($node->percent < 70)) {
        $node->css_class = 'cell-support-partial-60-70';
      } elseif (($node->percent >= 70) && ($node->percent < 80)) {
        $node->css_class = 'cell-support-partial-70-80';
      } elseif (($node->percent >= 80) && ($node->percent < 90)) {
        $node->css_class = 'cell-support-partial-80-90';
      } elseif (($node->percent >= 90) && ($node->percent < 100)) {
        $node->css_class = 'cell-support-partial-90-100';
      } elseif (($node->percent == 100)) {
        $node->css_class = 'cell-support-complete';
      }
    }

    return $node;
}





/**
 * Function which refresh all wikicompare cache tables. It will truncate the tables and then rebuild them based on the information in tables node and field_revisions_*.
 * We should use it if for any reason some nodes were miscalculated.
 */
function wikicompare_flush_caches() {

  global $language;

  //We put the site in maintenance, and check if it was already in maintenance to know if we shall reactive the website after the operation.
  $was_in_maintenance = FALSE;
  if (variable_get('maintenance_mode', 0) == 1) {
    $was_in_maintenance = TRUE;
  } else {
    //Activate maintenance mode.
    variable_set('maintenance_mode', 1);
  }

  //Delete all datas in cache.
  db_delete('cache_comparative_table')
    ->execute();

  $types = array('compared', 'feature', 'implementation');

  if (module_exists('wikicompare_needs')) {
    //Add need type.
    wikicompare_needs_node_types($types);
  }


  foreach ($types as $type) {

    //Delete all data in the type cache.
    db_delete('cache_' . $type)
      ->execute();

    //Get all data from node and field_revision_* tables.
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'vid', 'vid');
    if ($type != 'implementation') {
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
      if ($type != 'implementation') {
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

    if ($type != 'implementation') {
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
    if ($type != 'implementation') {
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

  //Update compatative table cache. We begin the update at the base of the feature tree and at the base of the compared tree.
  wikicompare_update_compare_tree('feature', $feature_without_children);

  //We only reactive the website if it wasn't in maintenance at the beginning.
  if ($was_in_maintenance == FALSE) {
    variable_set('maintenance_mode', 0);
  }

}


/**
 * Function to easily find the implementation id with the compared and the feature.
 *
 * @param $compared_id
 *   The compared id of the implementation to find.
 *
 * @param $feature_id
 *   The feature id of the implementation to find.
 *
 * @return $nid
 *   The id of the implementation.
 */
function wikicompare_get_implementation_id($compared_id, $feature_id) {

  $query = db_select('cache_implementation', 'n');
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
 * Generic function which will build the data needed, based on the information in the wikicompare caches.
 *
 * @param $type
 *   The type of the nodes to find.
 *
 * @param $db_settings
 *   An associative array containing the specific informations to build the database query.
 *     - nids: The nids are directly specified.
 *     - parent_id: We'll find the nodes by the parent id.
 *     - compared_id: We'll find the implementations nodes with the compareds and feature ids.
 *     - feature_id: We'll find the implementations nodes with the compareds and feature ids.
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

  //Non implementation specific fields.
  if ($type != 'implementation') {
    $query->addField('n', 'title', 'title');
    $query->addField('n', 'sequence', 'sequence');
    $query->addField('n', 'state', 'state');
    $query->addField('n', 'has_children', 'has_children');
    $query->addField('n', 'parent_id', 'parent_id');
    //If the nodes to recover are not specify by the nids in argument, then it means we need to use the parent_id.
    if (!isset($db_settings['nids'])) {
      $query->condition('n.parent_id', $db_settings['parent_id']);
      //By default, only published node are return, unless specify in the settings.
      $state = array('published-incomplete', 'published-submitted', 'published');
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
  //Implementation specific fields.
  } else {
    $query->addField('n', 'feature_id', 'feature_id');
    $query->addField('n', 'compared_id', 'compared_id');
    $query->addField('ctc', 'percent', 'percent');
    $query->addField('ctc', 'css_class', 'css_class');
    $query->leftjoin('cache_comparative_table', 'ctc', 'n.nid = ctc.nid');
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

  if (module_exists('wikicompare_needs')) {
    //Need specific fields.
    wikicompare_needs_request_db($query, $type);
    if ($type == 'need') {
      $query->addField('nf', 'feature_nid', 'need_feature_id');
      $query->leftjoin('cache_need_feature_rel', 'nf', 'n.nid = nf.need_nid');
    }
  }

  //Launch the request
  $result = $query->execute();


  $res = array();
  $need_features = array();
  foreach ($result as $record) {

    //Start building the ressource which will be returned for this node.
    $node_array = array(
      //All data returned by the request are stored in this object.
      'data' => $record,
      'children' => array(),
    );

    if (module_exists('wikicompare_needs')) {
      //Recover all need_features in an array to use them later.
      wikicompare_needs_request_db_build($node_array, $need_features, $record, $type);
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

    //Assign the node_array to $res with the nid as key, except it's an implementation we found thanks to the compared and feature ids.
    if ($type != 'implementation' || isset($settings['nids'])) {
      $res[$record->nid] = $node_array;
    } else {
      $res[$record->feature_id][$record->compared_id] = $node_array;
    }

  }

  if (module_exists('wikicompare_needs')) {
    //Assign node features to the $res. We couldn't do it  while we were parsing the records.
    wikicompare_needs_request_db_after($res, $need_features);
  }

  return $res;

}

?>
