(function ($, Drupal, window, document, undefined) {


  /* Apply select2 hide on mobile */
    Drupal.behaviors.mobileSelect = {
        attach: function (context, settings) {
            $('select', context).once('mobile_select', function(){
                if (!($( "body" ).hasClass( "page-admin" )) && (!(/Android|webOS|iPhone|iPad|iPod|BlackBerry|BB|PlayBook|IEMobile|Windows Phone|Kindle|Silk|Opera Mini/i.test(navigator.userAgent)))) {
                  $( 'select' ).select2();
                }
            });
        }
    };

	
})(jQuery, Drupal, this, this.document);