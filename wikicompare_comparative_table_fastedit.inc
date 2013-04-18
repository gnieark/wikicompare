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

        $compareds = request_db('compared', array('fastedit_status' => 1, 'can_be_translated' => 1), 'nids', $_POST['compared_ids']);

      }

      $commands = array();
      foreach($compareds as $nid => $compared) {

        $output = add_fastedit_items('compared' , $compared);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#compared_node_link_' . $nid, 'after', array($output));
        //ajax_command_invoke does not call the Drupal.behaviors, so the added content isn't ajaxified. By adding this dummy content, the Drupal.behaviors will be call.
        $commands[] = ajax_command_after('#comparative_table', '<div class="to_remove"/>');

      }

      $compared = array(
        'data' => new stdClass(),
      );
      $compared['data']->nid = 0;
      $commands[] = ajax_command_invoke('#add_compared_link', 'after', array(add_fastedit_items('compared' , $compared)));


      $features = array();
      if (!empty($_POST['feature_ids'])) {


        $features = request_db('feature', array('fastedit_status' => 1, 'can_be_translated' => 1), 'nids', $_POST['feature_ids']);

      }

      foreach($features as $nid =>$feature) {

        $output = add_fastedit_items('feature', $feature);
        //Insert the link in the page. Note we can't use ajax_command_after because it adds an unwanted div
        $commands[] = ajax_command_invoke('#feature_node_link_' . $nid, 'after', array($output));

      }

      $feature = array(
        'data' => new stdClass(),
      );
      $feature['data']->nid = 0;
      $commands[] = ajax_command_invoke('#add_feature_link', 'after', array(add_fastedit_items('feature' , $compared)));
      
      $implementations = array();
      if (!empty($_POST['implementation_ids'])) {

        $implementations = request_db('implementation', array('fastedit_status' => 1, 'can_be_translated' => 1), 'nids', $_POST['implementation_ids']);


        foreach($implementations as $nid => $implementation) {

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


    $test = False;
    if (isset($node_array['no-edit']) || $nid == 0) {
      $test = True;
    }

    foreach (module_implements('wikicompare_fastedit_items_test') as $module) {
      $function = $module . '_wikicompare_fastedit_items_test';
      $function($test, $node_array);
    }


    if ($test == False) {
      //Create the image link to edit the node
      $img = theme('image', array(
        'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/add.png',
        'alt' => t('Link to edit ') . $type . ' ' . $nid,
        'height' => '100%',
      ));
      //Create the link. The html = True indicate that the title of the link contain html.
      $img_link_to_edit = l($img, 'get_fastedit_form_callback/nojs', array('attributes' => array('id' => $type . '_edit_link_' . $nid, 'class' => array('fastedit_item ' . $type . '_edit_link')), 'html' => True));
      $output .= $img_link_to_edit;

      if (!isset($node_array['no-remove'])) {
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


  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method == 'ajax') {



    //If we want to displayed the compared children
    if ($_POST['action'] == 'display') {



      $display_type = 'itemlist';
      if (in_array($type, array('feature','implementation'))) {
        $display_type = 'row_table';
      } 

      if ($display_type == 'row_table') {
        $colspan = '';
        if (isset($_POST['nb_compareds'])) {
          $colspan = 'colspan="' . $_POST['nb_compareds'] . '"';
        }
        $output .= '<tr id="line_form_' . $type . '_fast' . $fastaction . '_'. $nid . '" class="form_fastedit form_'. $type . '_fast' . $fastaction . '"><td class="row_auto_colspan" ' . $colspan . '>';
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

          $readonly = False;
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

          $tnode = new stdClass;
          $readonly_translation = False;
          foreach (module_implements('wikicompare_fastedit_get_tnode') as $module) {
            $function = $module . '_wikicompare_fastedit_get_tnode';
            $function($tnode, $readonly_translation, $node);
          }
          
        } else {
          $output .= '<span id="parent_id" style="display:none;">' . $nid . '</span>';
        }

        $form = array();
        $form_state = array();
        wikicompare_build_form('fastedit', $form, $form_state, $output, $nid, $type, $fastaction, $node, $readonly, $tnode, $readonly_translation);

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

    if ($_POST['node_id']) {
      $from_db = request_db($type, array('fastedit' => 1), 'nids', array($_POST['node_id']));
      $from_db_record = $from_db[$_POST['node_id']];
    }

    $commands = array();

    if ($fastaction == 'remove' && !isset($from_db_record['no-remove'])) {

      node_delete($_POST['node_id']);
    
    } elseif (!isset($from_db_record['no-edit'])) {
  
      switch ($fastaction) {
        case 'add':
          $node = new stdClass();
          $node->type = $type;
          $node->language = language_default('language');
          node_object_prepare($node);
          break;
        case 'edit':
          $node = node_load($_POST['node_id']);
          $node->revision = 1;
          $node->comment = 2;
          break;
      }

      $tnode = new stdClass();
      foreach (module_implements('wikicompare_fastedit_submit_init_tnode') as $module) {
        $function = $module . '_wikicompare_fastedit_submit_init_tnode';
        $function($tnode, $_POST, $fastaction);
      }    

      if ($type != 'implementation') {
        $node->title = $_POST['title'];

        foreach (module_implements('wikicompare_fastedit_submit_element') as $module) {
          $function = $module . '_wikicompare_fastedit_submit_element';
          $function($tnode, $_POST, 'title', 'title');
        }

        if ($_POST['parent_id'] != 0) {

              $node->wikicompare_parent_id['und'][0]['target_id'] = $_POST['parent_id'];
              $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
          
        }

        $node->wikicompare_sequence['und'][0]['value'] = $_POST['sequence'];  
        $node->wikicompare_state['und'][0]['value'] = $_POST['state'];  

      }

/*  TODO When wysiwyg will work
      $node->body['und'][0] = array(
        'value' => $_POST['description'],
        'format' => 'full_html',
      );
*/

      foreach (module_implements('wikicompare_fastedit_submit_element') as $module) {
        $function = $module . '_wikicompare_fastedit_submit_element';
        $function($tnode, $_POST, 'body', 'description');
      }
      
      if ($type == 'feature') {
        $node->wikicompare_type['und'][0]['value'] = $_POST['feature_type'];
        
/*  TODO When wysiwyg will work
        $node->wikicompare_guidelines['und'][0]['value'] = $_POST['guidelines'];
        $node->wikicompare_guidelines['und'][0]['format'] = 'full_html';
        foreach (module_implements('wikicompare_fastedit_submit_element') as $module) {
          $function = $module . '_wikicompare_fastedit_submit_element';
          $function($tnode, $_POST, 'wikicompare_guidelines', 'guidelines');
        }
*/
        
        $node->wikicompare_weight['und'][0]['value'] = $_POST['weight'];        
        
        
      }
      
      if ($type == 'implementation') {
        $node->wikicompare_support['und'][0]['value'] = $_POST['support'];
      }

      foreach (module_implements('wikicompare_comparative_table_fastedit_submit') as $module) {
        $function = $module . '_wikicompare_comparative_table_fastedit_submit';
        $function($node, $type, $_POST);
      }

      foreach (module_implements('wikicompare_fastedit_submit_after') as $module) {
        $function = $module . '_wikicompare_fastedit_submit_after';
        $function($node, $tnode, $_POST);
      }
      
      $node->log = $_POST['revision'];




      node_save($node);
    
      _revisioning_publish_latest_revision($node);

      if (in_array($_POST['state'], array('new', 'incomplete', 'submitted'))) {
        $commands[] = ajax_command_invoke('#checkbox-draft-items', 'attr', array('checked', 'checked'));
      } elseif (in_array($_POST['state'],array('rejected', 'disactivated'))) {
        $commands[] = ajax_command_invoke('#checkbox-closed-items', 'attr', array('checked', 'checked'));
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



?>