<?php
/**
 * @file
 * Ctools access plugin for checking if a node has assignments.
 */
/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title' => t('Editorial Desk: A node has assignments'),
  'description' => t('Grants access if node has assignments. Required %node argument.'),
  'callback' => 'imagex_editorial_desk_node_has_assignments_access',  
  'summary' => 'imagex_editorial_desk_node_has_assignments_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function imagex_editorial_desk_node_has_assignments_access($conf, $context) {
  if (empty($context) || empty($context->data) || !isset($context->data->nid)) {
    return FALSE;
  }  
  
  // Check if the View returns results
  $view_name = 'imagex_editorial_desk_nodes';
  $args = array();
  
  // Add nid as argument
  if (!empty($context->data->nid)) {
    $nid = (int) $context->data->nid;
    $args = array($context->data->nid);
  }
  
  // views_get_view_result give errors so execute view direct
  $view = views_get_view($view_name);
  if (is_object($view)) {
    if (is_array($args)) {
      $view->set_arguments($args);
    }
    $view->init_display();
    $view->pre_execute();
    $view->execute();
    $result = $view->result;
  }
  
  if (!empty($result)) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Provide a summary description
 */
function imagex_editorial_desk_node_has_assignments_summary($conf, $context) {
  // Here we use the label value so its pretty
  return t('Node has assignments.');
}
