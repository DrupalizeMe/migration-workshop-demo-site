<div class="l-page">
  <header class="l-header" role="banner">
    <div class="l-branding site-branding">

      <?php if (!drupal_is_front_page()): ?>

        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-branding__logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; /* logo if */?> 

        <?php if ($site_name || $site_slogan): ?>
          <div class="sitename">
            <?php if ($site_name): ?>
          
              <h2 class="site-branding__name">
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
              </h2>
            <?php endif; /*site_name */ ?>

            <?php if ($site_slogan): ?>
              <h4 class="site-slogan"><?php print $site_slogan; ?></h4>
            <?php endif; ?>

          </div>

        <?php endif; /* name or slogan */ ?>

      <?php endif; /* not front */ ?>

    </div>

    <?php print render($page['header']); ?>
    <?php print render($page['navigation']); ?>
  </header>

  <div class="l-main">
    <div class="l-content" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1><?php print $title; ?></h1>

      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
    <?php print render($page['bottom']); ?>
  </div>

</div>
  <footer class="l-footer" role="contentinfo">
    <?php print render($page['footer']); ?>
  </footer>