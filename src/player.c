#include <stdlib.h>
#include "algorithm.h"
#include "move.h"

typedef struct player {
	algorithm_t *algorithm;
} player_t;

void player_init(player_t **p)
{
	*p = malloc(sizeof(player_t));
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

