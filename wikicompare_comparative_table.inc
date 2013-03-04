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

  //Add the javascript files used in the comparative_table
  drupal_add_js('/misc/ajax.js');
  drupal_add_js('/misc/progress.js');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  //Find all the compared on the first level of the tree
  $query = db_select('cache_compared', 's');
  $query->addField('s', 'nid', 'nid');
  $query->addField('s', 'title', 'title');
  $query->addField('s', 'has_children', 'has_children');
  $query->condition("s.parent_compared_id", NULL);
  $result = $query->execute();

  //Insert the compared in the form array to retrieve them in the theme
  foreach ($result as $record) {
    $form['compared_items'][$record->nid] = array(
      'title' => array(
        '#markup' => check_plain($record->title),
      ),
    );
    $form['compared_items'][$record->nid]['#id'] = $record->nid;
    $form['compared_items'][$record->nid]['#has_children'] = $record->has_children;
  }



  //Find all the features on the first level of the tree
  $query = db_select('cache_feature', 'f');
  $query->addField('f', 'nid', 'nid');
  $query->addField('f', 'title', 'title');
  $query->addField('f', 'type', 'type');
  $query->addField('f', 'weight', 'weight');
  $query->addField('f', 'parent_feature_id', 'parent_id');
  $query->addField('f', 'has_children', 'has_children');
  $query->condition('f.parent_feature_id', NULL);
  $query->condition('f.state', 'Published', '=');
  $features = $query->execute();

  //Insert the feature in the form array to retrieve them in the theme
  foreach ($features as $item) {

    $form['#feature_items'][$item->nid]['data'] = $item;
    $form['#feature_items'][$item->nid]['children'] = array();
/*
array(
      'title' => array(
        '#markup' => check_plain($item->title),
      ),
      'weight' => array(
        '#markup' => check_plain($item->weight),
      ),
    );
    $form['feature_items'][$item->nid]['#id'] = $item->nid;
    $form['feature_items'][$item->nid]['#type'] = $item->type;
    $form['feature_items'][$item->nid]['#has_children'] = $item->has_children;*/
  }

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

  //Prepare the array to use as argument for the item list building function.
  $compareds = array();
  //element_children is used to avoid the children beginning by # which are inserted by drupal in $form
  foreach (element_children($form['compared_items']) as $cid) {
    $compareds[$cid] = array(
      'nid' => $cid,
      'title' => $form['compared_items'][$cid]['title'],
      'has_children' => $form['compared_items'][$cid]['#has_children'],
    );
  }

  //Building the data for the item list
  $item_list_data = get_item_list($compareds, 'compared', 'compared_main_table', 0);


  //Render the item list
  $output = theme_item_list(array('items' => $item_list_data, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));

  //Add the link to open the select feature popup
  $select_feature_link = array(
    'text' => 'Select features',
    'title' => 'Select features',
    'selector' => 'dialog-content',
    'path' => 'get_select_feature_dialog_callback',
    'id' => 'select_feature_link',

  );
  $output .= '<p>' . theme('simple_dialog_link', $select_feature_link) . '</p>';
  

  //Add the compute button
  $compute_link = array(
    '#type' => 'link',
    '#title' => 'Compute',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'compute_comparative_table_callback/nojs',
    '#id' => 'compute_table_link',
    '#attributes' => array(
      'style' => 'display:none',
    ),
  );
  $output .= '<p><input id="compute_table_button" type="submit" value="Compute table" class="button"/>' . drupal_render($compute_link) . '</p>';
  
  //Prepare the array to use as argument for the table row building function.
  $features = array();
  //element_children is used to avoid the children beginning by # which are inserted by drupal in $form
dpm($form);
/*  foreach (element_children($form['feature_items']) as $fid) {
    $features[$fid] = array(
      'nid' => $fid,
      'title' => $form['feature_items'][$fid]['title'],
      'weight' => $form['feature_items'][$fid]['weight'],
      'type' => $form['feature_items'][$fid]['#type'],
      'has_children' => $form['feature_items'][$fid]['#has_children'],
//      'implementations' => array(),
    );
  }*/
  

  $output .= render_comparative_table($form['#feature_items'], array(), array(), 0, 0);


  //Add the link to go on FastEdit mode
  $toogle_link = array(
    '#type' => 'link',
    '#title' => 'Toogle FastEdit',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'toogle_fastedit_callback/nojs',
    '#id' => 'toogle_fastedit_link',

  );

  $output .= '<p>' . drupal_render($toogle_link) . '</p>';

  return $output;
}


/*
 * Ajax callback cunction called by javascript to recover the compared children of the clicked compared
 */
function get_item_list_children_response($method = 'ajax') {

  $nid = $_POST['node_id'];
  $type = $_POST['type'];
  $subaction = $_POST['subaction'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //If we want to displayed the children
    if ($_POST['action'] == 'display') {

      //Recover the children from database
      $query = db_select('cache_' . $type, 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->addField('s', 'has_children', 'has_children');
      $query->addField('r', 'uid', 'uid');
      $query->leftjoin('node_revision', 'r', 's.nid = r.nid');
      $query->condition("s.parent_" . $type . "_id", $nid);
      $result = $query->execute();

      //Prepare the array to use as argument for the item list building function
      $nodes = array();
      $fastedit_status = 0;
      foreach ($result as $record) {
        $nodes[$record->nid] = array(
          'nid' => $record->nid,
          'title' => array(
            '#markup' => check_plain($record->title),
          ),
          'has_children' => $record->has_children,
        );

        if ($subaction == 'compared_main_table') {
          //If already displayed in the table, we check it by default
          if (!empty($_POST['compared_column_ids'])) {
            if (in_array($record->nid, $_POST['compared_column_ids'])) {
              $nodes[$record->nid]['displayed'] = True;
            }
          }
          //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $nodes[$record->nid]['no-edit'] = True;
          }
          if (!empty($_POST['fastedit_status'])) {
            $fastedit_status = $_POST['fastedit_status'];
          }
        }
      }


      //Building the data for the item list
      $item_list_data = get_item_list($nodes, $type, $subaction, $fastedit_status);
      //Rendering the item list
      $output = theme_item_list(array('items' => $item_list_data, 'title' => '',  'type' => 'ul', 'attributes' => array()));
      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We prepared a div under the parent compared. This command will fill it with the compared children, and replace anything that was here before.
      $commands[] = ajax_command_html('#'. $type . '_children_' . $nid, $output);
      $page = array('#type' => 'ajax', '#commands' => $commands);

      return $page;

    //If we want to collapse the compared children
    } else {

      //In this case we return nothing, everything is managed on the javascript side
      $commands = array();
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}

/*
 * Function which will build the item list. Used in table initial building, in compared ajax callback and in modal dialog
 */
function get_item_list($nodes, $type, $action, $fastedit_status){

  $items = array();
  foreach ($nodes as $node){

    //If the node has children, the node name will become a link calling the callback function to display his children
    if ($node['has_children'] == 1){
      $title = array(
        '#type' => 'link',
        '#title' => drupal_render($node['title']),
        //The callback link, /nojs is automatically replace for /ajax by drupal. The second and third argument indicate the node_id for recovering his children and if we have to display or hide them
        '#href' => 'get_item_list_children_callback/nojs/',
        '#id' => $type . '_link_' . $node['nid'],
        '#attributes' => array(
          'class' => array('list_item_link ' . $action . ' ' . $type),
        ),
      );
    } else {
      $title = $node['title'];
    }

    //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table. Unless we configure the system to compute the compared parent, only the compared with no children will have a checkbox.
    $checkbox_area = '';
    $img_link_to_node = '';
    if ($action == 'compared_main_table') {
      if ((variable_get('wikicompare_update_compared', 'no-update') != 'no-update') || ($node['has_children'] != 1)) {
        $checkbox_settings = array('element' => array(
          '#title' => $node['nid'],
          '#id' => 'compared_checkbox_' . $node['nid'],
          '#attributes' => array(
            'class' => array('compared_checkbox'),
          ),
        ));
        //We were not able to ajaxify the checkbox, so instead the checkbox will call this hidden link
        $checkbox_link = array(
          '#type' => 'link',
          '#title' => 'toggle',
          //The link for the callback function which will display or hide the column in the table
          '#href' => 'toogle_compared_checkbox_ajax_callback/nojs/',
          '#id' => 'compared_checkbox_link_' . $node['nid'],
          '#attributes' => array(
            'class' => array('compared_checkbox_link' => 'compared_checkbox_link', 'hidden' => 'hidden'),
            'style' => 'display:none',
          )
        );
        if (isset($node['displayed'])) {
          $checkbox_settings['element']['#checked'] = True;
          $checkbox_link['#href'] = 'toogle_compared_checkbox_ajax_callback/nojs/';
		  unset($checkbox_link['#attributes']['class']['hidden']);
          $checkbox_link['#attributes']['class']['displayed'] = 'displayed';        
        }
        $checkbox = theme_checkbox($checkbox_settings);
        $checkbox_area = $checkbox . ' ' . drupal_render($checkbox_link);
      }

      //Create the image link to go to the node page
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to compared ') . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_node = ' ' . l($img, 'node/' . $node['nid'], array('attributes' => array('id' => 'compared_node_link_' . $node['nid'], 'class' => array('compared_node_link')), 'html' => True));

      if ($fastedit_status == 1) {
        $img_link_to_node .= add_fastedit_items('compared', $node);
      }
    }

    if ($action == 'select_multi_dialog') {
      if ($node['has_children'] != 1) {
        $checkbox_settings = array('element' => array(
          '#title' => $node['nid'],
          '#id' => $type . '_checkbox_' . $node['nid'],
          '#attributes' => array(
            'class' => array('checkbox_dialog'),
          ),
        ));
        $checkbox_area = theme_checkbox($checkbox_settings) . ' ';
      }
    }
    
    $items[$node['nid']]['id'] = $type . '_item_' . $node['nid'];
    $items[$node['nid']]['data'] = $checkbox_area . drupal_render($title) . $img_link_to_node;
    $items[$node['nid']]['class'] = array('list_item');

    //After the compared, we add the div which will contain the children
    $items[$node['nid']]['data'] = $items[$node['nid']]['data'] . '<div id="' . $type . '_children_' . $node['nid'] . '"  style="display:none;"></div>';


  }

  return $items;

}

function get_select_feature_dialog_response(){


  $output = t("<div id='dialog-content'>");


  //Find all the features on the first level of the tree
  $query = db_select('cache_feature', 'f');
  $query->addField('f', 'nid', 'nid');
  $query->addField('f', 'title', 'title');
  $query->addField('f', 'has_children', 'has_children');
  $query->condition('f.parent_feature_id', NULL);
  $query->condition('f.state', 'Published', '=');
  $result = $query->execute();

  $features = array();
  foreach ($result as $record) {
    $features[$record->nid] = array(
      'nid' => $record->nid,
      'title' => array(
        '#markup' => check_plain($record->title),
      ),
      'has_children' => $record->has_children,
    );
  }

  //Building the data for the item list
  $item_list_data = get_item_list($features, 'feature', 'select_multi_dialog', 0);

  $output .= theme_item_list(array('items' => $item_list_data, 'type' => 'ul', 'attributes' => array()));

  $output .= t("</div>");
  return $output;

}

/*
 * Ajax callback cunction called by javascript to recover the feature children of the clicked feature
 */
function get_feature_ajax_response($type = 'ajax') {

  $fid = $_POST['node_id'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the compared children
    if ($_POST['action'] == 'display') {

      //Recover the children from database
      $query = db_select('cache_feature', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->addField('s', 'weight', 'weight');
      $query->addField('s', 'type', 'type');
      $query->addField('s', 'parent_feature_id', 'parent_id');
      $query->addField('s', 'has_children', 'has_children');
      $query->addField('r', 'uid', 'uid');
      $query->leftjoin('node_revision', 'r', 's.nid = r.nid');
      $query->condition("s.parent_feature_id", $fid);
      $result = $query->execute();

      //Prepare the array to use as argument for the table row building function.
      $features = array();
      $features_ids = array();
      foreach ($result as $record) {
        $features[$record->nid]['data'] = $record;
        $features_ids[$record->nid] = $record->nid;
        //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
        if ($GLOBALS['user']->uid != $record->uid) {
          $features[$record->nid]['no-edit'] = True;
        }
      }
      //We recover from javascript argument the id of the columns displayed in the table, to know the cell we have to add
      if (!empty($_POST['compared_column_ids'])) {
        //Recover the implementation needed for the cells
        $query = db_select('cache_implementation', 'i');
        $query->addField('i', 'nid', 'nid');
        $query->addField('i', 'feature_id', 'feature_id');
        $query->addField('i', 'compared_id', 'compared_id');
        $query->addField('ctc', 'percent', 'percent');
        $query->addField('ctc', 'css_class', 'css_class');
        $query->addField('r', 'uid', 'uid');
        $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
        $query->leftjoin('node_revision', 'r', 'i.nid = r.nid');
        $query->condition("i.compared_id", $_POST['compared_column_ids'], 'in');
        $query->condition("i.feature_id", $features_ids, 'in');
        $result = $query->execute();

        //Insert the implementations in an array with their compared as key so we can then add them in the feature array
        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->feature_id][$record->compared_id] = $record;
          //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $implementations[$record->feature_id][$record->compared_id]['no-edit'] = True;
          }
        }
/*        //Insert the implementations in the feature array, using the compared as key. Note that the compared order must be kept because it's the order of the column in the table
        foreach ($features as $key => $feature) {
          foreach ($_POST['compared_column_ids'] as $compared_id) {
            $features[$key]['implementations'][] = $implementations[$key][$compared_id];
          }
        }*/
      }
      $fastedit_status = 0;
      if (!empty($_POST['fastedit_status'])) {
        $fastedit_status = $_POST['fastedit_status'];
      }
      //Building the data for the table row

      $feature_row_data = get_rows_data($features, $_POST['compared_column_ids'], $implementations, 0);
//dpm($feature_row_data);
      $output = render_rows($feature_row_data, $fastedit_status);
/*      //Add a row for each feature children
      foreach ($feature_row_data as $feature) {
        $output .= '<tr id="'. $feature['id'] . '" class="feature_row feature_children_' . $fid . '" style="display:none;">';
        //Add a column for each column in the table
        foreach ($feature['data'] as $data) {
          $output .= $data;
        }
        $output .= '</tr>';
      }*/

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We add the code after the parent row. Note we can't use ajax_command_after because it adds an unwanted div
      $commands[] = ajax_command_invoke('#feature_row_' . $fid, 'after', array($output));

      //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
      $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');
      $page = array('#type' => 'ajax', '#commands' => $commands);
  
      return $page;

    //If we want to collapse the feature children
    } else {

      //In this case we return nothing, everything is managed on the javascript side
      $commands = array();
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }
}





/*
 * Ajax callback cunction called by javascript to add or remove a column in the comparative table
 */
function toggle_compared_checkbox_ajax_response($type='ajax'){

  $cid = $_POST['node_id'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the compared children
    if ($_POST['action'] == 'display') {

      //Recover fastedit status
      $fastedit_status = 0;
      if (!empty($_POST['fastedit_status'])) {
        $fastedit_status = $_POST['fastedit_status'];
      }
    
      //Recover the detail of the compared we want to add
      $query = db_select('cache_compared', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->condition("s.nid", $cid);
      $result = $query->execute();
      foreach ($result as $record) {
        $compared = $record;
      }



      //Add the header of the new column, with the compared detail
      $header = '<th id="header_compared_' . $cid . '" class="header_compared" style="display:none;">' . $compared->title . ' ' . $cid . '</th>';

      //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
      if (!empty($_POST['feature_ids'])) {
        //Recover the implementation needed for the cells
        $query = db_select('cache_implementation', 'i');
        $query->addField('i', 'nid', 'nid');
        $query->addField('i', 'feature_id', 'feature_id');
        $query->addField('i', 'compared_id', 'compared_id');
        $query->addField('ctc', 'percent', 'percent');
        $query->addField('ctc', 'css_class', 'css_class');
        $query->addField('r', 'uid', 'uid');
        $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
        $query->leftjoin('node_revision', 'r', 'i.nid = r.nid');
        $query->condition("i.compared_id", $cid);
        $query->condition("i.feature_id", $_POST['feature_ids'], 'in');
        $result = $query->execute();



        //Build the cells we have to add in each row.
        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->feature_id][$cid] = $record;
/*          //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $implementations[$record->nid]['no-edit'] = True;
          }TODOTODOTODO*/
        }
dpm($implementations);        
        if ($_POST['computed']) {
          $features_array = array();
          $features_array = build_feature_tree($_POST['feature_ids'], $features_array);
          $features_ids = $features_array['tree'];
        } else {
          $features_ids = $_POST['feature_ids'];
        }
        $feature_row_data = get_rows_data($features_ids, array($cid), $implementations, $_POST['computed']);
//TODODODODDOO
dpm($feature_row_data);
dpm($features_ids);
dpm($_POST['computed']);
        $cells = array();
        foreach ($_POST['feature_ids'] as $feature_id) {

          $implementation = $implementations[$feature_id][$cid];
//dpm($implementation);
          $cells[$implementation->feature_id] .= render_implementation($implementation, $fastedit_status);
/*
          //Create the image link to go to the node page
          $img = theme('image', array(
            'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
            'alt' => t('Link to implementation ') . $implementation['nid'],
            'height' => '100%',
          ));
          //Create the link. The html = True indicate that the title of the link contain html.
          $img_link_to_node = l($img, 'node/' . $implementation['nid'], array('attributes' => array('id' => 'implementation_node_link_' . $implementation['nid'], 'class' => array('implementation_node_link')), 'html' => True));
          if ($fastedit_status == 1) {
            $img_link_to_node .= add_fastedit_items('implementation', $implementation); 
          }
          $cells[$implementation['feature_id']] = '<td id="implementation_' . $implementation['nid'] . '" class="implementation_cell ' . $implementation['css_class'] . ' implementation_compared_' . $cid . ' implementation_feature_' . $implementation['feature_id'] . '" style="display:none;">' . $implementation['nid'] . ' ' . $img_link_to_node . '<br/>Feature : ' . $implementation['feature_id'] . '<br/>Compared : ' . $cid . '<br/>' . $implementation['percent'] . '%</td>';*/
        }
      }
dpm($cells);

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //Add the new cell at the end of the header
      $commands[] = ajax_command_append('#comparative_table_header', $header);
      //Add the new cells at the end of each row
      foreach ($cells as $key => $cell) {
        $commands[] = ajax_command_append('#feature_row_' . $key, $cell);
      }
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    //If we want to remove the column
    } else {

      //In this case we return nothing, everything is managed on the javascript side
      $commands = array();
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}


function compute_comparative_table_response($method = 'ajax') {

dpm($_POST);
  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //Since in javascript we use an associative array for storing the selected_feature_ids, we need to remove the [0] in the array
    $selected_feature_ids = array();
    foreach ($_POST['selected_feature_ids'] as $selected_feature_id) {
      $selected_feature_ids[$selected_feature_id[0]] = $selected_feature_id[0];
    }

    //If empty, javascript return a null string and not an empty array. So we need to assign it in a variable and manage the null case.
    $compared_columns_ids = array();
    if ($_POST['compared_column_ids']) {
      $compared_columns_ids = $_POST['compared_column_ids'];
    }


    $feature_array = array();

    if ($selected_feature_ids) {
      $feature_array = build_feature_tree($selected_feature_ids, $feature_array);
    }

//dpm($feature_array);

    $implementations = array();
    if (!empty($feature_array['ids']) && !empty($compared_columns_ids)) {

      //Recover the implementation needed for the cells
      $query = db_select('cache_implementation', 'i');
      $query->addField('i', 'nid', 'nid');
      $query->addField('i', 'feature_id', 'feature_id');
      $query->addField('i', 'compared_id', 'compared_id');
      $query->addField('ctc', 'percent', 'percent');
      $query->addField('ctc', 'css_class', 'css_class');
//    $query->addField('r', 'uid', 'uid'); TODO
      $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
//    $query->leftjoin('node_revision', 'r', 'i.nid = r.nid');

      $query->condition("i.compared_id", $compared_columns_ids, 'in');
      $query->condition("i.feature_id", $feature_array['ids'], 'in');
      $result = $query->execute();

  


      //Insert the implementations in an array with their compared as key so we can then add them in the feature array

      foreach ($result as $record) {
        $implementations[$record->feature_id][$record->compared_id] = $record;
/*    $implementations[$record->feature_id][$record->compared_id]['feature_id'] = $record->feature_id;
    $implementations[$record->feature_id][$record->compared_id]['compared_id'] = $record->compared_id;
    $implementations[$record->feature_id][$record->compared_id]['percent'] = $record->percent;
    $implementations[$record->feature_id][$record->compared_id]['css_class'] = $record->css_class;*/
    //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
/*    if ($GLOBALS['user']->uid != $record->uid) {
      $implementations[$record->feature_id][$record->compared_id]['no-edit'] = True;
    }*/
      }
  //Insert the implementations in the feature array, using the compared as key. Note that the compared order must be kept because it's the order of the column in the table
/*  foreach ($features_array['ids'] as $key => $feature) {
    foreach ($_POST['compared_column_ids'] as $compared_id) {
      $features_array['tree'][$key]['implementations'][] = $implementations[$key][$compared_id];
    }
  }*/
    } 

    $fastedit_status = 0;
    if (!empty($_POST['fastedit_status'])) {
      $fastedit_status = $_POST['fastedit_status'];
    }
  
//dpm($compared_columns_ids);
    $output = render_comparative_table($feature_array['tree'], $compared_columns_ids, $implementations, $fastedit_status, 1);



//dpm($output);
    //Preparing the ajax commands to return to javascript
    $commands = array();
    $commands[] = ajax_command_replace('#comparative_table', $output);
//    $commands[] = ajax_command_invoke('#comparative_table', 'replace', array($output));
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}

function build_feature_tree($feature_ids, $features_array){

  $parent_ids = array();

  //No other way here but to put this query in recursive function. Some improvement for later may be to use the WITH RECURSIVE function of postgresql.
  $query = db_select('cache_feature', 's');
  $query->addField('s', 'nid', 'nid');
  $query->addField('s', 'title', 'title');
  $query->addField('s', 'weight', 'weight');
  $query->addField('s', 'type', 'type');
  $query->addField('s', 'parent_feature_id', 'parent_id');
  $query->addField('s', 'has_children', 'has_children');
//  $query->addField('r', 'uid', 'uid'); //TODO
//  $query->leftjoin('node_revision', 'r', 's.nid = r.nid');
  $query->condition("s.nid", $feature_ids, 'in');
  $result = $query->execute();

  foreach ($result as $record) {
    $node_array = array();
    $node_array['data'] = $record;
    //Check if some children of this node launched the recursive function to find this node as their parent. Then assign them as children of this node and unset the node in the array.
    $node_array['children'] = array();
    if (isset($features_array['parent_ressource'][$record->nid]['children'])) {
      $node_array['children'] = $features_array['parent_ressource'][$record->nid]['children'];
      unset($features_array['parent_ressource'][$record->nid]);
    }

    //Build a list of all id, parent and children, to use them in implementation sql request
    $features_array['ids'][$record->nid] = $record->nid;

    //If the node has parent, assign him in the parent array and tell the recursive function to find the parent next time. Else, set the node at the root of the array.
    if ($record->parent_id) {
      $features_array['parent_ressource'][$record->parent_id]['children'][$record->nid] = $node_array;
      $parent_ids[$record->parent_id] = $record->parent_id;
    } else {
      $features_array['tree'][$record->nid] = $node_array;
    }
  }

  //If there is others parents to add in the array, relaunch the recursive function until all parents are found.
  if ($parent_ids){
    $features_array = build_feature_tree($parent_ids, $features_array);
  }
  
  return $features_array;

}


function render_comparative_table($features, $compareds, $implementations, $fastedit_status, $computed){

  $feature_row_data = get_rows_data($features, $compareds, $implementations, $computed);

  $headers = array();
  if (!empty($compareds)) {
    $query = db_select('cache_compared', 's');
    $query->addField('s', 'nid', 'nid');
    $query->addField('s', 'title', 'title');
    $query->condition("s.nid", $compareds, 'in');
    $result = $query->execute();

    foreach ($result as $record) {
      $headers[$record->nid] = $record->title . ' ' . $record->nid;
    }
  }

  //Building the table
  $output = '<table id="comparative_table"';
  if ($computed) {
    $output .= ' class="computed"';
  }
  $output .= '><thead>';
  $output .= '<tr id="comparative_table_header">';
  $output .= '<th>' . t('Features') . '</th>';
  foreach ($headers as $header) {
    $output .= '<th>' . $header . '</th>';
  }
  $output .= '</tr>';
  $output .= '</thead>';
  $output .= '<tbody>';

  $output .= render_rows($feature_row_data, $fastedit_status);
/*
  //Add a row for each feature children
  foreach ($feature_row_data as $fid => $feature_array) {
//dpm($feature_array);
    $feature = $feature_array['data'];

    $output .= '<tr id="feature_row_'. $fid . '" class="feature_row';
    if ($feature->parent_id) {
        $output .= ' feature_children_' . $feature->parent_id;
    }
    $output .= '"';
    if (!isset($feature_array['root'])) {
      $output .= ' style="display:none;"';
    }
    $output .= '>';

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to feature ') . $fid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $fid, array('attributes' => array('id' => 'feature_node_link_' . $fid, 'class' => array('feature_node_link')), 'html' => True));
    if ($fastedit_status == 1) {
      $img_link_to_node .= add_fastedit_items('feature', $feature); 
    }

    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($feature->has_children == 1){
      $title_link = array(
        '#type' => 'link',
        '#title' => $feature->title . ' ' . $fid,
        //The callback link, /nojs is automatically replace for /ajax by drupal. The second and third argument indicate the feature_id for recovering his children and if we have to display or hide them
        '#href' => 'get_feature_ajax_callback/nojs/',
        '#id' => 'feature_link_' . $fid,
        '#attributes' => array(
          'class' => array('feature_link'),
        ),
      );
      $title = drupal_render($title_link);
    } else {
      $title = $feature->title . ' ' . $fid;
    }

    //Creating the first cell of the row, containing the feature details
    $output .= '<td>' . $title . ' ' . $img_link_to_node  . '<br/> Weight : ' .  $feature->weight . '<br/> Type : ' . $feature->type . '</td>';

    //Add a column for each column in the table
    foreach ($feature_array['implementations'] as $implementation) {
      $output .= render_implementation($implementation, $fastedit_status);
/*
      //Create the image link to go to the node page
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to implementation ') . $implementation->nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_node = l($img, 'node/' . $implementation->nid,  array('attributes' => array('id' => 'implementation_node_link_' . $implementation->nid, 'class' => array('implementation_node_link')), 'html' => True));
      if ($fastedit_status == 1) {
        $img_link_to_node .= add_fastedit_items('implementation', $implementation); 
      }

      $output .= '<td id="implementation_' . $implementation->nid . '" class="implementation_cell ' . $implementation->css_class . ' implementation_compared_' . $implementation->compared_id . ' implementation_feature_' . $feature->nid . '">' . $implementation->nid . ' ' .  $img_link_to_node . '<br/>Feature : ' . $implementation->feature_id . '<br/>Compared : ' . $implementation->compared_id . '<br/>' . $implementation->percent . '%</td>';*//*
    }
    $output .= '</tr>';
  }*/
  $output .= '</tbody>';
  $output .= '</table>';

  return $output;


}

function render_rows($feature_row_data, $fastedit_status) {

  $output = '';

  //Add a row for each feature children
  foreach ($feature_row_data as $fid => $feature_array) {
//dpm($feature_array);
    $feature = $feature_array['data'];

    $output .= '<tr id="feature_row_'. $fid . '" class="feature_row';
    if ($feature->parent_id) {
        $output .= ' feature_children_' . $feature->parent_id;
    }
    $output .= '"';
    if (!isset($feature_array['root'])) {
      $output .= ' style="display:none;"';
    }
    $output .= '>';

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to feature ') . $fid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $fid, array('attributes' => array('id' => 'feature_node_link_' . $fid, 'class' => array('feature_node_link')), 'html' => True));
    if ($fastedit_status == 1) {
      $img_link_to_node .= add_fastedit_items('feature', $feature); 
    }

    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($feature->has_children == 1){
      $title_link = array(
        '#type' => 'link',
        '#title' => $feature->title . ' ' . $fid,
        //The callback link, /nojs is automatically replace for /ajax by drupal. The second and third argument indicate the feature_id for recovering his children and if we have to display or hide them
        '#href' => 'get_feature_ajax_callback/nojs/',
        '#id' => 'feature_link_' . $fid,
        '#attributes' => array(
          'class' => array('feature_link feature_link_children_' . $fid),
        ),
      );
      $title = drupal_render($title_link);
    } else {
      $title = $feature->title . ' ' . $fid;
    }

    //Creating the first cell of the row, containing the feature details
    $output .= '<td>' . $title . ' ' . $img_link_to_node  . '<br/> Weight : ' .  $feature->weight . '<br/> Type : ' . $feature->type . '</td>';

    //Add a column for each column in the table
    foreach ($feature_array['implementations'] as $implementation) {
      $output .= render_implementation($implementation, $fastedit_status);
    }
    $output .= '</tr>';
  }

  return $output;


}

function render_implementation($implementation, $fastedit_status) {

  //Create the image link to go to the node page
  $img = theme('image', array(
    'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
    'alt' => t('Link to implementation ') . $implementation->nid,
    'height' => '100%',
  ));
  //Create the link. The html = True indicate that the title of the link contain html.
  $img_link_to_node = l($img, 'node/' . $implementation->nid,  array('attributes' => array('id' => 'implementation_node_link_' . $implementation->nid, 'class' => array('implementation_node_link')), 'html' => True));
  if ($fastedit_status == 1) {
    $img_link_to_node .= add_fastedit_items('implementation', $implementation); 
  }

  $output = '<td id="implementation_' . $implementation->nid . '" class="implementation_cell ' . $implementation->css_class . ' implementation_compared_' . $implementation->compared_id . ' implementation_feature_' . $feature->nid . '">' . $implementation->nid . ' ' .  $img_link_to_node . '<br/>Feature : ' . $implementation->feature_id . '<br/>Compared : ' . $implementation->compared_id . '<br/>' . $implementation->percent . '%</td>';

  return $output;
}

/*
 * Function which will build the features row. Used in table initial building and in feature ajax callback
 */
function get_rows_data($features, $compareds, $implementations, $computed){
//dpm($implementations);
  $rows = array();
dpm($features);
  foreach ($features as $fid => $feature){
    $rows[$fid]['data'] = $feature['data'];

    if ($feature['data']->parent_id) {
      $rows[$fid]['direct-child'] = True;
    } else {
      $rows[$fid]['root'] = True;
    }

    $children = array();
    if ($feature['children']) {
      $children = get_rows_data($feature['children'], $compareds, $implementations, $computed);
    }
//dpm($feature);
    $direct_children = array();
    foreach ($children as $key => $child) {
      if (isset($child['direct-child'])) {
        $direct_children[$key] = $child;
        unset($children[$key]['direct-child']);
      }
      
    }
//dpm($direct_children, 'direct_children');    
//dpm($compareds, 'compareds');

    $rows[$fid]['implementations'] = array();
    //Adding one cell for each implementation, which contain the details of the cells
    foreach ($compareds as $compared) {
//dpm($compared, 'compared');

      $implementation = $implementations[$fid][$compared];

      if ($computed) {
        //The type will be used in the wikicompare_compute_percent function
        $implementation->type = $feature['data']->type;
        //The weight will be used in the parent wikicompare_compute_percent function
        $implementation->weight = $feature['data']->weight;
//dpm($implementation, 'implementation');

        $through_feature_childs = array();
        foreach ($direct_children as $child) {
          $child_implementation = $child['implementations'][$compared];
          $through_feature_childs[$child_implementation->feature_id] = $child_implementation;
        }
//dpm($through_feature_childs, '$through_feature_childs');
//dpm($implementation, 'before implementation');
        if ($feature['data']->has_children) {
          $implementation = wikicompare_compute_percent($implementation, $through_feature_childs);
        }
      }
//dpm($implementation, 'implementation');
      $rows[$fid]['implementations'][$compared] = $implementation;
//dpm($rows, 'rows');
    }

    foreach ($children as $key=> $child) {
      $rows[$key] = $child;
    }


  }

  return $rows;

}


/*
 * Ajax callback function called by javascript to add or remove the fastedit items in the comparative table.
 */
function toggle_fastedit_response($type='ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the fastedit items
    if ($_POST['fastedit_status'] == false) {

      $compareds = array();
      if (!empty($_POST['compared_ids'])) {
        $query = db_select('node_revision', 'r');
        $query->addField('r', 'nid', 'nid');
        $query->addField('r', 'uid', 'uid');
        $query->condition('r.nid', $_POST['compared_ids'], 'in');
        $result = $query->execute();

        foreach ($result as $record) {
          $compareds[$record->nid]['nid'] = $record->nid;
          //If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $compareds[$record->nid]['no-edit'] = True;
          }
        }

      }

      $commands = array();
      foreach($compareds as $compared) {

        $output = add_fastedit_items('compared' , $compared);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#compared_node_link_' . $compared['nid'], 'after', array($output));
        //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
        $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

      }


      $features = array();
      if (!empty($_POST['feature_ids'])) {

        $query = db_select('node_revision', 'r');
        $query->addField('r', 'nid', 'nid');
        $query->addField('r', 'uid', 'uid');
        $query->condition('r.nid', $_POST['feature_ids'], 'in');
        $result = $query->execute();

        foreach ($result as $record) {
          $features[$record->nid]['nid'] = $record->nid;
          //If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $features[$record->nid]['no-edit'] = True;
          }
        }

      }

      foreach($features as $feature) {

        $output = add_fastedit_items('feature', $feature);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#feature_node_link_' . $feature['nid'], 'after', array($output));

      }
      
      $implementations = array();
      if (!empty($_POST['implementation_ids'])) {

        $query = db_select('node_revision', 'r');
        $query->addField('r', 'nid', 'nid');
        $query->addField('r', 'uid', 'uid');
        $query->condition('r.nid', $_POST['implementation_ids'], 'in');
        $result = $query->execute();

        foreach ($result as $record) {
          $implementations[$record->nid]['nid'] = $record->nid;
          //If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $implementations[$record->nid]['no-edit'] = True;
          }
        }

      }

      foreach($implementations as $implementation) {

        $output = add_fastedit_items('implementation', $implementation);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#implementation_node_link_' . $implementation['nid'], 'after', array($output));

      }
      //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
      $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');
      
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    //If we want to hide the fastedit items
    } else {

      //In this case we return nothing, everything is managed on the javascript side
      $commands = array();
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  //If javascript isn't enabled, we redirect to an error page.nds = array();
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }
}

function add_fastedit_items($type, $node){

  $output = ' ';
  
  if ($type == 'implementation') {
    
    if (!isset($node['no-edit'])) {   
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $node['nid'], 'class' => array('fastedit_item ' . $type . '_edit_link')), 'html' => True));
      $output .= $img_link_to_edit;
    }
  
  } else {
    //Create the image link to add a new children
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to add children ') . $type . ' ' . $node['nid'],
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_add = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_add_link_' . $node['nid'], 'class' => array('fastedit_item ' . $type . '_add_link')), 'html' => True));
    $output .= $img_link_to_add;

    if (!isset($node['no-edit'])) {
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $node['nid'], 'class' => array('fastedit_item ' . $type . '_edit_link')), 'html' => True));
      $output .= $img_link_to_edit;

      //Create the image link to remove the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to remove ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_remove = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_remove_link_' . $node['nid'], 'class' => array('fastedit_item ' . $type . '_remove_link')), 'html' => True));
      $output .= $img_link_to_remove;
    }
  }

  return $output;

}

/*
 * Ajax callback cunction called by javascript to display the fastedit form
 */
function get_fastedit_form_response($method='ajax'){

  $nid = $_POST['node_id'];
  $type = $_POST['type'];
  $fastaction = $_POST['fastaction'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //If we want to displayed the compared children
    if ($_POST['action'] == 'display') {

      if ($type != 'compared') {
        $output .= '<tr id="line_form_' . $type . '_fast' . $fastaction . '_'. $nid . '" class="line_form_fastedit form_'. $type . '_fast' . $fastaction . '"><td>';
      }
      
      $output .= '<form id="form_' . $type . '_fast' . $fastaction . '_'. $nid . '" class="form_fastedit form_'. $type . '_fast' . $fastaction . '">';
      
      
    
      if ($fastaction == 'remove') {
      
        $label = array(
          '#markup' => t('Do you really want to remove this ') . $type . '<br/>',
        );
        $output .= drupal_render($label);
      
      
      } else {
      
      
        if ($fastaction == 'edit') {
    
          $node = node_load($nid);
          
        }
      
        if ($type != 'implementation') {
          $name_field = array(
            '#type' => 'textfield',
            '#title' => t('Title'),
            '#id' => 'form_' . $type . '_fast' . $fastaction . '_title_' . $nid,
            '#attributes' => array(
              'class' => array('form_' . $type . '_fast' . $fastaction . '_title'),
            )
          );          
          if ($fastaction == 'edit') {
            $name_field['#value'] = $node->title;
          }
          $output .= drupal_render($name_field);

        }
      
        $description_field = array(
          '#type' => 'textarea',
          '#title' => t('Description'),
          '#id' => 'form_' . $type . '_fast' . $fastaction . '_description_' . $nid,
          '#attributes' => array(
            'class' => array('form_' . $type . '_fast' . $fastaction . '_description'),
          )
        );
        if ($fastaction == 'edit') {
          $description_field['#value'] = $node->body['und'][0]['value'];
        }
        $output .= drupal_render($description_field);
      

      
        if ($type == 'feature') {
          $type_field = array(
            '#type' => 'select',
            '#title' => t('Type'),
            '#options' => array(
              'parent-weighted-average' => 'Parent Feature - Weighted Average',
              'parent-highest-percentage' => 'Parent Feature - Highest Percentage',
            ),
            '#id' => 'form_' . $type . '_fast' . $fastaction . '_type_' . $nid,
            '#attributes' => array(
              'class' => array('form_' . $type . '_fast' . $fastaction . '_type'),
            )
          );
          if ($fastaction == 'edit') {
            $type_field['#value'] = $node->feature_type['und'][0]['value'];
          }
          $output .= drupal_render($type_field);
          
          $guidelines_field = array(
            '#type' => 'textarea',
            '#title' => t('Validation guidelines'),
            '#id' => 'form_' . $type . '_fast' . $fastaction . '_guidelines_' . $nid,
            '#attributes' => array(
              'class' => array('form_' . $type . '_fast' . $fastaction . '_guidelines'),
            )
          );
          if ($fastaction == 'edit') {
            $guidelines_field['#value'] = $node->feature_validation_guidelines['und'][0]['value'];
          }
          $output .= drupal_render($guidelines_field);
          
          $weight_field = array(
            '#type' => 'textfield',
            '#title' => t('Weight'),
            '#default_value' => 100,
            '#element_validate' => array('element_validate_integer_positive_or_null'),
            '#id' => 'form_' . $type . '_fast' . $fastaction . '_weight_' . $nid,
            '#attributes' => array(
              'class' => array('form_' . $type . '_fast' . $fastaction . '_weight'),
            )
          );
          if ($fastaction == 'edit') {
            $weight_field['#value'] = $node->feature_weight['und'][0]['value'];
          }
          $output .= drupal_render($weight_field);
          
          $state_field = array(
            '#type' => 'select',
            '#title' => t('State'),
            '#options' => array(
              'New' => 'New',
              'Incomplete' => 'Incomplete',
              'Published' => 'Published',
              'Disactivated' => 'Disactivated',
            ),
            '#id' => 'form_' . $type . '_fast' . $fastaction . '_state_' . $nid,
            '#attributes' => array(
              'class' => array('form_' . $type . '_fast' . $fastaction . '_state'),
            )
          );
          if ($fastaction == 'edit') {
            $state_field['#value'] = $node->feature_state['und'][0]['value'];
          }
          $output .= drupal_render($state_field);
        }
        
        if ($type == 'implementation') {
        
          $support_field = array(
            '#type' => 'select',
            '#title' => t('Support'),
            '#options' => array(
              0 => 'Unsupported',
              1 => 'Supported',
            ),
            '#id' => 'form_' . $type . '_fast' . $fastaction . '_support_' . $nid,
            '#attributes' => array(
              'class' => array('form_' . $type . '_fast' . $fastaction . '_support'),
            )
          );
          if ($fastaction == 'edit') {
            $support_field['#value'] = $node->feature_support['und'][0]['value'];
          }
          $output .= drupal_render($support_field);

        
        }
        
        
        $revision_field = array(
          '#type' => 'textarea',
          '#title' => t('Revision log message'),
          '#id' => 'form_' . $type . '_fast' . $fastaction . '_revision_' . $nid,
          '#attributes' => array(
            'class' => array('form_' . $type . '_fast' . $fastaction . '_revision'),
          )
        );
        $output .= drupal_render($revision_field);
      
      }
      


      $output .= '<input id="form_'. $type . '_fast' . $fastaction . '_submit_'. $nid . '" type="submit" value="Confirm" class="form_' . $type . '_fast' . $fastaction . '_submit button"/>';
      $submit_link = array(
        '#type' => 'link',
        '#title' => 'submit',
        '#href' => 'submit_fastedit_form_callback/nojs/',
        '#id' => 'form_' . $type . '_fast' . $fastaction . '_submit_link_' . $nid,
        '#attributes' => array(
          'class' => array('form_fastedit_submit_link form_' . $type . '_fast' . $fastaction . '_submit_link'),
          'style' => 'display:none',
        )
      );
      $output .= drupal_render($submit_link);
      $output .= '<input id="form_' . $type . '_fast' . $fastaction . '_cancel_'. $nid . '" type="button" value="Cancel" class="form_' . $type . '_fast' . fastaction . '_cancel button"/>';
      $output .= '</form>';
      
      if ($type == 'feature') {
        $output .= '</td></tr>';
      }

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //Insert the form in the page. Note we can't use ajax_command_before or ajax_command_after because it adds an unwanted div
      switch ($type) {
        case ('compared'):
          $commands[] = ajax_command_invoke('#compared_children_' . $nid, 'before', array($output));
          break;
        case ('feature'):
          $commands[] = ajax_command_invoke('#feature_row_' . $nid, 'after', array($output));
          break;
        case ('implementation'):
          $commands[] = ajax_command_invoke('#feature_row_' . $node->implementation_feature['und'][0]['target_id'], 'after', array($output));
          break;
      }

      //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
      $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');
      
      $page = array('#type' => 'ajax', '#commands' => $commands);          
      return $page;

    //If we want to hide the form
    } else {

      //In this case we return nothing, everything is managed on the javascript side
      $commands = array();
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}


/*
 * Ajax callback function called by javascript when we submit one of the fastedit form.
 */
function submit_fastedit_form_response($method='ajax'){

  $type = $_POST['type'];
  $fastaction = $_POST['fastaction'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    if ($fastaction == 'remove') {

      node_delete($_POST['node_id']);
    
    } else {
  
      switch ($fastaction) {
        case 'add':
          $node = new stdClass();
          $node->type = $type;
          $node->language = LANGUAGE_NONE;
          switch ($type) {
            case 'compared':
              $node->compared_parent_compared[$node->language][0]['target_id'] = $_POST['node_id'];
              $node->compared_parent_compared[$node->language][0]['target_type'] = "node";
              break;
            case 'feature':
              $node->feature_parent_feature[$node->language][0]['target_id'] = $_POST['node_id'];
              $node->feature_parent_feature[$node->language][0]['target_type'] = "node";
              break;
          }
          break;
        case 'edit':
          $node = node_load($_POST['node_id']);
          $node->revision = 1;
          break;
      }
    
      if ($type != 'implementation') {
        $node->title = $_POST['title'];
      }

        
      $node->body[$node->language][0] = array(
        'value' => $_POST['description'],
        'format' => 'full_html',
      );
      
      if ($type == 'feature') {
        $node->feature_type[$node->language][0]['value'] = $_POST['feature_type'];
        
        $node->feature_validation_guidelines[$node->language][0]['value'] = $_POST['guidelines'];
        $node->feature_validation_guidelines[$node->language][0]['format'] = 'full_html';
        
        $node->feature_weight[$node->language][0]['value'] = $_POST['weight'];        
        
        $node->feature_state[$node->language][0]['value'] = $_POST['state'];
        
      }
      
      if ($type == 'implementation') {
        $node->implementation_support[$node->language][0]['value'] = $_POST['support'];
      }
      
      $node->log = $_POST['revision'];
 
      node_save($node);
    
      _revisioning_publish_latest_revision($node);
      
    }

    //We return nothing, everything is managed on the javascript side
    $commands = array();
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;
    
  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }
}

/*
 * Dummy Ajax callback function called by javascript for the link which should return nothing in javascript.
 */
function dummy_ajax_function_response($type='ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {
    //We return nothing, everything is managed on the javascript side
    $commands = array();
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;
  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }
}

?>
