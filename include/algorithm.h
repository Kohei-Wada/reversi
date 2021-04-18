#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_
#include "reversi.h"
#include "disc.h"
#include "move.h"

typedef struct algorithm {
	int (*gen_move)(reversi_t *r, disc_t d, move_t *m);
}algorithm_t;

#endif
