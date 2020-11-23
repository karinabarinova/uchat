#ifndef CLIENT_H
#define CLIENT_H


#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "libmx.h"
#include <mx_connection.h>

typedef struct s_signin t_signin;
typedef struct s_chat_window t_chat_window;
typedef struct s_register t_register;


typedef struct s_user_info {
    char id;
    char *password;
    char *login;
    bool logged;
    bool to_login;
    bool regist; //clicked sign up button/register
    char *name;
    char *first_name;
    char *last_name;
}              t_user_info;

typedef struct s_window_widgets {
    

    GtkBuilder *builder;
    GtkBuilder *builder_window2;
    GtkBuilder *builder_window3; 
    t_signin *s_signin;
    t_chat_window *s_chat_window;
    t_register *s_register;
}              t_window_widgets;

typedef struct s_info {
    int sock;
    int port;
    char *token;
    char *ip;
    t_user_info *user_info;
    t_window_widgets *widgets;
}              t_info;

//UTILS
t_info *mx_validate_args(int argc, char *argv[]);
t_info *mx_info_new();
void mx_info_init(t_info **info);
void mx_init_gtk(t_info *info);
GtkWidget *mx_name_mess_to(char *user);
GtkWidget *mx_time_mess_to(char *data);
void mx_set_chat_settings(t_chat_window *chat);
void mx_show_window(t_info *info);
void show_signin_page(t_window_widgets *widgets);
bool mx_register_validation(t_register *regist);
void mx_register_clear_input(t_register *regist);
void mx_login_clear_input(t_signin *win);
bool mx_check_for_spaces(const char *text);
void mx_run_chat_list(char *token);
t_info *gs_info(t_info *in);
t_info *chat_info(t_info *in);
char *mx_run_login();
void mx_print_error(t_response *response);
void mx_run_message_send(char *token, const char *text);
void mx_run_sticker_send(char *token, const char *text);
void mx_run_message_list(char *token);
void mx_set_preferences(GtkWidget *label);
void mx_render_user_message(const char *message, 
    int message_time, int message_type, t_info *info);
void chat_list_del(t_list **list);
gboolean mx_find_clicked(__attribute__((unused)) GtkWidget *widget,
                             GdkEventKey *event,
                             __attribute__((unused)) gpointer data);
int
mx_change_window(t_info *info, int window);

//Remove
void print_error(t_response *response);

//Change theme
void mx_css_connect_light(void);
void mx_css_connect_dark(void);

//Build
void mx_create_sticker_1(GtkWidget *box);
void mx_create_sticker();
void mx_send_message(t_info *info);
void mx_sticker();
void mx_send_sticker_to(void);

void mx_init_widgets(t_window_widgets *widgets);
void mx_set_settings_default(t_window_widgets *widgets);
//Callback handlers
void mx_signin_handler(t_info *info);
void mx_chat_handler(t_info *info);
void mx_register_handler(t_info *info);
//Connection
void mx_connect(t_info *info);
int mx_socket(int port, char *ip);

struct s_signin {
    GtkWidget *login_window;
    GtkWidget *login_grid;
    GtkWidget *username_entry;
    GtkWidget *password_entry;
    GtkWidget *login_layout;
    GtkWidget *register_button;
    GtkWidget *login_button;
    GtkWidget *status_label;
};

struct s_chat_window {
    GtkWidget *window_main_chat;
    GtkWidget *window_delim2;
    GtkWidget *chats_window;
    GtkWidget *scrolled_window_chats;
    GtkWidget *fiend_entry;
    GtkWidget *scrolled_chats_list;
    GtkWidget *scrolled_window_message;
    GtkWidget *image_user;
    GtkWidget *window_text_message_scrolled;
    GtkWidget *window_text_message_scrolled_atribut;
    GtkWidget *entry_text_message;
    GtkWidget *scrolled_window_corespondent;
    GtkWidget *label_user_name;
    GtkWidget *scrolled_window_corespondent_atribut;
    GtkWidget *scrolled_corespondent_list;
    GtkWidget *send_button;
    GtkWidget *stickers_button;
    GtkWidget *theme_switch;
    GtkWidget *msg_bt;



    GtkWidget *win_stick;
    
};

struct s_register {
    GtkWidget *register_window;
    GtkWidget *register_grid;
    GtkWidget *first_name;
    GtkWidget *email;
    GtkWidget *register_username;
    GtkWidget *register_password;
    GtkWidget *register_password_confirm;
    GtkWidget *register_layout1;
    GtkWidget *register_layout2;
    GtkWidget *register_register_button;
    GtkWidget *register_back_button;
    GtkWidget *register_status_label;
};

typedef enum {
    MX_SIGNIN_WINDOW,
    MX_SIGNUP_WINDOW,
    MX_CHAT_WINDOW
} t_windows;

#define MX_SIGNIN_WINDOW 0
#define MX_CHAT_WINDOW 1
#define MX_REGISTER_WINDOW 2


#endif
