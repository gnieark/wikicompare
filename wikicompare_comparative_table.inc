<?php


define('NOJS_MESSAGE', "You need to activate javascript to use the comparative table.");

//DONE
function wikicompare_comparative_table() {



  //Add the javascript files used in the comparative_table
  drupal_add_js('/misc/ajax.js');
  drupal_add_js('/misc/progress.js');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  $checkbox_settings =  array(
    '#type' => 'checkbox',
    '#title' => 'Display draft items',
    '#id' => 'checkbox-draft-items',
   );
  $output = render($checkbox_settings);

  $checkbox_settings =  array(
    '#type' => 'checkbox',
    '#title' => 'Display closed items',
    '#id' => 'checkbox-closed-items',
   );
  $output .= render($checkbox_settings);

  $output .= '<div id="container-manual-selected-features"></div>';



  //Add the link to open the select feature popup
  $select_feature_link = array(
    'text' => 'Select features',
    'title' => 'Select features',
    'selector' => 'dialog-content',
    'path' => 'wikicompare_get_dialog_callback/multidialog/feature/manual-selected-features/0/',//manual_selected_features/none',
    'id' => 'select_feature_link',

  );
  $output .= '<p>' . theme('simple_dialog_link', $select_feature_link) . '</p>';
  

  if (module_exists('wikicompare_needs')) {
    wikicompare_needs_comparative_table_main_output($output);
  }





  //Add the compute button
  $compute_link = array(
    '#type' => 'link',
    '#title' => 'Compute',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'compute_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'compute_table',
      'style' => 'display:none',
    ),
  );
  $output .= '<p><input id="compute_table_button" type="submit" link="compute_table_link" value="Compute table" class="button wikicompare_button"/>' . render($compute_link);
 



  //Add the reset button
  $reset_link = array(
    '#type' => 'link',
    '#title' => 'Reset table',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'reset_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'reset_table',
    ),

  );
  $output .= ' ' . render($reset_link) . '</p>';

  $output .= wikicompare_table_render_main_itemlist('compared', 'Compareds', wikicompare_initialize_settings());


  

  $output .= wikicompare_table_render_comparative_table(wikicompare_initialize_settings());


  //Add the link to go on FastAction mode
  $toogle_link = array(
    '#type' => 'link',
    '#title' => 'Toogle FastAction',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'toogle_fastaction_callback/nojs',
    '#id' => 'toogle_fastaction_link',

  );

  $output .= '<p>' . render($toogle_link) . '</p>';


  //Add the link to go on FastAction mode
  $cleaning_link = array(
    '#type' => 'link',
    '#title' => 'Clean',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'wikicompare_make_cleaning_callback/nojs',
    '#id' => 'make_cleaning_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'make_cleaning',
      'style' => 'display:none',
    ),

  );

  $output .= '<p>' . render($cleaning_link) . '</p>';


  return $output;
}


//DONE
function wikicompare_table_render_main_itemlist($type, $title, $settings) {

//  $settings = array('can_be_translated' => 1);
/*  if (isset($settings['states'])) {
    $db_settings['states'] = $settings['states'];
  }*/

  $settings['context'] = 'table';

  //Find all the compared on the first level of the tree
  $nodes = request_db($type, array('parent_id' => NULL), $settings);

  
//  $itemlist_settings = initialize_itemlist_settings('compared_main_table');
/*
  if (isset($settings['fastaction'])) {
    $itemlist_settings['fastaction'] = $settings['fastaction'];
  }
*/

  //Building the data for the item list
  $itemlist_data = wikicompare_build_itemlist($type, $nodes, 0, $settings);

  $output ="<div id='comparative_table_main_" . $type . "'>";
  //Render the item list
  $output .= theme_item_list(array('items' => $itemlist_data, 'title' => $title, 'type' => 'ul', 'attributes' => array()));
  $output .= '<p>' . wikicompare_generate_add_link($type, $settings) . '</p>';
  $output .= '<div id="' . $type . '_table_children_0"></div>';
  $output .="</div>";

  return $output;

}

//DONE
function wikicompare_table_render_comparative_table($settings, $features=array(), $compared_ids=array()){
/*
  $fastaction = 0;
  if (isset($settings['fastaction'])) {
    $fastaction = $settings['fastaction'];
  }

  $computed = 0;
  if (isset($settings['computed'])) {
    $computed = $settings['computed'];
  }

  $db_settings = array('can_be_translated' => 1);
  if (isset($settings['states'])) {
    $db_settings['states'] = $settings['states'];
  }
*/

//  $db_settings = array('feature_ids' => $feature_ids, 'compare_ids' => $compared_ids);

  $settings['context'] = 'table';

  if (empty($features)) {
    //Find all the features on the first level of the tree
    $features = request_db('feature', array('parent_id' => NULL), $settings);
  }

  foreach ($features as $fid => $feature) {
    $feature_ids[$fid] = $fid;
  }


  $implementations = array();
  //I though about move this security in the request itself, but it would add an unnecessary db request in some case.
  if (!empty($feature_ids) && !empty($compared_ids)) {
    $implementations = request_db('implementation', array('feature_ids' => $feature_ids, 'compared_ids' => $compared_ids), $settings);
// array('fastaction' => $fastaction, 'compared_ids' => $compareds, 'feature_ids' => $settings['feature_ids']));
  } 

  $features_row_data = wikicompare_build_rows_data($features, $compared_ids, $implementations, $settings);

  $compareds = array();
  if (!empty($compared_ids)) {
    $compareds = request_db('compared', array('nids' => $compared_ids), $settings);
/*
    $query = db_select('cache_compared', 's');
    $query->addField('s', 'nid', 'nid');
    $query->addField('s', 'title', 'title');
    $query->condition("s.nid", $compareds, 'in');
    $result = $query->execute();

    foreach ($result as $record) {
      $headers[$record->nid] = $record->title . ' ' . $record->nid;
    }
*/
  }

  //Building the table
  $output = '<table id="comparative_table"';
  if ($settings['computed']) {
    $output .= ' class="computed"';
  }
  $output .= '><thead>';
  $output .= '<tr id="comparative_table_header">';
  $output .= '<th>' . t('Features') . '</th>';
  foreach ($compareds as $cid => $compared) {
    $output .= '<th id="header_compared_' . $cid . '" class="header_compared"><span class="compared_title_' . $cid . '">' . $compared['data']->title . '</span></th>';
  }
  $output .= '</tr>';
  $output .= '</thead>';
  $output .= '<tbody>';

  $output .= wikicompare_table_render_rows($features_row_data, $settings);
//  $colspan = '';
  $output .= '<tr id="feature_table_0"><td class="row_auto_colspan" ';
  if (isset($settings['colspan'])) {
    $output .= 'colspan="' . $settings['colspan'] . '"';
  }
  $output .= '>';
  $output .= wikicompare_generate_add_link('feature', $settings);
/*

  $output .= '<a id="add_feature_link" href="?q=node/add/feature">Add</a><span id="add_feature_link_fastaction">';
  if ($settings['fastaction']) {
    $feature = array(
      'data' => new stdClass(),
    );
    $feature['data']->nid = 0;
    $output .= add_fastaction_items('feature' , $feature);
  }
*/
  $output .= '</span></td><tr>';
  $output .= '</tbody>';
  $output .= '</table>';

  return $output;


}

//DONE
function wikicompare_table_render_rows($features_row_data, $settings) {



  $output = '';

  //Add a row for each feature children
  foreach ($features_row_data as $fid => $feature) {


//    $feature = $feature_array['data'];

    $output .= '<tr id="feature_table_'. $fid . '" class="feature_row';
    if ($feature['data']->parent_id) {
        $output .= ' feature_table_child_' . $feature['data']->parent_id;
    }
    if ($feature['data']->has_children){
      $output .= ' has_children';
    }
    $output .= '"';
    if (!isset($feature['root'])) {
      $output .= ' style="display:none;"';
    }
    $output .= '>';


    $output .= '<td>' . wikicompare_table_get_supertitle_item('feature', $feature, $settings) . '</td>';



    //Add a column for each column in the table
    foreach ($feature['implementations'] as $implementation) {
      $output .= wikicompare_table_render_implementation($implementation, $feature, $settings);
    }
    $output .= '</tr>';
  }

  return $output;


}

//DONE
function wikicompare_table_render_implementation($implementation, $feature, $settings) {

//  $implementation = $implementation_array['data'];

  if (in_array($feature['data']->state, array('published-incomplete', 'published-submitted', 'published')) || $feature == NULL) {

/*
    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to implementation ') . $implementation['data']->nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $implementation['data']->nid,  array('attributes' => array('id' => 'implementation_node_link_' . $implementation['data']->nid, 'class' => array('implementation_node_link')), 'html' => True));
    $img_link_to_node .= '<span id="fastaction_items_' . $implementation['data']->nid . '">';

    if ($settings['fastaction') {
      $img_link_to_node .= add_fastaction_items('implementation', $implementation); 
    }
    $img_link_to_node .= '</span>';
*/

    $output = '<td id="implementation_' . $implementation['data']->nid . '" class="implementation_cell ' . $implementation['data']->css_class . ' implementation_compared_' . $implementation['data']->compared_id . ' implementation_feature_' . $implementation['data']->feature_id . '">' . wikicompare_table_get_supertitle_item('implementation', $implementation, $settings) . '</td>';

  } else {
    $output = '<td></td>';
  }

  return $output;
}

//DONE
function wikicompare_table_get_supertitle_item($type, $node, $settings) {

//  $node = $node_array['data'];



//  if ($type != 'feature' || $itemlist_settings['context'] != 'table') {

/*
  //If the node has children, the node name will become a link calling the callback function to display his children
  if ($node->has_children){
    $class = array('list_item_link ', $type, $itemlist_settings['context']);

    if ($itemlist_settings['computed']) {
      $class[] = 'computed';
    }
    $title = l($title, 'wikicompare_build_itemlist_children_callback/nojs/',  array('attributes' => array('id' => $type . '_' . $itemlist_settings['context'] . '_link_' . $node->nid, 'class' => $class, 'type' => $type, 'context' => $itemlist_settings['context']), 'html' => True));

    if ($type == 'feature' && $itemlist_settings['context'] == 'table') {
      $title = l($title, 'get_feature_callback/nojs/',  array('attributes' => array('id' => $type . '_table_link_' . $node->nid, 'class' => array($type . '_link ' . $type . '_link_children_' . $node->nid)), 'html' => True));
    }

  }
*/
 

  //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table. Unless we configure the system to compute the compared parent, only the compared with no children will have a checkbox.
  $prefix = '';
  $suffix = '';
  $title = '<span class="' . $type . '_title_' . $node['data']->nid . '">' . $node['data']->title . '</span>';
  if ($type == 'implementation') {
    $title = $node['data']->percent . '%';
  }
  if ($settings['context'] == 'table') {

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to ' . $type . ' ') . $node['data']->nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $suffix .= ' ' . l($img, 'node/' . $node['data']->tnid, array('attributes' => array('id' => $type . '_node_link_' . $node['data']->nid), 'html' => True));

    $suffix .= '<span id="fastaction_items_' . $node['data']->nid . '">';
    if ($settings['fastaction']) {
      $suffix .=  add_fastaction_items($type, $node);
    }
    $suffix .= '</span>';
  }

  $url = 'wikicompare_get_itemlist_children_callback/nojs/';
  if ($type == 'feature' && $settings['context'] == 'table') {
    $url = 'wikicompare_get_feature_children_callback/nojs/';
    //Creating the first cell of the row, containing the feature details
    $suffix .= '<br/> Weight : <span class="' . $type . '_weight_' . $node['data']->nid . '">' .  $node['data']->weight . '</span>';
    if ($node['data']->has_children){
      $suffix .= '<br/> Type : <span class="' . $type . '_type_' . $node['data']->nid . '">' .  $node['data']->type . '</span>';
    }
    $suffix .= '<br/> State : <span class="' . $type . '_state_' . $node['data']->nid . '">' .  $node['data']->state . '</span>';
  
/*
    if ($node['data']->has_children){
      $class = array('item_link ' . $type . '_link_children_' . $node['data']->nid . ' ' . $type . '_table_link');
      if ($settings['computed']) {
        $class[] = 'computed';
      }
      $title = l($title, 'wikicompare_get_feature_children_callback/nojs/',  array('attributes' => array('id' => $type . '_table_link_' . $node['data']->nid, 'class' => $class, 'ntype' => 'feature', 'context' => 'table'), 'html' => True));
    }
*/




  } else {

    if ($node['data']->nid != $settings['forbidden_nid']) {

      if (in_array($settings['context'], array('table', 'multidialog')) && in_array($node['data']->state, array('published-incomplete', 'published-submitted', 'published'))) {

        if (variable_get('wikicompare_update_compared', 'no-update') != 'no-update' || $node['data']->has_children != 1) {
          $checkbox_settings = array('element' => array(
            '#title' => $node['data']->nid,
            '#id' => $type . '_' . $settings['context'] . '_checkbox_' . $node['data']->nid,
            '#attributes' => array(
              'class' => array('itemlist_checkbox'),
              'ntype' => $type,
              'context' => $settings['context'],
            ),
          ));
  /*
          if ($type == 'compared') {

            $checkbox_settings['element']['#attributes']['class'] = array('compared_checkbox');
          } else {
            $checkbox_settings['element']['#attributes']['class'] = array('itemlist_checkbox ' . $type);
          }
  */

          if (isset($node['data']->displayed)) {
            $checkbox_settings['element']['#checked'] = True;
          }

          $prefix .= theme_checkbox($checkbox_settings) . ' ';

          if ($type == 'compared') {


            //We were not able to ajaxify the checkbox, so instead the checkbox will call this hidden link
            $checkbox_link = array(
              '#type' => 'link',
              '#title' => 'toggle',
              //The link for the callback function which will display or hide the column in the table
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

  if ($node['data']->has_children){
    $class = array('item_link');

    if ($settings['computed']) {
      $class[] = 'computed';
    }
    if ($settings['context'] == 'table') {
      $class[] = $type . '_table_link';
    }
    $title = l($title, $url,  array('attributes' => array('id' => $type . '_' . $settings['context'] . '_link_' . $node['data']->nid, 'class' => $class, 'ntype' => $type, 'context' => $settings['context']), 'html' => True));

  }


/*
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
      if ($itemlist_settings['fastaction']) {
        $img_link_to_node .=  add_fastaction_items($type, $node_array);
      }
      $img_link_to_node .= '</span>';
    }
*/
/*
    if ($itemlist_settings['context'] == 'selectdialog') {

      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Select ') . $type . ' ' . $node->nid,
        'height' => '100%',
      ));

      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link = l($img, 'wikicompare_select_dialog_callback/nojs', array('attributes' => array('id' => 'wikicompare_select_dialog_' . $node->nid, 'class' => array('select_simple_dialog')), 'html' => True));
      $checkbox_area = $img_link . ' ';
    }
*/


//    $output = $checkbox_area . $title . $img_link_to_node;


/*
    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to feature ') . $node->nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $node->tnid, array('attributes' => array('id' => 'feature_node_link_' . $node->nid, 'class' => array($type . '_node_link')), 'html' => True));
    $img_link_to_node .= '<span id="fastaction_items_' . $node->nid . '">';
    if ($itemlist_settings['fastaction']) {

      $img_link_to_node .= add_fastaction_items($type, $node_array); 
    }
    $img_link_to_node .= '</span>';
*/
/*
    $title = '<span class="feature_title_' . $node->nid . '">' . $node->title . '</span>';
    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($node->has_children){
      $title = l($title, 'get_feature_callback/nojs/',  array('attributes' => array('id' => $type . '_table_link_' . $node->nid, 'class' => array($type . '_link ' . $type . '_link_children_' . $node->nid)), 'html' => True));
    } 


    //Creating the first cell of the row, containing the feature details
    $output = $title . ' ' . $img_link_to_node  . '<br/> Weight : <span class="' . $type . '_weight_' . $node->nid . '">' .  $node->weight . '</span>';
    if ($node->has_children){
      $output .= '<br/> Type : <span class="' . $type . '_type_' . $node->nid . '">' .  $node->type . '</span>';
    }
    $output .= '<br/> State : <span class="' . $type . '_state_' . $node->nid . '">' .  $node->state . '</span>';

  }
  */

  return '<span id="' . $type . '_' . $settings['context'] . '_supertitle_' . $node['data']->nid . '">' . $prefix . $title . $suffix . '</span>';

}



//DONE
/*
 * Function which will build the item list. Used in table initial building, in compared ajax callback and in modal dialog
 */
function wikicompare_build_itemlist($type, $nodes, $parent_node, $settings){



  $items = array();
  foreach ($nodes as $nid => $node){
/*
    if ($nid == $settings['forbidden_nid']) {
      continue;
    }
*/

//    $node = $node_array['data'];


    
    $items[$nid]['id'] = $type . '_' . $settings['context'] . '_item_' .  $nid;
    $items[$nid]['data'] = wikicompare_table_get_supertitle_item($type, $node, $settings);
    $items[$nid]['type'] =  $type;
    $items[$nid]['context'] = $settings['context'];
    $items[$nid]['class'] = array($type . '_item');
    if ($node['data']->has_children){
      $items[$nid]['class'][] = 'has_children';
    }
    if ($parent_node != 0) {
      $items[$nid]['class'] = array_merge($items[$nid]['class'], array($type . '_' . $settings['context'] . '_child_' . $parent_node));

      if ($settings['computed']) {
        $items[$nid]['style'] = 'display:none';
      }
    }


    if ($settings['computed'] && $node['data']->has_children) {
       $items[$nid]['children'] = wikicompare_build_itemlist($type, $node['children'], $nid, $settings);
    } else {
      //After the compared, we add the div which will contain the children
      $items[$nid]['data'] .= '<div id="' . $type . '_' . $settings['context'] . '_children_' . $nid . '" class="'. $type . '_children" style="display:none;"></div>';
    }


  }


  if (empty($items)) {
    $items[]['data'] = "There is no data yet.";
  }

  return $items;

}

//DONE

function wikicompare_build_recursive_data($type, $node_ids, $settings){

  $res = array();
dpm($node_ids);
  $res = wikicompare_build_recursive_tree($type, $node_ids, $res, $settings);
dpm($res);
  $res = wikicompare_build_fulltitle($res, $res['tree'], '');

  return $res;

}


//DONE 
function wikicompare_build_recursive_tree($type, $node_ids, $res, $settings){

  $parent_ids = array();

  //No other way here but to put this query in recursive function. Some improvement for later may be to use the WITH RECURSIVE function of postgresql.

  $nodes = request_db($type, array('nids' => $node_ids), $settings);


  foreach ($nodes as $nid => $node) {
    //Check if some children of this node launched the recursive function to find this node as their parent. Then assign them as children of this node and unset the node in the array.
    if (isset($res['parent_ressource'][$nid]['children'])) {
      $node['children'] = $res['parent_ressource'][$nid]['children'];

/*      if (isset($res['tree'][$nid])) {
dpm($res['tree'][$nid]['children']);
dpm($res['parent_ressource'][$nid]['children']);
        $node['children'] = $res['tree'][$nid]['children'] + $res['parent_ressource'][$nid]['children'];
      }*/
      unset($res['parent_ressource'][$nid]);
    }
    //If the parent was already set on the tree by a child on a different level
    if (isset($res['tree'][$nid])) {
      $node['children'] = $res['tree'][$nid]['children'] + $node['children'];
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
dpm($parent_ids);
dpm($res);
  //If there is others parents to add in the array, relaunch the recursive function until all parents are found.
  if ($parent_ids){
    $res = wikicompare_build_recursive_tree($type, $parent_ids, $res, $settings);
  } else {
    unset($res['parent_ressource']);
  }
  
  return $res;

}


//DONE
function wikicompare_build_fulltitle($res, $tree, $parent_title) {

  foreach ($tree as $nid => $node) {


    $fulltitle = $node['data']->title;
    if ($parent_title) {
      $fulltitle = $parent_title . ' / ' . $fulltitle;
    }

    $res['data'][$nid]['data']->fulltitle = $fulltitle;
    if (!empty($node['children'])) {
      $res = wikicompare_build_fulltitle($res, $node['children'], $fulltitle);
    }

  }

  return $res;

}

/*
 * Function which will build the features row. Used in table initial building and in feature ajax callback
 */
//DONE
function wikicompare_build_rows_data($features_tree, $compared_ids, $implementations, $settings){


  $rows = array();

  foreach ($features_tree as $fid => $feature){




    $rows[$fid] = $feature;

    //We need to set this flag, otherwise the parent will have no way to recover his true children since they will be all at the same level.
    if ($feature['data']->parent_id) {
      $rows[$fid]['direct-child'] = True;
    } else {
      $rows[$fid]['root'] = True;
    }

    $children = array();
    if ($feature['children']) {
      $children = wikicompare_build_rows_data($feature['children'], $compared_ids, $implementations, $settings);
    }

    //Since the row are not in a tree but in the end they are all at the same level, we need to use this flag to recover the true children of the node we are currently working on.
    $direct_children = array();
    foreach ($children as $key => $child) {
      if (isset($child['direct-child'])) {
        $direct_children[$key] = $child;
        unset($children[$key]['direct-child']);
      }
    }


    $rows[$fid]['implementations'] = array();

    //Adding one cell for each implementation, which contain the details of the cells
    foreach ($compared_ids as $cid) {


      $implementation = $implementations[$fid][$cid];

      if ($settings['computed']) {
        //The type of the feature will be used in the wikicompare_compute_percent function
        $implementation['data']->type = $feature['data']->type;
        //The weight will be used in the parent wikicompare_compute_percent function
        $implementation['data']->weight = $feature['data']->weight;


        $through_feature_childs = array();
        foreach ($direct_children as $child) {
          $child_implementation = $child['implementations'][$cid]['data'];
          $through_feature_childs[$child_implementation->feature_id] = $child_implementation;
        }
        if (!empty($through_feature_childs)) {
//$feature['data']->has_children) {

          $implementation['data'] = wikicompare_compute_percent($implementation['data'], $through_feature_childs);
        }
      }

      $rows[$fid]['implementations'][$cid] = $implementation;

    }


    foreach ($children as $key=> $child) {
      $rows[$key] = $child;
    }




  }

  return $rows;

}



/*
 * Ajax callback cunction called by javascript to recover the compared children of the clicked compared
 */
//DONE
function wikicompare_get_itemlist_children_response($method = 'ajax') {



//  $nid = $_POST['nid'];
//  $type = $_POST['type'];
//  $context = $_POST['context'];


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }


  $commands = array();

  //If we want to displayed the children
  if ($_POST['display']) {

    $settings = wikicompare_initialize_settings($_POST);

    $nodes = request_db($_POST['type'], array('parent_id' => $_POST['nid']),  $settings);
//'fastaction' => $_POST['fastaction'], 'can_be_translated' => 1, 'states' => $_POST['states']));

//      $settings = array(); //initialize_itemlist_settings($_POST['context']);

//      $settings['context'] = $_POST['context'];

//      if (!empty($_POST['fastaction'])) {
//      $settings['fastaction'] = $_POST['fastaction'];
//      }

    if (isset($_POST['selected_feature_ids'])) {
      if ($_POST['selected_feature_ids'] == '') {
        $_POST['selected_feature_ids'] = array();
      }

    }
    //Prepare the array to use as argument for the item list building function

    foreach ($nodes as $nid => $node) {

      if ($_POST['type'] == 'compared' && $settings['context'] == 'table') {
        //If already displayed in the table, we check it by default
//          if (!empty($_POST['compared_column_ids'])) {
        if (in_array($nid, $_POST['compared_column_ids'])) {
          $nodes[$nid]['data']->displayed = True;
        }
//        }

      }

      if ($_POST['type'] == 'feature' && $settings['context'] == 'multidialog') {



//          $selected_feature_ids = $_POST['selected_feature_ids'];
        if (in_array($nid, $_POST['selected_feature_ids'])) {
          $nodes[$nid]['data']->displayed = True;
        }
      }


      if (module_exists('wikicompare_needs')) {
        wikicompare_needs_table_prepare_itemlist($nid, $nodes, $_POST);
      }


    }
/*
    if (isset($_POST['forbidden_nid'])) {
      $settings['forbidden_nid'] = $_POST['forbidden_nid'];
    }
*/

/*
    $dialog = 0;
    $dialog_text = '';
    if (isset($_POST['dialog'])) {
      $itemlist_settings['dialog'] = 1;
      $itemlist_settings['node_link'] = 0;
      $dialog_text = 'dialog_';
    }
*/


    //Building the data for the item list
    $itemlist_data = wikicompare_build_itemlist($_POST['type'], $nodes, $_POST['nid'], $settings);

    //Rendering the item list
    $output = theme_item_list(array('items' => $itemlist_data, 'title' => '',  'type' => 'ul', 'attributes' => array()));

    //Preparing the ajax commands to return to javascript
//      $commands = array();
    //We prepared a div under the parent compared. This command will fill it with the compared children, and replace anything that was here before.

//$output = 'TEST';
    $commands[] = ajax_command_html('#'. $_POST['type'] . '_' . $settings['context'] . '_children_' . $_POST['nid'], $output);



  //If we want to collapse the compared children
  } 



  $page = array('#type' => 'ajax', '#commands' => $commands);

  return $page;

}

/*
 * Ajax callback cunction called by javascript to recover the feature children of the clicked feature
 */
//DONE
function wikicompare_get_feature_children_response($method = 'ajax') {


//  $fid = $_POST['nid'];



  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $commands = array();
  //If we want to displayed the compared children
  if ($_POST['display']) {

    $settings = wikicompare_initialize_settings($_POST);
/*
    $fastaction = 0;
    if (!empty($_POST['fastaction'])) {
      $fastaction = $_POST['fastaction'];
    }
*/
//      $settings['context'] = 'table';

    $features = request_db('feature', array('parent_id' => $_POST['nid']), $settings);


    $feature_ids = array();
    foreach ($features as $fid => $feature) {
      $feature_ids[$fid] = $fid;
    }

    $implementations = array();
    //We recover from javascript argument the id of the columns displayed in the table, to know the cell we have to add
    if (!empty($_POST['compared_column_ids'])) {
      //Recover the implementation needed for the cells
      $implementations = request_db('implementation', array('compared_ids' => $_POST['compared_column_ids'], 'feature_ids' => $feature_ids), $settings);
    }
    //Building the data for the table row


    if ($_POST['compared_column_ids'] == '') {
      $_POST['compared_column_ids'] = array();
    }
    $feature_row_data = wikicompare_build_rows_data($features, $_POST['compared_column_ids'], $implementations, $settings);


    $output = wikicompare_table_render_rows($feature_row_data, $settings);


    //We add the code after the parent row. Note we can't use ajax_command_after because it adds an unwanted div
    $commands[] = ajax_command_invoke('#feature_table_' . $_POST['nid'], 'after', array($output));

    //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
    $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');



  //If we want to collapse the feature children
  } 
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}





/*
 * Ajax callback cunction called by javascript to add or remove a column in the comparative table
 */
//DONE
function wikicompare_toggle_compared_checkbox_response($method = 'ajax'){

//  $cid = $_POST['nid'];


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }



  $commands = array();
  //If we want to displayed the compared children
  if ($_POST['display']) {

    $settings = wikicompare_initialize_settings($_POST);


//      $settings['states'] = array('draft' => 'draft', 'closed' => 'closed');
/*
    //Recover fastaction status
    $fastaction = 0;
    if (!empty($_POST['fastaction'])) {
      $fastaction = $_POST['fastaction'];
    }
*/
    //Recover the detail of the compared we want to add
    $compared = request_db('compared', array('nids' => array($_POST['nid'])), $settings);


    //Add the header of the new column, with the compared detail
    $header = '<th id="header_compared_' . $_POST['nid'] . '" class="header_compared" style="display:none;"><span class="compared_title_' . $_POST['nid'] . '">' . $compared[$_POST['nid']]['data']->title . '</span></th>';

    //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
    if (!empty($_POST['feature_ids'])) {

      $features = request_db('feature', array('nids' => $_POST['feature_ids']), $settings);

      //Recover the implementation needed for the cells
      $implementations = request_db('implementation', array('compared_ids' => array($_POST['nid']), 'feature_ids' => $_POST['feature_ids']), $settings);



      if ($settings['computed']) {
        $features_without_children = array();
        foreach ($features as $fid => $feature) {
          if (!$feature['data']->has_children) {
            $features_without_children[$fid] = $fid;
          }
        }
        $features = wikicompare_build_recursive_data('feature', $features_without_children, $settings);

        $features = wikicompare_build_rows_data($features['tree'], array($_POST['nid']), $implementations, $settings); 


      } else {
        $features = request_db('feature', array('nids' => $_POST['feature_ids']));

      }




      $cells = array();
      foreach ($features as $fid => $feature) {

        $implementation = $implementations[$fid][$_POST['nid']];

        $cells[$implementation['data']->feature_id] = wikicompare_table_render_implementation($implementation, $feature, $settings);
      }
    }



    //Preparing the ajax commands to return to javascript
    $commands = array();
    //Add the new cell at the end of the header
    $commands[] = ajax_command_append('#comparative_table_header', $header);
    //Add the new cells at the end of each row
    foreach ($cells as $fid => $cell) {
      $commands[] = ajax_command_append('#feature_table_' . $fid, $cell);
    }

    $commands[] = ajax_command_invoke('#compared_table_checkbox_' . $_POST['nid'], 'removeAttr', array('disabled'));

    $page = array('#type' => 'ajax', '#commands' => $commands);

    return $page;

  //If we want to remove the column
  } else {

    $commands[] = ajax_command_invoke('#compared_table_checkbox_' . $_POST['nid'], 'removeAttr', array('disabled'));


  }

  $page = array('#type' => 'ajax', '#commands' => $commands);

  return $page;


}

//DONE

function wikicompare_get_dialog_response($context, $type, $container, $nid){




  $output = t("<div id='dialog-content'>");

  $settings = wikicompare_initialize_settings(array('context' => $context, 'states' => array('draft' => 'draft', 'closed' => 'closed')));


  $output .= '<div id="initialize_selected_feature_dialog_ids" style="display:none;">';
  if ($container == 'manual-selected-features') {
    $output .= 'manual';
  } else {
   $output .= 'form';
  }
  $output .= '</div>';
  $output .= '<div id="dialog_type" style="display:none;">' . $type . '</div>';
  $output .= '<div id="select_container" style="display:none;">' . $container . '</div>';
//  $output .= '<div id="select_container_autocomplete" style="display:none;">' . $container_autocomplete . '</div>';
//  $output .= '<div id="select_container_id" style="display:none;">' . $container_id . '</div>';

//  $itemlist_settings = initialize_itemlist_settings($context);

//  $itemlist_settings['context'] = $context;
//  $itemlist_settings['node_link'] = 0;

  if ($nid != 0) {
    $output .= '<div id="forbidden_nid" style="display:none;">' . $nid . '</div>';
    $settings['forbidden_nid'] = $nid;
  }

  //Find all the features on the first level of the tree
  $nodes = request_db($type, array('parent_id' => NULL), $settings);

  //Building the data for the item list
  $itemlist_data = wikicompare_build_itemlist($type, $nodes, 0, $settings);


  $output .= theme_item_list(array('items' => $itemlist_data, 'type' => 'ul', 'attributes' => array()));

  //Add the compute button
  $submit_link = array(
    '#type' => 'link',
    '#title' => 'Submit',
    //The callback link, /nojs is automatically replace for /ajax by drupal. The secondi argument indicate if we have to display or hide the elements
    '#href' => 'wikicompare_submit_dialog_callback/nojs',
    '#id' => 'submitlink_dialog',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'submit_dialog',
      'style' => 'display:none',
    ),
  );

  if ($settings['context'] == 'multidialog') {
    $output .= '<p><input id="submitbutton_dialog" type="submit" link="submitlink_dialog" value="Submit" class="button wikicompare_button"/>' . render($submit_link) . '</p>';
  }

  $output .= t("</div>");
  return $output;

}

//DONE
function wikicompare_select_dialog_response($method = 'ajax'){


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }


  $settings = wikicompare_initialize_settings($_POST);

  $res = wikicompare_build_recursive_data($_POST['type'], array($_POST['nid']), $settings);

  $parent = $res['data'][$_POST['nid']];

  $hidden = '';
  if ($parent) {
    $hidden = '<input type="text" size="60" value="&quot;' . $parent['data']->title . ' (' . $parent['data']->nid .  ')&quot;" name="' . str_replace("-", "_", $_POST['container']) . '[und][0][target_id]">';


  }

  $commands = array();
  $commands[] = ajax_command_html('#container-' . $_POST['container'], $parent['data']->fulltitle);
  $commands[] = ajax_command_html('#edit-' . $_POST['container'], $hidden);
  $commands[] = ajax_command_html('#' . $_POST['container'], $parent['data']->nid);
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;



}


//DONE
function wikicompare_submit_dialog_response($method = 'ajax'){


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }



//    $selected_feature_ids = $_POST['selected_feature_ids'];



  $settings = wikicompare_initialize_settings($_POST);
  $settings['computed'] = 1;


//    $itemlist_settings = initialize_itemlist_settings('feature_list_computed');
  if ($_POST['container'] == 'manual_selected_features') {
    $settings['context'] = 'manual';
  } else {
    $settings['context'] = 'selected';
  }

  $features = array('data' => array());
  if ($_POST['selected_feature_ids']) {
    $features = wikicompare_build_recursive_data('feature', $_POST['selected_feature_ids'], $settings);
  }

  //Building the data for the item list
  $itemlist_data = wikicompare_build_itemlist('feature', $features['tree'], 0, $settings);


  //Render the item list
  $output = theme_item_list(array('items' => $itemlist_data, 'title' => 'Selected features', 'type' => 'ul', 'attributes' => array()));

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

  
  $hidden .= '<tr><td>
    <input type="text" size="60" value="" name="wikicompare_features[und][' . $i . '][target_id]" >
    </td></tr>
    </tbody>';

  $hidden_fastaction = '';
  foreach ($_POST['selected_feature_ids'] as $feature_id) {
    $hidden_fastaction .= '<div class="need_feature">' . $feature_id . '</div>';
  }

  $commands = array();
  $commands[] = ajax_command_html('#container-' . $_POST['container'], $output);
  $commands[] = ajax_command_html('#wikicompare-features-values', $hidden);
  $commands[] = ajax_command_html('#wikicompare-features', $hidden_fastaction);

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



function wikicompare_compute_table_response($method = 'ajax') {

dpm($_POST);
  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }



  $settings = wikicompare_initialize_settings($_POST);

//    $settings['colspan'] = $_POST['colspan'];

  $selected_feature_ids = array();
  if (!isset($_POST['reset'])) {


    if ($_POST['selected_feature_ids'] == '') {
      $_POST['selected_feature_ids'] = array();
    }

    $selected_feature_ids = $_POST['selected_feature_ids'];




    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_table_prepare_compute($selected_feature_ids, $_POST);
    }

  }



  //If empty, javascript return a null string and not an empty array. So we need to assign it in a variable and manage the null case.

  $compared_columns_ids = array();
  if ($_POST['compared_column_ids']) {
    $compared_columns_ids = $_POST['compared_column_ids'];
  }
/*
  $fastaction = 0;
  if (!empty($_POST['fastaction'])) {
    $fastaction = $_POST['fastaction'];
  }
*/

  $commands = array();

  if (module_exists('wikicompare_needs')) {
    wikicompare_needs_table_send_compute($commands, $settings);
  }


  $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_main_itemlist('compared', 'Compareds', $settings));


//    $settings = array('fastaction' => $fastaction, 'states' => $_POST['states'], 'colspan' => $_POST['nb_compareds']);
  if ($selected_feature_ids && !isset($_POST['reset'])) {

    $features = wikicompare_build_recursive_data('feature', $selected_feature_ids, $settings);

//      $settings['feature_ids'] = $features['ids'];
    $settings['computed'] = 1;


    $output = wikicompare_table_render_comparative_table($settings, $features['tree'], $compared_columns_ids);

  } else {
    $output = wikicompare_table_render_comparative_table($settings, array(), $compared_columns_ids);
  }


  //Preparing the ajax commands to return to javascript

  $commands[] = ajax_command_replace('#comparative_table', $output);
  $page = array('#type' => 'ajax', '#commands' => $commands);

  return $page;

}



function wikicompare_make_cleaning_response($method = 'ajax') {



  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }


  $settings = wikicompare_initialize_settings($_POST);

  $commands = array();
  $update_selected_features = false;


  $types = array('compared', 'feature');
  if (module_exists('wikicompare_needs')) {
    wikicompare_needs_wikicompare_node_types($types);
  }

  foreach ($types as $type) {

    if ($type == 'feature' && $settings['computed']) {
      continue;
    }


    if ($_POST[$type . '_displayed_ids'] == '') {
      $_POST[$type . '_displayed_ids'] = array();
    }

    $node_ids = array();  //$_POST['compared_column_ids'];
    foreach ($_POST[$type . '_ids'] as $nid => $node) {
      $node_ids[$nid] = $nid;
    }
  

    $nodes = array();
    if (!empty($node_ids)) {
      $nodes = request_db($type, array('nids' => $node_ids), $settings);
// array('fastaction' => $_POST['fastaction'], 'can_be_translated' => 1, 'nids' => $node_ids));
    }


    $in_db_nodes = request_db($type, array('parent_id' => NULL), $settings);
    $in_db_nodes_ids = array();
    foreach ($in_db_nodes as $nid => $node) {
      $in_db_nodes_ids[$nid] = $nid;
    }






    $in_table_node_ids = array();
    $reset = False;
    //We test all nodes present in the table
    foreach ($_POST[$type . '_ids'] as $nid => $node_from_table) {

      //Listing all node present in table in a array for later use
      $in_table_node_ids[$nid] = $nid;
      //If the node has a parent in the table
      if (isset($node_from_table['parent_id'])) {
        //If the parent of the node in the table is different of the parent of the node in db
        if ($node_from_table['parent_id'] != $nodes[$nid]['data']->parent_id) {

          if ($type == 'feature') {
            //In the case of a feature, it means there is a structural change so better refresh the manual_selected_feature itemlist
            $update_selected_features = true;
          }
          //If the parent in table is currently displaying his children, then the tested node is displayed as his child but isn't anymore, so we need to hide it
          if (in_array($node_from_table['parent_id'], $_POST[$type . '_displayed_ids'])) {
/*
            $parent = request_db($type, array('nids' => array($node_from_table['parent_id'])));
            $parent = $parent[$node_from_table['parent_id']];
*/
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

      if ($node_from_table['has_children'] != $nodes[$nid]['data']->has_children) {

        $commands[] = ajax_command_replace('#' . $type . '_table_supertitle_' . $nid, wikicompare_table_get_supertitle_item($type, $nodes[$nid], $settings));
        if (!$nodes[$nid]['data']->has_children) {
          $commands[] = ajax_command_invoke('#' . $type . '_table_item_'. $nid, 'removeClass', array('has_children'));
        }
      

    

      }


      //If one of the node without parent displayed in table isn't in the first level in db anymore
      if ((!in_array($nid, $in_db_nodes_ids)) && !isset($node_from_table['parent_id'])) {

        $reset = True;

      }
    }

    foreach ($in_db_nodes_ids as $nid) {
      //If one of the node present in the first level in db isn't displayed in the table
      if (!in_array($nid, $in_table_node_ids)) {

        $reset = True;
      }
    } 

    if (!empty($_POST[$type . '_displayed_ids'])) {
      $in_db_nodes_with_parent = request_db($type, array('parent_id' => $_POST[$type . '_displayed_ids']), $settings);

      foreach ($in_db_nodes_with_parent as $node) {
        if (!in_array($node['data']->nid, $in_table_node_ids)) {

          $commands[] = ajax_command_invoke('#' . $type . '_table_link_' . $node['data']->parent_id, 'click', array());
        }
      }
    }


    if ($reset == True) {
      switch ($type) {
        case 'compared':
          $commands[] = ajax_command_replace('#comparative_table_main_compared', wikicompare_table_render_main_itemlist('compared', 'Compareds', $settings));
          break;
        case 'feature':
/*            $settings = array(
            'fastaction' => $_POST['fastaction'],
            'computed' => 0
          );*/
          $commands[] = ajax_command_replace('#comparative_table', wikicompare_table_render_comparative_table($settings, array(), $_POST['compared_columns_ids']));
          break;
      }

    }



    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_table_clean_reset($commands, $type, $reset, $settings);
    }


    foreach($nodes as $nid => $node) {
      $commands[] = ajax_command_invoke('.' . $type . '_title_' . $nid, 'html', array($node['data']->title));
      if ($type == 'feature') {
        $commands[] = ajax_command_invoke('.feature_title_' . $nid, 'html', array($node['data']->title));
        $commands[] = ajax_command_invoke('.feature_weight_' . $nid, 'html', array($node['data']->weight));
        $commands[] = ajax_command_invoke('.feature_type_' . $nid, 'html', array($node['data']->type));
        $commands[] = ajax_command_invoke('.feature_state_' . $nid, 'html', array($node['data']->state));
      }
      if ($settings['fastaction']) {
        $commands[] = ajax_command_invoke('#fastaction_items_' . $nid, 'html', array(add_fastaction_items($type , $node)));
      }
    }

    if ($settings['fastaction']) {
      $node = array(
        'data' => new stdClass(),
      );
      $node['data']->nid = 0;
      $commands[] = ajax_command_invoke('#add_' . $type . '_link_fastaction', 'html', array(add_fastaction_items($type , $node)));
    }

  }




  if (!$_POST['computed']) {

    $feature_ids = array();
    foreach ($_POST['feature_ids'] as $feature) {
      $feature_ids[$feature['nid']] = $feature['nid'];
    }

    $implementations = array();

    if (!empty($_POST['compared_column_ids']) && !empty($feature_ids)) {
      $implementations = request_db('implementation', array('compared_ids' => $_POST['compared_column_ids'], 'feature_ids' => $feature_ids), $settings);
    }



    foreach($implementations as $fid => $compareds_implementations) {
      foreach ($compareds_implementations as $cid => $implementation) {
        $commands[] = ajax_command_replace('#implementation_' . $implementation['data']->nid, wikicompare_table_render_implementation($implementation, array(), $settings));
      }
    }
  }


  if ($update_selected_features) {
    

/*
    $selected_feature_ids = array();
    foreach ($_POST['selected_feature_ids'] as $selected_feature_id) {
      $selected_feature_ids[$selected_feature_id[0]] = $selected_feature_id[0];
    }
*/
    $features = array('tree' => array());
    if ($_POST['selected_feature_ids']) {
      $features = wikicompare_build_recursive_data('feature', $_POST['selected_feature_ids']);
    }
    //Building the data for the item list
    $itemlist_data = wikicompare_build_itemlist('feature', $features['tree'], 0, array('computed' => 1));
    //Render the item list
    $output = theme_item_list(array('items' => $itemlist_data, 'title' => 'Manually selected features', 'type' => 'ul', 'attributes' => array()));
    $commands[] = ajax_command_html('#selected_feature_itemlist', $output);
  }

  

  //Preparing the ajax commands to return to javascript

  $commands[] = ajax_command_invoke('.form_fastaction', 'remove', array());


  //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
  $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;


}



function wikicompare_initialize_settings($args = array()) {

  $settings = array();

  foreach (array('fastaction', 'context', 'forbidden_nid', 'computed', 'states', 'colspan', 'can_be_translated') as $key) {

    if (isset($args[$key])) {
      $settings[$key] = $args[$key];
    } else {
      $result = 0;
      if ($key == 'context') {
        $result = 'table';
      } elseif ($key == 'states') {
        $result = array();
/*      } elseif ($key == 'can_be_translated') { // move can_be_translated in db_settings, 1 by default
        $result = 1;*/
      }
      $settings[$key] = $result;
    }

  }

  return $settings;
}


function wikicompare_generate_add_link($type, $settings) {

  $output = '<a id="add_' . $type . '_link" href="?q=node/add/' . $type . '">Add</a><span id="add_' . $type . '_link_fastaction">';
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
