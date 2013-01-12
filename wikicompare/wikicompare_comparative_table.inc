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
    );
  }

  //Building the data for the item list
  $compared_item_list_data = get_compared_item_list($compareds);


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
    );
  }

  //Building the data for the table
  $feature_rows = get_feature_rows($features);


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
      }

      //Building the data for the item list
      $compared_item_list_data = get_compared_item_list($compareds);

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
function get_compared_item_list($compareds){

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
        //After the compared, we add the div which will contain the children
        '#suffix' => '<div id="compared_children_' . $compared['nid'] . '"></div>'
      );
    } else {
      $title = $compared['title'];
    }

    //Before the compared, we add a checkbox which will, when checked, add the column for this compared in the comparative table.
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
        'class' => array('compared_checkbox_link'),
      )
//TODO Move the hide css style here instead of in the javascript
    );

    $compared_items[$compared['nid']]['id'] = 'compared_item_' . $compared['nid'];
    $compared_items[$compared['nid']]['data'] = $checkbox . ' ' . drupal_render($checkbox_link) . drupal_render($title);


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
      $query->condition("s.parent_feature_id", $fid);
      $result = $query->execute();

      //Prepare the array to use as argument for the table row building function.
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

      //We recover from javascript argument the id of the columns displayed in the table, to know the cell we have to add
      if (!empty($_POST['compared_ids'])) {
        //Recover the implementation needed for the cells
        $query = db_select('cache_implementation', 'i');
        $query->addField('i', 'nid', 'nid');
        $query->addField('i', 'compared_id', 'compared_id');
        $query->addField('ctc', 'percent', 'percent');
        $query->addField('ctc', 'css_class', 'css_class');
        $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
        $query->condition("i.compared_id", $_POST['compared_ids'], 'in');
        $query->condition("i.feature_id", $fid);
        $result = $query->execute();

        //Insert the implementations in an array with their compared as key so we can then add them in the feature array
        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->compared_id] = $record;
        }

        //Insert the implementations in the feature array, using the compared as key. Note that the compared order must be kept because it's the order of the column in the table
        foreach ($features as $key => $feature) {
          foreach ($_POST['compared_ids'] as $compared_id) {
            $features[$key]['implementations'][] = $implementations[$compared_id[0]];
          }
        }
      }

      //Building the data for the table row
      $feature_row_data = get_feature_rows($features);


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
      //We add the code after the parent row
      $commands[] = ajax_command_after('#feature_row_' . $fid, $output);
      $page = array('#type' => 'ajax', '#commands' => $commands);
  
      return $page;

    //If we want to collapse the feature children
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
 * Function which will build the features row. Used in table initial building and in feature ajax callback
 */
function get_feature_rows($features){

  $rows = array();
  foreach ($features as $feature){

    //If the feature has children, the feature name will become a link calling the callback function to display his children
    if ($feature['has_children'] == 1){
      $title = array(
        '#type' => 'link',
        '#title' => drupal_render($feature['title']),
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
    $rows[$feature['nid']]['data'][0] = '<td>' . drupal_render($title)  . '<br/> Weight : ' .  drupal_render($feature['weight']) . '<br/> Type : ' . $feature['type'] . '</td>';
    //Adding one cell for each implementation, which contain the details of the cells
    foreach ($feature['implementations'] as $implementation) {
      $rows[$feature['nid']]['data'][] = '<td class="' . $implementation->css_class . ' implementation_compared_' . $implementation->compared_id . ' implementation_feature_' . $feature['nid'] . '">' . $implementation->nid . '<br/>' . $implementation->percent . '%</td>';
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
      $header = '<th id="header_compared_' . $cid . '" class="header_compared" style="display:none;">' . $compared->title . '</th>';

      //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
      if (!empty($_POST['feature_ids'])) {
        //Recover the implementation needed for the cells
        $query = db_select('cache_implementation', 'i');
        $query->addField('i', 'nid', 'nid');
        $query->addField('i', 'feature_id', 'feature_id');
        $query->addField('ctc', 'percent', 'percent');
        $query->addField('ctc', 'css_class', 'css_class');
        $query->leftjoin('cache_comparative_table', 'ctc', 'i.nid = ctc.nid');
        $query->condition("i.compared_id", $cid);
        $query->condition("i.feature_id", $_POST['feature_ids'], 'in');
        $result = $query->execute();

        //Build the cells we have to add in each row.
        $implementations = array();
        foreach ($result as $record) {
          $implementations[$record->feature_id] = '<td class="' . $record->css_class . ' implementation_compared_' . $cid . ' implementation_feature_' . $record->feature_id . '" style="display:none;">' . $record->nid . '<br/>' . $record->percent . '%</td>';
        }
      }

      //Preparing the ajax commands to return to javascript
      $commands = array();
      //Add the new cell at the end of the header
      $commands[] = ajax_command_append('#comparative_table_header', $header);
      //Add the new cells at the end of each row
      foreach ($implementations as $key => $implementation) {
        $commands[] = ajax_command_append('#feature_row_' . $key, $implementation);
      }
      $page = array('#type' => 'ajax', '#commands' => $commands);
  
      return $page;

    //If we want to remove the column
    } elseif ($action == 'hide') {

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

?>
