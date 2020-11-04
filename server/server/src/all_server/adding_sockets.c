#include "server.h"

int adding_sockets(s_list_client *base, int socket_new) {

	s_list_client *early = NULL;
	s_list_client *set = NULL;
	if (base == NULL) {
		return -1;
	}
	for (set = base; set != NULL; early = set, set = set->neo) {
		if (set->sock_fd == socket_new) 
			return -3;
	}
	set = (s_list_client*)malloc(sizeof(s_list_client));
	if (set == NULL) {
		return -1;
	}
	set->sock_fd = socket_new;
	early->neo = set;
	return 0;
	//В разработке!
}

