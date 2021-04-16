#include <stdlib.h> 
#include "observer.h"
#include "link_list.h"


typedef struct subject {
	link_list_t *observers;
} subject_t;

void subject_init(subject_t **s)
{
	*s = malloc(sizeof(subject_t));
	link_list_init(&(*s)->observers);
}

void subject_free(subject_t *s)
{
	link_list_free(s->observers);
	free(s);
}

void subject_register_observer(subject_t *s, observer_t *o)
{
	link_list_append(s->observers, o);
}

void subject_remove_observer(subject_t *s, observer_t *o)
{
	link_list_delete(s->observers, o);
}

void subject_notify_observers(subject_t *s, void *args)
{
	int i = 0;
	observer_t *o = link_list_index_of(s->observers, i);
	
	while (o) {
		if (o->interface->update)
			o->interface->update(args);
		++i;
		o = link_list_index_of(s->observers, i);
	}
}

void subject_is_changed(subject_t *s) 
{
	subject_notify_observers(s, NULL);
}

