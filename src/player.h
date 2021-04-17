#ifndef _PLAYER_H
#define _PLAYER_H
#include "algorithm.h"
#include "move.h"
#include "reversi.h"


typedef struct player {
	algorithm_t *algorithm;
	color_t c;
} player_t;


void player_init(player_t **p, color_t c);
void player_free(player_t *p);
move_t player_get_move(player_t *p);

color_t player_color(player_t *p);
#endif 
