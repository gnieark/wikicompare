<?php

//Define the message when a user didn't have the javascript activated.
define('NOJS_MESSAGE', "You need to activate javascript to use the comparative table.");



/**
 * Build the wikicompare comparative table.
 */
function wikicompare_comparative_table() {

  //Add the javascript files used in the comparative_table.
  drupal_add_js('/misc/ajax.js');
  drupal_add_js('/misc/progress.js');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  //Add the checkbox to display the draft and closed items in the tables.
  $checkbox_settings =  array(
    '#type' => 'checkbox',
    '#title' => 'Display draft items',
    '#id' => 'checkbox-draft-items',
    '#attributes' => array(
      'class' => array('state_checkbox'),
    ),
   );
  $output = render($checkbox_settings);
  $checkbox_settings =  array(
    '#type' => 'checkbox',
    '#title' => 'Display closed items',
    '#id' => 'checkbox-closed-items',
    '#attributes' => array(
      'class' => array('state_checkbox'),
    ),
   );
  $output .= render($checkbox_settings);

  //Add the container which will contain the selected feature itemlist. It'll be build when we submit the manual selected feature dialog.
  $output .= '<div id="container-manual-selected-features"></div>';
  //Add the link to open the select feature popup
  $select_feature_link = array(
    'text' => 'Select features',
    'title' => 'Select features',
    'selector' => 'dialog-content',
    'path' => 'wikicompare_get_dialog_callback/multidialog/feature/manual-selected-features/0/',//manual_selected_features/none',
    'id' => 'select_feature_link',
  );
  //Render the link thanks to the simple dialog module.
  $output .= '<p>' . theme('simple_dialog_link', $select_feature_link) . '</p>';

  if (module_exists('wikicompare_needs')) {
    //Generate the main need itemlist in the wikicompare table.
    wikicompare_needs_comparative_table_main_output($output);
  }

  //Add the compute button.
  $compute_link = array(
    '#type' => 'link',
    '#title' => 'Compute',
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'compute_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'compute_table',
      'style' => 'display:none',
    ),
  );
  $output .= '<p><input id="compute_table_button" type="submit" link="compute_table_link" value="Compute table" class="button wikicompare_button"/>' . render($compute_link);

  //Add the reset link.
  $reset_link = array(
    '#type' => 'link',
    '#title' => 'Reset table',
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'reset_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'reset_table',
    ),
  );
  $output .= ' ' . render($reset_link) . '</p>';

  //Generate the main compared itemlist.
  $output .= wikicompare_table_render_main_itemlist('compared', 'Compareds', wikicompare_initialize_settings());

  //Generate the comparative table.
  $output .= wikicompare_table_render_comparative_table(wikicompare_initialize_settings());


  //Add the link to go on FastAction mode.
  $toogle_link = array(
    '#type' => 'link',
    '#title' => 'Toogle FastAction',
    '#href' => 'toogle_fastaction_callback/nojs',
    '#id' => 'toogle_fastaction_link',
  );
  $output .= '<p>' . render($toogle_link) . '</p>';


  //Add the link to launch a cleaning on the table.
  $cleaning_link = array(
    '#type' => 'link',
    '#title' => 'Clean',
    '#href' => 'wikicompare_make_cleaning_callback/nojs',
    '#id' => 'make_cleaning_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'make_cleaning',
      'style' => 'display:none',
    ),
  );
  $output .= '<p>' . render($cleaning_link) . '</p>';

  //Return the html code.
  return $output;

}



/**
 * Generate the main table itemlist for the specified type. This function is called by the initial function of the comparative table and by the cleaning function if some important changes was made.
 *
 * @param type
 *   The type of the itemlist.
 *
 * @param title
 *   The title of the itemlist.
 *
 * @param settings
 *   The context of the itemlist.
 *
 * @return output
 *   The rendered itemlist.
 */
function wikicompare_table_render_main_itemlist($type, $title, $settings) {

  //Only the main itemlist of the table will be rendered by this function.
  $settings['context'] = 'table';

  //Find all nodes on the first level of the tree.
  $nodes = request_db($type, array('parent_id' => NULL), $settings);

  //Building the data for the itemlist.
  $itemlist_data = wikicompare_build_itemlist($type, $nodes, 0, $settings);

  $output ="<div id='comparative_table_main_" . $type . "'>";
  //Render the item list
  $output .= theme_item_list(array('items' => $itemlist_data, 'title' => $title, 'type' => 'ul', 'attributes' => array()));
  //Render the link to add a new node.
  $output .= '<p>' . wikicompare_generate_add_link($type, $settings) . '</p>';
  //We need to add the 0 children div to know where place the fastaction form.
  $output .= '<div id="' . $type . '_table_children_0"></div>';
  $output .="</div>";

  //Return itemlist.
  return $output;

}



/**
 * Generate the comparative table. This function is called by the initial function of the comparative table, by the compute and reset function and by the cleaning function if some important changes was made.
 *
 * @param settings
 *   The context of the table.
 *
 * @param features
 *   If specified, the table will be computed with the specified features.
 *
 * @param compared_ids
 *   The table will immediately add the specified compared as column.
 *
 * @return $output
 *   The rendered table.
 */
function wikicompare_table_render_comparative_table($settings, $features=array(), $compared_ids=array()){

  //Only the main table will be rendered by this function.
  $settings['context'] = 'table';

  if (empty($features)) {
    //Find all the features on the first level of the tree.
    $features['tree'] = request_db('feature', array('parent_id' => NULL), $settings);
    //Get the feature ids.
    foreach ($features['tree'] as $fid => $feature) {
      $features['ids'][$fid] = $fid;
    }
  }

  //Get the needed implementation thanks to feature and compared ids.
  $implementations = array();
  //I though about move this security in the request itself, but it would add an unnecessary db request in many cases.
  if (!empty($features['ids']) && !empty($compared_ids)) {
    //Get the needed implementation thanks to feature and compared ids.
    $implementations = request_db('implementation', array('feature_ids' => $features['ids'], 'compared_ids' => $compared_ids), $settings);
  }

  //Build recursively the features data and compute them if necessary.
  $features_row_data = wikicompare_build_rows_data($features['tree'], $compared_ids, $implementations, $settings);

  $compareds = array();
  if (!empty($compared_ids)) {
    //Get the compareds data for the header of the table.
    $compareds = request_db('compared', array('nids' => $compared_ids), $settings);
  }

  //Building the table
  $output = '<table id="comparative_table"';
  if ($settings['computed']) {
    //The computed status of the table will be checked thanks to this class.
    $output .= ' class="computed"';
  }
  $output .= '><thead>';
  //Build header.
  $output .= '<tr id="comparative_table_header">';
  $output .= '<th>' . t('Features') . '</th>';
  foreach ($compareds as $cid => $compared) {
    $output .= '<th id="header_compared_' . $cid . '" class="header_compared"><span class="compared_title_' . $cid . '">' . $compared['data']->title . '</span></th>';
  }
  $output .= '</tr>';
  $output .= '</thead>';
  $output .= '<tbody>';
  //Render rows.
  $output .= wikicompare_table_render_rows($features_row_data, $settings);
  //Add an autocolspan row for the add link.
  $output .= '<tr id="feature_table_0"><td class="row_auto_colspan" ';
  if (isset($settings['colspan'])) {
    $output .= 'colspan="' . $settings['colspan'] . '"';
  }
  $output .= '>';
  $output .= wikicompare_generate_add_link('feature', $settings);
  $output .= '</span></td><tr>';
  $output .= '</tbody>';
  $output .= '</table>';

  //Return the table.
  return $output;

}

/**
 * Render the rows for the comparative table. This function is called by the render comparative table function and by the feature add children ajax call.
 *
 * @param $features_row_data
 *   The consolidated data of the row, which contains the features in tree and their implementation.
 *
 * @param $settings
 *   The context of the rows.
 *
 * @return $output
 *   The rendered rows.
 */
function wikicompare_table_render_rows($features_row_data, $settings) {

  $output = '';

  //Add a row for each features.
  foreach ($features_row_data as $fid => $feature) {

    $output .= '<tr id="feature_table_'. $fid . '" class="feature_row';
    //If the feature has parent, we add it in the class to find them later. Thanks to this class, we can for exemple easily remove the children of a node.
    if ($feature['data']->parent_id) {
        $output .= ' feature_table_child_' . $feature['data']->parent_id;
    }
    //If the feature has children, we add this class to easily know that this feature can display children.
    if ($feature['data']->has_children){
      $output .= ' has_children';
    }
    $output .= '"';
    //If the feature was computed, then all the feature which are not in the first level of the tree must be hide.
    if (!isset($feature['root'])) {
      $output .= ' style="display:none;"';
    }
    $output .= '>';

    //Generate the main details of the feature in the first cell.
    $output .= '<td>' . wikicompare_table_get_supertitle_item('feature', $feature, $settings) . '</td>';

    //Add a column for each compared.
    foreach ($feature['implementations'] as $implementation) {
      //Render implementation.
      $output .= wikicompare_table_render_implementation($implementation, $feature, $settings);
    }
    $output .= '</tr>';

  }

  //Return the rendered row.
  return $output;

}

/**
 * Render the implementation. This fucntion is used in render row function and in the add compared column ajax call.
 *
 * @param $implementation
 *   The implementation to render.
 *
 * @param feature
 *   The detail of the feature of the implementation.
 *
 * @param $settings
 *   The context of the implementation.
 *
 * @return $output
 *   The rendered implementation.
 */
function wikicompare_table_render_implementation($implementation, $feature, $settings) {

  //We hide the implementation for all non-published feature, to more easily distinct them from the published ones.
  if (in_array($feature['data']->state, array('published-incomplete', 'published-submitted', 'published')) || $feature == NULL) {

    //Render the implementation.
    $output = '<td id="implementation_' . $implementation['data']->nid . '" class="implementation_cell ' . $implementation['data']->css_class . ' implementation_compared_' . $implementation['data']->compared_id . ' implementation_feature_' . $implementation['data']->feature_id . '">' . wikicompare_table_get_supertitle_item('implementation', $implementation, $settings) . '</td>';

  } else {
    $output = '<td></td>';
  }

  return $output;
}

/*
 * Render the supertitle of an item. This part is separate from the rest of the render function because we have to be able to call this in cleaning function, to for exemple change a simple title into a link if a node get children.
 * This function is call by all item function, itemlist, feature rows and implementations.
 *
 * @param $type
 *   The type of the rendered node.
 *
 * @param $node
 *   Array containing the detail of the rendered node.
 *
 * @param $settings
 *   Array containing the context of the rendering.
 *
 * @return $output
 *   The html code of the supertitle.
 */
function wikicompare_table_get_supertitle_item($type, $node, $settings) {

  $prefix = '';
  $suffix = '';

  if ($type != 'implementation') {

    //Get the title of the item, which can be a translated title.
    $title = '<span class="' . $type . '_title_' . $node['data']->nid . '">' . $node['data']->title . '</span>';

    //Specify the most used ajax call to display children.
    $url = 'wikicompare_get_itemlist_children_callback/nojs/';

    //Specific case of the table features.
    if ($type == 'feature' && $settings['context'] == 'table') {
      //The ajax call is not the same.
      $url = 'wikicompare_get_feature_children_callback/nojs/';
      //Creating the first cell of the row, containing the feature details.
      $suffix .= '<br/> Weight : <span class="' . $type . '_weight_' . $node['data']->nid . '">' .  $node['data']->weight . '</span>';
      //We display the type only for the parent feature, no interest in case of only children features.
      if ($node['data']->has_children){
        $suffix .= '<br/> Type : <span class="' . $type . '_type_' . $node['data']->nid . '">' .  $node['data']->type . '</span>';
      }
      $suffix .= '<br/> State : <span class="' . $type . '_state_' . $node['data']->nid . '">' .  $node['data']->state . '</span>';

    //In this case, we are in an itemlist.
    } else {

      //The forbidden nid is a node we must not be able to select in popin. We display him but will not generate any link or checkbox in the prefix.
      if ($node['data']->nid != $settings['forbidden_nid']) {

        //Only table and multidialog itemlist have checkboxes before the node title. Also, this node must be published.
        if (in_array($settings['context'], array('table', 'multidialog')) && in_array($node['data']->state, array('published-incomplete', 'published-submitted', 'published'))) {

          //We display a checkbox only if the node has children, or for compared table if we activated the option.
          if ($node['data']->has_children != 1 || (variable_get('wikicompare_update_compared', 'no-update') != 'no-update' && $settings['context'] == 'table' && $type == 'compared')) {

            //Generate checkbox.
            $checkbox_settings = array('element' => array(
              '#title' => $node['data']->nid,
              '#id' => $type . '_' . $settings['context'] . '_checkbox_' . $node['data']->nid,
              '#attributes' => array(
                'class' => array('itemlist_checkbox'),
                'ntype' => $type,
                'context' => $settings['context'],
              ),
            ));
            //We check it immediately if it was check before (a compared which already has his column in table, a feature present in the global array in javascript etc...
            if (isset($node['data']->displayed)) {
              $checkbox_settings['element']['#checked'] = True;
            }

            $prefix .= theme_checkbox($checkbox_settings) . ' ';

            //Add the ajax link which will add the column in table.
            if ($type == 'compared' && $settings['context'] == 'table') {
              $checkbox_link = array(
                '#type' => 'link',
                '#title' => 'toggle',
                '#href' => 'wikicompare_toogle_compared_checkbox_callback/nojs/',
                '#id' => 'compared_checkbox_link_' . $node['data']->nid,
                '#attributes' => array(
                  'class' => array('simple_ajaxlink'),
                  'action' => 'toogle_compared_checkbox',
                  'style' => 'display:none',
                )
              );
              $prefix .= render($checkbox_link);
            }

          }

        //In select dialog, we add a select link before each item.
        } elseif ($settings['context'] == 'selectdialog') {
          $img = theme('image', array(
            'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
            'alt' => t('Select ') . $type . ' ' . $node['data']->nid,
            'height' => '100%',
          ));
          //Create the link. The html = True indicate that the title of the link contain html.
          $prefix .= l($img, 'wikicompare_select_dialog_callback/nojs', array('attributes' => array('id' => 'select_dialog_' . $node['data']->nid, 'class' => array('selectlink_dialog')), 'html' => True)) . ' ';
        }

      }

    }

    //If the node has children, we replace the title with a link to display the children.
    if ($node['data']->has_children){
      $class = array('item_link');
      if ($settings['computed']) {
        $class[] = 'computed';
      }
      //This class is used to prepare the variable for the cleaning function.
      if ($settings['context'] == 'table') {
        $class[] = $type . '_table_link';
      }
      //Replace the title by the link.
      $title = l($title, $url,  array('attributes' => array('id' => $type . '_' . $settings['context'] . '_link_' . $node['data']->nid, 'class' => $class, 'ntype' => $type, 'context' => $settings['context']), 'html' => True));
    }

  } else {
    //An implementation has no title, we simply display his percentage.
    $title = $node['data']->percent . '%';
  }

  //For all table items, we add a link to access the node page and add a div to store the fastaction items.
  if ($settings['context'] == 'table') {

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to ' . $type . ' ') . $node['data']->nid,
      'height' => '100%',
    ));
    //Create the link. It will redirect to the translated node if any. The html = True indicate that the title of the link contain html.
    $suffix .= ' ' . l($img, 'node/' . $node['data']->tnid, array('attributes' => array('id' => $type . '_node_link_' . $node['data']->nid), 'html' => True));

    //Add fastaction item if fastaction flag is set, or else at least the div which will contains them.
    $suffix .= '<span id="fastaction_items_' . $node['data']->nid . '">';
    if ($settings['fastaction']) {
      $suffix .=  add_fastaction_items($type, $node);
    }
    $suffix .= '</span>';

  }

  //Return the supertitle rendered in a span so we can easily update it in the cleaning function.
  return '<span id="' . $type . '_' . $settings['context'] . '_supertitle_' . $node['data']->nid . '">' . $prefix . $title . $suffix . '</span>';

}





/**
 * Recursive function which will build the item list. Used in table initial building, in item children ajax callback and in dialog function.
 *
 * @param $type
 *   The type of the nodes.
 *
 * @param $nodes
 *   Array containing the details of the nodes. This array is a tree if the itemlist is computed.
 *
 * @param $parent_node
 *   The parent node id of the nodes.
 *
 * @param $settings
 *   The context of the build.
 *
 * @return $items
 *   A prepared array ready to be used by the theme_item_list drupal function.
 */
function wikicompare_build_itemlist($type, $nodes, $parent_node, $settings){

  $items = array();
  //Add each node in the returned array.
  foreach ($nodes as $nid => $node){
    //Id of the item.
    $items[$nid]['id'] = $type . '_' . $settings['context'] . '_item_' .  $nid;
    //Name of the item.
    $items[$nid]['data'] = wikicompare_table_get_supertitle_item($type, $node, $settings);
    //Needed argument for javascript.
    $items[$nid]['type'] =  $type;
    $items[$nid]['context'] = $settings['context'];
    //Class used to prepare variable for cleaning function.
    $items[$nid]['class'] = array($type . '_item');
    if ($node['data']->has_children){
      $items[$nid]['class'][] = 'has_children';
    }
    //Class used to easily act on the children of a node.
    if ($parent_node != 0) {
      $items[$nid]['class'] = array_merge($items[$nid]['class'], array($type . '_' . $settings['context'] . '_child_' . $parent_node));
      //If the itemlist is computed, all children are hidden.
      if ($settings['computed']) {
        $items[$nid]['style'] = 'display:none';
      }
    }

    //If the itemlist is computed and the node has children, then we call the recursive function to get the children.
    if ($settings['computed'] && $node['data']->has_children) {
       $items[$nid]['children'] = wikicompare_build_itemlist($type, $node['children'], $nid, $settings);
    //Else, we just add the div which will contain the children after an ajax call, and the fastaction form.
    } else {
      $items[$nid]['data'] .= '<div id="' . $type . '_' . $settings['context'] . '_children_' . $nid . '" class="'. $type . '_children" style="display:none;"></div>';
    }

  }

  //Display an error message if we try to build an itemlist without data yet.
  if (empty($items)) {
    $items[]['data'] = "There is no data yet.";
  }

  return $items;

}



/**
 * Simple function which will call the two function which build the recursive data, based only on the ids of the without children nodes.
 *
 * @param $type
 *   The type of the nodes.
 *
 * @param $nodes_ids
 *   The nids of the nodes without children.
 *
 * @param $settings
 *   The context of the build.
 *
 * @return $res
 *   An array containing the whole tree we need to display.
 */
function wikicompare_build_recursive_data($type, $node_ids, $settings){

  $res = array();
  //Build the recursive tree.
  $res = wikicompare_build_recursive_tree($type, $node_ids, $res, $settings);
  //From the resurcive tree, build the full title of the nodes.
  $res = wikicompare_build_fulltitle($res, $res['tree'], '');

  return $res;

}



/**
 * Recursive function which will build the recursive data, based only on the ids of the without children nodes.
 *
 * @param $type
 *   The type of the nodes.
 *
 * @param $nodes_ids
 *   The nids of the nodes without children.
 *
 * @param $res
 *   The array we want to update.
 *
 * @param $settings
 *   The context of the build.
 *
 * @return $res
 *   An array containing the tree we are building.
 */
function wikicompare_build_recursive_tree($type, $node_ids, $res, $settings){

  $parent_ids = array();

  //Get the details of the specified nodes. No other way here but to put this query in recursive function. Some improvement for later may be to use the WITH RECURSIVE function of postgresql.
  $nodes = request_db($type, array('nids' => $node_ids), $settings);

  foreach ($nodes as $nid => $node) {

    //Check if some children of this node launched the recursive function to find this node as their parent. Then assign them as children of this node and unset the node in the array.
    if (isset($res['parent_ressource'][$nid]['children'])) {
      $node['children'] = $res['parent_ressource'][$nid]['children'];
      unset($res['parent_ressource'][$nid]);
    }

    //If the parent was already set on the tree by a child on a different level
    if (isset($res['tree'][$nid])) {
      $node['children'] = $res['tree'][$nid]['children'] + $node['children'];
    }

    //Keep all ids and object outside of the tree, for other uses.
    $res['ids'][$nid] = $nid;
    $res['data'][$nid] = $node;

    //If the node has parent, assign him in the parent array and tell the recursive function to find the parent next time. Else, set the node as in the root of the array.
    if ($node['data']->parent_id) {
      $res['parent_ressource'][$node['data']->parent_id]['children'][$nid] = $node;
      $parent_ids[$node['data']->parent_id] = $node['data']->parent_id;
    } else {
      $res['tree'][$nid] = $node;
    }

  }

  //If there is others parents to add in the array, relaunch the recursive function until all parents are found.
  if ($parent_ids){
    $res = wikicompare_build_recursive_tree($type, $parent_ids, $res, $settings);
  } else {
    unset($res['parent_ressource']);
  }

  return $res;

}



/**
 * Recursive function which will build the full title of a node, based on the data build previously.
 *
 * @param $res
 *   The array we want to update.
 *
 * @param $tree
 *   The data previously built.
 *
 * @param $parent_title
 *   The full title of the parent.
 *
 * @return $res
 *   An array containing the tree we are building.
 */
function wikicompare_build_fulltitle($res, $tree, $parent_title) {

  foreach ($tree as $nid => $node) {

    //Get the full title of the node by concat him to the full title of the parent.
    $fulltitle = $node['data']->title;
    if ($parent_title) {
      $fulltitle = $parent_title . ' / ' . $fulltitle;
    }
    $res['data'][$nid]['data']->fulltitle = $fulltitle;

    //If the node has childre, call the recursive function to get the full title of the children.
    if (!empty($node['children'])) {
      $res = wikicompare_build_fulltitle($res, $node['children'], $fulltitle);
    }

  }

  return $res;

}



/**
 * Function which will build the features row, assign the implementations and compute the percent if we are in compute mode. Used in render comparative table and in feature ajax callback.
 *
 * @param $features_tree
 *   The feature tree previously build by recursive function.
 *
 * @param $compared_ids
 *   The nids of the compared nodes displayed in the table, so we can assign the implementations to each rows.
 *
 * @param $implementations
 *   The implementations details we previously extracted from database.
 *
 * @param $settings
 *   The context of the build.
 *
 * @return $rows
 *   The prepared rows ready to be rendered.
 */
function wikicompare_build_rows_data($features_tree, $compared_ids, $implementations, $settings){

  $rows = array();

  foreach ($features_tree as $fid => $feature){

    //Add the feature in the rows.
    $rows[$fid] = $feature;

    //We need to set this flag, otherwise the parent will have no way to recover his true children since they will be all at the same level.
    if ($feature['data']->parent_id) {
      $rows[$fid]['direct-child'] = True;
    //We set another flag if we are at the top of the tree.
    } else {
      $rows[$fid]['root'] = True;
    }

    //Launch the recursive function if we are computing the table and the feature have children.
    $children = array();
    if ($feature['children']) {
      $children = wikicompare_build_rows_data($feature['children'], $compared_ids, $implementations, $settings);
    }

    //Since the row are not in a tree but at the same level, we need to use the direct-child flag to recover the true children of the node we are currently working on.
    $direct_children = array();
    foreach ($children as $key => $child) {
      if (isset($child['direct-child'])) {
        $direct_children[$key] = $child;
        //Unset the flag so it can't be recovered by next parents.
        unset($children[$key]['direct-child']);
      }
    }

    //Assign implementation to each rows, following the displayed compareds.
    $rows[$fid]['implementations'] = array();
    foreach ($compared_ids as $cid) {

      //Get implementation detail, thanks to feature and compared id.
      $implementation = $implementations[$fid][$cid];

      //If the table is computed, then we will not use the percent in cache_comparative_table but compute it with the specified features.
      if ($settings['computed']) {

        //The type of the feature which will be used in the wikicompare_compute_percent function
        $implementation['data']->type = $feature['data']->type;
        //The weight of the feature which will be used in the parent wikicompare_compute_percent function
        $implementation['data']->weight = $feature['data']->weight;

        //Get all children implementation on the feature axis (same compared id).
        $through_feature_childs = array();
        foreach ($direct_children as $child) {
          $child_implementation = $child['implementations'][$cid]['data'];
          $through_feature_childs[$child_implementation->feature_id] = $child_implementation;
        }

        //Get the implementation percent by calling the same function than the one used in update_compare_tree.
        if (!empty($through_feature_childs)) {
          $implementation['data']->percent = 0;
          $implementation['data']->css_class = 'cell-support-no';
          $implementation['data'] = wikicompare_compute_percent($implementation['data'], $through_feature_childs);
        }

      }

      //Assign the implementation to the row.
      $rows[$fid]['implementations'][$cid] = $implementation;

    }

    //Add row children after the parent row.
    foreach ($children as $key=> $child) {
      $rows[$key] = $child;
    }

  }

  return $rows;

}






/**
 * Ajax callback function called by javascript to recover the children of the clicked node in an itemlist.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_get_itemlist_children_response($method = 'ajax') {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $commands = array();
  //If we want to displayed the children.
  if ($_POST['display']) {

    //Initialize settings with the variable from javascript.
    $settings = wikicompare_initialize_settings($_POST);

    //Get the children, with the parent nid.
    $nodes = request_db($_POST['type'], array('parent_id' => $_POST['nid']),  $settings);

    foreach ($nodes as $nid => $node) {

      //If a compared table is already displayed in the table, we check it by default.
      if ($_POST['type'] == 'compared' && $settings['context'] == 'table') {
        if (in_array($nid, $settings['compared_column_ids'])) {
          $nodes[$nid]['data']->displayed = True;
        }
      }

      //If a multidialog feature is already checked in javascript global variable, we check it by default.
      if ($_POST['type'] == 'feature' && $settings['context'] == 'multidialog') {
        if (in_array($nid, $settings['selected_feature_ids'])) {
          $nodes[$nid]['data']->displayed = True;
        }
      }

      if (module_exists('wikicompare_needs')) {
        //Auto check the already selected needs in main table.
        wikicompare_needs_table_prepare_itemlist($nid, $nodes, $_POST);
      }

    }

    //Building the data for the itemlist.
    $itemlist_data = wikicompare_build_itemlist($_POST['type'], $nodes, $_POST['nid'], $settings);

    //Rendering the itemlist.
    $output = theme_item_list(array('items' => $itemlist_data, 'title' => '',  'type' => 'ul', 'attributes' => array()));

    //We prepared a div under the parent compared. This command will fill it with the compared children, and replace anything that was here before.
    $commands[] = ajax_command_html('#'. $_POST['type'] . '_' . $settings['context'] . '_children_' . $_POST['nid'], $output);

  }

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript to recover the feature children of the clicked feature in the table.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_get_feature_children_response($method = 'ajax') {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $commands = array();
  //If we want to displayed the feature children.
  if ($_POST['display']) {

    //Initialize settings with the variable from javascript.
    $settings = wikicompare_initialize_settings($_POST);

    //Get the children, with the parent nid.
    $features = request_db('feature', array('parent_id' => $_POST['nid']), $settings);

    //Extract feature_ids to use it as argument to get the implementations.
    $feature_ids = array();
    foreach ($features as $fid => $feature) {
      $feature_ids[$fid] = $fid;
    }

    //Recover the implementations needed for the cells, thanks to compared and feature ids.
    $implementations = array();
    if (!empty($settings['compared_column_ids'])) {
      $implementations = request_db('implementation', array('compared_ids' => $settings['compared_column_ids'], 'feature_ids' => $feature_ids), $settings);
    }

    //Prepare the features data for rendering.
    $feature_row_data = wikicompare_build_rows_data($features, $settings['compared_column_ids'], $implementations, $settings);

    //Render the features.
    $output = wikicompare_table_render_rows($feature_row_data, $settings);

    //We add the new rows after the parent row. Note we can't use ajax_command_after because it adds an unwanted div.
    $commands[] = ajax_command_invoke('#feature_table_' . $_POST['nid'], 'after', array($output));

    //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
    $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

  }

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript to add or remove a column in the comparative table.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_toggle_compared_checkbox_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $commands = array();
  //If we want to display the column.
  if ($_POST['display']) {

    //Initialize settings with the variable from javascript.
    $settings = wikicompare_initialize_settings($_POST);

    //Recover the detail of the compared we want to add, by searching with his nid.
    $compared = request_db('compared', array('nids' => array($_POST['nid'])), $settings);

    //Add the header of the new column, with the compared title.
    $header = '<th id="header_compared_' . $_POST['nid'] . '" class="header_compared" style="display:none;"><span class="compared_title_' . $_POST['nid'] . '">' . $compared[$_POST['nid']]['data']->title . '</span></th>';

    //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
    if (!empty($_POST['feature_ids'])) {

      //Get the features details, by searching with their nids.
      $features = request_db('feature', array('nids' => $_POST['feature_ids']), $settings);

      //Recover the implementations needed for the cells.
      $implementations = request_db('implementation', array('compared_ids' => array($_POST['nid']), 'feature_ids' => $_POST['feature_ids']), $settings);

      //If the table was computed, then we need to compute the implementation of the compared, with the displayed features.
      if ($settings['computed']) {

        //We will use only the feature without childre for the computation.
        $features_without_children = array();
        foreach ($features as $fid => $feature) {
          if (!$feature['data']->has_children) {
            $features_without_children[$fid] = $fid;
          }
        }

        //Build the whole features tree.
        $features = wikicompare_build_recursive_data('feature', $features_without_children, $settings);
        $features = $features['tree'];

      }

      //Finally prepare the features and implementations for rendering if necessary compute the implementation percent.
      $features = wikicompare_build_rows_data($features, array($_POST['nid']), $implementations, $settings);

      $cells = array();
      foreach ($features as $fid => $feature) {
        //Get implementation details.
        $implementation = $feature['implementations'][$_POST['nid']];
        //Render the cell.
        $cells[$implementation['data']->feature_id] = wikicompare_table_render_implementation($implementation, $feature, $settings);
      }

    }

    //Add the new cell at the end of the header.
    $commands[] = ajax_command_append('#comparative_table_header', $header);
    //Add the new cells at the end of each row.
    foreach ($cells as $fid => $cell) {
      $commands[] = ajax_command_append('#feature_table_' . $fid, $cell);
    }

  }

  //We disactivated the compared checkbox during the ajax call to avoid user spamming, reactivate it.
  $commands[] = ajax_command_invoke('#compared_table_checkbox_' . $_POST['nid'], 'removeAttr', array('disabled'));

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by simple dialog module to display a popin in the page.
 *
 * @param $context
 *   The context of the call, if we want to select one or several items in the popin.
 *
 * @param $type
 *   The type of the displayed nodes.
 *
 * @param $container
 *   The container we need to update when we submit the popin.
 *
 * @param $nid
 *   The nid of the forbidden node we must not be able to submit in the popin.
 *
 * @return $output
 *   The html code of the popin.
 */
function wikicompare_get_dialog_response($context, $type, $container, $nid){

  //In the option of the simple dialog, we need to provide an anchor which indicate the content to display in the popin.
  $output = t("<div id='dialog-content'>");

  //Initialize settings with the context. We also display all states to ensure we have access to all nodes in the popin.
  $settings = wikicompare_initialize_settings(array('context' => $context, 'states' => array('draft' => 'draft', 'closed' => 'closed')));

  //Indicate if on submit we must update selected_feature_ids or manual_selected_feature_ids in the javascript global variable.
  $output .= '<div id="initialize_selected_feature_dialog_ids" style="display:none;">';
  if ($container == 'manual-selected-features') {
    $output .= 'manual';
  } else {
   $output .= 'form';
  }
  $output .= '</div>';

  //Indicate the type of the nodes displayed in the popin.
  $output .= '<div id="dialog_type" style="display:none;">' . $type . '</div>';

  //Indicate the container to update when we submit the popin.
  $output .= '<div id="select_container" style="display:none;">' . $container . '</div>';

  //If there is a forbiden_id, we indicate it so the javascript can recover him in his ajax call.
  if ($nid != 0) {
    $output .= '<div id="forbidden_nid" style="display:none;">' . $nid . '</div>';
    //We also add it in settings for the itemlist we will build in this function.
    $settings['forbidden_nid'] = $nid;
  }

  //Find all the nodes on the first level of the tree.
  $nodes = request_db($type, array('parent_id' => NULL), $settings);

  //Building the data for the itemlist.
  $itemlist_data = wikicompare_build_itemlist($type, $nodes, 0, $settings);

  //Render the itemlist.
  $output .= theme_item_list(array('items' => $itemlist_data, 'type' => 'ul', 'attributes' => array()));

  //If we have to select several items, then we add a button at the end of the popin. This button is linked to an hidden javascript link.
  if ($settings['context'] == 'multidialog') {
    $submit_link = array(
      '#type' => 'link',
      '#title' => 'Submit',
      '#href' => 'wikicompare_submit_dialog_callback/nojs',
      '#id' => 'submitlink_dialog',
      '#attributes' => array(
        'class' => array('simple_ajaxlink'),
        'action' => 'submit_dialog',
        'style' => 'display:none',
      ),
    );
    $output .= '<p><input id="submitbutton_dialog" type="submit" link="submitlink_dialog" value="Submit" class="button wikicompare_button"/>' . render($submit_link) . '</p>';
  }

  $output .= t("</div>");

  return $output;

}



/**
 * Ajax callback function called by javascript when we submit a selectdialog popin.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_select_dialog_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  //Call the recursive function mainly to get the full title of the selected node.
  $res = wikicompare_build_recursive_data($_POST['type'], array($_POST['nid']), $settings);
  $parent = $res['data'][$_POST['nid']];

  //In form, generate the drupal field so drupal can find it on submit.
  $hidden = '';
  if ($parent) {
    $hidden = '<input type="text" size="60" value="&quot;' . $parent['data']->title . ' (' . $parent['data']->nid .  ')&quot;" name="' . str_replace("-", "_", $_POST['container']) . '[und][0][target_id]">';
  }

  $commands = array();
  //Display the full title of the selected node.
  $commands[] = ajax_command_html('#container-' . $_POST['container'], $parent['data']->fulltitle);
  //Update the drupal field in form.
  $commands[] = ajax_command_html('#edit-' . $_POST['container'], $hidden);
  //Update the fastedit field for fastedit submit.
  $commands[] = ajax_command_html('#' . $_POST['container'], $parent['data']->nid);

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript when we submit a multidialog popin.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_submit_dialog_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  //The submit callback will return a computed itemlist in the main page.
  $settings['computed'] = 1;

  //Get the context.
  $settings['context'] = 'selected';
  if ($_POST['container'] == 'manual_selected_features') {
    $settings['context'] = 'manual';
  }

  //Prepare the data with the tree by calling the recursive function.
  $features = array('data' => array());
  if ($settings['selected_feature_ids']) {
    $features = wikicompare_build_recursive_data('feature', $settings['selected_feature_ids'], $settings);
  }

  //Building the data for the itemlist.
  $itemlist_data = wikicompare_build_itemlist('feature', $features['tree'], 0, $settings);

  //Render the itemlist.
  $output = theme_item_list(array('items' => $itemlist_data, 'title' => 'Selected features', 'type' => 'ul', 'attributes' => array()));

  //In form, generate the drupal field many2many so drupal can find it on submit.
  $hidden = '<tbody>';
  $i = 0;
  foreach ($features['data'] as $feature) {
    //We remove the feature if it's a parent feature. This case can happen if we add the feature to the need when it has no children, and then it become a parent.
    if (!$feature['data']->has_children) {
      $hidden .= '<tr><td>
      <input type="text" size="60" value="&quot;' . $feature['data']->title . ' (' . $feature['data']->nid . ')&quot;" name="wikicompare_features[und][' . $i . '][target_id]">
      </td></tr>';
      $i += 1;
    }
  }
  //Add an empty field, in case the many2many is empty. If we don't do it, drupal will not empty the field on submit.
  $hidden .= '<tr><td>
    <input type="text" size="60" value="" name="wikicompare_features[und][' . $i . '][target_id]" >
    </td></tr>
    </tbody>';

  //Add the value for the fastaction form.
  $hidden_fastaction = '';
  foreach ($settings['selected_feature_ids'] as $feature_id) {
    $hidden_fastaction .= '<div class="need_feature">' . $feature_id . '</div>';
  }

  $commands = array();
  //Display the itemlist in the container.
  $commands[] = ajax_command_html('#container-' . $_POST['container'], $output);
  //Update the drupal field in form.
  $commands[] = ajax_command_html('#wikicompare-features-values', $hidden);
  //Update the fastedit field for fastedit submit.
  $commands[] = ajax_command_html('#wikicompare-features', $hidden_fastaction);

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript when we launch a compute or a reset table.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_compute_table_response($method = 'ajax') {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  //Get the features we will use to compute the table.
  $selected_feature_ids = array();
  if (!isset($_POST['reset'])) {

    $selected_feature_ids = $settings['selected_feature_ids'];

    if (module_exists('wikicompare_needs')) {
      //Add the features of the selected needs.
      wikicompare_needs_table_prepare_compute($selected_feature_ids, $_POST, $settings);
    }
  }

  $commands = array();

  if (module_exists('wikicompare_needs')) {
    //Add commmand to reset the need part of the table.
    wikicompare_needs_table_send_compute($commands, $settings);
  }

  //Reset the compared part of the table.
  $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_main_itemlist('compared', 'Compareds', $settings));

  //Compute the table, unless no features was selected. In this case, we just reset it.
  if ($selected_feature_ids && !isset($_POST['reset'])) {
    //Build the feature tree.
    $features = wikicompare_build_recursive_data('feature', $selected_feature_ids, $settings);
    //Indicate we are computing the table.
    $settings['computed'] = 1;
    //Render and compute the table.
    $output = wikicompare_table_render_comparative_table($settings, $features, $settings['compared_column_ids']);

  //Else, just reset the table.
  } else {
    $output = wikicompare_table_render_comparative_table($settings, array(), $settings['compared_column_ids']);
  }

  //Replace the old table.
  $commands[] = ajax_command_replace('#comparative_table', $output);

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript when we launch a cleaning table.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @param $_POST
 *   The variables send by the javascript.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_make_cleaning_response($method = 'ajax') {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  $commands = array();
  $update_selected_features = false;

  //Execute for all wikicompare node type, except implementation.
  $types = array('compared', 'feature');
  if (module_exists('wikicompare_needs')) {
    //Add need type.
    wikicompare_needs_node_types($types);
  }

  $features = array();
  foreach ($types as $type) {

    //We must not touch anything on a computed table.
    if ($type == 'feature' && $settings['computed']) {
      continue;
    }

    //Security for the TYPE_displayed_ids, it's an array but javascript return a string when empty.
    if ($_POST[$type . '_displayed_ids'] == '') {
      $_POST[$type . '_displayed_ids'] = array();
    }

    //Get the ids of all the nodes in the table.
    $node_ids = array();
    foreach ($_POST[$type . '_ids'] as $nid => $node) {
      $node_ids[$nid] = $nid;
    }

    //Get the details from database of all the nodes displayed in the table.
    $nodes = array();
    if (!empty($node_ids)) {
      $nodes = request_db($type, array('nids' => $node_ids), $settings);
      //We need to keep the features details for the part with the implementations.
      if ($type == 'feature') {
        $features = $nodes;
      }
    }

    //Get from database the list of the nodes at the top of the tree.
    $in_db_nodes = request_db($type, array('parent_id' => NULL), $settings);
    //Extract nids.
    $in_db_nodes_ids = array();
    foreach ($in_db_nodes as $nid => $node) {
      $in_db_nodes_ids[$nid] = $nid;
    }

    $in_table_node_ids = array();
    $reset = False;
    //We test all nodes present in the table. The TYPE_ids array contain the nids of the node, his parent id and the has_children flag.
    foreach ($_POST[$type . '_ids'] as $nid => $node_from_table) {

      //Listing all node present in table in a array for later use.
      $in_table_node_ids[$nid] = $nid;

      //If the node has a parent in the table.
      if (isset($node_from_table['parent_id'])) {

        //If the parent of the node in the table is different then the parent of the node in db.
        if ($node_from_table['parent_id'] != $nodes[$nid]['data']->parent_id) {

          if ($type == 'feature') {
            //In the case of a feature, it means there is a structural change so better refresh the manual_selected_feature itemlist.
            $update_selected_features = true;
          }

          //If the parent in table is currently displaying his children, then the tested node is displayed as his child but isn't anymore, so we need to hide it
          if (in_array($node_from_table['parent_id'], $_POST[$type . '_displayed_ids'])) {
            $commands[] = ajax_command_invoke('#' . $type . '_table_link_' . $node_from_table['parent_id'], 'click', array());
          }

          //If the parent of the node in db is displaying his children in the table, then the tested node is missing among the children so we need to hide the children of the parent. Also, if the tested node is now without parent, then we need to reset the table to display it.
          if (in_array($nodes[$nid]['data']->parent_id, $_POST[$type . '_displayed_ids']) || $nodes[$nid]['data']->parent_id == NULL) {
            if ($nodes[$nid]['data']->parent_id != NULL) {
              $commands[] = ajax_command_invoke('#' . $type . '_table_link_' . $nodes[$nid]['data']->parent_id, 'click', array());
            } else {
              $reset = True;
            }
          }

        }

      }

      //If the has_children flag is different in table or in db, then we need to reset the supertitle to display a label or a link at title of the node.
      if ($node_from_table['has_children'] != $nodes[$nid]['data']->has_children) {
        $commands[] = ajax_command_replace('#' . $type . '_table_supertitle_' . $nid, wikicompare_table_get_supertitle_item($type, $nodes[$nid], $settings));
        if (!$nodes[$nid]['data']->has_children) {
          $commands[] = ajax_command_invoke('#' . $type . '_table_item_'. $nid, 'removeClass', array('has_children'));
        }
      }

      //If one of the node without parent displayed in table isn't in the first level in db anymore.
      if ((!in_array($nid, $in_db_nodes_ids)) && !isset($node_from_table['parent_id'])) {
        $reset = True;
      }

    }

    foreach ($in_db_nodes_ids as $nid) {
      //If one of the node present in the first level in db isn't displayed in the table.
      if (!in_array($nid, $in_table_node_ids)) {
        $reset = True;
      }
    }

    //We get from database all the children of the parent which are currently displaying his children. If one children is missing on the table, then we force the concerned parent to hide his children.
    if (!empty($_POST[$type . '_displayed_ids'])) {
      //Get children from database by searching from parent_ids.
      $in_db_nodes_with_parent = request_db($type, array('parent_id' => $_POST[$type . '_displayed_ids']), $settings);
      foreach ($in_db_nodes_with_parent as $node) {
        //If one of the children isn't in the table.
        if (!in_array($node['data']->nid, $in_table_node_ids)) {
          //Then we collapse the children of the parent.
          $commands[] = ajax_command_invoke('#' . $type . '_table_link_' . $node['data']->parent_id, 'click', array());
        }
      }
    }

    //If during the previous tests, we ask to reset the table. Only the part concerned by the node type will be reset.
    if ($reset == True) {
      switch ($type) {
        case 'compared':
          $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_main_itemlist('compared', 'Compareds', $settings));
          break;
        case 'feature':
          $commands[] = ajax_command_replace('#comparative_table', wikicompare_table_render_comparative_table($settings, array(), $_POST['compared_column_ids']));
          break;
      }

    }

    if (module_exists('wikicompare_needs')) {
      //Add commmand to reset the need part of the table.
      wikicompare_needs_table_clean_reset($commands, $type, $reset, $settings);
    }

    //Reset all fields displayed in the table. All field are in a span to easily refresh them.
    foreach($nodes as $nid => $node) {
      $commands[] = ajax_command_invoke('.' . $type . '_title_' . $nid, 'html', array($node['data']->title));
      if ($type == 'feature') {
        $commands[] = ajax_command_invoke('.feature_title_' . $nid, 'html', array($node['data']->title));
        $commands[] = ajax_command_invoke('.feature_weight_' . $nid, 'html', array($node['data']->weight));
        $commands[] = ajax_command_invoke('.feature_type_' . $nid, 'html', array($node['data']->type));
        $commands[] = ajax_command_invoke('.feature_state_' . $nid, 'html', array($node['data']->state));
      }
      //If we are in fastaction mode, then we also refresh the fastaction items. This for exemple allow us to remove a fastedit item if someone else add a revision on a node while the author is browsing the comparative table.
      if ($settings['fastaction']) {
        $commands[] = ajax_command_invoke('#fastaction_items_' . $nid, 'html', array(add_fastaction_items($type , $node)));
      }
    }

    //Add fastaction items to the Add link.
    if ($settings['fastaction']) {
      $node = array(
        'data' => new stdClass(),
      );
      $node['data']->nid = 0;
      $commands[] = ajax_command_invoke('#add_' . $type . '_link_fastaction', 'html', array(add_fastaction_items($type , $node)));
    }

  }

  //We refresh the implementations only if the table wasn't computed.
  if (!$_POST['computed']) {

    //Extract feature_ids.
    $feature_ids = array();
    foreach ($_POST['feature_ids'] as $feature) {
      $feature_ids[$feature['nid']] = $feature['nid'];
    }

    //Get implementations details.
    $implementations = array();
    if (!empty($settings['compared_column_ids']) && !empty($feature_ids)) {
      $implementations = request_db('implementation', array('compared_ids' => $settings['compared_column_ids'], 'feature_ids' => $feature_ids), $settings);
    }

    //Rerender all the implementations displayed in the table.
    foreach($implementations as $fid => $compareds_implementations) {
      foreach ($compareds_implementations as $cid => $implementation) {
        $commands[] = ajax_command_replace('#implementation_' . $implementation['data']->nid, wikicompare_table_render_implementation($implementation, $features[$implementation['data']->feature_id], $settings));
      }
    }

  }

  //If during the tests, we asked for a reset of the selected features itemlist.
  if ($update_selected_features) {
    $features = array('tree' => array());
    if ($settings['selected_feature_ids']) {
      $features = wikicompare_build_recursive_data('feature', $settings['selected_feature_ids']);
    }
    //Building the data for the itemlist.
    $itemlist_data = wikicompare_build_itemlist('feature', $features['tree'], 0, array('computed' => 1));
    //Render the itemlist.
    $output = theme_item_list(array('items' => $itemlist_data, 'title' => 'Manually selected features', 'type' => 'ul', 'attributes' => array()));
    $commands[] = ajax_command_html('#container-manual-selected-features', $output);
  }

  //We remove all fastaction form.
  $commands[] = ajax_command_invoke('.form_fastaction', 'remove', array());

  //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
  $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}





/**
 * Function which initialize the settings array, so keys are never missing.
 *
 * @param $args
 *   Allow us to initialize some keys in the array with another value than the default one.
 *
 * @return $settings
 *   Array containing the initialized settings.
 */
function wikicompare_initialize_settings($args = array()) {

  $settings = array();
  foreach (array('fastaction', 'context', 'compared_column_ids', 'selected_feature_ids', 'forbidden_nid', 'computed', 'states', 'colspan') as $key) {

    //If the key is already set in the argument of the function, we directly use it.
    if (isset($args[$key])) {
      $settings[$key] = $args[$key];

      //Security for some fields coming from javascript, they are array but javascript return a string when empty.
      if (in_array($key, array('compared_column_ids', 'selected_feature_ids')) && $args[$key] == '') {
        $settings[$key] = array();
      }

    //Else we set 0 as default value, except for some specific key.
    } else {
      $result = 0;
      if ($key == 'context') {
        $result = 'table';
      } elseif (in_array($key, array('compared_column_ids', 'selected_feature_ids', 'states'))) {
        $result = array();
      }
      $settings[$key] = $result;
    }

  }

  return $settings;

}



/**
 * Type-agnostic function which render the Add link at the end of each table element in comparative table.
 *
 * @param $type
 *   The type of the table element.
 *
 * @return $settings
 *   The context of the table.
 */
function wikicompare_generate_add_link($type, $settings) {

  //Add the html code of the add link.
  $output = '<a id="add_' . $type . '_link" href="?q=node/add/' . $type . '">Add</a><span id="add_' . $type . '_link_fastaction">';
  //If fastaction mode is activated, we add the fastadd item.
  if ($settings['fastaction']) {
    $node = array(
      'data' => new stdClass(),
    );
    $node['data']->nid = 0;
    $output .= add_fastaction_items($type , $node);
  }
  $output .= '</span>';

  return $output;

}

?>
