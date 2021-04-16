

#ifndef _OBSERVER_H_
#define _OBSERVER_H_


#include "subject.h"
typedef struct iobserver {
	void *(*update)(void *);
} iobserver_t;

typedef struct observer {
	iobserver_t *interface;
} observer_t;



void observer_init(observer_t **o, iobserver_t *i, subject_t *s);
void observer_free(observer_t *o);
void observer_change_interface(observer_t *o, iobserver_t *i);

#endif
