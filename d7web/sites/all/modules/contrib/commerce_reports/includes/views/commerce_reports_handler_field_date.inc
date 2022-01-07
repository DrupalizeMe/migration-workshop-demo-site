<?php
/**
 * @file
 * Views field handler for the created date on orders.
 *
 * Provides decent sorting, granularity and interpolation for missing dates.
 */

class commerce_reports_handler_field_date extends views_handler_field {

  var $granularities = array(
    'Y-m' => array(
      'label' => 'Monthly',
      'interval' => 2764800,
      'normalizationFunction' => '_normalizeMonthly',
      'displayFormat' => 'F Y',
    ),
    'o-W' => array(
      'label' => 'Weekly',
      'interval' => 604800,
      'normalizationFunction' => '_normalizeWeekly'
    ),
    'Y-m-d' => array(
      'label' => 'Daily',
      'interval' => 86400,
    ),
  );

  protected function _normalizeWeekly($timestamp) {
    return strtotime('this week UTC', $timestamp);
  }

  protected function _normalizeMonthly($timestamp) {
    // Workaround for PHP 5.2; PHP 5.3 works with 'first day of this month'
    return strtotime(date('Y-m', strtotime('this month UTC', $timestamp)) . ' UTC');
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['exposed'] = array(
      'default' => FALSE,
    );

    $options['default_granularity'] = array(
      'default' => 'Y-m',
    );

    $options['default_period'] = array(
      'default' => '2592000',
    );

    return $options;
  }

  function can_expose() {
    return TRUE;
  }

  function exposed_form(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    $form['granularity'] = array(
      '#type' => 'select',
      '#title' => t('Granularity'),
      '#options' => $this->granularityOptions(),
      '#default_value' => $this->options['default_granularity']
    );

    $timestamp = REQUEST_TIME - $this->options['default_period'];

    $form['startDate'] = array(
      '#type' => 'date',
      '#title' => t('Start date'),
      '#default_value' => array(
        'day' => format_date($timestamp, 'custom', 'j'),
        'month' => format_date($timestamp, 'custom', 'n'),
        'year' => format_date($timestamp, 'custom', 'Y'),
      ),
    );

    $form['endDate'] = array(
      '#type' => 'date',
      '#title' => t('End date'),
      '#default_value' => array(),
    );
  }

  function accept_exposed_input($input) {
    if (empty($this->options['exposed'])) {
      return TRUE;
    }

    if (!empty($input['granularity']) && in_array($input['granularity'], array_keys($this->granularityOptions()))) {
      $this->granularity = $input['granularity'];
    }
    else {
      return FALSE;
    }

    if (is_array($input['startDate']) && is_array($input['endDate'])) {
      $start = mktime(0, 0, 0, $input['startDate']['month'], $input['startDate']['day'], $input['startDate']['year']);
      $end = mktime(0, 0, 0, $input['endDate']['month'], $input['endDate']['day'], $input['endDate']['year']);
    }
    else {
      return FALSE;
    }

    if ($end > $start) {
      $this->startDate = $start;
      $this->endDate = $end;
    }
    else {
      return FALSE;
    }

    $this->startDate = $this->convertTimestamp($this->startDate);
    $this->endDate = $this->convertTimestamp($this->endDate);

    return TRUE;
  }

  function convertTimestamp($timestamp) {
    if (!is_numeric($timestamp)) {
      $timestamp = strtotime('today UTC');
    }
    else {
      $timestamp = strtotime('today UTC', $timestamp);
    }

    if (!empty($this->granularities[$this->getFormat()]['normalizationFunction'])) {
      $timestamp = $this->{$this->granularities[$this->getFormat()]['normalizationFunction']}($timestamp);
    }

    return $timestamp;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['exposed'] = array(
      '#type' => 'checkbox',
      '#title' => t('Expose this filter to visitors, to allow them to change it'),
      '#default_value' => $this->options['exposed'],
    );

    $form['default_granularity'] = array(
      '#type' => 'select',
      '#title' => t('Default granularity'),
      '#options' => $this->granularityOptions(),
      '#default_value' => $this->options['default_granularity'],
    );

    $form['default_period'] = array(
      '#type' => 'select',
      '#title' => t('Default time period'),
      '#options' => array(
        '604800' => t('One week'),
        '2592000' => t('One month'),
        '31556926' => t('One year'),
      ),
      '#default_value' => $this->options['default_period'],
    );
  }

  function granularityOptions() {
    static $cache;

    if (empty($cache)) {
      $cache = array();

      foreach ($this->granularities as $format => $data) {
        $cache[$format] = $data['label'];
      }
    }

    return $cache;
  }

  function getFormat() {
    if (!empty($this->options['exposed']) && !empty($this->granularity)) {
      return $this->granularity;
    }

    return $this->options['default_granularity'];
  }

  function getInterval() {
    return $this->granularities[$this->getFormat()]['interval'];
  }

  /**
   * Makes sure a start and end date are set
   */
  function pre_query() {
    // If no endDate is set, set it to today.
    if (empty($this->endDate)) {
      $this->endDate = $this->convertTimestamp(time());
    }

    // If no startDate is set, set it to the end date minus the default period.
    if (empty($this->startDate)) {
      $this->startDate = $this->convertTimestamp($this->endDate - $this->options['default_period']);
    }
  }

  /**
   * Adds the date to the query.
   * Adds GROUP BY and ORDER BY clause.
   */
  function query() {
    $this->ensure_my_table();

    $this->field_alias = sprintf("%s_%s_granularity", $this->table_alias, $this->real_field);

    $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
    $this->query->add_field($this->table_alias, $this->real_field, $this->field_alias, $params);

    // We group by the field using a SQL function to transform the timestamp to certain formats.
    // This way the database does the aggregation for us.
    $field_name = views_date_sql_format($this->getFormat(), $this->table_alias . '.' . $this->real_field);
    $this->query->add_groupby($field_name);

    $end_date = $this->endDate + $this->getInterval();
    $this->query->add_where_expression(0, "{$this->table_alias}.{$this->real_field} BETWEEN {$this->startDate} AND {$end_date}");

    $this->add_additional_fields();
  }

  function render($values) {
    $timestamp = $this->get_value($values);

    $format = $this->getFormat();
    if (!empty($this->granularities[$format]['displayFormat'])) {
      $format = $this->granularities[$format]['displayFormat'];
    }

    $value = format_date($timestamp, 'custom', $format, 'UTC');

    return $this->sanitize_value($value);
  }

  /**
   * Interpolates the missing dates linearly.
   */
  function post_execute(&$values) {
    $retrieved = array();

    foreach ($values as $record) {
      $timestamp = $this->convertTimestamp($record->{$this->field_alias});
      $record->{$this->field_alias} = $timestamp;

      $retrieved[$timestamp] = $record;
    }

    // Determine order direction.
    foreach ($this->query->orderby as $order) {
      if ($order['field'] == $this->field_alias) {
        $descending = ($order['direction'] == 'DESC');
        break;
      }
    }

    // If there is no order direction, then we don't need interpolation.
    if (!isset($descending)) {
      return;
    }

    $interval = $this->getInterval();
    $defaults = array();

    for ($current = $this->startDate; $current <= $this->endDate; $current += $interval) {
      $timestamp = $this->convertTimestamp($current);
      $defaults[$timestamp] = (object) array($this->field_alias => $timestamp);
    }

    $retrieved += $defaults;

    ksort($retrieved);

    $values = array_values($retrieved);
  }
}
