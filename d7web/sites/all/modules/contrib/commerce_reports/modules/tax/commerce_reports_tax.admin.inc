<?php
/**
 * @file
 * Administrative forms.
 */

 /**
  * Configuration form.
  */
function commerce_reports_tax_form($form, &$form_state) {
  $form['generate'] = array(
    '#type' => 'submit',
    '#value' => t('Generate all tax information'),
    '#submit' => array('commerce_reports_tax_form_submit_generate'),
  );

  return $form;
}

/**
 * Submit handler that generates a tax report.
 */
function commerce_reports_tax_form_submit_generate($form, &$form_state) {
  commerce_reports_tax_generate();
}

/**
 * Callback for tax report generation.
 */
function commerce_reports_tax_generate_callback() {
	commerce_reports_tax_generate();

	batch_process('admin/commerce/reports/tax');
}

/**
 * Returns the table containing the tax report.
 */
function commerce_reports_tax_table($start = 0, $end = REQUEST_TIME) {
  if (!variable_get('commerce_reports_tax_batch_finished', FALSE)) {
    drupal_set_message();
  }

  $rows = commerce_reports_tax($start, $end);

  if (!variable_get('commerce_reports_tax_batch_finished', FALSE)) {
    $rows = array();

  	$rows[] = array(
      'data' => array(array('data' => t("It seems you have not yet extracted tax information from orders that occurred before enabling the tax reporting module. You will have to <a href='@generate-url'>generate</a> past data before anything will show up.", array('@generate-url' => url('admin/commerce/config/tax-reports/generate'))), 'colspan' => 3)),
    );
  }
  elseif (!$rows) {
    $rows[] = array(
      'data' => array(array('data' => t("There's currently no tax data available. You might want to <a href='@generate-url'>generate</a> past data.", array('@generate-url' => url('admin/commerce/config/tax-reports/generate'))), 'colspan' => 3)),
    );
  }

  return array(
    '#theme' => 'table',
    '#header' => array(t('Tax rate'), t('Taxable'), t('Taxed')),
    '#rows' => $rows,
  );
}

function commerce_reports_tax_table_form($form, &$form_state) {
  $form['start'] = array(
    '#type' => 'date',
    '#title' => t('Start date'),
    '#default_value' => array(
      'day' => format_date(REQUEST_TIME, 'custom', 'j'),
      'month' => format_date(REQUEST_TIME, 'custom', 'n'),
      'year' => format_date(REQUEST_TIME, 'custom', 'Y') - 1,
    ),
    '#required' => TRUE,
  );
  $form['end'] = array(
    '#type' => 'date',
    '#title' => t('End date'),
    '#default_value' => array(
      'day' => format_date(REQUEST_TIME, 'custom', 'j'),
      'month' => format_date(REQUEST_TIME, 'custom', 'n'),
      'year' => format_date(REQUEST_TIME, 'custom', 'Y'),
    ),
    '#required' => TRUE,
  );
  $form['refresh'] = array(
    '#type' => 'submit',
    '#value' => t('Refresh'),
  );

  if (empty($form_state['input'])) {
    $start = 0;
    $end = REQUEST_TIME;
  }
  else {
    $start = $form_state['input']['start'];
    $start = mktime(0, 0, 0, $start['month'], $start['day'], $start['year']);

    $end = $form_state['input']['end'];
    $end = mktime(0, 0, 0, $end['month'], $end['day'], $end['year']);
  }

  $tax_table = commerce_reports_tax_table($start, $end);

  $form['taxes'] = array(
    '#markup' => drupal_render($tax_table),
  );

  return $form;
}

function commerce_reports_tax_table_form_submit($form, &$form_state) {
  // Rebuild the form
  $form_state['rebuild'] = TRUE;
}