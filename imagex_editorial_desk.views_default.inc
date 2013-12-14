<?php
/**
 * @file
 * imagex_editorial_desk.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function imagex_editorial_desk_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'imagex_editorial_desk';
  $view->description = 'Editorial desk calendar of assignments';
  $view->tag = 'imagex_editorial_desk';
  $view->base_table = 'eck_assignment';
  $view->human_name = 'ImageX Editorial Desk';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial Desk';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View Full Editorial Calendar';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck list assignment assignment entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '1';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['inline'] = array(
    'delete_link' => 'delete_link',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Assignment: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_assignment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Assignment: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Assignment: Description */
  $handler->display->display_options['fields']['field_assignment_description']['id'] = 'field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['table'] = 'field_data_field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['field'] = 'field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_assignment_description']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Assignment: Assigned User */
  $handler->display->display_options['fields']['field_assignment_assigned_user']['id'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['field'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Assignment author';
  /* Field: Assignment: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  /* Field: Assignment: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Sort criterion: Assignment: Deadline (field_assignment_deadline) */
  $handler->display->display_options['sorts']['field_assignment_deadline_value']['id'] = 'field_assignment_deadline_value';
  $handler->display->display_options['sorts']['field_assignment_deadline_value']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['sorts']['field_assignment_deadline_value']['field'] = 'field_assignment_deadline_value';
  /* Contextual filter: Date: Date (eck_assignment) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'eck_assignment';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['use_fromto'] = 'no';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_assignment_deadline.field_assignment_deadline_value' => 'field_data_field_assignment_deadline.field_assignment_deadline_value',
  );
  /* Filter criterion: Assignment: Assigned User (field_assignment_assigned_user) */
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['id'] = 'field_assignment_assigned_user_target_id';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['field'] = 'field_assignment_assigned_user_target_id';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['expose']['operator_id'] = 'field_assignment_assigned_user_target_id_op';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['expose']['label'] = 'Assigned User';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['expose']['operator'] = 'field_assignment_assigned_user_target_id_op';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['expose']['identifier'] = 'field_assignment_assigned_user_target_id';
  $handler->display->display_options['filters']['field_assignment_assigned_user_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
  );
  /* Filter criterion: Assignment: Status (field_assignment_status) */
  $handler->display->display_options['filters']['field_assignment_status_value']['id'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['filters']['field_assignment_status_value']['field'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator_id'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['identifier'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_assignment_status_value']['reduce_duplicates'] = TRUE;

  /* Display: Editorial Desk Content pane */
  $handler = $view->new_display('panel_pane', 'Editorial Desk Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Assignment: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Assignment: Description */
  $handler->display->display_options['fields']['field_assignment_description']['id'] = 'field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['table'] = 'field_data_field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['field'] = 'field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_assignment_description']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Assignment: Assigned User */
  $handler->display->display_options['fields']['field_assignment_assigned_user']['id'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['field'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Assigned by';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_type'] = 'span';
  /* Field: Assignment: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  /* Field: Assignment: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['pane_category']['name'] = 'ImageX';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'date_argument' => array(
      'type' => 'panel',
      'context' => 'token.current-page:query',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Date: Month',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Editorial Desk Upcoming List Content pane */
  $handler = $view->new_display('panel_pane', 'Editorial Desk Upcoming List Content pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Editorial Deadlines';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'admin/content/editorial-desk';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'field_assignment_status' => 'field_assignment_status',
    'field_assignment_deadline' => 'field_assignment_deadline',
    'field_assignment_assigned_user' => 'field_assignment_assigned_user',
    'delete_link' => 'delete_link',
    'edit_link' => 'delete_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_assignment_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_assignment_deadline' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_assignment_assigned_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '  ',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Assignment';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Assignment: Assigned User */
  $handler->display->display_options['fields']['field_assignment_assigned_user']['id'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['field'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['settings'] = array(
    'link' => 1,
  );
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = 'Operations';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  /* Field: Assignment: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Assignment: Deadline (field_assignment_deadline) */
  $handler->display->display_options['filters']['field_assignment_deadline_value']['id'] = 'field_assignment_deadline_value';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['field'] = 'field_assignment_deadline_value';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Assignment: Status (field_assignment_status) */
  $handler->display->display_options['filters']['field_assignment_status_value']['id'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['filters']['field_assignment_status_value']['field'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator_id'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['identifier'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_assignment_status_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'ImageX';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'date_argument' => array(
      'type' => 'context',
      'context' => 'string.raw',
      'context_optional' => 1,
      'panel' => '3',
      'fixed' => '',
      'label' => 'Date: Month',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: My Assignments Content pane */
  $handler = $view->new_display('panel_pane', 'My Assignments Content pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Assignments';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'admin/content/editorial-desk';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'delete_link' => 'delete_link',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You currently have no content assignments to complete.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Assignment: Assigned User (field_assignment_assigned_user) */
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['id'] = 'field_assignment_assigned_user_target_id';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['field'] = 'field_assignment_assigned_user_target_id';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignment_assigned_user_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Assignment: Deadline (field_assignment_deadline) */
  $handler->display->display_options['filters']['field_assignment_deadline_value']['id'] = 'field_assignment_deadline_value';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['field'] = 'field_assignment_deadline_value';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_assignment_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Assignment: Status (field_assignment_status) */
  $handler->display->display_options['filters']['field_assignment_status_value']['id'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['filters']['field_assignment_status_value']['field'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator_id'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['identifier'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_assignment_status_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'ImageX';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'field_assignment_assigned_user_target_id' => array(
      'type' => 'user',
      'context' => 'entity:assignment.field_assignment_assigned_user',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Assigned User',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';
  $export['imagex_editorial_desk'] = $view;

  $view = new view();
  $view->name = 'imagex_editorial_desk_nodes';
  $view->description = 'Editorial desk node -> assignments relations';
  $view->tag = 'imagex_editorial_desk';
  $view->base_table = 'eck_assignment';
  $view->human_name = 'ImageX Editorial Desk Nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Node Assignments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'field_assignment_status' => 'field_assignment_status',
    'field_assignment_deadline' => 'field_assignment_deadline',
    'created' => 'created',
    'field_assignment_description' => 'field_assignment_description',
    'field_assignment_assigned_user' => 'field_assignment_assigned_user',
    'name' => 'name',
    'delete_link' => 'delete_link',
    'edit_link' => 'delete_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_assignment_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_assignment_deadline' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_assignment_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_assignment_assigned_user' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => 'views-align-right',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Assignment: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_assignment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Assignment: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Assignment: Description */
  $handler->display->display_options['fields']['field_assignment_description']['id'] = 'field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['table'] = 'field_data_field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['field'] = 'field_assignment_description';
  $handler->display->display_options['fields']['field_assignment_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_assignment_description']['settings'] = array(
    'trim_length' => '50',
  );
  /* Field: Assignment: Assigned User */
  $handler->display->display_options['fields']['field_assignment_assigned_user']['id'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['field'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Assignment author';
  /* Field: Assignment: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['label'] = '';
  $handler->display->display_options['fields']['delete_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delete_link']['text'] = 'Delete';
  /* Field: Assignment: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = '';
  $handler->display->display_options['fields']['edit_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_link']['text'] = 'Edit';
  /* Field: Bulk operations: Assignment */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_imagex_editorial_desk_assignment_content' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_imagex_editorial_desk_assignment_notify_assigned' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_imagex_editorial_desk_assignment_validation' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::panelizer_set_status_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: Assignment: Deadline (field_assignment_deadline) */
  $handler->display->display_options['sorts']['field_assignment_deadline_value']['id'] = 'field_assignment_deadline_value';
  $handler->display->display_options['sorts']['field_assignment_deadline_value']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['sorts']['field_assignment_deadline_value']['field'] = 'field_assignment_deadline_value';
  /* Contextual filter: Assignment: Assignment Content (field_assignment_content_node) */
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['id'] = 'field_assignment_content_node_target_id';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['table'] = 'field_data_field_assignment_content_node';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['field'] = 'field_assignment_content_node_target_id';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['default_argument_options']['argument'] = 'NULL';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Assignment: Status (field_assignment_status) */
  $handler->display->display_options['arguments']['field_assignment_status_value']['id'] = 'field_assignment_status_value';
  $handler->display->display_options['arguments']['field_assignment_status_value']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['arguments']['field_assignment_status_value']['field'] = 'field_assignment_status_value';
  $handler->display->display_options['arguments']['field_assignment_status_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_assignment_status_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_assignment_status_value']['default_argument_options']['argument'] = 'assigned';
  $handler->display->display_options['arguments']['field_assignment_status_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignment_status_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignment_status_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_assignment_status_value']['limit'] = '0';
  /* Contextual filter: Assignment: Id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['id']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['id']['not'] = TRUE;

  /* Display: Node Assignments Content pane */
  $handler = $view->new_display('panel_pane', 'Node Assignments Content pane', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Loads any assignments related to a given node';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'delete_link' => 'delete_link',
    'edit_link' => 'edit_link',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Assignment: Status (field_assignment_status) */
  $handler->display->display_options['filters']['field_assignment_status_value']['id'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['filters']['field_assignment_status_value']['field'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator_id'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['operator'] = 'field_assignment_status_value_op';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['identifier'] = 'field_assignment_status_value';
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_assignment_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    4 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_assignment_status_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'ImageX';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'field_assignment_content_node_target_id' => array(
      'type' => 'user',
      'context' => 'entity:assignment.field_assignment_assigned_user',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Assignment Content',
    ),
    'field_assignment_status_value' => array(
      'type' => 'user',
      'context' => 'entity:assignment.field_assignment_assigned_user',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Status',
    ),
    'id' => array(
      'type' => 'none',
      'context' => 'entity:assignment.field_assignment_assigned_user',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Id',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Node Assignments Table Content Pane */
  $handler = $view->new_display('panel_pane', 'Node Assignments Table Content Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'name' => 'name',
    'field_assignment_assigned_user' => 'field_assignment_assigned_user',
    'created' => 'created',
    'field_assignment_deadline' => 'field_assignment_deadline',
    'field_assignment_status' => 'field_assignment_status',
  );
  $handler->display->display_options['style_options']['default'] = 'field_assignment_deadline';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_assignment_assigned_user' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_assignment_deadline' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
    'field_assignment_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'responsive' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Assignment: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: Assignment: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'assignment/assignment/[id]';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Assignment author';
  /* Field: Assignment: Assigned User */
  $handler->display->display_options['fields']['field_assignment_assigned_user']['id'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['field'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['settings'] = array(
    'link' => 1,
  );
  /* Field: Assignment: Deadline */
  $handler->display->display_options['fields']['field_assignment_deadline']['id'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['table'] = 'field_data_field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['field'] = 'field_assignment_deadline';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Assignment: Status */
  $handler->display->display_options['fields']['field_assignment_status']['id'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['table'] = 'field_data_field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['field'] = 'field_assignment_status';
  $handler->display->display_options['fields']['field_assignment_status']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_assignment_status']['element_label_type'] = 'span';
  /* Field: Assignment: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'eck_assignment';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Assignment: Assignment Content (field_assignment_content_node) */
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['id'] = 'field_assignment_content_node_target_id';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['table'] = 'field_data_field_assignment_content_node';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['field'] = 'field_assignment_content_node_target_id';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['default_argument_options']['argument'] = 'NULL';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignment_content_node_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_category']['name'] = 'ImageX';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'field_assignment_content_node_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Assignment Content (field_assignment_content_node)',
    ),
    'field_assignment_status_value' => array(
      'type' => 'none',
      'context' => 'entity:assignment.field_assignment_assigned_user',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Status (field_assignment_status)',
    ),
    'id' => array(
      'type' => 'none',
      'context' => 'entity:assignment.field_assignment_assigned_user',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Assignment: Id',
    ),
  );
  $export['imagex_editorial_desk_nodes'] = $view;

  features_alter_code('views_view', $export);

  return $export;
}
