<?php

/**
 * @file
 * Define the main functions, like the recursive function which update the compare tree, the one which refresh the cache and the generic request db function.
 */

require_once drupal_get_path('module', 'wikicompare') . '/wikicompare.module';



/**
 * The main function to update the percent and css_class for each evaluation
 * It'll find all children on product and criterion axis for the ids passed in argument, compute the percent thanks to theses informations and criterion type, and finally if the percent changed it'll update the parents on criterion and product axis.
 * This is a recursive function, which will call itself on parent if the percent computed change in both the criterion and product axis.
 *
 * @param $type
 *   The type of the node to update. Only the evaluation are updated at the end, but specifying product or criterion allow to directly update all their evaluations.
 *
 * @param $nids
 *   The nids of the nodes to update.
 *
 * @param $first
 *   Indicate if this is the first call of the recursive function, because it's only at this first call that we compute the total product. Unrequired argument.
 *
 * @return array
 *   An array containing the evaluations updated by the function.
 */
function wikicompare_update_compare_tree($type, $nids, $first=True) {

  if (!variable_get('wikicompare_computation_status', 1)) {
    return;
  }

  $nodes = array();
  if (!empty($nids)) {

    //Recover the details of the targeted evaluations.
    $query = db_select('cache_evaluation', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'criterion_id', 'fid');
    $query->addField('n', 'product_id', 'cid');
    $query->addField('n', 'support', 'support');
    $query->addField('n', 'criterion_type', 'type');
    $query->addField('n', 'percent', 'old_percent');
    $query->addField('n', 'css_class', 'old_css_class');
    $query->addField('n', 'parent_through_product_id', 'parent_through_product_id');
    $query->addField('n', 'parent_through_criterion_id', 'parent_through_criterion_id');

    //If possible, we search directly through criterion or product id to compute the sql request faster.
    switch ($type) {
      case "evaluation":
        $query->condition('n.nid', $nids, 'IN');
        break;
      case "criterion":
        $query->condition('n.product_has_children', 0); //Only the evaluation without children on product axis need to be updated, because they will update their parent on product axis anyway.
        $query->condition('n.criterion_id', $nids, 'IN');
        break;
      case "product":
        $query->condition('n.criterion_has_children', 0); //Only the evaluation without children on criterion axis need to be updated, because they will update their parent on criterion axis anyway.
        $query->condition('n.product_id', $nids, 'IN');
        break;
    }

    if (module_exists('wikicompare_inherit_product')) {
      //Add the requests to recover the inherited evaluation.
      wikicompare_inherit_product_update_main_query($query);
    }

    $result = $query->execute();

    //Build the variables needed for later computations.
    foreach($result as $record) {
      //Using $record->nid as key allow deduplication of the id in argument array.
      $nodes[$record->nid] = $record;
    }

    //Get the children on criterion axis.
    $through_criterion_childs = array();
    //We don't need the children through criterion axis in case of type = 'product'.
    if ($type != 'product') {
      //Get children evaluation through criterion axis
      $query = db_select('cache_evaluation', 'n');
      $query->addField('n', 'nid', 'nid');
      $query->addField('n', 'criterion_id', 'fid');
      $query->addField('n', 'product_id', 'cid');
      $query->addField('n', 'criterion_parent_id', 'parent_fid');
      $query->addField('n', 'percent', 'percent');
      $query->addField('n', 'criterion_weight', 'weight');
      switch ($type) {
        case "evaluation":
          //We keep only the evaluation of the child criterion node which has the same product than the evaluation. Which mean it's the children evaluation on the criterion axis.
          $query->condition('parent_through_criterion_id', $nids, 'IN');
          break;
        case "criterion":
          $query->condition('n.criterion_parent_id', $nids, 'IN');
          break;
      }

      //Only published criterions are used in their parent computation.
      $query->condition('n.criterion_state', unserialize(WIKICOMPARE_STATE_PUBLISHED), 'in');
      $result = $query->execute();

      //We assign the children evaluation in a array with fid and cid as key so their parents can recover them with fid and cid key.
      $through_criterion_childs = array();
      foreach($result as $record) {
        $through_criterion_childs[$record->parent_fid][$record->cid][$record->nid] = $record;
      }
    }

    //Get the children on criterion axis.
    $through_product_childs = array();
    //We don't need the children through product child in case of type = 'criterion'.
    if ($type != 'criterion') {
      //Get children evaluation through criterion axis.
      $query = db_select('cache_evaluation', 'n');
      $query->addField('n', 'nid', 'nid');
      $query->addField('n', 'criterion_id', 'fid');
      $query->addField('n', 'product_id', 'cid');
      $query->addField('n','product_parent_id', 'parent_cid');
      $query->addField('n', 'percent', 'percent');
      $query->addField('n', 'css_class', 'css_class');

      switch ($type) {
        case "evaluation":
          //We keep only the evaluation of the child product node which has the same criterion than the evaluation. Which mean it's the children evaluation on the product axis.
          $query->condition('parent_through_product_id', $nids, 'IN');
          break;
        case "product":
          $query->condition('n.product_parent_id', $nids, 'IN');
          break;
      }

      //Only published products are used in their parent computation.
      $query->condition('n.product_state', unserialize(WIKICOMPARE_STATE_PUBLISHED), 'in');
      $result = $query->execute();

      //We assign the children evaluation in a array with fid and cid as key so they parent can recover them with fid and cid key
      $through_product_childs = array();
      foreach($result as $record) {
        $through_product_childs[$record->parent_cid][$record->fid][$record->nid] = $record;
      }
    }

    //Assign children to each node to compute.
    foreach($nodes as $node) {
      $node->through_criterion_childs = array();
      if (isset($through_criterion_childs[$node->fid][$node->cid])) {
        //Assign the children thanks to fid and cid key.
        $node->through_criterion_childs = $through_criterion_childs[$node->fid][$node->cid];
      }
      $node->through_product_childs = array();
      if (isset($through_product_childs[$node->cid][$node->fid])) {
        //Assign the children thanks to fid and cid key.
        $node->through_product_childs = $through_product_childs[$node->cid][$node->fid];
      }
    }

    if (module_exists('wikicompare_inherit_product')) {
      //Compute the inherited evaluation if not already done, and get inheriting children.
      wikicompare_inherit_product_update_comparative_table_preparation($nodes, $type, $nids);
    }

  }



  /*
   * Now we'll compute the percent and css_class of each nids in function argument.
   */
  $to_update = array();
  $cache_to_update = array();
  $res = array('products_to_update' => array());
  foreach($nodes as $node) {

    //If any misconfiguration, it'll always return 0.
    $node->new_percent = 0;
    $node->new_css_class = 'cell-support-no';

    //The support field is used only if the evaluation is the deepest in the tree, on both the criterion and product axis.
    if (empty($node->through_criterion_childs) && empty($node->through_product_childs)) {
      if ($node->support == 1) {
        $node->new_percent = 100;
        $node->new_css_class = 'cell-support-complete';
      } else {
        $node->new_percent = 0;
        $node->new_css_class = 'cell-support-no';
      }

      if (module_exists('wikicompare_inherit_product')) {
        //Return the data computed according to the inherited evaluation.
        wikicompare_inherit_product_from_other_support($node);
      }
    //Use the children through criterion axis to compute the percent.
    } else {
      $node = wikicompare_compute_percent($node, $node->through_criterion_childs);
    }

    //If a children through product axis is higher than the value computed, then it'll be used instead.
    foreach($node->through_product_childs as $child) {
      if ($child->percent >= $node->new_percent) {
        $node->new_percent = $child->percent;
        $node->new_css_class = $child->css_class;
      }
    }

    //Update the value computed in database, only if the value has changed.
    if ((($node->old_percent != $node->new_percent) || ($node->old_css_class != $node->new_css_class))) {
        //We regroup all the same percent in a table to update them all at the same time.
      $cache_to_update[$node->new_css_class][$node->new_percent][$node->nid] = $node->nid;

      //Update the parent though criterion and product axis if the value changed.
      if ($node->parent_through_criterion_id) {
        $to_update[$node->parent_through_criterion_id] = $node->parent_through_criterion_id;
      //If their is not parent evaluation on criterion axis, then we need to trigger the total refresh of the product.
      } else {
        $res['products_to_update'][$node->cid] = $node->cid;
      }

      if ($node->parent_through_product_id) {
        $to_update[$node->parent_through_product_id] = $node->parent_through_product_id;
      }

      if (module_exists('wikicompare_inherit_product')) {
        //Add in the evaluation to update the evaluation which inherit the current evaluation.
        wikicompare_inherit_product_update_comparative_table_post($to_update, $node);
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
    $res_from_parents = wikicompare_update_compare_tree('evaluation', $to_update, False);
    //Get the list of the products we need to update from the recursive calls
    $res['products_to_update'] = array_merge($res['products_to_update'], $res_from_parents['products_to_update']);
  }

  //We update the total product only at the first call of the recursive function. The recursive function give their products to update in their return.
  if ($first) {

    if (!empty($res['products_to_update'])) {
      $query = db_select('cache_evaluation', 'n');
      $query->addField('n', 'nid', 'nid');
      $query->addField('n', 'criterion_id', 'criterion_id');
      $query->addField('n', 'product_id', 'product_id');
      $query->addField('n', 'percent', 'percent');
      $query->addField('n', 'criterion_weight', 'weight');
      $query->condition('n.product_id', $res['products_to_update'], 'IN');
      $query->condition('n.criterion_parent_id', NULL);
      //Only published criterions are used in the computation.
      $query->condition('n.criterion_state', unserialize(WIKICOMPARE_STATE_PUBLISHED), 'in');
      $result = $query->execute();

      //We assign the children evaluation in a array with fid and cid as key so their parents can recover them with fid and cid key.
      $products = array();
      foreach($result as $record) {
        $products[$record->product_id][$record->criterion_id] = $record;
      }

      foreach ($products as $product_id => $evaluations) {
        $node = new stdClass;
        $node->type = 'parent-weighted-average';
        $node = wikicompare_compute_percent($node, $evaluations);

        db_update('cache_product')
          ->fields(array(
            'total' => $node->new_percent,
          ))
          ->condition('nid', $product_id)
          ->execute();
      }
    }

    //Refresh suggestions on home page. We place the function here because it should be call each time a product percent change, but we should call it only once per compute call. By proceding like this, we can't target directly the criterion to update.
    wikicompare_refresh_cache_suggest();

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
 * @param $through_criterion_childs
 *   The children of the node.
 *
 * @return $node
 *   The object node completed with the computed value.
 */
function wikicompare_compute_percent($node, $through_criterion_childs) {

    if ($node->type == 'parent-weighted-average') {

      $total = 0;
      $count = 0;
      foreach($through_criterion_childs as $child) {
        $total += $child->percent * $child->weight;
        $count += $child->weight;
      }

      //Security to avoid the divided by 0
      if ($count == 0) {
        $count = 1;
      }

      //Compute the value. We round the percent to 4 because it's the precision in database.
      $node->new_percent = round(($total / $count),4);

    //If the criterion is of type highest percentage, it'll take the maximum value of the children.
    } elseif ($node->type == 'parent-highest-percentage') {
      $node->new_percent = 0;
      $node->new_css_class = 'cell-support-no';
      foreach($through_criterion_childs as $child) {

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

  $types = array('product', 'criterion', 'evaluation');
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
      $query->addField('nf', 'wikicompare_criterion_id_target_id', 'criterion_id');
      $query->addField('nc', 'wikicompare_product_id_target_id', 'product_id');
      $query->addField('ns', 'wikicompare_support_value', 'support');
      $query->leftjoin('field_revision_wikicompare_criterion_id', 'nf', 'n.vid = nf.revision_id');
      $query->leftjoin('field_revision_wikicompare_product_id', 'nc', 'n.vid = nc.revision_id');
      $query->leftjoin('field_revision_wikicompare_support', 'ns', 'n.vid = ns.revision_id');
    }
    if ($type == 'product') {
      $query->addField('nsd', 'wikicompare_short_description_value', 'short_description');
      $query->leftjoin('field_revision_wikicompare_short_description', 'nsd', 'n.vid = nsd.revision_id');
      $query->addField('nc', 'wikicompare_comparable_value', 'comparable');
      $query->leftjoin('field_revision_wikicompare_comparable', 'nc', 'n.vid = nc.revision_id');
    }
    if ($type == 'criterion') {
      $query->addField('nt', 'wikicompare_type_value', 'type');
      $query->addField('nw', 'wikicompare_weight_value', 'weight');
      $query->addField('nsu', 'wikicompare_suggest_value', 'suggest');
      $query->leftjoin('field_revision_wikicompare_type', 'nt', 'n.vid = nt.revision_id');
      $query->leftjoin('field_revision_wikicompare_weight', 'nw', 'n.vid = nw.revision_id');
      $query->leftjoin('field_revision_wikicompare_suggest', 'nsu', 'n.vid = nsu.revision_id');
    }
    $query->condition('n.type', $type);
    //Only the main language nodes are concerned.
    $query->condition('n.language', language_default('language'));
    if (module_exists('wikicompare_inherit_product')) {
      //Search for the inhehrit product specific fields in the flush tables function.
      wikicompare_inherit_product_flush_select($query, $type);
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
        $to_insert[$record->nid]['product_id'] = $record->product_id;
        $to_insert[$record->nid]['criterion_id'] = $record->criterion_id;
      }
      if ($type == 'product') {
        $to_insert[$record->nid]['short_description'] = $record->short_description;
        $to_insert[$record->nid]['comparable'] = $record->comparable;
      }
      if ($type == 'criterion') {
        $to_insert[$record->nid]['type'] = $record->type;
        $to_insert[$record->nid]['weight'] = $record->weight;
        $to_insert[$record->nid]['suggest'] = $record->suggest;
      }
      if (module_exists('wikicompare_inherit_product')) {
        //Prepare the inherit product specific fields in the flush tables function.
        wikicompare_inherit_product_flush_cache($to_insert, $record, $type);
      }
    }

    if ($type != 'evaluation') {
      //Set has_children flag.
      foreach ($parent_array as $pid => $parent) {
        $to_insert[$pid]['has_children'] = 1;
      }

      if ($type == 'criterion') {
        //Later, we will launch the update_compare_table with only the criterion without children, this will be enough to compute the whole tree.
        $criterion_without_children = array();
        foreach ($to_insert as $node) {
          if ($node['has_children'] == 0) {
            $criterion_without_children[$node['nid']] = $node['nid'];
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
      $header[] = 'product_id';
      $header[] = 'criterion_id';
      $header[] = 'support';
    }
    if ($type == 'product') {
      $header[] = 'short_description';
      $header[] = 'comparable';
    }
    if ($type == 'criterion') {
      $header[] = 'type';
      $header[] = 'weight';
      $header[] = 'suggest';
    }
    if (module_exists('wikicompare_inherit_product')) {
      //Add inherit product specific headers.
      wikicompare_inherit_product_cache_fields_header($header, $type);
    }

    //Insert the data into the wikicompare cache table.
    $query = db_insert('cache_' . $type)->fields($header);
    foreach ($to_insert as $values) {
      $query->values($values);
    }
    $query->execute();

  }

  //Update parent_through_product_id and parent_through_criterion_id field in cache_evaluation.
  wikicompare_update_parent_link();

  //Update the structural fields from product and criterion in evaluation.
  if (Database::getConnection()->databaseType() == 'mysql') {
    db_query('UPDATE cache_evaluation n
           INNER JOIN cache_product nc ON n.product_id = nc.nid
           INNER JOIN cache_criterion nf ON n.criterion_id = nf.nid
           SET n.product_parent_id = nc.parent_id, n.product_state = nc.state, n.product_has_children = nc.has_children,
           n.criterion_parent_id = nf.parent_id, n.criterion_state = nf.state, n.criterion_has_children = nf.has_children, n.criterion_type = nf.type, n.criterion_weight = nf.weight');
  } else {
    db_query('UPDATE cache_evaluation
           SET product_parent_id = nc.parent_id, product_state = nc.state, product_has_children = nc.has_children,
           criterion_parent_id = nf.parent_id, criterion_state = nf.state, criterion_has_children = nf.has_children, criterion_type = nf.type, criterion_weight = nf.weight
           FROM cache_evaluation n
           INNER JOIN cache_product nc ON n.product_id = nc.nid
           INNER JOIN cache_criterion nf ON n.criterion_id = nf.nid
           WHERE cache_evaluation.nid = n.nid');
  }

  if (module_exists('wikicompare_inherit_product')) {
    //Update parent_through_inherit_id in cache_evaluation.
    wikicompare_inherit_product_update_parent_link();
  }

  //Update compatative table cache. We begin the update at the base of the criterion tree and at the base of the product tree.
  wikicompare_update_compare_tree('criterion', $criterion_without_children);

  //Refresh the suggestions in home page.
  wikicompare_refresh_cache_suggest();

  //We only reactive the website if it wasn't in maintenance at the beginning.
  if ($was_in_maintenance == FALSE) {
    variable_set('maintenance_mode', 0);
  }

}



/**
 * Function to refresh the cache of the suggestions on home page.
 */
function wikicompare_refresh_cache_suggest() {

  $query = db_delete('cache_wikicompare_suggest');
  $query->execute();

  $criterions = array();
  $percents = array();
  $query = db_select('cache_criterion', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->addField('n', 'suggest', 'suggest');
  $query->addField('e', 'product_id', 'product_id');
  $query->addField('e', 'percent', 'percent');
  $query->leftjoin('cache_evaluation', 'e', 'n.nid = e.criterion_id');
  //TODO Remove this leftjoin by adding comparable in cache_evaluation.
  $query->leftjoin('cache_product', 'p', 'e.product_id = p.nid');
  $query->condition('n.suggest', 0, '!=');
  $or = db_or();
  $or->condition('p.has_children', 0);
  $or->condition('p.comparable', 'always-combine');
  $query->condition($or);
  $result = $query->execute();

  foreach ($result as $record) {
    $criterions[$record->nid][$record->product_id] = $record;
    $percents[$record->nid][$record->product_id] = $record->percent;
  }

  $to_insert = array();
  foreach ($percents as $criterion_id => $products) {
    arsort($products);
    $i = 0;
    foreach ($products as $product_id => $product) {
      $i++;
      //TODO All products which are eligible for suggestion (aka percent in the top 3) should be store here and randomly displayed, even if more than three.
      if ($i <= 3) {
        $record = $criterions[$criterion_id][$product_id];
        $to_insert[] = array(
          'criterion_id' => $record->nid,
          'sequence' => $record->suggest,
          'product_id' => $record->product_id,
          'percent' => $record->percent
        );
      }
    }
  }

  $query = db_insert('cache_wikicompare_suggest')->fields(array('criterion_id', 'sequence', 'product_id', 'percent'));
  foreach ($to_insert as $fields) {
    $query->values($fields);
  }
  $query->execute();

}



/**
 * Function to easily find the evaluation id with the product and the criterion.
 *
 * @param $product_id
 *   The product id of the evaluation to find.
 *
 * @param $criterion_id
 *   The criterion id of the evaluation to find.
 *
 * @return $nid
 *   The id of the evaluation.
 */
function wikicompare_get_evaluation_id($product_id, $criterion_id) {

  $query = db_select('cache_evaluation', 'n');
  $query->addField('n', 'nid', 'nid');
  $query->condition('product_id', $product_id);
  $query->condition('criterion_id', $criterion_id);
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
 *     - product_id: We'll find the evaluations nodes with the products and criterion ids.
 *     - criterion_id: We'll find the evaluations nodes with the products and criterion ids.
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
    if (!isset($db_settings['nids']) && !isset($db_settings['get_comparable_products'])) {
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


  //Evaluation specific fields.
  } else {
    $query->addField('n', 'criterion_id', 'criterion_id');
    $query->addField('n', 'product_id', 'product_id');
    $query->addField('n', 'percent', 'percent');
    $query->addField('n', 'css_class', 'css_class');
    $query->addField('n', 'criterion_weight', 'weight');
  }

  $or = db_or();
  $flag = False;

  //If we didn't used another method to recover the nids.
  if (isset($db_settings['nids']) && !empty($db_settings['nids'])) {
    $or->condition('n.nid', $db_settings['nids'], 'in');
    $flag = True;
  }

  //We can't use isset because the value of parent_id can be null.
  if (array_key_exists('parent_id', $db_settings)) {
    $or->condition('n.parent_id', $db_settings['parent_id']);
    $flag = True;
  }

  if (isset($db_settings['get_comparable_products'])) {
    $or->condition('n.has_children', 0);
    $or->condition('n.comparable', 'always-combine');
    $flag = True;
  }

  if ($flag) {
    $query->condition($or);
  }

  //If the nodes to recover are not specify by the nids in argument, then it means we need to find them thanks to the products and criterions ids.
  if ($type == 'evaluation' && !isset($db_settings['nids'])) {
    $query->condition("n.product_id", $db_settings['product_ids'], 'in');
    $query->condition("n.criterion_id", $db_settings['criterion_ids'], 'in');
  }



  switch ($type) {
    case 'product':
      $query->addField('n', 'short_description', 'short_description');
      $query->addField('n', 'comparable', 'comparable');
      $query->addField('n', 'total', 'total');

      //Add the specified infofields in the object returned.
      if (isset($db_settings['get_infofields'])) {
        foreach ($settings['infofields'] as $infofield) {
          $query->addField('wikicf_' . $infofield['name'] , 'wikicf_' . $infofield['name'] . '_value', 'wikicf_' . $infofield['name']);
          $query->leftjoin('field_revision_wikicf_' . $infofield['name'], 'wikicf_' . $infofield['name'], 'n.vid = wikicf_' . $infofield['name'] . '.revision_id');
        }
      }
//TODO centralize the swith type
      //Filter the returned objects based on the infofields.
      if (isset($db_settings['filters'])) {
        foreach($db_settings['filters'] as $name => $filter) {
          switch ($filter['type']) {
            case 'text':
              if ($name == 'name') {//TODO manage translations
                $query->condition('n.title', '%' . $filter['value'] . '%', 'LIKE');
              } else {
                //If it was in infofields, the join is already done.
                if (!in_array($name, $settings['infofields'])) {
                  $query->join('field_revision_wikicf_' . $name, 'wikicf_' . $name, 'n.vid = wikicf_' . $name . '.revision_id');
                }
                $query->condition('wikicf_' . $name . '.wikicf_' . $name . '_value', '%' . $filter['value'] . '%', 'LIKE');
              }
              break;
            case 'number':
              //If it was in infofields, the join is already done.
              if (!in_array($name, $settings['infofields'])) {
                $query->join('field_revision_wikicf_' . $name, 'wikicf_' . $name, 'n.vid = wikicf_' . $name . '.revision_id');
              }
              $query->condition('wikicf_' . $name . '.wikicf_' . $name . '_value', $filter['min'], '>=');
              $query->condition('wikicf_' . $name . '.wikicf_' . $name . '_value', $filter['max'], '<=');
              break;
            case 'select':
              //If it was in infofields, the join is already done.
              if (!in_array($name, $settings['infofields'])) {
                $query->join('field_revision_wikicf_' . $name, 'wikicf_' . $name, 'n.vid = wikicf_' . $name . '.revision_id');
              }
              $query->condition('wikicf_' . $name . '.wikicf_' . $name . '_value', $filter['value']);
              break;
            case 'checkboxes':
              //If it was in infofields, the join is already done.
              if (!in_array($name, $settings['infofields'])) {
                $query->join('field_revision_wikicf_' . $name, 'wikicf_' . $name, 'n.vid = wikicf_' . $name . '.revision_id');
              }
              $query->condition('wikicf_' . $name . '.wikicf_' . $name . '_value', $filter['values'], 'IN');
              break;
          }
        }
      }
      break;
    case 'criterion':
      $query->addField('n', 'type', 'type');
      $query->addField('n', 'weight', 'weight');
      $query->addField('n', 'suggest', 'suggest');
      break;
  }

  //If fastaction mode is triggered, then we need to recover all the revision of the nodes to test if the user is the author of all the revisions. Otherwise, he will not be able to fastedit the node.
  if (isset($settings['fastaction'])) {
    if ($settings['fastaction'] == 1) {
      $query->addField('r', 'uid', 'uid');
      $query->leftjoin('node_revision', 'r', 'n.nid = r.nid');
    }
  }

  if (module_exists('wikicompare_inherit_product')) {
    //Add inherit product specific fields.
    wikicompare_inherit_product_request_db($query, $type);
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
  $profile_criterions = array();
  foreach ($result as $record) {

    //We round the percent with a precision of 1.
    foreach (array('percent', 'total') as $field) {
      if (isset($record->$field)) {
        $record->$field = round($record->$field, 1);
      }
    }

    //Start building the ressource which will be returned for this node.
    $node_array = array(
      //All data returned by the request are stored in this object.
      'data' => $record,
      'children' => array(),
    );

    if (module_exists('wikicompare_profiles')) {
      //Recover all profile_criterions in an array to use them later.
      wikicompare_profiles_request_db_build($node_array, $profile_criterions, $record, $type);
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

    //Assign the node_array to $res with the nid as key, except it's an evaluation we found thanks to the product and criterion ids.
    if ($type != 'evaluation' || isset($db_settings['nids'])) {
      $res[$record->nid] = $node_array;
    } else {
      $res[$record->criterion_id][$record->product_id] = $node_array;
    }

  }

  if (module_exists('wikicompare_profiles')) {
    //Assign node criterions to the $res. We couldn't do it  while we were parsing the records.
    wikicompare_profiles_request_db_after($res, $profile_criterions);
  }

  return $res;

}

?>
