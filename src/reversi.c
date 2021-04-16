#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include "move.h"



static const int board_size = 8;

typedef enum {EMPTY = 0 , BLACK, WHITE} color_t;

typedef struct reversi {
	char *array; 
	int n_moves;
} reversi_t;

/*******************************************************************************/
 
static int position(int x, int y) {
	return board_size * y + x;
}
static const int top_left_corner = 0;
static const int top_right_corner = board_size - 1;
static const int bottom_left_corner = board_size * (board_size - 1);
static const int bottom_right_corner = board_size * (board_size -1 );

static int is_corner(int p)
{
	return p == top_left_corner || p == top_right_corner \
			  || p == bottom_left_corner || bottom_right_corner;
}

static int end_left(int p)
{
	return p % board_size == 0;
}

static int end_right(int p) 
{
	return p % board_size == board_size - 1; 
}

static int end_up(int p) 
{
	return p / board_size == 0; 
}

static int end_down(int p) 
{
	return p / board_size == board_size - 1;
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


int reversi_is_possible(reversi_t *r, move_t *m, color_t c)
{
	int i;
	const int cpos = position(m->x, m->y);
	color_t op = c == WHITE? BLACK : WHITE;

	if (m->x == -1 && m->y == -1) return 0;
	if (r->array[cpos] != EMPTY) return 0;


	/*horizontale 1*/
	if (!end_left(cpos) && r->array[i = cpos - 1] == op) {
		for (; !end_left(i) && r->array[i] == op; --i);
		if (r->array[i] == c) return 1;
	}

	/*horizontale 2*/
	if (!end_right(cpos) && r->array[i = cpos + 1] == op) {
		for (; !end_right(i) && r->array[i] == op; ++i);
		if (r->array[i] == c) return 1;
	}

	/*vertical 1*/
	if (!end_up(cpos) && r->array[i = cpos - board_size] == op) {
		for (; end_up(i) && r->array[i] == op; i -= board_size);
		if (r->array[i] == c) return 1;
	}

	/*vertical 2*/
	if (!end_down(cpos) && r->array[i = cpos + board_size] == op) {
		for (; end_down(i) && r->array[i] == op; i += board_size);
		if (r->array[i] == c) return 1; 
	}

	/*diagonal 1*/
	if (!end_left(cpos) && !end_up(cpos) && r->array[i = cpos - board_size - 1] == op) {
		for (; !end_left(i) && !end_up(i) && r->array[i] == op; i -= board_size + 1);
		if (r->array[i] == c) return 1;
	}

	/*diagonal 2*/
	if (!end_right(cpos) && !end_down(cpos) && r->array[i = cpos + board_size + 1] == op) {
		for (; !end_right(i) && !end_down(i) && r->array[i] == op; i += board_size + 1);
		if (r->array[i] == c) return 1;
	}
	/*diagonal 3*/
	if (!end_left(cpos) && !end_down(cpos) && r->array[i = cpos + board_size - 1] == op) {
		for (; !end_left(i) && !end_down(i) && r->array[i] == op; i += board_size - 1);
		if (r->array[i] == c) return 1;
	}
	/*diagonal 1*/
	if (!end_right(cpos) && !end_up(cpos) && r->array[i = cpos - board_size + 1] == op) {
		for (; !end_right(i) && !end_up(i) && r->array[i] == op; i -= board_size - 1);
		if (r->array[i] == c) return 1;
	}
	return 0;
}


int reversi_exitsts_moves(reversi_t *r, color_t c)
{
	move_t m;

	if (r->n_moves == 0) return 0;

	for (m.x = 0; m.x < board_size; ++m.x) 
		for (m.y = 0; m.y < board_size; ++m.y) 
			if (reversi_is_possible(r, &m, c))
					return 1;
	return 0;
}


