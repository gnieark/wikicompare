<?php



 /*
  * The main function to update the percent and css_class for each implementation
  * It'll find all children on compared and feature axis for the ids passed in argument, compute the percent thanks to theses informations and feature type, and finally if the percent changed it'll update the parents on feature and compared axis.
  * This is a recursive function, which will call itself on children side if a cache percent is missing and parent side if the percent computed change, and in both the feature and compared axis.
  */
function wikicompare_update_compare_tree($type, $nids, $update_parent = NULL) {


  $nodes = array();
  if (!empty($nids)) {

    $query = db_select('cache_implementation', 'fs');
    $query->addField('fs', 'nid', 'nid');
    $query->addField('fs', 'feature_id', 'fid');
    $query->addField('fs', 'compared_id', 'cid');
    $query->addField('fs', 'support', 'support');	
    $query->addField('nf', 'type', 'type');
    $query->addField('nf', 'parent_feature_id', 'parent_feature_id');
    $query->addField('nfpnf', 'nid', 'parent_fs_through_feature_nid');

    //Get parent implementation through feature axis
    $query->join('cache_feature', 'nf', 'fs.feature_id = nf.nid'); //Get feature node
    $query->leftjoin('cache_implementation', 'nfpnf', 'nf.parent_feature_id = nfpnf.feature_id'); //Get implementation of the parent feature node

    $query->join('cache_compared', 'nc', 'fs.compared_id = nc.nid'); //Get compared node

    //Get parent implementation through compared axis, only if compared update is enabled
    if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
      $query->addField('nc', 'parent_compared_id', 'parent_compared_id');
      $query->addField('ncpnc', 'nid', 'parent_fs_through_compared_nid');
      $query->leftjoin('cache_implementation', 'ncpnc', 'nc.parent_compared_id = ncpnc.compared_id'); //Get implementation of the parent compared node

      $query->where('ncpnc.feature_id = fs.feature_id OR nc.parent_compared_id IS NULL'); //We keep only the implementation of the parent compared node which has the same feature than the implementation. Which mean it's the parent implementation on the compared axis.

    }

    //If possible, we search directly through feature or compared id to compute the sql request faster
    switch ($type) {
      case "implementation":
        $query->condition('fs.nid', $nids, 'IN');
        break;
      case "feature":
        //Recover children of implementation on compared axis, because we will only update implementation which has no children on compared axis
        $query->leftjoin('cache_compared', 'ncc', 'fs.compared_id = ncc.parent_compared_id'); //Get compared node children
        $query->where('ncc.nid IS NULL'); //Only the implementation without children on compared axis need to be updated, because they will update their parent on compared axis anyway
        $query->condition('fs.feature_id', $nids, 'IN');
        break;
      case "compared":
        //Recover children of implementation on feature axis, because we will only update implementation which has no children on feature axis
        $query->leftjoin('cache_feature', 'nfc', 'fs.feature_id = nfc.parent_feature_id'); //Get feature node children
        $query->where('nfc.nid IS NULL'); //Only the implementation without children on feature axis need to be updated, because they will update their parent on feature axis anyway
        $query->condition('fs.compared_id', $nids, 'IN');
        break;
    }

    $query->where('nfpnf.compared_id = fs.compared_id OR nf.parent_feature_id IS NULL'); //We keep only the implementation of the parent feature node which has the same compared than the implementation. Which mean it's the parent implementation on the feature axis.

    //Allow the others modules to update the query
    foreach (module_implements('wikicompare_update_main_query') as $module) {
      $function = $module . '_wikicompare_update_main_query';
      $function($query);
    }

    $result = $query->execute();


    $implementation_ids = array();
    $res_search_feature_children = '';
    $res_search_compared_children = '';
    foreach($result as $record) {
      //Using $record->nid as key allow deduplication of the id in argument array
      $nodes[$record->nid] = $record;
      $implementation_ids[$record->nid] = $record->nid;

      //Build the where argument for the later get children query
      if ($res_search_feature_children) {
        $res_search_feature_children = $res_search_feature_children . ',';
      }
      $res_search_feature_children = $res_search_feature_children . "('" . $record->fid . "','" . $record->cid . "')";

      if ($res_search_compared_children) {
        $res_search_compared_children = $res_search_compared_children . ',';
      }
      $res_search_compared_children = $res_search_compared_children . "('" . $record->cid . "','" . $record->fid . "')";
    }


    $through_feature_childs = array();
    //We don't need the children through feature child in case of type = 'compared'. Also, we should not call this function if $res_search_feature_children is used and null, otherwise it'll crash.
    if ($type == 'feature' || ($type == 'implementation' && $res_search_feature_children)) {
      //Get children implementation through feature axis
      $query = db_select('cache_implementation', 'fs');
      $query->addField('fs', 'nid', 'nid');
      $query->addField('fs', 'feature_id', 'fid');
      $query->addField('fs', 'compared_id', 'cid');
      $query->addField('nf','parent_feature_id', 'parent_fid');
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
          $query->where('(nf.parent_feature_id, fs.compared_id) IN (' . $res_search_feature_children . ')');
          break;
        case "feature":
          $query->condition('nf.parent_feature_id', $nids, 'IN');
          break;
      }

      //Only published feature are used in their parent computation
      $query->condition('nf.state', 'Published', '=');
      $result = $query->execute();

      $through_feature_childs = array();
      foreach($result as $record) {
        //We assign the children implementation in a array with fid and cid as key so their parents can recover them with fid and cid key
        $through_feature_childs[$record->parent_fid][$record->cid][$record->nid] = $record;
      }

    }


    $through_compared_childs = array();

    //We don't need the children through compared child in case of type = 'feature'. Also, we should not call this function if $res_search_feature_children is used and null, otherwise it'll crash.
    if ($type == 'compared' || ($type == 'implementation' && $res_search_compared_children)) {

      //Get children implementation through feature axis
      $query = db_select('cache_implementation', 'fs');
      $query->addField('fs', 'nid', 'nid');
      $query->addField('fs', 'feature_id', 'fid');
      $query->addField('fs', 'compared_id', 'cid');
      $query->addField('nc','parent_compared_id', 'parent_cid');
      $query->addField('ctc', 'nid', 'cache_nid');
      $query->addField('ctc', 'percent', 'percent');
      $query->addField('ctc', 'css_class', 'css_class');

      //Get parent compared
      $query->leftjoin('cache_compared', 'nc', 'fs.compared_id = nc.nid');

      //Get the percent computed of the children, if already computed
      $query->leftjoin('cache_comparative_table', 'ctc', 'fs.nid = ctc.nid');

      switch ($type) {
        case "implementation":
          //We keep only the implementation of the child compared node which has the same feature than the implementation. Which mean it's the children implementation on the compared axis.
          $query->where('(nc.parent_compared_id, fs.feature_id) IN (' . $res_search_compared_children . ')');
          break;
        case "compared":
          $query->condition('nc.parent_compared_id', $nids, 'IN');
          break;
      }

      $result = $query->execute();

      $through_compared_childs = array();
      foreach($result as $record) {
        //We assign the children implementation in a array with fid and cid as key so they parent can recover them with fid and cid key
        $through_compared_childs[$record->parent_cid][$record->fid][$record->nid] = $record;
      }

    }

    //Assign children to each node to compute. 
    $to_update = array();
    foreach($nodes as $node) {
      $node->through_feature_childs = array();
      if (isset($through_feature_childs[$node->fid][$node->cid])) {
        //Assign the children thanks to fid and cid key
        $node->through_feature_childs = $through_feature_childs[$node->fid][$node->cid];
        foreach($through_feature_childs[$node->fid][$node->cid] as $child) {
          if (!$child->cache_nid) {
            //If the children isn't already computed, we mark it to update
            $to_update_feature_childs[$child->nid] = $child->nid;
          }
        }
      }
      $node->through_compared_childs = array();
      if (isset($through_compared_childs[$node->cid][$node->fid])) {
        //Assign the children thanks to fid and cid key
        $node->through_compared_childs = $through_compared_childs[$node->cid][$node->fid];
        foreach($through_compared_childs[$node->cid][$node->fid] as $child) {
          if (!$child->cache_nid) {
            //If the children isn't already computed, we mark it to update
            $to_update_compared_childs[$child->nid] = $child->nid;
          }
        }
      }
    }





    if (!empty($to_update_feature_childs)) {
      //Update the children on feature axis with the flag no-update-feature. This flag ensure it'll not try to update parent on the same axis than the one we use here
      $res = wikicompare_update_compare_tree('implementation', $to_update_feature_childs, 'no-update-feature');
      foreach($nodes as $node) {
        foreach($node->through_feature_childs as $key => $child) {
          //Update_compare_tree function return percent and css_class value of the implementation computed in array, we use it to update our children
          if (isset($res[$key])) {
            $child->percent = $res[$key]['percent'];
            $child->css_class = $res[$key]['css_class'];
          }
        }
      }
    }


    if (!empty($to_update_compared_childs)) {
      //Update the children on compared axis with the flag no-update-compared. This flag ensure it'll not try to update parent on the same axis than the one we use here
      $res = wikicompare_update_compare_tree('implementation', $to_update_compared_childs, 'no-update-compared');
      foreach($nodes as $node) {
        foreach($node->through_compared_childs as $key => $child) {
          //Update_compare_tree function return percent and css_class value of the implementation computed in array, we use it to update our children
          if (isset($res[$key])) {
            $child->percent = $res[$key]['percent'];
            $child->css_class = $res[$key]['css_class'];
          }
        }
      }
    }

  

    //Allow others modules to make some action before we start computing the node
    foreach (module_implements('wikicompare_update_comparative_table_preparation') as $module) {
      $function = $module . '_wikicompare_update_comparative_table_preparation';
      $function($nids, $nodes, $type);
    }

    //Recover the existing cache value only now and not in the first SQL request, because their value may be updated during the children update
    if ($implementation_ids) {
      $query = db_select('node', 'fs');
      $query->addField('fs', 'nid', 'nid');
      $query->addField('ctc', 'nid', 'cache_nid');
      $query->addField('ctc', 'percent', 'cache_percent');
      $query->addField('ctc', 'css_class', 'cache_css_class');
      $query->leftjoin('cache_comparative_table', 'ctc', 'fs.nid = ctc.nid');
      $query->condition('fs.nid', $implementation_ids, 'IN');
      $result = $query->execute();
    }

    foreach($result as $record) {
      $nodes[$record->nid]->cache_nid = $record->cache_nid;
      $nodes[$record->nid]->cache_percent = $record->cache_percent;
      $nodes[$record->nid]->cache_css_class = $record->cache_css_class;
    }

}

  /*
   * Now we'll compute the percent and css_class of each nids in function argument
   */
  $to_update = array();
  $cache_to_update = array();
  $cache_to_insert = array();
  $res = array();
  foreach($nodes as $node) {

    //We update only if the update parent isn't set and there is no children on compared axis
    if ((variable_get('wikicompare_update_compared', 'no-update') == 'no-update') && !empty($node->through_compared_childs)) {
      continue;
    }

    //If any misconfiguration, it'll always return 0
    $node->percent = 0;
    $node->css_class = 'cell-support-no';

    //The support field is used only if the implementation is the deepest in the tree, on both the feature and compared axis
    if (empty($node->through_feature_childs) && empty($node->through_compared_childs)) {

      if ($node->support == 1) {
        $node->percent = 100;
        $node->css_class = 'cell-support-complete';
      } else {
        $node->percent = 0;
        $node->css_class = 'cell-support-no';
      }

      //Allow others modules to change the way support is computed at the base of the tree
      foreach (module_implements('wikicompare_from_other_support') as $module) {
        $function = $module . '_wikicompare_from_other_support';
        $function($node);
      }

    //If the feature is of type weighted average, it'll use the children through feature axis to compute the percent
    } elseif ($node->type == 'parent-weighted-average') {

      $total = 0;
      $count = 0;
      foreach($node->through_feature_childs as $child) {
        $total += $child->percent * $child->weight;
        $count += $child->weight;
      }

      //Security to avoid the divided by 0
      if ($count == 0) {
        $count = 1;
      }

      $node->percent = round(($total / $count),4);
      $node->css_class = find_css_class($node->percent);

    //If the feature is of type highest percentage, it'll use the children through feature axis to compute the percent
    } elseif ($node->type == 'parent-highest-percentage') {
      $node->percent = 0;
      $node->css_class = 'cell-support-no';
      foreach($node->through_feature_childs as $child) {

          //Security if weight field is misconfigured
          if ($child->weight > 100) {
            $child->weight = 100;
          }

          //Compute the value for this children.
          $child_percent = round(($child->percent * $child->weight / 100), 4);
          //If percent for this children is highter, then it'll be the value computed
          if ($child_percent >= $node->percent) {
            $node->percent = $child_percent;
          }

      }
      $node->css_class = find_css_class($node->percent);

    }

    //If a children through compared axis is higher than the value computed, then it'll be used instead
    foreach($node->through_compared_childs as $child) {

      if ($child->percent >= $node->percent) {
        $node->percent = $child->percent;
        $node->css_class = $child->css_class;
      }

    }


    //Update the value computed in database, only if the value changed
    if (!(($node->percent == $node->cache_percent) && ($node->css_class == $node->cache_css_class))) {
      if ($node->cache_nid) {
        //We regroup all the same percent in a table to update them all at the same time
        $cache_to_update[$node->css_class][$node->percent][] = $node->nid;
      } else {
        //We regroup all the same percent in a table to insert them all at the same time
        $cache_to_insert[$node->css_class][$node->percent][] = $node->nid;
      }
    }

    //Update the parent though feature and compared axis if the value changed, or if we have the flag force-update. Above, we rounded the percent computed to 4 because it'll be the same rounding than the one in database. This ensure this comparison work correctly and don't update parent if unnecessary.
    //If the flag no-update is set, no update will be made.
    if (($node->percent != $node->cache_percent) || ($node->css_class != $node->cache_css_class)) {

      //We mark the parent id through feature axis to update if exist, unless we have the flag no-update-feature. This flag deny the parent update through feature axis if wikicompare_update_compare_tree was launched for a children computation
      if (($node->parent_fs_through_feature_nid) && ($update_parent != 'no-update-feature')) {
        $to_update[$node->parent_fs_through_feature_nid] = $node->parent_fs_through_feature_nid;
      }

      //We mark the parent id through compared axis to update if exist, unless we have the flag no-update-compared. This flag deny the parent update through compared axis if wikicompare_update_compare_tree was launched for a children computation
      if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
        if (($node->parent_fs_through_compared_nid) && ($update_parent != 'no-update-compared')) {
          $to_update[$node->parent_fs_through_compared_nid] = $node->parent_fs_through_compared_nid;
        }
      }

      //Allow others modules to update others implementations
      foreach (module_implements('wikicompare_update_comparative_table_post') as $module) {
        $function = $module . '_wikicompare_update_comparative_table_post';
        $function($to_update, $node);
      }

    }

    //Fill the res variable the function will return
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

  //Update the parent marked
  if (!empty($to_update)) {
    wikicompare_update_compare_tree('implementation', $to_update);
  }
  return $res;

}

/*
 * Function used to computed the css_class according to the percent value
 */
function find_css_class($percent) {

  if ($percent ==0) {
    $css_class = 'cell-support-no';
  } elseif (($percent > 0) && ($percent < 10)) {
    $css_class = 'cell-support-partial-0-10';
  } elseif (($percent >= 10) && ($percent < 20)) {
    $css_class = 'cell-support-partial-10-20';
  } elseif (($percent >= 20) && ($percent < 30)) {
    $css_class = 'cell-support-partial-20-30';
  } elseif (($percent >= 30) && ($percent < 40)) {
    $css_class = 'cell-support-partial-30-40';
  } elseif (($percent >= 40) && ($percent < 50)) {
    $css_class = 'cell-support-partial-40-50';
  } elseif (($percent >= 50) && ($percent < 60)) {
    $css_class = 'cell-support-partial-50-60';
  } elseif (($percent >= 60) && ($percent < 70)) {
    $css_class = 'cell-support-partial-60-70';
  } elseif (($percent >= 70) && ($percent < 80)) {
    $css_class = 'cell-support-partial-70-80';
  } elseif (($percent >= 80) && ($percent < 90)) {
    $css_class = 'cell-support-partial-80-90';
  } elseif (($percent >= 90) && ($percent < 100)) {
    $css_class = 'cell-support-partial-90-100';
  } elseif (($percent == 100)) {
    $css_class = 'cell-support-complete';
  }

  return $css_class;

}


function wikicompare_flush_caches() {

  //We put the site in maintenance
  $was_in_maintenance = FALSE;
  if (variable_get('maintenance_mode', 0) == 1) {
    $was_in_maintenance = TRUE;
  } else {
    variable_set('maintenance_mode', 1);
  }


  //Delete all data in cache
  db_delete('cache_comparative_table')
    ->execute();

  db_delete('cache_implementation')
    ->execute();

  db_delete('cache_feature')
    ->execute();

  db_delete('cache_compared')
    ->execute();


  //Get all feature data and insert in feature cache table
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'vid', 'vid');
  $query->addField('n', 'title', 'title');
  $query->addField('npf', 'feature_parent_feature_target_id', 'parent_feature_id');
  $query->addField('nt', 'feature_type_value', 'type');
  $query->addField('nw', 'feature_weight_value', 'weight');
  $query->addField('ns', 'feature_state_value', 'state');
  $query->leftjoin('field_revision_feature_parent_feature', 'npf', 'n.vid = npf.revision_id');
  $query->leftjoin('field_revision_feature_type', 'nt', 'n.vid = nt.revision_id');
  $query->leftjoin('field_revision_feature_weight', 'nw', 'n.vid = nw.revision_id');
  $query->leftjoin('field_revision_feature_state', 'ns', 'n.vid = ns.revision_id');
  $query->condition('n.type', 'feature');
  $result = $query->execute();

  $parent_array = array();
  $feature_to_insert = array();
  foreach($result as $record) {
    $feature_to_insert[$record->nid] = array(
      'nid' => $record->nid,
      'vid' => $record->vid,
      'title' => $record->title,
      'parent_feature_id' => $record->parent_feature_id,
      'type' => $record->type,
      'weight' => $record->weight,
      'state' => $record->state,
      'has_children' => 0,
    );

    if ($record->parent_feature_id) {
      $parent_array[$record->parent_feature_id][] = $record->nid;
    }

    

  }

  //Set has_children flag
  foreach ($parent_array as $key => $parent) {
    $feature_to_insert[$key]['has_children'] = 1;
  }

  //Later, we will launch the update_compare_table with only the feature without children
  $feature_without_children = array();
  foreach ($feature_to_insert as $feature) {
    if ($feature['has_children'] == 0) {
      $feature_without_children[$feature['nid']] = $feature['nid'];
    }
  }


  $query = db_insert('cache_feature')->fields(array('nid', 'vid', 'title', 'parent_feature_id', 'type', 'weight', 'state', 'has_children'));
  foreach ($feature_to_insert as $feature) {
    $query->values($feature);
  }
  $query->execute();


  //Get all compared data and insert in compared cache table
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'vid', 'vid');
  $query->addField('n', 'title', 'title');
  $query->addField('npc', 'compared_parent_compared_target_id', 'parent_compared_id');
  $query->leftjoin('field_revision_compared_parent_compared', 'npc', 'n.vid = npc.revision_id');
  $query->condition('n.type', 'compared');

  foreach (module_implements('wikicompare_select_compared') as $module) {
    $function = $module . '_wikicompare_select_compared';
    $function($query);
  }

  $result = $query->execute();

  $parent_array = array();
  $compareds = array();
  foreach($result as $record) {
    $compared = array(
      'nid' => $record->nid,
      'vid' => $record->vid,
      'title' => $record->title,
      'parent_compared_id' => $record->parent_compared_id,
      'has_children' => 0,
    );

    if ($record->parent_compared_id) {
      $parent_array[$record->parent_compared_id][] = $record->nid;
    }

    foreach (module_implements('wikicompare_flush_cache_compared') as $module) {
      $function = $module . '_wikicompare_flush_cache_compared';
      $function($compared, $record);
    }

    $compareds[$compared['nid']] = $compared;

  }

  //Set has_children flag
  foreach ($parent_array as $key => $parent) {
    $compareds[$key]['has_children'] = 1;
  }


  $header = array('nid', 'vid', 'title', 'parent_compared_id', 'has_children');
  foreach (module_implements('wikicompare_cache_compared_fields_header') as $module) {
    $function = $module . '_wikicompare_cache_compared_fields_header';
    $function($header);
  }

  $query = db_insert('cache_compared')->fields($header);
  foreach ($compareds as $compared) {
    $query->values($compared);
  }
  $query->execute();



  //Get all implementation data and insert in implementation cache table
  $query = db_select('node', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'vid', 'vid');
  $query->addField('nf', 'implementation_feature_target_id', 'feature_id');
  $query->addField('nc', 'implementation_compared_target_id', 'compared_id');
  $query->addField('ns', 'implementation_support_value', 'support');
  $query->leftjoin('field_revision_implementation_feature', 'nf', 'n.vid = nf.revision_id');
  $query->leftjoin('field_revision_implementation_compared', 'nc', 'n.vid = nc.revision_id');
  $query->leftjoin('field_revision_implementation_support', 'ns', 'n.vid = ns.revision_id');
  $query->condition('n.type', 'implementation');

  foreach (module_implements('wikicompare_select_implementation') as $module) {
    $function = $module . '_wikicompare_select_implementation';
    $function($query);
  }

  $result = $query->execute();

  $implementations = array();
  foreach($result as $record) {

    if ($record->support == "Supported") {
      $support = 1;
    } else {
      $support = 0;
    }

    $implementation = array(
      'nid' => $record->nid,
      'vid' => $record->vid,
      'feature_id' => $record->feature_id,
      'compared_id' => $record->compared_id,
      'support' => $support,
    );

    foreach (module_implements('wikicompare_flush_cache_implementation') as $module) {
      $function = $module . '_wikicompare_flush_cache_implementation';
      $function($implementation, $record);
    }

    $implementations[$implementation['nid']] = $implementation;


  }

  $header = array('nid', 'vid', 'feature_id', 'compared_id', 'support');
  foreach (module_implements('wikicompare_cache_implementation_fields_header') as $module) {
    $function = $module . '_wikicompare_cache_implementation_fields_header';
    $function($header);
  }

  $query = db_insert('cache_implementation')->fields($header);
  foreach ($implementations as $implementation) {
    $query->values($implementation);
  }
  $query->execute();


  //Update compatative table cache. We begin the update at the base of the feature tree and at the base of the compared tree.
  wikicompare_update_compare_tree('feature', $feature_without_children);

  //We only reactive the website if it wasn't in maintenance at the beginning
  if ($was_in_maintenance == FALSE) {
    variable_set('maintenance_mode', 0);
  }

}


//Function to easily find the implementation id with the compared and the feature
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



?>
