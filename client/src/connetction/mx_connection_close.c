//
// Created by Rostyslav Druzhchenko on 03.11.2020.
//

#include <mx_connection.h>

void mx_connection_close(t_connection **connection) {
    // TODO: Close connection
    free(*connection);
    *connection = 0;
}
