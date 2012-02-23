<?php

/**
 * @file
 * Provide a Webform A/B Test win condition: Percentage of hits that result in
 * conversions
 */


$plugin = array(
  'title' => t('Conversion Percentage'),
  'description' => t('A webform must reach this percentage of conversions to be declared the winner.'),
  'config form' => 'webform_ab_percent_conversions_config',
  'config validation form' => 'webform_ab_percent_conversions_config_validate',
  'check win criteria' => 'webform_ab_percent_conversions_check_win',
);

/**
 * Return the config options form for this win condition
 */
function webform_ab_percent_conversions_config() {
  $form = array();
  $form['percentage'] = array(
    '#type' => 'textfield',
    '#title' => t('Percentage'),
    '#description' => t('Percentage of hits that become conversions. Enter either as 25% or 0.25.'),
    '#size' => 10,
    '#maxlength' => 255,
  );
  return $form;
}

/**
 * Validate the config for this plugin
 */
function webform_ab_percent_conversions_config_validate($config, $field_name_prefix) {
  $value = $config['percentage'];

  // If it's between 0 and 1, it's a decimal and OK
  if ($value > 0 && $value <= 1) {
    // Fine
  }
  // See if the string ends with a percentage
  elseif (substr(trim($value), -1) == '%') {
    // Strip the percent sign
    $number = substr($value, 0, strlen($value) - 1);
    if (!($number > 0 && $number <= 100)) {
      form_set_error($field_name_prefix . 'percentage', t('Please enter a valid percentage for Conversion Percentage win conditoion. You can either enter it as a percentage (e.g., 45%) or a decimal value (e.g., 0.45).'));
    }
  }
  // Not a number
  else {
    form_set_error($field_name_prefix . 'percentage', t('Please enter a valid percentage for Conversion Percentage win conditoion. You can either enter it as a percentage (e.g., 45%) or a decimal value (e.g., 0.45).'));
  }
}

/**
 * Check if the given Webform A/B Test node has a winner
 */
function webform_ab_percent_conversions_check_win($test_node) {
  return FALSE;
}