(function ($) {

//Drupal.behaviors is the equivalent for Drupal of ready()
Drupal.behaviors.WikicompareGlobal = {
  attach: function (context, settings) {

    $('.select select').change(function(ev) {
      var $this = $(this);

      $this.siblings('span').text($this.find('[value=' + this.value + ']').text());
    });

  }
};

})(jQuery);
