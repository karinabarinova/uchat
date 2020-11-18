//
// Created by Rostyslav Druzhchenko on 18.11.2020.
//

#include <server.h>

t_response *mx_response_message_send(t_message *message) {
    t_response *response = mx_response_new();
    response->type = E_MSGTYPE_MESSAGE_SEND;
    response->code = E_STATUS_CODE_OK;

    JsonNode *node_root = json_mkobject();

    JsonNode *node_code = json_mknumber(E_STATUS_CODE_OK);
    JsonNode *node_type = json_mknumber(E_MSGTYPE_MESSAGE_SEND);
    JsonNode *node_message = mx_message_to_json_node(message);

    json_append_member(node_root, "code", node_code);
    json_append_member(node_root, "type", node_type);
    json_append_member(node_root, "message", node_message);

    response->body = json_encode(node_root);
    json_delete(node_root);

    return response;
}
