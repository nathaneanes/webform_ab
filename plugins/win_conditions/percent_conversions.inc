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
function webform_ab_percent_conversions_config_validate($form_state) {
  return TRUE;
}

/**
 * Check if the given Webform A/B Test node has a winner
 */
function webform_ab_percent_conversions_check_win($test_node) {
  return FALSE;
}