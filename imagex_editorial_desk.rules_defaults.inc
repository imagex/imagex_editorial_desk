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
  $items['rules_imagex_editorial_desk_assignment_content'] = entity_import('rules_config', '{ "rules_imagex_editorial_desk_assignment_content" : {
      "LABEL" : "ImageX Editorial Desk Assignment Content",
      "PLUGIN" : "rule set",
      "TAGS" : [ "imagex_editorial_desk" ],
      "REQUIRES" : [ "rules", "imagex_editorial_desk" ],
      "USES VARIABLES" : {
        "assignment" : { "label" : "Assignment", "type" : "assignment" },
        "entity_access" : { "label" : "Entity Access", "type" : "boolean" },
        "entity_edit_access" : { "label" : "Edit Access", "type" : "boolean" }
      },
      "RULES" : [
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
              { "entity_access" : {
                  "entity" : [ "assignment:field-assignment-content-node" ],
                  "op" : "update",
                  "account" : [ "assignment:field-assignment-assigned-user" ]
                }
              }
            ],
            "DO" : [ { "data_set" : { "data" : [ "entity-access" ], "value" : 1 } } ],
            "LABEL" : "Check Assigned User Content Edit Access"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_content_node" } },
              { "entity_has_field" : {
                  "entity" : [ "assignment" ],
                  "field" : "field_assignment_assigned_user"
                }
              },
              { "user_edit_node_access" : {
                  "entity" : [ "assignment:field-assignment-content-node" ],
                  "account" : [ "assignment:field-assignment-assigned-user" ]
                }
              }
            ],
            "DO" : [
              { "data_set" : {
                  "data" : [ "assignment:field-assignment-content-node:author" ],
                  "value" : [ "assignment:field-assignment-assigned-user" ]
                }
              },
              { "data_set" : { "data" : [ "entity-edit-access" ], "value" : 1 } }
            ],
            "LABEL" : "Check Assigned User Content Edit Permission"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "assignment" ], "field" : "field_assignment_content_node" } },
              { "data_is_empty" : { "data" : [ "entity-access" ] } },
              { "data_is_empty" : { "data" : [ "entity-edit-access" ] } }
            ],
            "DO" : [
              { "drupal_message" : {
                  "message" : "The assigned user (\\u003Ca href=\\u0022[assignment:field-assignment-assigned-user:url]\\u0022\\u003E[assignment:field-assignment-assigned-user:name]\\u003C\\/a\\u003E) does not have access to edit the content item (\\u003Ca href=\\u0022[assignment:field-assignment-content-node:url]\\u0022\\u003E[assignment:field-assignment-content-node:title]\\u003C\\/a\\u003E) associated with this assignment.\\r\\nEnsure this user has the correct user role and that role has the \\u0022edit any [assignment:field-assignment-content-node:type] content\\u0022 or \\u0022edit own [assignment:field-assignment-content-node:type] content\\u0022 permissions.\\u003Cbr \\/\\u003E\\r\\nIf this content type is under moderation you may also need to ensure that the user is assigned to the same moderation section has the content.",
                  "type" : "error",
                  "repeat" : 0
                }
              }
            ],
            "LABEL" : "Assigned User Content Edit Access Denied"
          }
        }
      ]
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
                  "message" : "This is an automated email to notify you that an editorial assignment has been assigned to you.\\r\\n\\r\\nView your assignment: [site:url]\\/assignment\\/assignment\\/[assignment:id]\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment was assigned by: [assignment-author:name] ([assignment-author:mail])",
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
                  "message" : "This is an automated email to notify you that an editorial assignment assigned to you has been updated.\\r\\n\\r\\nView your assignment: [site:url]\\/assignment\\/assignment\\/[assignment:id]\\r\\nAssignment status: [assignment:field-assignment-status]\\r\\nAssignment was assigned by: [assignment-author-update:name] ([assignment-author-update:mail])",
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
        { "component_rules_imagex_editorial_desk_assignment_content" : {
            "assignment" : [ "assignment" ],
            "entity_access" : 0,
            "entity_edit_access" : 0
          }
        },
        { "component_rules_imagex_editorial_desk_assignment_notify_assigned" : { "assignment" : [ "assignment" ] } }
      ]
    }
  }');
  return $items;
}
