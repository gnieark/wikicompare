<?php
/**
 * @file
 * Building the compare table page
 */

/**
 * Build the compare table form
 *
 * @return
 *   A form array set for theming
 */
function wikicompare_comparative_table($form_state) {
  // Identify that the elements in 'example_items' are a collection, to
  // prevent Form API from flattening the array when submitted.
  $form['compared_items']['#tree'] = TRUE;


  $compared_ids = array(4,8,12);

  //Inform them of the compared item which should be displayed in the table
  $form['#compared_ids'] = $compared_ids;

  //Find all the compared item and the data required to rebuild the tree in the theme
  $query = db_select('cache_compared', 's');
  $query->addField('s', 'nid', 'nid');
  $query->addField('s', 'title', 'title');
  $query->addField('s', 'parent_compared_id', 'pid');
  $compared = $query->execute();



  //Find all the features which should be displayed in the table
  $query = db_select('cache_feature', 'f');
  $query->addField('f', 'nid', 'nid');
  $query->addField('f', 'title', 'title');
  $query->addField('f', 'type', 'type');
  $query->addField('f', 'parent_feature_id', 'pid');
  $query->addField('f', 'weight', 'weight');
  $query->condition('f.state', 'Published', '=');
  $features = $query->execute();




  // Iterate through each database result
  foreach ($compared as $item) {

    //Insert each compared item in the array
    $form['compared_items'][$item->nid] = array(

      // We'll use a form element of type '#markup' to display the item name.
      'title' => array(
        '#markup' => check_plain($item->title),
      ),

    );

    //We set the parent id in the #parents field so we can rebuild the tree later
    $form['compared_items'][$item->nid]['#parents'] = array('id' => $item->pid);
    //We also set the nid so we can use it later
    $form['compared_items'][$item->nid]['#id'] = $item->nid;

  }


  $feature_ids = array();
  // Iterate through each database result
  foreach ($features as $item) {

    //Insert each feature item in the array
    $form['feature_items'][$item->nid] = array(

      // We'll use a form element of type '#markup' to display the item name.
      'title' => array(
        '#markup' => check_plain($item->title),
      ),
      'weight' => array(
        '#markup' => check_plain($item->weight),
      ),
    );

    //We set the parent id in the #parents field so we can rebuild the tree later
    $form['feature_items'][$item->nid]['#parents'] = array('id' => $item->pid);
    //We set the nid so we can use it later
    $form['feature_items'][$item->nid]['#id'] = $item->nid;
    //We set the type so we can adapt the line to the type later
    $form['feature_items'][$item->nid]['#type'] = $item->type;
    //We create the array now in case there is no implementations
    $form['feature_items'][$item->nid]['#implementations'] = array();


    //We set the feature ids in this array so we can build the implementation database query later
    $feature_ids[] = (int) $item->nid;


  }

  //We get all implementation which have the feature and compared item above  
  $query = db_select('cache_implementation', 'fs');
  $query->addField('fs', 'nid', 'nid');
  $query->addField('fs', 'compared_id', 'cid');
  $query->addField('fs', 'feature_id', 'fid');
  $query->addField('fs', 'support', 'support');
  $query->addField('ctc', 'nid', 'cache_nid');
  $query->addField('ctc', 'percent', 'percent');
  $query->addField('ctc', 'css_class', 'css_class');
  $query->leftjoin('cache_comparative_table', 'ctc', 'fs.nid = ctc.nid');
  $query->where("fs.compared_id IN (" . implode(',',$compared_ids) . ")");
  $query->where("fs.feature_id IN (" . implode(',',$feature_ids) . ")");
  $implementations = $query->execute();



  //Then we set the implementation in the corresponding feature array, with the compared nid as key
  foreach ($implementations as $item) {

    //If there is no cache for the implementation, we call the function to create it and then recover the value.
    if(!$item->cache_nid) {
      $res = wikicompare_update_compare_tree(array($item->nid), 'update');
      $item->percent = $res[$item->nid]['percent'];
      $item->css_class = $res[$item->nid]['css_class'];
    }

    $form['feature_items'][$item->fid]['#implementations'][$item->cid] = array(

      'title' => array(
        '#markup' => check_plain($item->nid),
      ),
      'percent' => array(
        '#markup' => check_plain($item->percent),
      ),
      'css_class' => array(
        '#markup' => check_plain($item->css_class),
      ),
      'support' => array(
        '#markup' => check_plain($item->support),
      ),
    );

  };


  return $form;

}


/**
 * Theme callback for the wikicompare_comparative_table form
 *
 * The theme callback will format the $form data structure into a table and
 * add our tabledrag functionality.  (Note that drupal_add_tabledrag should be
 * called from the theme layer, and not from a form declaration.  This helps
 * keep template files clean and readable, and prevents tabledrag.js from
 * being added twice accidently.
 *
 * @return
 *   The rendered tabledrag form
 */


function theme_wikicompare_comparative_table($variables) {
  $form = $variables['form'];

  //Set each item in the array of his parent. This is a preparation of the rebuild of the tree
  $list_parent_compared = array();
  foreach (element_children($form['compared_items']) as $a){
    if ($form['compared_items'][$a]['#parents']['id'] == NULL) {
      $list_parent_compared[0][] = $form['compared_items'][$a]; //If the item has no parent, we assign it at the array with key 0, considered as root of the tree
    } else {
      $list_parent_compared[$form['compared_items'][$a]['#parents']['id']][] = $form['compared_items'][$a]; //We assign the item in the array of his parent id
    }
  }

  //Call the recursive function which will rebuild the tree. Return an array which has the good format for an item list theme
  $compared_items = build_list_compared($list_parent_compared, $list_parent_compared[0]); 

  //Insert the item list of the compared in the page
  $output = theme_item_list(array('items' => $compared_items, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));



  //Set each item in the array of his parent. This is a preparation of the rebuild of the tree
  $list_parent_feature = array();
  foreach (element_children($form['feature_items']) as $a){
    if ($form['feature_items'][$a]['#parents']['id'] == NULL) {
      $list_parent_feature[0][] = $form['feature_items'][$a]; //If the item has no parent, we assign it at the array with key 0, considered as root of the tree
    } else {
      $list_parent_feature[$form['feature_items'][$a]['#parents']['id']][] = $form['feature_items'][$a]; //We assign the item in the array of his parent id
    }
  }

  //Call the recursive function which will return the rows of the table. Use the same kind of code than the one which rebuild tree so we have the children rows under the parent rows
  $table_rows = build_rows_feature($form['feature_items'], $list_parent_feature, $list_parent_feature[0], -1);

  //Will return the header of the table, with one column for each compared item in the table
  $header = array(t('Features'));
  foreach($form['#compared_ids'] as $id) {
    $header[] = drupal_render($form['compared_items'][$id]['title']);
  }

  //Insert the comparative table in the page
  $output .= theme('table', array('header' => $header, 'rows' => $table_rows));


  return $output;
}



function build_list_compared(&$list, $parent){
    $items = array();
    //Will insert an item for each children of the array
    foreach ($parent as $child){
        $array = array();
        //Content of the list, a checkbox with the name of the compared item
        $array['data'] = theme_checkbox(array('element' => array('#title' => $child['#id']))) . ' ' . drupal_render($child['title']);
        //Check if the item has children
        if(isset($list[$child['#id']])){
            //If yes, call the recursive function to add children to the array
            $array['children'] = build_list_compared($list, $list[$child['#id']]);
        }
        //Add the children to the array
        $items[] = $array;
    }
    return $items;
}

function build_rows_feature($support_array, &$list, $parent, $depth){
    $rows = array();
    //We need to know the depth of the recursivity to know how many indent set
    $depth = $depth + 1;
    //Will add rows for each children of the arry
    foreach ($parent as $child){
        $array = array(
          'data' => array()
        );
        //In the first column, add the feature name with indentation corresponding of the depth
        $array['data'][] = theme('indentation', array('size' => $depth)) . drupal_render($child['title']) . '<br/> Weight : ' .  drupal_render($child['weight']) . '<br/> Type : ' . $child['#type'];
        //Then add as many columns as the number of compared item in the table.
        foreach($child['#implementations'] as $implementation){
          $array['data'][] = drupal_render($implementation['title']) . '<br/>' . drupal_render($implementation['percent']) . '%<br/> CSS : ' . drupal_render($implementation['css_class']) . '<br/> Support :  ' . drupal_render($implementation['support']);
        }
        //Add the parent row in the returned array
        $rows[] = $array;
        //Check if the item has children
        if(isset($list[$child['#id']])){
            //If yes, call the recursive function to add children to the returned array
            $child_rows = build_rows_feature($support_array, $list, $list[$child['#id']], $depth);
            //Add children to the returned array
            foreach($child_rows as $child_row){
               $rows[] = $child_row;
            }
        }
    }
    return $rows;
}


?>
