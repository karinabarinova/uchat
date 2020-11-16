//
// Created by Karina Barinova on 12.11.2020.
//

#include <client.h>

#define GET (void *)-1

t_info *register_info(t_info *in) {
    static t_info *info = 0;
    if (info == 0)
        info = mx_info_new();
    if (in == GET)
        return info;
    info = in;
    return info;
}


void mx_go_to_login(t_info *info) {
    info = register_info(GET);

    gtk_widget_show(info->widgets->s_signin->login_window);
    gtk_widget_hide(info->widgets->s_register->register_window);
    gtk_widget_hide(info->widgets->s_chat_window->window_main_chat);
    gtk_main();
}

void mx_register_handler(t_info *info) {
    register_info(info);
    t_register *regist = info->widgets->s_register;

    g_signal_connect(GTK_WIDGET(regist->register_window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(GTK_WIDGET(regist->register_register_button), "clicked",
                     (GCallback)mx_go_to_login, info);
}