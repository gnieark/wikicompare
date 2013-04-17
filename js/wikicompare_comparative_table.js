(function ($) {


      //Set global variable
      fastedit_status = 0;
      manual_selected_feature_ids = {};
      selected_feature_ids = {};
      selected_need_ids = {};

  

//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareComparativeTable = {
  attach: function (context, settings) {


    $('#edit-need-state:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      fastedit_status = settings['wikicompare_needs']['fastedit_status'];
      selected_feature_ids = settings['wikicompare_needs']['selected_feature_ids'];
    });


    //Ajaxify the compared link
    $('.list_item_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');


      if ($(this).hasClass('feature')) {
        type = 'feature';
      } else if ($(this).hasClass('compared')) {
        type = 'compared';
      } else if ($(this).hasClass('need')) {
        type = 'need';
      }

      if ($(this).hasClass('compared_main_table')) {
        subaction = 'compared_main_table';
      } else if ($(this).hasClass('select_multi_dialog')) {
        subaction = 'select_multi_dialog';
      } else if ($(this).hasClass('select_simple_dialog')) {
        subaction = 'select_simple_dialog';
      }

      if ($(this).hasClass('computed')) {
        $(this).click(function() {
          var patt = /[0-9]+/g;
          var node_id = patt.exec(link_id);
          if (!$(this).hasClass('displayed')) {
            $('.feature_children_computed_' + node_id).show();
            $(this).addClass('displayed');
          } else { 
            remove_children_tree(node_id, '#feature_link_', '.feature_children_computed_', false);
          }
          return false;
        });
      } else {
        Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'expand_list_children', type, subaction);
      }



    });

    //Dynamize the checkbox so it add the item in the return and mark the parent with css class
    $('.itemlist_checkbox:not(.event_set)').addClass('event_set').each(function () {
      //Recover the node_id
      var patt = /[0-9]+/g;
      var node_id = patt.exec($(this).attr('id'))[0];
      //Set the onclick event
      $('#' + $(this).attr('id')).click(function() {
       
        if ($(this).hasClass('need')) {
          if ($(this).attr('checked')) {
            selected_need_ids[node_id] = node_id;

          } else {
            delete selected_need_ids[node_id];
          }
        } else {
          if ($(this).attr('checked')) {
            selected_feature_dialog_ids[node_id] = node_id;
          } else {
            delete selected_feature_dialog_ids[node_id];
          }
        }
      });
    });

    $('#initialize_selected_feature_dialog_ids:not(.event_set)').addClass('event_set').each(function () {

        if ($(this).text() == 'manual') {
          selected_feature_dialog_ids = manual_selected_feature_ids;
        } else {

          selected_feature_dialog_ids = selected_feature_ids;
        }

    });


    $('.select_simple_dialog:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      type = $('#dialog_type').text();

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'select_dialog', type);
    });
    
    $('#submit_dialog_button:not(.event_set)').addClass('event_set').each(function () {
      $('#' + $(this).attr('id')).click(function() {
        $('#submit_dialog_link').click();
        return false;
      });
    });

    $('#submit_dialog_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'submit_dialog');
    });

    $('.clear_link:not(.event_set)').addClass('event_set').each(function () {
      $(this).click(function() {
        type = $(this).attr('type');
        $('#form_selected_parent').html('No parent');
        $('#edit-' + type + '-parent-' + type).html('<input type="text" size="60" value="" name="' + type + '_parent_' + type + '[und][0][target_id]">');
        $('#parent_id').empty();
        return false;
      });
    });



    //Ajaxify the compute table link
    $('#reset_table_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'reset_table');
    });


    $('#compute_table_button:not(.event_set)').addClass('event_set').each(function () {
      $('#' + $(this).attr('id')).click(function() {
        $('#compute_table_link').click();
        return false;
      });
    });


    //Ajaxify the compute table link
    $('#compute_table_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'compute_table');
    });

    //Ajaxify the compute table link
    $('#make_cleaning_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'make_cleaning');
    });


    //Ajaxify the feature link
    $('.feature_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      if ($('#comparative_table').hasClass('computed')) {
        $(this).click(function() {

          var patt = /[0-9]+/g;
          var node_id = patt.exec(link_id);
          if (!$('#' + link_id).hasClass('displayed')) {
            $('.feature_children_' + node_id).show();
            $('#' + link_id).addClass('displayed');
          } else {
            remove_children_tree(node_id, '.feature_link_children_', '.feature_children_', true);;
            $('#' + link_id).removeClass('displayed');
          }
          return false;
        });
      } else {
        Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'expand_row_children');
      }
    });





    //Ajaxify the compared checkbox link
    $('.compared_checkbox_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'toogle_compared_checkbox');
    });


    //Dynamize the compared checkbox so it call the compared checkbox link on click
    $('.compared_checkbox:not(.event_set)').addClass('event_set').each(function () {
      //Recover the compared_id to find later the checkbox_link id
      var patt = /[0-9]+/g;
      var compared_id = patt.exec($(this).attr('id'));
      //Set the onclick event
      $('#' + $(this).attr('id')).click(function() {
        $(this).attr('disabled', 'disabled');
        $('#compared_checkbox_link_' + compared_id).click();
      });
    });

    //Dynamize the toogle fast edit link to display the elements add/edit/remove.
    $('#toogle_fastedit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {


      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');



      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'toogle_fastedit');

    });

    
    //Dynamize the compared add fastedit element.
    $('.fastedit_item:not(.ajax-processed)').addClass('ajax-processed').each(function () {
    
      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
      
      if ($(this).hasClass('compared_add_link')) {
        type = 'compared';
        subaction = 'add';
      } else if ($(this).hasClass('compared_edit_link')) {
        type = 'compared';
        subaction = 'edit';
      } else if ($(this).hasClass('compared_remove_link')) {
        type = 'compared';
        subaction = 'remove';
      } else if ($(this).hasClass('feature_add_link')) {
        type = 'feature';
        subaction = 'add';
      } else if ($(this).hasClass('feature_edit_link')) {
        type = 'feature';
        subaction = 'edit';
      } else if ($(this).hasClass('feature_remove_link')) {
        type = 'feature';
        subaction = 'remove';
      } else if ($(this).hasClass('implementation_edit_link')) {
        type = 'implementation';
        subaction = 'edit';
      } else if ($(this).hasClass('need_add_link')) {
        type = 'need';
        subaction = 'add';
      } else if ($(this).hasClass('need_edit_link')) {
        type = 'need';
        subaction = 'edit';
      } else if ($(this).hasClass('need_remove_link')) {
        type = 'need';
        subaction = 'remove';
      }


      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'show_fastedit_form', type, subaction);
    });
    
    $('.form_fastedit').submit(function () {
      //Recover the compared_id by using a regular expression on the compared_link
      var patt = /[0-9]+/g;
      var node_id = patt.exec($(this).attr('id'));
      
      if ($(this).hasClass('form_compared_fastadd')) {
        type = 'compared';
        subaction = 'add';
      } else if ($(this).hasClass('form_compared_fastedit')) {
        type = 'compared';
        subaction = 'edit';
      } else if ($(this).hasClass('form_compared_fastremove')) {
        type = 'compared';
        subaction = 'remove';
      } else if ($(this).hasClass('form_feature_fastadd')) {
        type = 'feature';
        subaction = 'add';
      } else if ($(this).hasClass('form_feature_fastedit')) {
        type = 'feature';
        subaction = 'edit';
      } else if ($(this).hasClass('form_feature_fastremove')) {
        type = 'feature';
        subaction = 'remove';
      } else if ($(this).hasClass('form_implementation_fastedit')) {
        type = 'implementation';
        subaction = 'edit';
      } else if ($(this).hasClass('form_need_fastadd')) {
        type = 'need';
        subaction = 'add';
      } else if ($(this).hasClass('form_need_fastedit')) {
        type = 'need';
        subaction = 'edit';
      } else if ($(this).hasClass('form_need_fastremove')) {
        type = 'need';
        subaction = 'remove';
      }
      
      $('#form_' + type + '_fast' + subaction + '_submit_link_' + node_id).click();
      //Block the page loading
      return false;
    });
       

    $('.fastform_cancel_button:not(.event_set)').addClass('event_set').each(function () {
      $(this).click(function() {
        $('#make_cleaning_link').click();
        return false;
      });
    }); 
    
    
    
    //Dynamize the compared add fastedit submit link.
    $('.form_fastedit_submit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {
    
      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      if ($(this).hasClass('form_compared_fastadd_submit_link')) {
        type = 'compared';
        subaction = 'add';
      } else if ($(this).hasClass('form_compared_fastedit_submit_link')) {
        type = 'compared';
        subaction = 'edit';
      } else if ($(this).hasClass('form_compared_fastremove_submit_link')) {
        type = 'compared';
        subaction = 'remove';
      } else if ($(this).hasClass('form_feature_fastadd_submit_link')) {
        type = 'feature';
        subaction = 'add';
      } else if ($(this).hasClass('form_feature_fastedit_submit_link')) {
        type = 'feature';
        subaction = 'edit';
      } else if ($(this).hasClass('form_feature_fastremove_submit_link')) {
        type = 'feature';
        subaction = 'remove';
      } else if ($(this).hasClass('form_implementation_fastedit_submit_link')) {
        type = 'implementation';
        subaction = 'edit';
      } else if ($(this).hasClass('form_need_fastadd_submit_link')) {
        type = 'need';
        subaction = 'add';
      } else if ($(this).hasClass('form_need_fastedit_submit_link')) {
        type = 'need';
        subaction = 'edit';
      } else if ($(this).hasClass('form_need_fastremove_submit_link')) {
        type = 'need';
        subaction = 'remove';
      }
      
      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'submit_fastedit_form', type, subaction);
    });

    
    function build_ajax_link(link_id, object, action, type=false, subaction=false) {

      //Recover the node_id by using a regular expression on the link_id
      var patt = /[0-9]+/g;
      var node_id = patt.exec(link_id);

    
      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(object).attr('href')) {
        element_settings.url = $(object).attr('href');
        element_settings.event = 'click';
      }
      //Create the ajax event
      var ajax = new Drupal.ajax(link_id, object, element_settings);

      
      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal
      ajax.old_beforeSerialize = ajax.beforeSerialize;

      ajax.beforeSerialize = function (element, options) {  
        //We remove all hidded element so they can't perturb the computation
        $('.to_remove').remove();
        
        options.data.fastedit_status = fastedit_status;
        
        manage_displayed_flag = false;
        send_node_id = false;
        send_type = false;
        send_computed_status = false;
        send_compareds = false;
        send_compareds_columns = false;
        send_features = false;
        send_implementations = false;
        send_needs = false;
        send_manual_selected_features = false;
        send_selected_needs = false;
        send_states_to_display = false;
        send_forbidden_nid = false;
        send_container = false;
        make_cleaning = false;
        
        if (action == 'expand_list_children') {
          send_node_id = true;
          manage_displayed_flag = true;
          send_compareds_columns = true;
          send_forbidden_nid = true;
          options.data.type = type;
          options.data.subaction = subaction;

          if ($('#' + link_id).hasClass('dialog')) {
            options.data.dialog = true;
            if (subaction == 'select_multi_dialog') {
              options.data.selected_feature_ids = selected_feature_dialog_ids;
            } 
          } else {
            make_cleaning = true;
          }

          if ($('#' + link_id).hasClass('need')) {
            send_selected_needs = true;
          }
        }
        
        if (action == 'expand_row_children') {
          send_node_id = true;
          manage_displayed_flag = true;
          send_compareds_columns = true;
          send_states_to_display = true;
          make_cleaning = true;
        }
        
        if (action == 'toogle_compared_checkbox') {
          send_node_id = true;
          send_computed_status = true;
          manage_displayed_flag = true;
          send_features = true;
          make_cleaning = true;
        }

        if (action == 'select_dialog') {
           send_node_id = true;
           send_type = true;
           send_container = true;
        }

        if (action == 'submit_dialog') {
          if ($('#initialize_selected_feature_dialog_ids').text() == 'manual') {
            manual_selected_feature_ids = selected_feature_dialog_ids;
            send_manual_selected_features = true;
          } else {
            selected_feature_ids = selected_feature_dialog_ids;
            options.data.selected_feature_ids = selected_feature_dialog_ids;
          }
          send_container = true;
        }
  
        if (action == 'compute_table') {
          send_compareds_columns = true;
          send_manual_selected_features = true;
          send_selected_needs = true;
          send_states_to_display = true;
          make_cleaning = true;
        }

        if (action == 'reset_table') {
          send_compareds_columns = true;
          send_states_to_display = true;
          options.data.reset = true;
        }
     
        if (action == 'toogle_fastedit') {
          manage_displayed_flag = true;
          send_compareds = true;
          send_features = true;
          send_implementations = true;
          send_needs = true;
          make_cleaning = true;
        }
        
        
        if (action == 'show_fastedit_form') {
          send_node_id = true;
          manage_displayed_flag = true;

          if ($('#' + link_id).hasClass('displayed')) {
            make_cleaning = true;
          }
          
          send_type = true;
          options.data.fastaction = subaction;
        }
     
        if (action == 'submit_fastedit_form') {
          send_node_id = true;
          send_type = true;
          make_cleaning = true;
          options.data.fastaction = subaction;
          
          if (type != 'implementation') {
            options.data.title = $('#form_' + type + '_fast' + subaction + '_title_' + node_id).val();
            options.data.title_translation = $('#form_' + type + '_fast' + subaction + '_title_' + node_id + '_translation').val();
            options.data.parent_id = $('#parent_id').text();
          }
          options.data.description = $('#form_' + type + '_fast' + subaction + '_description_' + node_id).val();
          options.data.description_translation = $('#form_' + type + '_fast' + subaction + '_description_' + node_id + '_translation').val();
          
          if (type == 'feature') {
            options.data.feature_type = $('#form_' + type + '_fast' + subaction + '_type_' + node_id).val();
            options.data.guidelines = $('#form_' + type + '_fast' + subaction + '_guidelines_' + node_id).val();
            options.data.guidelines_translation = $('#form_' + type + '_fast' + subaction + '_guidelines_' + node_id + '_translation').val();
            options.data.weight = $('#form_' + type + '_fast' + subaction + '_weight_' + node_id).val();
            options.data.state = $('#form_' + type + '_fast' + subaction + '_state_' + node_id).val();
          }
          
          if (type == 'implementation') {
            options.data.support = $('#form_' + type + '_fast' + subaction + '_support_' + node_id).val();
          }

          if (type == 'need') {
            var need_feature_ids = {};
            var i = 0;
            $('.need_feature').each(function (key, value) {
              //var need_feature_id = $('#' + $(this).attr('id'));
              //var patt = /[0-9]+/g;
              need_feature_ids[$(this).text()] = $(this).text();
              i = i + 1;
            });
            //Add them in the ajax call variables
            options.data.need_feature_ids = need_feature_ids;

            options.data.state = $('#form_' + type + '_fast' + subaction + '_state_' + node_id).val();
          }
          options.data.revision = $('#form_' + type + '_fast' + subaction + '_revision_' + node_id).val();
          options.data.selectnode = $('#form_' + type + '_fast' + subaction + '_selectnode_' + node_id).val();
        }


        if (action == 'make_cleaning') {
          send_computed_status = true;
          send_compareds_columns = true;
          send_implementations = true;
          send_selected_features = true;
          send_states_to_display = true;

          var compared_ids = new Array();
          var i = 0;
          $('.compared_item').each(function (key, value) {
            var patt = /[0-9]+/g;
            compared_ids[i] = new Array();
            compared_id = patt.exec($(this).attr('id'))[0];
            //Not using associative array because we shall not remove doublon. We need to make the security check on each element in the page.
            compared_ids[i][0] = compared_id;
            if ($(this).parent().parent().parent().hasClass('compared_children')) {
              parent = $(this).parent().parent().parent().attr('id');
              compared_ids[i][1] = patt.exec(parent)[0];
            }
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.compared_ids = compared_ids;

          var compared_displayed_ids = new Array();
          var i = 0;
          $('.compared_main_table').each(function (key, value) {
            if ($(this).hasClass('displayed')) {
              var patt = /[0-9]+/g;
              compared_displayed_ids[i] = patt.exec($(this).attr('id'))[0]
              i = i + 1;
            }
          });
          //Add them in the ajax call variables
          options.data.compared_displayed_ids = compared_displayed_ids;

          var feature_ids = new Array();
          var i = 0;
          $('.feature_row').each(function (key, value) {
            var patt = /[0-9]+/g;
            feature_ids[i] = new Array();
            feature_id = patt.exec($(this).attr('id'))[0];
            //Not using associative array because we shall not remove doublon. We need to make the security check on each element in the page.
            feature_ids[i][0] = feature_id;
            //The only numeric value in feature row class is the parent id
            if (patt.test($(this).attr('class'))) {
              //I don't know why, but I need to remake the patt, the patt.exec will otherwise not work  
              var patt = /[0-9]+/g;
              parent_id = patt.exec($(this).attr('class'));
              feature_ids[i][1] = parent_id[0];
            }
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.feature_ids = feature_ids;

          var feature_displayed_ids = new Array();
          var i = 0;
          $('.feature_link').each(function (key, value) {
            if ($(this).hasClass('displayed')) {
              var patt = /[0-9]+/g;
              feature_displayed_ids[i] = patt.exec($(this).attr('id'))[0]
              i = i + 1;
            }
          });
          //Add them in the ajax call variables
          options.data.feature_displayed_ids = feature_displayed_ids;

          var need_ids = new Array();
          var i = 0;
          $('.need_item').each(function (key, value) {
            var patt = /[0-9]+/g;
            need_ids[i] = new Array();
            need_id = patt.exec($(this).attr('id'))[0];
            //Not using associative array because we shall not remove doublon. We need to make the security check on each element in the page.
            need_ids[i][0] = need_id;
            if ($(this).parent().parent().parent().hasClass('need_children')) {
              parent = $(this).parent().parent().parent().attr('id');
              need_ids[i][1] = patt.exec(parent)[0];
            }
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.need_ids = need_ids;

          var need_displayed_ids = new Array();
          var i = 0;
          $('.list_item_link:.need').each(function (key, value) {
            if ($(this).hasClass('displayed')) {
              var patt = /[0-9]+/g;
              need_displayed_ids[i] = patt.exec($(this).attr('id'))[0]
              i = i + 1;
            }
          });
          //Add them in the ajax call variables
          options.data.need_displayed_ids = need_displayed_ids;


        }
        
        if (manage_displayed_flag == true) {
          //Check if the column is already displayed
          options.data.action = '';
          if (!$('#' + link_id).hasClass('displayed')) {
            options.data.action = 'display';
          }
        }

        if (send_node_id == true) {
          //Add the clicked node in argument
          options.data.node_id = node_id[0];
        }

        if (send_type == true) {
          options.data.type = type;
        }

        if (send_computed_status == true) {
          if ($('#comparative_table').hasClass('computed')) {
            options.data.computed = 1;
          } else {
            options.data.computed = 0;
          }
        }
        
        if (send_compareds == true) {
          //Recover all compared columns displayed in the table to send their id to drupal
          var compared_ids = new Array();
          var i = 0;
          $('.compared_item').each(function (key, value) {
            var column_id = $('#' + $(this).attr('id'));
            var patt = /[0-9]+/g;
            compared_ids[i] = patt.exec($(this).attr('id'))[0];
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.compared_ids = compared_ids;
        }
        
        if (send_compareds_columns == true) {
          //Recover all compared columns displayed in the table to send their id to drupal, in the right order
          var compared_column_ids = new Array();
          var i = 0;
          $('.header_compared').each(function (key, value) {
            var column_id = $('#' + $(this).attr('id'));
            var patt = /[0-9]+/g;
            compared_column_ids[i] = patt.exec($(this).attr('id'))[0];
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.compared_column_ids = compared_column_ids;
        }
        
        if (send_features == true) {
          //Recover all feature row displayed in the table to send their id to drupal
          var feature_ids = new Array();
          var i = 0;
          $('.feature_row').each(function (key, value) {
            var row_id = $('#' + $(this).attr('id'));
            var patt = /[0-9]+/g;
            feature_ids[i] = patt.exec($(this).attr('id'))[0];
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.feature_ids = feature_ids;
        }
        
        if (send_implementations == true) {
          //Recover all implementation displayed in the table to send their id to drupal
          var implementation_ids = new Array();
          var i = 0;
          $('.implementation_cell').each(function (key, value) {
            var cell_id = $('#' + $(this).attr('id'));
            var patt = /[0-9]+/g;
            implementation_ids[i] = patt.exec($(this).attr('id'))[0];
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.implementation_ids = implementation_ids;
        }

        if (send_needs == true) {
          var need_ids = new Array();
          var i = 0;
          $('.need_item').each(function (key, value) {
            var need_id = $('#' + $(this).attr('id'));
            var patt = /[0-9]+/g;
            need_ids[i] = patt.exec($(this).attr('id'))[0];
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.need_ids = need_ids;
        }

        if (send_manual_selected_features == true) {
          //Recover all manually selected feature to send their id to drupal
          //Add them in the ajax call variables

          options.data.selected_feature_ids = manual_selected_feature_ids;
        }

        if (send_selected_needs == true) {
          options.data.selected_need_ids = selected_need_ids;
        }

        if (send_states_to_display == true) {
          var states = {};
          if ($('#checkbox-draft-items').attr('checked')) {
            states['draft'] = 'draft';
          }
          if ($('#checkbox-closed-items').attr('checked')) {
            states['closed'] = 'closed';
          }
          options.data.states = states;

        }

        if (send_forbidden_nid == true) {
          forbidden_nid = $('#forbidden_nid').text();
          options.data.forbidden_nid = forbidden_nid;
        }

        if (send_container == true) {
          container = $('#select_container').text();
          options.data.container = container;
        }
        
        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }
      
      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {
        //First launch regular success function
        this.old_success(response, status);



        dialog_text = '';
        if ($('#' + link_id).hasClass('dialog')) {
          dialog_text = 'dialog_';
        }
        
        if (action == 'toogle_fastedit') {
          if (fastedit_status == 0) {
            //Set the global variable
            fastedit_status = 1;
          //If we are hidding the items
          } else {
            //Set the global variable
            fastedit_status = 0;
            to_clean = true;
            $('.compared_add_link').remove();
            $('.compared_edit_link').remove();
            $('.compared_remove_link').remove();
            $('.feature_add_link').remove();
            $('.feature_edit_link').remove();
            $('.feature_remove_link').remove();
            $('.implementation_edit_link').remove();
            $('.need_add_link').remove();
            $('.need_edit_link').remove();
            $('.need_remove_link').remove();
          }
        }

        
        if (manage_displayed_flag == true) {
        
          if (!$('#' + link_id).hasClass('displayed')) {
            //Change the class link, so next time we click on this link it will hide the content
            $('#' + link_id).addClass('displayed');
  
            if (action == 'expand_list_children') {
              $('#' + type + '_children_' + dialog_text + node_id).slideDown();
            }
  
            if (action == 'expand_row_children') {
             
              //Display the children with slide animation
              $('.feature_children_' + node_id).show();
//TODO Les lignes s'affichent instantanement pour une raison qui m'echappe si je met un slideDown(). Utiliser la fonction suivante pour les afficher les unes apres les autres
//http://paulirish.com/2008/sequentially-chain-your-callbacks-in-jquery-two-ways/
/*
          (function shownext(jq){
            jq.eq(0).slideDown("slow", function(){
              (jq=jq.slice(1)).length && hidenext(jq);
            });
          })($(children_id))
*/
            
            }
            
            if (action == 'toogle_compared_checkbox') {    
              //Display the column with fade animation. We don't fade the header because of some bug with the current template, to check when we will have the final template.
              $('#header_compared_' + node_id).show();
              $('.implementation_compared_' + node_id).fadeIn();
            }
            
//TODO Repli des enfants, copier le fonctionnement sur les autres form ou supprimer la feature, le clean pourrait suffire
            if (action == 'show_fastedit_form') {
              if (type == 'need') {
                var need_feature_ids = {};
                var i = 0;
                $('.need_feature').each(function (key, value) {

                  //var need_feature_id = $('#' + $(this).attr('id'));
                  //var patt = /[0-9]+/g;
                  feature = $(this).text();

                  need_feature_ids[feature] = feature;
                  i = i + 1;
                });
                //Add them in the ajax call variables
                selected_feature_ids = need_feature_ids;

              }
              if ($('#compared_link_' + node_id).hasClass('displayed')) {
                $('#compared_link_' + node_id).click();
              }
            }
          } else {
          
            //Change the class link, so next time we click on this link it will display the content
            $('#' + link_id).removeClass('displayed');
          
            if (action == 'expand_list_children') {
              $('#' + type + '_children_' + dialog_text + node_id).slideUp();
            }
          
            if (action == 'expand_row_children') {
              //Hide the children with slide animation
              remove_children_tree(node_id, '.feature_link_children_', '.feature_children_', false);
              //Mark the children row so they will be remove at the next event. We can't do it now because otherwise it will crash the slide animation
              $('.feature_children_' + node_id).addClass('to_remove');
            }
          
            if (action == 'toogle_compared_checkbox') {   
              //Hide the column. We can't use animation because of the current template, to check when we will have the final template
              $('#header_compared_' + node_id).hide();
              $('.implementation_compared_' + node_id).hide();
              //Mark the column element so they will be remove at the next event. We can't do it now because otherwise it will crash the fade animation
              $('#header_compared_' + node_id).addClass('to_remove');
              $('.implementation_compared_' + node_id).addClass('to_remove');
            }
          

          }
          
        }
        
        if (make_cleaning == true) {
          $('#make_cleaning_link').click();
        }
      }

      return ajax;
    }
    
    
    function remove_children_tree(node_id, link_prefix, children_prefix, computed) {
      $(children_prefix + node_id).each(function(index) {
        var patt = /[0-9]+/g;
        var node_child_id = patt.exec($(this).attr('id'));
        remove_children_tree(node_child_id, link_prefix, children_prefix, computed);
      });
      //TODO replace with a slideUp()
      $(children_prefix + node_id).hide();
      //We need to remove the class when the row isn't deleted, especially when the table is computed
      $(link_prefix + node_id).removeClass('displayed');
      if (!computed == true) {
        $(children_prefix + node_id).addClass('to_remove');
      }
    }


  }
};


//TODO dans edit et remove, centraliser les controles dans une function
//TODO remplacer les if action par des case
//TODO mettre les securité dans la fonction submit pour edit et remove
//TODO ajuster les colspan automatiquement pour les line_fastedit
//TODO remplacer drupal_render par render
//TODO il faudrait générer les element du formulaire avec l'equivalent editable de field_view_field
//TODO bouger l'initialisation des variables globales dans un endroit plus sur
//TODO integrer un module de chat sur le site pourrait être sympa, suggestion https://github.com/cloudfuji/kandan
//TODO isoler le test ajax dans une fonction a part
//TODO remplacer new Array par [], voir si pas mieux d'utiliser des objets
//TODO Deplacer les variables globales utilisé dans ajax dans le javascript pour ne pas perturber le fonctionnement du tableau en cas de modification de la configuration
//TODO Trouver un moyen de sortir les requetes sql de la boucle update_compare_tree, pour un gain massif de performance
//TODO Remplacer les $key par $nid quand je les ai utilise en tant que tel
//TODO Pour faire marcher le dialog dans fastedit, je dois enlever le mot cle context dans simple_dialog.js -> "$('a.simple-dialog' + classes, context).each(function(event) {" Il faut trouver pourquoi pour que ça marche directement.
//TODO remplacer display par un flag true, pour recuperer le keyword action
//TODO Dans les fastaction, separer les class en type et action
//TODO remplacer event_set par listener_set
//TODO renommer toutes les fonctions en les demarrant par wikicompare
//TODO pour les fastedit, rajouter le type et le fastaction comme attribut du lien, comme on a fait pour clear
//TODO Quand on valide un formulaire, si statut est != published, cocher les cases status pour que l'enregistrement s'affiche quand même après la validation
//TODO verifier que les commentaires sont ouvert quand on créé via form et via fastedit, avec tous les users. C'est ok pour form, mais pas fastedit
//TODO Ajouter les required dans les fastedit. Gérer le cas quand un champ est manquant
//TODO deplacer autant de fonction que possible de l'after ajax dans le php. Sortir command et page de la boucle displayed, ex. toggle compared. Seul les fonctions communes à plusieurs appels doivent rester dans success.
//TODO statut et power users sur compared
//TODO Split the javascript file en deux
//TODO Centraliser fonction form et fastedit
})(jQuery);
