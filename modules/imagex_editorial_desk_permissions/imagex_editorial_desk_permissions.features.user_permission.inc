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

  // Exported permission: 'delete own assigned assignments'.
  $permissions['delete own assigned assignments'] = array(
    'name' => 'delete own assigned assignments',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'imagex_editorial_desk',
  );

  // Exported permission: 'eck add assignment assignment entities'.
  $permissions['eck add assignment assignment entities'] = array(
    'name' => 'eck add assignment assignment entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add assignment bundles'.
  $permissions['eck add assignment bundles'] = array(
    'name' => 'eck add assignment bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add bundles'.
  $permissions['eck add bundles'] = array(
    'name' => 'eck add bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entities'.
  $permissions['eck add entities'] = array(
    'name' => 'eck add entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entity types'.
  $permissions['eck add entity types'] = array(
    'name' => 'eck add entity types',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer assignment assignment entities'.
  $permissions['eck administer assignment assignment entities'] = array(
    'name' => 'eck administer assignment assignment entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer assignment bundles'.
  $permissions['eck administer assignment bundles'] = array(
    'name' => 'eck administer assignment bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer bundles'.
  $permissions['eck administer bundles'] = array(
    'name' => 'eck administer bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entities'.
  $permissions['eck administer entities'] = array(
    'name' => 'eck administer entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entity types'.
  $permissions['eck administer entity types'] = array(
    'name' => 'eck administer entity types',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete assignment assignment entities'.
  $permissions['eck delete assignment assignment entities'] = array(
    'name' => 'eck delete assignment assignment entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete assignment bundles'.
  $permissions['eck delete assignment bundles'] = array(
    'name' => 'eck delete assignment bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete bundles'.
  $permissions['eck delete bundles'] = array(
    'name' => 'eck delete bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entities'.
  $permissions['eck delete entities'] = array(
    'name' => 'eck delete entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entity types'.
  $permissions['eck delete entity types'] = array(
    'name' => 'eck delete entity types',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit assignment assignment entities'.
  $permissions['eck edit assignment assignment entities'] = array(
    'name' => 'eck edit assignment assignment entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit assignment bundles'.
  $permissions['eck edit assignment bundles'] = array(
    'name' => 'eck edit assignment bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit bundles'.
  $permissions['eck edit bundles'] = array(
    'name' => 'eck edit bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entities'.
  $permissions['eck edit entities'] = array(
    'name' => 'eck edit entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entity types'.
  $permissions['eck edit entity types'] = array(
    'name' => 'eck edit entity types',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list assignment assignment entities'.
  $permissions['eck list assignment assignment entities'] = array(
    'name' => 'eck list assignment assignment entities',
    'roles' => array(
      'Content Creator' => 'Content Creator',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list assignment bundles'.
  $permissions['eck list assignment bundles'] = array(
    'name' => 'eck list assignment bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list bundles'.
  $permissions['eck list bundles'] = array(
    'name' => 'eck list bundles',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entities'.
  $permissions['eck list entities'] = array(
    'name' => 'eck list entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entity types'.
  $permissions['eck list entity types'] = array(
    'name' => 'eck list entity types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view assignment assignment entities'.
  $permissions['eck view assignment assignment entities'] = array(
    'name' => 'eck view assignment assignment entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view entities'.
  $permissions['eck view entities'] = array(
    'name' => 'eck view entities',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
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

  // Exported permission: 'entityconnect add button'.
  $permissions['entityconnect add button'] = array(
    'name' => 'entityconnect add button',
    'roles' => array(),
    'module' => 'entityconnect',
  );

  // Exported permission: 'entityconnect edit button'.
  $permissions['entityconnect edit button'] = array(
    'name' => 'entityconnect edit button',
    'roles' => array(),
    'module' => 'entityconnect',
  );

  // Exported permission: 'manage assignment properties'.
  $permissions['manage assignment properties'] = array(
    'name' => 'manage assignment properties',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'update own assigned assignments'.
  $permissions['update own assigned assignments'] = array(
    'name' => 'update own assigned assignments',
    'roles' => array(
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'imagex_editorial_desk',
  );

  // Exported permission: 'view field_assignment_content_node'.
  $permissions['view field_assignment_content_node'] = array(
    'name' => 'view field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Creator' => 'Content Creator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own assigned assignments'.
  $permissions['view own assigned assignments'] = array(
    'name' => 'view own assigned assignments',
    'roles' => array(
      'Content Creator' => 'Content Creator',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'imagex_editorial_desk',
  );

  // Exported permission: 'view own field_assignment_content_node'.
  $permissions['view own field_assignment_content_node'] = array(
    'name' => 'view own field_assignment_content_node',
    'roles' => array(
      'Content Administrator' => 'Content Administrator',
      'Content Creator' => 'Content Creator',
      'Content Manager' => 'Content Manager',
      'Super User' => 'Super User',
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
