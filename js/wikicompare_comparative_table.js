(function ($) {

//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareComparativeTable = {
  attach: function (context, settings) {

    //Ajaxify the compared link
    $('.compared_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $('#' + $(this).attr('id'));

      //Recover the compared_id by using a regular expression on the compared_link
      var patt = /[0-9]+/g;
      var compared_id = patt.exec($(this).attr('id'));

      //Recover the id of the div containing the children
      var children_id = '#compared_children_' + compared_id;

      //Set the class to collapsed at the creation of the compared
      $(this).addClass('collapsed');
  
      //We hide the children div at the creation so the slideDown go without problem
      $(children_id).hide();

      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(this).attr('href')) {
        element_settings.url = $(this).attr('href');
        element_settings.event = 'click';
      }
      var base = $(this).attr('id');
      //Create the ajax event
      var ajax = new Drupal.ajax(base, this, element_settings);

      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal
      ajax.old_beforeSerialize = ajax.beforeSerialize;

      ajax.beforeSerialize = function (element, options) {
        //We remove all hidded element so they can't perturb the computation
        $('.to_remove').remove();
        //Check if fastedit is enabled
        options.data.fastedit_toggled = fastedit_toggled;
        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }
      
      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {
        //First launch regular success function
        this.old_success(response, status);

        //If we are displaying the children
        if ($(link_id).hasClass('collapsed')) {
          //Change the class link, so next time we click on this link it will hide the children
          $(link_id).addClass('expanded');
          $(link_id).removeClass('collapsed');
          //Change the last argument of the callback function
          $(link_id).attr('href', 'get_compared_ajax_callback/nojs/' + compared_id + '/collapse');
          //Display the children with slide animation
          $(children_id).slideDown();
        //If we are hiding the children
        } else {
          //Change the class link, so next time we click on this link it will display the children
          $(link_id).addClass('collapsed');
          $(link_id).removeClass('expanded');
          //Change the last argument of the callback function
          $(link_id).attr('href', 'get_compared_ajax_callback/nojs/' + compared_id + '/expand');
          //Hide the children with slide animation
          $(children_id).slideUp();
        }

      }

      //Active the code
      Drupal.ajax[base] = ajax;
    });




    //Ajaxify the feature link
    $('.feature_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $('#' + $(this).attr('id'));

      //Recover the feature_id by using a regular expression on the feature_link
      var patt = /[0-9]+/g;
      var feature_id = patt.exec($(this).attr('id'));

      //Recover the id of the current row
      var row_id = '#feature_row_' + feature_id;

      //Recover the id of the row children
      var children_id = '.feature_children_' + feature_id;

      //Set the class to collapsed at the creation of the feature
      $(this).addClass('collapsed');

      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(this).attr('href')) {
        element_settings.url = $(this).attr('href');
        element_settings.event = 'click';
      }
      var base = $(this).attr('id');
      //Create the ajax event
      var ajax = new Drupal.ajax(base, this, element_settings);

      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal
      ajax.old_beforeSerialize = ajax.beforeSerialize;

      ajax.beforeSerialize = function (element, options) {
        //We remove all hidded element so they can't perturb the computation
        $('.to_remove').remove();

        //Recover all compared columns displayed in the table to send their id to drupal, in the right order
        var compared_ids = new Array();
        var i = 0;
        $('.header_compared').each(function (key, value) {
          var column_id = $('#' + $(this).attr('id'));
          var patt = /[0-9]+/g;
          compared_ids[i] = patt.exec($(this).attr('id'));
          i = i + 1;
        });
        //Add them in the ajax call variables
        options.data.compared_ids = compared_ids;
        //Check if fastedit is enabled
        options.data.fastedit_toggled = fastedit_toggled;
        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }

      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {
        //First launch regular success function
        this.old_success(response, status);

        //If we are displaying the children
        if ($(link_id).hasClass('collapsed')) {
//TODO RAAAHHHHH Pour une raison qui m'echappe, il renvoi les <tr> dans un div, ce qui fout en l'air le design du tableau. En plus c'est le seul endroit ou il me met ca dans un div, pourquoi?
          //Change the class link, so next time we click on this link it will hide the children
          $(link_id).addClass('expanded');
          $(link_id).removeClass('collapsed');
          //Change the last argument of the callback function
          $(link_id).attr('href', 'get_feature_ajax_callback/nojs/' + feature_id + '/collapse');
          //Display the children with slide animation
          $(children_id).show();
//TODO Les lignes s'affichent instantanement pour une raison qui m'echappe si je met un slideDown(). Utiliser la fonction suivante pour les afficher les unes apres les autres
//http://paulirish.com/2008/sequentially-chain-your-callbacks-in-jquery-two-ways/
/*
          (function shownext(jq){
            jq.eq(0).slideDown("slow", function(){
              (jq=jq.slice(1)).length && hidenext(jq);
            });
          })($(children_id))
*/
        //If we are hiding the children
        } else {
          //Change the class link, so next time we click on this link it will display the children
          $(link_id).addClass('collapsed');
          $(link_id).removeClass('expanded');
//TODO pareil qu'au dessus, 
          //Hide the children with slide animation
          $(children_id).hide();
          //Mark the children row so they will be remove at the next event. We can't do it now because otherwise it will crash the slide animation
          $(children_id).addClass('to_remove');
       }

      }

      //Active the code
      Drupal.ajax[base] = ajax;
    });



    //Ajaxify the compared checkbox link
    $('.compared_checkbox_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $('#' + $(this).attr('id'));

      //Recover the compared_id by using a regular expression on the compared_link
      var patt = /[0-9]+/g;
      var compared_id = patt.exec($(this).attr('id'));

      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(this).attr('href')) {
        element_settings.url = $(this).attr('href');
        element_settings.event = 'click';
      }
      var base = $(this).attr('id');
      //Create the ajax event
      var ajax = new Drupal.ajax(base, this, element_settings);

      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal
      ajax.old_beforeSerialize = ajax.beforeSerialize;

      ajax.beforeSerialize = function (element, options) {
        //We remove all hidded element so they can't perturb the computation
        $('.to_remove').remove();
        //Recover all feature row displayed in the table to send their id to drupal
        var feature_ids = new Array(); 
        var i = 0;
        $('.feature_row').each(function (key, value) {
          var row_id = $('#' + $(this).attr('id'));
          var patt = /[0-9]+/g;
          feature_ids[i] = patt.exec($(this).attr('id'));
          i = i + 1;
        });
        //Add them in the ajax call variables
        options.data.feature_ids = feature_ids;
        //Check if fastedit is enabled
        options.data.fastedit_toggled = fastedit_toggled;
        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }

      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {

        //First launch regular success function	  
        this.old_success(response, status);
        //If we are displaying the column
        if ($(link_id).hasClass('hidden')) {
          //Change the class link, so next time we click on this link it will hide the column
          $(link_id).addClass('displayed');
          $(link_id).removeClass('hidden');
          //Change the last argument of the callback function
          $(link_id).attr('href', 'toogle_compared_checkbox_ajax_callback/nojs/' + compared_id + '/hide');
          //Display the column with fade animation. We don't fade the header because of some bug with the current template, to check when we will have the final template.
          $('#header_compared_' + compared_id).show();
          $('.implementation_compared_' + compared_id).fadeIn();
        //If we are hiding the column
        } else {
          //Change the class link, so next time we click on this link it will display the column
          $(link_id).addClass('hidden');
          $(link_id).removeClass('displayed');
          //Hide the column. We can't use animation because of the current template, to check when we will have the final template
          $('#header_compared_' + compared_id).hide();
          $('.implementation_compared_' + compared_id).hide();
          //Mark the column element so they will be remove at the next event. We can't do it now because otherwise it will crash the slide animation
          $('#header_compared_' + compared_id).addClass('to_remove');
          $('.implementation_compared_' + compared_id).addClass('to_remove');
       }
      }

      //Active the code
      Drupal.ajax[base] = ajax;
    });


    //Dynamize the compared checkbox so it call the compared checkbox link on click
    $('.compared_checkbox:not(.event_set)').addClass('event_set').each(function () {
      //Recover the compared_id to find later the checkbox_link id
      var patt = /[0-9]+/g;
      var compared_id = patt.exec($(this).attr('id'));
      //Set the onclick event
      $('#' + $(this).attr('id')).click(function() {
        $('#compared_checkbox_link_' + compared_id).click();
      });
    });

//TODO Toujours le probleme avec l'argument non mis a jour au second click
    //Dynamize the toogle fast edit link to display the elements add/edit/remove. Note we need to make a dummy ajax call so the user is correctly redirected to error page if javascript isn't enabled.
    $('#toogle_fastedit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      fastedit_toggled = 0;

      //Recover the link_id used later in the functions
      var link_id = $('#' + $(this).attr('id'));

      //Configure the ajax event
      var element_settings = {};
      element_settings.progress = { 'type': 'throbber' };
      if ($(this).attr('href')) {
        element_settings.url = $(this).attr('href');
        element_settings.event = 'click';
      }
      var base = $(this).attr('id');
      //Create the ajax event
      var ajax = new Drupal.ajax(base, this, element_settings);

      //The beforeSerialize function is launched when drupal build the ajax call. We will override it to alter the variables and send them to drupal
      ajax.old_beforeSerialize = ajax.beforeSerialize;

      ajax.beforeSerialize = function (element, options) {
        //We remove all hidded element so they can't perturb the computation
        $('.to_remove').remove();
//alert(options.url);
/*        if ($(link_id).attr('href') == 'toogle_fastedit_callback/nojs/hide') {
          options.url = 'toogle_fastedit_callback/ajax/hide';
        }
alert(options.url);
alert(options.toSource());*/

        if (fastedit_toggled == 0) {
          options.data.action = 'show';
        } else {
          options.data.action = 'hide';
        }

        //Recover all compared columns displayed in the table to send their id to drupal
        var compared_ids = new Array();
        var i = 0;
        $('.compared_item').each(function (key, value) {
          var column_id = $('#' + $(this).attr('id'));
          var patt = /[0-9]+/g;
          compared_ids[i] = patt.exec($(this).attr('id'));
          i = i + 1;
        });
        //Add them in the ajax call variables
        options.data.compared_ids = compared_ids;

        //Recover all feature row displayed in the table to send their id to drupal
        var feature_ids = new Array();
        var i = 0;
        $('.feature_row').each(function (key, value) {
          var row_id = $('#' + $(this).attr('id'));
          var patt = /[0-9]+/g;
          feature_ids[i] = patt.exec($(this).attr('id'));
          i = i + 1;
        });
        //Add them in the ajax call variables
        options.data.feature_ids = feature_ids;
        
        //Recover all implementation displayed in the table to send their id to drupal
        var implementation_ids = new Array();
        var i = 0;
        $('.implementation_cell').each(function (key, value) {
          var cell_id = $('#' + $(this).attr('id'));
          var patt = /[0-9]+/g;
          implementation_ids[i] = patt.exec($(this).attr('id'));
          i = i + 1;
        });
        //Add them in the ajax call variables
        options.data.implementation_ids = implementation_ids;

        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }



      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {

        //First launch regular success function
        this.old_success(response, status);
//alert(response.toSource());
       //If we are displaying the items
        if (fastedit_toggled == 0) {
          //Set the global variable
          fastedit_toggled = 1;
        //If we are hidding the items
        } else {
          //Set the global variable
          fastedit_toggled = 0;
          $('.compared_add_link').remove();
          $('.compared_edit_link').remove();
          $('.compared_remove_link').remove();
          $('.feature_add_link').remove();
          $('.feature_edit_link').remove();
          $('.feature_remove_link').remove();
          $('.implementation_edit_link').remove();
        }
      }


      //Active the code
      Drupal.ajax[base] = ajax;

    });

//TODO Add the edit link in implementation, if toogle mode the item are already added in the new feature and compared in other functions


  }
};

})(jQuery);
