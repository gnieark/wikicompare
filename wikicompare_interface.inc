<?php

/**
 * @file
 * Fonctions which modify the forms, in the node page or in fastaction.
 */



/**
 * Implements hook_form().
 * We need it to display the title in the nodes form.
 */
function criterion_form($node, $form_state) {
  return node_content_form($node, $form_state);
}

function product_form($node, $form_state) {
  return node_content_form($node, $form_state);
}



/**
 * Implements hook_form_TYPE_node_form_alter().
 * This hook allow us to alter the edit form of the node.
 */
function wikicompare_form_product_node_form_alter(&$form, &$form_state, $form_id) {
  //Call type-agnostic function.
  wikicompare_build_form(array(), 'form', $form, $form_state, 'product');
}
function wikicompare_form_criterion_node_form_alter(&$form, &$form_state, $form_id) {
  //Call type-agnostic function.
  wikicompare_build_form(array(), 'form', $form, $form_state, 'criterion');
}
function wikicompare_form_evaluation_node_form_alter(&$form, &$form_state, $form_id) {
  //Call type-agnostic function.
  wikicompare_build_form(array(), 'form', $form, $form_state, 'evaluation');
}



/**
 * Type-agnostic function which will build the form for edit node and also for fastaction form.
 *
 * @param $form_type
 *   Flag defining if the function is called to build a form node of a fastaction form.
 *
 * @param $form
 *   The form array which will be used by Drupal to build the node form. Passed by reference.
 *
 * @param $form_state
 *   Array containing in-depth information of the node and form settings. Passed by reference.
 *
 * @param $type
 *   The type of the consulted node.
 *
 * @param $output
 *   The HTML code which will be inserted in the comparative table to display the fastaction form. Passed by reference.
 *
 * @param $nid
 *   The nid of the consulted node.
 *
 * @param $fastaction
 *   The fastaction (add or edit)
 *
 * @param $node
 *   Object containing the detail of the node.
 *
 * @param $readonly
 *   Flag defining if the user should be able to modify the main node in fastaction.
 *
 * @param $tnode
 *   Object containing the detail of the translation node, in the language of the user.
 *
 * @param $readonly_translation
 *   Flag defining if the user should be able to modify the translation node in fastaction.
 */
function wikicompare_build_form($settings, $form_type, &$form=NULL, &$form_state=NULL, $type=NULL, &$output=NULL, $nid=NULL, $fastaction=NULL, $node=NULL, $readonly=NULL, $tnode=NULL, $readonly_translation=NULL) {

  if ($form_type == 'form') {

    $nid = 0;
    $node = $form_state['node'];
    //There is no nid if we are creating a new node.
    if (isset($node->nid)) {
      $nid = $node->nid;
    }

    //When we create a new node, the language is undefined, we change it for the main language.
    if ($form_state['node']->language == 'und') {
      $form_state['node']->language = language_default('language');
    }

    //Add the wikicompare javascript file. Mainly used to display the popin.
    $form['#attached']['js'][] = drupal_get_path('module', 'wikicompare') . '/js/wikicompare_comparative_table.js';

    $settings = array();

    if (module_exists('wikicompare_profiles')) {
      //Send the criterions of the profile node to javascript file, so we can checked the criterions by default in the popin.
      wikicompare_profiles_build_form_settings($settings, $form_state);
    }

    if (module_exists('wikicompare_translation')) {
      //Get the main language node if we are consulting a translation node.
      wikicompare_translation_build_form_settings($node, $nid, $form_state);
    }

    //Send the needed variables to the javascript.
    $form['#attached']['js'][] = array(
      'type' => 'setting',
      'data' => $settings,
    );

  }

  //Code specific to all node type except evaluation.
  if ($type != 'evaluation') {

    //Code relative to title field. It is automatically displayed in form, so only fastaction is concerned.
    if ($form_type == 'fastaction') {
      $name_field = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#required' => TRUE,
        '#id' => 'form-' . $type . '-fast' . $fastaction . '-title-' . $nid,
      );
      //We preset the field with the value in database.
      if ($fastaction == 'edit') {
        $name_field['#value'] = $node->title;
      }
      //The render() function destroy the variable, so we need a duplication for the translation.
      $name_field_clone = $name_field;
      //If the user do not have rights, then the field become read-only.
      if ($readonly == True) {
        $name_field['#attributes']['disabled'] = True;
      }
      //Render the HTML code.
      $output .= render($name_field);

      if (module_exists('wikicompare_translation')) {
        //Add an item coming from the translated node in the form.
        wikicompare_translation_fastaction_add_element($output, $tnode, $name_field_clone, 'title', $readonly_translation, $fastaction);
      }

    }

    //Code relative to the parent field. The field isn't displayed in fastadd mode because the parent is defined by the button fastadd itself.
    if ($form_type == 'form' || $fastaction == 'edit' || isset($settings['force_parent_field'])) {

      $parent_id = 0;
      //Default message.
      $parent_name = 'No parent';
      //Get parent detail.
      if (isset($node->wikicompare_parent_id['und'])) {
        $parent_id = $node->wikicompare_parent_id['und'][0]['target_id'];
        //We use wikicompare_build_recursive_data() to build the full title of the parent.
        $res = wikicompare_build_recursive_data($type, array($parent_id), wikicompare_initialize_settings());
        $parent_name = $res['data'][$parent_id]['data']->fulltitle;
      }

      //Link which will open a popin where we can select the parent.
      $select_parent_link = array(
        '#type' => 'link',
        '#title' => 'Select parent',
        '#href' => 'wikicompare-get-dialog-callback/nojs',
        '#id' => 'select-parent-link-' . $nid,
        '#attributes' => array(
          'class' => array('ajaxlink'),
          'action' => 'open-dialog',
          'dialog-action' => 'selectdialog',
          'side' => 'left',
          'nid' => $nid,
          'ntype' => $type,
          'context' => 'selectdialog',
          'container' => 'wikicompare-parent-id',
        ),
      );

      //Link which will reset the parent.
      $clear_parent_link = l('Clear', '/',  array('attributes' => array('class' => array('clear-link'), 'type' => $type)));

      //Add an array which will be generated by drupal with the items relatives to the parent.
      if ($form_type == 'form') {
        //Container which will contain the parent name.
        $form['container_selected_parent'] = array(
          'title' => array('#markup' => $parent_name),
          '#type' => 'container',
          //This id will be used by javascript to update the parent name.
          '#id' => 'container-wikicompare-parent-id',
          '#weight' => -3,
          //We add the link after the container.
          '#suffix' => '<p>' . render($select_parent_link) . ' ' . $clear_parent_link . '</p>'
        );
        //Hide the field from drupal. We can't use the hide() function because it'll block the javascript to update the parent.
        $form['wikicompare_parent_id']['#attributes']['style'] = 'display:none;';
      }

      //Add the HTML code relative to the parents.
      if ($form_type == 'fastaction') {
        //Container with the parent name.
        $output .= '<p><span id="container-wikicompare-parent-id">' . $parent_name . '</span>';
        if ($readonly != True) {
          //Span with the parent_id, which will be recovered by the submit function and updated by javascript. Followed by the link.
          $output .= '<span id="wikicompare-old-parent-id" style="display:none;">' . $parent_id . '</span><span id="wikicompare-parent-id" style="display:none;">' . $parent_id . '</span> ' . render($select_parent_link) . ' ' . $clear_parent_link . '</p>';
        }
      }

    }

    //Code relative to sequence field. It is automatically displayed in form, so only fastaction is concerned.
    if ($form_type == 'fastaction') {
      $sequence_field = array(
        '#type' => 'textfield',
        '#title' => t('Sequence'),
        '#value' => 1,
        '#required' => TRUE,
        '#element_validate' => array('element_validate_integer'),
        '#id' => 'form-' . $type . '-fast' . $fastaction . '-sequence-' . $nid,

      );
      //We preset the field with the value in database.
      if ($fastaction == 'edit') {
        $sequence_field['#value'] = $node->wikicompare_sequence['und'][0]['value'];
      }
      //If the user do not have rights, then the field become read-only.
      if ($readonly == True) {
        $sequence_field['#attributes']['disabled'] = True;
      }
      //Render the HTML code.
      $output .= render($sequence_field);
    }

    if (module_exists('wikicompare_inherit_product')) {
      //Add the fields relative to inherit product in product node.
      wikicompare_inherit_product_modify_form_no_evaluation($form, $output, $form_type, $type, $node, $nid, $readonly);
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

    //Display the field power users, only in form.
    if ($form_type == 'form') {
      //Modify the weight to place it at the end of the form.
      $form['wikicompare_user_ids']['#weight'] = 10;
      //We can modify the field only if we have the rights on the node.
      if (wikicompare_revisioning_access_node_revision('publish revisions', $node) != 1) {
        //Hide the field in the form. We can't unset it, otherwise it display an error.
        hide($form['wikicompare_user_ids']);
        //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
        unset($form_state['node']->wikicompare_user_ids);
      }
      //The users from parent must never be modified by the users.
      //Hide the field in the form. We can't unset it, otherwise it display an error.
      hide($form['wikicompare_user_from_parent_ids']);
      //We empty the field because only the published revision need to have the values. No security problem here since only the published revision is used, so no need to update form_state.
      $form['wikicompare_user_from_parent_ids']['und'][0]['target_id'] = NULL;
    }

  //Code specific to evaluation.
  } else {

    //Get information from cache, like guidelines and has_children flag of product and criterion.
    $query = db_select('wikicompare_cache_evaluation', 'n');
    $query->addField('f', 'title', 'criterion');
    $query->addField('c', 'title', 'product');
    $query->addField('f', 'has_children', 'criterion_has_children');
    $query->addField('c', 'has_children', 'product_has_children');
    $query->addField('ngf', 'wikicompare_guidelines_value', 'guidelines');
    $query->leftjoin('wikicompare_cache_criterion', 'f', 'n.criterion_id = f.nid');
    $query->leftjoin('wikicompare_cache_product', 'c', 'n.product_id = c.nid');
    $query->leftjoin('field_revision_wikicompare_guidelines', 'ngf', 'f.vid = ngf.revision_id');
    $query->condition('n.nid', $nid);
    $result = $query->execute();
    foreach ($result as $record) {
      $res = $record;
    }

    if ($form_type == 'form') {

      //Display guidelines from criterion.
      $form['wikicompare_guidelines'] = array(
        '#markup' => $record->guidelines,
        '#weight' => -2,
      );

      //Transform criterion and product many2one field into simple label.
      $form['wikicompare_criterion_id'] = array('#markup' => $res->criterion);
      $form['wikicompare_product_id'] = array('#markup' => $res->product);

      //We can modify the value of the evaluation only it is at the root of the tree in both axis.
      if (!$res->criterion_has_children && !$res->product_has_children) {
        //If the user has not rights on the node, then he will not be able to change the protected status of the evaluation.
        if (wikicompare_revisioning_access_node('', 'publish revisions', $node) == False) {
          //Hide the field in the form. We can't unset it, otherwise it display an error.
          hide($form['wikicompare_protected']);
          //We unset the field in form_state by security, so even if a user display the field with firebug and change value, the value will not be updated.
          unset($form_state['node']->wikicompare_protected);
        }
      //If we are not at the root of the table, we remove the support fields.
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

      if (module_exists('wikicompare_inherit_product')) {
        $test = False;
        //Add the fields relative to inherit product in evaluation node.
        wikicompare_inherit_product_modify_form_evaluation($form, $output, $readonly, $test, 'form', $type, $node, $fastaction);
      }

    }


    if ($form_type == 'fastaction') {

      //We can modify the value of the evaluation only it is at the root of the tree in both axis.
      if (!$res->criterion_has_children && !$res->product_has_children) {
        $test = False;
        $disable_support = False;
        if (module_exists('wikicompare_inherit_product')) {
          wikicompare_inherit_product_modify_form_evaluation($form, $output, $disable_support, $test, 'fastaction', $type, $node, $readonly, $fastaction);
        }

        //I wasn't able to use the renderable array, so I coded directly in html
        $output .= '<input class="form-evaluation-fastaction-support form-checkbox" type="checkbox" id="edit-wikicompare-support-und"';

        if ($fastaction == 'edit') {
          $test_support = False;
          //Test if the support field must be checked.
          if ($node->wikicompare_support['und'][0]['value'] == 1) {
            $test_support = True;
          }
          if (module_exists('wikicompare_inherit_product')) {
            //Test if the support field must be checked.
            wikicompare_inherit_product_test_form_evaluation($test_support, $test, $node);
          }
          if ($test_support == True) {
            $output .= ' checked="checked"';
          }
        }

        //If the user do not have rights, then the field become read-only.
        if ($readonly == True || $disable_support == True) {
          $output .= ' disabled="disabled"';
        }

        $output .= ' value="1" />  <label class="option" for="form-evaluation-fastaction-support-' . $node->nid . '">Support? </label>';
      }

    }

  }

  if ($form_type == 'fastaction') {

    //Product specific fields.
    if ($type == 'product') {

      $comparable_field = array(
        '#type' => 'select',
        '#title' => t('Comparable'),
        '#required' => TRUE,
        '#options' => array(
          'only-without-children' => 'Only if it has no children',
          'always-combine' => 'Always - Combine the children evaluations',
        ),
        '#id' => 'form-' . $type . '-fast' . $fastaction . '-comparable-' . $nid,
      );
      if ($fastaction == 'edit') {
        $comparable_field['#value'] = $node->wikicompare_comparable['und'][0]['value'];
      }
      if ($readonly == True) {
        $comparable_field['#attributes']['disabled'] = True;
      }
      $output .= render($comparable_field);

      //Get all active infofields.
      $settings['infofields'] = array();
      $query = db_select('wikicompare_infofields', 'f');
      $query->addField('f', 'name', 'name');
      $query->addField('f', 'title', 'title');
      $query->addField('f', 'type', 'type');
      $query->addField('f', 'category', 'category');
      $query->addField('f', 'allowed_values', 'allowed_values');
      $query->addField('f', 'is_required', 'is_required');
      $query->condition('f.is_active', 1);
      $query->orderby('f.category_sequence');
      $query->orderby('f.category');
      $query->orderby('f.sequence');
      $query->orderby('f.title');
      $result = $query->execute();
      foreach ($result as $record) {
        $infofield_name = 'wikicf_' . $record->name;
        $infofield_type = 'textfield';
        if ($record->type == 'select') {
          $infofield_type = 'select';
        }
        //Transform the text field into exploitable array.
        $record->allowed_values = str_replace("\n\r", "\n", $record->allowed_values);
        $allowed_values = array();
        foreach(explode("\n", $record->allowed_values) as $value) {
          $allowed_values[$value] = $value;
        }
        $infofield = array(
          '#type' => $infofield_type,
          '#title' => $record->title,
          '#required' => $record->is_required,
          '#options' => $allowed_values,
          '#id' => 'form-' . $type . '-fast' . $fastaction . '-wikicf-' . $record->name . '-' . $nid,
          '#attributes' => array('class' => array('fastaction-infofield'), 'field' => $record->name, 'required' => $record->is_required),
        );
        if ($fastaction == 'edit') {
          $infofield_value = $node->$infofield_name;
          $infofield['#value'] = $infofield_value['und'][0]['value'];
        }
        if ($readonly == True) {
          $comparable_field['#attributes']['disabled'] = True;
        }
        $output .= render($infofield);
      }
    }

    //Criterion specific fields.
    if ($type == 'criterion') {

      $type_field = array(
        '#type' => 'select',
        '#title' => t('Type'),
        '#required' => TRUE,
        '#options' => array(
          'parent-weighted-average' => 'Parent Criterion - Weighted Average',
          'parent-highest-percentage' => 'Parent Criterion - Highest Percentage',
        ),
        '#id' => 'form-' . $type . '-fast' . $fastaction . '-type-' . $nid,
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
      //If the parent if of type highest-percentage, then the default weight must be 100 and not 1.
      if ($parent_id != 0 && $fastaction != 'edit') {
        $query = db_select('wikicompare_cache_criterion', 'n');
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
        '#id' => 'form-' . $type . '-fast' . $fastaction . '-weight-' . $nid,

      );
      if ($fastaction == 'edit') {
        $weight_field['#value'] = $node->wikicompare_weight['und'][0]['value'];
      }
      if ($readonly == True) {
        $weight_field['#attributes']['disabled'] = True;
      }
      $output .= render($weight_field);

      $user = $GLOBALS['user'];

      if (user_access('administer wikicompare', $user)) {
        $suggest_field = array(
          '#type' => 'textfield',
          '#title' => t('Use this criterion for home page suggestions'),
          '#required' => TRUE,
          '#value' => 0,
          '#element_validate' => array('element_validate_integer_positive_or_null'),
          '#id' => 'form-' . $type . '-fast' . $fastaction . '-suggest-' . $nid,

        );
        if ($fastaction == 'edit') {
          $suggest_field['#value'] = $node->wikicompare_suggest['und'][0]['value'];
        }
        if ($readonly == True) {
          $suggest_field['#attributes']['disabled'] = True;
        }
        $output .= render($suggest_field);
      }

    }

  }

  //Code relative to state field, common to all type except evaluation.
  if ($type != 'evaluation') {

    if ($form_type == 'form') {
      //Default state.
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
        '#id' => 'form-' . $type . '-fast' . $fastaction . '-state-' . $nid,

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
      //Remove importants fields in form if we are in translation node.
      wikicompare_translation_build_form_after($form, $form_state, $node);
    }
  }

  if (module_exists('wikicompare_profiles')) {
    //Add the field specific to profile at the end of the form.
    wikicompare_profiles_build_form($form, $form_state, $output, $form_type, $type, $node, $fastaction, $nid);
  }

  //Add the revision field in fastaction, which allow to tell why you modify the node in a new revision.
  if ($form_type == 'fastaction') {
    $revision_field = array(
      '#type' => 'textarea',
      '#title' => t('Revision log message'),
      '#id' => 'form-' . $type . '-fast' . $fastaction . '-revision-' . $nid,
      '#value' => '',
    );
    $output .= render($revision_field);

    if (module_exists('wikicompare_translation')) {
      //Add the selected field which will allow to select the node which will be submited, main language node or translation.
      wikicompare_translation_fastaction_specific_after($output, $type, $node, $fastaction, $nid, $readonly, $readonly_translation);
    }

  }

}





/**
 * Return the html code of the fastaction items to display on the comparative table.
 *
 * @param $type
 *   The type of the node.
 *
 * @param $node_array
 *   The node for which we want to display the fastaction item.
 */
function add_fastaction_items($type, $node_array){


  $nid = $node_array['data']->nid;
  $actions = array();

  //If the node is an evaluation, then we can only fastedit the item, not fastadd or fastremove.
  if ($type == 'evaluation') {

    //Unless the database say the user can't fastedit the node, for exemple if he's not the author of some of the revisions.
    if (!isset($node_array['no-edit'])) {
      $actions['edit'] = 'edit';
    }

  //We can fastadd / fastedit / fastremove all the other node types.
  } else {
    //In translation mode, we display the add fastaction in item only if they don't have children. Else, the fastadd is at the bottom of the children zone.
    if ((in_array($type, array('criterion', 'profile')) && !$node_array['data']->has_children) || ($type == 'product' && ($_SESSION['current_path'] != 'home' || $nid == 0))) {
      $actions['add'] = 'add';
    }

    //Test if we can fastedit the item, based on the information of the database query function.
    $test = False;

    //We don't display edit nor remove if the security test in request_db failed or if we are in a add zone.
    if (isset($node_array['no-edit']) || isset($node_array['add'])) {
      $test = True;
    }

    if (module_exists('wikicompare_translation')) {
      //If the user can fastedit the main language node or the translation node, then the fastedit item must be displayed.
      wikicompare_translation_fastaction_items_test($test, $node_array);
    }

    //If the user can display the fastedit item.
    if ($test == False) {
      $actions['edit'] = 'edit';

      //If the user can display the fastremove item.
      if (!isset($node_array['no-remove'])) {
        $actions['remove'] = 'remove';
      }
    }
  }

  //The space between the node detail and the fastaction items.
  $output = ' ';

  foreach ($actions as $action) {
    //Create the image link to edit the node
    $img = theme('image', array(
      'path' => drupal_get_path('theme',$GLOBALS['theme']) . '/images/fast' . $action . '.png',
      'alt' => 'Link to ' . $action . ' ' . $type . ' ' . $nid,
      'height' => '100%',
    ));
    //Create the link. The html = True indicate that the title of the link contain html.
    $img_link = l($img, 'wikicompare-table-fastaction-form-callback/nojs', array('attributes' => array('id' => $type . '-' . $action . '-link-' . $nid, 'class' => array('ajaxlink','fastaction-item'), 'action' => 'open-dialog', 'nid' => $nid, 'parent-id' => $node_array['data']->parent_id, 'ntype' => $type, 'dialog-action' => 'fastaction', 'fastaction' => $action, 'side' => 'right'), 'html' => True));
    $output .= $img_link;
  }

  //Return the html code.
  return $output;

}



/**
 * Ajax callback function called by javascript to display the fastaction form.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_table_fastaction_form_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Get some variables from javascript.
  $nid = $_POST['nid'];
  $type = $_POST['type'];
  $fastaction = $_POST['fastaction'];

  $commands = array();

  $output = '<form id="form-fastaction-' . $nid . '" class="form-fastaction">';

  //If we want to fastremove the node.
  if ($fastaction == 'remove') {
    //Display a confirmation message
    $label = array(
      '#markup' => t('Do you really want to remove this ') . $type . '<br/>',
    );
    $output .= render($label);
    $output .= '<span id="wikicompare-old-parent-id" style="display:none;">' . $_POST['parent_id'] . '</span>';
    $output .= '<span id="wikicompare-parent-id" style="display:none;">' . $_POST['parent_id'] . '</span>';

  //Else, display the form.
  } else {

    //Preparing the new object, in case of a node creation.
    $node = new stdClass;
    $node->type = $type;
    $readonly = False;
    $tnode = new stdClass;
    $readonly_translation = False;

    //If we are fastediting the node, we load its informations from database.
    if ($fastaction == 'edit') {
      //Load node from database.
      $node = node_load($nid);

      //Test if we can fastedit the main language node.
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
        //Get tnode and test if we can fastedit it.
        wikicompare_translation_fastaction_get_tnode($tnode, $readonly_translation, $node);
      }

    //If we are just fastadding a node, then we insert an hidden span containing the id of the parent.
    } else {
      $output .= '<span id="wikicompare-old-parent-id" style="display:none;">' . $nid . '</span>';
      $output .= '<span id="wikicompare-parent-id" style="display:none;">' . $nid . '</span>';
    }

    $form = array();
    $form_state = array();
    //Call the generic function which will build the form. $output will be updated with the form.
    wikicompare_build_form($_POST, 'fastaction', $form, $form_state, $type, $output, $nid, $fastaction, $node, $readonly, $tnode, $readonly_translation);

  }

  //Add an error zone which will be filled if we badly submit the form.
  $output .= '<div id="form-fastaction-error-zone"></div>';

  //Add the submit button, followed by his hidden ajax link.
  $output .= '<div class="button-wrapper"><div  id="compute-table-button" link="form-fastaction-submit-link-' . $nid . '" class="button wikicompare-button"><input id="form-fastaction-submit-' . $nid . '" type="submit" value="Confirm" class="form-fastaction-submit button"/></div></div>';
  $submit_link = array(
    '#type' => 'link',
    '#title' => 'submit',
    '#href' => 'wikicompare-table-fastaction-submit-callback/nojs/',
    '#id' => 'form-fastaction-submit-link-' . $nid ,
    '#attributes' => array(
      'class' => 'ajaxlink',
      'action' => 'submit-fastaction-form',
      'style' => 'display:none',
      'nid' => $nid,
      'ntype' => $type,
      'fastaction' => $fastaction,
      'side' => $_POST['side']
    )
  );
  $output .= render($submit_link);
  $output .= '</form>';

  $output .= '<br/>';

  $commands[] = ajax_command_append('#' . $_POST['side'] . '-dialog-content', $output);

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}



/**
 * Ajax callback function called by javascript to submit the fastaction form.
 *
 * @param $method
 *   Indicate if the call was made with javascript or if it's a simple browser call.
 *
 * @return $page
 *   Array containing the instructions for the javascript.
 */
function wikicompare_table_fastaction_submit_response($method = 'ajax'){

  //If javascript isn't activated on the browser, the first argument will not be transformed in ajax value. In such case, we just redirect to an error message.
  if ($method != 'ajax') {
    $output = NOJS_MESSAGE;
    return $output;
  }

  //Initialize settings with the variable from javascript.
  $settings = wikicompare_initialize_settings($_POST);

  //Security to avoid firebug hacking while the user is anonymous.
  if (user_is_anonymous() == True) {
    return "You can only use fastaction if you are logged";
  }

  //Get some variables from javascript.
  $type = $_POST['type'];
  $fastaction = $_POST['action'];

  //If we are not fastadding, we get the information from database to proceed an ultimate check of the user right. This should protect us from firebug hacking.
  $from_db_record = array();
  if ($_POST['nid']) {
    $from_db = request_db($type, array('nids' => array($_POST['nid'])), wikicompare_initialize_settings(array('fastaction' =>  1)));
    $from_db_record = $from_db[$_POST['nid']];
  }

  $commands = array();
  //If we are fastremoving, and if the user has the right for it.
  if ($fastaction == 'remove' && !isset($from_db_record['no-remove'])) {

    //Delete the node.
    node_delete($_POST['nid']);

    //Display a confirmatio message.
    $commands[] = ajax_command_html('#form-fastaction-' . $_POST['nid'], 'The node is correctly removed');

    //Close the dialog
    $commands[] = ajax_command_invoke('#' . $_POST['side'] . '-dialog-close', 'click', array());

    //Update the table.
    $commands = array_merge($commands, wikicompare_control_table($settings));

  //If we are fastadding / fasteditting and the user has the right for it.
  } elseif (!isset($from_db_record['no-edit'])) {

    $missing_field = FALSE;

    switch ($fastaction) {
      //Create a new node.
      case 'add':
        $node = new stdClass();
        $node->type = $type;
        $node->language = language_default('language');
        node_object_prepare($node);
        $node->comment = 2;
        break;
      //Load the actual node, and say we are creating a new revision.
      case 'edit':
        $node = node_load($_POST['nid']);
        $node->revision = 1;
        break;
    }

    $tnode = new stdClass();

    if (module_exists('wikicompare_translation')) {
      //Initiate the tnode according to the information from javascript.
      wikicompare_translation_fastaction_submit_init_tnode($tnode, $_POST, $fastaction);
    }

    //Fields relatives to all node type except evaluation.
    if ($type != 'evaluation') {
      //Assign the field, or mark the field as missing if empty.
      if ($_POST['title'] != NULL) {
        $node->title = $_POST['title'];
      } else {
        $missing_field = TRUE;
      }

      if (module_exists('wikicompare_translation')) {
        //Add the translated fields in the node which will be submited.
        wikicompare_translation_fastaction_submit_element($tnode, $_POST, 'title', 'title', $fastaction);
      }

      //Assign parent.
      if ($_POST['parent_id'] != 0) {
            $node->wikicompare_parent_id['und'][0]['target_id'] = $_POST['parent_id'];
            $node->wikicompare_parent_id['und'][0]['target_type'] = "node";
      } else {
        $node->wikicompare_parent_id['und'] = NULL;
      }

      //Assign sequence.
      if ($_POST['sequence'] != NULL) {
        $node->wikicompare_sequence['und'][0]['value'] = $_POST['sequence'];
      } else {
        $missing_field = TRUE;
      }

      //Assign state.
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
    } */

    $donotupdate = False;
    if (module_exists('wikicompare_inherit_product')) {
      //Assign inherit product specific fields.
      wikicompare_inherit_product_fastaction_submit_element($node, $donotupdate, $_POST);
    }

    //Product specific fields.
    if ($type == 'product') {
      //Assign comparable field.
      if ($_POST['product_comparable'] != NULL) {
        $node->wikicompare_comparable['und'][0]['value'] = $_POST['product_comparable'];
      } else {
        $missing_field = TRUE;
      }

      //Assign infofields.
      foreach ($_POST['fastaction_infofields'] as $infofield) {
        $infofield_name = 'wikicf_' . $infofield['name'];
        if ($infofield['value'] != NULL || !$infofield['required']) {
          $infofield_array = array();
          $infofield_array['und'][0]['value'] = $infofield['value'];
          $node->$infofield_name = $infofield_array;
        } else {
          $missing_field = TRUE;
        }
      }
    }

    //Criterion specific fields.
    if ($type == 'criterion') {

      //Assign type field.
      if ($_POST['criterion_type'] != NULL) {
        $node->wikicompare_type['und'][0]['value'] = $_POST['criterion_type'];
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

      //Assign weight field.
      if ($_POST['weight'] != NULL) {
        $node->wikicompare_weight['und'][0]['value'] = $_POST['weight'];
      } else {
        $missing_field = True;
      }

      //Assign suggest field.
      $user = $GLOBALS['user'];

      $node->wikicompare_suggest['und'][0]['value'] = 0;
      if (user_access('administer wikicompare', $user)) {
        if ($_POST['suggest'] != NULL) {
          $node->wikicompare_suggest['und'][0]['value'] = $_POST['suggest'];
        } else {
          $missing_field = True;
        }
      }

    }

    //evaluation specific field.
    if ($type == 'evaluation') {
      //Assign support field.
      if ($donotupdate == False) {
          if ($_POST['support'] == 'true') {
            $node->wikicompare_support['und'][0]['value'] = 1;
          } else {
            $node->wikicompare_support['und'][0]['value'] = 0;
          }
      }
    }

    if (module_exists('wikicompare_profiles')) {
      //Assign profile specific fields.
      wikicompare_profiles_fastaction_submit_after($node, $type, $_POST);
    }

    if (module_exists('wikicompare_translation')) {
      //Replace the node submitted by the tnode if it's the choice of the user.
      wikicompare_translation_fastaction_submit_after($node, $tnode, $_POST, $fastaction);
    }

    //Assign the revision message.
    $node->log = $_POST['revision'];

    //If no required field are missing.
    if ($missing_field == FALSE) {

      //We save the new revision.
      node_save($node);

      //We auto publish the latest submitted revision of the node.
      _revisioning_publish_latest_revision($node);

      //If the submitted node isn't in published state, then we ensure that his state is displayed in the table so the user can immmediately see the node.
      if ($type != 'evaluation') {
        if (in_array($_POST['state'], array('new', 'incomplete', 'submitted'))) {
          $commands[] = ajax_command_invoke('#checkbox-draft-items', 'attr', array('checked', 'checked'));
        } elseif (in_array($_POST['state'],array('rejected', 'disactivated'))) {
          $commands[] = ajax_command_invoke('#checkbox-closed-items', 'attr', array('checked', 'checked'));
        }
      }

      //Close the dialog
      $commands[] = ajax_command_invoke('#' . $_POST['side'] . '-dialog-close', 'click', array());

      //Prepare the new nid for the control function, so it can detect the missing nid.
      if ($fastaction == 'add') {
        $settings['control_nid'] = $node->nid;
      }

      //Update the table.
      $commands = array_merge($commands, wikicompare_control_table($settings));

    //If a required field is missing.
    } else {
      //Display an error message in error zone.
      $commands[] = ajax_command_html('#form-fastaction-error-zone', 'Some required fields are missing.');
    }

  //If the security test failed.
  } else {
    $commands[] = ajax_command_html('#form-fastaction-' . $_POST['nid'], 'The node was modified by someone else before your confirmation');
  }

  //Return the javascript commands.
  $page = array('#type' => 'ajax', '#commands' => $commands);
  return $page;

}





/**
 * Get the possible value of the state, by checking the user rights and the actual state.
 *
 * @param $nid
 *   The nid of the node.
 *
 * @param $current_state
 *   The actual state of the node.
 *
 * @return $options
 *   Array containing the options available in the select field.
 */
function wikicompare_state_get_options($nid, $current_state) {

  $user = $GLOBALS['user'];

  //Get the options in constant.
  $label_options = unserialize(WIKICOMPARE_STATE_OPTIONS);

  //Check if the user have power right on the node.
  $has_right = False;
  if (wikicompare_test_access_node('test', array($nid), $user->uid)  || user_access('moderate wikicompare', $user) || $user->uid == 1) {
    $has_right = True;
  }

  //Add item to options array, following the current state of the node.
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
 * Implements hook_revisioning_access_node_revision().
 *
 * Since auto-publish use directly revisioning_user_node_access, we can't alter his result. Therefore, we can't use the auto-publish criterion for now because since everyone has the publish revision right, everyone will auto-publish even those who are not power users.
 *
 * @param $revision_op
 *   Indicate which operation the module is doing, and so the access right to check.
 *
 * @param $node
 *   The object node we try to access.
 *
 * @return $test or $users
 *   Return either a boolean to give or not access, or an array with the users of the node.
 */
function wikicompare_revisioning_access_node_revision($revision_op, $node) {

  //Only the access right relative to publishing need to be check.
  if ($revision_op == 'publish revisions') {

    $uid = $GLOBALS['user']->uid;

    $test = False;
    //There is no problem when we create the node because there is no revision to publish yet.
    if (isset($node->nid)) {
      //Call the generic function which will test the access to the node.
      $test = wikicompare_test_access_node('test', array($node->nid), $uid);
    }

    //Return the boolean to revisionning module.
    if (($test == False) && ($uid != 1)) {

      return NODE_ACCESS_DENY;
    } else {
      return True;
    }

  }

}



/**
 * Generic function which will test the power users of a node to either give access to publish right or return the users to the children of the node.
 *
 * @param $action
 *   The reason we call the function, either a boolean test or to get the users of the node.
 *
 * @param $nids
 *   An array containing the nids of the nodes to test.
 *
 * @param $uid
 *   The uid to test
 *
 * @return
 */
function wikicompare_test_access_node($action, $nids, $uid=NULL) {

    $test = False;
    $users = array();

    if (empty($nids)) {
      return False;
    }

    //The moderator get instant access.
    if (user_access('moderate wikicompare')) {
      $test = True;
    }

    //Get the users linked to the node from parents.
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'type', 'type');
    $query->addField('f', 'wikicompare_user_from_parent_ids_target_id', 'uid');
    $query->join('field_revision_wikicompare_user_from_parent_ids', 'f', 'n.vid = f.revision_id');
    $query->condition('n.nid', $nids, 'in');
    if ($action == 'test') {
      //Test our user.
      $query->condition('f.wikicompare_user_from_parent_ids_target_id', $uid);
    }
    $result = $query->execute();
    foreach ($result as $record) {
      if ($action == 'test') {
        //Grant access if the user is in the node.
        $test = True;
      } else {
        //Return the users.
        $users[$record->nid][$record->uid] = array(
          'entity_type' => 'node',
          'bundle' => $record->type,
          'deleted' => 0,
          'entity_id' => 0,
          'revision_id' => 0,
          'language' => 'und',
          'delta' => 0,
          'wikicompare_user_from_parent_ids_target_id' => $record->uid,
        );
      }
    }

    //Get the users directly linked in the node.
    $query = db_select('node', 'n');
    $query->addField('n', 'nid', 'nid');
    $query->addField('n', 'type', 'type');
    $query->addField('f', 'wikicompare_user_ids_target_id', 'uid');
    $query->join('field_revision_wikicompare_user_ids', 'f', 'n.vid = f.revision_id');
    $query->condition('n.nid', $nids, 'in');
    if ($action == 'test') {
      //Test our user.
      $query->condition('f.wikicompare_user_ids_target_id', $uid);
    }
    $result = $query->execute();
    foreach ($result as $record) {
      if ($action == 'test') {
        //Grant access if the user is in the node.
        $test = True;
      } else {
        //Return the users.
        $users[$record->nid][$record->uid] = array(
          'entity_type' => 'node',
          'bundle' => $record->type,
          'deleted' => 0,
          'entity_id' => 0,
          'revision_id' => 0,
          'language' => 'und',
          'delta' => 0,
          'wikicompare_user_from_parent_ids_target_id' => $record->uid,
        );
      }
    }

    //Return the result.
    if ($action == 'test') {
      return $test;
    } else {
      return $users;
    }

}

?>