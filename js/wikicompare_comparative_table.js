(function ($) {

/*
 * Set global variable. Executed only once at the load of the file.
 */
//The fastaction status of the table.
fastaction = 0;
//The dictionnary containing the criterion manually selected.
manual_selected_criterion_ids = {};
//The dictionnary containing the criterion selected in forms.
selected_criterion_ids = {};
//The dictionnary containing the profiles selected in the table.
selected_profile_ids = {};


//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareComparativeTable = {
  attach: function (context, settings) {

    /*
     * Ajaxify the links in the itemlist, so they display their children.
     */
    $('.item_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Get type and context of the link. We use context mainly to not confuse the link in table, in popup, in selected itemlist etc...
      var type = $(this).attr('ntype');
      var context = $(this).attr('context');

      //If the itemlist was computed, then the children are already in the itemlist, we just need to display them.
      if ($(this).hasClass('computed')) {

        //What happen when we click on the link.
        $(this).click(function() {
          //Get the nid of the node.
          var nid = extract_nid(link_id);
          //Display the children if they are not already shown.
          if (!$(this).hasClass('displayed')) {
            $('.criterion_' + context + '_child_' + nid).show();
            //Next time, it'll hide the children.
            $(this).addClass('displayed');
          //Hide the children.
          } else {
            //By using this recursive function, the children will be recursively hidded.
            remove_children_tree(nid, '#criterion_' + context + '_link_', '.criterion_' + context + '_child_', false);
          }
          //Avoid the hyperlink to load another page.
          return false;
        });

      //If we need to display the child by ajax.
      } else {

        action = 'expand_list_children';
        //Only the criterion in the table are not displayed in an itemlist but in row, the ajax call is not the same.
        if (type == 'criterion' && context == 'table') {
          action = 'expand_row_children';
        }

        //Build ajax link.
        Drupal.ajax[link_id] = build_ajax_link(link_id, this, action, type, context);

      }

    });



    /*
     * Dynamize the checkboxes.
     */
    $('.itemlist_checkbox:not(.listener_set)').addClass('listener_set').each(function () {

      //Get link name and nid.
      var link_id = $(this).attr('id');
      var nid = extract_nid(link_id)[0];

      //Set the onclick event
      $(this).click(function() {

        //The checkbox in the table product itemlist, which must add or remove a column in the table.
        if ($(this).attr('ntype') == 'product' && $(this).attr('context') == 'table') {
          //Disable the checkbox during the ajax event.
          $(this).attr('disabled', 'disabled');
          //Call the ajax to display the column.
          $('#product_checkbox_link_' + nid).click();

        //The checkbox in the table profile itemlist, which must keep in memory all checked profile for the table computation.
        } else if ($(this).attr('ntype') == 'profile') {
          //Add or remove the checked/unchecked checkbox in the global variable.
          if ($(this).attr('checked')) {
            selected_profile_ids[nid] = nid;
          } else {
            delete selected_profile_ids[nid];
          }

        //All other itemlist checkboxes are selected criterions (manually or for forms) in popin.
        } else {
          //Add or remove the checked/unchecked checkbox in the global variable.
          if ($(this).attr('checked')) {
            selected_criterion_dialog_ids[nid] = nid;
          } else {
            delete selected_criterion_dialog_ids[nid];
          }
        }

      });

    });



    /*
     * Ajaxify the simple link which has no particular code to manage in the call.
     * Theses links are often hidden and automatically clicked on some event, like checkbox check, click on button or call by ajax.
     * Exemple :
     *   - The product checkbox which add a column in the table.
     *   - The link after a submit button, in popin or fastaction form.
     *   - The cleaning function.
     */
    $('.simple_ajaxlink:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      //Get the link id and the ajax action which will be build.
      var link_id = $(this).attr('id');
      var action = $(this).attr('action');
      //Build ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, action);
    });



    /*
     * The buttons does not have ajax event on them, but they are followed by an hidden ajax link, whose id in in the link attribute of the button.
     */
    $('.wikicompare_button:not(.listener_set)').addClass('listener_set').each(function () {
      //When we click on the button.
      $(this).click(function() {
        //We click on the ajax link attached to the button.
        $('#' + $(this).attr('link')).click();
        //Avoid page redirecting.
        return false;
      });
    });



    /*
     * When we scroll the product list, load the next products at the end of the scroll.
     */
    var load = false;
    //We use the position of the last product as mark.
    var offset = $('.product_list_item:last').offset();
    $('#product_list_column').scroll(function(){
      //If the offset is at the bottom of the scroll, is there is no current loading, if there is more than five displayed product and if all products are not already displayed, then we launch the function.
      if ((offset.top - $('#product_list_column').height() - 150 <= $('#product_list_column').scrollTop()) && load==false && ($('.product_list_item').size()>=5) && ($('.product_list_item').size()!=$('#nb_products').text())){
//TODO At the third call, the offset.top drastically diminush and so all next product are insta loaded. Instead of a step of 400 between each offset, we have only a step of 100. I don't know why.
        //Lock the function.
        load = true;
        $('#append_product_list_link').click();
      }
    });



    /*
     * When we open a popin, recover the selected criterion from the main page, either the manually selected or the form selected criterions.
     */
    $('#initialize_selected_criterion_dialog_ids:not(.listener_set)').addClass('listener_set').each(function () {
        if ($(this).text() == 'manual') {
          selected_criterion_dialog_ids = manual_selected_criterion_ids;
        } else {
          selected_criterion_dialog_ids = selected_criterion_ids;
        }
    });



    /*
     * In select popin, there is a link before each item. On click, it'll return the item to the main page.
     */
    $('.selectlink_dialog:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      //Recover the link_id
      var link_id = $(this).attr('id');
      //The node type in popin, indicated on an hidden div at the beginning of the popin.
      type = $('#dialog_type').text();
      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'select_dialog', type);

    });


    /*
     * Launch a cleaning ajax call when we check a state checkbox, to reset the tables if necessary.
     */
    $('.state_checkbox:not(.listener_set)').addClass('listener_set').each(function () {
      //Set the onclick event
      $(this).click(function() {
        $('#make_cleaning_link').click(); 
      });
    });





    /*
     * Dynamize the toogle fastaction link to display the fastaction items.
     */
    $('#toogle_fastaction_link:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        //On click, we change the fastaction flag.
        if (fastaction == 0) {
          fastaction = 1;
        } else {
          fastaction = 0;
          //Remove the displayed fastaction item.
          $('.fastaction_item').remove();
        }
        //Then we call the cleaning function, which will add the fastaction item since we changed the fastaction flag.
        $('#make_cleaning_link').click();
        //Avoid page redirection.
        return false;
      });
    });


    /*
     * Ajaxify the fastaction items, to display the fastaction form.
     */
    $('.fastaction_item:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      //Recover the link_id, the type of the node and the fastaction.
      var link_id = $(this).attr('id');
      var type = $(this).attr('type');
      var action = $(this).attr('action');
      //Build the ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'show_fastaction_form', type, action);
    });



    /*
     * Call the ajax submit link of the fastaction form when we submit it.
     */
    $('.form_fastaction').submit(function () {
      //Get the nid of the form
      var nid = extract_nid($(this).attr('id'));
      //Call the ajax submit link.
      $('#form_fastaction_submit_link_' + nid).click();
      //Avoid page redirection.
      return false;
    });



    /*
     * Ajaxify the submit link of the form.
     */
    $('.form_fastaction_submit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      //Recover the link id, the type of the node and the fastaction.
      var link_id = $(this).attr('id');
      var type = $(this).attr('type');
      var action = $(this).attr('action');
      //Build ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'submit_fastaction_form', type, action);
    });



    /*
     * Dynamize the cancel button so it remove the form.
     */
    $('.form_fastaction_cancel:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        //Make sure the next time we click on the item it open the form.
        $('.fastaction_item:.displayed').removeClass('displayed');
        //The form will be clean by the function.
        $('#make_cleaning_link').click();
        //Block the page loading
        return false;
      });
    });



    /*
     * Use the wikicompare_criterions field to detect that we are in a profile form. In this case, we recover the settings from Drupal to initiate selected_criterion_ids.
     */
    $('#edit-wikicompare-criterions:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      //Get settings from Drupal.
      from_db = settings['wikicompare_profiles']['selected_criterion_ids'];
      for (index = 0; index < from_db.length; ++index) {
        var fid = from_db[index];
        //Initiate selected_criterion_ids.
        selected_criterion_ids[fid] = fid;
      }
    });



    /*
     * Use the wikicompare_use_from_inherit field to detect that we are in a evaluation form. When we change the value of use_from_inherit, the value of support field is recomputed.
     */
    $('#edit-wikicompare-use-from-inherit-und:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      $(this).click(function() {
        $('.compute_inherit_link').click();
      });
    });


    /*
     * Ajaxify the hidden link which will recompute the support field in evaluation form.
     */
    $('.compute_inherit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      var link_id = $(this).attr('id');
      //Build the ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'compute_inherit');
    });



    /*
     * In form, the clear link will reset the parent_id value of the form.
     */
    $('.clear_link:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        //Reset title displayed in the field.
        $('#container-wikicompare-parent-id').html('No parent');
        //Reset Drupal field value.
        $('#edit-wikicompare-parent-id').html('<input type="text" size="60" value="" name="wikicompare_parent_id[und][0][target_id]">');
        //Reset fastaction field value.
        $('#wikicompare-parent-id').empty();
        //Avoid page rediraction.
        return false;
      });
    });



    /*
     * In product form, the clear link will reset the inherit_id value of the form.
     */
    $('.clear_link_inherit:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        //Reset title displayed in the field.
        $('#container-wikicompare-inherit-product-id').html('No inherited product');
        //Reset Drupal field value.
        $('#edit-wikicompare-inherit-product-id').html('<input type="text" size="60" value="" name="wikicompare_inherit_product_id[und][0][target_id]">');
        //Reset fastaction field value.
        $('#wikicompare-inherit-product-id').empty();
        //Avoid page rediraction.
        return false;
      });
    });





    /*
     * The generic function which will build the ajax link in wikicompare.
     *
     * @param link_id
     *   The link id of the link we click on.
     *
     * @param object
     *
     * @param action
     *   The action callback which will be called.
     *
     * @param type
     *   The node type
     *
     * @param context
     *   The context of the item (table, manual, selected, dialog etc...) or the fastaction (remove, add, edit).
     */
    function build_ajax_link(link_id, object, action, type=false, context=false) {



      //Theses functions does not have nid and so would cause some problem. For example, they would disable the simple_dialog links.
      if (action != 'append_product_list' && action != 'submit_dialog' && action != 'compute_table' && action != 'reset_table' && action != 'make_cleaning') {
        //Recover the nid by using a regular expression on the link_id.
        var nid = extract_nid(link_id)[0];
      }
//TODO Move in send_nid

      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(object).attr('href')) {
        element_settings.url = $(object).attr('href');
        element_settings.event = 'click';
      }
      //Create the ajax event
      var ajax = new Drupal.ajax(link_id, object, element_settings);


      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal.
      ajax.old_beforeSerialize = ajax.beforeSerialize;
      ajax.beforeSerialize = function (element, options) {

        //We can't remove directly at cleaning otherwise some content will be remove before the end of animation (slideUp, etc...)
        if (action != 'make_cleaning') {
          //We remove all old element so they can't perturb the computation?
          $('.to_remove').remove();
        }

        //Send the fastaction flag, so drupal know if the fastaction mode is activated.
        options.data.fastaction = fastaction;

        //Initialize all the information we can send to Drupal. This is a way to centralize the code.
        send_nid = false;
        send_type = false;
        manage_displayed_flag = false;
        send_computed = false;
        send_products = false;
        send_products_columns = false;
        send_criterions = false;
        send_evaluations = false;
        send_profiles = false;
        send_products_tree_mode = false;
        send_manual_selected_criterions = false;
        send_selected_profiles = false;
        send_states = false;
        send_forbidden_nid = false;
        send_container = false;
        send_colspan = false;
        auto_colspan = false;
        make_cleaning = false;

        //When we want to display the children in an itemlist.
        if (action == 'expand_list_children') {
          //Send the parent_id so we retrieve the children.
          send_nid = true;
          //Send the flag, so we know if we display or hide the children.
          manage_displayed_flag = true;
          //Send the product displayed in the table, so in case of product table we can checked the already displayed items.
          send_products_columns = true;
          //Send states if we want to also display the draft and closed items.
          send_states = true;
          //In popin, we may have to block a forbidden nid.
          send_forbidden_nid = true;
          options.data.type = type;
          options.data.context = context;

          //When we are in popin, selecting a criterion, we send the already checked criterions so they are checked by default.
          if (context == 'multidialog') {
            options.data.selected_criterion_ids = selected_criterion_dialog_ids;
          } else if (context != 'selectdialog') {
            //After a children display, we clean the table except if we are in popin (in such case, we have multidialog or selectdialog in context).
            make_cleaning = true;
          }

          //If we are in profile table itemlist, we send the already checked profile so they are checked by default.
          if (type == 'profile') {
            send_selected_profiles = true;
          }
        }

        //When we want to display the criterion children in table.
        if (action == 'expand_row_children') {
          //Send the parent_id so we retrieve the children.
          send_nid = true;
          //Send the flag, so we know if we display or hide the children.
          manage_displayed_flag = true;
          //Send the product displayed in the table, so we directly add the cell of these columns in the new lines of the criterion children.
          send_products_columns = true;
          //Send states if we want to also display the draft and closed items.
          send_states = true;
          //The table will be clean after the operation.
          make_cleaning = true;
        }

        if (action == 'append_product_list') {
          send_computed = true;
          send_manual_selected_criterions = true;
          send_selected_profiles = true;
          send_products_tree_mode = true;
          options.data.products_offset = $('#products_offset').text();
        }

        //When we want to add a new column in the table.
        if (action == 'toogle_product_checkbox') {
          //Send the nid of the product to add.
          send_nid = true;
          //Send the flag, so we know if we display or hide the column.
          manage_displayed_flag = true;
          //Verify if the table was computed, in such case the data need to be computed with the selected criterion.
          send_computed = true;
          //Send the criterion displayed in the table, so we directly add the cells for these row in the new column.
          send_criterions = true;
          //Resize all lines to the new size of the table.
          auto_colspan = true;
          //The table will be clean after the operation.
          make_cleaning = true;
        }

        //If we are selected a node in popin.
        if (action == 'select_dialog') {
          //Send the nid of the selected node.
          send_nid = true;
          //Send the type of the selected node.
          send_type = true;
          //Send the container we need to update in the main page.
          send_container = true;
        }

        //If we are selecting several items in popin.
        if (action == 'submit_dialog') {
          //Send the criterions selected and send the array to the main page, to the selected array or manual array.
          if ($('#initialize_selected_criterion_dialog_ids').text() == 'manual') {
            manual_selected_criterion_ids = selected_criterion_dialog_ids;
            send_manual_selected_criterions = true;
          } else {
            selected_criterion_ids = selected_criterion_dialog_ids;
            options.data.selected_criterion_ids = selected_criterion_dialog_ids;
          }
          //Send the container we need to update in the main page.
          send_container = true;
        }

        //If we launched the table computation.
        if (action == 'compute_table') {
          //Send the product displayed in the table, they'll keep display in the new table.
          send_products_columns = true;
          //Send the criterions manually selected, they'll be used to select the computed criterions.
          send_manual_selected_criterions = true;
          //Send the selected profile. Their criterions will be used to select the computed criterions.
          send_selected_profiles = true;
          //Send the states.
          send_states = true;
          //Send the size of the table to adjust the lines.
          send_colspan = true;
          //Clean the table after the computation.
          make_cleaning = true;
        }

        //If we want to restore the initial state of the table.
        if (action == 'reset_table') {
          //Send the product displayed in the table, they'll keep display in the new table.
          send_products_columns = true;
          //Send the states.
          send_states = true;
          //Send the size of the table to adjust the lines.
          send_colspan = true;
          //We call the same ajax function that computation, we use this variable to tell the table we want to reset it.
          options.data.reset = true;
        }

        //If we want to display the fastaction form.
        if (action == 'show_fastaction_form') {
          //Send the nid of the form.
          send_nid = true;
          //Send the type of the node.
          send_type = true;
          //Send the flag, so we know if we display or hide the column.
          manage_displayed_flag = true;
          //Send the size of the table to adjust the colspan of the form.
          send_colspan = true;
          //Send the fastaction (add, edit, remove).
          options.data.fastaction = context;

          //We remove all other fastaction form by calling the cleaning function.
          if ($('#' + link_id).hasClass('displayed')) {
            make_cleaning = true;
          }


        }

        if (action == 'submit_fastaction_form') {
          //Send the nid of the node.
          send_nid = true;
          //Send the type of the node.
          send_type = true;
          //Send the fastaction (add, edit, remove).
          options.data.fastaction = context;

          //Get value of all fields in the fastaction form, and send them to Drupal.
          if (type != 'evaluation') {
            options.data.title = $('#form_' + type + '_fast' + context + '_title_' + nid).val();
            options.data.title_translation = $('#form_' + type + '_fast' + context + '_title_' + nid + '_translation').val();
            options.data.parent_id = $('#wikicompare-parent-id').text();
            options.data.sequence = $('#form_' + type + '_fast' + context + '_sequence_' + nid).val();
            options.data.state = $('#form_' + type + '_fast' + context + '_state_' + nid).val();
          }
          options.data.description = $('#form_' + type + '_fast' + context + '_description_' + nid).val();
          options.data.description_translation = $('#form_' + type + '_fast' + context + '_description_' + nid + '_translation').val();
          if (type == 'product') {
            options.data.inherit_id = $('#wikicompare-inherit-product-id').text();
          }
          if (type == 'criterion') {
            options.data.criterion_type = $('#form_' + type + '_fast' + context + '_type_' + nid).val();
            options.data.guidelines = $('#form_' + type + '_fast' + context + '_guidelines_' + nid).val();
            options.data.guidelines_translation = $('#form_' + type + '_fast' + context + '_guidelines_' + nid + '_translation').val();
            options.data.weight = $('#form_' + type + '_fast' + context + '_weight_' + nid).val();
          }
          if (type == 'evaluation') {
            options.data.support = $('#edit-wikicompare-support-und').is(':checked');
            options.data.use_from_inherit = $('#edit-wikicompare-use-from-inherit-und').is(':checked');
          }
          if (type == 'profile') {
            var profile_criterion_ids = {};
            var i = 0;
            $('.profile_criterion').each(function (key, value) {
              profile_criterion_ids[$(this).text()] = $(this).text();
              i = i + 1;
            });
            options.data.profile_criterion_ids = profile_criterion_ids;
          }
          options.data.revision = $('#form_' + type + '_fast' + context + '_revision_' + nid).val();
          options.data.selectnode = $('#form_' + type + '_fast' + context + '_selectnode_' + nid).val();
        }

        //If we are updating the support value in evaluation form.
        if (action == 'compute_inherit') {
          //Send evaluation value.
          send_nid = true;
          //Send value of use_from_inherit field.
          options.data.use_from_inherit = $('#edit-wikicompare-use-from-inherit-und').attr('checked');
        }

        //If we want to clean the table.
        if (action == 'make_cleaning') {

          //Send computed state, the table will not be touched if it was computed.
          send_computed = true;
          //Send product displayed, to update the titles.
          send_products_columns = true;
          //Send evaluations, to update the percent.
          send_evaluations = true;
          //Send selected_criterions, to check if we need to reset the manual itemlist.
          send_selected_criterions = true;
          //Send states.
          send_states = true;

          //We will send all nodes in the cleaning function, and check which parent is displaying his children.
          var a = ['product', 'criterion', 'profile'];
          for (index = 0; index < a.length; ++index) {

            //The node type we are working on.
            var ftype = a[index];
            var node_ids = {};
            //Get the class to find the item in the table.
            var item = ftype + '_item';
            if (ftype == 'criterion') {
              item = 'criterion_row';
            }

            //For all item in the table.
            $('.' + item).each(function (key, value) {
              //In the make cleaning function, the to_remove items are not already remove to not break the slideUp, but they still must not be send.
              if (!$(this).hasClass('to_remove')) {
                //Extract nid.
                nid = extract_nid($(this).attr('id'))[0];
                node_ids[nid] = {};
                //Assign the nid.
                node_ids[nid]['nid'] = nid;
                //Get the parent id from the table.
                if (ftype == 'criterion') {
                  var patt = /[0-9]+/g;
                  //The only numerical value in the class of a criterion item is his parent.
                  if (patt.test($(this).attr('class'))) {
                    var pid = $(this).attr('class');
                    node_ids[nid]['parent_id'] = extract_nid(pid)[0];
                  }
                } else {
                  //Extract parent by checking the upper item of the itemlist.
                  if ($(this).parent().parent().parent().hasClass(ftype + '_children')) {
                    pid = $(this).parent().parent().parent().attr('id');
                    node_ids[nid]['parent_id'] = extract_nid(pid)[0];
                  }
                }
                //Check if the node has children.
                node_ids[nid]['has_children'] = 0;
                if ($(this).hasClass('has_children')) {
                  node_ids[nid]['has_children'] = 1;
                }
              }
            });
            //Add them in the ajax call variables.
            options.data[ftype + '_ids'] = node_ids;

            //Then we need to find which item are displaying his children.
            var node_displayed_ids = {};
            //For each item which have children (since they have link).
            $('.' + ftype + '_table_link').each(function (key, value) {
              //Check if the item is displaying his children.
              if ($(this).hasClass('displayed')) {
                //Extract nid.
                var nid = extract_nid($(this).attr('id'))[0];
                node_displayed_ids[nid] = nid;
              }
            });
            //Add them in the ajax call variables
            options.data[ftype + '_displayed_ids'] = node_displayed_ids;

          }

        }


        //Get and send the nid.
        if (send_nid == true) {
          options.data.nid = nid;
        }

        //Get and send the type.
        if (send_type == true) {
          options.data.type = type;
        }

        //Get and send the display flag by checking the class on the link.
        if (manage_displayed_flag == true) {
          options.data.display = 0;
          if (!$('#' + link_id).hasClass('displayed')) {
            options.data.display = 1;
          }
        }

        //Get and send the computed flag by checking the class on the table.
        if (send_computed == true) {
          if ($('#comparative_table').hasClass('computed')) {
            options.data.computed = 1;
          } else {
            options.data.computed = 0;
          }
        }

        //Get and send the products in the table.
        if (send_products == true) {
          var product_ids = {};
          $('.product_item').each(function (key, value) {
            var cid = extract_nid($(this).attr('id'))[0];
            product_ids[cid] = cid;
          });
          //Add them in the ajax call variables.
          options.data.product_ids = product_ids;
        }

        //Get and send the products displayed as column in the table.
        if (send_products_columns == true) {
          //Recover all product columns displayed in the table to send their id to drupal, in the right order. This is why we can't use a dictionnary.
          var product_column_ids = [];
          var i = 0;
          $('.header_product').each(function (key, value) {
            if (!$(this).hasClass('to_remove')) {
              var cid = extract_nid($(this).attr('id'))[0];
              product_column_ids[i] = cid;
              i = i + 1;
            }
          });
          //Add them in the ajax call variables.
          options.data.product_column_ids = product_column_ids;
        }

        //Get and send the criterions in the table.
        if (send_criterions == true) {
          var criterion_ids = {};
          $('.criterion_row').each(function (key, value) {
            var fid = extract_nid($(this).attr('id'))[0];
            criterion_ids[fid] = fid;
          });
          //Add them in the ajax call variables.
          options.data.criterion_ids = criterion_ids;
        }

        //Get and send the evaluations in the table.
        if (send_evaluations == true) {
          var evaluation_ids = {};
          $('.evaluation_cell').each(function (key, value) {
            var iid = extract_nid($(this).attr('id'))[0];
            evaluation_ids[iid] = iid;
          });
          //Add them in the ajax call variables.
          options.data.evaluation_ids = evaluation_ids;
        }

        //Get and send the profiles in the table.
        if (send_profiles == true) {
          var profile_ids = {};
          $('.profile_item').each(function (key, value) {
            var nid = extract_nid($(this).attr('id'))[0];
            profile_ids[nid] =  nid;
          });
          //Add them in the ajax call variables.
          options.data.profile_ids = profile_ids;
        }

        if (send_products_tree_mode == true) {
          options.data.products_tree_mode = $('#products_tree_mode').text();
        }

        //Get all manually selected criterions to send their id to drupal.
        if (send_manual_selected_criterions == true) {
          options.data.selected_criterion_ids = manual_selected_criterion_ids;
        }

        //Get all manually selected profiles to send their id to drupal.
        if (send_selected_profiles == true) {
          options.data.selected_profile_ids = selected_profile_ids;
        }

        //Send the states which must be displayed in the table, by checking the checkboxes at the beginning of the table.
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

        //Send the forbidden nid we must not display in the popin. It is specify in a hidden div at the beginning of the popin.
        if (send_forbidden_nid == true) {
          forbidden_nid = $('#forbidden_nid').text();
          options.data.forbidden_nid = forbidden_nid;
        }

        //Send the container we must insert the selected value in the popin. It is specify in a hidden div at the beginning of the popin.
        if (send_container == true) {
          container = $('#select_container').text();
          options.data.container = container;
        }

        //Get and send the size of the table.
        if (send_colspan == true) {
          options.data.colspan = $('.header_product').length + 1;
        }

        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }


      //The success function is launched when drupal return the commands. We will override it to add some other commands.
      ajax.old_success = ajax.success;
      ajax.success = function (response, status) {

        //First launch regular success function
        this.old_success(response, status);

        //If the ajax link of of type active/disactive.
        if (manage_displayed_flag == true) {

          //If we are displaying the elements.
          if (!$('#' + link_id).hasClass('displayed')) {

            //Change the class link, so next time we click on this link it will hide the content
            $('#' + link_id).addClass('displayed');

            //The children are here but hidden, we display them with a slideDown animation.
            if (action == 'expand_list_children') {
              $('#' + type + '_' + context + '_children_' + nid).slideDown();
            }

            if (action == 'expand_row_children') {
              $('.criterion_table_child_' + nid).show();
              //TODO Lines instant display if I put a slideDown(). Use the following fucntion to display them one after another.
//http://paulirish.com/2008/sequentially-chain-your-callbacks-in-jquery-two-ways/
//          (function shownext(jq){
//            jq.eq(0).slideDown("slow", function(){
//              (jq=jq.slice(1)).length && hidenext(jq);
//            });
//          })($(children_id))
            }

            if (action == 'toogle_product_checkbox') {
              //Display the column with fade animation. We don't fade the header because of some bug with the current template, to check when we will have the final template.
              $('#header_product_' + nid).show();
              $('.evaluation_product_' + nid).fadeIn();
            }

            //Initialize the selected_criterions_ids when we open a profile fastaction form. Not the same variable than manual_selected_criterions_ids to avoid conflict.
            if (action == 'show_fastaction_form') {
              if (type == 'profile') {
                var profile_criterion_ids = {};
                $('.profile_criterion').each(function (key, value) {
                  fid = $(this).text();
                  profile_criterion_ids[fid] = fid;
                });
                //Insert actual criterions in global variable.
                selected_criterion_ids = profile_criterion_ids;
              }
            }

          //When we want to hide the children.
          //I'd like to move this case out of this ajax function so the children removing would be manage only by javascript, without making a useless ajax call. Unfortunately, the ajax call is made each time we click on the link, so I found no solution.
          } else {

            //Change the class link, so next time we click on this link it will display the content
            $('#' + link_id).removeClass('displayed');

            if (action == 'expand_list_children') {
              $('#' + type + '_' + context + '_children_' + nid).slideUp();
              $('.' + type + '_' + context + '_child_' + nid).addClass('to_remove');
            }

            if (action == 'expand_row_children') {
              //Hide the children recursively.
              remove_children_tree(nid, '#criterion_table_link_', '.criterion_table_child_', false);
            }

            if (action == 'toogle_product_checkbox') {
              //Hide the column. We can't use animation because of the current template, to check when we will have the final template
              $('#header_product_' + nid).hide();
              $('.evaluation_product_' + nid).hide();
              //Mark the column element so they will be remove at the next event. We can't do it now because otherwise it will crash the fade animation
              $('#header_product_' + nid).addClass('to_remove');
              $('.evaluation_product_' + nid).addClass('to_remove');
            }

          }

        }

        if (action == 'append_product_list') {
          //Refresh the offset with the value of the last loaded product.
          offset = $('.product_list_item:last').offset();
					//We can now scroll and append new products.
          load = false;
        }

        //Adjust the lines to the new size of the table, when we add a new column.
        if (auto_colspan == true) {
          colspan = $('.header_product').length + 1;
          $('.row_auto_colspan').attr('colspan', colspan);
        }

        //Launch the cleaning function.
        if (make_cleaning == true) {
          $('#make_cleaning_link').click();
        }

      }

      return ajax;

    }



    /*
     * Function to extract nid in object id thank to regular expression.
     *
     * @param link_id
     *   The string we need to extract the nid.
     *
     * @return nid
     *   The nid extracted.
     */
    function extract_nid(link_id) {
      //The regular expression, extract any number in the string.
      var patt = /[0-9]+/g;
      //Execute.
      var nid = patt.exec(link_id);

      return nid;
    }



    /*
     * Function to recursively hide the children of itemlist / row item.
     *
     * @param nid
     *   The nid of the parent node.
     *
     * @param link_prefix
     *   The prefix of the parent link.
     *
     * @param children_prefix
     *   The prefix of the class of the children.
     *
     * @param computed
     *   Boolean indicated if the children are computed or not.
     */
    function remove_children_tree(nid, link_prefix, children_prefix, computed) {
      //For all children.
      $(children_prefix + nid).each(function(index) {
        //Get nid of the child.
        var child_nid = extract_nid($(this).attr('id'))[0];
        //Recursively launch the function to hide the children of the child.
        remove_children_tree(child_nid, link_prefix, children_prefix, computed);
      });
      //Hide the children. Later replace the hide by an animation, slideUp for exemple.
      $(children_prefix + nid).hide();
      //Remove the display flag in the parent link.
      $(link_prefix + nid).removeClass('displayed');
      //Remove the children from the page, only if it was not computed.
      if (!computed == true) {
        $(children_prefix + nid).addClass('to_remove');
      }
    }

  }
};

})(jQuery);
