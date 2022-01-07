<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * TC Drupal Omega theme.
 */




function tcdrupal_omega_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title'] = t('Search'); // Change the text on the label element
    $form['search_block_form']['#title_display'] = 'invisible'; // Toggle label visibilty
    $form['search_block_form']['#default_value'] = t('Search Site'); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('search'); // Change the text on the submit button
    $form['actions']['submit']['#attributes']['alt'] = "Search Button"; //add alt tag
    //unset($form['actions']['submit']['#value']); // Remove the value attribute from the input tag, since it is not valid when input type = image

    //$form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/icon-search.png');

// Add extra attributes to the text box
    $form['search_block_form']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search Site';}";
    $form['search_block_form']['#attributes']['onfocus'] = "if (this.value == 'Search Site') {this.value = '';}";
  }
}//end form alter

/**
 * Implements hook_preprocess_entity().
 */
function tcdrupal_omega_preprocess_entity(&$vars) {
  switch ($vars['entity_type']) {
    case 'paragraphs_item':
      // Add user-entered additional CSS classes to the entity DIV.
      if (!empty($vars['paragraphs_item']->field_p_class[LANGUAGE_NONE][0]['value'])) {
        $additional_classes = explode(' ', $vars['paragraphs_item']->field_p_class[LANGUAGE_NONE][0]['value']);
        $vars['classes_array'] = array_merge($vars['classes_array'], $additional_classes);
      }
      break;
  }
}

/**
 * add classes based on use of sidebar regions
 */
function tcdrupal_omega_preprocess_html(&$variables) {
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'two_sidebars';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'one_sidebar sidebar_first';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'one_sidebar sidebar_second';
  }
  else {
    $variables['classes_array'][] = 'no_sidebars';
  }
}


