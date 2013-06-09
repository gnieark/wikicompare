<?php




/**
 * Implements hook_form().
 * We need it to display the title in the node form
 */
function feature_form($node, $form_state) {
  return node_content_form($node, $form_state);
}


function compared_form($node, $form_state) {
  return node_content_form($node, $form_state);
}




function wikicompare_form_compared_node_form_alter(&$form, &$form_state, $form_id) {

  wikicompare_build_form('form', $form, $form_state, 'compared');

}

function wikicompare_form_feature_node_form_alter(&$form, &$form_state, $form_id) {

  wikicompare_build_form('form', $form, $form_state, 'feature');

}

function wikicompare_form_implementation_node_form_alter(&$form, &$form_state, $form_id) {

  wikicompare_build_form('form', $form, $form_state, 'implementation');

}

function wikicompare_build_form($form_type, &$form=NULL, &$form_state=NULL, $type=NULL, &$output=NULL, $nid=NULL, $fastaction=NULL, $node=NULL, $readonly=NULL, $tnode=NULL, $readonly_translation=NULL) {



  if ($form_type == 'form') {

//    $node = new stdClass;
    $nid = 0;
//    if (isset($form_state['node'])) {
    $node = $form_state['node'];
    if (isset($node->nid)) {
      $nid = $node->nid;
    }

//    }

    if ($form_state['node']->language == 'und') {
      $form_state['node']->language = language_default('language');
    }

    //$form['#attached']['js'][] = '/misc/ajax.js';
    //$form['#attached']['js'][] = '/misc/progress.js';
    $form['#attached']['js'][] = drupal_get_path('module', 'wikicompare') . '/js/wikicompare_comparative_table.js';

    $settings = array();
/*      'wikicompare' => array(
        'fastaction' => 0,
      )
    );*/


    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_build_form_settings($settings, $form_state);
    }

    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_build_form_settings($settings, $node, $nid, $form_state);
    }


    $form['#attached']['js'][] = array(
      'type' => 'setting',
      'data' => $settings,
    );
  }

  if ($type != 'implementation') {

    if ($form_type == 'fastaction') { 
      $name_field = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#required' => TRUE,
        '#id' => 'form_' . $type . '_fast' . $fastaction . '_title_' . $nid,
      );          
      if ($fastaction == 'edit') {
        $name_field['#value'] = $node->title;
      }
      $name_field_clone = $name_field;
      if ($readonly == True) {
        $name_field['#attributes']['disabled'] = True;
      }
      $output .= render($name_field);

      if (module_exists('wikicompare_translation')) {
        wikicompare_translation_fastaction_add_element($output, $tnode, $name_field_clone, 'title', $readonly_translation, $fastaction);
      }

    }

    if ($form_type == 'form' || $fastaction == 'edit') {

      $parent_id = 0;
      $parent_name = 'No parent';
      if (isset($node->wikicompare_parent_id['und'])) {
        $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];

        $res = wikicompare_build_recursive_data($type, array($parent_id), wikicompare_initialize_settings());
        $parent_name = $res['data'][$parent_id]['data']->fulltitle;
      }
      //TODO We need to remove the keyword context in simple_dialog.js to make this link work.
      $select_parent_link = array(
        'text' => 'Select parent',
        'title' => 'Select parent',
        'selector' => 'dialog-content',
        'path' => 'wikicompare_get_dialog_callback/selectdialog/' . $type . '/wikicompare-parent-id/' . $nid, // . '/wikicompare-parent-id/wikicompare-parent-id',
      );
      $clear_parent_link = l('Clear', '/',  array('attributes' => array('class' => array('clear_link'), 'type' => $type)));

      if ($form_type == 'form') {
  /*
        $title = 'No parent';
        if (isset($node->wikicompare_parent_id['und'])) {
          $parent_nid = $node->wikicompare_parent_id['und'][0]['target_id'];
          $res = wikicompare_build_recursive_data($type, array($parent_nid), wikicompare_initialize_settings());
          $title = $res['data'][$parent_nid]['data']->fulltitle;
        }
  */


        $form['container_selected_parent'] = array(
          'title' => array('#markup' => $parent_name),
          '#type' => 'container',
          '#id' => 'container-wikicompare-parent-id',
          '#weight' => -3,
          '#suffix' => '<p>' . theme('simple_dialog_link', $select_parent_link) . ' ' . $clear_parent_link . '</p>'
    
        );

        $form['wikicompare_parent_id']['#attributes']['style'] = 'display:none;';

      }


      if ($form_type == 'fastaction') {

//        if ($fastaction == 'edit') {


  /*

          if (module_exists('wikicompare_needs')) {
            wikicompare_needs_wikicompare_comparative_table_fastaction_parent($parent_id, $type, $node);
          }
  */

  /*
          //TODO We need to remove the keyword context in simple_dialog.js to make this link work.
          //Add the link to open the select feature popup
          $select_parent_link = array(
            'text' => 'Select parent',
            'title' => 'Select parent',
            'selector' => 'dialog-content',
            'path' => 'wikicompare_get_dialog_callback/selectdialog/' . $type . '/form_selected_parent/' . $nid . '/wikicompare-parent-id/parent_id',
          );
          $clear_parent_link = l('Clear', '/',  array('attributes' => array('class' => array('clear_link'))));
  */
        $output .= '<p><span id="container-wikicompare-parent-id">' . $parent_name . '</span>';
        if ($readonly != True) {
          $output .= '<span id="parent_id" style="display:none;">' . $parent_id . '</span> ' . theme('simple_dialog_link', $select_parent_link) . ' ' . $clear_parent_link . '</p>';
        }

//        }
      }

      
      if ($form_type == 'fastaction') {
        $sequence_field = array(
          '#type' => 'textfield',
          '#title' => t('Sequence'),
          '#value' => 1,
          '#required' => TRUE,
          '#element_validate' => array('element_validate_integer'),
          '#id' => 'form_' . $type . '_fast' . $fastaction . '_sequence_' . $nid,

        );
        if ($fastaction == 'edit') {
          $sequence_field['#value'] = $node->wikicompare_sequence['und'][0]['value'];
        }
        if ($readonly == True) {
          $sequence_field['#attributes']['disabled'] = True;
        }
        $output .= render($sequence_field);
      }

    }


    if (module_exists('wikicompare_inherit_compared')) {
      wikicompare_inherit_compared_modify_form_no_implementation($form, $output, $form_type, $type, $node, $readonly);
    }


/* TODO Not working, textarea work but not text_format.
    if ($form_type == 'fastaction') {
      $description_field = array(
        '#type' => 'text_format',
        '#title' => t('Description'),
        '#format' => 'wikicompare_text_format',
        '#id' => 'form_' . $type . '_fast' . $fastaction . '_description_' . $nid,
        '#attributes' => array(
          'class' => array('form_' . $type . '_fast' . $fastaction . '_description'),
        )
      );

      if ($fastaction == 'edit') {
        $description_field['#value'] = $node->body['und'][0]['value'];
      } 
      $description_field_clone = $description_field;
      if ($readonly == True) {
        $description_field['#attributes']['disabled'] = True;
      }

    

      if (module_exists('wikicompare_translation')) {
        wikicompare_translation_fastaction_add_element($output, $tnode, $name_field_clone, 'body', $readonly_translation, $fastaction);
      }

    }
*/

    if ($form_type == 'form') {
      $form['wikicompare_user_ids']['#weight'] = 10;


      if (wikicompare_revisioning_access_node('', 'publish revisions', $node) == False) {
        //Hide the field in the form. We can't unset it, otherwise it display an error.
        hide($form['wikicompare_user_ids']);
        //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
        unset($form_state['node']->wikicompare_user_ids);
      }

      //Hide the field in the form. We can't unset it, otherwise it display an error.
      hide($form['wikicompare_user_from_parent_ids']);
      //We empty the field because only the published revision need to have the values. No security problem here since only the published revision is used, so no need to update form_state.
      $form['wikicompare_user_from_parent_ids']['und'][0]['target_id'] = NULL;
    }

  } else {

    $query = db_select('cache_implementation', 'n');
    $query->addField('f', 'title', 'feature');
    $query->addField('c', 'title', 'compared');
    $query->addField('f', 'has_children', 'feature_has_children');
    $query->addField('c', 'has_children', 'compared_has_children');
    $query->addField('ngf', 'wikicompare_guidelines_value', 'guidelines'); 
    $query->leftjoin('cache_feature', 'f', 'n.feature_id = f.nid');
    $query->leftjoin('cache_compared', 'c', 'n.compared_id = c.nid');
    $query->leftjoin('field_revision_wikicompare_guidelines', 'ngf', 'f.vid = ngf.revision_id');
    $query->condition('n.nid', $nid);
    $result = $query->execute();
    foreach ($result as $record) {
      $res = $record;
    }

    if ($form_type == 'form') {


      $form['wikicompare_guidelines'] = array(
        '#markup' => $record->guidelines,
        '#weight' => -2,
      );

      $form['wikicompare_feature_id'] = array('#markup' => $res->feature);
      $form['wikicompare_compared_id'] = array('#markup' => $res->compared);

      if (!$res->feature_has_children && !$res->compared_has_children) {
        if (wikicompare_revisioning_access_node('', 'publish revisions', $node) == False) {
          //Hide the field in the form. We can't unset it, otherwise it display an error.
          hide($form['wikicompare_protected']);
          //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
          unset($form_state['node']->wikicompare_protected);
        }
      } else {
          //Hide the field in the form. We can't unset it, otherwise it display an error.
          hide($form['wikicompare_support']);
          //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
          unset($form_state['node']->wikicompare_support);

          //Hide the field in the form. We can't unset it, otherwise it display an error.
          hide($form['wikicompare_protected']);
          //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
          unset($form_state['node']->wikicompare_protected);

          //Hide the field in the form. We can't unset it, otherwise it display an error.
          hide($form['wikicompare_proofs']);
          //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
          unset($form_state['node']->wikicompare_proofs);
      }

      if (module_exists('wikicompare_inherit_compared')) {
        wikicompare_inherit_compared_modify_form_implementation($form, $output, $readonly, $test, 'form', $type, $node, $fastaction);
      }

    }



    if ($form_type == 'fastaction') {

      if (!$res->feature_has_children && !$res->compared_has_children) {

        $test = False;
        if (module_exists('wikicompare_inherit_compared')) {
          wikicompare_inherit_compared_modify_form_implementation($form, $output, $readonly, $test, 'fastaction', $node, $fastaction);
        }

        //I wasn't able to use the renderable array, so I coded directly in html
        $output .= '<input class="form_implementation_fastaction_support form-checkbox" type="checkbox" id="edit-wikicompare-support-und"';

        if ($fastaction == 'edit') {

          $test_support = False;
 
          if ($node->wikicompare_support['und'][0]['value'] == 1) {
            $test_support = True;
          }

          if (module_exists('wikicompare_inherit_compared')) {
            wikicompare_inherit_compared_test_form_implementation($test_support, $test, $node);
          }
          if ($test_support == True) {
            $output .= ' checked="checked"';
          }
        }

        if ($readonly == TRUE) {
          $output .= ' disabled="disabled"';
        }

        $output .= ' value="1" />  <label class="option" for="form_implementation_fastaction_support_' . $node->nid . '">Support? </label>';
      }

    }

  }


  if ($form_type == 'fastaction') {
    if ($type == 'feature') {
      $type_field = array(
        '#type' => 'select',
        '#title' => t('Type'),
        '#required' => TRUE,
        '#options' => array(
          'parent-weighted-average' => 'Parent Feature - Weighted Average',
          'parent-highest-percentage' => 'Parent Feature - Highest Percentage',
        ),
        '#id' => 'form_' . $type . '_fast' . $fastaction . '_type_' . $nid,
      );
      if ($fastaction == 'edit') {
        $type_field['#value'] = $node->wikicompare_type['und'][0]['value'];
      }
      if ($readonly == True) {
        $type_field['#attributes']['disabled'] = True;
      }
      $output .= render($type_field);


/* TODO Not working, textarea work but not text_format.
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
      $guidelines_field_clone = $guidelines_field;
      if ($readonly == True) {
        $guidelines_field['#attributes']['disabled'] = True;
      }
      $output .= render($guidelines_field);

      if (module_exists('wikicompare_translation')) {
        wikicompare_translation_fastaction_add_element($output, $tnode, $name_field_clone, 'wikicompare_guidelines', $readonly_translation, $fastaction);
      }

*/

      $weight_default = 1;
      if ($parent_id != 0 && $fastaction != 'edit') {

        $query = db_select('cache_feature', 'n');
        $query->addField('n', 'nid', 'nid');
        $query->addField('n', 'type', 'type');
        $query->condition('n.nid', $parent_id);
        $result = $query->execute();
        foreach ($result as $record) {

          if ($record->type == 'parent-highest-percentage') {
            $weight_default = 100;
          }
        }
      }
      
      
      
      $weight_field = array(
        '#type' => 'textfield',
        '#title' => t('Weight'),
        '#required' => TRUE,
        '#value' => $weight_default,
        '#element_validate' => array('element_validate_integer_positive_or_null'),
        '#id' => 'form_' . $type . '_fast' . $fastaction . '_weight_' . $nid,

      );
      if ($fastaction == 'edit') {
        $weight_field['#value'] = $node->wikicompare_weight['und'][0]['value'];
      }
      if ($readonly == True) {
        $weight_field['#attributes']['disabled'] = True;
      }
      $output .= render($weight_field);
      

    }
  }


  if ($type != 'implementation') {
    if ($form_type == 'form') {
      $current_state = 'new';  
      if (isset($form['wikicompare_state']['und']['#default_value'][0])) {
        $current_state = $form['wikicompare_state']['und']['#default_value'][0];
      }
      $form['wikicompare_state']['und']['#options'] = wikicompare_state_get_options($nid, $current_state);
    }

    if ($form_type == 'fastaction') {
      $state_field = array(
        '#type' => 'select',
        '#title' => t('State'),
        '#required' => TRUE,
        '#options' => wikicompare_state_get_options($nid, 'new'),
        '#id' => 'form_' . $type . '_fast' . $fastaction . '_state_' . $nid,

      );
      if ($fastaction == 'edit') {
        $state_field['#value'] = $node->wikicompare_state['und'][0]['value'];
        $state_field['#options'] = wikicompare_state_get_options($nid, $state_field['#value']);
      }
      if ($readonly == True) {
        $state_field['#attributes']['disabled'] = True;
      }
      $output .= render($state_field);
    }

  }

  if ($form_type == 'form') {


    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_build_form_after($form, $form_state, $node);
    }

  }


  if (module_exists('wikicompare_needs')) {
    wikicompare_needs_build_form($form, $form_state, $output, $form_type, $type, $node, $fastaction, $nid);
  }

  if ($form_type == 'fastaction') {


    
    $revision_field = array(
      '#type' => 'textarea',
      '#title' => t('Revision log message'),
      '#id' => 'form_' . $type . '_fast' . $fastaction . '_revision_' . $nid,
      '#value' => '',

    );
    $output .= render($revision_field);

    //Allow others modules to modify the output
    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_fastaction_specific_after($output, $type, $node, $fastaction, $nid, $readonly, $readonly_translation);
    }

  }


}




function add_fastaction_items($type, $node_array){


  $output = ' ';

  $nid = $node_array['data']->nid;

  
  if ($type == 'implementation') {
    
    if (!isset($node_array['no-edit'])) {   
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'wikicompare_table_fastaction_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $nid, 'class' => array('fastaction_item '), 'type' => $type, 'action' => 'edit'), 'html' => True));
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
    $img_link_to_add = l($img, 'wikicompare_table_fastaction_form_callback/nojs', array('attributes' => array('id' => $type . '_add_link_' . $nid, 'class' => array('fastaction_item '), 'type' => $type, 'action' => 'add'), 'html' => True));
    $output .= $img_link_to_add;


    $test = False;
    if (isset($node_array['no-edit']) || $nid == 0) {
      $test = True;
    }



    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_fastaction_items_test($test, $node_array);
    }

    if ($test == False) {
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'wikicompare_table_fastaction_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $nid, 'class' => array('fastaction_item '), 'type' => $type, 'action' => 'edit'), 'html' => True));
      $output .= $img_link_to_edit;

      if (!isset($node_array['no-remove'])) {
        //Create the image link to remove the node
        $img = theme('image', array(
          'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
          'alt' => t('Link to remove ') . $type . ' ' . $nid,
          'height' => '100%',
        ));
        //Create the link. The html = True indicate that the title of the link contain html.
        $img_link_to_remove = l($img, 'wikicompare_table_fastaction_form_callback/nojs', array('attributes' => array('id' => $type . '_remove_link_' . $nid, 'class' => array('fastaction_item '), 'type' => $type, 'action' => 'remove'), 'html' => True));
        $output .= $img_link_to_remove;
      }
    }
  }

  return $output;

}

/*
 * Ajax callback cunction called by javascript to display the fastaction form
 */
function wikicompare_table_fastaction_form_response($method = 'ajax'){


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }







  $nid = $_POST['nid'];
  $type = $_POST['type'];
  $fastaction = $_POST['fastaction'];


  $commands = array();




  //If we want to displayed the compared children
  if ($_POST['display']) {

    $output = '';

    $display_type = 'itemlist';
    if (in_array($type, array('feature','implementation'))) {
      $display_type = 'row_table';
    } 

    if ($display_type == 'row_table') {
      $colspan = '';
      if (isset($_POST['colspan'])) {
        $colspan = 'colspan="' . $_POST['colspan'] . '"';
      }
      $output .= '<tr id="form_fastaction_' . $nid . '" class="form_fastaction"><td class="row_auto_colspan" ' . $colspan . '>';
    }
    
    $output .= '<form id="form_fastaction_' . $nid . '" class="form_fastaction">';
    
    
  
    if ($fastaction == 'remove') {
    
      $label = array(
        '#markup' => t('Do you really want to remove this ') . $type . '<br/>',
      );
      $output .= render($label);
    
    
    } else {
    
      
      $node = new stdClass;
      $node->type = $type;
      $readonly = False;
      $tnode = new stdClass;
      $readonly_translation = False;        
            
      if ($fastaction == 'edit') {
  
        $node = node_load($nid);


        $query = db_select('node_revision', 'n');
        $query->addField('n', 'nid', 'nid');
        $query->addField('n', 'uid', 'uid');
        $query->condition('n.nid', $nid);
        $result = $query->execute();
        foreach ($result as $record) {
          if ($GLOBALS['user']->uid != $record->uid) {
            $readonly = True;
          }
        }


        if (module_exists('wikicompare_translation')) {
          wikicompare_translation_fastaction_get_tnode($tnode, $readonly_translation, $node);
        }
        
      } else {
        $output .= '<span id="parent_id" style="display:none;">' . $nid . '</span>';
      }

      $form = array();
      $form_state = array();
      wikicompare_build_form('fastaction', $form, $form_state, $output, $nid, $type, $fastaction, $node, $readonly, $tnode, $readonly_translation);

    }
    
    $output .= '<div id="form_fastaction_error_zone"></div>';

    $output .= '<input id="form_fastaction_submit_' . $nid . '" type="submit" value="Confirm" class="form_fastaction_submit button"/>';
    $submit_link = array(
      '#type' => 'link',
      '#title' => 'submit',
      '#href' => 'wikicompare_table_fastaction_submit_callback/nojs/',
      '#id' => 'form_fastaction_submit_link_' . $nid ,
      '#attributes' => array(
        'class' => 'form_fastaction_submit_link',
        'style' => 'display:none',
        'type' => $type,
        'action' => $fastaction,
      )
    );
    $output .= render($submit_link);
    $output .= '<input id="form_fastaction_cancel_ ' . $nid . '" type="button" value="Cancel" class="form_fastaction_cancel button"/>';
    $output .= '</form>';
    
    if ($display_type == 'row_table') {
      $output .= '</td></tr>';
    }




    //Insert the form in the page. Note we can't use ajax_command_before or ajax_command_after because it adds an unwanted div
    switch ($type) {
      case ('compared'):
        $commands[] = ajax_command_invoke('#compared_table_children_' . $nid, 'before', array($output));
        break;
      case ('feature'):
        $commands[] = ajax_command_invoke('#feature_table_' . $nid, 'after', array($output));
        break;
      case ('implementation'):
        $commands[] = ajax_command_invoke('#feature_table_' . $node->wikicompare_feature_id['und'][0]['target_id'], 'after', array($output));
        break;
    }


    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_fastaction_command($commands, $type, $nid, $output);
    }

    //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
    $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');


  //If we want to hide the form
  }

  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}


/*
 * Ajax callback function called by javascript when we submit one of the fastaction form.
 */
function wikicompare_table_fastaction_submit_response($method = 'ajax'){


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  $type = $_POST['type'];
  $fastaction = $_POST['fastaction'];


  if ($_POST['nid']) {
    $from_db = request_db($type, array('nids' => array($_POST['nid'])), wikicompare_initialize_settings(array('fastaction' =>  1)));
    $from_db_record = $from_db[$_POST['nid']];
  }

  $commands = array();

  if ($fastaction == 'remove' && !isset($from_db_record['no-remove'])) {

    node_delete($_POST['nid']);

    $commands[] = ajax_command_remove('#' . $type . '_table_supertitle_'. $_POST['nid']);
    $commands[] = ajax_command_invoke('#' . $type . '_table_item_'. $_POST['nid'], 'addClass', array('to_remove'));
    $commands[] = ajax_command_html('#form_fastaction_' . $_POST['nid'], 'The node is correctly removed');
    $commands[] = ajax_command_invoke('#wikicompare_make_cleaning_link', 'click', array());

  } elseif (!isset($from_db_record['no-edit'])) {

    $missing_field = FALSE;

    switch ($fastaction) {
      case 'add':
        $node = new stdClass();
        $node->type = $type;
        $node->language = language_default('language');
        node_object_prepare($node);
        break;
      case 'edit':
        $node = node_load($_POST['nid']);
        $node->revision = 1;
        $node->comment = 2;
        break;
    }

    $tnode = new stdClass();

    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_fastaction_submit_init_tnode($tnode, $_POST, $fastaction);
    } 

    if ($type != 'implementation') {
      if ($_POST['title'] != NULL) {
        $node->title = $_POST['title'];
      } else {
        $missing_field = TRUE;
      }

      if (module_exists('wikicompare_translation')) {
        wikicompare_translation_fastaction_submit_element($tnode, $_POST, 'title', 'title', $fastaction);
      } 

      if ($_POST['parent_id'] != 0) {

            $node->wikicompare_parent_id['und'][0]['target_id'] = $_POST['parent_id'];
            $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
        
      } else {
        $node->wikicompare_parent_id['und'] = NULL;
      }



      if ($_POST['sequence'] != NULL) {
        $node->wikicompare_sequence['und'][0]['value'] = $_POST['sequence'];  
      } else {
        $missing_field = TRUE;
      }

      if ($_POST['state'] != NULL) {
        $node->wikicompare_state['und'][0]['value'] = $_POST['state'];  
      } else {
        $missing_field = TRUE;
      }

    }


/*  TODO When wysiwyg will work
    $node->body['und'][0] = array(
      'value' => $_POST['description'],
      'format' => 'full_html',
    );


    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_wikicompare_fastaction_submit_element($tnode, $_POST, 'body', 'description');
    } 

*/

    $donotupdate = False;
    if (module_exists('wikicompare_inherit_compared')) {
      wikicompare_inherit_compared_fastaction_submit_element($node, $donotupdate, $_POST);
    }
    
    if ($type == 'feature') {
      if ($_POST['feature_type'] != NULL) {
        $node->wikicompare_type['und'][0]['value'] = $_POST['feature_type'];
      } else {
        $missing_field = TRUE;
      }
      
/*  TODO When wysiwyg will work
      $node->wikicompare_guidelines['und'][0]['value'] = $_POST['guidelines'];
      $node->wikicompare_guidelines['und'][0]['format'] = 'full_html';

      if (module_exists('wikicompare_translation')) {
        wikicompare_translation_wikicompare_fastaction_submit_element($tnode, $_POST, 'wikicompare_guidelines', 'guidelines');
      } 

*/
      
      if ($_POST['weight'] != NULL) {
        $node->wikicompare_weight['und'][0]['value'] = $_POST['weight'];        
      } else {
        $missing_field = True;
      }
      
      
    }
    
    if ($type == 'implementation') {
      if ($donotupdate == False) {
          if ($_POST['support'] == 'true') {
            $node->wikicompare_support['und'][0]['value'] = 1;
          } else {
            $node->wikicompare_support['und'][0]['value'] = 0;
          }
      }
    }


    if (module_exists('wikicompare_needs')) {
      wikicompare_needs_fastaction_submit_after($node, $type, $_POST);
    }



    if (module_exists('wikicompare_translation')) {
      wikicompare_translation_fastaction_submit_after($node, $tnode, $_POST, $fastaction);
    } 
    
    $node->log = $_POST['revision'];




    if ($missing_field == FALSE) {

      node_save($node);
  
      _revisioning_publish_latest_revision($node);

      if ($type != 'implementation') {
        if (in_array($_POST['state'], array('new', 'incomplete', 'submitted'))) {
          $commands[] = ajax_command_invoke('#checkbox-draft-items', 'attr', array('checked', 'checked'));
        } elseif (in_array($_POST['state'],array('rejected', 'disactivated'))) {
          $commands[] = ajax_command_invoke('#checkbox-closed-items', 'attr', array('checked', 'checked'));
        }
      }

      $commands[] = ajax_command_invoke('.fastaction_item:.displayed', 'removeClass', array('displayed'));
      $commands[] = ajax_command_invoke('#make_cleaning_link', 'click', array());

    } else {
      $commands[] = ajax_command_html('#form_fastaction_error_zone', 'Some required fields are missing.');
    }


    
  } else {
    $commands[] = ajax_command_html('#form_fastaction_' . $_POST['nid'], 'The node was modified by someone else before your confirmation');
  }


  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}






function wikicompare_state_get_options($nid, $current_state) {

  $user = $GLOBALS['user'];

  $label_options = unserialize(WIKICOMPARE_STATE_OPTIONS);  

  $has_right = False;
  if (wikicompare_test_access_node('test', $nid, $user->uid)  || user_access('moderate wikicompare', $user) || $user->uid == 1) {
    $has_right = True;
  }

  $options = array();

  if ($current_state == 'new') {
    $options['new'] = $label_options['new'];
  }

  if ((in_array($current_state, array('incomplete', 'submitted', 'disactivated')) || $has_right)) {
    $options['incomplete'] = $label_options['incomplete'];
  }

  if ((in_array($current_state, array('new', 'incomplete', 'submitted', 'disactivated')) || $has_right)) {
    $options['submitted'] = $label_options['submitted'];
  }

  if ((in_array($current_state, array('published-incomplete', 'published-submitted', 'published')) || $has_right)) {
    $options['published-incomplete'] = $label_options['published-incomplete'];
  }


  if ((in_array($current_state, array( 'published-incomplete', 'published-submitted', 'published')) || $has_right)) {
    $options['published-submitted'] = $label_options['published-submitted'];
  }

  if ((in_array($current_state, array('published-incomplete', 'published-submitted', 'published')) || $has_right)) {
    $options['published'] = $label_options['published'];
  }

  if ($has_right) {
    $options['rejected'] = $label_options['rejected'];
  }

  $options['disactivated'] = $label_options['disactivated'];

  return $options;


}




/**
 * Implements hook_revisioning_access_node().
 * Check _revisioning_access_node_revision and revisioning_user_node_access in revisioning.module for more information
 * We need to add :
 * $tests = module_invoke_all('revisioning_access_node', $node_op, $revision_op, $node);
 * foreach ($tests as $test) {
 *   if ($test == False) {
 *     $node_op = False;
 *   }
 * }
 * after
 * $node_op = revisioning_user_node_access($revision_op, $node);
 * in revisioning.module. Make some lobbying to integrate this hook in revisioning module.
 *
 * It would be better to implement this hook in revisioning_user_node_access, but this function is poorly designed. It return during the whole function, we suggest to move only one return at the end and insert the hook just before.
 * Since auto-publish use directly revisioning_user_node_access, we can't alter his result. Therefore, we can't use the auto-publish feature for now because since everyone has the publish revision right, everyone will auto-publish even those who are not power users.
 */ 
function wikicompare_revisioning_access_node($node_op, $revision_op, $node) {


  if ($revision_op == 'publish revisions') {

    $uid = $GLOBALS['user']->uid;

    $test = False;
    if (isset($node->nid)) { //Manage case when we create the node
      $test = wikicompare_test_access_node('test', $node->nid, $uid);
    }


    if (($test == False) && ($uid != 1)) {
      return False;
    } else {
      return True;
    }

  }



}

function wikicompare_test_access_node($action, $nid, $uid=NULL) {

    $test = False;
    $users = array();

    if ($nid == NULL) {
      return False;
    }

    if (user_access('moderate wikicompare')) {
      $test = True;
    }


    $query = db_select('node', 'n');
    $query->addField('f', 'wikicompare_user_from_parent_ids_target_id', 'uid');
    $query->join('field_revision_wikicompare_user_from_parent_ids', 'f', 'n.vid = f.revision_id');
    $query->condition('n.nid', $nid);
    if ($action == 'test') {
      $query->condition('f.wikicompare_user_from_parent_ids_target_id', $uid);
    }
    $result = $query->execute();
    foreach ($result as $record) {
      if ($action == 'test') {
        $test = True;
      } else {
          $users[$record->uid] = array(
            'entity_type' => 'node',
            'bundle' => '',
            'deleted' => 0,
            'entity_id' => 0,
            'revision_id' => 0,
            'language' => 'und',
            'delta' => 0,
            'wikicompare_user_from_parent_ids_target_id' => $record->uid,
          );
      }
    }


    $query = db_select('node', 'n');
    $query->addField('f', 'wikicompare_user_ids_target_id', 'uid');
    $query->join('field_revision_wikicompare_user_ids', 'f', 'n.vid = f.revision_id');
    $query->condition('n.nid', $nid);
    if ($action == 'test') {
      $query->condition('f.wikicompare_user_ids_target_id', $uid);
    }
    $result = $query->execute();
    foreach ($result as $record) {
      if ($action == 'test') {
        $test = True;
      } else {
          $users[$record->uid] = array(
            'entity_type' => 'node',
            'bundle' => '',
            'deleted' => 0,
            'entity_id' => 0,
            'revision_id' => 0,
            'language' => 'und',
            'delta' => 0,
            'wikicompare_user_from_parent_ids_target_id' => $record->uid,
          );
      }
    }

  

    if ($action == 'test') {
      return $test;
    } else {
      return $users;
    }

}





?>