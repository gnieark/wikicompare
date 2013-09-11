<?php
/**
 * @file
 * Define the wikicompare frontend view.
 */
 require_once drupal_get_path('module', 'wikicompare') . '/wikicompare.module';
 

function wikicompare_testing() 
{

?>
<table>
<tr>
  <td style="width: 420px;">Profiles List<br><a href="#">admin</a></td><td style="width: 420px;">column2</td><td style="width: 420px;">column3</td>
 </tr>
</table>
<?php }

 /*
function wikicompare_sidebar() {

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
  } */
  ?>