#include <stdlib.h>
#include <stdio.h>

#include "player.h"
#include "disc.h"
#include "move.h"
#include "algorithm.h"
#include "reversi.h"
#include "command.h"

typedef struct game {
	reversi_t *reversi;
	player_t *player[2];
} game_t;

/***********************************************************************/
static move_t test(void)
{
//	printf("inside test()\n");
	move_t m = {.x = 1, .y = 1};
	return m;
}

static void print_move(move_t m)
{
	printf("m.x = %d, m.y = %d\n", m.x, m.y);
}

/***********************************************************************/

static algorithm_t interface0 = {
	.gen_move = command_get,
};

static algorithm_t interface1 = {
	.gen_move = command_get,
};

/***********************************************************************/

void game_init(game_t **g)
{
	*g = malloc(sizeof(game_t));
	reversi_init(&(*g)->reversi);
	player_init(&(*g)->player[0], BLACK, &interface0);
	player_init(&(*g)->player[1], WHITE, &interface1);
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

	for (int i = 32; i ; --i) {
		for (int j = 0; j < 2; ++j) {
			reversi_display(g->reversi);
			m = player_gen_move(g->player[j]);
			print_move(m);
			reversi_put(g->reversi, player_disc(g->player[j]), &m);
		}
	}
}


