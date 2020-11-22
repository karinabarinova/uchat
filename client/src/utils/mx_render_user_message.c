//
// Created by Karina Barinova on 22.11.2020.
//

#include <client.h>

void mx_render_user_message(const char *message, int message_time, t_info *info) {

    time_t t;
    if (message_time == 0) {
        time(&t);
    }
    else
        t = message_time;

    GtkWidget *row, *label1, *general_box, *box_left, *box_right, *login, *time;

    row = gtk_list_box_row_new();
    gtk_widget_set_halign(row, GTK_ALIGN_END);
    gtk_list_box_row_set_activatable(GTK_LIST_BOX_ROW(row), TRUE);
    gtk_list_box_row_set_selectable(GTK_LIST_BOX_ROW(row), FALSE);

    label1 = gtk_label_new(message);
    mx_set_preferences(label1);
        
    general_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, FALSE);// created boxes
    box_right = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, FALSE);
    box_left = gtk_box_new (GTK_ORIENTATION_VERTICAL, FALSE);

    login = mx_name_mess_to(info->user_info->login);
    time = mx_time_mess_to(ctime(&t));

    gtk_box_pack_start(GTK_BOX(box_right), time, 0, 1, 1);// snap to left or top side, leaving space on right or bottom
    gtk_box_pack_end(GTK_BOX(box_left), login, 0, 0, 1); // snap to right or bottom side, leaving space on left or top
    gtk_box_pack_start(GTK_BOX(box_left), label1, 1, 1, 1);
    gtk_box_pack_start(GTK_BOX(general_box), box_left, 1, 1, 1);

    gtk_container_add_with_properties (GTK_CONTAINER (general_box), box_right, "expand", TRUE, NULL); //placing widgets in a container
    gtk_container_add(GTK_CONTAINER(general_box), box_left);
    gtk_container_add(GTK_CONTAINER(row), general_box);
    gtk_container_add(GTK_CONTAINER(
        info->widgets->s_chat_window->scrolled_corespondent_list), row);
    gtk_widget_set_name(label1, "user_message");
    gtk_widget_show_all(row);
}