#ifndef _REVERSI_H_
#define _REVERSI_H_
#include "move.h"
#include "disc.h"

#define REVERSI_SIZE 8

typedef struct reversi reversi_t;
	

void reversi_init(reversi_t **r);
void reversi_free(reversi_t *r);
void reversi_display(reversi_t *r);
void reversi_is_possible(reversi_t *r, disc_t d, move_t *m);
void reversi_exist_moves(reversi_t *r, disc_t d);
void reversi_put(reversi_t *r, disc_t d, move_t *m);

#endif
