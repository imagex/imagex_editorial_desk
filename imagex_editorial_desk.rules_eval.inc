<?php

/**
 * @file
 * Rules custom callbacks
 *
 * @see: imagex_editorial_desk.rules.inc
 */


/**
 * Condition: User has access to field & parent entity (imagex_editorial_desk_user_edit_node_access)
 *
 * Maybe the user has right permissions but access denied by Workbench or similar
 */
function imagex_editorial_desk_rules_condition_entity_access(EntityDrupalWrapper $wrapper, $op, $account = NULL) {
  return entity_access($op, $wrapper->type(), $wrapper->value(), $account);
}

/**
 * Condition: User has "edit any" access for assign content type (imagex_editorial_desk_user_edit_node_access)
 */
function imagex_editorial_desk_rules_condition_entity_edit_permissions(EntityDrupalWrapper $wrapper, $account = NULL) {
  // Admin permissions
  $admin_access = user_access('bypass node access', $account) || user_access('administer content', $account);

  // Edit permissions
  $edit_access = user_access('edit any ' . $wrapper->value()->type . ' content', $account) || user_access('edit own ' . $wrapper->value()->type . ' content', $account);
  
  return $admin_access || $edit_access;
}
