<?php

//Define the message when a user didn't have the javascript activated.
define('NOJS_MESSAGE', "You need to activate javascript to use the comparative table.");
//Some constant dimensions used in the table.
define('ROW_HEIGHT', 100);
define('FIRST_COLUMN_WIDTH', 30);
require_once drupal_get_path('module', 'wikicompare') . '/wikicompare.module';



/**
 * Build the home page.
 */
function wikicompare_home_page() {

  //Add the javascript files used in the comparative_table.
  drupal_add_js('misc/ajax.js');
  drupal_add_js('misc/progress.js');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  /*
   * Left column.
   */
  $output = '<div id="sidebar-first" style="height:500px; float:left;">';

  //Generate the filter link which will be called each time we modify a filter. This mainly regenerate the product list.
  $filter_link = array(
    '#type' => 'link',
    '#title' => 'Filter',
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'filter_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'refresh_list',
      'mode' => 'filter',
      'style' => 'display:none',
    ),
  );
  $output .= render($filter_link);

  //The name filter is hardcoded.
  $name_filter = new stdClass;
  $name_filter->type = 'text';
  $name_filter->name = 'name';
  $name_filter->title = 'Name';
  $filters = array($name_filter);

  //Get all filters from infofields table.
  $query = db_select('wikicompare_infofields', 'f');
  $query->addField('f', 'name', 'name');
  $query->addField('f', 'title', 'title');
  $query->addField('f', 'type', 'type');
  $query->addField('f', 'filter_type', 'filter_type');
  $query->addField('f', 'allowed_values', 'allowed_values');
  $query->condition('f.is_filter', 1);
  $query->condition('f.is_active', 1);
  $query->orderby('f.sequence');
  $result = $query->execute();
  foreach ($result as $record) {
    $filters[] = $record;
  }

  //Render filter, depending of the type.
  foreach ($filters as $record) {
    $output .= '<p>';
    switch ($record->type) {
      case 'text':
        $filter = array(
          '#type' => 'textfield',
          '#id' => 'filter_' . $record->name,
          '#title' => $record->title,
          '#size' => 25,
          '#attributes' => array(
            'field' => $record->name,
            'class' => array('home_filter text'),
          )
        );
        $output .= render($filter);
        break;
      case 'number':
        $output .= '<div class="form-item">';
        $output .= '<label>' . $record->title . '</label>';
        $output .= '<input id="filter_min_' . $record->name . '" class="home_filter min number" type="text" size="5" field="' . $record->name . '">';
        $output .= ' - ';
        $output .= '<input id="filter_max_' . $record->name . '" class="home_filter max number" type="text" size="5" field="' . $record->name . '">';
        $output .= '</div>';
        break;
      //The select type can have two display filter, select or checkboxes.
      case 'select':
        switch ($record->filter_type) {
          case 'select':
            $output .= '<div class="form-item">';
            $output .= '<label>' . $record->title . '</label>';
            $output .= '<select id="filter_' . $record->name . '" class="home_filter" field="' . $record->name . '">';
            $output .= '<option></option>';
            foreach (explode("\n", $record->allowed_values) as $value) {
              $output .= '<option value="' . $value . '">' . $value . '</option>';
            }
            $output .= '</select>';
            $output .= '</div>';
            break;
          case 'checkboxes':
            $output .= '<div class="form-item">';
            $output .= '<label>' . $record->title . '</label>';
            foreach (explode("\n", $record->allowed_values) as $value) {
              $output .= '<input type="checkbox" id="filter_' . $record->name . '" class="home_filter" field="' . $record->name . '" value="' . $value . '"  />' . $value . '<br/>';
            }
            $output .= '</div>';
            break;
        }
    }

  }


  //Add the container which will contain the selected criterion itemlist. It'll be build when we submit the manual selected criterion dialog.
  $output .= '<div id="container-manual-selected-criterions"></div>';
  //Add the link to open the select criterion popup
  $select_criterion_link = array(
    'text' => 'Select criterions',
    'title' => 'Select criterions',
    'selector' => 'dialog-content',
    'path' => 'wikicompare_get_dialog_callback/multidialog/criterion/manual-selected-criterions/0/',//manual_selected_criterions/none',
    'id' => 'select_criterion_link',
  );
  //Render the link thanks to the simple dialog module. //TODO
//  $output .= '<p>' . theme('simple_dialog_link', $select_criterion_link) . '</p>';
  $select_criterion_link = array(
    '#type' => 'link',
    '#title' => 'Select criterions',
    '#href' => 'wikicompare_get_dialog_callback/nojs',
    '#id' => 'select_criterion_link',
    '#attributes' => array(
      'class' => array('dialog'),
      'action' => 'select_dialog',
      'side' => 'left',
      'ntype' => 'criterion',
      'context' => 'multidialog',
      'container' => 'manual-selected-criterions',
    ),
  );
  $output .= ' ' . render($select_criterion_link) . '</p>';

  if (module_exists('wikicompare_profiles')) {
    //Generate the main profile itemlist in the wikicompare table.
    wikicompare_profiles_comparative_table_main_output($output);
  }

  //Add the compute button.
  $compute_link = array(
    '#type' => 'link',
    '#title' => 'Compute',
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'compute_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'refresh_list',
      'mode' => 'compute',
      'style' => 'display:none',
    ),
  );
  $output .= '<p><input id="compute_table_button" type="submit" link="compute_table_link" value="Compute table" class="button wikicompare_button"/>' . render($compute_link);
  $output .= '<span id="computed" style="display:none;">0</span>';

  //Add the reset link.
  $reset_link = array(
    '#type' => 'link',
    '#title' => 'Reset table',
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'reset_table_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'refresh_list',
      'mode' => 'reset',
    ),
  );
  $output .= ' ' . render($reset_link) . '</p>';

  $output .= '</div>';



  /*
   * Central column.
   */
  $output .= '<div id="products_list_column" style="height:600px; width:400px; float:left;">';
  $settings = wikicompare_initialize_settings();

  //Get all infofields displayed on product list. The number of infofield here is limited.
  $settings['infofields'] = array();
  $query = db_select('wikicompare_infofields', 'f');
  $query->addField('f', 'name', 'name');
  $query->addField('f', 'title', 'title');
  $query->condition('f.is_home', 1);
  $query->condition('f.is_active', 1);
  $query->orderby('f.sequence');
  $query->orderby('f.title');
  $query->range(0, 4);
  $result = $query->execute();
  foreach ($result as $record) {
    $settings['infofields'][] = array(
      'name' => $record->name,
      'title' => $record->title
    );
  }

  $res = wikicompare_table_render_product_list($settings);

  $output .= '<span id="nb_products" style="display:none;">' . $res['count'] . '</span>';
  $output .= '<span id="products_offset" style="display:none;">' . $res['offset'] . '</span>';
  $best_products_link = array(
    '#type' => 'link',
    '#title' => 'Compare the three best',
    '#href' => $res['url'],
    '#id' => 'best_products_link',
  );
  $output .= '<p>' . render($best_products_link) . '</p>';
  $toogle_product_mode_link = array(
    '#type' => 'link',
    '#title' => 'Toogle product mode',
    '#href' => 'wikicompare_compute_table_callback/nojs',
    '#id' => 'toogle_product_mode_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'refresh_list',
      'mode' => 'toogle_product_mode',
    ),
  );
  $output .= '<p>' . render($toogle_product_mode_link) . '</p>';
  $output .= '<div id="products_list" style="height:500px; overflow:auto;">';
  //Generate product list with a table.
  $output .= '<table><thead>';
  $output .= '<th>Products</th>';
  $output .= '<th>Rank</th>';
  //Infofields header.
  foreach ($settings['infofields'] as $infofield) {
    $output .= '<th class="infofield_title" field="' . $infofield['name'] . '">' . $infofield['title'] . '</th>';
  }
  $output .= '</thead><tbody>';
  $output .= $res['output'];
  $output .= '</tbody></table>';
  $output .= '</div>';
  $append_link = array(
    '#type' => 'link',
    '#title' => 'Append product list',
    '#href' => 'wikicompare_get_append_product_list_callback/nojs',
    '#id' => 'append_product_list_link',
    '#attributes' => array(
      'class' => array('simple_ajaxlink'),
      'action' => 'append_product_list',
      'style' => 'display:none',
    ),
  );
  $output .= '<p><span id="products_tree_mode" style="display:none;">0</span>' . render($append_link) . '</p>';
  $output .= '</div>';



  /*
   * Right column.
   */
  $output .= '<div id="sidebar-second" style="height:500px; float:right;">';
  $output .= wikicompare_table_render_home_suggest();
//TODO temp
  $output .= wikicompare_table_render_footer();
  $output .= '<div id="storage_zone" style="display:none;">';
  $output .= '</div>';
  $output .= '</div>';

  return $output;

}



/**
 * Build the wikicompare comparative table.
 */
function wikicompare_comparative_table($root_criterion, $compared_products, $selected_criterions, $selected_profiles) {

  //Add the javascript files used in the comparative_table.
  drupal_add_js('misc/ajax.js');
  drupal_add_js('misc/progress.js');
  drupal_add_library('system', 'drupal.collapse');
  drupal_add_library('wikicompare', 'wikicompare_comparative_table');

  $product_ids = array();
  if ($compared_products != 0) {
    $compared_products = explode('-', $compared_products);
    foreach ($compared_products as $product_id) {
      $product_ids[$product_id] = $product_id;
    }
  }

  $selected_criterion_ids = array();
  if ($selected_criterions != 0) {
    $selected_criterions = explode('-', $selected_criterions);
    foreach ($selected_criterions as $criterion_id) {
      $selected_criterion_ids[$criterion_id] = $criterion_id;
    }
  }

//TODO move in profile module
  $selected_profile_ids = array();
  if ($selected_profiles != 0) {
    $selected_profiles = explode('-', $selected_profiles);
    foreach ($selected_profiles as $profile_id) {
      $selected_profile_ids[$profile_id] = $profile_id;
    }
  }

  $computed = 0;
  if (!empty($selected_criterion_ids) || !empty($selected_profile_ids)) {
    $computed = 1;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings(array('product_column_ids' => $product_ids, 'selected_criterion_ids' => $selected_criterion_ids, 'selected_profile_ids' => $selected_profile_ids, 'computed' => $computed));

  //Get all active infofields.
  $settings['infofields'] = array();
  $query = db_select('wikicompare_infofields', 'f');
  $query->addField('f', 'name', 'name');
  $query->addField('f', 'title', 'title');
  $query->addField('f', 'category', 'category');
  $query->condition('f.is_active', 1);
  $query->orderby('f.category_sequence');
  $query->orderby('f.category');
  $query->orderby('f.sequence');
  $query->orderby('f.title');
  $result = $query->execute();
  foreach ($result as $record) {
    $settings['infofields'][] = array(
      'name' => $record->name,
      'title' => $record->title,
      'category' => $record->category
    );
  }

  $products = array();
  if (!empty($product_ids)) {
    //Get the products data for the header of the table.
    $products = request_db('product', array('nids' => $product_ids, 'get_infofields' => 1), $settings);
  }

  //Generate the main product itemlist.
  $settings['displayed_ids'] = $settings['product_column_ids'];
  $output = wikicompare_table_render_main_itemlist('product', 'Products', $settings);

  //Generate the comparative table.
  $output .= wikicompare_table_render_comparative_table($settings, $products);

  //Render the fieldset with the infofield, collapsed at the loading page.
  $fieldset = '<table><tbody>';
  $category = '';
  $settings['width'] = (100 - FIRST_COLUMN_WIDTH) / count($product_ids);
  foreach ($settings['infofields'] as $infofield) {
    //Render the row with the category.
    if ($infofield['category'] != $category) {
      $fieldset .= '<tr><td class="row_auto_colspan" colspan="' . (1 + count($product_ids)) . '">' . $infofield['category'] . '</td></tr>';
      $category = $infofield['category'];
    }
    //Render the infofield row.
    $fieldset .= '<tr id="infofield_row_' . $infofield['name'] . '"><td class="infofield_title" style="width:' . FIRST_COLUMN_WIDTH . '%;" field="' . $infofield['name'] . '">' . $infofield['title'] . '</td>';
    //Render the infofield cells.
    foreach ($product_ids as $product_id) {
      $fieldset .= wikicompare_table_render_infofield($products[$product_id], $infofield, $settings);
    }
    $fieldset .= '</tr>';
  }
  $fieldset .= '</tbody></table>';

  //Render fieldset.
  $output .= theme_fieldset(array('element' => array('#title' => 'More details...', '#children' => $fieldset, '#collapsible' => true, '#collapsed'  => true, '#attributes' => array('class' => array('collapsible', 'collapsed')))));

  //TODO temp
  $output .= wikicompare_table_render_footer();

  //Return the html code.
  return $output;

}



/**
 * Build the wikicompare footer.
 */
function wikicompare_table_render_footer() {

  $output = '';

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

  //Add the link to go on FastAction mode.
  $toogle_link = array(
    '#type' => 'link',
    '#title' => 'Toogle FastAction',
    '#href' => 'toogle_fastaction_callback/nojs',
    '#id' => 'toogle_fastaction_link',
  );
  //Fastaction is only available for authenticated users.
  if (user_is_anonymous() != True) {
    $output .= '<p>' . render($toogle_link) . '</p>';
  }


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
//TODO change table keyword for context into main

  $settings['include_root_items'] = True;

  //Find all nodes which are displayed or in the root of the itemlist, and organize them into a tree.
  $nodes = wikicompare_build_recursive_data($type, $settings['displayed_ids'], $settings);
  $nodes = $nodes['tree'];

//TODO move into profile module
  if (module_exists('wikicompare_profiles')) {
    if ($type == 'profile' && $settings['context'] == 'table') {
      $settings['itemlist_translate'] = True;
    }
//    wikicompare_profiles_table_prepare_compute($selected_criterion_ids, $settings);
  }

  $output ="<div id='comparative_table_main_" . $type . "'>";

  $output .= '<h3>' . $title . '</h3>';

  if (isset($settings['itemlist_translate'])) {
    $output .= '<div id="main_' . $type . '_itemlist_container" style="overflow:hidden;">'; //TODO not sure we still need this container.
    //The container which contain the tables, and will slide to display them.
    $output .= '<div id="main_' . $type . '_itemlists" style="height: ' . count($nodes) * ROW_HEIGHT . 'px; position:relative; -webkit-transition:all 1.0s ease-in-out; -moz-transition:all 1.0s ease-in-out; -o-transition:all 1.0s ease-in-out;   transition:all 1.0s ease-in-out;">';
    $output .= '<div id="itemlist_stored_0"  style="float:left; position:absolute; top: 0; left:' . $settings['depth'] * ROW_HEIGHT . '%; width:100%;">';
  }

  //Building the data for the itemlist.
  $output .= wikicompare_build_itemlist($type, $nodes, 0, $settings);

  if (isset($settings['itemlist_translate'])) {
    $output .= '</div>';
    $output .= '</div>';
    $output .= '</div>';
  }

  //Render the link to add a new node.
  $output .= '<p>' . wikicompare_generate_add_link($type, $settings) . '</p>';
  //We need to add the 0 children div to know where place the fastaction form.
  $output .= '<div id="' . $type . '_table_children_0"></div>';
  $output .="</div>";

  //Return itemlist.
  return $output;

}



/**
 * Generate the product list, ordered by their percentages.
 *
 * @param criterions
 *   If specified, the list will be computed with the specified criterions.
 *
 * @param settings
 *   The context of the table.
 *
 * @return output
 *   The rendered list.
 */
function wikicompare_table_render_product_list($settings, $criterions=array(), $offset=1) {

  //Only the product in the home page will be rendered by this function.
  $settings['context'] = 'list';

  //If we are loading the list in standard mode.
  $db_settings = array('get_infofields' => 1);
  //If we are expanding the children of a node in tree mode.
  $parent_id = 0;
  if (isset($settings['nid'])) {
    $db_settings['parent_id'] = $settings['nid'];
    $parent_id = $settings['nid'];
  } else {
    $db_settings['get_comparable_products'] = 1;
  }

  //Assign filters to request from context.
  if (isset($settings['filters'])) {
    $db_settings['filters'] = $settings['filters'];
  }

  //Recover comparable products.
  $products = request_db('product', $db_settings, $settings);

  $product_ids = array();
  foreach ($products as $product_id => $product) {
    $product_ids[$product_id] = $product_id;
  }

  //If we are in tree mode, we need to get the product in tree mode. Unless we are getting the children of a node.
  if ($settings['products_tree_mode'] && !isset($settings['nid'])) {
    //Get product tree. We can use comparable products as base because it always contain at least all products without children.
    $products_recursive_data = wikicompare_build_recursive_tree('product', $product_ids, array(), $settings);
    $product_ids = $products_recursive_data['ids'];
    $products = $products_recursive_data['data'];
  }

  $evaluations = array();
  $products_sort = array();
  //If we are computing percentage.
  if ($settings['computed']) {
    if (!empty($criterions['ids']) && !empty($product_ids)) {
      //Get the needed evaluation thanks to criterion and product ids.
      $evaluations = request_db('evaluation', array('criterion_ids' => $criterions['ids'], 'product_ids' => $product_ids), $settings);
    }

    //Build recursively the criterions data and compute them if necessary.
    $criterions_row_data = wikicompare_build_rows_data($criterions['tree'], $product_ids, $evaluations, $settings);

    foreach ($products as $product_id => $product) {
      $node = new stdClass;
      $node->type = 'parent-weighted-average';
      $evaluations = array();

      foreach ($criterions_row_data as $criterion_id => $criterion_row_data) {
        if (isset($criterion_row_data['root'])) {
          $evaluations[$criterion_id] = $criterion_row_data['evaluations'][$product_id]['data'];
        }
      }

      $node = wikicompare_compute_percent($node, $evaluations);

      $products_sort[$product_id] = $node->new_percent;
    }
  //Assign percentage from cache_compared total field.
  } else {
    foreach ($products as $product_id => $product) {
      $products_sort[$product_id] = $product['data']->total;
    }
  }

  //Order the products by their percentages.
  if (!$settings['products_tree_mode']) {
    arsort($products_sort);
  }

  //For tree mode, now that we recovered the percentage, we assign the products in tree mode before the call of the recursive function.
  if ($settings['products_tree_mode'] && !isset($settings['nid'])) {
    $products = $products_recursive_data['tree'];
  }

  $limit = 5 + $offset;

  //Generate items.
  $output = wikicompare_table_render_product_item($products, $products_sort, $parent_id, $offset, $limit, True, $settings);

  //Generate the best products url.
  $url = 'compare/0';
  $is_products = True;
  //Generate the three argument products/criterions/profiles.
  foreach (array($products_sort, $settings['selected_criterion_ids'], $settings['selected_profile_ids']) as $array) { //TODO move profile_ids in module
    $i = 0;
    $first = True;
    $ids_url = 0;
    //Add each id, separated by a -.
    foreach ($array as $id => $node) {
      if (!$first) {
        $ids_url .= '-' . $id;
      } else {
        $ids_url = $id;
      }
      $first = false;
      $i++;
      //We limit the product passed to the comparative table.
      if ($i == 3 && $is_products) {
        break;
      }
    }
    $url .= '/' . $ids_url;
    //The products are first and the only ones to be limited to three, so we use this variable as flag to recognize them.
    $is_products = False;
  }

  return array('offset' => $limit, 'count' => count($products), 'url' => $url, 'output' => $output);

}



/**
 * Render the product items in the list.
 *
 * @param products
 *   The products ressources, in tree if in tree mode and computed.
 *
 * @param products_sort
 *   Array containing the percentage computed for each product.
 *
 * @param parent_id
 *   When recursive call, use this value for the parent_id attribute.
 *
 * @param offset
 *   Indicate where we are in the list, the previous value should not be loaded.
 *
 * @param limit
 *   Indicate the number of item we should load.
 *
 * @param first
 *   Indicate if we are at the first call of the recursive function.
 *
 * @param settings
 *   The context of the table.
 *
 * @return output
 *   The rendered list.
 */
function wikicompare_table_render_product_item($products, $products_sort, $parent_id, $offset, $limit, $first, $settings) {

  $output = '';
  $i = 0;
  foreach ($products_sort as $product_id => $percent) {
    //Important mainly in computed tree mode, if the product is not at the current level of the recursive function then we zap it with no effect on the iterator.
    if (isset($products[$product_id])) {
      $product = $products[$product_id];
    } else {
      continue;
    }
    $i++;
    //Zap all products already loaded.
    if ($i < $offset) {
      continue;
    }
    //In standard mode, zap all products superior to the limit.
    if ($i == $limit && !$settings['products_tree_mode'] && !$settings['computed']) {
      break;
    }
    //Unless we are in tree mode, we will not display the get children link for the product node.
    if (!$settings['products_tree_mode']) {
      $settings['no_children_link'] = 1;
    }

    $output .= '<tr id="product_list_item_' . $product_id . '" class="product_list_item"';
    //In computed tree mode (the only mode which can have first = false), we hide the item if not at the root level or if we are displaying a children.
    if (!$first || isset($settings['nid'])) {
      $output .= ' style="display:none;"';
    }
    //In computed tree mode, we link the children to their parent with this attribute.
    if ($parent_id) {
      $output .= ' parent_id="' . $parent_id . '"';
    }
    $output .= '>';
    //Render product name.
    $output .= '<td>' . wikicompare_table_get_supertitle_item('product', $product, $settings) . '<br/><br/><br/><br/><br/><br/><br/><br/></td>';
    //Render percentage.
    $output .= '<td>' . $products_sort[$product_id] . '%</td>';
    //Render infofields.
    foreach ($settings['infofields'] as $infofield) {
      $field = 'wikicf_' . $infofield['name'];

      $output .= '<td>';
      //Avoid value = 0;
      if ($product['data']->$field) {
        $output .= $product['data']->$field;
      }
      $output .= '</td>';
    }
    $output .= '</tr>';
    //Recursive call to get the children.
    if ($settings['computed'] && !empty($product['children'])) {
      $output .= wikicompare_table_render_product_item($product['children'], $products_sort, $product_id, $offset, $limit, False, $settings);
    }
  }

  return $output;

}



/**
 * Render the product suggestion on home page, based on selected criterions.
 *
 * @return $output
 *   The rendered suggests.
 */
function wikicompare_table_render_home_suggest() {

  $res = array();
  $query = db_select('cache_wikicompare_suggest', 'n');
  $query->addField('n', 'criterion_id', 'criterion_id');
  $query->addField('n', 'sequence', 'sequence');
  $query->addField('n', 'product_id', 'product_id');
  $query->addField('n', 'percent', 'percent');
  $query->addField('c', 'title', 'criterion_title');
  $query->addField('p', 'title', 'product_title');
  $query->leftjoin('cache_criterion', 'c', 'n.criterion_id = c.nid');
  $query->leftjoin('cache_product', 'p', 'n.product_id = p.nid');
  $query->orderby('n.sequence, n.criterion_id');
  $query->orderby('n.percent', 'DESC');
  $result = $query->execute();
//TODO Translate title
  foreach($result as $record) {
    $res[$record->criterion_id][$record->product_id] = $record;
  }

  $output = '';
  foreach ($res as $criterion) {
    $first = True;
    foreach ($criterion as $product) {
      if ($first) {
        $output .= '<p>' . $product->criterion_title . '<br/>';
        $first = False;
      }
      $output .= $product->product_title . ' : ' . $product->percent . '%<br/>';
    }
  }

  return $output;

}



/**
 * Get the criterions ids from settings.
 *
 * @param settings
 *   The context of the table.
 *
 * @return $output
 *   The rendered table.
 */
function wikicompare_compute_get_criterions($settings) {
//TODO Maybe we can merge this function directly with render comparative table
  //Get the criterions we will use to compute the table.
  $selected_criterion_ids = array();
  if ($settings['computed']) {

    $selected_criterion_ids = $settings['selected_criterion_ids'];

    if (module_exists('wikicompare_profiles')) {
      //Add the criterions of the selected profiles.
      wikicompare_profiles_table_prepare_compute($selected_criterion_ids, $settings);
    }

  }
/*
  if (module_exists('wikicompare_profiles')) { TODO no need anymore
    //Add commmand to reset the profile part of the table.
    wikicompare_profiles_table_send_compute($commands, $settings);
  }*/

  $criterions = array();
  //Compute the table, unless no criterions was selected. In this case, we just reset it.
  if ($selected_criterion_ids && $settings['computed']) {
    //Build the criterion tree.
    $criterions = wikicompare_build_recursive_data('criterion', $selected_criterion_ids, $settings);
  }

  return $criterions;

}



/**
 * Generate the comparative table. This function is called by the initial function of the comparative table, by the compute and reset function and by the cleaning function if some important changes was made.
 *
 * @param settings
 *   The context of the table.
 *
 * @param criterions
 *   If specified, the table will be computed with the specified criterions.
 *
 * @param product_ids
 *   The table will immediately add the specified product as column.
 *
 * @return $output
 *   The rendered table.
 */
function wikicompare_table_render_comparative_table($settings, $products=array()){

  //Only the main table will be rendered by this function.
  $settings['context'] = 'table';

  //Get criterions.
  $criterions = wikicompare_compute_get_criterions($settings);
  $product_ids = $settings['product_column_ids'];

  if (empty($criterions)) {
    //Find all the criterions on the first level of the tree.
    $criterions['tree'] = request_db('criterion', array('parent_id' => NULL), $settings);
    //Get the criterion ids.
    foreach ($criterions['tree'] as $fid => $criterion) {
      $criterions['ids'][$fid] = $fid;
    }
  }

  //Get the needed evaluation thanks to criterion and product ids.
  $evaluations = array();
  //I though about move this security in the request itself, but it would add an unnecessary db request in many cases.
  if (!empty($criterions['ids']) && !empty($product_ids)) {
    //Get the needed evaluation thanks to criterion and product ids.
    $evaluations = request_db('evaluation', array('criterion_ids' => $criterions['ids'], 'product_ids' => $product_ids), $settings);
  }

  //Build recursively the criterions data and compute them if necessary.
  $criterions_row_data = wikicompare_build_rows_data($criterions['tree'], $product_ids, $evaluations, $settings);

  $output = '<div id="comparative_table">';
  //Set the computed flag.
  $output .= '<span id="computed" style="display:none;">' . $settings['computed'] . '</span>';
  //Set the breadcrumb zone.
  $output .= '<div id="breadcrumb_zone" style="height: 25px;"></div>';
  //Set the header zone.
  $output .= '<table id="table_header"><thead>';
  //Build header.
  $output .= '<tr id="comparative_table_header">';
  $output .= '<th style="width: ' . FIRST_COLUMN_WIDTH . '%;">' . t('Criterions') . '</th>';
  //Get the columns width.
  $settings['width'] = (100 - FIRST_COLUMN_WIDTH) / count($products);
  foreach ($products as $cid => $product) {
    $output .= '<th id="header_product_' . $cid . '" class="header_product" style="width: ' . $settings['width'] . '%; padding: 0; text-align: center; -webkit-transition: width 1s ease-in-out; -moz-transition: width 1s ease-in-out; -o-transition: width 1s ease-in-out; transition: width 1s ease-in-out;"><div class="width_div_' . $cid . '"><span class="product_title_' . $cid . '">' . $product['data']->title . '</span></div></th>';
  }
  $output .= '</tr>';
  $output .= '</thead>';
  $output .= '</table>';
  //Get rows.
  $rows = wikicompare_table_render_rows($criterions_row_data, $settings);

  $root_row = $rows['root'];
  $storage_zone_content = '';
  //Get all the needed tables.
  if ($settings['computed']) {
    unset($rows['root']);
    foreach ($rows as $parent_id => $row) {
      $storage_zone_content .= $row['output'];
      //If some of the children table have a greater size that the root table, so we can adjust the height.
      if ($root_row['count'] < $row['count']) {
        $root_row['count'] = $row['count'];
      }
    }
  }

  $output .= '<div id="comparative_tables_container" style="overflow:hidden;">'; //TODO not sure we still need this container.
  //The container which contain the tables, and will slide to display them.
  $output .= '<div id="comparative_tables" style="height: ' . $root_row['count'] * ROW_HEIGHT . 'px; position:relative; -webkit-transition:all 1.0s ease-in-out; -moz-transition:all 1.0s ease-in-out; -o-transition:all 1.0s ease-in-out;   transition:all 1.0s ease-in-out;">';
  //Display the root rows.
  $output .= $root_row['output'];
  $output .= '</div>';
  $output .= '</div>';

  //Add an small table for the add link.
  $output .= '<table>';
  $output .= '<tbody>';
  $output .= '<tr id="criterion_table_0"><td class="row_auto_colspan" ';
  if (isset($settings['colspan'])) {
    $output .= 'colspan="' . $settings['colspan'] . '"';
  }
  $output .= '>';
  $output .= wikicompare_generate_add_link('criterion', $settings);
//TODO it's probably best to display them out of a table. Check on generate_add_link if there is not tr in it.
  $output .= '</td><tr>';
  $output .= '</tbody>';
  $output .= '</table>';
  $output .= '</div>';

  //Add the storage zone where we will store the tables. Of course, this zone is hidden.
  $output .= '<div id="storage_zone" style="display:none;">';
  $output .= $storage_zone_content;
  $output .= '</div>';

  //Return the table.
  return $output;

}



/**
 * Render the rows for the comparative table. This function is called by the render comparative table function and by the criterion add children ajax call.
 *
 * @param $criterions_row_data
 *   The consolidated data of the row, which contains the criterions in tree and their evaluation.
 *
 * @param $settings
 *   The context of the rows.
 *
 * @return $output
 *   The rendered rows.
 */
function wikicompare_table_render_rows($criterions_row_data, $settings) {

  $res = array();

  //Add a row for each criterions.
  foreach ($criterions_row_data as $fid => $criterion) {

    //We need to add the id as class because this id is used for two items when we add a new columns with a computed table.
    $output = '<tr id="criterion_table_'. $fid . '" class="criterion_row criterion_table_'. $fid;

    //If the criterion has parent, we add it in the class to find them later. Thanks to this class, we can for exemple easily remove the children of a node.
    if ($criterion['data']->parent_id) {
        $output .= ' criterion_table_child_' . $criterion['data']->parent_id;
    }
    //If the criterion has children, we add this class to easily know that this criterion can display children.
    if ($criterion['data']->has_children){
      $output .= ' has_children';
    }
    $output .= '" height="100px">';
//TODO set all height et width attribute in style, because it's better for the transition.

    //Generate the main details of the criterion in the first cell.
    $output .= '<td style="width: ' . FIRST_COLUMN_WIDTH . '%;">' . wikicompare_table_get_supertitle_item('criterion', $criterion, $settings) . '</td>';

    //Add a column for each product.
    foreach ($criterion['evaluations'] as $cid => $evaluation) {
      //Render evaluation.
      $output .= wikicompare_table_render_evaluation($evaluation, $criterion, $cid, $settings);
    }

    $output .= '</tr>';

    //Assign each rows with root of parent_id as keys.
    $key = 'root';
    if (isset($criterion['data']->parent_id)) {
      $key = $criterion['data']->parent_id;
    }

    //Initiate the table for each key, if not already done.
    if (!isset($res[$key])) {
      $res[$key]['output'] = '<table id="comparative_table_';
      //Except for root, each tables will be insert in the storage zone.
      if ($key != 'root') {
        $res[$key]['output'] .= 'stored_' . $key;
      } else {
        $res[$key]['output'] .= 0;
      }
      $res[$key]['output'] .= '" style="float:left; position:absolute; top: 0; left:' . $settings['depth'] * ROW_HEIGHT . '%;"><tbody>';
      $res[$key]['count'] = 0;
    }

    //Append the row in the table.
    $res[$key]['output'] .= $output;
    //We count the number of rows to later find the height of the table.
    $res[$key]['count'] += 1;

  }

  //Close each tables.
  foreach ($res as $key => $output) {
    $res[$key]['output'] .= '</tbody></table>';
  }

  //Return the rendered row.
  return $res;

}



/**
 * Render the evaluation. This fucntion is used in render row function and in the add product column ajax call.
 *
 * @param $evaluation
 *   The evaluation to render.
 *
 * @param criterion
 *   The detail of the criterion of the evaluation.
 *
 * @param $settings
 *   The context of the evaluation.
 *
 * @return $output
 *   The rendered evaluation.
 */
function wikicompare_table_render_evaluation($evaluation, $criterion, $cid, $settings) {

  $output = '<td';
  $css_class = '';
  if (isset($evaluation['data']->nid)) {
    $output .= ' id="evaluation_' . $evaluation['data']->nid . '"';
    $css_class = 'evaluation_cell ' . $evaluation['data']->css_class;
  }
  $output .= ' class="' . $css_class . ' evaluation_product_' . $cid . ' evaluation_criterion_' . $criterion['data']->nid . '" style="width: ' . $settings['width'] . '%; padding: 0; text-align: center; -webkit-transition: width 1s ease-in-out; -moz-transition: width 1s ease-in-out; -o-transition: width 1s ease-in-out; transition: width 1s ease-in-out;"><div class="width_div_' . $cid . '"';

  //If we are adding a new column with ajax call, we need to hide it to prevent animation crashing.
  if ($settings['width'] == 0) {
    $output .= ' style="display: none;"';
  }
  $output .= '>';

  //We hide the evaluation for all non-published criterion, to more easily distinct them from the published ones.
  if (in_array($criterion['data']->state, unserialize(WIKICOMPARE_STATE_PUBLISHED)) || $criterion == NULL) {
    //Render the evaluation.
    $output .= wikicompare_table_get_supertitle_item('evaluation', $evaluation, $settings);
  }
  $output .= '</div></td>';

  return $output;
}



/**
 * Render the infofield. This fucntion is used in initial table render and when we add a new column.
 *
 * @param $product
 *   The product to render.
 *
 * @param infofield
 *   The infofield to render.
 *
 * @param $settings
 *   The context of the infofield.
 *
 * @return $output
 *   The rendered infofield.
 */
function wikicompare_table_render_infofield($product, $infofield, $settings) {

  $field = 'wikicf_' . $infofield['name'];
  $output = '<td class="infofield_product_' . $product['data']->nid .' infofield_product"  style="width:' . $settings['width'] . '%; padding: 0; text-align: center; -webkit-transition: width 1s ease-in-out; -moz-transition: width 1s ease-in-out; -o-transition: width 1s ease-in-out; transition: width 1s ease-in-out;"><div class="width_div_' . $product['data']->nid . '"';

  //If we are adding a new column with ajax call, we need to hide it to prevent animation crashing.
  if ($settings['width'] == 0) {
    $output .= ' style="display: none;"';
  }
  $output .= '>';

  //Avoid display if data == 0.
  if ($product['data']->$field) {
    $output .= $product['data']->$field;
  }
  $output .= '</div></td>';

  return $output;

}



/*
 * Render the supertitle of an item. This part is separate from the rest of the render function because we have to be able to call this in cleaning function, to for exemple change a simple title into a link if a node get children.
 * This function is call by all item function, itemlist, criterion rows and evaluations.
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

  if ($type != 'evaluation') {

    //Get the title of the item, which can be a translated title.
    $title = '<span class="' . $type . '_title_' . $node['data']->nid . '">' . $node['data']->title . '</span>';

    //Specify the most used ajax call to display children.
    $url = 'wikicompare_get_itemlist_children_callback/nojs/';

    //Specific case of the table criterions.
    if ($type == 'criterion' && $settings['context'] == 'table') {
      //The ajax call is not the same.
      $url = 'wikicompare_get_criterion_children_callback/nojs/';
      //Creating the first cell of the row, containing the criterion details.
      $suffix .= '<br/> Weight : <span class="' . $type . '_weight_' . $node['data']->nid . '">' .  $node['data']->weight . '</span>';
      //We display the type only for the parent criterion, no interest in case of only children criterions.
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

          //Prepare for the check of comparable field. We can't do it directly in the if because comparable field isn't always set.
          $comparable_flag = True;
          if ($settings['context'] == 'table' && $type == 'product') {
            if ($node['data']->comparable != 'always-combine') {
              $comparable_flag = False;
            }
          }

          //We display a checkbox only if the node has children, or for product table if we activated the option.
          if ($node['data']->has_children != 1 || ($settings['context'] == 'table' && $type == 'product' && $comparable_flag)) {

            //Generate checkbox.
            $checkbox_settings = array('element' => array(
              '#title' => $node['data']->nid,
              '#id' => $type . '_' . $settings['context'] . '_checkbox_' . $node['data']->nid,
              '#attributes' => array(
                'class' => array('itemlist_checkbox'),
                'ntype' => $type,
                'context' => $settings['context'],
                'nid' => $node['data']->nid,
                'parent_id' => $settings['parent_id'],
              ),
            ));
            //We check it immediately if it was check before (a product which already has his column in table, a criterion present in the global array in javascript etc...
            if (isset($settings['displayed_ids']) && in_array($node['data']->nid, $settings['displayed_ids'])) { //TODO replace everywhere isset($node['data']->displayed)) {
              $checkbox_settings['element']['#checked'] = True;
            }

            $prefix .= theme_checkbox($checkbox_settings) . ' ';

            //Add the ajax link which will add the column in table.
            if ($type == 'product' && $settings['context'] == 'table') {
              $checkbox_link = array(
                '#type' => 'link',
                '#title' => 'toggle',
                '#href' => 'wikicompare_toogle_product_checkbox_callback/nojs/',
                '#id' => 'product_checkbox_link_' . $node['data']->nid,
                '#attributes' => array(
                  'class' => array('simple_ajaxlink'),
                  'action' => 'toogle_product_checkbox',
                  'style' => 'display:none',
                )
              );
              if (isset($settings['displayed_ids']) && in_array($node['data']->nid, $settings['displayed_ids'])) {
                $checkbox_link['#attributes']['class'][] = 'displayed';
              }
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
    if ($node['data']->has_children && !isset($settings['no_children_link'])){
      $class = array();
      //In the comparative table, the children display isn't managed by the same javascript code than the others cases.
      if (!($type == 'criterion' && $settings['context'] == 'table')) {
        $class[] = 'item_link';
      }
      //The computed flag is only used for criterion in comparative table, in criterion dialog itemlist on in product list.
      if ($settings['computed'] && ($type == 'criterion' || ($type == 'product' && $settings['context'] == 'list'))) {
        $class[] = 'computed';
      }
      //Indicate if the itemlist must display his children with translation.
      if (isset($settings['itemlist_translate'])) {
        $class[] = 'translate';
      }
      //This class is used to prepare the variable for the cleaning function.
      if ($settings['context'] == 'table') {
        $class[] = $type . '_table_link';
      }
      //Replace the title by the link.
      $title = l($title, $url,  array('attributes' => array('id' => $type . '_' . $settings['context'] . '_link_' . $node['data']->nid, 'class' => $class, 'ntype' => $type, 'context' => $settings['context'], 'nid' => $node['data']->nid, 'parent_id' => $node['data']->parent_id), 'html' => True));
    }

  } else {
    //An evaluation has no title, we simply display his percentage.
    $title = $node['data']->percent . '%';
  }

  //For all list or table items, we add a link to access the node page and add a div to store the fastaction items.
  if (in_array($settings['context'], array('table', 'list'))) {

    //Create the image link to go to the node page
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to ' . $type . ' ') . $node['data']->nid,
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

  $output = '<ul>';
  //Add each node in the returned array.
  foreach ($nodes as $nid => $node){
    $output .= '<li id="' . $type . '_' . $settings['context'] . '_item_' .  $nid . '" class ="' . $type . '_item';
    if ($node['data']->has_children){
      $output .= ' has_children';
    }
    //If a node has children on initialization or is himself in displayed_ids, then it means he had checked children.
    if (!empty($node['children']) || in_array($nid, $settings['displayed_ids'])) {
      $output .= ' has_checked_children';
    }
    $output .= '" ntype="' . $type . '" context="' . $settings['context'] . '" nid="' . $nid . '" parent_id="' . $parent_node .'"';
    if ($parent_node != 0) {
      //If the itemlist is computed, all children are hidden.
      if ($settings['computed']) {
        $output .= ' style="display:none"';
      }
    }
    $output .= '>';

    //Name of the item.
    $settings['parent_id'] = $parent_node;
    $output .= wikicompare_table_get_supertitle_item($type, $node, $settings);

    //Set the checked zone.
    $output .= '<div id="' . $type . '_' . $settings['context'] . '_children_checked_' . $nid . '" class="'. $type . '_children">';
    //Get the children.
    $output .= wikicompare_build_itemlist($type, $node['children'], $nid, $settings);
    $output .= '</div>';
    //Set the children zone.
    $output .= '<div id="' . $type . '_' . $settings['context'] . '_children_' . $nid . '" class="'. $type . '_children" style="display:none;">';
    $output .= '</div>';
    $output .= '</li>';
  }

  $output .= '</ul>';

  //Display an error message if we try to build an itemlist without data yet.
/* TODO set the message outside of the function  if (empty($nodes)) {
    $output = "<p>There is no data yet.</p>";
  }*/

  return $output;

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

  //Build the recursive tree.
  $res = wikicompare_build_recursive_tree($type, $node_ids, array(), $settings);
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

  //Get the details of the specified nodes. No other way here but to put this query in recursive function. Some improvement for later may be to use the WITH RECURSIVE function of postgresql.
  $db_settings = array('nids' => $node_ids);
  if (isset($settings['include_root_items']) && !isset($settings['not_first'])) {
    $db_settings['parent_id'] = NULL;
  }
  if (isset($settings['infofields'])) {
    $db_settings['get_infofields'] = 1;
  }
  $nodes = request_db($type, $db_settings, $settings);

  $parent_ids = array();
  foreach ($nodes as $nid => $node) {

    //If the parent was already set on the tree by a child on a different level
    if (isset($res['tree'][$nid])) {
      $node['children'] = $res['tree'][$nid]['children'] + $node['children'];
    }

    //Check if some children of this node launched the recursive function to find this node as their parent. Then assign them as children of this node and unset the node in the array.
    if (isset($res['parent_ressource'][$nid]['children'])) {
      //Note that parent_ressource is prioritary before $res['tree'] so we insert it after. Also, we can't use operator +.
      foreach ($res['parent_ressource'][$nid]['children'] as $child_id => $child) {
        $node['children'][$child_id] = $child;
      }
      unset($res['parent_ressource'][$nid]);
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
  if (!empty($parent_ids)){
    $settings['not_first'] = True;
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
 * Function which will build the criterions row, assign the evaluations and compute the percent if we are in compute mode. Used in render comparative table and in criterion ajax callback.
 *
 * @param $criterions_tree
 *   The criterion tree previously build by recursive function.
 *
 * @param $product_ids
 *   The nids of the product nodes displayed in the table, so we can assign the evaluations to each rows.
 *
 * @param $evaluations
 *   The evaluations details we previously extracted from database.
 *
 * @param $settings
 *   The context of the build.
 *
 * @return $rows
 *   The prepared rows ready to be rendered.
 */
function wikicompare_build_rows_data($criterions_tree, $product_ids, $evaluations, $settings){

  $rows = array();

  foreach ($criterions_tree as $fid => $criterion){

    //Add the criterion in the rows.
    $rows[$fid] = $criterion;

    //We need to set this flag, otherwise the parent will have no way to recover his true children since they will be all at the same level.
    if ($criterion['data']->parent_id) {
      $rows[$fid]['direct-child'] = True;
    //We set another flag if we are at the top of the tree.
    } else {
      $rows[$fid]['root'] = True;
    }

    //Launch the recursive function if we are computing the table and the criterion have children.
    $children = array();
    if ($criterion['children']) {
      $children = wikicompare_build_rows_data($criterion['children'], $product_ids, $evaluations, $settings);
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

    //Assign evaluation to each rows, following the displayed products.
    $rows[$fid]['evaluations'] = array();
    foreach ($product_ids as $cid) {

      //Get evaluation detail, thanks to criterion and product id.
      if (isset($evaluations[$fid][$cid])) {
        $evaluation = $evaluations[$fid][$cid];
      } else {
        $evaluation = array('data' => new stdClass);
      }

      //If the table is computed, then we will not use the percent in cache_evaluation but compute it with the specified criterions.
      if ($settings['computed']) {

        //The type of the criterion which will be used in the wikicompare_compute_percent function
        $evaluation['data']->type = $criterion['data']->type;
        //The weight of the criterion which will be used in the parent wikicompare_compute_percent function
        $evaluation['data']->weight = $criterion['data']->weight;

        //Get all children evaluation on the criterion axis (same product id).
        $through_criterion_childs = array();
        foreach ($direct_children as $child) {
          $child_evaluation = $child['evaluations'][$cid]['data'];
          $through_criterion_childs[$child_evaluation->criterion_id] = $child_evaluation;
        }

        //Get the evaluation percent by calling the same function than the one used in update_compare_tree.
        if (!empty($through_criterion_childs)) {
          $evaluation['data']->new_percent = 0;
          $evaluation['data']->new_css_class = 'cell-support-no';
          $evaluation['data'] = wikicompare_compute_percent($evaluation['data'], $through_criterion_childs);
          //Update percent and css_class for parent computation and render, new_percent and new_css_class are only used in the core_function file.
          $evaluation['data']->percent = $evaluation['data']->new_percent;
          $evaluation['data']->css_class = $evaluation['data']->new_css_class;
        }

      }

      //Assign the evaluation to the row.
      $rows[$fid]['evaluations'][$cid] = $evaluation;

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

    //If a product table is already displayed in the table, we check it by default.
    if ($_POST['type'] == 'product' && $settings['context'] == 'table') {
      $settings['displayed_ids'] = $settings['product_column_ids'];
    }

    //If a multidialog criterion is already checked in javascript global variable, we check it by default.
    if ($_POST['type'] == 'criterion' && $settings['context'] == 'multidialog') {
      $settings['displayed_ids'] = $settings['selected_criterion_ids'];
    }

    if (module_exists('wikicompare_profiles')) {
      //Auto check the already selected profiles in main table.
      wikicompare_profiles_table_prepare_itemlist($settings);
    }

    //Get the children, with the parent nid.
    $nodes = request_db($_POST['type'], array('parent_id' => $_POST['nid']),  $settings);

    if ($settings['context'] != 'list') {

      $output = '';

      if (isset($_POST['translate'])) {
        $output .= '<div id="itemlist_stored_' . $_POST['nid'] . '"  style="float:left; position:absolute; top: 0; left:' . $settings['depth'] * ROW_HEIGHT . '%; width:100%;>';
      }

      //Rendering the itemlist.
      $output .= wikicompare_build_itemlist($_POST['type'], $nodes, $_POST['nid'], $settings);

      if (isset($_POST['translate'])) {
        $output .= '</div>';
      }

      if (!isset($_POST['translate'])) {
        //We prepared a div under the parent product. This command will fill it with the product children, and replace anything that was here before.
        $commands[] = ajax_command_html('#'. $_POST['type'] . '_' . $settings['context'] . '_children_' . $_POST['nid'], $output);
        //We mark the children zone as stored. Next time, no ajax call will be made.
        $commands[] = ajax_command_invoke('#'. $_POST['type'] . '_' . $settings['context'] . '_children_' . $_POST['nid'], 'addClass', array('stored'));
      } else {
        //We add the new table in the storage zone, then javascript will copy it after the displayed table. Note we can't use ajax_command_append because it adds an unwanted div.
        $commands[] = ajax_command_invoke('#storage_zone', 'append', array($output));
      }
    } else {

      $settings['nid'] = $_POST['nid'];
      $res = wikicompare_table_render_product_list($settings);

      //We add the new items after the parent item. Note we can't use ajax_command_after because it adds an unwanted div.
      $commands[] = ajax_command_invoke('#product_list_item_' . $_POST['nid'], 'after', array($res['output']));

    }

  }

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript to recover the criterion children of the clicked criterion in the table.
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
function wikicompare_get_criterion_children_response($method = 'ajax') {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $commands = array();

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  //We are adding a new depth in the table.
  $settings['depth'] = $settings['depth'] + 1;

  //Get the children, with the parent nid.
  $criterions = request_db('criterion', array('parent_id' => $_POST['nid']), $settings);

  //Extract criterion_ids to use it as argument to get the evaluations.
  $criterion_ids = array();
  foreach ($criterions as $fid => $criterion) {
    $criterion_ids[$fid] = $fid;
  }

  //Get parent data to get his title.
  $parents = request_db('criterion', array('nids' => array($_POST['nid'])), $settings);
  $title = '';
  foreach ($parents as $fid => $parent) {
    $title = $parent['data']->title;
  }

  //Recover the evaluations needed for the cells, thanks to product and criterion ids.
  $evaluations = array();
  if (!empty($settings['product_column_ids'])) {
    $evaluations = request_db('evaluation', array('product_ids' => $settings['product_column_ids'], 'criterion_ids' => $criterion_ids), $settings);
  }

  //Prepare the criterions data for rendering.
  $criterion_row_data = wikicompare_build_rows_data($criterions, $settings['product_column_ids'], $evaluations, $settings);

  //We need to get the current width for the new rows.
  $settings['width'] = (100 - FIRST_COLUMN_WIDTH) / count($settings['product_column_ids']);

  //Render the criterions.
  $rows = wikicompare_table_render_rows($criterion_row_data, $settings);

  //If the new table has more height than the current one, we augment it.
  $new_height = $rows[$_POST['nid']]['count'] * ROW_HEIGHT;
  if ($settings['table_height'] < $new_height) {
    $commands[] = ajax_command_invoke('#comparative_tables', 'height', array($new_height));
  }

  //We add the new table in the storage zone, then javascript will copy it after the displayed table. Note we can't use ajax_command_append because it adds an unwanted div.
  $commands[] = ajax_command_invoke('#storage_zone', 'append', array($rows[$_POST['nid']]['output']));

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript to append the product list.
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
function wikicompare_get_append_product_list_response($method = 'ajax') {

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  $commands = array();
  $res = wikicompare_table_render_product_list($settings, array(), $_POST['products_offset']);
  $commands[] = ajax_command_invoke('#products_list tbody', 'append', array($res['output']));
  $commands[] = ajax_command_invoke('#products_offset', 'html', array($res['offset']));

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
function wikicompare_toggle_product_checkbox_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $commands = array();

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  //For the accordeon animation, we need to first initialize the column width to 0;
  $settings['width'] = 0;

  //Recover the detail of the product we want to add, by searching with his nid.
  $product = request_db('product', array('nids' => array($_POST['nid']), 'get_infofields' => 1), $settings);

  //Add the header of the new column, with the product title.
  $header = '<th id="header_product_' . $_POST['nid'] . '" class="header_product" style="width: 0%; padding: 0; text-align: center; -webkit-transition: width 1s ease-in-out; -moz-transition: width 1s ease-in-out; -o-transition: width 1s ease-in-out; transition: width 1s ease-in-out;"><div class="width_div_' . $_POST['nid'] . '" style="display: none;"><span class="product_title_' . $_POST['nid'] . '">' . $product[$_POST['nid']]['data']->title . '</span></div></th>';
  //Add the new cell at the end of the header.
  $commands[] = ajax_command_append('#comparative_table_header', $header);

  //We recover from javascript argument the id of the row displayed in the table, to know the cell we have to add
  if (!empty($_POST['criterion_ids'])) {

    //Get the criterions details, by searching with their nids.
    $criterions = request_db('criterion', array('nids' => $_POST['criterion_ids']), $settings);

    //Recover the evaluations needed for the cells.
    $evaluations = request_db('evaluation', array('product_ids' => array($_POST['nid']), 'criterion_ids' => $_POST['criterion_ids']), $settings);

    //If the table was computed, then we need to compute the evaluation of the product, with the displayed criterions.
    if ($settings['computed']) {

      //We will use only the criterion without childre for the computation.
      $criterions_without_children = array();
      foreach ($criterions as $fid => $criterion) {
        if (!$criterion['data']->has_children) {
          $criterions_without_children[$fid] = $fid;
        }
      }

      //Build the whole criterions tree.
      $criterions = wikicompare_build_recursive_data('criterion', $criterions_without_children, $settings);
      $criterions = $criterions['tree'];

    }

    //Finally prepare the criterions and evaluations for rendering if necessary compute the evaluation percent.
    $criterions = wikicompare_build_rows_data($criterions, array($_POST['nid']), $evaluations, $settings);

    $cells = array();
    foreach ($criterions as $fid => $criterion) {
      //Get evaluation details.
      $evaluation = $criterion['evaluations'][$_POST['nid']];
      //Render the cell.
      $cells[$fid] = wikicompare_table_render_evaluation($evaluation, $criterion, $_POST['nid'], $settings);
    }

    //Add the new cells at the end of each row.
    foreach ($cells as $fid => $cell) {
      $commands[] = ajax_command_append('.criterion_table_' . $fid, $cell);
    }

    //Add the new infofields in the bottom fieldset table.
    foreach ($settings['infofields'] as $infofield) {
      $commands[] = ajax_command_append('#infofield_row_' . $infofield['name'], wikicompare_table_render_infofield($product[$_POST['nid']], $infofield, $settings));
    }

  }

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function to display a dialog in the page.
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
function wikicompare_get_dialog_response($method = 'ajax'){
//function wikicompare_get_dialog_response($context, $type, $container, $nid){ TODO
  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //In the option of the simple dialog, we need to provide an anchor which indicate the content to display in the popin.
//  $output = t("<div id='dialog-content'>");

  //Initialize settings with the context. We also display all states to ensure we have access to all nodes in the popin.
  $settings = wikicompare_initialize_settings($_POST);

  //Indicate if on submit we must update selected_criterion_ids or manual_selected_criterion_ids in the javascript global variable.
  $output .= '<div id="initialize_selected_criterion_dialog_ids" style="display:none;">';
  if ($settings['container'] == 'manual-selected-criterions') {
    $output .= 'manual';
  } else {
   $output .= 'form';
  }
  $output .= '</div>';

  //Indicate the type of the nodes displayed in the popin.
  $output .= '<div id="dialog_type" style="display:none;">' . $settings['type'] . '</div>';

  //Indicate the container to update when we submit the popin.
  $output .= '<div id="select_container" style="display:none;">' . $settings['container'] . '</div>';

  //If there is a forbiden_id, we indicate it so the javascript can recover him in his ajax call.
  if ($settings['nid'] != 0) {
    $output .= '<div id="forbidden_nid" style="display:none;">' . $settings['nid'] . '</div>';
    //We also add it in settings for the itemlist we will build in this function.
    $settings['forbidden_nid'] = $settings['nid'];
  }

  //Find all the nodes on the first level of the tree.
  $nodes = request_db($settings['type'], array('parent_id' => NULL), $settings);

  //Building the data for the itemlist.
  $itemlist_data = wikicompare_build_itemlist($settings['type'], $nodes, 0, $settings);

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

//  $output .= t("</div>");
  $commands = array();
  $commands[] = ajax_command_append('#' . $_POST['side'] . '_dialog', $output);

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

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
  if ($_POST['container'] == 'manual_selected_criterions') {
    $settings['context'] = 'manual';
  }

  //Prepare the data with the tree by calling the recursive function.
  $criterions = array('data' => array());
  if ($settings['selected_criterion_ids']) {
    $criterions = wikicompare_build_recursive_data('criterion', $settings['selected_criterion_ids'], $settings);
  }

  //Building the data for the itemlist.
  $itemlist_data = wikicompare_build_itemlist('criterion', $criterions['tree'], 0, $settings);

  //Render the itemlist.
  $output = theme_item_list(array('items' => $itemlist_data, 'title' => 'Selected criterions', 'type' => 'ul', 'attributes' => array()));

  //In form, generate the drupal field many2many so drupal can find it on submit.
  $hidden = '<tbody>';
  $i = 0;
  foreach ($criterions['data'] as $criterion) {
    //We remove the criterion if it's a parent criterion. This case can happen if we add the criterion to the profile when it has no children, and then it become a parent.
    if (!$criterion['data']->has_children) {
      $hidden .= '<tr><td>
      <input type="text" size="60" value="&quot;' . $criterion['data']->title . ' (' . $criterion['data']->nid . ')&quot;" name="wikicompare_criterions[und][' . $i . '][target_id]">
      </td></tr>';
      $i += 1;
    }
  }
  //Add an empty field, in case the many2many is empty. If we don't do it, drupal will not empty the field on submit.
  $hidden .= '<tr><td>
    <input type="text" size="60" value="" name="wikicompare_criterions[und][' . $i . '][target_id]" >
    </td></tr>
    </tbody>';

  //Add the value for the fastaction form.
  $hidden_fastaction = '';
  foreach ($settings['selected_criterion_ids'] as $criterion_id) {
    $hidden_fastaction .= '<div class="profile_criterion">' . $criterion_id . '</div>';
  }

  $commands = array();
  //Display the itemlist in the container.
  $commands[] = ajax_command_html('#container-' . $_POST['container'], $output);
  //Update the drupal field in form.
  $commands[] = ajax_command_html('#wikicompare-criterions-values', $hidden);
  //Update the fastedit field for fastedit submit.
  $commands[] = ajax_command_html('#wikicompare-criterions', $hidden_fastaction);

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}


//TODO rename into refresh list
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

  //Reset the product part of the table.
  $commands[] = ajax_command_replace('#comparative_table_main_product', wikicompare_table_render_main_itemlist('product', 'Products', $settings));

  //Replace the old table.
  $commands[] = ajax_command_replace('#comparative_table', wikicompare_table_render_comparative_table($settings));

  //Regenerate the product list.
  $criterions = wikicompare_compute_get_criterions($settings);
  $res = wikicompare_table_render_product_list($settings, $criterions);
  $commands[] = ajax_command_html('#nb_products', $res['count']);
  $commands[] = ajax_command_html('#products_offset', $res['offset']);
  $commands[] = ajax_command_invoke('#best_products_link', 'attr', array('href', $res['url']));
  $commands[] = ajax_command_invoke('#products_list tbody', 'html', array($res['output']));

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
  $update_selected_criterions = false;

  //Execute for all wikicompare node type, except evaluation.
  $types = array('product', 'criterion');
  if (module_exists('wikicompare_profiles')) {
    //Add profile type.
    wikicompare_profiles_node_types($types);
  }

  $criterions = array();
  foreach ($types as $type) {

    //We must not touch anything on a computed table.
    if ($type == 'criterion' && $settings['computed']) {
      continue;
    }

    //Security for the TYPE_ids, it's an array but javascript return a string when empty.
    if ($_POST[$type . '_ids'] == '') {
      $_POST[$type . '_ids'] = array();
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
      //We need to keep the criterions details for the part with the evaluations.
      if ($type == 'criterion') {
        $criterions = $nodes;
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

          if ($type == 'criterion') {
            //In the case of a criterion, it means there is a structural change so better refresh the manual_selected_criterion itemlist.
            $update_selected_criterions = true;
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
        case 'product':
          $commands[] = ajax_command_replace('#comparative_table_main_product', wikicompare_table_render_main_itemlist('product', 'Products', $settings));
          break;
        case 'criterion':
          $commands[] = ajax_command_replace('#comparative_table', wikicompare_table_render_comparative_table($settings, array(), $_POST['product_column_ids']));
          break;
      }

    }

    if (module_exists('wikicompare_profiles')) {
      //Add commmand to reset the profile part of the table.
      wikicompare_profiles_table_clean_reset($commands, $type, $reset, $settings);
    }

    //Reset all fields displayed in the table. All field are in a span to easily refresh them.
    foreach($nodes as $nid => $node) {
      $commands[] = ajax_command_invoke('.' . $type . '_title_' . $nid, 'html', array($node['data']->title));
      if ($type == 'criterion') {
        $commands[] = ajax_command_invoke('.criterion_title_' . $nid, 'html', array($node['data']->title));
        $commands[] = ajax_command_invoke('.criterion_weight_' . $nid, 'html', array($node['data']->weight));
        $commands[] = ajax_command_invoke('.criterion_type_' . $nid, 'html', array($node['data']->type));
        $commands[] = ajax_command_invoke('.criterion_state_' . $nid, 'html', array($node['data']->state));
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

  //We refresh the evaluations only if the table wasn't computed.
  if (!$_POST['computed']) {

    //Extract criterion_ids.
    $criterion_ids = array();
    foreach ($_POST['criterion_ids'] as $criterion) {
      $criterion_ids[$criterion['nid']] = $criterion['nid'];
    }

    //Get evaluations details.
    $evaluations = array();
    if (!empty($settings['product_column_ids']) && !empty($criterion_ids)) {
      $evaluations = request_db('evaluation', array('product_ids' => $settings['product_column_ids'], 'criterion_ids' => $criterion_ids), $settings);
    }

    //Rerender all the evaluations displayed in the table.
    foreach($evaluations as $fid => $products_evaluations) {
      foreach ($products_evaluations as $cid => $evaluation) {
        $commands[] = ajax_command_replace('#evaluation_' . $evaluation['data']->nid, wikicompare_table_render_evaluation($evaluation, $criterions[$evaluation['data']->criterion_id], $cid, $settings));
      }
    }

  }

  //If during the tests, we asked for a reset of the selected criterions itemlist.
  if ($update_selected_criterions) {
    $criterions = array('tree' => array());
    if ($settings['selected_criterion_ids']) {
      $criterions = wikicompare_build_recursive_data('criterion', $settings['selected_criterion_ids']);
    }
    //Building the data for the itemlist.
    $itemlist_data = wikicompare_build_itemlist('criterion', $criterions['tree'], 0, array('computed' => 1));
    //Render the itemlist.
    $output = theme_item_list(array('items' => $itemlist_data, 'title' => 'Manually selected criterions', 'type' => 'ul', 'attributes' => array()));
    $commands[] = ajax_command_html('#container-manual-selected-criterions', $output);
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
//TODO move selected_profile_ids in module.
  $settings = $args;
  foreach (array('fastaction', 'context', 'product_column_ids', 'selected_criterion_ids', 'selected_profile_ids', 'forbidden_nid', 'depth', 'computed', 'products_tree_mode', 'states', 'colspan') as $key) {

    //If the key is already set in the argument of the function, we directly use it.
    if (isset($args[$key])) {
      $settings[$key] = $args[$key];

      //Security for some fields coming from javascript, they are array but javascript return a string when empty.
      if (in_array($key, array('product_column_ids', 'selected_criterion_ids')) && $args[$key] == '') {
        $settings[$key] = array();
      }

    //Else we set 0 as default value, except for some specific key.
    } else {
      $result = 0;
      if ($key == 'context') {
        $result = 'table';
      } elseif (in_array($key, array('product_column_ids', 'selected_criterion_ids', 'selected_profile_ids', 'states'))) {
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
