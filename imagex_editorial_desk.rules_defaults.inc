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
        { "component_rules_imagex_editorial_desk_assignment_notify_assigned" : { "assignment" : [ "assignment" ] } }
      ]
    }
  }');
  return $items;
}
