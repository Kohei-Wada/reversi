#ifndef LINK_LIST_H
#define LINK_LIST_H

typedef struct link_list link_list_t;


void link_list_init(link_list_t **l);
void link_list_free(link_list_t *l);
void link_list_add_head(link_list_t *l, void *data);
void link_list_add_tail(link_list_t *l, void *data);
void link_list_append(link_list_t *l, void *data);
void link_list_delete(link_list_t *l, void *data);
void link_list_display(link_list_t *l);
void *link_list_index_of(link_list_t *l, int index);
int link_list_length(link_list_t *l);
#endif
