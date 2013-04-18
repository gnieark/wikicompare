(function ($) {



  

//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareForms = {
  attach: function (context, settings) {
//alert(Drupal.behaviors.WikicompareComparativeTable.toSource());
    Drupal.behaviors.WikicompareComparativeTable.test_override = function() {
alert('test!!');
    }

  }
};
})(jQuery);
