#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_
#include "move.h"

typedef struct algorithm {
	int (*gen_move)(move_t *m);
}algorithm_t;

#endif
