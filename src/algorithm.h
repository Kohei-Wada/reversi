#ifndef _ALGORITHM_H
#define _ALGORITHM_H
#include "move.h"

typedef struct algorithm {
	move_t (*getmove)(void);
} algorithm_t;

void algorithm_init(algorithm_t **a);
void algorithm_free(algorithm_t *a);
void algorithm_get_move(algorithm_t *a);



#endif
