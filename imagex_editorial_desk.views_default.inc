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
  $view->tag = 'default';
  $view->base_table = 'eck_assignment';
  $view->human_name = 'ImageX Editorial Desk';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Editorial Desk';
  $handler->display->display_options['use_more_always'] = FALSE;
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

  /* Display: Editorial Desk Upcoming ListContent pane */
  $handler = $view->new_display('panel_pane', 'Editorial Desk Upcoming ListContent pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Editorial Deadlines';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'admin/content/editorial-desk';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
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
  /* Field: Assignment: Assigned User */
  $handler->display->display_options['fields']['field_assignment_assigned_user']['id'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['table'] = 'field_data_field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['field'] = 'field_assignment_assigned_user';
  $handler->display->display_options['fields']['field_assignment_assigned_user']['settings'] = array(
    'link' => 1,
  );
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
  $export['imagex_editorial_desk'] = $view;

  return $export;
}