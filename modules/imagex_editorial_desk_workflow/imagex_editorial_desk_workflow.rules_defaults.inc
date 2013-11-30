<?php
/**
 * @file
 * imagex_editorial_desk_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function imagex_editorial_desk_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_imagex_editorial_desk_content_transitioned'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_content_transitioned" : {
      "LABEL" : "imagex_editorial_desk_content_transitioned",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules", "views_bulk_operations", "workbench_moderation" ],
      "ON" : [ "workbench_moderation_after_moderation_transition" ],
      "IF" : [
        { "views_bulk_operations_condition_result_count" : {
            "view" : "imagex_editorial_desk_nodes|default",
            "args" : "[node:nid]\\r\\nall",
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "imagex_editorial_desk_nodes|default",
              "args" : "[node:nid]\\r\\nall"
            },
            "PROVIDE" : { "entity_list" : { "related_assignments" : "Related Assignments List" } }
          }
        },
        { "component_rules_imagex_editorial_desk_content_transitions" : {
            "assignment_node" : [ "node" ],
            "related_assignments" : [ "related_assignments" ]
          }
        }
      ]
    }
  }');
  $items['rules_imagex_editorial_desk_content_transitions'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_content_transitions" : {
      "LABEL" : "ImageX Editorial Desk Content Transitions",
      "PLUGIN" : "rule set",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "workbench_moderation", "rules" ],
      "USES VARIABLES" : {
        "assignment_node" : { "label" : "Assignment Node", "type" : "node" },
        "related_assignments" : { "label" : "Related Assignments", "type" : "list\\u003Cassignment\\u003E" }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "content_is_using_workbench_moderation" : { "node" : [ "assignment-node" ] } },
              { "contents_previous_state" : { "node" : [ "assignment-node" ], "moderation_state" : "draft" } },
              { "contents_current_state" : { "node" : [ "assignment-node" ], "moderation_state" : "needs_review" } }
            ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "related-assignments" ] },
                  "ITEM" : { "assignment" : "Assignment" },
                  "DO" : [
                    { "component_rules_imagex_editorial_desk_update_assignment_status_nofity" : {
                        "assignment" : [ "assignment" ],
                        "assignment_status" : "pending",
                        "subject" : "Content related to an assignment you created is ready for review.",
                        "message" : "This is an automated email to notify you that an item of content ([assignment-node:title]) related to an assignment ([assignment:title]) you created is ready for review.\\r\\n\\r\\nAssignment: [assignment:title] ([site:url]assignment\\/assignment\\/[assignment:id])\\r\\nAssignment content: [assignment-node:title] ([assignment-node:url])\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment deadline: [assignment:field_assignment_deadline]\\r\\nAssigned user: [assignment:field-assignment-assigned-user:name] ([assignment:field-assignment-assigned-user:url])"
                      }
                    },
                    { "component_rules_imagex_editorial_desk_update_assignment_status" : { "assignment" : [ "assignment" ], "assignment_status" : "pending" } }
                  ]
                }
              }
            ],
            "LABEL" : "Content Marked As Needs Review"
          }
        },
        { "RULE" : {
            "IF" : [
              { "content_is_using_workbench_moderation" : { "node" : [ "assignment-node" ] } },
              { "contents_previous_state" : { "node" : [ "assignment-node" ], "moderation_state" : "needs_review" } },
              { "contents_current_state" : { "node" : [ "assignment-node" ], "moderation_state" : "draft" } }
            ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "related-assignments" ] },
                  "ITEM" : { "assignment" : "Assignment" },
                  "DO" : [
                    { "component_rules_imagex_editorial_desk_update_assignment_status_nofity" : {
                        "assignment" : [ "assignment" ],
                        "assignment_status" : "assigned",
                        "subject" : "Content related to an assignment you created has been moved back into the draft state.",
                        "message" : "This is an automated email to notify you that an item of content ([assignment-node:title]) related to an assignment ([assignment:title]) you created has been moved back into the draft state.\\r\\n\\r\\nAssignment: [assignment:title] ([site:url]assignment\\/assignment\\/[assignment:id])\\r\\nAssignment content: [assignment-node:title] ([assignment-node:url])\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment deadline: [assignment:field_assignment_deadline]\\r\\nAssigned user: [assignment:field-assignment-assigned-user:name] ([assignment:field-assignment-assigned-user:url])"
                      }
                    },
                    { "component_rules_imagex_editorial_desk_update_assignment_status" : { "assignment" : [ "assignment" ], "assignment_status" : "assigned" } }
                  ]
                }
              }
            ],
            "LABEL" : "Content Marked As Draft"
          }
        },
        { "RULE" : {
            "IF" : [
              { "content_is_using_workbench_moderation" : { "node" : [ "assignment-node" ] } },
              { "contents_current_state" : { "node" : [ "assignment-node" ], "moderation_state" : "published" } }
            ],
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "related-assignments" ] },
                  "ITEM" : { "assignment" : "Assignment" },
                  "DO" : [
                    { "component_rules_imagex_editorial_desk_update_assignment_status_nofity" : {
                        "assignment" : [ "assignment" ],
                        "assignment_status" : "complete",
                        "subject" : "Content related to an assignment you created has been published.",
                        "message" : "This is an automated email to notify you that an item of content ([assignment-node:title]) related to an assignment ([assignment:title]) you created has been published so the assignment is now complete.\\r\\n\\r\\nAssignment: [assignment:title] ([site:url]assignment\\/assignment\\/[assignment:id])\\r\\nAssignment content: [assignment-node:title] ([assignment-node:url])\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment deadline: [assignment:field_assignment_deadline]\\r\\nAssigned user: [assignment:field-assignment-assigned-user:name] ([assignment:field-assignment-assigned-user:url])"
                      }
                    },
                    { "component_rules_imagex_editorial_desk_update_assignment_status" : { "assignment" : [ "assignment" ], "assignment_status" : "complete" } }
                  ]
                }
              }
            ],
            "LABEL" : "Content Marked As Published"
          }
        }
      ]
    }
  }');
  $items['rules_imagex_editorial_desk_update_assignment_status'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_update_assignment_status" : {
      "LABEL" : "ImageX Editorial Desk Update Assignment Status",
      "PLUGIN" : "rule",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "assignment" : { "label" : "Assignment", "type" : "assignment" },
        "assignment_status" : { "label" : "Assignment Status", "type" : "text" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_status" } },
        { "NOT data_is_empty" : { "data" : [ "assignment-status" ] } },
        { "data_is" : {
            "data" : [ "assignment:field-assignment-status" ],
            "op" : "IN",
            "value" : { "value" : { "assigned" : "assigned", "pending" : "pending" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "assignment:field-assignment-status" ],
            "value" : [ "assignment-status" ]
          }
        }
      ]
    }
  }');
  $items['rules_imagex_editorial_desk_update_assignment_status_nofity'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_update_assignment_status_nofity" : {
      "LABEL" : "ImageX Editorial Desk Update Assignment Status Nofity",
      "PLUGIN" : "rule",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "assignment" : { "label" : "Assignment", "type" : "assignment" },
        "assignment_status" : { "label" : "Assignment Status", "type" : "text" },
        "subject" : { "label" : "Subject", "type" : "text" },
        "message" : { "label" : "Message", "type" : "text" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_status" } },
        { "NOT data_is_empty" : { "data" : [ "assignment-status" ] } },
        { "data_is" : {
            "data" : [ "assignment:field-assignment-status" ],
            "op" : "IN",
            "value" : { "value" : { "assigned" : "assigned", "pending" : "pending" } }
          }
        },
        { "NOT data_is" : { "data" : [ "assignment:uid" ], "value" : [ "site:current-user" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "assignment:uid:mail" ],
            "subject" : [ "subject" ],
            "message" : [ "message" ],
            "from" : [ "site:mail" ],
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
