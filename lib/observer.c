#include <stdlib.h>
#include "subject.h"

typedef struct iobserver {
	void *(*update)(void *args);
} iobserver_t;

typedef struct observer {
	iobserver_t *interface;
	subject_t *subject;
} observer_t;

void observer_init(observer_t **o, iobserver_t *i, subject_t *s)
{
	*o = malloc(sizeof(observer_t));
	(*o)->interface = i;
	(*o)->subject = s;
	subject_register_observer(s, (*o));
}

void observer_free(observer_t *o)
{
	subject_remove_observer(o->subject, o);
	free(o);
}

void observer_change_interface(observer_t *o, iobserver_t *i)
{
	o->interface = i;
}



