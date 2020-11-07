//
// Created by Rostyslav Druzhchenko on 03.11.2020.
//

#ifndef SERVER_MX_DATA_H
#define SERVER_MX_DATA_H

#include <uuid/uuid.h>
#include <stdlib.h>
#include <libmx.h>
#include <json.h>

typedef struct {
    char *id;
    char *login;
    char *first_name;
    char *last_name;
} t_user;

t_user *mx_user_new(void);
void mx_user_del(t_user **user);
JsonNode *mx_user_list_to_json_node(t_list *list);
JsonNode *mx_user_to_json_node(t_user *user);

// Messages
//
typedef struct {
    char *id;
    char *user_id;
    char *chat_id;
} t_message;

t_message *mx_message_new(void);
void mx_message_del(t_message  **message);

// Chat
//
typedef struct {
    char *name;
    char *id;
    t_list *participants; // t_user
} t_chat;

t_chat *mx_chat_new(void);
void mx_chat_del(t_chat **chat);
char *mx_chat_list_to_json(t_list *list);
JsonNode *mx_chat_to_json_node(t_chat *chat);

#endif //SERVER_MX_DATA_H