#ifndef _REVERSI_H_
#define _REVERSI_H_
#include "move.h"


typedef enum {EMPTY = 0, BLACK, WHITE} color_t;

typedef struct reversi {
	int i;
} reversi_t;

void reversi_init(reversi_t **r);
void reversi_free(reversi_t *r);
void reversi_display(reversi_t *r);
int reversi_is_possible(reversi_t *r, move_t *m, color_t c);
void reversi_put_disk(reversi_t *r, move_t *m, color_t c);

#endif
