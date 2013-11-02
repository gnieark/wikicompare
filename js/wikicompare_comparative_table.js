(function ($) {

/*
 * Set global variable. Executed only once at the load of the file.
 */

//The dictionnary containing the products selected in products list
selectedProducts = {};
//The dictionnary containing the criterion manually selected.
manual_selected_criterion_ids = {};
//The dictionnary containing the criterion selected in forms.
selected_criterion_ids = {};
//The dictionnary containing the profiles selected in the table.
selected_profile_ids = {};
//Some constant dimensions used in the table.
row_height = 100;
first_column_width = 30;
suggest_height = 15;
//Boolean which block the loading in product list while another loading is performing.
load = false;



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
            $('.' + type + '_' + context + '_item[parent_id=' + nid + ']').show().removeClass('hidden');
            //Next time, it'll hide the children.
            $(this).addClass('displayed');
          //Hide the children.
          } else {
            //By using this recursive function, the children will be recursively hidded.
            remove_children_tree2(nid, '#' + type + '_' + context + '_link_', '.' + type + '_' + context + '_item', true);
          }
          //Refresh oddeven.
          odd_even_product_list('.product_list_item');
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

        var aj_settings = {};
        aj_settings['type'] = type;
        aj_settings['context'] = context;

        //Build ajax link.
        Drupal.ajax[link_id] = build_ajax_link(link_id, this, action, aj_settings);

      }

    });



    /*
     * Ajaxify the criterion links in the comparative table, so they display their children.
     */
    $('.criterion_table_link:not(#storage_zone .criterion_table_link):not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
//TODO simple_ajaxlink?
      var aj_settings = {};
      aj_settings['type'] = 'criterion';
      aj_settings['context'] = 'table';

      //Build ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'expand_row_children', aj_settings);

    });



    /*
     * Dynamize the breadcrumb so we can click on it to return on superior part of the table.
     */
    $('.breadcrumb_item_link:not(.listener-set)').addClass('listener-set').each(function () {

      $(this).click(function() {

        var clicked_depth = extract_nid($(this).attr('id'))[0];
        var nid = $(this).attr('nid');
        var max_depth = get_table_depth('.breadcrumb_item');

        //Slide the table to return at the clicked depth.
        $("#comparative_tables").css("transform","translateX(" + (clicked_depth - 1) * -100 + "%)");
        //Remove the flag on link.
        $('.criterion_table_link[nid=' + nid + ']').removeClass('displayed');

        //Action on each tables hidded by the slide.
        while ((max_depth + 1) != clicked_depth) {
          //Mark the table for removal.
          $("#comparative_table_" + max_depth).addClass('to_remove');
          //Fade out the breadcrumb part linked to this table and mark it for removal.
          $("#breadcrumb_item_" + max_depth).fadeOut();
          $("#breadcrumb_item_" + max_depth).addClass('to_remove');

          max_depth = max_depth - 1;
        }

        //Block the page loading;
        return false;

      });

    });



    /*
     * Dynamize the itemlist return link so we can click on it to return on superior part of the itemlist.
     */
    $('.itemlist_return_link:not(#storage_zone .itemlist_return_link):not(.listener-set)').addClass('listener-set').each(function () {

      $(this).click(function() {

        var clicked_depth = extract_nid($(this).attr('id'))[0];
        var nid = $(this).attr('nid');
        var type = $(this).attr('ntype');
        var max_depth = get_table_depth('.itemlist_return_link');

        //Slide the table to return at the clicked depth.
        $("#main_" + type + "_itemlists").css("transform","translateX(" + (clicked_depth - 1) * -100 + "%)");
        //Remove the flag on link.
        $('.' + type + '_table_link[nid=' + nid + ']').removeClass('displayed');

        //Action on each tables hidded by the slide.
        while ((max_depth + 1) != clicked_depth) {
          //Mark the table for removal.
          $("#itemlist_" + max_depth).addClass('to_remove');
          max_depth = max_depth - 1;
        }

        //Block the page loading;
        return false;

      });

    });



    /*
     * Dynamize the checkboxes.
     */
    $('.itemlist_checkbox:not(#storage_zone .itemlist_checkbox):not(.listener_set)').addClass('listener_set').each(function () {

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

        if ($(this).attr('checked')) {
          parent_checked_children('check', $(this).attr('ntype'), $(this).attr('context'), nid);
        } else {
          parent_checked_children('uncheck', $(this).attr('ntype'), $(this).attr('context'), nid);
        }

      });

    });



    /*
     * Dynamize the filters.
     */
    $('.home_filter:not(.listener_set)').addClass('listener_set').each(function () {

      $(this).change(function() {
        var click = true;
        //Specific case of the number, we only trigger the event if both field are filled.
        if ($(this).hasClass('number')) {
          click = false;
          var counterlimit = 'max';
          if ($(this).hasClass('max')) {
            var counterlimit = 'min';
          }
          if ($('#filter_' + counterlimit + '_' + $(this).attr('field')).val() != '' && $(this).val() != '') {
            click = true;
          }
        }
        //Trigger product list reload.
        if (click) {
          $('#filter_table_link').click();
        }
      });

    });



    /*
     * Dynamize the compare buttons.
     */
    $('.compare-button:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        var nid = $(this).attr('nid');
        if (!$(this).hasClass('selected')) {
          //Add it in dictionary
          selectedProducts[nid] = nid;
          $(this).addClass('selected');
        } else {
          delete selectedProducts[nid];
          $(this).removeClass('selected');
          //Empty the Compare now link of this product is displayed.
          $('.compare_link[nid=' + nid + ']').html('');
        }

        refreshCompareUrl();
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

      var aj_settings = {};
      if (action == 'submit_infofield') {
        aj_settings['context'] = $(this).attr('context');
      }

      //Build ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, action, aj_settings);
    });



    /*
     * When we click on toogle fastaction in footer.
     */
    $('#fastaction-footer:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        if (!$(this).hasClass('selected')) {
          $(this).addClass('selected');
        } else {
          $(this).removeClass('selected');
          //Remove the displayed fastaction item.
          $('.fastaction_item').remove();
        }
        //Launch ajax link.
        $('#toogle_fastaction_link').click();
      });
    });



    /*
     * Launch a cleaning ajax call when we check a state checkbox, to reset the tables if necessary.
     */
    $('#state-draft-footer:not(.listener_set),#state-closed-footer:not(.listener_set)').addClass('listener_set').each(function () {
      //Set the onclick event
      $(this).click(function() {
        if (!$(this).hasClass('selected')) {
          $(this).addClass('selected');
        } else {
          $(this).removeClass('selected');
        }
        $('#make_cleaning_link').click();
      });
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
     * Ajaxify the links which open dialog on the left or right side of the page.
     */
    $('.dialog:not(.ajax-processed)').addClass('ajax-processed').each(function () {
      //Get the link id and the ajax action which will be build.
      var aj_settings = {}
      var link_id = $(this).attr('id');
      aj_settings['dialog_action'] = $(this).attr('action');
      aj_settings['type'] = $(this).attr('ntype');
      aj_settings['context'] = $(this).attr('context');
      aj_settings['container'] = $(this).attr('container');
      aj_settings['side'] = $(this).attr('side');
      aj_settings['field'] = $(this).attr('field');
      aj_settings['fastaction'] = $(this).attr('fastaction');
//TODO use directly the .attr in the ajax function, thanks to this we'll probably be able to centralise most of the functions
      //Build ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'open_dialog', aj_settings);
    });



    /*
     * Dynamize the link to close the dialog.
     */
    $('.close_dialog:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        var side = $(this).attr('side');
        $('#' + side + '_dialog').css("transform","translateX(0%)");
        $('#' + side + '_dialog').addClass('to_remove');

        return false;
      });
    });



    /*
     * Dynamize the compare product link in footer, to display or hide the product list in table.
     */
    $('#compare-link-footer:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).click(function() {
        var sign = '';
        if (!$(this).hasClass('displayed')) {
          $(this).addClass('displayed');
        } else {
          $(this).removeClass('displayed');
          //Change sign so the dialog will be hide
          sign = '-';
          //Close all displayed product.
          $('.product_table_link:.displayed').click();
        }
        //Translate the dialog to display or hide it.
        $('#comparative_table_main_product').css('transform','translateX(' + sign + '100%)');
      });
      //Initiate the number of product displayed in the table.
      $('#nb-products-footer').html($('.header_product').length);
    });



    /*
     * Initiate Charts
     */
    $('.chart:not(.listener_set)').addClass('listener_set').each(function () {
      var ctx = $(this).get(0).getContext("2d");
      var percent = parseFloat($(this).attr('percent'));

      //Get background color.
      var color = '#fafafa';
      if ($(this).closest(".odd").length) { //TODO not work
        color = '#f1f1f1';
      }

      //Build data
      var data = [
        {
          value: percent,
          color: "#b7cf37"
        },
        {
          value : 100 - percent,
          color : "#cb5f34"
        }
      ];

      //Build Chart
      var myNewChart = new Chart(ctx).Doughnut(data, {
        //Color of segment.
        segmentStrokeColor : color,
        //Width of segment
	      segmentStrokeWidth : 1,
        //The space in the chart take 70% of the chart.
	      percentageInnerCutout : 70,
        //Animation duration.
	      animationSteps : 75,
        //Animation type.
        animationEasing : "easeOutQuart",
      });
    });



    /*
     * Animate suggest slideshow on home page
     */
    $('#suggest-slideshow:not(.listener_set)').addClass('listener_set').each(function () {
      setInterval(function(){ 
        $('#suggest-slideshow').animate({marginTop:'-' + suggest_height + 'em'},800,function(){  //
           $('#suggest-slideshow').css({marginTop:0}).find("li:last").after($('#suggest-slideshow').find("li:first"));  
        }) 
      }, 10000);  
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
      var aj_settings = {};
      aj_settings['type'] = $('#dialog_type').text();
      //Active the code
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'select_dialog', aj_settings);
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

      var aj_settings = {};
      aj_settings['type'] = $(this).attr('type');
      aj_settings['fastaction'] = $(this).attr('fastaction');
      aj_settings['side'] = $(this).attr('side');
      //Build ajax link.
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'submit_fastaction_form', aj_settings);
    });



    /*
     * Dynamize the type field in infofield form to display allowed value field.
     */
    $('#form_infofield_type:not(.listener_set)').addClass('listener_set').each(function () {
      $(this).change(function() {
        //If we select the select type, we display the allowed value and filter type field.
        if ($(this).val() == 'select') {
          $('#allowed_values_field_div').show();
          $('#filter_type_field_div').show();
        //Else we make sure the fields are hidden.
        } else {
          $('#allowed_values_field_div').hide();
          $('#filter_type_field_div').hide();
        }
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
      Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'compute_inherit', {});
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
    function build_ajax_link(link_id, object, action, aj_settings) {

      //Theses functions does not have nid and so would cause some problem. For example, they would disable the simple_dialog links.
      if (action != 'append_product_list' && action != 'open_dialog' && action != 'submit_dialog' && action != 'submit_infofield' && action != 'refresh_list' && action != 'toogle_fastaction' && action != 'make_cleaning') {
        //Recover the nid by using a regular expression on the link_id.
        var nid = extract_nid(link_id)[0];
      }
//TODO Move in send_nid. Argh we need the nid in the action if, maybe I can try just letting the var nid in any case.

      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(object).attr('href')) {
        element_settings.url = $(object).attr('href');
        element_settings.event = 'click';
      }

      //Create the ajax event
      var ajax = new Drupal.ajax(link_id, object, element_settings);



      //The eventResponse function is the main function which launch the ajax call, and call beforeSerialize. We will override it to block the ajax call if only our specific code need to be processed, without the ajax call.
      ajax.old_eventResponse = ajax.eventResponse;
      ajax.eventResponse = function (element, event) {

        //Get type and context, which are standard variables, from aj_settings.
        type = aj_settings['type'];
        context = aj_settings['context'];

        skip_ajax = false;

        //We can't remove directly at cleaning otherwise some content will be remove before the end of animation (slideUp, etc...)
        if (action != 'make_cleaning') {
          //We remove all old elements so they can't perturb the next events.
          $('.to_remove').remove();
        }

        if (action == 'expand_list_children') {
          //Stored itemlist under children div.
          if ($('#' + type + '_' + context + '_children_' + nid).hasClass('stored')) {
            skip_ajax = true;
          }

          //Stored itemlist in the stored zone.
          if ($('#' + link_id).hasClass('translate') && $('#itemlist_stored_' + nid).length) {
            skip_ajax = true;
          }

          //List in tree mode.
          if (context == 'list' && ($('#' + link_id).hasClass('displayed') || $('#' + link_id).hasClass('stored'))) {
            skip_ajax = true;
          }

        }

        if (action == 'toogle_product_checkbox' && $('#' + link_id).hasClass('displayed')) {
//TODO try replacing $('#' + link_id) by $(object)
          skip_ajax = true;
        }

        if (action == 'expand_row_children') {
          //We zap the ajax if the table is already in the storage zone.
          if ($('#comparative_table_stored_' + nid).length) {
            skip_ajax = true;
          }
        }

/*        if (action == 'open_dialog') {
          skip_ajax = true; //TODO product in comparative table
        }*/


        if (skip_ajax) {
          //We call our specific code.
          ajax.beforeSerialize(element, ajax.options);
          ajax.success('', '');
          //We block the rest of the ajax call.
          return false;
        } else {
          //Launch regular eventResponse function.
          return this.old_eventResponse(element, event);
        }

      }



      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal.
      ajax.old_beforeSerialize = ajax.beforeSerialize;
      ajax.beforeSerialize = function (element, options) {

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
        send_side = false;
        send_infofields = false;
        send_filters = false;
        send_manual_selected_criterions = false;
        send_selected_profiles = false;
        send_states = false;
        send_forbidden_nid = false;
        send_container = false;
        send_colspan = false;
        auto_colspan = false;
        send_fastaction = false;
        send_control = {};
        computed = 0;
        column_number = 0;
        depth = 0;

        //When we want to display the children in an itemlist.
        if (action == 'expand_list_children') {
          //Send the parent_id so we retrieve the children.
          send_nid = true;
          //Send the flag, so we know if we display or hide the children.
          manage_displayed_flag = true;
          //Send the product displayed in the table, so in case of product table we can checked the already displayed items.
          send_products_columns = true;
          //Send the tree mode flag for the list children expand.
          send_products_tree_mode = true;
          //Send states if we want to also display the draft and closed items.
          send_states = true;
          //In popin, we may have to block a forbidden nid.
          send_forbidden_nid = true;
          send_fastaction = true;
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

          //If we display the children with translation effect, drupal need to know it.
          if ($('#' + link_id).hasClass('translate')) {
            options.data.translate = true;
            depth = get_table_depth('.itemlist_return_link');
            options.data.depth = depth;
          }

          if (context == 'list') {
            send_infofields = true;
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
          send_fastaction = true;
          //The table will be clean after the operation.
          make_cleaning = true;

          //Get the depth of the table.
          depth = get_table_depth('.breadcrumb_item');
          options.data.depth = depth;

          //Get the height of the table, to know if we need to augment it because of the loaded content.
          options.data.table_height = $('#comparative_tables').height();
        }

        if (action == 'append_product_list') {
          send_computed = true;
          send_manual_selected_criterions = true;
          send_selected_profiles = true;
          send_products_tree_mode = true;
          send_infofields = true;
          send_filters = true;

          //Send all product already listed, so we don't append them again.
          var product_listed_ids = {};
          $('.product_list_item').each(function (key, value) {
            var pid = $(this).attr('nid');
            product_listed_ids[pid] = pid;
          });
          options.data.product_listed_ids = product_listed_ids;

          //Send the minimum percent displayed, to avoid adding a product with a higher percent in the middle of the list.
          options.data.last_percent = $('.product_list_item:last .chart-percent').text();
        }

        //When we want to add a new column in the table.
        if (action == 'toogle_product_checkbox') {
          //Send the nid of the product to add.
          send_nid = true;
          //Send the flag, so we know if we display or hide the column.
          manage_displayed_flag = true;
          //Send the number of displayed products. This value is used to compute the new column width.
          send_products_columns = true;
          //Send the infofields displayed in the page.
          send_infofields = true;
          //Verify if the table was computed, in such case the data need to be computed with the selected criterion.
          send_computed = true;
          //Send the criterion displayed in the table, so we directly add the cells for these row in the new column.
          send_criterions = true;
          //Resize all lines to the new size of the table.
          auto_colspan = true;
          send_fastaction = true;
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
          //Send side to close the dialog.
          send_side = true;
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
          //Send side to close the dialog.
          send_side = true;
        }

        //If we launched the table computation.
        if (action == 'refresh_list') {
          //Send the product displayed in the table, they'll keep display in the new table.
          send_products_columns = true;
          //Send the criterions manually selected, they'll be used to select the computed criterions.
          send_manual_selected_criterions = true;
          //Send the selected profile. Their criterions will be used to select the computed criterions.
          send_selected_profiles = true;
          //Send products mode.
          send_products_tree_mode = true;
          //Send infofields.
          send_infofields = true;
          //Send filters.
          send_filters = true;
          //Send the states.
          send_states = true;
          //Send the size of the table to adjust the lines.
          send_colspan = true;
          //Verify if the table was computed.
          send_computed = true;
          //Clean the table after the computation.
          make_cleaning = true;

          var mode = $(object).attr('mode');
          if (mode == 'compute') {
            //Change the computed status.
            $('#computed').html(1);
          }
          if (mode == 'reset') {
            //Change the computed status.
            $('#computed').html(0);
          }
          if (mode == 'toogle_product_mode') {
            if ($('#products_tree_mode').text() == 0) {
              $('#products_tree_mode').html(1);
            } else {
              $('#products_tree_mode').html(0);
            }
          }

        }

        //If we want to display a dialog on left or right side.
        if (action == 'open_dialog') {

          //Depending of the side of the dialog, the position change.
          var position = '-30';
          if (aj_settings['side'] == 'right') {
            position = '100';
          }

          //Add the container outside of the page.
          $('body').append('<div id="' + aj_settings['side'] + '_dialog" class="wikicompare-dialog" style="left: ' + position + '%;"><div id="' + aj_settings['side'] + '_dialog_content" class="wikicompare-dialog-content"><p style="text-align: right;"><a href="/" id="' + aj_settings['side'] + '_dialog_close" class="close_dialog" side="' + aj_settings['side'] + '">Close</a></p></div></div>');

          //Send the type of the node.
          send_type = true;
          send_side = true;
          options.data.context = context;
          options.data.container = aj_settings['container'];

          if (aj_settings['dialog_action'] == 'infofields') {
            //Return the field we want to modify.
            if (context != 'add') {
              options.data.field = aj_settings['field'];
            }
          }

          if (aj_settings['dialog_action'] == 'select_manual_criterions') {
            options.data.displayed_ids = manual_selected_criterion_ids;
          }

          if (aj_settings['dialog_action'] == 'selectdialog' || aj_settings['dialog_action'] == 'select_criterions_profile') {
            options.data.action = aj_settings['dialog_action'];
            options.data.nid = $('#' + link_id).attr('nid');
          }

          if (aj_settings['dialog_action'] == 'fastaction') {
            nid = $('#' + link_id).attr('nid'); //TODO 
            //Send the nid of the form.
            send_nid = true;
            //Send the type of the node.
            send_type = true;
            //Send the fastaction (add, edit, remove).
            options.data.fastaction = aj_settings['fastaction'];
            options.data.parent_id = $('#' + link_id).attr('parent_id');
          }

        }

        if (action == 'submit_fastaction_form') {

          //Send the nid of the node.
          send_nid = true;
          //Send the type of the node.
          send_type = true;
          //Send the fastaction (add, edit, remove).
          options.data.action = aj_settings['fastaction'];
          //Send dialog side.
          send_side = true;

          //Prepare data for the control function.
          options.data.control_mode = 'nid';
          options.data.control_type = type;
          options.data.control_nid = nid;
          options.data.control_parent_id = $('#wikicompare-parent-id').text();
          if (options.data.control_parent_id == 0) {
            options.data.control_parent_id = '';
          }
          if (options.data.control_parent_id != $('#wikicompare-old-parent-id').text()) {
            options.data.control_old_parent_id = $('#wikicompare-old-parent-id').text();
          }

          //Get value of all fields in the fastaction form, and send them to Drupal.
          if (type != 'evaluation') {
            options.data.title = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_title_' + nid).val();
            options.data.title_translation = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_title_' + nid + '_translation').val();
            options.data.parent_id = options.data.control_parent_id;
            options.data.sequence = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_sequence_' + nid).val();
            options.data.state = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_state_' + nid).val();
          }
          options.data.description = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_description_' + nid).val();
          options.data.description_translation = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_description_' + nid + '_translation').val();
          if (type == 'product') {
            options.data.product_comparable = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_comparable_' + nid).val();
            var fastaction_infofields = {};
            var i = 0;
            $('.fastaction_infofield').each(function (key, value) {
              infofield = {};
              infofield['name'] = $(this).attr('field');
              infofield['value'] = $(this).val();
              infofield['required'] = $(this).attr('required');
              fastaction_infofields[i] = infofield;
              i = i + 1;
            });
            options.data.fastaction_infofields = fastaction_infofields;
            options.data.inherit_id = $('#wikicompare-inherit-product-id').text();
          }
          if (type == 'criterion') {
            options.data.criterion_type = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_type_' + nid).val();
            options.data.guidelines = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_guidelines_' + nid).val();
            options.data.guidelines_translation = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_guidelines_' + nid + '_translation').val();
            options.data.weight = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_weight_' + nid).val();
            options.data.suggest = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_suggest_' + nid).val();
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
          options.data.revision = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_revision_' + nid).val();
          options.data.selectnode = $('#form_' + type + '_fast' + aj_settings['fastaction'] + '_selectnode_' + nid).val();
        }

        //If we are submitting the infofield form, return the values of the form.
        if (action == 'submit_infofield') {
          options.data.context = context;
          options.data.name = $('#form_infofield_name').val();
          options.data.title = $('#form_infofield_title').val();
          options.data.type = $('#form_infofield_type').val();
          options.data.allowed_values = $('#form_infofield_allowed_values').val();
          options.data.sequence = $('#form_infofield_sequence').val();
          options.data.is_required = $('#form_infofield_is_required').val();
          options.data.is_active = $('#form_infofield_is_active').val();
          options.data.is_home = $('#form_infofield_is_home').val();
          options.data.is_filter = $('#form_infofield_is_filter').val();
          options.data.filter_type = $('#form_infofield_filter_type').val();
          options.data.category = $('#form_infofield_category').val();
          options.data.category_sequence = $('#form_infofield_category_sequence').val();
        }

        //If we are updating the support value in evaluation form.
        if (action == 'compute_inherit') {
          //Send evaluation value.
          send_nid = true;
          //Send value of use_from_inherit field.
          options.data.use_from_inherit = $('#edit-wikicompare-use-from-inherit-und').attr('checked');
        }

        if (action == 'toogle_fastaction') {
          options.data.control_mode = 'toogle_fastaction';
        }

        //If we want to clean the table.
        if (typeof(options.data.control_mode) != 'undefined') {

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
          send_fastaction = true;

//TODO centralize with send_criterions
          var criterion_ids = {};
          $('.criterion_item').each(function (key, value) {
            var fid = extract_nid($(this).attr('id'))[0];
            criterion_ids[fid] = fid;
          });
          //Add them in the ajax call variables.
          options.data.criterion_complete_ids = criterion_ids;

          //We will send all nodes in the cleaning function, and check which parent is displaying his children.
          var a = ['product', 'criterion', 'profile'];
          //If a type is defined, we will only control this type.
          if (typeof(options.data.control_type) != 'undefined') {
            a = [type];
          }
          for (index = 0; index < a.length; ++index) {

            //The node type we are working on.
            var ftype = a[index];
            var node_ids = {};
            //Get the items in table.
            var selector = '.' + ftype + '_item';
            if (typeof(options.data.control_nid) != 'undefined') {
              c = selector;
              selector = selector + '[nid=' + options.data.control_nid + ']';
              //If parent_id, we want to select it in item so we can change his supertitle is has_children changed and his children to know if his children changed.
              if (typeof(options.data.control_parent_id) != 'undefined') {
                selector = selector + ',' + c + '[parent_id=' + options.data.control_parent_id + '],' + c + '[nid=' + options.data.control_parent_id + ']';
                //Same for the old parent.
                if (typeof(options.data.control_old_parent_id) != 'undefined') {
                  selector = selector + ',' + c + '[parent_id=' + options.data.control_old_parent_id + '],' + c + '[nid=' + options.data.control_old_parent_id + ']';
                }
              }
            }

            //Get nid, parent_id and has_children flag of all the items.
            $(selector).each(function (key, value) {
              //Extract nid.
              inid = extract_nid($(this).attr('id'))[0];
              node_ids[inid] = {};
              //Assign the nid.
              node_ids[inid]['nid'] = inid;
              node_ids[inid]['parent_id'] = $(this).attr('parent_id');
              //Check if the node has children.
              node_ids[inid]['has_children'] = 0;
              if ($(this).hasClass('has_children')) {
                node_ids[inid]['has_children'] = 1;
              }
            });
            //Add them in the ajax call variables.
            options.data[ftype + '_ids'] = node_ids;

            //Then we need to find which item are displaying his children.
            var node_displayed_ids = {};
            var selector = '.' + ftype + '_table_link';
            //If nid mode, we only check the parent.
            if (typeof(options.data.control_nid) != 'undefined') {
              var c = selector;
              selector = c + '[nid=' + options.data.control_parent_id + ']';
              //And the old parent.
              if (typeof(options.data.control_old_parent_id) != 'undefined') {
                selector = c + ',' + c + '[nid=' + options.data.control_old_parent_id + ']';
              }
            }

            //For each item which have children (since they have link).
            $(selector).each(function (key, value) {
              //Check if the item is displaying his children.
              if ($(this).hasClass('displayed')) {
                //Extract nid.
                var inid = extract_nid($(this).attr('id'))[0];
                node_displayed_ids[inid] = inid;
              }
            });
            //Add them in the ajax call variables
            options.data[ftype + '_displayed_ids'] = node_displayed_ids;

            //Get the fastaction add so we can set their fastadd picture.
            var fastaction_adds = {};
            $('.link_fastaction[ntype=' + ftype + ']').each(function (key, value) {
              fastaction_adds[$(this).attr('nid')] = $(this).attr('nid');
            });
            options.data[ftype + '_fastaction_adds'] = fastaction_adds;

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
          computed = $('#computed').text();
          options.data.computed = computed;
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

          $('.header_product').each(function (key, value) {
            if (!$(this).hasClass('to_remove')) {
              var cid = extract_nid($(this).attr('id'))[0];
              product_column_ids[column_number] = cid;
              column_number = column_number + 1;
            }
          });
          //Add them in the ajax call variables.
          options.data.product_column_ids = product_column_ids;
          //Each time we send the product_column, we also need the width of the columns.
          options.data.width = (100 - first_column_width) / (column_number);
        }

        //Get and send the criterions in the table.
        if (send_criterions == true) {
          var criterion_ids = {};
          $('.criterion_item').each(function (key, value) {
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

        //Send product list mode.
        if (send_products_tree_mode == true) {
          options.data.products_tree_mode = $('#products_tree_mode').text();
        }

        if (send_side == true) {
          options.data.side = $('#' + link_id).attr('side');
        }

        //Send infofields, based on the displayed column / row which mean we use the infofield used at the page loading. This should prevent error if a user load a page while the admin is modify infofields sequence.
        if (send_infofields == true) {
          var infofields = [];
          var i = 0;
          $('.infofield_title').each(function (key, value) {
            infofields[i] = {};
            infofields[i]['name'] = $(this).attr('field');
            infofields[i]['title'] = $(this).text();
            i = i + 1;
          });
          options.data.infofields = infofields;
        }

        if (send_filters == true) {
          //Send the value of all filled filters.
          var filters = {};
          $('.home_filter').each(function(index) {
            //Text filter
            if  ($(this).hasClass('text') && $(this).val() != '') {
              filters[$(this).attr('field')] = {};
              filters[$(this).attr('field')]['type'] = 'text';
              filters[$(this).attr('field')]['value'] = $(this).val();
            }
            //Number filter.
            if ($(this).hasClass('number') && $(this).hasClass('min') && $(this).val() != '') {
              if ($('#filter_max_' + $(this).attr('field')).val() != '') {
                filters[$(this).attr('field')] = {};
                filters[$(this).attr('field')]['type'] = 'number';
                filters[$(this).attr('field')]['min'] = $(this).val();
                filters[$(this).attr('field')]['max'] = $('#filter_max_' + $(this).attr('field')).val();
              }
            }
            //Select filter.
            if ($(this).is('select') && $(this).val() != '') {
              filters[$(this).attr('field')] = {};
              filters[$(this).attr('field')]['type'] = 'select';
              filters[$(this).attr('field')]['value'] = $(this).val();
            }
            //Checkboxes filter.
            if  ($(this).attr('type') == 'checkbox' && $(this).is(':checked')) {
              if (!($(this).attr('field') in filters)) {
                filters[$(this).attr('field')] = {};
                filters[$(this).attr('field')]['type'] = 'checkboxes';
                filters[$(this).attr('field')]['values'] = {};
              }
              filters[$(this).attr('field')]['values'][$(this).attr('value')] = $(this).attr('value');
            }
          });
          options.data.filters = filters;
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

        if (send_fastaction == true) {
          var fastaction = 0;
          if ($('#fastaction-footer').hasClass('selected')) {
            fastaction = 1;
          }
          //Send the fastaction flag, so drupal know if the fastaction mode is activated.
          options.data.fastaction = fastaction;
        }

        //Launch regular beforeSerialize function, only if we are not skipping the ajax call.
        if (!skip_ajax) {
          this.old_beforeSerialize(element, options);
        }

      }


      //The success function is launched when drupal return the commands. We will override it to add some other commands.
      ajax.old_success = ajax.success;
      ajax.success = function (response, status) {

        //First launch regular success function, only if we are not skipping the ajax call.
        if (!skip_ajax) {
          this.old_success(response, status);
        }

        //If the ajax link of of type active/disactive.
        if (manage_displayed_flag == true) {

          //If we are displaying the elements.
          if (!$('#' + link_id).hasClass('displayed')) {

            //Change the class link, so next time we click on this link it will hide the content
            $('#' + link_id).addClass('displayed');

            //The children are here but hidden, we display them with a slideDown animation.
            if (action == 'expand_list_children') {

              if (context != 'list') {

                //Standard case.
                if (!$('#' + link_id).hasClass('translate')) {

                  //For each line in checked zone.
                  $('#' + type + '_' + context + '_children_checked_' + nid + '>ul>li').each(function(index) {
                    //We replace each line in children zone by the line from checked zone, to keep the checked children information and other stuff.
                    $('#' + type + '_' + context + '_children_' + nid + ' li[context=' + context + '][nid=' + $(this).attr('nid') + ']').replaceWith($(this).clone());
                    //Then we remove all data in checked zone, to prevent them to catch the selector of others functions.
                    $('#' + type + '_' + context + '_children_checked_' + nid + ' #' + $(this).attr('id') + ' *').addClass('to_remove');
                    //In itemlist, we switch normal and simple title. Simple titles doesn't have link to display children.
                    $('#' + type + '_' + context + '_children_' + nid + ' .simpletitle[ntype=' + type + '][context=' + context + '][nid=' + $(this).attr('nid') + ']').hide();
                    $('#' + type + '_' + context + '_children_' + nid + ' .normaltitle[ntype=' + type + '][context=' + context + '][nid=' + $(this).attr('nid') + ']').show();

                    //Since we only copy it, we need to remove the listener class on checkbox and link so they can have their own listener.
                    $('#' + type + '_' + context + '_children_' + nid + ' li[context=' + context + '][nid=' + $(this).attr('nid') + '] .listener_set').removeClass('listener_set');
                    $('#' + type + '_' + context + '_children_' + nid + ' li[context=' + context + '][nid=' + $(this).attr('nid') + '] .ajax-processed').removeClass('ajax-processed');
  //TODO centralize listener_set and ajax-processed
                  });

                  //Switch children zone and checked zone.
                  $('#' + type + '_' + context + '_children_checked_' + nid).slideUp(600);
                  $('#' + type + '_' + context + '_children_' + nid).slideDown(600);

                  //Search for all displayed items. If not a parent of this node, we close it.
                  var parent_ids = get_parent_ids(nid, type, context);
                  $('.item_link:.displayed[ntype=' + type + '][context=' + context + '][nid!=' + nid + ']').each(function(index) {
                    if (!($(this).attr('nid') in parent_ids)) {
                      $(this).click();
                    }
                  });

                  //We are in a dialog, we update the scroll bar.
                  $('#left_dialog').mCustomScrollbar("update");

                //Display itemlist with translation effect.
                } else {

                  //We are adding a new depth level.
                  depth = depth + 1;

                  //Get the div from the storage zone.
                  var div = '<div id="itemlist_' + depth + '" nid="' + nid + '" class="itemlist_translate" style="left:' + depth * 100 + '%;">';
//TODO remove                  div += '<a href="/" id="main_' + type + '_itemlist_return_link_' + depth + '" class="itemlist_return_link" nid="' + nid + '" ntype="' + type + '">Return</a><br/>';
                  div += $('#itemlist_stored_' + nid).html();
                  div += '</div>';
                  //Attach the table after the displayed table.
                  $('#main_' + type + '_itemlists').append(div);

                  //Check the marked checkbox.
                  $('.itemlist_checkbox[ntype=' + type + '][context=' + context + '][parent_id=' + nid + ']').each(function(index) {
                    var check = false;

                    //In main profile itemlist, we check if the profile isn't already in the selected_profile_ids.
                    if (type == 'profile' && context == 'table') {
                      if ($(this).attr('nid') in selected_profile_ids) {
                        check = true;
                      }
                    }

                    //If true, we check the checkbox and make sure his parent know they have a checked children.
                    if (check) {
                      $('.itemlist_checkbox[ntype=' + type + '][context=' + context + '][nid=' + $(this).attr('nid') + ']').attr('checked', 'checked');
                      parent_checked_children('check', type, context, $(this).attr('nid'));
                    }
                  });

                  //Slide the tables to display the new one.
                  $('#main_' + type + '_itemlists').css("transform","translateX(-" + (depth) * 100 + "%)");
                }

              //Product list.
              } else {
                $('#' + link_id).addClass('stored');
                $('.product_list_item[parent_id=' + nid + ']').show();
//TODO collapse other displayed item, like we did in itemlist
                //Refresh oddeven.
                odd_even_product_list('.product_list_item');
              }

            }

            if (action == 'toogle_product_checkbox') {
              //We reduce the column width to make the place for the new column, with a css transform animation.
              var width = (100 - first_column_width) / (column_number + 1);
              $('.header_product').css("width", width + '%');
              $('.evaluation_cell').css("width", width + '%');
              $('.infofield_product').css("width", width + '%');

              //The content of the cells will break the start of the width animation so we display:none; it. Just before the end of the width animation, we start a very short fadeIn to display the content.
              $('.width_div_' + nid).delay(400).fadeIn(200);

              //We disactivated the product checkbox during the ajax call to avoid user spamming, reactivate it.
              $('#product_table_checkbox_' + nid).removeAttr('disabled');
            }

          //When we want to hide the children.
          //I'd like to move this case out of this ajax function so the children removing would be manage only by javascript, without making a useless ajax call. Unfortunately, the ajax call is made each time we click on the link, so I found no solution.
          } else {

            //Change the class link, so next time we click on this link it will display the content
            $('#' + link_id).removeClass('displayed');

            if (action == 'expand_list_children') {
              if (context != 'list') {
                //Fill the checked zone with a copy of the checked item in children zone.
                $('#' + type + '_' + context + '_children_checked_' + nid).empty();
                $('#' + type + '_' + context + '_children_checked_' + nid).append('<ul></ul>');

                //For each checked line in children zone.
                $('.' + type + '_item:.has_checked_children[context=' + context + '][parent_id=' + nid + ']').each(function (key, value) {
                  //Append the item to the checked zone. The first is important because we are adding item containing ul, otherwise the second item will be add to the first etc...
                  $('#' + type + '_' + context + '_children_checked_' + nid + ' ul').first().append($(this).clone());
                  //Then we remove all checked link in children zone, to prevent them to catch the selector of others functions.
                  $('#' + type + '_' + context + '_children_' + nid + ' #' + $(this).attr('id') + ' *').addClass('to_remove');
                  //In itemlist, we switch normal and simple title. Simple titles doesn't have link to display children.
                  $('#' + type + '_' + context + '_children_checked_' + nid + ' .normaltitle[ntype=' + type + '][context=' + context + '][nid=' + $(this).attr('nid') + ']').hide();
                  $('#' + type + '_' + context + '_children_checked_' + nid + ' .simpletitle[ntype=' + type + '][context=' + context + '][nid=' + $(this).attr('nid') + ']').show();

                  //Since we only copy it, we need to remove the listener class on checkbox and link so they can have their own listener.
                  $('#' + type + '_' + context + '_children_checked_' + nid + ' .' + type + '_item:.has_checked_children[context=' + context + '][parent_id=' + nid + '] .listener_set').removeClass('listener_set');
                  $('#' + type + '_' + context + '_children_checked_' + nid + ' .' + type + '_item:.has_checked_children[context=' + context + '][parent_id=' + nid + '] .ajax-processed').removeClass('ajax-processed');
                });

                //Switch checked and children zone.
                $('#' + type + '_' + context + '_children_' + nid).slideUp(600);
                $('#' + type + '_' + context + '_children_checked_' + nid).slideDown(600);

                if (!$('#' + link_id).hasClass('translate')) {
                  //We are in a dialog, we update the scroll bar.
                  $('#left_dialog').mCustomScrollbar("update");
                }

              } else {
                remove_children_tree2(nid, '#product_list_link_', '.product_list_item', true);
                //Refresh oddeven.
                odd_even_product_list('.product_list_item');
              }
            }

            if (action == 'toogle_product_checkbox') {

              //Hide the column. We can't use animation because of the current template, to check when we will have the final template
              //We immediately start a short fadeOut so it'll not crash the width animation.
              $('.width_div_' + nid).fadeOut(200);

              //We start the animation to hide the removed column. We use a css transform for this.
              $('#header_product_' + nid).css("width", '0%');
              $('.evaluation_product_' + nid).css("width", '0%');
              $('.infofield_product_' + nid).css("width", '0%');

              //We find the new width of the others columns, and start the animation to adjust it.
              var width = (100 - first_column_width) / (column_number - 1);
              $('.header_product:not(#header_product_' + nid + ')').css("width", width + '%');
              $('.evaluation_cell:not(.evaluation_product_' + nid + ')').css("width", width + '%');
              $('.infofield_product:not(.infofield_product_' + nid + ')').css("width", width + '%');

              //Mark the hidded content for removal.
              $('#header_product_' + nid).addClass('to_remove');
              $('.evaluation_product_' + nid).addClass('to_remove');
              $('.infofield_product_' + nid).addClass('to_remove');

              //Update product number in footer.
              $('#nb-products-footer').html($('.header_product').length - 1);

              //We disactivated the product checkbox during the ajax call to avoid user spamming, reactivate it. We use a class base because the checkbox to reactive can be the one on checked zone or the one on children zone.
              $('.itemlist_checkbox[ntype=product][context=table][nid=' + nid + ']').removeAttr('disabled');

            }

          }

        }

        //Initialize the selected_criterions_ids when we open a profile fastaction form. Not the same variable than manual_selected_criterions_ids to avoid conflict.
        if (action == 'open_dialog' && aj_settings['fastaction']) {
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

        if (action == 'append_product_list') {
          //Refresh the offset with the value of the last loaded product.
          offset = $('.product_list_item:last').offset();
          //Refresh oddeven.
          odd_even_product_list('.product_list_item');
          //We can now scroll and append new products.
          load = false;
        }

        if (action == 'refresh_list') {
          //Refresh oddeven.
          odd_even_product_list('.product_list_item');
        }

        if (action == 'expand_row_children') {
          //We are adding a new depth level.
          depth = depth + 1;

          //Get the table from the storage zone.
          var table = '<table id="comparative_table_' + depth + '" nid="' + nid + '" style="float:left; position:absolute; top: 0; left:' + depth * row_height + '%;">';
          table += $('#comparative_table_stored_' + nid).html();
          table += '</table>';
          //Attach the table after the displayed table.
          $('#comparative_tables').append(table);

          //Slide the tables to display the new one.
          $("#comparative_tables").css("transform","translateX(-" + (depth) * 100 + "%)");

          //Add the link in the breadcrumb to return on previous levels.
          var backlink = '<span id="breadcrumb_item_' + depth + '" class="breadcrumb_item" style="display:none;">';
          if (depth != 1) {
            backlink += ' / ';
          }
          backlink += '<a href="/" id="breadcrumb_item_link_' + depth + '" class="breadcrumb_item_link" nid="' + nid + '">' + $('.criterion_title_' + nid).html() + '</a></span>';
          $('#breadcrumb_zone').append(backlink);
          //We display it with a fadeIn.
          $("#breadcrumb_item_" + (depth)).fadeIn();

          //Refresh oddeven, especially for the new table.
          odd_even_product_list('.criterion_item');

        }

        if (action == 'open_dialog') {

          //We add the scrollbar only now because before we didn't had the content and so the scrollbar size.
          $('#' + aj_settings['side'] + '_dialog').addClass('with-custom-scrollbar');

          //Depending of the side, we change the translate direction.
          var sign = '';
          if (aj_settings['side'] == 'right') {
            sign = '-';
          }

          //Translate the dialog to display it.
          $('#' + aj_settings['side'] + '_dialog').css('transform','translateX(' + sign + '100%)');
        }


        //Adjust the lines to the new size of the table, when we add a new column.
        if (auto_colspan == true) {
          colspan = $('.header_product').length + 1;
          $('.row_auto_colspan').attr('colspan', colspan);
        }

        //We need to call this function to add the listeners on the added content. It is often called by the Drupal functions, but by calling it here we are sure about it.
        Drupal.attachBehaviors(context, settings);

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
//TODO set nid as attribute so we don't need this function anymore
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
    function remove_children_tree2(nid, link_prefix, children_prefix, computed) {
      //For all children.
      $(children_prefix + '[parent_id=' + nid + ']').each(function(index) {
        //Get nid of the child.
        var child_nid = extract_nid($(this).attr('id'))[0];
        //Recursively launch the function to hide the children of the child.
        remove_children_tree2(child_nid, link_prefix, children_prefix, computed);
      });
      //Hide the children. Later replace the hide by an animation, slideUp for exemple.
      $(children_prefix + '[parent_id=' + nid + ']').hide();
      //Remove the display flag in the parent link.
      $(link_prefix + nid).removeClass('displayed');
      //Remove the children from the page, only if it was not computed.
      if (!computed == true) {
        $(children_prefix + '[parent_id=' + nid + ']').addClass('to_remove');
      } else {
        $(children_prefix + '[parent_id=' + nid + ']').addClass('hidden');
      }
    }
//TODO Replace all link to parent by a parent_id attribute. Best if we do this after the browser debug, I suspect that this custom attribute may be the problem.

    function get_table_depth(dom) {
      var max_depth = 0;
      $(dom + ':not(#storage_zone ' + dom + ')').each(function (key, value) {
        var depth = extract_nid($(this).attr('id'))[0];
        depth = parseInt(depth);
        if (depth > max_depth) {
          max_depth = depth;
        }
      });

      return max_depth;
    }

    /*
     * Function to recursively update the has_checked_children flag on itemlist.
     */
    function parent_checked_children(action, type, context, nid) {

      var test = false;
      var parent_id = $('#' + type + '_' + context + '_item_' + nid).attr('parent_id');

      //If we want the parent to know they have a checked children.
      if (action == 'check') {
        //We mark the current item.
        $('.' + type + '_item[context=' + context + '][nid=' + nid + ']').addClass('has_checked_children');
      //If we are unchecking a children.
      } else {

        //We check if it has other checked children, in this case we save it.
        $('.' + type + '_item[context=' + context + '][parent_id=' + nid + ']').each(function(index) {
          if ($(this).hasClass('has_checked_children')) {
            test = true;
          }
        });
        //If the item is himself checked, we also save it.
        if ($('.itemlist_checkbox[ntype=' + type + '][context=' + context + '][nid=' + nid + ']').is(':checked')) {
          test = true;
        }

        if (!test) {
          //We unmark the current item.
          $('.' + type + '_item[context=' + context + '][nid=' + nid + ']').removeClass('has_checked_children');
          //We hide the item in checked zone and mark it for remove.
          if (type != 'profile' || context != 'table') {
            $('#' + type + '_' + context + '_children_checked_' + parent_id + ' .' + type + '_item[context=' + context + '][nid=' + nid + ']').slideUp();
            $('#' + type + '_' + context + '_children_checked_' + parent_id + ' .' + type + '_item[context=' + context + '][nid=' + nid + ']').addClass('to_remove');
          }
        }

      }

      //Get the parent id, and recursively call the function. We only do it if we are checking or if the current item didn't kept his has_checked_children class.
      if (!test) {
        if (parent_id != 0) {
          parent_checked_children(action, type, context, parent_id)
        }
      }
    }

    /*
     * Function to recursively get a associative array of a given nid.
     */
    function get_parent_ids(current_nid, type, context) {
      var parent_ids = {};
      var parent_id = $('.' + type + '_item[context=' + context + '][nid=' + current_nid + ']').attr('parent_id');
      parent_ids[parent_id] = parent_id;
      if (parent_id != 0) {
        parent_ids = $.extend(parent_ids, get_parent_ids(parent_id, type, context));
      }

      return parent_ids;

    }



    /*
     * Refresh all the links which send to the comparative table.
     */
    function refreshCompareUrl() {
      //If we selected some products.
      if (!jQuery.isEmptyObject(selectedProducts)) {
        //Get prefix from drupal.
        var url = $('#prefix-compare-url').text() + '0/';
        var first = true;
        var i = 0;
        //Concat all selected product nid with -.
        for(var nid in selectedProducts) {
          if (!first) {
            url += '-' + nid;
          } else {
            url += nid;
          }
          first = false;

          i++;
        }
        //Get suffix from drupal.
        url += $('#suffix-compare-url').text();
        //Update number product in footer.
        $('#nb-products-footer').html(i);
        //Make sure we replace Compare Best by Compare products.
        $('#compare-text-footer').html('Compare products');
      //If we selected no products
      } else {
        //Replace the url by the best products url computed by drupal.
        var url = $('#best-compare-url').text();
        //The best product url contain only three products.
        $('#nb-products-footer').html(3);
        //Make sure we replace Compare Best by Compare products.
        $('#compare-text-footer').html('Compare best');
      }

      //We display Compare now links only if two products are selected.
      if (i >= 2) {
        for(var nid in selectedProducts) {
          $('.compare_link[nid=' + nid + ']').html('<a class="compare-url" href="#">Compare now</a>');
        }
      }

      //If less than two products are selected, we remove all Compare now links.
      if (i < 2) {
        $('.compare_link').html('');
      }

      //Attach compare link in footer.
      $('.compare-url').attr('href', url);

    }



    /*
     * Refresh odd even in tables.
     */
    function odd_even_product_list(dom) {

      var oddeven = 'odd';
      var parent_id = '';
      $(dom).each(function(index) {

        if (!$(this).hasClass('hidden')) {
          $(this).removeClass('even');
          $(this).removeClass('odd');

          if (dom != '.product_list_item') {
            //Reinitiate with odd if we start a new table, in comparative table.
            if (parent_id != $(this).attr('parent_id')) {
              oddeven = 'odd';
              parent_id = $(this).attr('parent_id');
            }
          }

          $(this).addClass(oddeven);
          if (oddeven == 'even') {
            oddeven = 'odd';
          } else {
            oddeven = 'even';
          }
        }
      });
    }


    /*
     * Create the styled scrollbar.
     */

    $('.with-custom-scrollbar:not(.mCustomScrollbar)').each(function () {
      $(this).mCustomScrollbar({
        //Almost no inertia.
        scrollInertia:150,
      });
    });



    /*
     * Code executed when we load the home page.
     */
    $('#products_list_column:not(.init-set)').addClass('init-set').each(function () {

      //When the user is scrolling.
      $(window).scroll(function()
      {
        //When we hit the end of the scrollbar in product list, we append new products. Only in standard mode, if another append isn't processin and we didn't already load all the items.
        if (($(window).scrollTop() + $(window).height()) + 150 > $(document).height() && $('#products_tree_mode').text() == 0 && load==false && ($('.product_list_item').size()!=$('#nb_products').text())) {
          //Block another append.
          load = true;
          //Launch append.
          $('#append_product_list_link').click();
        }
      });

      //Refresh oddeven at the end of the page load.
      odd_even_product_list('.product_list_item');
      //Refresh compare url on footer.
      refreshCompareUrl();
    });

    /*
     * Code executed when we load the compare page.
     */
    $('#comparative_table:not(.init-set)').addClass('init-set').each(function () {
      //Refresh oddeven at the end of the page load.
      odd_even_product_list('.criterion_item');
    });

  }
};

//TODO revoir nom function javascript, exemple oddEvenProductList, remplacer _ par - dans les class et id
})(jQuery);
/*TODO For custom attribute :
http://www.electrictoolbox.com/jquery-store-data-in-dom/
http://stackoverflow.com/questions/4191386/jquery-how-to-find-an-element-based-on-a-data-attribute-value
http://stackoverflow.com/questions/1735230/can-i-add-custom-attribute-to-html-tag
*/