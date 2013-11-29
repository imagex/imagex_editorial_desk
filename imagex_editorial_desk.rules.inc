<?php

/**
 * @file
 * Rules integration for the imagex_editorial_desk.module.
 */

/**
 * Implements hook_rules_file_info().
 */
function imagex_editorial_desk_rules_file_info() {
  return array('imagex_editorial_desk.rules_eval');
}

/**
 * Implements hook_rules_condition_info()
 * @see rules_core_modules()
 */
function imagex_editorial_desk_rules_condition_info() {
  return array(
    // Checks if user can edit node
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
      'group' => t('Editorial Desk'),
      'base' => 'imagex_editorial_desk_rules_condition_entity_access',
    ),
    
    // Checks if user has edit any or own permission for given content type
    'imagex_editorial_desk_entity_edit_permissions' => array(
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
      'group' => t('Editorial Desk'),
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
