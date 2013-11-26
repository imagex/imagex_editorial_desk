<?php
/**
 * @file
 * imagex_editorial_desk_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function imagex_editorial_desk_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_assignment_content_node'.
  $permissions['create field_assignment_content_node'] = array(
    'name' => 'create field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'eck add assignment assignment entities'.
  $permissions['eck add assignment assignment entities'] = array(
    'name' => 'eck add assignment assignment entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add assignment bundles'.
  $permissions['eck add assignment bundles'] = array(
    'name' => 'eck add assignment bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer assignment assignment entities'.
  $permissions['eck administer assignment assignment entities'] = array(
    'name' => 'eck administer assignment assignment entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer assignment bundles'.
  $permissions['eck administer assignment bundles'] = array(
    'name' => 'eck administer assignment bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete assignment assignment entities'.
  $permissions['eck delete assignment assignment entities'] = array(
    'name' => 'eck delete assignment assignment entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete assignment bundles'.
  $permissions['eck delete assignment bundles'] = array(
    'name' => 'eck delete assignment bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit assignment assignment entities'.
  $permissions['eck edit assignment assignment entities'] = array(
    'name' => 'eck edit assignment assignment entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit assignment bundles'.
  $permissions['eck edit assignment bundles'] = array(
    'name' => 'eck edit assignment bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list assignment assignment entities'.
  $permissions['eck list assignment assignment entities'] = array(
    'name' => 'eck list assignment assignment entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list assignment bundles'.
  $permissions['eck list assignment bundles'] = array(
    'name' => 'eck list assignment bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view assignment assignment entities'.
  $permissions['eck view assignment assignment entities'] = array(
    'name' => 'eck view assignment assignment entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'edit field_assignment_content_node'.
  $permissions['edit field_assignment_content_node'] = array(
    'name' => 'edit field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_assignment_content_node'.
  $permissions['edit own field_assignment_content_node'] = array(
    'name' => 'edit own field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'manage assignment properties'.
  $permissions['manage assignment properties'] = array(
    'name' => 'manage assignment properties',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'view field_assignment_content_node'.
  $permissions['view field_assignment_content_node'] = array(
    'name' => 'view field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_assignment_content_node'.
  $permissions['view own field_assignment_content_node'] = array(
    'name' => 'view own field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
