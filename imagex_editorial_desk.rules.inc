<?php

/**
 * @file
 * Rules integration for the Flag module.
 */


/**
 * Implements hook_rules_condition_info()
 * @see rules_core_modules()
 */
function imagex_editorial_desk_rules_condition_info() {
  return array(
    'imagex_editorial_desk_entity_access' => array(
      'label' => t('User has entity access'),
      'parameter' => array(
        'entity' => array(
          'type' => 'entity',
          'label' => t('Entity'),
          'description' => t('Specifies the entity for which to evaluate the condition.'),
          'restriction' => 'selector',
          'wrapped' => TRUE,
        ),
        'op' => array(
          'type' => 'text',
          'label' => t('Access operation'),
          'options list' => 'imagex_editorial_desk_rules_condition_entity_access_op_options',
          'restriction' => 'input',
          'optional' => TRUE,
          'default value' => 'view',
        ),
        'account' => array(
          'type' => 'user',
          'label' => t('User account'),
          'description' => t('Specifies the user account for which to check access. If left empty, the currently logged in user will be used.'),
          'restriction' => 'selector',
          'optional' => TRUE,
          'default value' => NULL,
        ),
      ),
      'group' => t('Entities'),
      'base' => 'imagex_editorial_desk_rules_condition_entity_access',
    ),
    'imagex_editorial_desk_user_edit_node_access' => array(
      'label' => t('User has edit node access'),
      'parameter' => array(
        'entity' => array(
          'type' => 'entity',
          'label' => t('Entity'),
          'description' => t('Specifies the entity for which to evaluate the condition.'),
          'restriction' => 'selector',
          'wrapped' => TRUE,
        ),
        'account' => array(
          'type' => 'user',
          'label' => t('User account'),
          'description' => t('Specifies the user account for which to check access. If left empty, the currently logged in user will be used.'),
          'restriction' => 'selector',
          'optional' => TRUE,
          'default value' => NULL,
        ),
      ),
      'group' => t('Entities'),
      'base' => 'imagex_editorial_desk_rules_condition_entity_edit_permissions',
    ),   
  );
}

/**
 * Returns options for choosing a entity_access() operation.
 */
function imagex_editorial_desk_rules_condition_entity_access_op_options(RulesAbstractPlugin $element) {
  return array(
    'view' => t('View'),
    'update' => t('Edit'),
  );
}

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
