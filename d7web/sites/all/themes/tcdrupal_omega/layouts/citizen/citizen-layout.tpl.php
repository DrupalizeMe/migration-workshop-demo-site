<div<?php print $attributes; ?>>
  <header class="l-header" role="banner">

    <div class="top-header-wrap">
      <?php print render($page['header']); ?>
    </div>

  <div class="l-constrained">


      <div class="l-branding site-branding">
        <?php print render($page['branding']); ?>

        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="site-branding__logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
        <?php endif; ?>
        <?php if ($site_name): ?>
          <h2 class="site-branding__name"><a href="<?php print $front_page; ?>"  title="<?php print t('Home'); ?>" rel="home">
            <span class="tc">Twin Cities</span>
            <span class="dc"> Drupal Camp</span></a>
          </h2>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
          <h2 class="site-branding__slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>

          <div class="register-block">
              <div class="pointer"></div>
              <a href="#">
                <span><?php print t('June 22-25, 2017'); ?></span>
                <?php print t('Save the date!'); ?>
              </a>
          </div>

      </div>

      <?php print render($page['navigation']); ?>

    </div>
  </header>

  <?php if (!empty($page['hero'])): ?>
    <?php print render($page['hero']); ?>
  <?php endif; ?>

  <?php if (!empty($page['highlighted'])): ?>
    <div class="l-highlighted-wrapper">
      <?php print render($page['highlighted']); ?>
    </div>
  <?php endif; ?>

  <div class="l-main l-constrained">
    <a id="main-content"></a>
    <?php print render($tabs); ?>
    <?php print $breadcrumb; ?>
    <?php print $messages; ?>
    <?php print render($page['help']); ?>

    <div class="l-content" role="main">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
  </div>


</div>
  <footer class="l-footer-wrapper" role="contentinfo">
    <div class="footer-wrap"><?php print render($page['footer']); ?></div>
    <div class="bottom-wrap"><?php print render($page['bottom']); ?></div>
  </footer>
