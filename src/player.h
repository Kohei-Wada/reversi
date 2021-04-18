#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "algorithm.h"
#include "move.h"
#include "disc.h"
typedef struct player player_t;

void player_init(player_t **p, disc_t d, algorithm_t *a);
void player_free(player_t *p);
int  player_gen_move(player_t *p, move_t *m);
disc_t player_disc(player_t *p);

#endif
