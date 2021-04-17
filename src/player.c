#include <stdlib.h>
#include "algorithm.h"
#include "move.h"
#include "reversi.h"

typedef struct player {
	algorithm_t *algorithm;
	color_t c;
} player_t;

void player_init(player_t **p, color_t c)
{
	*p = malloc(sizeof(player_t));
	(*p)->c = c;
	algorithm_init(&(*p)->algorithm);
}

void player_free(player_t *p)
{
	algorithm_free(p->algorithm);
	free(p);
}

move_t player_get_move(player_t *p)
{
	 return  p->algorithm->getmove();
}

void player_change_algorithm(player_t *p, algorithm_t *a)
{
	p->algorithm = a;
}

color_t player_color(player_t *p)
{
	return p->c;
}

