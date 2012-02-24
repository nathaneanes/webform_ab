<?php

/**
 * @file
 * Provide a Webform A/B Test win condition: Total number of conversions
 */

$plugin = array(
  'title' => t('Total Conversions'),
  'description' => t('This many conversions must be made by a webform before it is declared the winner.'),
  'config form' => 'webform_ab_total_conversions_config',
  'config validation form' => 'webform_ab_total_conversions_config_validate',
  'check win criteria' => 'webform_ab_total_conversions_check_win',
);


/**
 * Return the config options form for this win condition
 */
function webform_ab_total_conversions_config() {
  $form = array();
  $form['conversions'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Conversions'),
    '#description' => t(''),
    '#size' => 10,
    '#maxlength' => 255,
  );
  return $form;
}


/**
 * Validate the config for this plugin
 */
function webform_ab_total_conversions_config_validate($config, $field_name_prefix) {
  if (!ctype_digit($config['conversions']) || !($config['conversions'] > 0)) {
    form_set_error($field_name_prefix . 'conversions', t('Please enter an integer for Number of Conversions win condition.'));
  }
  return TRUE;
}


/**
 * Check if the given Webform A/B Test node has a winner
 * 
 * @param $config
 *   Array of config options for this plugin for the Webform A/B test being
 *   checked for a win. In this case, the array will contain 'conversions'
 * @param $webform_details
 *   Array of info about the webform to check.
 */
function webform_ab_total_conversions_check_win($config, $webform_details) {
  return ($webform_details['conversions'] >= $config['conversions']);
}
