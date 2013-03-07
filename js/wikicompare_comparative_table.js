(function ($) {

//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareComparativeTable = {
  attach: function (context, settings) {

  
    //Ajaxify the compared link
    $('.list_item_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');


      if ($(this).hasClass('feature')) {
        type = 'feature';
      } else {
        type = 'compared';
      }

      if ($(this).hasClass('compared_main_table')) {
        subaction = 'compared_main_table';
      } else if ($(this).hasClass('select_multi_dialog')) {
        subaction = 'select_multi_dialog';
      }

      if ($(this).hasClass('computed')) {
        $(this).click(function() {
          var patt = /[0-9]+/g;
          var node_id = patt.exec(link_id);
          if (!$(this).hasClass('displayed')) {
            $('.feature_children_computed_' + node_id).show();
            $(this).addClass('displayed');
          } else {
            $('.feature_children_computed_' + node_id).hide();
            $(this).removeClass('displayed');
          }
          return false;
        });
      } else {
        Drupal.ajax[link_id] = build_ajax_link(link_id, this, 'expand_list_children', type, subaction);
      }
    });

//TODO make the hide recursive

    //Dynamize the checkbox so it add the item in the return and mark the parent with css class
    $('.checkbox_dialog:not(.event_set)').addClass('event_set').each(function () {
      //Recover the node_id
      var patt = /[0-9]+/g;
      var node_id = patt.exec($(this).attr('id'));
      //Set the onclick event
      $('#' + $(this).attr('id')).click(function() {
        
        if ($(this).attr('checked')) {
          selected_feature_dialog_ids[node_id] = node_id;
        } else {
          delete selected_feature_dialog_ids[node_id];
        }
      });
    });
//TODO Add has_selected_children to parent class thanks to a recursive function
//TODO Set dialog as checked if already existing

    $('#initialize_selected_feature_dialog_ids:not(.event_set)').addClass('event_set').each(function () {
        selected_feature_dialog_ids = selected_feature_ids;
alert(selected_feature_dialog_ids.toSource());
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


    //Ajaxify the feature link
    $('.feature_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {

      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');

      //Active the code
      if ($('#comparative_table').hasClass('computed')) {
        $('#' + link_id).click(function() {
          var patt = /[0-9]+/g;
          var node_id = patt.exec(link_id);
          if (!$('#' + link_id).hasClass('displayed')) {
            $('.feature_children_' + node_id).show();
            $('#' + link_id).addClass('displayed');
          } else {
            remove_feature_children_row(node_id, true);
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
        $('#compared_checkbox_link_' + compared_id).click();
      });
    });

    //Dynamize the toogle fast edit link to display the elements add/edit/remove.
    $('#toogle_fastedit_link:not(.ajax-processed)').addClass('ajax-processed').each(function () {


      //Recover the link_id used later in the functions
      var link_id = $(this).attr('id');
      
      //Set global variable
      fastedit_status = 0;
      selected_feature_ids = {};


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
      }
      
      $('#form_' + type + '_fast' + subaction + '_submit_link_' + node_id).click();
      //Block the page loading
      return false;
    });
        
    $('.form_compared_fastadd_cancel').click(function () {
      clean_fastedit_forms();
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
        send_computed_status = false;
        send_compareds = false;
        send_compareds_columns = false;
        send_features = false;
        send_implementations = false;
        send_selected_features = false;
        
        if (action == 'expand_list_children') {
          send_node_id = true;
          manage_displayed_flag = true;
          send_compareds_columns = true;
          options.data.type = type;
          options.data.subaction = subaction;
        }
        
        if (action == 'expand_row_children') {
          send_node_id = true;
          manage_displayed_flag = true;
          send_compareds_columns = true;
        }
        
        if (action == 'toogle_compared_checkbox') {
          send_node_id = true;
          send_computed_status = true;
          manage_displayed_flag = true;
          send_features = true;
        }

        if (action == 'submit_dialog') {
          selected_feature_ids = selected_feature_dialog_ids;
          send_selected_features = true;
        }
  
        if (action == 'compute_table') {
          send_compareds_columns = true;
          send_selected_features = true;
        }
        
        if (action == 'toogle_fastedit') {
          manage_displayed_flag = true;
          send_compareds = true;
          send_features = true;
          send_implementations = true;
        }
        
        
        if (action == 'show_fastedit_form') {
          send_node_id = true;
          manage_displayed_flag = true;
          
          options.data.type = type;
          options.data.fastaction = subaction;
        }
     
        if (action == 'submit_fastedit_form') {
          send_node_id = true;
          options.data.type = type;
          options.data.fastaction = subaction;
          
          if (type != 'implementation') {
            options.data.title = $('#form_' + type + '_fast' + subaction + '_title_' + node_id).val();
          }
          options.data.description = $('#form_' + type + '_fast' + subaction + '_description_' + node_id).val();
          
          if (type == 'feature') {
            options.data.feature_type = $('#form_' + type + '_fast' + subaction + '_type_' + node_id).val();
            options.data.guidelines = $('#form_' + type + '_fast' + subaction + '_guidelines_' + node_id).val();
            options.data.weight = $('#form_' + type + '_fast' + subaction + '_weight_' + node_id).val();
            options.data.state = $('#form_' + type + '_fast' + subaction + '_state_' + node_id).val();
          }
          
          if (type == 'implementation') {
            options.data.support = $('#form_' + type + '_fast' + fastaction + '_support_' + node_id).val();
          }
          options.data.revision = $('#form_' + type + '_fast' + subaction + '_revision_' + node_id).val();
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
            compared_ids[i] = patt.exec($(this).attr('id'));
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
            implementation_ids[i] = patt.exec($(this).attr('id'));
            i = i + 1;
          });
          //Add them in the ajax call variables
          options.data.implementation_ids = implementation_ids;
        }

        if (send_selected_features == true) {
          //Recover all manually selected feature to send their id to drupal
          //Add them in the ajax call variables
          options.data.selected_feature_ids = selected_feature_ids;
        }
        
        //Launch regular beforeSerialize function
        this.old_beforeSerialize(element, options);
      }
      
      //The success function is launched when drupal return the commands. We will override it to add some other commands
      ajax.old_success = ajax.success;

      ajax.success = function (response, status) {
        //First launch regular success function
        this.old_success(response, status);

        to_clean = false;
        
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
          }
        }
        
        if (manage_displayed_flag == true) {
        
          if (!$('#' + link_id).hasClass('displayed')) {
            //Change the class link, so next time we click on this link it will hide the content
            $('#' + link_id).addClass('displayed');
  
            if (action == 'expand_list_children') {
              $('#' + type + '_children_' + node_id).slideDown();
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
            
            if (action == 'show_fastedit_form') {
              if ($('#compared_link_' + node_id).hasClass('displayed')) {
                $('#compared_link_' + node_id).click();
              }
            }
          } else {
          
            //Change the class link, so next time we click on this link it will display the content
            $('#' + link_id).removeClass('displayed');
          
            if (action == 'expand_list_children') {
              $('#' + type + '_children_' + node_id).slideUp();
            }
          
            if (action == 'expand_row_children') {
              //Hide the children with slide animation
              remove_feature_children_row(node_id, false);
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
          
            if (action == 'show_fastedit_form') {
              to_clean = true;
            }
          }
          
        }
        
        
        if (action == 'submit_fastedit_form') {
          to_clean = true;
        }
        
        if (to_clean == true) {
          clean_fastedit_forms();
        }
      }

      return ajax;
    }
    
    
    function remove_feature_children_row(feature_id, computed) {
      $('.feature_children_' + feature_id).each(function(index) {
        var patt = /[0-9]+/g;
        var feature_child_id = patt.exec($(this).attr('id'));
        remove_feature_children_row(feature_child_id, computed);
      });
      //TODO replace with a slideUp()
      $('.feature_children_' + feature_id).hide();
      //We need to remove the class when the row isn't deleted, especially when the table is computed
      $('.feature_link_children_' + feature_id).removeClass('displayed');
      if (!computed == true) {
        $('.feature_children_' + feature_id).addClass('to_remove');
      }
    }
    
    function clean_fastedit_forms() {
      $('.form_compared_fastadd').remove();
      
      $('.compared_add_link:.displayed').each(function () {
        $('#' + $(this).attr('id')).removeClass('displayed');
      });
    }
  }
};


//TODO enlever les ajax dans les ajax_response et ajax_callback
//TODO dans edit et remove, centraliser les controles dans une function
//TODO faire une fonction qui va recharger les fastedit items et les pourcentages / nom compared feature, données bref tout le tableau.
//TODO If a form is open, expand un compared clean les fastedit items
//TODO regrouper autant que possible les fonctions
//TODO remplacer les if action par des case
//TODO Remplacer type variable par method pour ajax / nojs
//TODO mettre les securité dans la fonction submit pour edit et remove
//TODO ajuster les colspan automatiquement pour les line_fastedit
//TODO remplacer drupal_render par render
//TODO il faudrait générer les element du formulaire avec l'equivalent editable de field_view_field
//TODO faire un check pour afficher ou non le champ support si l'implementation est un enfant sur axe compared et feature
//TODO rajouter un champ sequence dans compared et feature pour les classe. Pas de drag&drop sur la V1 du projet
//TODO Rajouter un champ ajax qui fera apparaitre un popup sur le champ parent compared/feature. Ce code sera réutilisé dans les page d'édition.
//TODO Rajouter sur le bouton calculer l'affichage des feature new/incomplete/obsolete
//TODO Afficher un popup pour selectionner manuellement les feature qui nous interesse, et recalculer le tableau au clic sur "calculer"
//TODO bouger l'initialisation des variables globales dans un endroit plus sur
//TODO integrer un module de chat sur le site pourrait être sympa, suggestion https://github.com/cloudfuji/kandan
//TODO isoler le test ajax dans une fonction a part
//TODOfaire un submit sur les select_multi_dialog, qui vont ensuite refresh l'arbo selectionné sur la page principale. 
//TODO remplacer new Array par [], voir si pas mieux d'utiliser des objets
//TODO Centraliser toutes les requetes SQL dans une même fonction
//TODO Deplacer les variables globales utilisé dans ajax dans le javascript pour ne pas perturber le fonctionnement du tableau en cas de modification de la configuration
//TODO Trouver un moyen de sortir les requetes sql de la boucle update_compare_tree, pour un gain massif de performance

})(jQuery);
