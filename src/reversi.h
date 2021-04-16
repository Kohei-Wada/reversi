#ifndef _REVERSI_H_
#define _REVERSI_H_
#include "move.h"


typedef struct reversi {
	int i;
} reversi_t;

void reversi_init(reversi_t **r);
void reversi_free(reversi_t *r);
void reversi_display(reversi_t *r);
void reversi_put_disk(move_t *m);

#endif
