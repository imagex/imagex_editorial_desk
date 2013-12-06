<?php
/**
 * @file
 * imagex_editorial_desk.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function imagex_editorial_desk_default_rules_configuration() {
  $items = array();
  $items['rules_imagex_editorial_desk_assigned_user_as_author'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_assigned_user_as_author" : {
      "LABEL" : "ImageX Editorial Desk Assigned User As Author",
      "PLUGIN" : "rule set",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules", "imagex_editorial_desk" ],
      "USES VARIABLES" : { "assignment" : { "label" : "Assignment", "type" : "assignment" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_content_node" } },
              { "entity_has_field" : {
                  "entity" : [ "assignment" ],
                  "field" : "field_assignment_assigned_user"
                }
              },
              { "NOT data_is_empty" : { "data" : [ "assignment:field-assignment-assigned-user" ] } },
              { "imagex_editorial_desk_entity_edit_permissions" : {
                  "entity" : [ "assignment:field-assignment-content-node" ],
                  "account" : [ "assignment:field-assignment-assigned-user" ]
                }
              },
              { "NOT data_is" : {
                  "data" : [ "assignment:field-assignment-assigned-user" ],
                  "value" : [ "assignment:field-assignment-content-node:author" ]
                }
              }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "assignment:field-assignment-content-node:author" ],
                  "value" : [ "assignment:field-assignment-assigned-user" ]
                }
              }
            ],
            "LABEL" : "Make Assigned User Content Author"
          }
        }
      ]
    }
  }');
  $items['rules_imagex_editorial_desk_assignment_node_has_assignment'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_assignment_node_has_assignment" : {
      "LABEL" : "ImageX Editorial Desk Assignment Node Has Assignment",
      "PLUGIN" : "rule set",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "USES VARIABLES" : {
        "assignment" : { "label" : "Assignment", "type" : "assignment" },
        "validation_fail" : { "label" : "Validation Fail", "type" : "boolean", "parameter" : false }
      },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_content_node" } },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_status" } },
              { "data_is" : {
                  "data" : [ "assignment:field-assignment-status" ],
                  "value" : "assigned"
                }
              },
              { "views_bulk_operations_condition_result_count" : {
                  "view" : "imagex_editorial_desk_nodes|default",
                  "args" : "[assignment:field-assignment-content-node:nid]\\r\\nassigned\\r\\n[assignment:id]",
                  "minimum" : "1"
                }
              }
            ],
            "DO" : [
              { "drupal_message" : {
                  "message" : "The content selected in the \\u0022Assignment Content\\u0022 field is already assigned to another assignment which has been assigned.\\u003Cbr \\/\\u003E\\r\\nTo prevent multiple assignments effecting the same node at the same time you can only have one \\u0022assigned\\u0022 assignment related to the same node at the same time. You can save this assignment as \\u0022draft\\u0022 until the existing assignment is complete.",
                  "type" : "error",
                  "repeat" : 0
                }
              },
              { "data_set" : { "data" : [ "validation-fail" ], "value" : 1 } }
            ],
            "LABEL" : "Check Assignment Content Isn\\u0027t Already Assigned"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "validation_fail" ]
    }
  }');
  $items['rules_imagex_editorial_desk_assignment_notify_assigned'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_assignment_notify_assigned" : {
      "LABEL" : "ImageX Editorial Desk Assignment Notify (Assigned)",
      "PLUGIN" : "rule set",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "assignment" : { "label" : "Assignment", "type" : "assignment" } },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_fetched" : { "assignment_author" : "Assignment Author" } },
            "IF" : [
              { "entity_has_field" : {
                  "entity" : [ "assignment" ],
                  "field" : "field_assignment_assigned_user"
                }
              },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_user_notify" } },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_status" } },
              { "NOT data_is_empty" : { "data" : [ "assignment:field-assignment-user-notify" ] } },
              { "entity_is_new" : { "entity" : [ "assignment" ] } },
              { "data_is" : {
                  "data" : [ "assignment:field-assignment-status" ],
                  "value" : "assigned"
                }
              }
            ],
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "user", "id" : [ "assignment:uid:uid" ] },
                  "PROVIDE" : { "entity_fetched" : { "assignment_author" : "Assignment Author" } }
                }
              },
              { "mail" : {
                  "to" : "[assignment:field-assignment-assigned-user:mail]",
                  "subject" : "An editorial assignment has been assigned to you.",
                  "message" : "This is an automated email to notify you that an editorial assignment has been assigned to you.\\r\\n\\r\\nView your assignment: [site:url]assignment\\/assignment\\/[assignment:id]\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment deadline: [assignment:field_assignment_deadline]\\r\\nAssignment was assigned by: [assignment-author:name] ([assignment-author:mail])",
                  "from" : "[assignment-author:mail]",
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "Assignment User Notify (New)"
          }
        },
        { "RULE" : {
            "PROVIDE" : { "entity_fetched" : { "assignment_author_update" : "Assignment Author Update" } },
            "IF" : [
              { "entity_has_field" : {
                  "entity" : [ "assignment" ],
                  "field" : "field_assignment_assigned_user"
                }
              },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_user_notify" } },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_status" } },
              { "NOT data_is_empty" : { "data" : [ "assignment:field-assignment-user-notify" ] } },
              { "NOT data_is_empty" : { "data" : [ "assignment:field-assignment-assigned-user" ] } },
              { "NOT entity_is_new" : { "entity" : [ "assignment" ] } },
              { "data_is" : {
                  "data" : [ "assignment:field-assignment-status" ],
                  "value" : "assigned"
                }
              }
            ],
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "user", "id" : [ "assignment:uid:uid" ] },
                  "PROVIDE" : { "entity_fetched" : { "assignment_author_update" : "Assignment Author Update" } }
                }
              },
              { "mail" : {
                  "to" : "[assignment:field-assignment-assigned-user:mail]",
                  "subject" : "An editorial assignment assigned to you has been updated.",
                  "message" : "This is an automated email to notify you that an editorial assignment assigned to you has been updated.\\r\\n\\r\\nView your assignment: [site:url]assignment\\/assignment\\/[assignment:id]\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment deadline: [assignment:field_assignment_deadline]\\r\\nAssignment was assigned by: [assignment-author-update:name] ([assignment-author-update:mail])",
                  "from" : "[assignment-author-update:mail]",
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "Assignment User Notify (Update)"
          }
        }
      ]
    }
  }');
  $items['rules_imagex_editorial_desk_assignment_saved'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_assignment_saved" : {
      "LABEL" : "imagex_editorial_desk_assignment_saved",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules", "eck" ],
      "ON" : [ "assignment_insert", "assignment_update" ],
      "DO" : [
        { "component_rules_imagex_editorial_desk_assigned_user_as_author" : { "assignment" : [ "assignment" ] } },
        { "component_rules_imagex_editorial_desk_assignment_notify_assigned" : { "assignment" : [ "assignment" ] } }
      ]
    }
  }');
  $items['rules_imagex_editorial_desk_assignment_user_has_content_access'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_assignment_user_has_content_access" : {
      "LABEL" : "ImageX Editorial Desk Assignment User Has Content Access",
      "PLUGIN" : "rule set",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules", "imagex_editorial_desk" ],
      "USES VARIABLES" : {
        "assignment" : { "label" : "Assignment", "type" : "assignment" },
        "validation_fail" : { "label" : "Validation Fail", "type" : "boolean", "parameter" : false }
      },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "component_rules_imagex_editorial_desk_assigned_user_as_author" : { "assignment" : [ "assignment" ] } }
            ],
            "LABEL" : "Make Assigned User Content Author"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : {
                  "entity" : [ "assignment" ],
                  "field" : "field_assignment_assigned_user"
                }
              },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_content_node" } },
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_status" } },
              { "NOT data_is_empty" : { "data" : [ "assignment:field-assignment-assigned-user" ] } },
              { "NOT data_is_empty" : { "data" : [ "assignment:field-assignment-content-node" ] } },
              { "NOT imagex_editorial_desk_entity_access" : {
                  "entity" : [ "assignment:field-assignment-content-node" ],
                  "op" : "update",
                  "account" : [ "assignment:field-assignment-assigned-user" ]
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "validation-fail" ], "value" : 1 } },
              { "drupal_message" : {
                  "message" : "The \\u0022Assigned User\\u0022 (\\u003Ca href=\\u0022[assignment:field-assignment-assigned-user:url]\\u0022\\u003E[assignment:field-assignment-assigned-user:name]\\u003C\\/a\\u003E) does not have access to edit the content item (\\u003Ca href=\\u0022[assignment:field-assignment-content-node:url]\\u0022\\u003E[assignment:field-assignment-content-node:title]\\u003C\\/a\\u003E) associated with this assignment.\\u003Cbr \\/\\u003E\\r\\nEnsure the following:\\r\\n\\u003Col\\u003E\\r\\n\\u003Cli\\u003EThe assigned user has the correct user role and that role has the following permissions: \\r\\n  \\u003Cul\\u003E\\r\\n    \\u003Cli\\u003E\\u0022\\u003Cem\\u003E[assignment:field-assignment-content-node:type]:\\u003C\\/em\\u003E edit own content\\u0022\\u003C\\/li\\u003E\\r\\n    \\u003Cli\\u003E\\u0022View List of Assignment Assignment Entities\\u0022\\u003C\\/li\\u003E \\r\\n    \\u003Cli\\u003E\\u0022View Assignment Assignment Entities\\u0022\\u003C\\/li\\u003E\\r\\n    \\u003Cli\\u003E\\u0022View Own Assigned Assignments\\u0022\\u003C\\/li\\u003E\\r\\n  \\u003C\\/ul\\u003E\\r\\n\\u003C\\/li\\u003E\\r\\n\\u003Cli\\u003EIf this content type is under moderation you may also need to ensure that the user is assigned to the same moderation section as the content.\\u003C\\/li\\u003E\\r\\n\\u003C\\/ol\\u003E",
                  "type" : "error",
                  "repeat" : 0
                }
              }
            ],
            "LABEL" : "Check Assigned User Content Edit Access"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "validation_fail" ]
    }
  }');

  features_alter_code('rules_config', $items);

  return $items;
}
