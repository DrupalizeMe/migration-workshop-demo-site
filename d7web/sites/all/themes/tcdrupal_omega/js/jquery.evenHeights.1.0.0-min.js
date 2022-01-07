/*
 * jqEvenHeights
 * Version: 1.0.0
 * @requires jQuery v1.4 or above
 *
 * Copyright (c) 2011 www.webdesigner506.com
 * @author Michael Gutierrez Lara
 *
 * Dual licensed under the MIT and GPL licenses:
 * http://www.opensource.org/licenses/mit-license.php
 * http://www.gnu.org/licenses/gpl.html
 *
 */
// This will even heights of elements of the same type or with same class name, comparing each other to
// find the major height and applying that height to the rest of elements.
// Works for Windows PC and Mac on all major browsers.
(function($){$.fn.evenHeights=function(){var element=this;var maxHeight=0;var totalElements=$(element).length;var count=0;function compareHeights(){$(element).each(function(){count++;var elemHeight=$(this).height();if(elemHeight>maxHeight){maxHeight=elemHeight;}if(count==totalElements){setHeight();}});}function setHeight(){$(element).css('height',maxHeight);}compareHeights();};})(jQuery);