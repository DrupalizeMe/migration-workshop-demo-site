(function ($, Drupal, window, document, undefined) {
  $(function() {

	$("div.search-form").hide();

      $('.search-toggle').click(function() {
          $('div.search-form').fadeToggle('slow', function() {
          });
      });
      
  });

  // FOOTER FIXED SETUP
  Drupal.behaviors.sticky_footer = {
    attach: function(context, settings) {
      $('.not-logged-in .l-footer', context).once('isFixed', function(){
          $(window).load(myfunction);
          $(window).resize(myfunction);
          function myfunction(){
            var windowW = $(window).width();
            var windowH = $(window).height();
     
            //run position check if width is tab or greater
            if(windowW > 760){
              checkOffset();
            //  $('#footer-wrapper').hide(0);
              $(document).scroll(function() {
              //  $('#footer-wrapper').slideDown(200);
                 checkOffset();
              });

              //position check
              function checkOffset() {
                //check the offset of the bottom of the fixed item against the offest of the top of the bottom page wrapper
                if($('.l-footer').offset().top + $('.l-footer').height()
                                           >= ($('.l-page').offset().top + $('.l-page').outerHeight() - $('.l-footer').outerHeight()))
                  //set to relative if the bottom of the fixed element crosses into bottom page wrapper
                  $('.l-footer').removeClass('isfixed');
                //reset to fixed when it crosses back out
                if($(document).scrollTop() + window.innerHeight < ($('.l-page').offset().top + $('.l-page').outerHeight() - $('.l-footer').outerHeight()))
                    $('.l-footer').addClass('isfixed');
              }
            }//end widown > 760 if
          };//end lodd /resize
      });
    }
  };


//SNOWGLOBE HOMEPAGE ANIMATION
 //Insert h2 into img-wrapper on header image
Drupal.behaviors.homeSnowglobe = {
  attach: function (context, settings) {
    $(".front .block--block-7 .snowglobe", context).once('snowGlobe', function(){ 
      $(window).load(function(){
        $('.block--block-7 .snowglobe img').animate({opacity: 1}, 600);
      });
    });
  }
}

//Twitter Hashtag animation
Drupal.behaviors.twitterHash = {
  attach: function (context, settings) {
    $(".block--block-11", context).once('hashtag', function(){ 
      $(window).load(function(){
          animation();
        $(document).scroll(function() {
            animation();
        });
      });
    });
  }
}

//hashtag
Drupal.behaviors.whatGoingOn = {
  attach: function (context, settings) {
    $(".block--views-whats-going-on-whats-going-on", context).once('goingOn', function(){ 
      $(window).load(function(){
          animation();
        $(document).scroll(function() {
            animation();
        });
      });
    });
  }
}

//sponsors animation
Drupal.behaviors.sponsors_zoom = {
  attach: function (context, settings) {
    $(".view-id-sponsors", context).once('sponsorZoom', function(){ 
      $(window).load(function(){
          animation();
        $(document).scroll(function() {
            animation();
        });
      });
    });
  }
}

function animation() {
	//sponsors random zoom
    $('.view-id-sponsors .views-row').each(function(){
        if($(document).scrollTop() + window.innerHeight > $(this).offset().top + 50){
            $(this).addClass('zoom');
        }
    });
    //what's going on slideup
    $('.view-id-whats_going_on .views-row').each(function(){
        if($(document).scrollTop() + window.innerHeight > $(this).offset().top + 50){
           	$(this).addClass('slideUp');
        }
    });
    //twitter hastag fadein
    $('.block--block-11 h2').each(function(){
    	if($(document).scrollTop() + window.innerHeight > $(this).offset().top + 50){
           	$(this).addClass('fadeIn');
        }
    });
}


/* Apply select2 only on desktop  */
Drupal.behaviors.mobileSelect = {
  attach: function (context, settings) {
    $('select', context).once('mobile_select', function(){
      if (!(/Android|webOS|iPhone|iPad|iPod|BlackBerry|BB|PlayBook|IEMobile|Windows Phone|Kindle|Silk|Opera Mini/i.test(navigator.userAgent))) {
        $( 'select' ).select2();
        //check if that device is running ie
        if($('.is-ie').length){
          //remove the labels if the ie version is older than 10
          if($.browser.msie && parseInt($.browser.version, 10) > 9){
            $('.views-exposed-widget label').remove();
          }else{
            $('.views-exposed-form .views-exposed-widget').addClass('old-ie');
          }
          //if we're not running ie, remove the labels
        }else{
          $('.views-exposed-widget label').remove();
        }
      }
    });
  }
};




})(jQuery, Drupal, this, this.document);
