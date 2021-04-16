#ifndef _PLAYER_H
#define _PLAYER_H
#include "algorithm.h"
#include "move.h"

typedef struct player {
	algorithm_t *algorithm;
} player_t;


void player_init(player_t **p);
void player_free(player_t *p);
move_t player_get_move(player_t *p);

#endif 
