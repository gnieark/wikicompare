(function ($) {


      //Set global variable
      fastaction = 0;
      manual_selected_feature_ids = {};
      selected_feature_ids = {};
      selected_need_ids = {};

 

//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareComparativeTable = {
  attach: function (context, settings) {



    //Ajaxify the compared link
    $('.item_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
//      var nid = extract_nid(link_id)[0];


      var type = $(this).attr('ntype');
      var context = $(this).attr('context');


      if ($(this).hasClass('computed')) {

        $(this).click(function() {

          var nid = extract_nid(link_id);
          if (!$(this).hasClass('displayed')) {
            $('.feature_' + context + '_child_' + nid).show();
            $(this).addClass('displayed');
          } else { 
            remove_children_tree(nid, '#feature_' + context + '_link_', '.feature_' + context + '_child_', false);
          }
          return false;
        });
      } else {
        action = 'expand_list_children';
        if (type == 'feature' && context == 'table') {
          action = 'expand_row_children';
        }

        Drupal.ajax[link_id] = build_ajax_link(link_id, this, action, type, context);
      }





    });

/*
    //Ajaxify the feature link
    $('.feature_table_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');


      //Active the code
      if ($('#comparative_table').hasClass('computed')) {
        $(this).click(function() {

          var nid = extract_nid(link_id);

          if (!$(this).hasClass('displayed')) {
            $('.feature_table_child_' + nid).show();
            $(this).addClass('displayed');
          } else {
            remove_children_tree(nid, '.feature_link_children_', '.feature_table_child_', true);;
            $(this).removeClass('displayed');
          }
          return false;
        });
      } else {
        Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'expand_row_children');
      }

    });
*/


    //Dynamize the checkbox so it add the item in the return and mark the parent with css class
    $('.itemlist_checkbox:not(.listener_set)').addClass('listener_set').each(function () {
      //Recover the nid
/*      var patt = /[0-9]+/g;
      var nid = patt.exec($(this).attr('id'))[0];
*/
      var link_id = $(this).attr('id');
      var nid = extract_nid(link_id)[0];

      //Set the onclick event
      $(this).click(function() {


       
//        if ($(this).hasClass('need')) {
        if ($(this).attr('ntype') == 'compared' && $(this).attr('context') == 'table') {

          $(this).attr('disabled', 'disabled');
          $('#compared_checkbox_link_' + nid).click();
        } else if ($(this).attr('ntype') == 'need') {
          if ($(this).attr('checked')) {
            selected_need_ids[nid] = nid;

          } else {
            delete selected_need_ids[nid];
          }
        } else {
          if ($(this).attr('checked')) {
            selected_feature_dialog_ids[nid] = nid;
          } else {
            delete selected_feature_dialog_ids[nid];
          }

        }
      });
    });

/*
    //Dynamize the compared checkbox so it call the compared checkbox link on click
    $('.compared_checkbox:not(.listener_set)').addClass('listener_set').each(function () {
      //Recover the compared_id to find later the checkbox_link id
      var patt = /[0-9]+/g;
      var compared_id = patt.exec($(this).attr('id'));

      var cid = extract_nid($(this).attr('id'));
      //Set the onclick event
      $(this).click(function() {
        $(this).attr('disabled', 'disabled');
        $('#compared_checkbox_link_' + cid).click();
      });
    });
*/

    //Ajaxify the compared checkbox link
    $('.simple_ajaxlink:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      var link_id = $(this).attr('id');
      var action = $(this).attr('action');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, action);
    });



/*
    //Ajaxify the compared checkbox link
    $('.compared_checkbox_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'toogle_compared_checkbox');
    });
*/



/*

    $('#submitlink_dialog:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'submit_dialog');
    });
*/



/*

    //Ajaxify the compute table link
    $('#compute_table_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'compute_table');
    });
*/


/*
    //Ajaxify the compute table link
    $('#reset_table_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'reset_table');
    });
*/

/*
    //Ajaxify the compute table link
    $('#wikicompare_make_cleaning_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'make_cleaning');
    });

*/

    $('.wikicompare_button:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        $('#' + $(this).attr('link')).click();
        return false;
      });
    });



    $('#initialize_selected_feature_dialog_ids:not(.listener_set)').addClass('listener_set').each(function () {


        if ($(this).text() == 'manual') {
          selected_feature_dialog_ids = manual_selected_feature_ids;
        } else {
          selected_feature_dialog_ids = selected_feature_ids;
/*
//          selected_feature_dialog_ids = selected_feature_ids;
          selected_feature_dialog_ids = {};
          for (index = 0; index < selected_feature_ids.length; ++index) {
            var fid = selected_feature_ids[index];
            selected_feature_dialog_ids[fid] = [fid];
          }*/


/*
        if ($(this).text() == 'manual') {
          var feature_ids = manual_selected_feature_ids;
        } else {
          var feature_ids = selected_feature_ids;
        }

        selected_feature_dialog_ids = {};*/
/*
        for (index = 0; index < feature_ids.length; ++index) {
          var fid = feature_ids[index];
          selected_feature_dialog_ids[fid] = [fid];
        }
alert(selected_feature_dialog_ids.toSource());*/
        }

    });
/*
    $('#initialize_need_features:not(.listener_set)').addClass('listener_set').each(function () {

      var from_db = settings.wikicompare_needs.selected_feature_ids;
      for (index = 0; index < from_db.length; ++index) {
        var fid = from_db[index];
        selected_feature_ids[fid] = [fid];
      }


    });*/
    $('.selectlink_dialog:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
//      var nid = extract_nid(link_id)[0];

      type = $('#dialog_type').text();

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'select_dialog', type);
    });

    


/*

    $('#compute_table_button:not(.listener_set)').addClass('listener_set').each(function () {
      $('#' + $(this).attr('id')).click(function() {
        $('#compute_table_link').click();
        return false;
      });
    });
*/


    //Dynamize the toogle fast edit link to display the elements add/edit/remove.
    $('#toogle_fastaction_link:not(.listener_set)').addClass('listener_set').each(function () {

      $(this).click(function() {
        if (fastaction == 0) {
          //Set the global variable
          fastaction = 1;
        //If we are hidding the items
        } else {
          //Set the global variable
          fastaction = 0;
          $('.fastaction_item').remove();
/*
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
*/

        }
        $('#make_cleaning_link').click();
        return false;
      });




    });

    
    //Dynamize the compared add fastaction element.
    $('.fastaction_item:not(.ajax-processed)').addClass('ajax-processed').each(function () {
    


      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
//      var nid = extract_nid(link_id)[0];

      var type = $(this).attr('type');
      var action = $(this).attr('action');


      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'show_fastaction_form', type, action);
    });
    

       
    $('.form_fastaction').submit(function () {
/*      var patt = /[0-9]+/g;
      var nid = patt.exec($(this).attr('id'));*/
      var nid = extract_nid($(this).attr('id'));

      $('#form_fastaction_submit_link_' + nid).click();
      return false;
    });
   
    
    
    //Dynamize the compared add fastaction submit link.
    $('.form_fastaction_submit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {
    
      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
//      var nid = extract_nid(link_id)[0];

      var type = $(this).attr('type');
      var action = $(this).attr('action');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'submit_fastaction_form', type, action);
    });


    $('.form_fastaction_cancel:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        $('.fastaction_item:.displayed').removeClass('displayed');
        $('#make_cleaning_link').click();
        //Block the page loading
        return false;
      });
    }); 



    $('#edit-wikicompare-features:not(.ajax-processed)').addClass('ajax-processed').each(function () {
//      fastaction = settings['wikicompare_needs']['fastaction'];
// pourquoi fastaction?
      from_db = settings['wikicompare_needs']['selected_feature_ids'];

      for (index = 0; index < from_db.length; ++index) {
        var fid = from_db[index];

        selected_feature_ids[fid] = fid;
      }

    });



    $('#edit-wikicompare-use-from-inherit-und:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      $(this).click(function() {
        $('.compute_inherit_link').click();
      });
    });


    //Ajaxify the compared checkbox link
    $('.compute_inherit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'compute_inherit');
    });


    $('.clear_link:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        $('#container-wikicompare-parent-id').html('No parent');
        $('#edit-wikicompare-parent-id').html('<input type="text" size="60" value="" name="wikicompare_parent_id[und][0][target_id]">');
        $('#wikicompare-parent-id').empty();
        return false;
      });
    });

    $('.clear_link_inherit:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        $('#container-wikicompare-inherit-compared-id').html('No inherited compared');
        $('#edit-wikicompare-inherit-compared-id').html('<input type="text" size="60" value="" name="wikicompare_inherit_compared_id[und][0][target_id]">');
        $('#wikicompare-inherit-compared-id').empty();
        return false;
      });
    });






    
    function build_ajax_link(link_id, object, action, type=false, context=false) {

      //Recover the nid by using a regular expression on the link_id

      //Theses functions does not have nid and so would cause some problem. Essentially, they would disable the simple_dialog links.
      if (action != 'submit_dialog' && action != 'compute_table' && action != 'reset_table' && action != 'make_cleaning') {
        var nid = extract_nid(link_id)[0];
      }
  
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

        //We can't remove directly at cleaning otherwise some content will be remove before the end of slideUp
        if (action != 'make_cleaning') {
          //We remove all hidded element so they can't perturb the computation
          $('.to_remove').remove();
        }

        options.data.fastaction = fastaction;
        

        send_nid = false;
        send_type = false;
        manage_displayed_flag = false;
        send_computed = false;
        send_compareds = false;
        send_compareds_columns = false;
        send_features = false;
        send_implementations = false;
        send_needs = false;
        send_manual_selected_features = false;
        send_selected_needs = false;
        send_states = false;
        send_forbidden_nid = false;
        send_container = false;
        send_colspan = false;
        auto_colspan = false;
        make_cleaning = false;
        
        if (action == 'expand_list_children') {

          send_nid = true;
          manage_displayed_flag = true;
          send_compareds_columns = true;
          send_states = true;
          send_forbidden_nid = true;
          options.data.type = type;
          options.data.context = context;

          if (context == 'multidialog') {
//            options.data.dialog = true;
            options.data.selected_feature_ids = selected_feature_dialog_ids;

          } else if (context != 'selectdialog') {
            make_cleaning = true;
          }


          if ($('#' + link_id).hasClass('need')) {
            send_selected_needs = true;
          }
        }
        
        if (action == 'expand_row_children') {
          send_nid = true;
          manage_displayed_flag = true;
          send_compareds_columns = true;
          send_states = true;
          make_cleaning = true;
        }
        
        if (action == 'toogle_compared_checkbox') {
          send_nid = true;
          manage_displayed_flag = true;
          send_computed = true;
          send_features = true;
          auto_colspan = true;
          make_cleaning = true;
        }

        if (action == 'select_dialog') {
          send_nid = true;
          send_type = true;
          send_container = true;
//          options.data.container_autocomplete = $('#select_container_autocomplete').text();
//          options.data.container_id = $('#select_container_id').text();
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
          send_states = true;
          send_colspan = true;
          make_cleaning = true;
        }


        if (action == 'reset_table') {
          send_compareds_columns = true;
          send_states = true;
          send_colspan = true;
          options.data.reset = true;
        }

        

        
        if (action == 'show_fastaction_form') {
          send_nid = true;
          send_type = true;
          manage_displayed_flag = true;
          send_colspan = true;
          options.data.fastaction = context;

          
          $('.form_fastaction').remove();

          if ($('#' + link_id).hasClass('displayed')) {
            make_cleaning = true;
          }
          

        }
     
        if (action == 'submit_fastaction_form') {
          send_nid = true;
          send_type = true;
          options.data.fastaction = context;
          
          if (type != 'implementation') {
            options.data.title = $('#form_' + type + '_fast' + context + '_title_' + nid).val();
            options.data.title_translation = $('#form_' + type + '_fast' + context + '_title_' + nid + '_translation').val();
            options.data.parent_id = $('#parent_id').text();
            options.data.sequence = $('#form_' + type + '_fast' + context + '_sequence_' + nid).val();
            options.data.state = $('#form_' + type + '_fast' + context + '_state_' + nid).val();
          }
          options.data.description = $('#form_' + type + '_fast' + context + '_description_' + nid).val();
          options.data.description_translation = $('#form_' + type + '_fast' + context + '_description_' + nid + '_translation').val();
          if (type == 'compared') {
            options.data.inherit_id = $('#wikicompare-inherit-compared-id').text();
          }
          if (type == 'feature') {
            options.data.feature_type = $('#form_' + type + '_fast' + context + '_type_' + nid).val();
            options.data.guidelines = $('#form_' + type + '_fast' + context + '_guidelines_' + nid).val();
            options.data.guidelines_translation = $('#form_' + type + '_fast' + context + '_guidelines_' + nid + '_translation').val();
            options.data.weight = $('#form_' + type + '_fast' + context + '_weight_' + nid).val();
          }
          
          if (type == 'implementation') {
            options.data.support = $('#edit-wikicompare-support-und').is(':checked');
            options.data.use_from_inherit = $('#edit-wikicompare-use-from-inherit-und').is(':checked');
          }

          if (type == 'need') {
            var need_feature_ids = {};
            var i = 0;
            $('.need_feature').each(function (key, value) {

              need_feature_ids[$(this).text()] = $(this).text();
              i = i + 1;
            });
            //Add them in the ajax call variables
            options.data.need_feature_ids = need_feature_ids;

            options.data.state = $('#form_' + type + '_fast' + context + '_state_' + nid).val();
          }
          options.data.revision = $('#form_' + type + '_fast' + context + '_revision_' + nid).val();
          options.data.selectnode = $('#form_' + type + '_fast' + context + '_selectnode_' + nid).val();
        }

        if (action == 'compute_inherit') {
          send_nid = true;
          options.data.use_from_inherit = $('#edit-wikicompare-use-from-inherit-und').attr('checked');

        }


        if (action == 'make_cleaning') {
          send_computed = true;
          send_compareds_columns = true;
          send_implementations = true;
          send_selected_features = true;
          send_states = true;


          var a = ['compared', 'feature', 'need'];
          for (index = 0; index < a.length; ++index) {
            var ftype = a[index];
            var node_ids = {};
//            var i = 0;
            var item = ftype + '_item';
            if (ftype == 'feature') {
              item = 'feature_row';
            }
            $('.' + item).each(function (key, value) {
              //In the make cleaning function, the to_remove item are not already remove to not break the slideUp
              if (!$(this).hasClass('to_remove')) {

//                var id = $(this).attr('id');

                nid = extract_nid($(this).attr('id'))[0];
                node_ids[nid] = {};
                //Not using associative array because we shall not remove doublon. We need to make the security check on each element in the page.
                node_ids[nid]['nid'] = nid;
                if (ftype == 'feature') {
                  var patt = /[0-9]+/g;
                  if (patt.test($(this).attr('class'))) {
                    //I don't know why, but I need to remake the patt, the patt.exec will otherwise not work  
      //              var patt = /[0-9]+/g;
                    var pid = $(this).attr('class');
                    node_ids[nid]['parent_id'] = extract_nid(pid)[0]; //patt.exec($(this).attr('class'));
      //               = parent_id;
                  }
                } else {
                  if ($(this).parent().parent().parent().hasClass(ftype + '_children')) {
                    pid = $(this).parent().parent().parent().attr('id');
                    node_ids[nid]['parent_id'] = extract_nid(pid)[0];
                  }
                }

                node_ids[nid]['has_children'] = 0;
                if ($(this).hasClass('has_children')) {
                  node_ids[nid]['has_children'] = 1;
                }
//                i = i + 1;
              }
            });
            //Add them in the ajax call variables
            options.data[ftype + '_ids'] = node_ids;

            var node_displayed_ids = {};
//            var i = 0;
            $('.' + ftype + '_table_link').each(function (key, value) {

              if ($(this).hasClass('displayed')) {

  //              var patt = /[0-9]+/g;
//                var id = $(this).attr('id');
                var nid = extract_nid($(this).attr('id'))[0];
                node_displayed_ids[nid] = nid;// patt.exec($(this).attr('id'))[0]
//                i = i + 1;
              }
            });

            //Add them in the ajax call variables
            options.data[ftype + '_displayed_ids'] = node_displayed_ids;

          }


        }




        if (send_nid == true) {
          //Add the clicked node in argument
          options.data.nid = nid;
        }

        if (send_type == true) {
          options.data.type = type;
        }

        if (manage_displayed_flag == true) {
          //Check if the column is already displayed
//          options.data.action = '';

          options.data.display = 0;
          if (!$('#' + link_id).hasClass('displayed')) {

            options.data.display = 1;
          }
        }

        if (send_computed == true) {
          if ($('#comparative_table').hasClass('computed')) {
            options.data.computed = 1;
          } else {
            options.data.computed = 0;
          }
        }
        
        if (send_compareds == true) {
          //Recover all compared columns displayed in the table to send their id to drupal
          var compared_ids = {};
//          var i = 0;
          $('.compared_item').each(function (key, value) {
//            var column_id = $('#' + $(this).attr('id'));
            var cid = extract_nid($(this).attr('id'))[0];
            compared_ids[cid] = cid; //patt.exec($(this).attr('id'))[0];
//            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.compared_ids = compared_ids;
        }
        
        if (send_compareds_columns == true) {
          //Recover all compared columns displayed in the table to send their id to drupal, in the right order. This is why we can't use a dictionnary.
          var compared_column_ids = {};
          var i = 0;
          $('.header_compared').each(function (key, value) {
            if (!$(this).hasClass('to_remove')) {
//              var column_id = $('#' + $(this).attr('id'));
              var cid = extract_nid($(this).attr('id'))[0];
              compared_column_ids[cid] = cid;
              i = i + 1;
            }
          });

          //Add them in the ajax call variables
          options.data.compared_column_ids = compared_column_ids;
        }
        
        if (send_features == true) {
          //Recover all feature row displayed in the table to send their id to drupal
          var feature_ids = {};
//          var i = 0;
          $('.feature_row').each(function (key, value) {
//            var row_id = $('#' + $(this).attr('id'));
            var fid = extract_nid($(this).attr('id'))[0];
            feature_ids[fid] = fid;
//            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.feature_ids = feature_ids;
        }
        

        if (send_implementations == true) {
          //Recover all implementation displayed in the table to send their id to drupal
          var implementation_ids = {};
//          var i = 0;
          $('.implementation_cell').each(function (key, value) {
//            var cell_id = $('#' + $(this).attr('id'));
            var iid = extract_nid($(this).attr('id'))[0];
            implementation_ids[iid] = iid; //patt.exec($(this).attr('id'))[0];
//            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.implementation_ids = implementation_ids;
        }

        if (send_needs == true) {
          var need_ids = {};
//          var i = 0;
          $('.need_item').each(function (key, value) {
//            var need_id = $('#' + $(this).attr('id'));
            var nid = extract_nid($(this).attr('id'))[0];
            need_ids[nid] =  nid; //patt.exec($(this).attr('id'))[0];
//            i = i + 1;
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

        if (send_states == true) {
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

        if (send_colspan == true) {
          options.data.colspan = $('.header_compared').length + 1;
        }

        
        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }
      
      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {
        //First launch regular success function
        this.old_success(response, status);


        
        if (manage_displayed_flag == true) {

        
          if (!$('#' + link_id).hasClass('displayed')) {
            //Change the class link, so next time we click on this link it will hide the content
            $('#' + link_id).addClass('displayed');

            if (action == 'expand_list_children') {
              $('#' + type + '_' + context + '_children_' + nid).slideDown();
            }
  
            if (action == 'expand_row_children') {
             
              //Display the children with slide animation
              $('.feature_table_child_' + nid).show();
//TODO Les lignes s'affichent instantanement pour une raison qui m'echappe si je met un slideDown(). Utiliser la fonction suivante pour les afficher les unes apres les autres
//http://paulirish.com/2008/sequentially-chain-your-callbacks-in-jquery-two-ways/

//          (function shownext(jq){
//            jq.eq(0).slideDown("slow", function(){
//              (jq=jq.slice(1)).length && hidenext(jq);
//            });
//          })($(children_id))

            
            }
            
            if (action == 'toogle_compared_checkbox') {    
              //Display the column with fade animation. We don't fade the header because of some bug with the current template, to check when we will have the final template.
              $('#header_compared_' + nid).show();
              $('.implementation_compared_' + nid).fadeIn();
            }
            

            if (action == 'show_fastaction_form') {
              if (type == 'need') {
                var need_feature_ids = {};
                var i = 0;
                $('.need_feature').each(function (key, value) {

                  //var need_feature_id = $('#' + $(this).attr('id'));
                  //var patt = /[0-9]+/g;
                  fid = $(this).text();

                  need_feature_ids[fid] = fid;
                  i = i + 1;
                });
                //Add them in the ajax call variables
                selected_feature_ids = need_feature_ids;


              }
            }

          //I'd like to move this case out of this ajax function so the children removing whould be manage only by javascript, without making a useless ajax call. Unfortunately, the ajax call is made each time we click on the link, so I found no solution.
          } else {
          
            //Change the class link, so next time we click on this link it will display the content
            $('#' + link_id).removeClass('displayed');
          
            if (action == 'expand_list_children') {
              $('#' + type + '_' + context + '_children_' + nid).slideUp();
              $('.' + type + '_' + context + '_child_' + nid).addClass('to_remove');
            }
          
            if (action == 'expand_row_children') {
              //Hide the children with slide animation
              remove_children_tree(nid, '#feature_table_link_', '.feature_table_child_', false);

            }
          
            if (action == 'toogle_compared_checkbox') {   
              //Hide the column. We can't use animation because of the current template, to check when we will have the final template
              $('#header_compared_' + nid).hide();
              $('.implementation_compared_' + nid).hide();
              //Mark the column element so they will be remove at the next event. We can't do it now because otherwise it will crash the fade animation
              $('#header_compared_' + nid).addClass('to_remove');
              $('.implementation_compared_' + nid).addClass('to_remove');
            }
          

          }
          
        }

        if (auto_colspan == true) {
          colspan = $('.header_compared').length + 1;
          $('.row_auto_colspan').attr('colspan', colspan);
        }

        if (make_cleaning == true) {
          $('#make_cleaning_link').click();
        }


      }

      return ajax;
    }
    

    function extract_nid(link_id) {
      var patt = /[0-9]+/g;
      var nid = patt.exec(link_id);

      return nid;
    }

    function remove_children_tree(nid, link_prefix, children_prefix, computed) {

      $(children_prefix + nid).each(function(index) {
//        var patt = /[0-9]+/g;
        var child_nid = extract_nid($(this).attr('id'))[0];
        remove_children_tree(child_nid, link_prefix, children_prefix, computed);
      });
      //TODO replace with a slideUp()
      $(children_prefix + nid).hide();
      //We need to remove the class when the row isn't deleted, especially when the table is computed
      $(link_prefix + nid).removeClass('displayed');
      if (!computed == true) {
        $(children_prefix + nid).addClass('to_remove');
      }
    }


  }
};


/*
4/24
21 fichiers
faire les TODOS
Faire le INSTALL.txt, installer une plateforme de demo et une de stresstest sur le serveur.
Debogage
*/

//TODO on a encore des plantages sur le simpledialog quand on valide les fastedit, mais plus dans les autres cas.










//TODO les fastremove n'apparaissent plus
//TODO les needs ne sont plus traduits

//TODO Centralize the main update function, et integrer les where directement dans les leftjoin quand possible


//TODO Remplacer les $key par $nid quand je les ai utilise en tant que tel
//TODO renommer toutes les fonctions en les demarrant par wikicompare

//TODO A l'installation, le block language ne se met pas dans le contenu
//TODO Dans inherit compared, dans le formulaire d'implementation, quand on active / desactive la récupération depuis l'inherit, la valeur de support n'est pas correctement récupérée. Je n'arrive pas à corriger.
//TODO Dans fastaction, je n'arrive pas à afficher les description et guidelines avec le wysiwyg, ni les many2many comme users et proofs. On retire pour l'instant, archiver dans fichier TODO.
//TODO Trouver un moyen de sortir les requetes sql de la boucle update_compare_tree, pour un gain massif de performance
//TODO Code quality : Split the javascript file in three : main for forms (defining ajax function), one for comparative table and one for needs. The last two will override some function in the main file, using a hook system.
//TODO integrer un module de chat sur le site pourrait être sympa, suggestion drupalchat me parait pas mal
//TODO Pour faire marcher le dialog dans fastaction, je dois enlever le mot cle context dans simple_dialog.js -> "$('a.simple-dialog' + classes, context).each(function(event) {" Il faut trouver pourquoi pour que ça marche directement.
//TODO Low : The selected itemlist are in ordered list intead of unordered list. Looks like there is no error with html code, so we'll just wait for the template.
//TODO sur une implementation, quand on decoche use_from_inherit la valeur support n'est pas prise en compte / medium
//TODO Je pense que les expression reguliere ne recupere pas correctement l'id quand > 4 chiffres / critical
//TODO achever la traduction
//TODO dans form need, les features ne sont modifiée que une par une

})(jQuery);
