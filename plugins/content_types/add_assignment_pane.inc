<?php
/**
 * @file
 * add_assignment_pane.inc
 *
 * Provides a simple pane with a "Add New Assignment" link
 */

$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'title' => t('Add Assignment Link'),  // Title to show up on the pane screen.
  'description' => t('Provides a simple pane with a "Add New Assignment" link'), // Description to show up on the pane screen.
  'category' => t('Widgets'), // A category to put this under.
  'render callback' => 'add_assignment_pane_render', // A function that will return the renderable content.
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);

/**
 * Render callback for Add Assignment Link pane
 */
function add_assignment_pane_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  
  // No access check to allow pane flexibility
  $block->title = '';
  $block->content = l(t("Add New Assignment"), 'admin/structure/entity-type/assignment/assignment/add', array('query' => drupal_get_destination()));
 
  return $block;
}
