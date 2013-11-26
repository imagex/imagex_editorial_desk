<?php
/**
 * @file
 * imagex_editorial_desk.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function imagex_editorial_desk_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'assignment-assignment-field_assignment_assigned_user'
  $field_instances['assignment-assignment-field_assignment_assigned_user'] = array(
    'bundle' => 'assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The user who will be assigned to complete this assignment.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'assignment',
    'field_name' => 'field_assignment_assigned_user',
    'label' => 'Assigned User',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 34,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'assignment-assignment-field_assignment_content_node'
  $field_instances['assignment-assignment-field_assignment_content_node'] = array(
    'bundle' => 'assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Internal, admin only field. Records the assignment to content relation if content is internal.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'assignment',
    'field_name' => 'field_assignment_content_node',
    'label' => 'Assignment Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 35,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'assignment-assignment-field_assignment_content_type'
  $field_instances['assignment-assignment-field_assignment_content_type'] = array(
    'bundle' => 'assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the type of content this assignment should create. ie. news, event',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'assignment',
    'field_name' => 'field_assignment_content_type',
    'label' => 'Assignment Content Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 36,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'assignment-assignment-field_assignment_deadline'
  $field_instances['assignment-assignment-field_assignment_deadline'] = array(
    'bundle' => 'assignment',
    'deleted' => 0,
    'description' => 'The deadline date that this assignment should be completed by.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'assignment',
    'field_name' => 'field_assignment_deadline',
    'label' => 'Deadline',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 32,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'assignment-assignment-field_assignment_description'
  $field_instances['assignment-assignment-field_assignment_description'] = array(
    'bundle' => 'assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Description of the assignment.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'assignment',
    'field_name' => 'field_assignment_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'assignment-assignment-field_assignment_status'
  $field_instances['assignment-assignment-field_assignment_status'] = array(
    'bundle' => 'assignment',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Define the status of the assignment. This will automatically be update as process is made on the assignment.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'assignment',
    'field_name' => 'field_assignment_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 33,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Assigned User');
  t('Assignment Content');
  t('Assignment Content Type');
  t('Deadline');
  t('Define the status of the assignment. This will automatically be update as process is made on the assignment.');
  t('Description');
  t('Description of the assignment.');
  t('Internal, admin only field. Records the assignment to content relation if content is internal.');
  t('Select the type of content this assignment should create. ie. news, event');
  t('Status');
  t('The deadline date that this assignment should be completed by.');
  t('The user who will be assigned to complete this assignment.');

  return $field_instances;
}
