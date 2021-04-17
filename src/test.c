#include <stdio.h>
#include "game.h"
#include "command.h"

#include "move.h"

void print_move(move_t *m)
{

	printf("move.x = %d\n", m->x);

	printf("move.y = %d\n", m->y);

}

int main(void)
{
	move_t m;
	int retval = 0;
	while (retval == 0) {
		retval = command_get(&m);
		print_move(&m);
	}

	return 0;

}

