<?php
/**
 * @file
 * imagex_editorial_desk.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function imagex_editorial_desk_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function imagex_editorial_desk_eck_bundle_info() {
  $items = array(
  'assignment_assignment' => array(
  'machine_name' => 'assignment_assignment',
  'entity_type' => 'assignment',
  'name' => 'assignment',
  'label' => 'Assignment',
),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function imagex_editorial_desk_eck_entity_type_info() {
$items = array(
       'assignment' => array(
  'name' => 'assignment',
  'label' => 'Assignment',
  'properties' => array(
    'title' => array(
      'label' => 'Title',
      'type' => 'text',
      'behavior' => 'title',
    ),
    'uid' => array(
      'label' => 'Author',
      'type' => 'integer',
      'behavior' => 'author',
    ),
    'created' => array(
      'label' => 'Created',
      'type' => 'integer',
      'behavior' => 'created',
    ),
    'changed' => array(
      'label' => 'Changed',
      'type' => 'integer',
      'behavior' => 'changed',
    ),
    'language' => array(
      'label' => 'Entity language',
      'type' => 'language',
      'behavior' => 'language',
    ),
  ),
),
  );
  return $items;
}
