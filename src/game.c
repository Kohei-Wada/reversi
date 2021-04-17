#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "player.h"
#include "move.h"
#include "reversi.h"

typedef struct game {
	reversi_t *reversi;
	player_t *player[2];
} game_t;

void game_init(game_t **g)
{
	*g = malloc(sizeof(game_t));
	reversi_init(&(*g)->reversi);

	player_init(&(*g)->player[0], BLACK);
	player_init(&(*g)->player[1], WHITE);
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
	move_t m;
	int i = 0;
	color_t c;

	while (1) {
		system("clear");
		m = player_get_move(g->player[i]);
		c = player_color(g->player[i]);
		if (reversi_is_possible(g->reversi, &m, c)) 
			reversi_put(g->reversi, &m, c);
		i = !i;
		reversi_display(g->reversi);
		usleep(100000);
	}
}


