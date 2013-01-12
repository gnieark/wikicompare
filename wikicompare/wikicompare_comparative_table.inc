<?php
/**
 * @file
 * Building the compare table page
 */

//For ajax, informations from http://www.angrydonuts.com/drupal-7-advanced-ajax-tips-and-tricks was really helpfull

/**
 * Build the compare table form
 *
 * @return
 *   A form array set for theming
 */
function wikicompare_comparative_table($form_state) {

  drupal_add_js('/misc/ajax.js');
  drupal_add_js('/misc/progress.js');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');


  // Identify that the elements in 'example_items' are a collection, to
  // prevent Form API from flattening the array when submitted.
//  $form['compared_items']['#tree'] = TRUE;


//  $compared_ids = array(4,8,12);

  //Inform them of the compared item which should be displayed in the table
//  $form['#compared_ids'] = $compared_ids;

  //Find all the compared item and the data required to rebuild the tree in the theme
  $query = db_select('cache_compared', 's');
  $query->addField('s', 'nid', 'nid');
  $query->addField('s', 'title', 'title');
//  $query->addField('s', 'parent_compared_id', 'pid');
  $query->addField('s', 'has_children', 'has_children');
  $query->condition("s.parent_compared_id", NULL);
  $result = $query->execute();

  // Iterate through each database result
  foreach ($result as $record) {

    //Insert each compared item in the array
    $form['compared_items'][$record->nid] = array(

      // We'll use a form element of type '#markup' to display the item name.
      'title' => array(
        '#markup' => check_plain($record->title),
      ),

    );

    //We set the parent id in the #parents field so we can rebuild the tree later
//    $form['compared_items'][$record->nid]['#parents'] = array('id' => $record->pid);
    //We also set the nid so we can use it later
    $form['compared_items'][$record->nid]['#id'] = $record->nid;
    $form['compared_items'][$record->nid]['#has_children'] = $record->has_children;

  }



  //Find all the features which should be displayed in the table
  $query = db_select('cache_feature', 'f');
  $query->addField('f', 'nid', 'nid');
  $query->addField('f', 'title', 'title');
  $query->addField('f', 'type', 'type');
//  $query->addField('f', 'parent_feature_id', 'pid');
  $query->addField('f', 'weight', 'weight');
  $query->addField('f', 'has_children', 'has_children');
  $query->condition('f.parent_feature_id', NULL);
  $query->condition('f.state', 'Published', '=');
  $features = $query->execute();



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
//    $form['feature_items'][$item->nid]['#parents'] = array('id' => $item->pid);
    //We set the nid so we can use it later
    $form['feature_items'][$item->nid]['#id'] = $item->nid;
    //We set the type so we can adapt the line to the type later
    $form['feature_items'][$item->nid]['#type'] = $item->type;
    //We create the array now in case there is no implementations
    $form['feature_items'][$item->nid]['#has_children'] = $item->has_children;


    //We set the feature ids in this array so we can build the implementation database query later
//    $feature_ids[] = (int) $item->nid;


  }
/*
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
*/

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

//  drupal_add_js('/misc/ajax.js');
//  drupal_add_js('/misc/progress.js');
//  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  $form = $variables['form'];


/*
  //Set each item in the array of his parent. This is a preparation of the rebuild of the tree
  $list_parent_compared = array();
  foreach (element_children($form['compared_items']) as $a){
    if ($form['compared_items'][$a]['#parents']['id'] == NULL) {
      $list_parent_compared[0][] = $form['compared_items'][$a]; //If the item has no parent, we assign it at the array with key 0, considered as root of the tree
    } else {
      $list_parent_compared[$form['compared_items'][$a]['#parents']['id']][] = $form['compared_items'][$a]; //We assign the item in the array of his parent id
    }
  }
*/
  //Call the recursive function which will rebuild the tree. Return an array which has the good format for an item list theme
//  $compared_items = build_list_compared($list_parent_compared, $list_parent_compared[0]); 

  $compareds = array();
  foreach (element_children($form['compared_items']) as $cid) {
    $compareds[$cid] = array(
      'nid' => $cid,
      'title' => $form['compared_items'][$cid]['title'],
      'has_children' => $form['compared_items'][$cid]['#has_children'],
    );
  }

  $compared_item_list_data = get_compared_item_list($compareds);


  //Insert the item list of the compared in the page
  $output = theme_item_list(array('items' => $compared_item_list_data, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));


  $featuress = array();
  foreach (element_children($form['feature_items']) as $fid) {
    $features[$fid] = array(
      'nid' => $fid,
      'title' => $form['feature_items'][$fid]['title'],
      'weight' => $form['feature_items'][$fid]['weight'],
      'type' => $form['feature_items'][$fid]['#type'],
      'has_children' => $form['feature_items'][$fid]['#has_children'],
      'implementations' => array(),
    );
  }

  $feature_rows = get_feature_rows($features);


  //Set each item in the array of his parent. This is a preparation of the rebuild of the tree
/*  $list_parent_feature = array();
  foreach (element_children($form['feature_items']) as $a){
    if ($form['feature_items'][$a]['#parents']['id'] == NULL) {
      $list_parent_feature[0][] = $form['feature_items'][$a]; //If the item has no parent, we assign it at the array with key 0, considered as root of the tree
    } else {
      $list_parent_feature[$form['feature_items'][$a]['#parents']['id']][] = $form['feature_items'][$a]; //We assign the item in the array of his parent id
    }
  }
*/
  //Call the recursive function which will return the rows of the table. Use the same kind of code than the one which rebuild tree so we have the children rows under the parent rows
//  $table_rows = build_rows_feature($form['feature_items'], $list_parent_feature, $list_parent_feature[0], -1);

  //Will return the header of the table, with one column for each compared item in the table
  $header = array(t('Features'));
/*  foreach($form['#compared_ids'] as $id) {
    $header[] = drupal_render($form['compared_items'][$id]['title']);
  }*/

  //Insert the comparative table in the page

  $output .= '<table id="comparative_table">';
  $output .= '<thead>';
  $output .= '<tr id="comparative_table_header">';
  $output .= '<th>' . t('Features') . '</th>';
  $output .= '</tr>';
  $output .= '</thead>';
  $output .= '<tbody>';
  foreach ($feature_rows as $row) {
    $output .= '<tr id="'. $row['id'] . '" class="feature_row">';
    $output .= $row['data'][0];
    $output .= '</tr>';
//    $output .= '<div id="feature_children_' . $row['id'] . '"></div>';
  }
  $output .= '</tbody>';
  $output .= '</table>';

  return $output;
}



function get_compared_ajax_response($type = 'ajax', $cid, $action) {

  if ($type == 'ajax') {

    if ($action == 'expand') {

      $query = db_select('cache_compared', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->addField('s', 'has_children', 'has_children');
      $query->condition("s.parent_compared_id", $cid);
      $result = $query->execute();

      $compareds = array();
      foreach ($result as $record) {

        $compareds[$record->nid] = array(
          'nid' => $record->nid,
          'title' => array(
            '#markup' => check_plain($record->title),
          ),
          'has_children' => $record->has_children,
        );

      }

      $compared_item_list_data = get_compared_item_list($compareds);

      $output = theme_item_list(array('items' => $compared_item_list_data, 'type' => 'ul', 'attributes' => array()));
//$output = 'Test';
/*
      $link = array(
        '#type' => 'link',
        '#title' => 'Link',
        // Note the /nojs portion of the href - if javascript is enabled,
        // this part will be stripped from the path before it is called.
        '#href' => 'get_compared_ajax_callback/nojs/' . $cid . '/collapse',
        '#id' => 'compared_backlink_' . $cid,
        '#ajax' => array(
//          'wrapper' => 'compared_children_' . $cid,
//          'method' => 'html',
          'effect' => 'slide',
        ),
      );
*/
//$output = 'Test';
      $commands = array();
      $commands[] = ajax_command_html('#compared_children_' . $cid, $output);

//      $commands[] = ajax_command_append('#compared_item_' . $cid, drupal_render($link));

//      $commands[] = ajax_command_replace('#compared_link_' . $cid, drupal_render($link));

//        $commands[] = ajax_command_invoke('<a id="compared_link_' . $cid . '"', 'replaceAll', array('<a id="compared_backlink_' . $cid . '">'));

//      $commands[] = ajax_command_invoke('<a id="compared_link_' . $cid . '" href="/get_compared_ajax_callback/nojs/' . $cid . '/expand"  class="ajax-processed">', 'replaceAll', array('<a id="compared_link_' . $cid . '" class=ajax-processed href="get_compared_ajax_callback/nojs/' . $cid . '/collapse">'));
//*      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('href', 'get_compared_ajax_callback/nojs/' . $cid . '/collapse'));
//*      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'removeClass', array('ajax-processed'));

//      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('id', 'compared_backlink_' . $cid));

//*      $commands[] = ajax_command_invoke('#compared_item_' . $cid, 'addClass', array('expanded'));

      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;
//      ajax_deliver($page);

    } elseif ($action == 'collapse') {

      $commands = array();
/*      $commands[] = ajax_command_invoke('#compared_children_' . $cid, 'slideUp');
//      $commands[] = ajax_command_replace('#compared_children_' . $cid, '<div id="compared_children_' . $cid . '"></div>');
      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('href', 'get_compared_ajax_callback/nojs/' . $cid . '/expand'));
      $commands[] = ajax_command_invoke('#compared_item_' . $cid, 'removeClass', array('expanded'));*/

      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  }
  else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }
}


function get_compared_item_list($compareds){

  $compared_items = array();
  foreach ($compareds as $compared){

    if ($compared['has_children'] == 1){
      $title = array(
        '#type' => 'link',
        '#title' => drupal_render($compared['title']),
        // Note the /nojs portion of the href - if javascript is enabled,
        // this part will be stripped from the path before it is called.
        '#href' => 'get_compared_ajax_callback/nojs/' . $compared['nid'] . '/expand',
        '#id' => 'compared_link_' . $compared['nid'],
        '#attributes' => array(
          'class' => array('compared_link'),
        ),
//        '#ajax' => array(
//            'callback' => 'get_compared_ajax_callback_test',
//          'wrapper' => 'compared_children_' . $compared['nid'],
//          'method' => 'html',
//          'effect' => 'slide',
//        ),
        '#suffix' => '<div id="compared_children_' . $compared['nid'] . '"></div>'

      );
    } else {
      $title = $compared['title'];
    }

    $checkbox = theme_checkbox(array('element' => array(
      '#title' => $compared['nid'],
      '#id' => 'compared_checkbox_' . $compared['nid'],
      '#attributes' => array(
        'class' => array('compared_checkbox'),
      ),

/*      '#ajax' => array(
        'callback' => 'compared_checkbox_selected',
        'wrapper' => 'compared_item_' . $compared['nid'],
      ),*/
    )));

    $checkbox_link = array(
      '#type' => 'link',
      '#title' => 'toggle',
      // Note the /nojs portion of the href - if javascript is enabled,
      // this part will be stripped from the path before it is called.
      '#href' => 'toogle_compared_checkbox_ajax_callback/nojs/' . $compared['nid'] . '/show',
      '#id' => 'compared_checkbox_link_' . $compared['nid'],
      '#attributes' => array(
        'class' => array('compared_checkbox_link'),
      )
    );


    //Content of the list, a checkbox with the name of the compared item
    $compared_items[$compared['nid']]['id'] = 'compared_item_' . $compared['nid'];
    $compared_items[$compared['nid']]['data'] = $checkbox . ' ' . drupal_render($checkbox_link) . drupal_render($title);


  }

  return $compared_items;

}



function get_feature_ajax_response($type = 'ajax', $fid, $action) {

  if ($type == 'ajax') {

    if ($action == 'expand') {

      $query = db_select('cache_feature', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->addField('s', 'weight', 'weight');
      $query->addField('s', 'type', 'type');
      $query->addField('s', 'has_children', 'has_children');
      $query->condition("s.parent_feature_id", $fid);
      $result = $query->execute();

      $features = array();
      foreach ($result as $record) {

        $features[$record->nid] = array(
          'nid' => $record->nid,
          'title' => array(
            '#markup' => check_plain($record->title),
          ),
          'weight' => array(
            '#markup' => check_plain($record->weight),
          ),
          'type' => $record->type,
          'has_children' => $record->has_children,
          'implementations' => array(),
        );

      }

      if (!empty($_POST['compared_ids'])) {
        $query = db_select('cache_implementation', 'i');
        $query->addField('i', 'nid', 'nid');
        $query->addField('i', 'compared_id', 'compared_id');
        $query->addField('ctc', 'percent', 'percent');
        $query->addField('ctc', 'css_class', 'css_class');
        $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
        $query->condition("i.compared_id", $_POST['compared_ids'], 'in');
        $query->condition("i.feature_id", $fid);

        $result = $query->execute();

        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->compared_id] = $record;
        }
        foreach ($features as $key => $feature) {
          foreach ($_POST['compared_ids'] as $compared_id) {
            $features[$key]['implementations'][] = $implementations[$compared_id[0]];
          }
        }
      }

      $feature_row_data = get_feature_rows($features);
      $output = '';

      foreach ($feature_row_data as $feature) {

        $output .= '<tr id="'. $feature['id'] . '" class="feature_row feature_children_' . $fid . '" style="display:none;">';

        foreach ($feature['data'] as $data) {
          $output .= $data;
        }

        $output .= '</tr>';

//        $output .= '<div id="feature_children_' . $fid . '"></div>';

      }
dpm($output);
//$output = 'Test';
/*
      $link = array(
        '#type' => 'link',
        '#title' => 'Link',
        // Note the /nojs portion of the href - if javascript is enabled,
        // this part will be stripped from the path before it is called.
        '#href' => 'get_compared_ajax_callback/nojs/' . $cid . '/collapse',
        '#id' => 'compared_backlink_' . $cid,
        '#ajax' => array(
//          'wrapper' => 'compared_children_' . $cid,
//          'method' => 'html',
          'effect' => 'slide',
        ),
      );
*/
//$output = 'Test';
      $commands = array();
      $commands[] = ajax_command_after('#feature_row_' . $fid, $output);

//      $commands[] = ajax_command_append('#compared_item_' . $cid, drupal_render($link));

//      $commands[] = ajax_command_replace('#compared_link_' . $cid, drupal_render($link));

//        $commands[] = ajax_command_invoke('<a id="compared_link_' . $cid . '"', 'replaceAll', array('<a id="compared_backlink_' . $cid . '">'));

//      $commands[] = ajax_command_invoke('<a id="compared_link_' . $cid . '" href="/get_compared_ajax_callback/nojs/' . $cid . '/expand"  class="ajax-processed">', 'replaceAll', array('<a id="compared_link_' . $cid . '" class=ajax-processed href="get_compared_ajax_callback/nojs/' . $cid . '/collapse">'));
//*      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('href', 'get_compared_ajax_callback/nojs/' . $cid . '/collapse'));
//*      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'removeClass', array('ajax-processed'));

//      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('id', 'compared_backlink_' . $cid));

//*      $commands[] = ajax_command_invoke('#compared_item_' . $cid, 'addClass', array('expanded'));
dpm($commands);
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;
//      ajax_deliver($page);

    } elseif ($action == 'collapse') {

      $commands = array();
/*      $commands[] = ajax_command_invoke('#compared_children_' . $cid, 'slideUp');
//      $commands[] = ajax_command_replace('#compared_children_' . $cid, '<div id="compared_children_' . $cid . '"></div>');
      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('href', 'get_compared_ajax_callback/nojs/' . $cid . '/expand'));
      $commands[] = ajax_command_invoke('#compared_item_' . $cid, 'removeClass', array('expanded'));*/

      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }
}



function get_feature_rows($features){

  $rows = array();
  foreach ($features as $feature){

    if ($feature['has_children'] == 1){
      $title = array(
        '#type' => 'link',
        '#title' => drupal_render($feature['title']),
        // Note the /nojs portion of the href - if javascript is enabled,
        // this part will be stripped from the path before it is called.
        '#href' => 'get_feature_ajax_callback/nojs/' . $feature['nid'] . '/expand',
        '#id' => 'feature_link_' . $feature['nid'],
        '#attributes' => array(
          'class' => array('feature_link'),
        ),
//        '#ajax' => array(
//            'callback' => 'get_compared_ajax_callback_test',
//          'wrapper' => 'compared_children_' . $compared['nid'],
//          'method' => 'html',
//          'effect' => 'slide',
//        ),

      );
    } else {
      $title = $feature['title'];
    }

    $rows[$feature['nid']]['id'] = 'feature_row_' . $feature['nid'];
    $rows[$feature['nid']]['data'][0] = '<td>' . drupal_render($title)  . '<br/> Weight : ' .  drupal_render($feature['weight']) . '<br/> Type : ' . $feature['type'] . '</td>';
    foreach ($feature['implementations'] as $implementation) {
      $rows[$feature['nid']]['data'][] = '<td class="' . $implementation->css_class . ' implementation_compared_' . $implementation->compared_id . ' implementation_feature_' . $feature['nid'] . '">' . $implementation->nid . '<br/>' . $implementation->percent . '%</td>';
    }
//    $rows[$feature['nid']]['class'] = array('feature_children_' . $feature['nid']);


  }

  return $rows;

}

function toggle_compared_checkbox_ajax_response($type='ajax', $cid, $action){
  if ($type == 'ajax') {

    if ($action == 'show') {


      $query = db_select('cache_compared', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->condition("s.nid", $cid);
      $result = $query->execute();

      foreach ($result as $record) {
        $compared = $record;
      }

      $header = '<th id="header_compared_' . $cid . '" class="header_compared" style="display:none;">' . $compared->title . '</th>';

      if (!empty($_POST['feature_ids'])) {
        $query = db_select('cache_implementation', 'i');
        $query->addField('i', 'nid', 'nid');
        $query->addField('i', 'feature_id', 'feature_id');
        $query->addField('ctc', 'percent', 'percent');
        $query->addField('ctc', 'css_class', 'css_class');
        $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
        $query->condition("i.compared_id", $cid);
        $query->condition("i.feature_id", $_POST['feature_ids'], 'in');
        $result = $query->execute();

        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->feature_id] = '<td class="' . $record->css_class . ' implementation_compared_' . $cid . ' implementation_feature_' . $record->feature_id . '" style="display:none;">' . $record->nid . '<br/>' . $record->percent . '%</td>';
        }
      }




      $commands = array();
      $commands[] = ajax_command_append('#comparative_table_header', $header);

      foreach ($implementations as $key => $implementation) {
        $commands[] = ajax_command_append('#feature_row_' . $key, $implementation);
      }

      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    } elseif ($action == 'hide') {

      $commands = array();
/*      $commands[] = ajax_command_invoke('#compared_children_' . $cid, 'slideUp');
//      $commands[] = ajax_command_replace('#compared_children_' . $cid, '<div id="compared_children_' . $cid . '"></div>');
      $commands[] = ajax_command_invoke('#compared_link_' . $cid, 'attr', array('href', 'get_compared_ajax_callback/nojs/' . $cid . '/expand'));
      $commands[] = ajax_command_invoke('#compared_item_' . $cid, 'removeClass', array('expanded'));*/

      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }


}
/*
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
*/

?>
