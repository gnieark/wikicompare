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
  $query->addField('f', 'has_children', 'has_children');
  $query->condition('f.parent_feature_id', NULL);
  $query->condition('f.state', 'Published', '=');
  $features = $query->execute();

  //Insert the feature in the form array to retrieve them in the theme
  foreach ($features as $item) {
    $form['feature_items'][$item->nid] = array(
      'title' => array(
        '#markup' => check_plain($item->title),
      ),
      'weight' => array(
        '#markup' => check_plain($item->weight),
      ),
    );
    $form['feature_items'][$item->nid]['#id'] = $item->nid;
    $form['feature_items'][$item->nid]['#type'] = $item->type;
    $form['feature_items'][$item->nid]['#has_children'] = $item->has_children;
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
      'no-edit' => False,
    );
  }

  //Building the data for the item list
  $compared_item_list_data = get_compared_item_list($compareds, 0);


  //Render the item list
  $output = theme_item_list(array('items' => $compared_item_list_data, 'title' => 'Compared', 'type' => 'ul', 'attributes' => array()));


  //Prepare the array to use as argument for the table row building function.
  $features = array();
  //element_children is used to avoid the children beginning by # which are inserted by drupal in $form
  foreach (element_children($form['feature_items']) as $fid) {
    $features[$fid] = array(
      'nid' => $fid,
      'title' => $form['feature_items'][$fid]['title'],
      'weight' => $form['feature_items'][$fid]['weight'],
      'type' => $form['feature_items'][$fid]['#type'],
      'has_children' => $form['feature_items'][$fid]['#has_children'],
      'implementations' => array(),
      'no-edit' => False,
    );
  }
//TODO retirer les no-edit initiaux car on fait un check en !isset
  //Building the data for the table
  $feature_rows = get_feature_rows($features, 0);


  //Prepare the header of the table. As this point we have no compared column displayed so only the first column with the feature will be displayed
  $header = array(t('Features'));

  //Building the table
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
  }
  $output .= '</tbody>';
  $output .= '</table>';

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
function get_compared_ajax_response($type = 'ajax', $cid, $action) {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the compared children
    if ($action == 'expand') {

      //Recover the children from database
      $query = db_select('cache_compared', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->addField('s', 'has_children', 'has_children');
      $query->addField('r', 'uid', 'uid');
      $query->leftjoin('node_revision', 'r', 's.nid = r.nid');
      $query->condition("s.parent_compared_id", $cid);
      $result = $query->execute();

      //Prepare the array to use as argument for the item list building function
      $compareds = array();
      foreach ($result as $record) {
        $compareds[$record->nid] = array(
          'nid' => $record->nid,
          'title' => array(
            '#markup' => check_plain($record->title),
          ),
          'has_children' => $record->has_children,
        );
        //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
        if ($GLOBALS['user']->uid != $record->uid) {
          $compareds[$record->nid]['no-edit'] = True;
        }
      }
      $fastedit_toggled = 0;
      if (!empty($_POST['fastedit_toggled'])) {
        $fastedit_toggled = $_POST['fastedit_toggled'];
      }
      //Building the data for the item list
      $compared_item_list_data = get_compared_item_list($compareds, $fastedit_toggled);
      //Rendering the item list
      $output = theme_item_list(array('items' => $compared_item_list_data, 'type' => 'ul', 'attributes' => array()));
      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We prepared a div under the parent compared. This command will fill it with the compared children, and replace anything that was here before.
      $commands[] = ajax_command_html('#compared_children_' . $cid, $output);
      $page = array('#type' => 'ajax', '#commands' => $commands);

      return $page;

    //If we want to collapse the compared children
    } elseif ($action == 'collapse') {

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
 * Function which will build the compared item list. Used in table initial building and in compared ajax callback
 */
function get_compared_item_list($compareds, $fastedit_toggled){

  $compared_items = array();
  foreach ($compareds as $compared){

    //If the compared has children, the compared name will become a link calling the callback function to display his children
    if ($compared['has_children'] == 1){
      $title = array(
        '#type' => 'link',
        '#title' => drupal_render($compared['title']),
        //The callback link, /nojs is automatically replace for /ajax by drupal. The second and third argument indicate the compared_id for recovering his children and if we have to display or hide them
        '#href' => 'get_compared_ajax_callback/nojs/' . $compared['nid'] . '/expand',
        '#id' => 'compared_link_' . $compared['nid'],
        '#attributes' => array(
          'class' => array('compared_link'),
        ),
      );
    } else {
      $title = $compared['title'];
    }

    //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table. Unless we configure the system to compute the compared parent, only the compared with no children will have a checkbox.
    $checkbox_area = '';
    if ((variable_get('wikicompare_update_compared', 'no-update') != 'no-update') || ($compared['has_children'] != 1)) {
      $checkbox = theme_checkbox(array('element' => array(
        '#title' => $compared['nid'],
        '#id' => 'compared_checkbox_' . $compared['nid'],
        '#attributes' => array(
          'class' => array('compared_checkbox'),
        ),
      )));

      //We were not able to ajaxify the checkbox, so intead the checkbox will call this hidden link
      $checkbox_link = array(
        '#type' => 'link',
        '#title' => 'toggle',
        //The link for the callback function which will display or hide the column in the table
        '#href' => 'toogle_compared_checkbox_ajax_callback/nojs/' . $compared['nid'] . '/show',
        '#id' => 'compared_checkbox_link_' . $compared['nid'],
        '#attributes' => array(
          'class' => array('compared_checkbox_link', 'hidden'),
          'style' => 'display:none',
        )
      );
      $checkbox_area = $checkbox . ' ' . drupal_render($checkbox_link);
    }

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to compared ') . $compared['nid'],
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $compared['nid'], array('attributes' => array('id' => 'compared_node_link_' . $compared['nid'], 'class' => array('compared_node_link')), 'html' => True));

    if ($fastedit_toggled == 1) {
      $img_link_to_node .= add_fastedit_items('compared', $compared);
    }
    
    $compared_items[$compared['nid']]['id'] = 'compared_item_' . $compared['nid'];
    $compared_items[$compared['nid']]['data'] = $checkbox_area . drupal_render($title) . ' ' . $img_link_to_node;
    $compared_items[$compared['nid']]['class'] = array('compared_item');

    //After the compared, we add the div which will contain the children
    $compared_items[$compared['nid']]['data'] = $compared_items[$compared['nid']]['data'] . '<div id="compared_children_' . $compared['nid'] . '"></div>';


  }

  return $compared_items;

}


/*
 * Ajax callback cunction called by javascript to recover the feature children of the clicked feature
 */
function get_feature_ajax_response($type = 'ajax', $fid, $action) {
  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the compared children
    if ($action == 'expand') {

      //Recover the children from database
      $query = db_select('cache_feature', 's');
      $query->addField('s', 'nid', 'nid');
      $query->addField('s', 'title', 'title');
      $query->addField('s', 'weight', 'weight');
      $query->addField('s', 'type', 'type');
      $query->addField('s', 'has_children', 'has_children');
      $query->addField('r', 'uid', 'uid');
      $query->leftjoin('node_revision', 'r', 's.nid = r.nid');
      $query->condition("s.parent_feature_id", $fid);
      $result = $query->execute();

      //Prepare the array to use as argument for the table row building function.
      $features = array();
      $features_ids = array();
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
        $features_ids[$record->nid] = $record->nid;
        //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
        if ($GLOBALS['user']->uid != $record->uid) {
          $features[$record->nid]['no-edit'] = True;
        }
      }
      //We recover from javascript argument the id of the columns displayed in the table, to know the cell we have to add
      if (!empty($_POST['compared_ids'])) {
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
        $query->condition("i.compared_id", $_POST['compared_ids'], 'in');
        $query->condition("i.feature_id", $features_ids, 'in');
        $result = $query->execute();

        //Insert the implementations in an array with their compared as key so we can then add them in the feature array
        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->feature_id][$record->compared_id]['nid'] = $record->nid;
          $implementations[$record->feature_id][$record->compared_id]['feature_id'] = $record->feature_id;
          $implementations[$record->feature_id][$record->compared_id]['compared_id'] = $record->compared_id;
          $implementations[$record->feature_id][$record->compared_id]['percent'] = $record->percent;
          $implementations[$record->feature_id][$record->compared_id]['css_class'] = $record->css_class;
          //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $implementations[$record->feature_id][$record->compared_id]['no-edit'] = True;
          }
        }
        //Insert the implementations in the feature array, using the compared as key. Note that the compared order must be kept because it's the order of the column in the table
dpm($_POST['compared_ids']);
        foreach ($features as $key => $feature) {
          foreach ($_POST['compared_ids'] as $compared_id) {

            $features[$key]['implementations'][] = $implementations[$key][$compared_id[0]];
          }
        }
dpm($features);        
      }
      $fastedit_toggled = 0;
      if (!empty($_POST['fastedit_toggled'])) {
        $fastedit_toggled = $_POST['fastedit_toggled'];
      }
      //Building the data for the table row
      $feature_row_data = get_feature_rows($features, $fastedit_toggled);

      $output = '';
      //Add a row for each feature children
      foreach ($feature_row_data as $feature) {
        $output .= '<tr id="'. $feature['id'] . '" class="feature_row feature_children_' . $fid . '" style="display:none;">';
        //Add a column for each column in the table
        foreach ($feature['data'] as $data) {
          $output .= $data;
        }
        $output .= '</tr>';
      }

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //We add the code after the parent row. Note we can't use ajax_command_after because it adds an unwilling div
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
 * Function which will build the features row. Used in table initial building and in feature ajax callback
 */
function get_feature_rows($features, $fastedit_toggled){

  $rows = array();
  foreach ($features as $feature){

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to feature ') . $feature['nid'],
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_node = l($img, 'node/' . $feature['nid'], array('attributes' => array('id' => 'feature_node_link_' . $feature['nid'], 'class' => array('feature_node_link')), 'html' => True));
    if ($fastedit_toggled == 1) {
      $img_link_to_node .= add_fastedit_items('feature', $feature); 
    }

    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($feature['has_children'] == 1){
      $title = array(
        '#type' => 'link',
        '#title' => drupal_render($feature['title']) . ' ' . $feature['nid'],
        //The callback link, /nojs is automatically replace for /ajax by drupal. The second and third argument indicate the feature_id for recovering his children and if we have to display or hide them
        '#href' => 'get_feature_ajax_callback/nojs/' . $feature['nid'] . '/expand',
        '#id' => 'feature_link_' . $feature['nid'],
        '#attributes' => array(
          'class' => array('feature_link'),
        ),
      );
    } else {
      $title = $feature['title'];
    }
    $rows[$feature['nid']]['id'] = 'feature_row_' . $feature['nid'];
    //Creating the first cell of the row, containing the feature details
    $rows[$feature['nid']]['data'][0] = '<td>' . drupal_render($title) . ' ' . $img_link_to_node  . '<br/> Weight : ' .  drupal_render($feature['weight']) . '<br/> Type : ' . $feature['type'] . '</td>';
    //Adding one cell for each implementation, which contain the details of the cells
    foreach ($feature['implementations'] as $implementation) {
      //Create the image link to go to the node page
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to implementation ') . $implementation['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_node = l($img, 'node/' . $implementation['nid'],  array('attributes' => array('id' => 'implementation_node_link_' . $implementation['nid'], 'class' => array('implementation_node_link')), 'html' => True));
      if ($fastedit_toggled == 1) {
        $img_link_to_node .= add_fastedit_items('implementation', $implementation); 
      }

      $rows[$feature['nid']]['data'][] = '<td id="implementation_' . $implementation['nid'] . '" class="implementation_cell ' . $implementation['css_class'] . ' implementation_compared_' . $implementation['compared_id'] . ' implementation_feature_' . $feature['nid'] . '">' . $implementation['nid'] . ' ' .  $img_link_to_node . '<br/>Feature : ' . $implementation['feature_id'] . '<br/>Compared : ' . $implementation['compared_id'] . '<br/>' . $implementation['percent'] . '%</td>';

    }

  }

  return $rows;

}


/*
 * Ajax callback cunction called by javascript to add or remove a column in the comparative table
 */
function toggle_compared_checkbox_ajax_response($type='ajax', $cid, $action){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the compared children
    if ($action == 'show') {

      //Recover fastedit status
      $fastedit_toggled = 0;
      if (!empty($_POST['fastedit_toggled'])) {
        $fastedit_toggled = $_POST['fastedit_toggled'];
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
          $implementations[$record->nid]['nid'] = $record->nid;
          $implementations[$record->nid]['feature_id'] = $record->feature_id;
          $implementations[$record->nid]['percent'] = $record->percent;
          $implementations[$record->nid]['css_class'] = $record->css_class;
          //For fastedit, If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $implementations[$record->nid]['no-edit'] = True;
          }
        }
        
        $cells = array();
        foreach ($implementations as $implementation) {
          //Create the image link to go to the node page
          $img = theme('image', array(
            'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
            'alt' => t('Link to implementation ') . $implementation['nid'],
            'height' => '100%',
          ));
          //Create the link. The html = True indicate that the title of the link contain html.
          $img_link_to_node = l($img, 'node/' . $implementation['nid'], array('attributes' => array('id' => 'implementation_node_link_' . $implementation['nid'], 'class' => array('implementation_node_link')), 'html' => True));
          if ($fastedit_toggled == 1) {
            $img_link_to_node .= add_fastedit_items('implementation', $implementation); 
          }
          $cells[$implementation['feature_id']] = '<td id="implementation_' . $implementation['nid'] . '" class="implementation_cell ' . $implementation['css_class'] . ' implementation_compared_' . $cid . ' implementation_feature_' . $implementation['feature_id'] . '" style="display:none;">' . $implementation['nid'] . ' ' . $img_link_to_node . '<br/>Feature : ' . $implementation['feature_id'] . '<br/>Compared : ' . $cid . '<br/>' . $implementation['percent'] . '%</td>';
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

//TODO remove all info about dummy

/*
 * Ajax callback function called by javascript to add or remove the fastedit items in the comparative table. Essentially a dummy function.
 */
function toggle_fastedit_response($type='ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($type == 'ajax') {

    //If we want to displayed the fastedit items
    if ($_POST['action'] == 'show') {

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
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwilling div
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
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwilling div
        $commands[] = ajax_command_invoke('#feature_node_link_' . $feature['nid'], 'after', array($output));
        //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
        $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

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
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwilling div
        $commands[] = ajax_command_invoke('#implementation_node_link_' . $implementation['nid'], 'after', array($output));
        //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
        $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

      }
//TODO il faut surement sortir les commande dummy to remove des boucle et en mettre juste une � la fin
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

  if ($type == 'implementation') {
    $output = '';
    if (!isset($node['no-edit'])) {   
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'node/' . $node['nid'], array('attributes' => array('id' => $type . '_edit_link_' . $node['nid'], 'class' => array($type . '_edit_link')), 'html' => True));
      $output = $img_link_to_edit;
    }
  
  } else {
    //Create the image link to add a new children
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to add children ') . $type . ' ' . $node['nid'],
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_add = l($img, 'node/' . $node['nid'], array('attributes' => array('id' => $type . '_add_link_' . $node['nid'], 'class' => array($type . '_add_link')), 'html' => True));
    $output = $img_link_to_add;

    if (!isset($node['no-edit'])) {
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'node/' . $node['nid'], array('attributes' => array('id' => $type . '_edit_link_' . $node['nid'], 'class' => array($type . '_edit_link')), 'html' => True));
      $output .= $img_link_to_edit;

      //Create the image link to remove the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to remove ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_remove = l($img, 'node/' . $node['nid'], array('attributes' => array('id' => $type . '_remove_link_' . $node['nid'], 'class' => array($type . '_remove_link')), 'html' => True));
      $output .= $img_link_to_remove;
    }
  }

  return $output;

}

?>