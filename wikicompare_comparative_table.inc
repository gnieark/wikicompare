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

require_once drupal_get_path('module', 'wikicompare') . '/wikicompare_comparative_table_fastedit.inc';

function wikicompare_comparative_table($form_state) {

  //Add the javascript files used in the comparative_table
  drupal_add_js('/misc/ajax.js');
  drupal_add_js('/misc/progress.js');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  //Find all the compared on the first level of the tree
  $res = request_db('compared');

  $form['#compared_items'] = $res;



  //Find all the features on the first level of the tree
  $res = request_db('feature');

  $form['#feature_items'] = $res;


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

  $itemlist_settings = initialize_itemlist_settings('compared_main_table');
/*  $itemlist_settings = array(
    'fastedit_status' => 0,
    'dialog' => 0,
    'checkbox_parent' => 0,
    'checkbox_children' => 1,
    'select_link' => 0,
    'compared_link' => 1,
    'computed' => 0,
  );

  if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
    $itemlist_settings['checkbox_parent'] = 1;
  }*/

  //Building the data for the item list
  $item_list_data = get_item_list($form['#compared_items'], 'compared', 'compared_main_table', 0, $itemlist_settings);


  //Render the item list
  $output = theme_item_list(array('items' => $item_list_data, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));

  $output .= '<div id="manual_selected_features"></div>';

  //Add the link to open the select feature popup
  $select_feature_link = array(
    'text' => 'Select features',
    'title' => 'Select features',
    'selector' => 'dialog-content',
    'path' => 'get_dialog_callback/select_multi_dialog/feature/manual_selected_features/0',
    'id' => 'select_feature_link',

  );
  $output .= '<p>' . theme('simple_dialog_link', $select_feature_link) . '</p>';
  

  //Allow others modules to modify the output
  foreach (module_implements('wikicompare_comparative_table_before_compute') as $module) {
    $function = $module . '_wikicompare_comparative_table_before_compute';
    $function($output);
  }


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


  //Add the link to go on FastEdit mode
  $cleaning_link = array(
    '#type' => 'link',
    '#title' => 'Clean',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'make_cleaning_callback/nojs',
    '#id' => 'make_cleaning_link',
    '#attributes' => array(
      'style' => 'display:none',
    ),

  );

  $output .= '<p>' . drupal_render($cleaning_link) . '</p>';

  return $output;
}


/*
 * Ajax callback cunction called by javascript to recover the compared children of the clicked compared
 */
function get_item_list_children_response($method = 'ajax') {

dpm($_POST, 'post_itemlist');
  $nid = $_POST['node_id'];
  $type = $_POST['type'];
  $subaction = $_POST['subaction'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {



    //If we want to displayed the children
    if ($_POST['action'] == 'display') {

      $itemlist_settings = initialize_itemlist_settings($subaction);
/*      $itemlist_settings = array(
        'fastedit_status' => $_POST['fastedit_status'],
        'dialog' => 0,
        'checkbox_parent' => 0,
        'checkbox_children' => 0,
        'select_link' => 0,
        'compared_link' => 0,
        'computed' => 0,
      );

      switch ($subaction) {
        case 'compared_main_table':
          $itemlist_settings['checkbox_children'] = 1;
          $itemlist_settings['compared_link'] = 1;
          if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
            $itemlist_settings['checkbox_parent'] = 1;
          }
          break;
        case 'feature_list_computed':
          $itemlist_settings['computed'] = 1;
          break;
        case 'select_multi_dialog':
          $itemlist_settings['checkbox_children'] = 1;
          break;
        case 'select_simple_dialog':
          $itemlist_settings['select_link'] = 1;
          break;
      }*/


      if (!empty($_POST['fastedit_status'])) {
        $itemlist_settings['fastedit_status'] = $_POST['fastedit_status'];
      }
      $nodes = request_db($type, $itemlist_settings['fastedit_status'], 'parent', array($nid));
//dpm($nodes);

      //Prepare the array to use as argument for the item list building function

      foreach ($nodes as $key => $record) {

        if ($subaction == 'compared_main_table') {
          //If already displayed in the table, we check it by default
          if (!empty($_POST['compared_column_ids'])) {
            if (in_array($key, $_POST['compared_column_ids'])) {
              $nodes[$key]['data']->displayed = True;
            }
          }

        }

        if ($subaction == 'select_multi_dialog') {
/*
          //Since in javascript we use an associative array for storing the selected_feature_ids, we need to remove the [0] in the array
          $selected_feature_ids = array();
          foreach ($_POST['selected_feature_ids'] as $selected_feature_id) {
            $selected_feature_ids[$selected_feature_id] = $selected_feature_id;
          }*/

          $selected_feature_ids = $_POST['selected_feature_ids'];
          if (in_array($key, $selected_feature_ids)) {
            $nodes[$key]['data']->displayed = True;
          }
        }

        //Allow others modules to modify the output
        foreach (module_implements('wikicompare_comparative_table_prepare_itemlist') as $module) {
          $function = $module . '_wikicompare_comparative_table_prepare_itemlist';
          $function($key, $nodes, $_POST);
        }

      }

      if (isset($_POST['forbidden_nid'])) {
        $itemlist_settings['forbidden_nid'] = $_POST['forbidden_nid'];
      }

      $dialog = 0;
      $dialog_text = '';
      if (isset($_POST['dialog'])) {
        $itemlist_settings['dialog'] = 1;
        $itemlist_settings['node_link'] = 0;
        $dialog_text = 'dialog_';
      }
dpm($nodes, 'nodes');
      //Building the data for the item list
      $item_list_data = get_item_list($nodes, $type, $subaction, 0, $itemlist_settings);

      //Rendering the item list
      $output = theme_item_list(array('items' => $item_list_data, 'title' => '',  'type' => 'ul', 'attributes' => array()));

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We prepared a div under the parent compared. This command will fill it with the compared children, and replace anything that was here before.

      $commands[] = ajax_command_html('#'. $type . '_children_' . $dialog_text . $nid, $output);
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
 * Ajax callback cunction called by javascript to recover the feature children of the clicked feature
 */
function get_feature_response($method = 'ajax') {

  $fid = $_POST['node_id'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //If we want to displayed the compared children
    if ($_POST['action'] == 'display') {



      $fastedit_status = 0;
      if (!empty($_POST['fastedit_status'])) {
        $fastedit_status = $_POST['fastedit_status'];
      }

      $features = request_db('feature', $fastedit_status, 'parent', array($fid));

      $features_ids = array();
      foreach ($features as $key => $feature) {
        $features_ids[$key] = $key;
      }

      //We recover from javascript argument the id of the columns displayed in the table, to know the cell we have to add
      if (!empty($_POST['compared_column_ids'])) {
        //Recover the implementation needed for the cells
        $implementations = request_db('implementation', $fastedit_status, 'parent', NULL, $_POST['compared_column_ids'], $features_ids);
      }
      //Building the data for the table row

      $feature_row_data = get_rows_data($features, $_POST['compared_column_ids'], $implementations, 0);


      $output = render_rows($feature_row_data, $fastedit_status);

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
function toggle_compared_checkbox_response($method = 'ajax'){

  $cid = $_POST['node_id'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

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
      $header = '<th id="header_compared_' . $cid . '" class="header_compared" style="display:none;"><span class="compared_title_' . $cid . '">' . $compared->title . '</span> ' . $cid . '</th>';

      //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
      if (!empty($_POST['feature_ids'])) {
        //Recover the implementation needed for the cells
        $implementations = request_db('implementation', $fastedit_status, 'parent', NULL, array($cid), $_POST['feature_ids']);

        if ($_POST['computed']) {
          $features_array = get_recursive_data('feature', $_POST['feature_ids'], $fastedit_status);
          $features_ids = $features_array['tree'];
        } else {
          foreach ($_POST['feature_ids'] as $feature_id) {
            $features_ids[$feature_id] = $feature_id;
          }
        }

        $feature_row_data = get_rows_data($features_ids, array($cid), $implementations, $_POST['computed']);

        $cells = array();
        foreach ($_POST['feature_ids'] as $feature_id) {

          $implementation = $implementations[$feature_id][$cid];

          $cells[$implementation['data']->feature_id] .= render_implementation($implementation, $fastedit_status);
        }
      }


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


function get_dialog_response($action, $type, $container, $nid){


  $output = t("<div id='dialog-content'>");


  //Find all the features on the first level of the tree
  $nodes = request_db($type);

  $output .= '<div id="initialize_selected_feature_dialog_ids">';
  if ($container == 'manual_selected_features') {
    $output .= 'manual';
  } else {
   $output .= 'form';
  }
  $output .= '</div>';
  $output .= '<div id="dialog_type" style="display:none;">' . $type . '</div>';
  $output .= '<div id="select_container" style="display:none;">' . $container . '</div>';
  

  $itemlist_settings = initialize_itemlist_settings($action);
/*  $itemlist_settings = array(
    'fastedit_status' => 0,
    'dialog' => 0,
    'checkbox_parent' => 0,
    'checkbox_children' => 0,
    'select_link' => 0,
    'compared_link' => 0,
    'computed' => 0,
  );

  switch ($container) {
    case 'manual_select_features':
      $itemlist_settings['checkbox_children'] = 1;
      break;
    case 'form_select_features':
      $itemlist_settings['select_link'] = 1;
      break;
    case 'form_selected_parent':

    }*/

  $itemlist_settings['dialog'] = 1;
  $itemlist_settings['node_link'] = 0;

  if ($nid != 0) {
    $output .= '<div id="forbidden_nid" style="display:none;">' . $nid . '</div>';
    $itemlist_settings['forbidden_nid'] = $nid;
  }

  //Building the data for the item list
  $item_list_data = get_item_list($nodes, $type, $action, 0, $itemlist_settings);

  $output .= theme_item_list(array('items' => $item_list_data, 'type' => 'ul', 'attributes' => array()));

  //Add the compute button
  $submit_link = array(
    '#type' => 'link',
    '#title' => 'Submit',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'submit_dialog_callback/nojs',
    '#id' => 'submit_dialog_link',
    '#attributes' => array(
      'style' => 'display:none',
    ),
  );
  $output .= '<p><input id="submit_dialog_button" type="submit" value="Submit" class="button"/>' . drupal_render($submit_link) . '</p>';

  $output .= t("</div>");
  return $output;

}


function select_dialog_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

/*
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'title', 'title');
    $query->condition("n.nid", $_POST['node_id']);
    $result = $query->execute();
    foreach ($result as $record) {
      $nid = $record->nid;
      $title = $record->title;
    }*/
dpm($_POST, 'post');
    $res = get_recursive_data($_POST['type'], array($_POST['node_id']));

    $parent = $res['data'][$_POST['node_id']]['data'];
dpm($parent);
    $hidden = '';
    if ($parent) {
      $hidden = '<input type="text" size="60" value="&quot;' . $parent->title . ' (' . $parent->nid .  ')&quot;" name="' . $_POST['type'] . '_parent_' . $_POST['type'] . '[und][0][target_id]">';
    }

    $commands = array();
    $commands[] = ajax_command_html('#' . $_POST['container'], $parent->fulltitle);
    $commands[] = ajax_command_html('#edit-' . $_POST['type'] . '-parent-' . $_POST['type'], $hidden);
//    $commands[] = ajax_command_replace('#parent_title', '<span id="parent_title">' . $parent->title . '</span>');
    $commands[] = ajax_command_replace('#parent_id', '<span id="parent_id" style="display:none;">' . $parent->nid . '</span>');
    $page = array('#type' => 'ajax', '#commands' => $commands);
dpm($page, 'page');
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}


function submit_dialog_response($method = 'ajax'){
dpm($_POST, 'post');
  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

/*
    //Since in javascript we use an associative array for storing the selected_feature_ids, we need to remove the [0] in the array
    $selected_feature_ids = array();
    foreach ($_POST['selected_feature_ids'] as $selected_feature_id) {
      $selected_feature_ids[$selected_feature_id[0]] = $selected_feature_id[0];
    }*/

    $selected_feature_ids = $_POST['selected_feature_ids'];

    $feature_array = array();

    if ($selected_feature_ids) {
      $feature_array = get_recursive_data('feature', $selected_feature_ids);
    }

    $itemlist_settings = initialize_itemlist_settings('feature_list_computed');
/*
    $itemlist_settings = array(
      'fastedit_status' => 0,
      'dialog' => 0,
      'checkbox_parent' => 0,
      'checkbox_children' => 0,
      'select_link' => 0,
      'compared_link' => 0,
      'computed' => 0,
    );*/
dpm($itemlist_settings, 'settings');

    //Building the data for the item list
    $item_list_data = get_item_list($feature_array['tree'], 'feature', 'feature_list_computed', 0, $itemlist_settings);

    //Render the item list
    $output = theme_item_list(array('items' => $item_list_data, 'title' => 'Manually selected features', 'type' => 'ul', 'attributes' => array()));

//    $features = request_db('feature', 0, 'nids', $selected_feature_ids);

    $hidden = '<tbody>';
    $i = 0;
    foreach ($feature_array['data'] as $feature) {
      //We remove the feature if it's a parent feature. This case can happen if we add the feature to the need when it has no children, and then it become a parent.
      if (!$feature['data']->has_children) {
        $hidden .= '<tr><td>
        <input type="text" size="60" value="&quot;' . $feature['data']->title . ' (' . $feature['data']->nid . ')&quot;" name="need_features[und][' . $i . '][target_id]">
        </td></tr>';
        $i += 1;
      }
      
      $hidden .= '<tr><td>
        <input type="text" size="60" value="" name="need_features[und][' . $i . '][target_id]" >
        </td></tr>
        </tbody>';
    }

    $hidden_fastedit = '';
    foreach ($selected_feature_ids as $feature_id) {
      $hidden_fastedit .= '<div class="need_feature">' . $feature_id . '</div>';
    }

    $commands = array();
    $commands[] = ajax_command_html('#' . $_POST['container'], $output);
    $commands[] = ajax_command_html('#need-features-values', $hidden);
    $commands[] = ajax_command_html('#need-features', $hidden_fastedit);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}


function compute_comparative_table_response($method = 'ajax') {


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //Since in javascript we use an associative array for storing the selected_feature_ids, we need to remove the [0] in the array
/*    $selected_feature_ids = array();
    foreach ($_POST['selected_feature_ids'] as $selected_feature_id) {
      $selected_feature_ids[$selected_feature_id[0]] = $selected_feature_id[0];
    }*/

    $selected_feature_ids = $_POST['selected_feature_ids'];

    //Allow others modules to modify the output
    foreach (module_implements('wikicompare_comparative_table_prepare_compute') as $module) {
      $function = $module . '_wikicompare_comparative_table_prepare_compute';
      $function($selected_feature_ids, $_POST);
    }

    //If empty, javascript return a null string and not an empty array. So we need to assign it in a variable and manage the null case.
    $compared_columns_ids = array();
    if ($_POST['compared_column_ids']) {
      $compared_columns_ids = $_POST['compared_column_ids'];
    }

    $fastedit_status = 0;
    if (!empty($_POST['fastedit_status'])) {
      $fastedit_status = $_POST['fastedit_status'];
    }

    $feature_array = array();

    if ($selected_feature_ids) {
      $feature_array = get_recursive_data('feature', $selected_feature_ids, $fastedit_status);
    }





    $implementations = array();
    if (!empty($feature_array['ids']) && !empty($compared_columns_ids)) {

      $implementations = request_db('implementation', $fastedit_status, 'parent', NULL, $compared_columns_ids, $feature_array['ids']);

    } 


  
    $output = render_comparative_table($feature_array['tree'], $compared_columns_ids, $implementations, $fastedit_status, 1);




    //Preparing the ajax commands to return to javascript
    $commands = array();
    $commands[] = ajax_command_replace('#comparative_table', $output);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}

function make_cleaning_response($method = 'ajax') {

//dpm($_POST);

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    $commands = array();
dpm($_POST, 'post cleaning');
    $compared_ids = $_POST['compared_column_ids'];
    foreach ($_POST['compared_ids'] as $compared) {
      $compared_ids[$compared[0]] = $compared[0];
    }

    $compareds = array();
    if (!empty($compared_ids)) {
      $compareds = request_db('compared', 0, 'nids', $compared_ids);
    }
    
    foreach ($_POST['compared_ids'] as $compared) {
      if ($compared[1] != $compareds[$compared[0]]['data']->parent_id) {
        if (in_array($compared[1], $_POST['compared_displayed_ids'])) {
          $commands[] = ajax_command_invoke('#compared_link_' . $compared[1], 'click', array());
        }
        if (in_array($compareds[$compared[0]]['data']->parent_id, $_POST['compared_displayed_ids'])) {
          $commands[] = ajax_command_invoke('#compared_link_' . $compareds[$compared[0]]['data']->parent_id, 'click', array());
        }
      }
    }

    foreach($compareds as $cid => $compared) {
      $commands[] = ajax_command_invoke('.compared_title_' . $cid, 'html', array($compared['data']->title));
    }

    //Allow others modules to modify the output
    foreach (module_implements('wikicompare_comparative_table_cleaning') as $module) {
      $function = $module . '_wikicompare_comparative_table_cleaning';
      $function($commands, $_POST);
    }

    if (!$_POST['computed']) {
      $feature_ids = array();
      foreach ($_POST['feature_ids'] as $feature) {
        $feature_ids[$feature[0]] = $feature[0];
      }

      $features = array();
      if (!empty($feature_ids)) {
        $features = request_db('feature', 0, 'nids', $feature_ids);
      }
    
      $update_selected_feature = false;
      foreach ($_POST['feature_ids'] as $feature) {
        if ($feature[1] != $features[$feature[0]]['data']->parent_id) {
          $update_selected_feature = true;
          if (in_array($feature[1], $_POST['feature_displayed_ids'])) {
            $commands[] = ajax_command_invoke('#feature_link_' . $feature[1], 'click', array());
          }
          if (in_array($features[$feature[0]]['data']->parent_id, $_POST['feature_displayed_ids'])) {
            $commands[] = ajax_command_invoke('#feature_link_' . $features[$feature[0]]['data']->parent_id, 'click', array());
          }
        }
      }

      foreach($features as $fid => $feature) {
        $commands[] = ajax_command_invoke('.feature_title_' . $fid, 'html', array($feature['data']->title));
        $commands[] = ajax_command_invoke('.feature_weight_' . $fid, 'html', array($feature['data']->weight));
        $commands[] = ajax_command_invoke('.feature_type_' . $fid, 'html', array($feature['data']->type));
      }

      $implementations = array();
      if (!empty($_POST['compared_columns_ids']) && !empty($feature_ids)) {
        $implementations = request_db('implementation', $_POST['fastedit_status'], 'parent', NULL, $_POST['compared_columns_ids'], $feature_ids);
      }

      foreach($implementations as $nid => $implementation) {
        $commands[] = ajax_command_replace('#implementation_' . $nid, render_implementation($implementation, $_POST['fastedit_status']));
      }


      if ($update_selected_feature) {
        $selected_feature_ids = array();
        foreach ($_POST['selected_feature_ids'] as $selected_feature_id) {
        $selected_feature_ids[$selected_feature_id[0]] = $selected_feature_id[0];
        }
        $feature_array = array();
        if ($selected_feature_ids) {
          $feature_array = get_recursive_data('feature', $selected_feature_ids);
        }
        //Building the data for the item list
        $item_list_data = get_item_list($feature_array['tree'], 'feature', 'feature_list_computed', 0, 0);
        //Render the item list
        $output = theme_item_list(array('items' => $item_list_data, 'title' => 'Manually selected features', 'type' => 'ul', 'attributes' => array()));
        $commands[] = ajax_command_html('#selected_feature_itemlist', $output);
      }

    }

    //Preparing the ajax commands to return to javascript

    $commands[] = ajax_command_invoke('.form_fastedit', 'remove', array());
    $page = array('#type' => 'ajax', '#commands' => $commands, '#arguments' => array('test'));
dpm($page);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}

/*
 * Function which will build the item list. Used in table initial building, in compared ajax callback and in modal dialog
 */
function get_item_list($nodes, $type, $action, $parent_node, $itemlist_settings){

dpm($itemlist_settings);

  $dialog_text = '';
  if ($itemlist_settings['dialog']) {
    $dialog_text = 'dialog_';
  }

  $items = array();
  foreach ($nodes as $nid => $node_array){

    if ($nid == $itemlist_settings['forbidden_nid']) {
      continue;
    }

    $node = $node_array['data'];

    $title_title = '<span class="' . $type . '_title_' . $nid . '">' . $node->title . '</span>';
    //If the node has children, the node name will become a link calling the callback function to display his children
    if ($node->has_children == 1){
      $class = array('list_item_link ', $action, $type);

      if ($itemlist_settings['dialog']) {
        $class[] = 'dialog';
      }
      if ($itemlist_settings['computed']) {
        $class[] = 'computed';
      }
      $title = l($title_title, 'get_item_list_children_callback/nojs/',  array('attributes' => array('id' => $type . '_link_' . $dialog_text . $nid, 'class' => $class), 'html' => True));
    } else {
      $title = $title_title;
    }

    //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table. Unless we configure the system to compute the compared parent, only the compared with no children will have a checkbox.
    $checkbox_area = '';
    $img_link_to_node = '';
//    if ($action == 'compared_main_table') {
    if ($itemlist_settings['checkbox_children']) {
      if ($itemlist_settings['checkbox_parent'] || ($node->has_children != 1)) {
        $checkbox_settings = array('element' => array(
          '#title' => $nid,
          '#id' => 'compared_checkbox_' . $nid,
//          '#attributes' => array(
//            'class' => array('compared_checkbox'),
//          ),
        ));


        if ($itemlist_settings['compared_link']) {
          $checkbox_settings['element']['#attributes']['class'] = array('compared_checkbox');
        } else {
          $checkbox_settings['element']['#attributes']['class'] = array('itemlist_checkbox ' . $type);
        }

        if (isset($node->displayed)) {
          $checkbox_settings['element']['#checked'] = True;
//TODO Pas le bon lien          $checkbox_link['#attributes']['class']['displayed'] = 'displayed';        
        }

        $checkbox_area = theme_checkbox($checkbox_settings) . ' ';

        if ($itemlist_settings['compared_link']) {

//          $checkbox_settings['element']['#attributes']['class'] = array('compared_checkbox');

          //We were not able to ajaxify the checkbox, so instead the checkbox will call this hidden link
          $checkbox_link = array(
            '#type' => 'link',
            '#title' => 'toggle',
            //The link for the callback function which will display or hide the column in the table
            '#href' => 'toogle_compared_checkbox_callback/nojs/',
            '#id' => 'compared_checkbox_link_' . $nid,
            '#attributes' => array(
              'class' => array('compared_checkbox_link' => 'compared_checkbox_link'),
              'style' => 'display:none',
            )
          );

          $checkbox_area .= drupal_render($checkbox_link);
        }
      }
    }

    if ($itemlist_settings['node_link']) {

      //Create the image link to go to the node page
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to compared ') . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_node = ' ' . l($img, 'node/' . $nid, array('attributes' => array('id' => $type . '_node_link_' . $nid, 'class' => array($type . '_node_link')), 'html' => True));

      if ($itemlist_settings['fastedit_status'] == 1) {
        $img_link_to_node .= add_fastedit_items($type, $node_array);
      }
    }
/*
    if ($action == 'select_multi_dialog') {
      if ($node->has_children != 1) {
        $checkbox_settings = array('element' => array(
          '#title' => $nid,
          '#id' => $type . '_checkbox_' . $nid,
          '#attributes' => array(
            'class' => array('checkbox_dialog ' . $type),
          ),
        ));
        if (isset($node->displayed)) {
          $checkbox_settings['element']['#checked'] = True;
        }
        $checkbox_area = theme_checkbox($checkbox_settings) . ' ';
      }
    }*/

    if ($itemlist_settings['select_link']) {

      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Select ') . $type . ' ' . $nid,
        'height' => '100%',
      ));

      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link = l($img, 'select_dialog_callback/nojs', array('attributes' => array('id' => 'select_dialog_' . $nid, 'class' => array('select_simple_dialog')), 'html' => True));
      $checkbox_area = $img_link . ' ';
    }

    
    $items[$nid]['id'] = $type . '_item_' . $dialog_text . $nid;
    $items[$nid]['data'] = $checkbox_area . $title . $img_link_to_node;
    $items[$nid]['class'] = array($type . '_item list_item');
    if ($parent_node != 0) {
      $items[$nid]['class'] = array('feature_children_computed_' . $parent_node);
      $items[$nid]['style'] = 'display:none';
    }


    if ($itemlist_settings['computed'] && $node->has_children) {
       $items[$nid]['children'] = get_item_list($node_array['children'], $type, $action, $nid, $itemlist_settings);
    } else {
      //After the compared, we add the div which will contain the children
      $items[$nid]['data'] .= '<div id="' . $type . '_children_' . $dialog_text . $nid . '" class="'. $type . '_children" style="display:none;"></div>';
    }


  }

  //This case happen when the only children of the clicked node is the forbidden node.
  if (empty($items)) {
    $items[]['data'] = "You can't select this node as parent of himself.";
  }

  return $items;

}

function get_recursive_data($type, $ids, $fastedit_status=0){

  $res = array();
  $res = build_recursive_tree($type, $ids, $res, $fastedit_status);

  $res = build_fulltitle($res, $res['tree'], '');

  return $res;

}

function build_fulltitle($res, $tree, $parent_path) {

  foreach ($tree as $nid => $node) {

    if ($parent_path) {
      $fulltitle = $parent_path . ' / ' . $node['data']->title;
    } else {
      $fulltitle = $node['data']->title;
    }
dpm($fulltitle);
    $res['data'][$nid]['data']->fulltitle = $fulltitle;
    if (!empty($node['children'])) {
      $res = build_fulltitle($res, $node['children'], $fulltitle);
    }

  }

  return $res;

}


function build_recursive_tree($type, $ids, $res, $fastedit_status=0){

  $parent_ids = array();

  //No other way here but to put this query in recursive function. Some improvement for later may be to use the WITH RECURSIVE function of postgresql.

  $nodes = request_db($type, $fastedit_status, 'nid', $ids);

  foreach ($nodes as $nid => $node) {
    //Check if some children of this node launched the recursive function to find this node as their parent. Then assign them as children of this node and unset the node in the array.
    if (isset($res['parent_ressource'][$nid]['children'])) {
      $node['children'] = $res['parent_ressource'][$nid]['children'];
      unset($res['parent_ressource'][$nid]);
    }

    //Build a list of all id, parent and children, to use them in implementation sql request
    $res['ids'][$nid] = $nid;
    $res['data'][$nid] = $node;

    //If the node has parent, assign him in the parent array and tell the recursive function to find the parent next time. Else, set the node at the root of the array.
    if ($node['data']->parent_id) {
      $res['parent_ressource'][$node['data']->parent_id]['children'][$nid] = $node;
      $parent_ids[$node['data']->parent_id] = $node['data']->parent_id;
    } else {
      $res['tree'][$nid] = $node;
    }
  }

  //If there is others parents to add in the array, relaunch the recursive function until all parents are found.
  if ($parent_ids){
    $res = build_recursive_tree($type, $parent_ids, $res, $fastedit_status);
  } else {
    unset($res['parent_ressource']);
  }
  
  return $res;

}

/*
 * Function which will build the features row. Used in table initial building and in feature ajax callback
 */
function get_rows_data($features, $compareds, $implementations, $computed){

  $rows = array();

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

    $direct_children = array();
    foreach ($children as $key => $child) {
      if (isset($child['direct-child'])) {
        $direct_children[$key] = $child;
        unset($children[$key]['direct-child']);
      }
      
    }

    $rows[$fid]['implementations'] = array();
    //Adding one cell for each implementation, which contain the details of the cells
    foreach ($compareds as $compared) {


      $implementation = $implementations[$fid][$compared];

      if ($computed) {
        //The type will be used in the wikicompare_compute_percent function
        $implementation['data']->type = $feature['data']->type;
        //The weight will be used in the parent wikicompare_compute_percent function
        $implementation['data']->weight = $feature['data']->weight;


        $through_feature_childs = array();
        foreach ($direct_children as $child) {
          $child_implementation = $child['implementations'][$compared]['data'];
          $through_feature_childs[$child_implementation->feature_id] = $child_implementation;
        }
        if ($feature['data']->has_children) {
          $implementation['data'] = wikicompare_compute_percent($implementation['data'], $through_feature_childs);
        }
      }

      $rows[$fid]['implementations'][$compared] = $implementation;

    }

    foreach ($children as $key=> $child) {
      $rows[$key] = $child;
    }


  }

  return $rows;

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
  $output .= '</tbody>';
  $output .= '</table>';

  return $output;


}

function render_rows($feature_row_data, $fastedit_status) {

  $output = '';

  //Add a row for each feature children
  foreach ($feature_row_data as $fid => $feature_array) {

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
      $img_link_to_node .= add_fastedit_items('feature', $feature_array); 
    }

    $title_title = '<span class="feature_title_' . $fid . '">' . $feature->title . '</span>';
    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($feature->has_children == 1){
      $title = l($title_title . ' ' . $fid, 'get_feature_callback/nojs/',  array('attributes' => array('id' => 'feature_link_' . $fid, 'class' => array('feature_link feature_link_children_' . $fid)), 'html' => True));
    } else {
      $title = $title_title;
    }

    //Creating the first cell of the row, containing the feature details
    $output .= '<td>' . $title . ' ' . $img_link_to_node  . '<br/> Weight : <span class="feature_weight_' . $fid . '">' .  $feature->weight . '</span><br/> Type : <span class="feature_type_' . $fid . '">' .  $feature->type . '</span></td>';

    //Add a column for each column in the table
    foreach ($feature_array['implementations'] as $implementation) {
      $output .= render_implementation($implementation, $fastedit_status);
    }
    $output .= '</tr>';
  }

  return $output;


}

function render_implementation($implementation_array, $fastedit_status) {

  $implementation = $implementation_array['data'];

  //Create the image link to go to the node page
  $img = theme('image', array(
    'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
    'alt' => t('Link to implementation ') . $implementation->nid,
    'height' => '100%',
  ));
  //Create the link. The html = True indicate that the title of the link contain html.
  $img_link_to_node = l($img, 'node/' . $implementation->nid,  array('attributes' => array('id' => 'implementation_node_link_' . $implementation->nid, 'class' => array('implementation_node_link')), 'html' => True));
  if ($fastedit_status == 1) {
    $img_link_to_node .= add_fastedit_items('implementation', $implementation_array); 
  }

  $output = '<td id="implementation_' . $implementation->nid . '" class="implementation_cell ' . $implementation->css_class . ' implementation_compared_' . $implementation->compared_id . ' implementation_feature_' . $feature->nid . '">' . $implementation->nid . ' ' .  $img_link_to_node . '<br/>Feature : ' . $implementation->feature_id . '<br/>Compared : ' . $implementation->compared_id . '<br/>' . $implementation->percent . '%</td>';

  return $output;
}


function initialize_itemlist_settings($subaction) {

  $itemlist_settings = array(
    'fastedit_status' => 0,
    'dialog' => 0,
    'forbidden_nid' => 0,
    'node_link' => 0,
    'checkbox_parent' => 0,
    'checkbox_children' => 0,
    'select_link' => 0,
    'compared_link' => 0,
    'computed' => 0,
  );

  switch ($subaction) {
    case 'compared_main_table':
      $itemlist_settings['checkbox_children'] = 1;
      $itemlist_settings['compared_link'] = 1;
      $itemlist_settings['node_link'] = 1;
      if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update') {
        $itemlist_settings['checkbox_parent'] = 1;
      }
      break;
    case 'feature_list_computed':
      $itemlist_settings['computed'] = 1;
      break;
    case 'select_multi_dialog':
      $itemlist_settings['checkbox_children'] = 1;
      $itemlist_settings['node_link'] = 1;
      break;
    case 'select_simple_dialog':
      $itemlist_settings['select_link'] = 1;
      break;
  }

  return $itemlist_settings;
}
?>
