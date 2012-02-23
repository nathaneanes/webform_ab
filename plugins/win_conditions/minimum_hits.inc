<?php

/**
 * @file
 * Provide a Webform A/B Test win condition: Minimum number of hits
 */


$plugin = array(
  'title' => t('Minimum Hits'),
  'description' => t('A webform must be visited by at least this many users before it can be declared the winner.'),
  'config form' => 'webform_ab_minimum_hits_config',
  'config validation form' => 'webform_ab_minimum_hits_config_validate',
  'check win criteria' => 'webform_ab_minimum_hits_check_win',
);

/**
 * Return the config options form for this win condition
 */
function webform_ab_minimum_hits_config() {
  $form = array();
  $form['hits'] = array(
    '#type' => 'textfield',
    '#title' => t('Hits'),
    '#description' => t('The minimum number of hits.'),
    '#size' => 10,
    '#maxlength' => 255,
  );
  return $form;
}

/**
 * Validate the config for this plugin
 */
function webform_ab_minimum_hits_config_validate($config, $field_name_prefix) {
  if (!ctype_digit($config['hits']) || !($config['hits'] > 0)) {
    form_set_error($field_name_prefix . 'hits', t('Please enter an integer for Minimum Hits win condition.'));
  }
}

/**
 * Check if the given Webform A/B Test node has a winner
 */
function webform_ab_minimum_hits_check_win($test_node) {
  return FALSE;
}
