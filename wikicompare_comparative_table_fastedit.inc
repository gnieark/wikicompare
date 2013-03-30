<?php




/*
 * Ajax callback function called by javascript to add or remove the fastedit items in the comparative table.
 */
function toggle_fastedit_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //If we want to displayed the fastedit items
    if ($_POST['fastedit_status'] == false) {

      $compareds = array();
      if (!empty($_POST['compared_ids'])) {

        $compareds = request_db('compared', 1, 'nids', $_POST['compared_ids']);

      }

      $commands = array();
      foreach($compareds as $nid => $compared) {

        $output = add_fastedit_items('compared' , $compared);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#compared_node_link_' . $nid, 'after', array($output));
        //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
        $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

      }


      $features = array();
      if (!empty($_POST['feature_ids'])) {


        $features = request_db('feature', 1, 'nids', $_POST['feature_ids']);

      }

      foreach($features as $nid =>$feature) {

        $output = add_fastedit_items('feature', $feature);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#feature_node_link_' . $nid, 'after', array($output));

      }
      
      $implementations = array();
      if (!empty($_POST['implementation_ids'])) {
dpm($_POST, 'postpost');
/*
        $query = db_select('node_revision', 'r');
        $query->addField('r', 'nid', 'nid');
        $query->addField('r', 'uid', 'uid');
        $query->condition('r.nid', $_POST['implementation_ids'], 'in');
        $result = $query->execute();
*/
        $implementations = request_db('implementation', 1, 'nids', $_POST['implementation_ids']);

/*        foreach ($result as $record) {
          $implementations[$record->nid]['nid'] = $record->nid;
          //If the node was created by or have some revision from other users, current user will not be able to edit it
          if ($GLOBALS['user']->uid != $record->uid) {
            $implementations[$record->nid]['no-edit'] = True;
          }
        }
*/

        foreach($implementations as $nid => $implementation) {
dpm($implementation);

          $output = add_fastedit_items('implementation', $implementation);
          //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
          $commands[] = ajax_command_invoke('#implementation_node_link_' . $nid, 'after', array($output));

        }

      }

      

      //Allow others modules to modify the output
      foreach (module_implements('wikicompare_comparative_table_toogle_fastedit') as $module) {
        $function = $module . '_wikicompare_comparative_table_toogle_fastedit';
        $function($commands, $_POST);
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

function add_fastedit_items($type, $node_array){

  $output = ' ';

  $nid = $node_array['data']->nid;
  
  if ($type == 'implementation') {
    
    if (!isset($node_array['no-edit'])) {   
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $node['nid'],
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $nid, 'class' => array('fastedit_item ' . $type . '_edit_link')), 'html' => True));
      $output .= $img_link_to_edit;
    }
  
  } else {
    //Create the image link to add a new children
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
      'alt' => t('Link to add children ') . $type . ' ' . $nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link_to_add = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_add_link_' . $nid, 'class' => array('fastedit_item ' . $type . '_add_link')), 'html' => True));
    $output .= $img_link_to_add;

    if (!isset($node_array['no-edit'])) {
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $nid, 'class' => array('fastedit_item ' . $type . '_edit_link')), 'html' => True));
      $output .= $img_link_to_edit;

      //Create the image link to remove the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to remove ') . $type . ' ' . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_remove = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_remove_link_' . $nid, 'class' => array('fastedit_item ' . $type . '_remove_link')), 'html' => True));
      $output .= $img_link_to_remove;
    }
  }

  return $output;

}

/*
 * Ajax callback cunction called by javascript to display the fastedit form
 */
function get_fastedit_form_response($method = 'ajax'){

  $nid = $_POST['node_id'];
  $type = $_POST['type'];
  $fastaction = $_POST['fastaction'];

dpm($_POST);


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {

    //If we want to displayed the compared children
    if ($_POST['action'] == 'display') {

      $display_type = 'itemlist';
      if (in_array($type, array('feature','implementation'))) {
        $display_type = 'row_table';
      } 
/*
      //Allow others modules to modify the output
      foreach (module_implements('wikicompare_comparative_table_fastedit_displaytype') as $module) {
        $function = $module . '_wikicompare_comparative_table_fastedit_displaytype';
        $function($display_type, $type);
      }*/


      if ($display_type == 'row_table') {
        $output .= '<tr id="line_form_' . $type . '_fast' . $fastaction . '_'. $nid . '" class="form_fastedit form_'. $type . '_fast' . $fastaction . '"><td>';
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
          
        } else {
          $output .= '<span id="parent_id" style="display:none;">' . $nid . '</span>';
        }
dpm($node);      
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


          if ($fastaction == 'edit') {

            $parent = 0;
            if ($type == 'feature') {
              $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];
            } elseif ($type == 'compared') {
              $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];
            }

            //Allow others modules to modify the output
            foreach (module_implements('wikicompare_comparative_table_fastedit_parent') as $module) {
              $function = $module . '_wikicompare_comparative_table_fastedit_parent';
              $function($parent_id, $type, $node);
            }
/*
            $query = db_select('node', 'n');
            $query->addField('n', 'title', 'title');
            $query->condition("n.nid", $parent_id);
            $result = $query->execute();
            foreach ($result as $record) {
              $parent_name = $record->title;
            }*/

            $res = get_recursive_data($type, array($parent_id));
            $parent_name = $res['data'][$parent_id]['data']->fulltitle;

            //TODO We need to remove the keyword context in simple_dialog.js to make this link work.
            //Add the link to open the select feature popup
            $select_parent_link = array(
              'text' => 'Select parent',
              'title' => 'Select parent',
              'selector' => 'dialog-content',
              'path' => 'get_dialog_callback/select_simple_dialog/' . $type . '/form_selected_parent/' . $nid,
            );
            $clear_parent_link = l('Clear', '/',  array('attributes' => array('class' => array('clear_link'))));
            $output .= '<p><span id="form_selected_parent">' . $parent_name . '</span><span id="parent_id" style="display:none;">' . $parent_id . '</span> ' . theme('simple_dialog_link', $select_parent_link) . ' ' . $clear_parent_link . '</p>';

          }

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
            $type_field['#value'] = $node->wikicompare_type['und'][0]['value'];
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
            $guidelines_field['#value'] = $node->wikicompare_guidelines['und'][0]['value'];
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
            $weight_field['#value'] = $node->wikicompare_weight['und'][0]['value'];
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
            $state_field['#value'] = $node->wikicompare_state['und'][0]['value'];
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
            $support_field['#value'] = $node->wikicompare_support['und'][0]['value'];
          }
          $output .= drupal_render($support_field);

        
        }
        
        //Allow others modules to modify the output
        foreach (module_implements('wikicompare_comparative_table_fastedit_specific') as $module) {
          $function = $module . '_wikicompare_comparative_table_fastedit_specific';
          $function($output, $type, $node, $fastaction, $nid);
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
      $output .= '<input id="form_' . $type . '_fast' . $fastaction . '_cancel_'. $nid . '" type="button" value="Cancel" class="fastform_cancel_button button"/>';
      $output .= '</form>';
      
      if ($display_type == 'row_table') {
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
          $commands[] = ajax_command_invoke('#feature_row_' . $node->wikicompare_feature_id['und'][0]['target_id'], 'after', array($output));
          break;
      }

      //Allow others modules to modify the output
      foreach (module_implements('wikicompare_comparative_table_fastedit_command') as $module) {
        $function = $module . '_wikicompare_comparative_table_fastedit_command';
        $function($commands, $type, $nid, $output);
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
function submit_fastedit_form_response($method = 'ajax'){

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
          break;
        case 'edit':
          $node = node_load($_POST['node_id']);
          $node->revision = 1;
          break;
      }
    
      if ($type != 'implementation') {
        $node->title = $_POST['title'];

        switch ($type) {
          case 'compared':
            $node->wikicompare_parent_id[$node->language][0]['target_id'] = $_POST['parent_id'];
            $node->wikicompare_parent_id[$node->language][0]['target_type'] = "node";
            break;
          case 'feature':
            $node->wikicompare_parent_id[$node->language][0]['target_id'] = $_POST['parent_id'];
            $node->wikicompare_parent_id[$node->language][0]['target_type'] = "node";
            break;
        }

      }

        
      $node->body[$node->language][0] = array(
        'value' => $_POST['description'],
        'format' => 'full_html',
      );
      
      if ($type == 'feature') {
        $node->wikicompare_type[$node->language][0]['value'] = $_POST['feature_type'];
        
        $node->wikicompare_guidelines[$node->language][0]['value'] = $_POST['guidelines'];
        $node->wikicompare_guidelines[$node->language][0]['format'] = 'full_html';
        
        $node->wikicompare_weight[$node->language][0]['value'] = $_POST['weight'];        
        
        $node->wikicompare_state[$node->language][0]['value'] = $_POST['state'];
        
      }
      
      if ($type == 'implementation') {
        $node->wikicompare_support[$node->language][0]['value'] = $_POST['support'];
      }

      foreach (module_implements('wikicompare_comparative_table_fastedit_submit') as $module) {
        $function = $module . '_wikicompare_comparative_table_fastedit_submit';
        $function($node, $type, $_POST);
      }
      
      $node->log = $_POST['revision'];
dpm($node, 'presave'); 
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



?>