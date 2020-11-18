#include <alt_client.h>

int main() {
    t_connection *connection = mx_connection_open("127.0.0.1", 7766);

    mx_run_login(connection);

    mx_connection_close(&connection);

    mx_check_leaks();

    return 0;
}
