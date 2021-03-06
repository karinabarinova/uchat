//
// Created by Rostyslav Druzhchenko on 11.11.2020.
//

#include <mx_data.h>

char *mx_message_list_to_json(t_list *list) {
    JsonNode *node_array = mx_message_list_to_json_node(list);

    char *json = json_encode(node_array);
    json_delete(node_array);

    return json;
}
