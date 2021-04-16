#include <stdlib.h> 
#include <stdio.h>

#include "link_list.h"
typedef struct node {
	struct node *prev;
	struct node *next;
	int index;
	void *data;
} node_t;


typedef struct link_list {
	node_t *list_head;
	node_t *list_tail;
	int list_len;
} link_list_t;


void link_list_init(link_list_t **l)
{
	*l = malloc(sizeof(link_list_t));
	(*l)->list_head = NULL;
	(*l)->list_tail = NULL;
	(*l)->list_len = 0;
}


void link_list_add_head(link_list_t *l, void *data)
{
	node_t *node = malloc(sizeof(node_t));
	node->data = data;
	node->prev = NULL;
	node->next = l->list_head;

	if (l->list_head == NULL) 
		l->list_tail = node;
	else 
		l->list_head->prev = node;
	
	l->list_head = node;
}

void link_list_add_tail(link_list_t *l, void *data)
{
	link_list_append(l, data);
}

void link_list_append(link_list_t *l, void *data)
{
	node_t *node = malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;
	node->prev = l->list_tail;

	if (l->list_head == NULL) 
		l->list_head = node;
	else 
		l->list_tail->next = node;

	l->list_tail = node;
}

void link_list_delete(link_list_t *l, void *data)
{
	node_t *node;
	for (node = l->list_head; node && node->data != data; node = node->next);
	if (!node) return;

	if (node == l->list_head && node == l->list_tail) {
		l->list_head = l->list_tail = NULL;
	}
	else if (node == l->list_head) {
		l->list_head = node->next;
		node->next->prev = NULL;
	}
	else if (node == l->list_tail) {
		l->list_tail = node->prev;
		node->prev->next = NULL;
	}
	else {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
}


void link_list_free(link_list_t *l)
{
	node_t *node, *tmp;

	for (node = l->list_head; node; node = tmp) {
		tmp = node->next;
		free(node);
	}
}

void link_list_display(link_list_t *l)
{
	node_t *node;
	for (node = l->list_head; node; node = node->next) 
		printf("%p\n", node->data);
}

void *link_list_index_of(link_list_t *l, int index)
{
	node_t *node = l->list_head; 
	for (node = l->list_head; node && index ; node = node->next) 
		--index;
	return node? node->data: NULL;
}

