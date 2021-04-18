#include "game.h"
#include "reversi.h"
int main(void)
{
	game_t *g;
	game_init(&g);
	game_run(g);
	game_free(g);
	return 0;
}

