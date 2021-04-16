#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include "move.h"



static const int board_size = 8;

enum {EMPTY = 0 , BLACK, WHITE};

typedef struct reversi {
	char *array; 
	int n_moves;
} reversi_t;

/*******************************************************************************/


static int position(int x, int y) {
	return board_size * y + x;
}

/*******************************************************************************/

void reversi_init(reversi_t **r)
{
	*r = malloc(sizeof(reversi_t));
	(*r)->array = malloc(sizeof(char) * board_size * board_size); 

	int pos = position(board_size / 2 - 1, board_size / 2 - 1); 

	(*r)->array[pos] = BLACK;
	(*r)->array[pos + 1] = WHITE;
	(*r)->array[pos + board_size] = WHITE;
	(*r)->array[pos + board_size + 1] = BLACK;
}

void reversi_free(reversi_t *r)
{
	free(r);
}


static void reversi_draw_line(void)
{
	printf("\n    +");
	for (int i = 1; i < board_size; ++i) 
		printf("---+");
	printf("---+\n");
}

static void reversi_draw_char(void)
{
	printf("     ");
	for (int i = 0; i < board_size; ++i)
		printf(" %c  ", i + 'A');
}

void reversi_display(reversi_t *r)
{
	unsigned int i, j, k = 0; 

	printf("\n");
	reversi_draw_char();
	reversi_draw_line();

	for (j = 1; j <= board_size; ++j) {
		printf("  %d |", j);
		for (i = 1; i <= board_size; ++i, ++k) {
			switch (r->array[k]) {
			case BLACK : printf(" o |"); break;
			case WHITE : printf(" x |"); break;
			default    : printf("   |"); break;
			}
		}
		printf(" %d", j);
		reversi_draw_line();
	}
	reversi_draw_char();
	printf("\n\n");


	
}

void reversi_put_disk(move_t *m)
{
	
}

