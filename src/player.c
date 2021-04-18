#include <stdlib.h> 

#include "disc.h"
#include "move.h"
#include "algorithm.h"

typedef struct player {
	disc_t d;
	algorithm_t *interface;
} player_t;
	

void player_init(player_t **p, disc_t d, algorithm_t *a)
{
	*p = malloc(sizeof(player_t));
	(*p)->d = d;
	(*p)->interface = a;
}

move_t player_gen_move(player_t *p)
{
	return p->interface->gen_move();
}

void player_free(player_t *p)
{
	free(p);
}

disc_t player_disc(player_t *p)
{
	return p->d;
}

