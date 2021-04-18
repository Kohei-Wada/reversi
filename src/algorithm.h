#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_
#include "move.h"

typedef struct algorithm {
	move_t (*gen_move)(void);
}algorithm_t;

#endif
