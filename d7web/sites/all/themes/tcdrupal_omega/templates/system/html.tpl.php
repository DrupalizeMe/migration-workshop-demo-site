<?php
//comments
?><!DOCTYPE html>
<?php if (omega_extension_enabled('compatibility') && omega_theme_get_setting('omega_conditional_classes_html', TRUE)): ?>
  <!--[if IEMobile 7]><html class="no-js ie iem7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if lte IE 6]><html class="no-js ie lt-ie9 lt-ie8 lt-ie7" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if (IE 7)&(!IEMobile)]><html class="no-js ie lt-ie9 lt-ie8" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if IE 8]><html class="no-js ie lt-ie9" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"><![endif]-->
  <!--[if (gte IE 9)|(gt IEMobile 7)]><html class="no-js ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><![endif]-->
  <!--[if !IE]><!--><html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>><!--<![endif]-->
<?php else: ?>
  <html class="no-js" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<?php endif; ?>
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript" src="//fast.fonts.net/jsapi/a7758d6a-0bfb-414b-8887-82c171afc4a9.js"></script>
  <style>@import url("https://fonts.googleapis.com/css?family=Open+Sans:400italic,400,700");
  </style>

</head>
<body<?php print $attributes;?>>
  <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>

<script> (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){ (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o), m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m) })(window,document,'script','//www.google-analytics.com/analytics.js','ga');  ga('create', 'UA-52700145-1', 'auto'); ga('send', 'pageview');  </script>
</body>
</html>
