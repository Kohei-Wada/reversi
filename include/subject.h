
#ifndef _SUBJECT_H_
#define _SUBJECT_H_
typedef struct observer observer_t;
typedef struct subject subject_t;
void subject_init(subject_t **s);
void subject_free(subject_t *s);
void subject_register_observer(subject_t *s, observer_t *o);
void subject_remove_observer(subject_t *s, observer_t *o);
void subject_notify_observers(subject_t *s, void *args);

#endif
