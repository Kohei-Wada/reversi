#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include "player.h"
#include "move.h"
#include "reversi.h"


typedef struct game {
	reversi_t *reversi;
	player_t *player[2];
} game_t;

static void move_print(move_t m)
{
	printf("x = %d, y = %d\n", m.x, m.y);
}

void game_init(game_t **g)
{
	*g = malloc(sizeof(game_t));
	reversi_init(&(*g)->reversi);
	for (int i = 0; i < 2; ++i) 
		player_init(&(*g)->player[i]);
}

void game_free(game_t *g) 
{
	reversi_free(g->reversi);
	for (int i = 0; i < 2; ++i)
		player_free(g->player[i]);
	free(g);
}


void game_run(game_t *g)
{
	 reversi_display(g->reversi);
}



