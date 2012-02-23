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
function webform_ab_total_conversions_config_validate($form_state) {
  return TRUE;
}


/**
 * Check if the given Webform A/B Test node has a winner
 */
function webform_ab_total_conversions_check_win($test_node) {
  return FALSE;
}
