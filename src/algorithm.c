#include <stdlib.h>
#include <time.h>
#include "move.h"

typedef struct algorithm {
	 move_t (*getmove)(void); 
} algorithm_t;



move_t algorithm_random(void)
{
	move_t m;
	m.x = random() % 64;
	m.y = random() % 64;
	return m;
}

void algorithm_init(algorithm_t **a) 
{
	srand((unsigned int)time(NULL));
	*a = malloc(sizeof(algorithm_t));
	(*a)->getmove = algorithm_random;
}


void algorithm_free(algorithm_t *a) 
{
	free(a);
}


void algorithm_get_move(algorithm_t *a) 
{
}

 
