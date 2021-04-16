
#ifndef _GAME_H_
#define _GAEME_H


typedef struct game game_t;

void game_init(game_t **g);
void game_free(game_t *g);
void game_run(game_t *g);



#endif
