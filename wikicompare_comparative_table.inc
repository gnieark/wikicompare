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
  
/*
  //Find all the compared on the first level of the tree
  $res = request_db('compared', array('can_be_translated' => 1));

  $form['#compared_items'] = $res;
*/

/*
  //Find all the features on the first level of the tree
  $res = request_db('feature', array('can_be_translated' => 1));

  $form['#feature_items'] = $res;
*/
  $form = array();
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
/*
  //Prepare the array to use as argument for the item list building function.
  $compareds = array();
  //element_children is used to avoid the children beginning by # which are inserted by drupal in $form

  $itemlist_settings = initialize_itemlist_settings('compared_main_table');

  //Building the data for the item list
  $item_list_data = get_item_list($form['#compared_items'], 'compared', 'compared_main_table', 0, $itemlist_settings);


  //Render the item list
  $output = theme_item_list(array('items' => $item_list_data, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));
*/


  $checkbox_settings =  array(
    '#type' => 'checkbox',
    '#title' => 'Display draft items',
    '#id' => 'checkbox-draft-items',
   );
  $output = drupal_render($checkbox_settings);

  $checkbox_settings =  array(
    '#type' => 'checkbox',
    '#title' => 'Display closed items',
    '#id' => 'checkbox-closed-items',
   );
  $output .= drupal_render($checkbox_settings);

  $output .= '<div id="manual_selected_features"></div>';

dpm(language_list());

  //Add the link to open the select feature popup
  $select_feature_link = array(
    'text' => 'Select features',
    'title' => 'Select features',
    'selector' => 'dialog-content',
    'path' => 'get_dialog_callback/multidialog/feature/manual_selected_features/0/manual_selected_features/none',
    'id' => 'select_feature_link',

  );
  $output .= '<p>' . theme('simple_dialog_link', $select_feature_link) . '</p>';
  
/*
  //Allow others modules to modify the output
  foreach (module_implements('wikicompare_comparative_table_before_compute') as $module) {
    $function = $module . '_wikicompare_comparative_table_before_compute';
    $function($output);
  }
*/
  if (module_exists('wikicompare_needs')) {
    wikicompare_needs_wikicompare_comparative_table_before_compute($output);
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
  $output .= '<p><input id="compute_table_button" type="submit" value="Compute table" class="button"/>' . drupal_render($compute_link);
 



  //Add the reset button
  $reset_link = array(
    '#type' => 'link',
    '#title' => 'Reset table',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'compute_comparative_table_callback/nojs',
    '#id' => 'reset_table_link',
/*    '#attributes' => array(
      'style' => 'display:none',
    ),*/
  );
  $output .= ' ' . drupal_render($reset_link) . '</p>';

  $output .= wikicompare_table_render_compared();


  

  $output .= render_comparative_table();


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
/*
  //Add the link to go on FastEdit mode
  $rebuild_compared_link = array(
    '#type' => 'link',
    '#title' => 'Rebuild Compareds',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'rebuild_table_callback/nojs/compared',
    '#id' => 'rebuild_compared_link',
    '#attributes' => array(
      'style' => 'display:none',
    ),

  );

  $output .= '<p>' . drupal_render($rebuild_compared_link) . '</p>';

  //Add the link to go on FastEdit mode
  $rebuild_feature_link = array(
    '#type' => 'link',
    '#title' => 'Rebuild Features',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'rebuild_table_callback/nojs/feature',
    '#id' => 'rebuild_feature_link',
    '#attributes' => array(
      'style' => 'display:none',
    ),

  );

  $output .= '<p>' . drupal_render($rebuild_feature_link) . '</p>';*/

  return $output;
}


/*
 * Ajax callback cunction called by javascript to recover the compared children of the clicked compared
 */
function get_item_list_children_response($method = 'ajax') {


  $nid = $_POST['node_id'];
  $type = $_POST['type'];
  $context = $_POST['context'];

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {



    //If we want to displayed the children
    if ($_POST['action'] == 'display') {

      $itemlist_settings = initialize_itemlist_settings($context);

      $itemlist_settings['context'] = $context;

      if (!empty($_POST['fastedit_status'])) {
        $itemlist_settings['fastedit_status'] = $_POST['fastedit_status'];
      }
      $nodes = request_db($type, array('fastedit_status' => $itemlist_settings['fastedit_status'], 'can_be_translated' => 1, 'states' => $_POST['states']), 'parent', array($nid));


      //Prepare the array to use as argument for the item list building function

      foreach ($nodes as $key => $record) {

        if ($type == 'compared' && $context == 'table') {
          //If already displayed in the table, we check it by default
          if (!empty($_POST['compared_column_ids'])) {
            if (in_array($key, $_POST['compared_column_ids'])) {
              $nodes[$key]['data']->displayed = True;
            }
          }

        }

        if ($type == 'feature' && $context == 'multidialog') {

          if ($_POST['selected_feature_ids'] == '') {
            $_POST['selected_feature_ids'] = array();
          }

          $selected_feature_ids = $_POST['selected_feature_ids'];
          if (in_array($key, $selected_feature_ids)) {
            $nodes[$key]['data']->displayed = True;
          }
        }
/*
        //Allow others modules to modify the output
        foreach (module_implements('wikicompare_comparative_table_prepare_itemlist') as $module) {
          $function = $module . '_wikicompare_comparative_table_prepare_itemlist';
          $function($key, $nodes, $_POST);
        }
*/

        if (module_exists('wikicompare_needs')) {
          wikicompare_needs_wikicompare_comparative_table_prepare_itemlist($key, $nodes, $_POST);
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

      //Building the data for the item list
      $item_list_data = get_item_list($nodes, $type, $context, $nid, $itemlist_settings);

      //Rendering the item list
      $output = theme_item_list(array('items' => $item_list_data, 'title' => '',  'type' => 'ul', 'attributes' => array()));

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We prepared a div under the parent compared. This command will fill it with the compared children, and replace anything that was here before.

      $commands[] = ajax_command_html('#'. $type . '_' . $context . '_children_' . $nid, $output);
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

      $features = request_db('feature', array('fastedit_status' => $fastedit_status, 'can_be_translated' => 1, 'states' => $_POST['states']), 'parent', array($fid));

      $features_ids = array();
      foreach ($features as $key => $feature) {
        $features_ids[$key] = $key;
      }

      $implementations = array();
      //We recover from javascript argument the id of the columns displayed in the table, to know the cell we have to add
      if (!empty($_POST['compared_column_ids'])) {
        //Recover the implementation needed for the cells
        $implementations = request_db('implementation', array('fastedit_status' => $fastedit_status), 'parent', NULL, $_POST['compared_column_ids'], $features_ids);
      }
      //Building the data for the table row

      if ($_POST['compared_column_ids'] == '') {
        $_POST['compared_column_ids'] = array();
      }
      $feature_row_data = get_rows_data($features, $_POST['compared_column_ids'], $implementations, 0);


      $output = render_rows($feature_row_data, $fastedit_status);

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We add the code after the parent row. Note we can't use ajax_command_after because it adds an unwanted div
      $commands[] = ajax_command_invoke('#feature_table_' . $fid, 'after', array($output));

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
/*    
      //Recover the detail of the compared we want to add
      $query = db_select('cache_compared', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->condition("s.nid", $cid);
      $result = $query->execute();
      foreach ($result as $record) {
        $compared = $record;
      }*/

      //Recover the detail of the compared we want to add
      $compared = request_db('compared', array('can_be_translated' => 1), 'nids', array($cid));


      //Add the header of the new column, with the compared detail
      $header = '<th id="header_compared_' . $cid . '" class="header_compared" style="display:none;"><span class="compared_title_' . $cid . '">' . $compared[$cid]['data']->title . '</span> ' . $cid . '</th>';

      //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
      if (!empty($_POST['feature_ids'])) {

        $features = request_db('feature', array('states' => array('draft' => 'draft', 'closed' => 'closed')), 'nids', $_POST['feature_ids']);

        //Recover the implementation needed for the cells
        $implementations = request_db('implementation', array('fastedit_status' => $fastedit_status), 'parent', NULL, array($cid), $_POST['feature_ids']);
/*
        if ($_POST['computed']) {
          $features_array = get_recursive_data('feature', $_POST['feature_ids'], $fastedit_status);

          $features = $features_array['tree'];
        } else {
          $features = request_db('feature', array(), 'nids', $_POST['feature_ids']);

        }

        $feature_row_data = get_rows_data($features, array($cid), $implementations, $_POST['computed']); */

        $cells = array();
        foreach ($features as $fid => $feature) {

          $implementation = $implementations[$fid][$cid];

          $cells[$implementation['data']->feature_id] = render_implementation($implementation, $feature, $fastedit_status);
        }
      }


      //Preparing the ajax commands to return to javascript
      $commands = array();
      //Add the new cell at the end of the header
      $commands[] = ajax_command_append('#comparative_table_header', $header);
      //Add the new cells at the end of each row
      foreach ($cells as $key => $cell) {
        $commands[] = ajax_command_append('#feature_table_' . $key, $cell);
      }
      $commands[] = ajax_command_invoke('#compared_checkbox_' . $cid, 'removeAttr', array('disabled'));
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    //If we want to remove the column
    } else {

      //In this case we return nothing, everything is managed on the javascript side
      $commands = array();
      $commands[] = ajax_command_invoke('#compared_checkbox_' . $cid, 'removeAttr', array('disabled'));
      $page = array('#type' => 'ajax', '#commands' => $commands);
      return $page;

    }

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}


function get_dialog_response($context, $type, $container, $nid, $container_autocomplete, $container_id){




  $output = t("<div id='dialog-content'>");


  //Find all the features on the first level of the tree
  $nodes = request_db($type, array('can_be_translated' => 1, 'states' => array('draft' => 'draft', 'closed' => 'closed')));

  $output .= '<div id="initialize_selected_feature_dialog_ids" style="display:none;">';
  if ($container == 'manual_selected_features') {
    $output .= 'manual';
  } else {
   $output .= 'form';
  }
  $output .= '</div>';
  $output .= '<div id="dialog_type" style="display:none;">' . $type . '</div>';
  $output .= '<div id="select_container" style="display:none;">' . $container . '</div>';
  $output .= '<div id="select_container_autocomplete" style="display:none;">' . $container_autocomplete . '</div>';
  $output .= '<div id="select_container_id" style="display:none;">' . $container_id . '</div>';

  $itemlist_settings = initialize_itemlist_settings($context);

  $itemlist_settings['context'] = $context;
  $itemlist_settings['node_link'] = 0;

  if ($nid != 0) {
    $output .= '<div id="forbidden_nid" style="display:none;">' . $nid . '</div>';
    $itemlist_settings['forbidden_nid'] = $nid;
  }

  //Building the data for the item list
  $item_list_data = get_item_list($nodes, $type, $context, 0, $itemlist_settings);
//      $item_list_data = get_item_list($nodes, $type, $context, $nid, $itemlist_settings);

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

  if ($context == 'multidialog') {
    $output .= '<p><input id="submit_dialog_button" type="submit" value="Submit" class="button"/>' . drupal_render($submit_link) . '</p>';
  }

  $output .= t("</div>");
  return $output;

}


function select_dialog_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    $res = get_recursive_data($_POST['type'], array($_POST['node_id']));

    $parent = $res['data'][$_POST['node_id']]['data'];

    $hidden = '';
    if ($parent) {
      $hidden = '<input type="text" size="60" value="&quot;' . $parent->title . ' (' . $parent->nid .  ')&quot;" name="' . str_replace("-", "_", $_POST['container_autocomplete']) . '[und][0][target_id]">';
/*
      $hidden = '<input type="text" size="60" value="&quot;' . $parent->title . ' (' . $parent->nid .  ')&quot;" name="wikicompare_parent_id[und][0][target_id]">';*/

    }

    $commands = array();
    $commands[] = ajax_command_html('#' . $_POST['container'], $parent->fulltitle);
    $commands[] = ajax_command_html('#edit-' . $_POST['container_autocomplete'], $hidden);
    $commands[] = ajax_command_html('#' . $_POST['container_id'], $parent->nid);
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;


  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}


function submit_dialog_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {


    $selected_feature_ids = $_POST['selected_feature_ids'];

    $feature_array = array();

    if ($selected_feature_ids) {
      $feature_array = get_recursive_data('feature', $selected_feature_ids);
    }

    $itemlist_settings = initialize_itemlist_settings('feature_list_computed');
    if ($_POST['container'] == 'manual_selected_features') {
      $itemlist_settings['context'] = 'manual';
    } else {
      $itemlist_settings['context'] = 'selected';
    }

    //Building the data for the item list
    $item_list_data = get_item_list($feature_array['tree'], 'feature', 'selected', 0, $itemlist_settings);
//      $item_list_data = get_item_list($nodes, $type, $context, $nid, $itemlist_settings);

    //Render the item list
    $output = theme_item_list(array('items' => $item_list_data, 'title' => 'Manually selected features', 'type' => 'ul', 'attributes' => array()));
dpm($output, 'themeitemlist');
    $hidden = '<tbody>';
    $i = 0;
    foreach ($feature_array['data'] as $feature) {
      //We remove the feature if it's a parent feature. This case can happen if we add the feature to the need when it has no children, and then it become a parent.
      if (!$feature['data']->has_children) {
        $hidden .= '<tr><td>
        <input type="text" size="60" value="&quot;' . $feature['data']->title . ' (' . $feature['data']->nid . ')&quot;" name="wikicompare_features[und][' . $i . '][target_id]">
        </td></tr>';
        $i += 1;
      }
      
      $hidden .= '<tr><td>
        <input type="text" size="60" value="" name="wikicompare_features[und][' . $i . '][target_id]" >
        </td></tr>
        </tbody>';
    }

    $hidden_fastedit = '';
    foreach ($selected_feature_ids as $feature_id) {
      $hidden_fastedit .= '<div class="need_feature">' . $feature_id . '</div>';
    }

    $commands = array();
    $commands[] = ajax_command_html('#' . $_POST['container'], $output);
    $commands[] = ajax_command_html('#wikicompare-features-values', $hidden);
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

    $selected_feature_ids = array();
    if (!isset($_POST['reset'])) {
      if ($_POST['selected_feature_ids'] == '') {
        $_POST['selected_feature_ids'] = array();
      }

      $selected_feature_ids = $_POST['selected_feature_ids'];

  /*
      //Allow others modules to modify the output
      foreach (module_implements('wikicompare_comparative_table_prepare_compute') as $module) {
        $function = $module . '_wikicompare_comparative_table_prepare_compute';
        $function($selected_feature_ids, $_POST);
      }
  */

  
      if (module_exists('wikicompare_needs')) {
        wikicompare_needs_wikicompare_comparative_table_prepare_compute($selected_feature_ids, $_POST);
      }

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

    $commands = array();

    if (module_exists('wikicompare_needs')) {
      $commands[] = ajax_command_replace('#comparative_table_main_need', wikicompare_needs_table_render_need(array('fastedit_status' => $fastedit_status, 'states' => $_POST['states'])));
    }

    $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_compared(array('fastedit_status' => $fastedit_status, 'states' => $_POST['states'])));


    $settings = array('fastedit_status' => $fastedit_status, 'states' => $_POST['states'], 'colspan' => $_POST['nb_compareds']);
    if ($selected_feature_ids && !isset($_POST['reset'])) {

      $feature_array = get_recursive_data('feature', $selected_feature_ids, $fastedit_status);

      $settings['feature_ids'] = $feature_array['ids'];
      $settings['computed'] = 1;
      $output = render_comparative_table($feature_array['tree'], $compared_columns_ids, $settings);
    } else {
      $output = render_comparative_table(array(), $compared_columns_ids, $settings);
    }




/*
    $implementations = array();
    if (!empty($feature_array['ids']) && !empty($compared_columns_ids)) {

      $implementations = request_db('implementation', array('fastedit_status' => $fastedit_status), 'parent', NULL, $compared_columns_ids, $feature_array['ids']);

    } 
*/

  
    //$output = render_comparative_table($feature_array['tree'], $compared_columns_ids, $fastedit_status, 1);




    //Preparing the ajax commands to return to javascript

    $commands[] = ajax_command_replace('#comparative_table', $output);
    $page = array('#type' => 'ajax', '#commands' => $commands);

    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}

/*
function reset_table_response($method = 'ajax') {


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {



    //If empty, javascript return a null string and not an empty array. So we need to assign it in a variable and manage the null case.
    $compared_columns_ids = array();
    if ($_POST['compared_column_ids']) {
      $compared_columns_ids = $_POST['compared_column_ids'];
    }

    $fastedit_status = 0;
    if (!empty($_POST['fastedit_status'])) {
      $fastedit_status = $_POST['fastedit_status'];
    }


//TODO MERGE WITH COMPUTE

    //Preparing the ajax commands to return to javascript
    $commands = array();
    $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_compared());
    $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $compared_columns_ids, $fastedit_status, 0));
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}
*/

function make_cleaning_response($method = 'ajax') {

dpm($_POST, 'post');
  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    $commands = array();
    $update_selected_feature = false;


    $types = array('compared', 'feature');
    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_wikicompare_node_types($types);
    }

    foreach ($types as $type) {

      if ($type == 'feature' && $_POST['computed']) {
        continue;
      }

      if ($_POST[$type . '_displayed_ids'] == '') {
        $_POST[$type . '_displayed_ids'] = array();
      }

      $node_ids = array();  //$_POST['compared_column_ids'];
      foreach ($_POST[$type . '_ids'] as $node) {
        $node_ids[$node['nid']] = $node['nid'];
      }
    

      $nodes = array();
      if (!empty($node_ids)) {
        $nodes = request_db($type, array('fastedit_status' => $_POST['fastedit_status'], 'can_be_translated' => 1), 'nids', $node_ids);
      }


      $in_db_nodes = request_db($type, array('states' => $_POST['states']));
      $in_db_nodes_ids = array();
      foreach ($in_db_nodes as $key => $node) {
        $in_db_nodes_ids[$key] = $key;
      }
dpm($type);      
dpm($nodes, 'nodes');
dpm($in_db_nodes_ids, 'indb_nodes');

      $in_table_node_ids = array();
      $reset = False;
      //We test all nodes present in the table
      foreach ($_POST[$type . '_ids'] as $node) {

        //Listing all node present in table in a array for later use
        $in_table_node_ids[$node['nid']] = $node['nid'];
        //If the node has a parent in the table
        if (isset($node['parent_id'])) {
          //If the parent of the node in the table is different of the parent of the node in db
          if ($node['parent_id'] != $nodes[$node['nid']]['data']->parent_id) {
dpm($node);
            if ($type == 'feature') {
              //In the case of a feature, it means there is a structural change so better refresh the manual_selected_feature itemlist
              $update_selected_feature = true;
            }
            //If the parent in table is currently displaying his children, then the tested node is displayed as his child but isn't anymore, so we need to hide it
            if (in_array($node['parent_id'], $_POST[$type . '_displayed_ids'])) {
dpm('reset1');
              $node1 = request_db($type, array(), 'nids', array($node['parent_id']));
              $node1 = $node1[$node['parent_id']];
              //??
//              if ($node1['data']->parent_id != NULL) {
              $commands[] = ajax_command_invoke('#' . $type . '_table_link_' . $node['parent_id'], 'click', array());
//              } else {

//                $reset = True;
                
//              }
            }


            //If the parent of the node in db is displaying his children in the table, then the tested node is missing among the children so we need to hide the children of the parent. Also, if the tested node is now without parent, then we need to reset the table to display it.
            if (in_array($nodes[$node['nid']]['data']->parent_id, $_POST[$type . '_displayed_ids']) || $nodes[$node['nid']]['data']->parent_id == NULL) {
dpm('reset2');
              if ($nodes[$node['nid']]['data']->parent_id != NULL) {
                $commands[] = ajax_command_invoke('#' . $type . '_table_link_' . $nodes[$node['nid']]['data']->parent_id, 'click', array());

              } else {

                $reset = True;
              }
            }
          }




        }
dpm($node['nid']);
dpm($node['has_children'], 'has_children from table');
dpm($nodes[$node['nid']]['data']->has_children, 'has_children from table');
        if ($node['has_children'] != $nodes[$node['nid']]['data']->has_children) {
dpm('test ok');
          $commands[] = ajax_command_replace('#' . $type . '_table_supertitle_' . $node['nid'], wikicompare_get_supertitle_item($type, $nodes[$node['nid']]['data'], array('context' => 'table')));
          if ($nodes[$node['nid']]['data']->has_children == 0) {
            $commands[] = ajax_command_invoke('#' . $type . '_table_item_'. $node['nid'], 'removeClass', array('has_children'));
          }
        

      
dpm($commands, 'commands');
//TODO 
// Regenerate title of this item
// If node['has_children'] from db = 0, hide children
// Agir directement sur le title via une commande, et utiliser addClass
        }


        //If one of the node without parent displayed in table isn't in the first level in db anymore
        if ((!in_array($node['nid'], $in_db_nodes_ids)) && !isset($node['parent_id'])) {
dpm('reset3');
          $reset = True;

        }
      }
dpm($in_table_node_ids, 'intable_nodes');
      foreach ($in_db_nodes_ids as $nid) {
        //If one of the node present in the first level in db isn't displayed in the table
        if (!in_array($nid, $in_table_node_ids)) {
dpm('reset4');
          $reset = True;
        }
      } 

      if ($reset == True) {
        switch ($type) {
          case 'compared':
            $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_compared(array('states' => $_POST['states'])));
            break;
          case 'feature':
            $settings = array(
              'fastedit_status' => $_POST['fastedit_status'],
              'computed' => 0
            );
            $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $_POST['compared_columns_ids'], $settings));
            break;
        }

      }



      if (module_exists('wikicompare_needs')) {
        if ($type == 'need' && $reset == True) {
          $commands[] = ajax_command_replace('#comparative_table_main_need', wikicompare_needs_table_render_need(array('states' => $_POST['states'])));
        }
      }


      foreach($nodes as $nid => $node) {
        $commands[] = ajax_command_invoke('.' . $type . '_title_' . $nid, 'html', array($node['data']->title));
        if ($type == 'feature') {
          $commands[] = ajax_command_invoke('.feature_title_' . $nid, 'html', array($node['data']->title));
          $commands[] = ajax_command_invoke('.feature_weight_' . $nid, 'html', array($node['data']->weight));
          $commands[] = ajax_command_invoke('.feature_type_' . $nid, 'html', array($node['data']->type));
          $commands[] = ajax_command_invoke('.feature_state_' . $nid, 'html', array($node['data']->state));
        }
        if ($_POST['fastedit_status'] == 1) {
          $commands[] = ajax_command_invoke('#fastaction_items_' . $nid, 'html', array(add_fastedit_items($type , $node)));
        }
      }

      if ($_POST['fastedit_status'] == 1) {
        $node = array(
          'data' => new stdClass(),
        );
        $node['data']->nid = 0;
        $commands[] = ajax_command_invoke('#add_' . $type . '_link_fastaction', 'html', array(add_fastedit_items($type , $node)));
      }

    }


/*
    //Allow others modules to modify the output
    foreach (module_implements('wikicompare_comparative_table_cleaning') as $module) {
      $function = $module . '_wikicompare_comparative_table_cleaning';
      $function($commands, $_POST);
    }
*/


/*

    if (!$_POST['computed']) {
      $feature_ids = array();
      foreach ($_POST['feature_ids'] as $feature) {
        $feature_ids[$feature[0]] = $feature[0];
      }


      $features = array();
      if (!empty($feature_ids)) {
        $features = request_db('feature', array('fastedit_status' => $_POST['fastedit_status'], 'can_be_translated' => 1), 'nids', $feature_ids);
      }



      $in_db_features = request_db('feature', array('states' => $_POST['states']));
      $in_db_features_ids = array();
      foreach ($in_db_features as $key => $feature) {
        $in_db_features_ids[$key] = $key;
      }
    
      $update_selected_feature = false;
      $in_table_feature_ids = array();
      foreach ($_POST['feature_ids'] as $key => $feature) {
        $in_table_feature_ids[$feature[0]] = $feature[0];
        if (isset($feature[1])) {
          if ($feature[1] != $features[$feature[0]]['data']->parent_id) {
            $update_selected_feature = true;
            if (in_array($feature[1], $_POST['feature_displayed_ids'])) {
              $feature1 = request_db('feature', array(), 'nids', array($feature[1]));
              $feature1 = $feature1[$feature[1]];
              if ($feature1['data']->parent_id != NULL) {
                $commands[] = ajax_command_invoke('#feature_link_' . $feature[1], 'click', array());
              } else {
                $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $_POST['compared_columns_ids'], $_POST['fastedit_status'], 0));
              }
            }
            if (in_array($features[$feature[0]]['data']->parent_id, $_POST['feature_displayed_ids'])) {
              if ($compareds[$compared[0]]['data']->parent_id != NULL) {
                $commands[] = ajax_command_invoke('#feature_link_' . $features[$feature[0]]['data']->parent_id, 'click', array());
              } else {
                $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $_POST['compared_columns_ids'], $_POST['fastedit_status'], 0));
              }
            }
          }
        

         if ((!in_array($feature[0], $in_db_features_ids)) && !isset($feature[1])) {

            $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $_POST['compared_columns_ids'], $_POST['fastedit_status'], 0));
            break;
          }
        }
      }

      foreach ($in_db_features_ids as $fid) {

        if (!in_array($fid, $in_table_feature_ids)) {

          $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $_POST['compared_columns_ids'], $_POST['fastedit_status'], 0));
          break;
        }
      }

      foreach($features as $fid => $feature) {
        $commands[] = ajax_command_invoke('.feature_title_' . $fid, 'html', array($feature['data']->title));
        $commands[] = ajax_command_invoke('.feature_weight_' . $fid, 'html', array($feature['data']->weight));
        $commands[] = ajax_command_invoke('.feature_type_' . $fid, 'html', array($feature['data']->type));
        $commands[] = ajax_command_invoke('.feature_state_' . $fid, 'html', array($feature['data']->state));
        if ($_POST['fastedit_status'] == 1) {
          $commands[] = ajax_command_invoke('#fastaction_items_' . $fid, 'html', array(add_fastedit_items('feature' , $feature)));
        }
      }

      if ($_POST['fastedit_status'] == 1) {
        $feature = array(
          'data' => new stdClass(),
        );
        $feature['data']->nid = 0;
        $commands[] = ajax_command_invoke('#add_feature_link_fastaction', 'html', array(add_fastedit_items('feature' , $feature)));
      }
*/

    if (!$_POST['computed']) {

      $feature_ids = array();
      foreach ($_POST['feature_ids'] as $feature) {
        $feature_ids[$feature[0]] = $feature[0];
      }

      $implementations = array();

      if (!empty($_POST['compared_column_ids']) && !empty($feature_ids)) {
        $implementations = request_db('implementation', array('fastedit_status' => $_POST['fastedit_status']), 'parent', NULL, $_POST['compared_column_ids'], $feature_ids);
      }
  


      foreach($implementations as $fid => $compareds_implementations) {
        foreach ($compareds_implementations as $cid => $implementation) {
          $commands[] = ajax_command_replace('#implementation_' . $implementation['data']->nid, render_implementation($implementation, array(), $_POST['fastedit_status']));
        }
      }
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

    

    //Preparing the ajax commands to return to javascript

    $commands[] = ajax_command_invoke('.form_fastaction', 'remove', array());


    //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
    $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}
/*

function rebuild_table_response($method = 'ajax', $type) {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    $commands = array();

    if ($type == 'compared') {
      $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_compared());
    }

    if ($type == 'feature') {
      if ($_POST['computed'] != 1) {
        $commands[] = ajax_command_replace('#comparative_table', render_comparative_table(array(), $_POST['compared_columns_ids'], $_POST['fastedit_status'], 0));
      }
    }
    $page = array('#type' => 'ajax', '#commands' => $commands);
    return $page;

  //If javascript isn't enabled, we redirect to an error page.
  } else {
    $output = t("You need to activate javascript to use the comparative table."); //TO DO put this message in constant
    return $output;
  }

}
*/

/*
 * Function which will build the item list. Used in table initial building, in compared ajax callback and in modal dialog
 */
function get_item_list($nodes, $type, $action, $parent_node, $itemlist_settings){
/*
  $dialog_text = '';
  if ($itemlist_settings['dialog']) {
    $dialog_text = 'dialog_';
  }
*/

dpm($nodes);
  $items = array();
  foreach ($nodes as $nid => $node_array){

    if ($nid == $itemlist_settings['forbidden_nid']) {
      continue;
    }

    $node = $node_array['data'];

//    $data = wikicompare_get_supertitle_item($type, $node, $itemlist_settings);
/*
    $title = '<span class="' . $type . '_title_' . $nid . '">' . $node->title . '</span>';
    //If the node has children, the node name will become a link calling the callback function to display his children
    if ($node->has_children == 1){
      $class = array('list_item_link ', $type, $itemlist_settings['context']);

      if ($itemlist_settings['computed']) {
        $class[] = 'computed';
      }
      $title = l($title, 'get_item_list_children_callback/nojs/',  array('attributes' => array('id' => $type . '_' . $itemlist_settings['context'] . '_link_' . $nid, 'class' => $class, 'type' => $type, 'context' => $itemlist_settings['context']), 'html' => True));
    }*/
/* else {
      $title = $title_title;
    }*/


/*
    //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table. Unless we configure the system to compute the compared parent, only the compared with no children will have a checkbox.
    $checkbox_area = '';
    $img_link_to_node = '';
    if (in_array($itemlist_settings['context'], array('table', 'multidialog')) && in_array($node->state, array('published-incomplete', 'published-submitted', 'published'))) {
//    if ($itemlist_settings['checkbox_children'] && in_array($node->state, array('published-incomplete', 'published-submitted', 'published'))) {
//      if ($itemlist_settings['checkbox_parent'] || ($node->has_children != 1)) {
      if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update' || $node->has_children != 1) {
        $checkbox_settings = array('element' => array(
          '#title' => $nid,
          '#id' => 'compared_checkbox_' . $nid,
        ));

        if ($type == 'compared') {
//        if ($itemlist_settings['compared_link']) {
          $checkbox_settings['element']['#attributes']['class'] = array('compared_checkbox');
        } else {
          $checkbox_settings['element']['#attributes']['class'] = array('itemlist_checkbox ' . $type);
        }

        if (isset($node->displayed)) {
          $checkbox_settings['element']['#checked'] = True;
//TODO Pas le bon lien          $checkbox_link['#attributes']['class']['displayed'] = 'displayed';        
        }

        $checkbox_area = theme_checkbox($checkbox_settings) . ' ';

        if ($type == 'compared') {
//        if ($itemlist_settings['compared_link']) {

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

//    if ($itemlist_settings['node_link']) {
    if ($itemlist_settings['context'] == 'table') {

      //Create the image link to go to the node page
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to compared ') . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_node = ' ' . l($img, 'node/' . $node->tnid, array('attributes' => array('id' => $type . '_node_link_' . $nid, 'class' => array($type . '_node_link')), 'html' => True));

      $img_link_to_node .= '<span id="fastaction_items_' . $nid . '">';
      if ($itemlist_settings['fastedit_status'] == 1) {
        $img_link_to_node .=  add_fastedit_items($type, $node_array);
      }
      $img_link_to_node .= '</span>';
    }

    if ($itemlist_settings['context'] == 'selectdialog') {

      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Select ') . $type . ' ' . $nid,
        'height' => '100%',
      ));

      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link = l($img, 'select_dialog_callback/nojs', array('attributes' => array('id' => 'select_dialog_' . $nid, 'class' => array('select_simple_dialog')), 'html' => True));
      $checkbox_area = $img_link . ' ';
    }
*/
    
    $items[$nid]['id'] = $type . '_' . $itemlist_settings['context'] . '_item_' .  $nid;
    $items[$nid]['data'] = wikicompare_get_supertitle_item($type, $node, $itemlist_settings);
    $items[$nid]['class'] = array($type . '_item', 'list_item', $itemlist_settings['context']);
    if ($node->has_children == 1){
    $items[$nid]['class'][] = 'has_children';
    }
    $items[$nid]['type'] =  $type;
    $items[$nid]['context'] = $itemlist_settings['context'];
    if ($parent_node != 0) {
      $items[$nid]['class'] = array_merge($items[$nid]['class'], array($type . '_' . $itemlist_settings['context'] . '_child_' . $parent_node));
//      $items[$nid]['class'] = array('feature_children_computed_' . $parent_node);
      if ($itemlist_settings['computed']) {
        $items[$nid]['style'] = 'display:none';
      }
    }


    if ($itemlist_settings['computed'] && $node->has_children) {
       $items[$nid]['children'] = get_item_list($node_array['children'], $type, $action, $nid, $itemlist_settings);
    } else {
      //After the compared, we add the div which will contain the children
      $items[$nid]['data'] .= '<div id="' . $type . '_' . $itemlist_settings['context'] . '_children_' . $nid . '" class="'. $type . '_children" style="display:none;"></div>';
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

  $nodes = request_db($type, array('fastedit_status' => $fastedit_status, 'can_be_translated' => 1), 'nid', $ids);


  foreach ($nodes as $nid => $node) {
    //Check if some children of this node launched the recursive function to find this node as their parent. Then assign them as children of this node and unset the node in the array.
    if (isset($res['parent_ressource'][$nid]['children'])) {
      $node['children'] = $res['parent_ressource'][$nid]['children'];
      //If the parent was already set on the tree by a child on a different level
      if (isset($res['tree'][$nid])) {

        $node['children'] = $res['tree'][$nid]['children'] + $res['parent_ressource'][$nid]['children'];
      }
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


//    $rows[$fid] = $feature;

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

function wikicompare_table_render_compared($settings=array()) {

  $db_settings = array('can_be_translated' => 1);
  if (isset($settings['states'])) {
    $db_settings['states'] = $settings['states'];
  }

  //Find all the compared on the first level of the tree
  $compareds = request_db('compared', $db_settings);

  
  $itemlist_settings = initialize_itemlist_settings('compared_main_table');

  if (isset($settings['fastedit_status'])) {
    $itemlist_settings['fastedit_status'] = $settings['fastedit_status'];
  }
dpm($compareds, 'compareds');
  //Building the data for the item list
  $item_list_data = get_item_list($compareds, 'compared', 'compared_main_table', 0, $itemlist_settings);

  $output ="<div id='comparative_table_main_compared'>";
  //Render the item list
  $output .= theme_item_list(array('items' => $item_list_data, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));
  $output .= '<p><a id="add_compared_link" href="?q=node/add/compared">Add</a><span id="add_compared_link_fastaction">';
 
  if ($itemlist_settings['fastedit_status']) {
    $compared = array(
      'data' => new stdClass(),
    );
    $compared['data']->nid = 0;
    $output .= add_fastedit_items('compared' , $compared);
  }
  $output .= '</span></p>';
  $output .= '<div id="compared_table_children_0"></div>';
  $output .="</div>";

  return $output;

}


function render_comparative_table($features=array(), $compareds=array(), $settings=array()){

  $fastedit_status = 0;
  if (isset($settings['fastedit_status'])) {
    $fastedit_status = $settings['fastedit_status'];
  }

  $computed = 0;
  if (isset($settings['computed'])) {
    $computed = $settings['computed'];
  }

  $db_settings = array('can_be_translated' => 1);
  if (isset($settings['states'])) {
    $db_settings['states'] = $settings['states'];
  }


  if (empty($features)) {
    //Find all the features on the first level of the tree
    $features = request_db('feature', $db_settings);
    
    foreach ($features as $fid => $feature) {

      $settings['feature_ids'][$fid] = $fid;
    }



  }
/*
  $feature_ids = array();
  foreach ($features as $key => $feature) {
    $feature_ids[$key] = $key;
  }
*/


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

  $implementations = array();
  if (!empty($settings['feature_ids']) && !empty($compareds)) {
    $implementations = request_db('implementation', array('fastedit_status' => $fastedit_status), 'parent', NULL, $compareds, $settings['feature_ids']);
  } 


  $feature_row_data = get_rows_data($features, $compareds, $implementations, $computed);

  //Building the table
  $output = '<table id="comparative_table"';
  if ($computed) {
    $output .= ' class="computed"';
  }
  $output .= '><thead>';
  $output .= '<tr id="comparative_table_header">';
  $output .= '<th>' . t('Features') . '</th>';
  foreach ($headers as $cid => $header) {
    $output .= '<th id="header_compared_' . $cid . '" class="header_compared"><span class="compared_title_' . $cid . '">' . $header . '</span></th>';
  }
  $output .= '</tr>';
  $output .= '</thead>';
  $output .= '<tbody>';

  $output .= render_rows($feature_row_data, $fastedit_status);
  $colspan = '';
  if (isset($settings['colspan'])) {
    $colspan = 'colspan="' . $settings['colspan'] . '"';
  }
  $output .= '<tr id="feature_table_0"><td class="row_auto_colspan" ' . $colspan . '><a id="add_feature_link" href="?q=node/add/feature">Add</a><span id="add_feature_link_fastaction">';

  if ($fastedit_status) {
    $feature = array(
      'data' => new stdClass(),
    );
    $feature['data']->nid = 0;
    $output .= add_fastedit_items('feature' , $feature);
  }
  $output .= '</span></td><tr>';
  $output .= '</tbody>';
  $output .= '</table>';

  return $output;


}

function render_rows($feature_row_data, $fastedit_status) {

  $output = '';

  //Add a row for each feature children
  foreach ($feature_row_data as $fid => $feature_array) {

    $feature = $feature_array['data'];

    $output .= '<tr id="feature_table_'. $fid . '" class="feature_row';
    if ($feature->parent_id) {
        $output .= ' feature_table_child_' . $feature->parent_id;
    }
    if ($feature->has_children == 1){
      $output .= ' has_children';
    }
    $output .= '"';
    if (!isset($feature_array['root'])) {
      $output .= ' style="display:none;"';
    }
    $output .= '>';

/*
    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to feature ') . $fid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $feature->tnid, array('attributes' => array('id' => 'feature_node_link_' . $fid, 'class' => array('feature_node_link')), 'html' => True));
    $img_link_to_node .= '<span id="fastaction_items_' . $fid . '">';
    if ($fastedit_status == 1) {
      $img_link_to_node .= add_fastedit_items('feature', $feature_array); 
    }
    $img_link_to_node .= '</span>';

    $title = '<span class="feature_title_' . $fid . '">' . $feature->title . '</span>';
    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($feature->has_children == 1){
      $title = l($title . ' ' . $fid, 'get_feature_callback/nojs/',  array('attributes' => array('id' => 'feature_table_link_' . $fid, 'class' => array('feature_link feature_link_children_' . $fid)), 'html' => True));
    } 


    //Creating the first cell of the row, containing the feature details
    $output .= '<td>' . $title . ' ' . $img_link_to_node  . '<br/> Weight : <span class="feature_weight_' . $fid . '">' .  $feature->weight . '</span>';
    if ($feature->has_children == 1){
      $output .= '<br/> Type : <span class="feature_type_' . $fid . '">' .  $feature->type . '</span>';
    }
    $output .= '<br/> State : <span class="feature_state_' . $fid . '">' .  $feature->state . '</span></td>';
*/
    $output .= '<td>' . wikicompare_get_supertitle_item('feature', $feature, array('context' => 'table', 'fastedit_status' => $fastedit_status)) . '</td>';
dpm($output);

    //Add a column for each column in the table
    foreach ($feature_array['implementations'] as $implementation) {
      $output .= render_implementation($implementation, $feature_array, $fastedit_status);
    }
    $output .= '</tr>';
  }

  return $output;


}

function render_implementation($implementation_array, $feature_array, $fastedit_status) {

  $implementation = $implementation_array['data'];

  if (in_array($feature_array['data']->state, array('published-incomplete', 'published-submitted', 'published')) || $feature_array == NULL) {

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to implementation ') . $implementation->nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $implementation->nid,  array('attributes' => array('id' => 'implementation_node_link_' . $implementation->nid, 'class' => array('implementation_node_link')), 'html' => True));
    $img_link_to_node .= '<span id="fastaction_items_' . $implementation->nid . '">';

    if ($fastedit_status == 1) {
      $img_link_to_node .= add_fastedit_items('implementation', $implementation_array); 
    }
    $img_link_to_node .= '</span>';

    $output = '<td id="implementation_' . $implementation->nid . '" class="implementation_cell ' . $implementation->css_class . ' implementation_compared_' . $implementation->compared_id . ' implementation_feature_' . $implementation->feature_id . '">' . $implementation->nid . ' ' .  $img_link_to_node . '<br/>Feature : ' . $implementation->feature_id . '<br/>Compared : ' . $implementation->compared_id . '<br/>' . $implementation->percent . '%</td>';

  } else {
    $output = '<td></td>';
  }

  return $output;
}


function initialize_itemlist_settings($subaction) {

  $itemlist_settings = array(
    'fastedit_status' => 0,
    'context' => 0,
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
      $itemlist_settings['context'] = 'table';
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


function wikicompare_get_supertitle_item($type, $node, $itemlist_settings) {

  if ($type != 'feature') {

    $title = '<span class="' . $type . '_title_' . $node->nid . '">' . $node->title . '</span>';
    //If the node has children, the node name will become a link calling the callback function to display his children
    if ($node->has_children == 1){
      $class = array('list_item_link ', $type, $itemlist_settings['context']);
  /*
      if ($itemlist_settings['dialog']) {
        $class[] = 'dialog';
      }*/
      if ($itemlist_settings['computed']) {
        $class[] = 'computed';
      }
      $title = l($title, 'get_item_list_children_callback/nojs/',  array('attributes' => array('id' => $type . '_' . $itemlist_settings['context'] . '_link_' . $node->nid, 'class' => $class, 'type' => $type, 'context' => $itemlist_settings['context']), 'html' => True));
    }


    //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table. Unless we configure the system to compute the compared parent, only the compared with no children will have a checkbox.
    $checkbox_area = '';
    $img_link_to_node = '';
    if (in_array($itemlist_settings['context'], array('table', 'multidialog')) && in_array($node->state, array('published-incomplete', 'published-submitted', 'published'))) {
  //    if ($itemlist_settings['checkbox_children'] && in_array($node->state, array('published-incomplete', 'published-submitted', 'published'))) {
  //      if ($itemlist_settings['checkbox_parent'] || ($node->has_children != 1)) {
      if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update' || $node->has_children != 1) {
        $checkbox_settings = array('element' => array(
          '#title' => $node->nid,
          '#id' => 'compared_checkbox_' . $node->nid,
        ));

        if ($type == 'compared') {
  //        if ($itemlist_settings['compared_link']) {
          $checkbox_settings['element']['#attributes']['class'] = array('compared_checkbox');
        } else {
          $checkbox_settings['element']['#attributes']['class'] = array('itemlist_checkbox ' . $type);
        }

        if (isset($node->displayed)) {
          $checkbox_settings['element']['#checked'] = True;
  //TODO Pas le bon lien          $checkbox_link['#attributes']['class']['displayed'] = 'displayed';        
        }

        $checkbox_area = theme_checkbox($checkbox_settings) . ' ';

        if ($type == 'compared') {
  //        if ($itemlist_settings['compared_link']) {

          //We were not able to ajaxify the checkbox, so instead the checkbox will call this hidden link
          $checkbox_link = array(
            '#type' => 'link',
            '#title' => 'toggle',
            //The link for the callback function which will display or hide the column in the table
            '#href' => 'toogle_compared_checkbox_callback/nojs/',
            '#id' => 'compared_checkbox_link_' . $node->nid,
            '#attributes' => array(
              'class' => array('compared_checkbox_link' => 'compared_checkbox_link'),
              'style' => 'display:none',
            )
          );

          $checkbox_area .= drupal_render($checkbox_link);
        }
      }
    }

  //    if ($itemlist_settings['node_link']) {
    if ($itemlist_settings['context'] == 'table') {

      //Create the image link to go to the node page
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to compared ') . $node->nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_node = ' ' . l($img, 'node/' . $node->tnid, array('attributes' => array('id' => $type . '_node_link_' . $node->nid, 'class' => array($type . '_node_link')), 'html' => True));

      $img_link_to_node .= '<span id="fastaction_items_' . $node->nid . '">';
      if ($itemlist_settings['fastedit_status'] == 1) {
        $img_link_to_node .=  add_fastedit_items($type, $node_array);
      }
      $img_link_to_node .= '</span>';
    }

    if ($itemlist_settings['context'] == 'selectdialog') {

      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Select ') . $type . ' ' . $node->nid,
        'height' => '100%',
      ));

      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link = l($img, 'select_dialog_callback/nojs', array('attributes' => array('id' => 'select_dialog_' . $node->nid, 'class' => array('select_simple_dialog')), 'html' => True));
      $checkbox_area = $img_link . ' ';
    }

    $output = $checkbox_area . $title . $img_link_to_node;

  } else {

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to feature ') . $node->nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $node->tnid, array('attributes' => array('id' => 'feature_node_link_' . $node->nid, 'class' => array($type . '_node_link')), 'html' => True));
    $img_link_to_node .= '<span id="fastaction_items_' . $node->nid . '">';
    if ($itemlist_settings['fastedit_status'] == 1) {
      $img_link_to_node .= add_fastedit_items($type, $node_array); 
    }
    $img_link_to_node .= '</span>';

    $title = '<span class="feature_title_' . $node->nid . '">' . $node->title . '</span>';
    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($node->has_children == 1){
      $title = l($title . ' ' . $node->nid, 'get_feature_callback/nojs/',  array('attributes' => array('id' => $type . '_table_link_' . $node->nid, 'class' => array($type . '_link ' . $type . '_link_children_' . $node->nid)), 'html' => True));
    } 
/*else {
      $title = $title_title;
    }*/

    //Creating the first cell of the row, containing the feature details
    $output = $title . ' ' . $img_link_to_node  . '<br/> Weight : <span class="' . $type . '_weight_' . $node->nid . '">' .  $node->weight . '</span>';
    if ($node->has_children == 1){
      $output .= '<br/> Type : <span class="' . $type . '_type_' . $node->nid . '">' .  $node->type . '</span>';
    }
    $output .= '<br/> State : <span class="' . $type . '_state_' . $node->nid . '">' .  $node->state . '</span>';

  }

  return '<span id="' . $type . '_' . $itemlist_settings['context'] . '_supertitle_' . $node->nid . '">' . $output . '</span>';

}
?>
