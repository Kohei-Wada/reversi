#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 

#include "move.h"
#include "disc.h"

static const int reversi_size = 8;
static const int top_left_corner = 0;
static const int top_right_corner = reversi_size - 1;
static const int bottom_left_corner = reversi_size * (reversi_size - 1);
static const int bottom_right_corner = (reversi_size * reversi_size) - 1;

/**************************************************************************/
typedef struct reversi {
	char *array;
	int n_moves;
} reversi_t;


/**************************************************************************/

static int position(int x, int y) 
{
	return reversi_size * y + x;
}

static int is_corner(int p)
{
	return p % reversi_size == 0;
}

static int end_left(int p)
{
	return p % reversi_size == 0; 
}

static int end_right(int p)
{
	return p % reversi_size == reversi_size - 1;
}

static int end_up(int p)
{
	return p / reversi_size == 0; 
}

static int end_down(int p)
{
	return p / reversi_size == reversi_size - 1;
}

/**************************************************************************/

void reversi_init(reversi_t **r)
{
	*r = malloc(sizeof(reversi_t));
	(*r)->array = malloc(sizeof(char) * reversi_size * reversi_size);
	(*r)->n_moves = reversi_size * reversi_size - 4;

	int pos = position(reversi_size / 2 - 1, reversi_size / 2 - 1);

	(*r)->array[pos]                    = WHITE; 
	(*r)->array[pos + 1]                = BLACK;
	(*r)->array[pos + reversi_size]     = BLACK;
	(*r)->array[pos + reversi_size + 1] = WHITE;
}

void reversi_free(reversi_t *r)
{
	free(r->array);
	free(r);
}

/**************************************************************************/
static void reversi_draw_line(void) 
{
	printf("\n    +");
	for (int i = 1; i < reversi_size; ++i)
		printf("---+");
	printf("---+\n");
}

static void reversi_draw_char(void)
{
	printf("     ");
	for (int i = 0; i < reversi_size; ++i)
		printf(" %c  ", i + 'A');
}

void reversi_display(reversi_t *r)
{
	unsigned int i, j, k = 0; 

	printf("\n");
	reversi_draw_char();
	reversi_draw_line();

	for (j = 1; j <= reversi_size; ++j) {
		printf("  %d |", j);

		for (i = 1; i <= reversi_size; ++i, ++k) 
			printf(" %c |", r->array[k]? r->array[k] : ' ');

		printf(" %d", j);
		reversi_draw_line();
	}
	reversi_draw_char();
	printf("\n\n");
}
/**************************************************************************/


int reversi_is_possible(reversi_t *r, disc_t d, move_t *m)
{
	int i;

	/*constant move*/
	const int cpos = position(m->x, m->y);
	
	/*opponent*/
	disc_t op = d == WHITE? BLACK : WHITE;

	if (m->x == -1 && m->y == -1) return 0;
	if (r->array[cpos] != 0)        return 0;

	/*horizontale 1*/
    if (!end_left(cpos) && r->array[i = cpos - 1] == op) {
        for (; !end_left(i) && r->array[i] == op; --i);
        if (r->array[i] == d) return 1;
    }

    /*horizontale 2*/
    if (!end_right(cpos) && r->array[i = cpos + 1] == op) {
        for (; !end_right(i) && r->array[i] == op; ++i);
        if (r->array[i] == d) return 1;
    }

    /*vertical 1*/
    if (!end_up(cpos) && r->array[i = cpos - reversi_size] == op) {
        for (; !end_up(i) && r->array[i] == op; i -= reversi_size);
        if (r->array[i] == d) return 1;
    }

    /*vertical 2*/
    if (!end_down(cpos) && r->array[i = cpos + reversi_size] == op) {
        for (; !end_down(i) && r->array[i] == op; i += reversi_size);
        if (r->array[i] == d) return 1;
    }

    /*diagonal 1*/
    if (!end_left(cpos) && !end_up(cpos) && r->array[i = cpos - reversi_size - 1] == op) {
        for (; !end_left(i) && !end_up(i) && r->array[i] == op; i -= reversi_size + 1);
        if (r->array[i] == d) return 1;
    }

    /*diagonal 2*/
    if (!end_right(cpos) && !end_down(cpos) && r->array[i = cpos + reversi_size + 1] == op) {
        for (; !end_right(i) && !end_down(i) && r->array[i] == op; i += reversi_size + 1);
        if (r->array[i] == d) return 1;
    }
    /*diagonal 3*/
    if (!end_left(cpos) && !end_down(cpos) && r->array[i = cpos + reversi_size - 1] == op) {
        for (; !end_left(i) && !end_down(i) && r->array[i] == op; i += reversi_size - 1);
        if (r->array[i] == d) return 1;
    }
    /*diagonal 1*/
    if (!end_right(cpos) && !end_up(cpos) && r->array[i = cpos - reversi_size + 1] == op) {
        for (; !end_right(i) && !end_up(i) && r->array[i] == op; i -= reversi_size - 1);
        if (r->array[i] == d) return 1;
    }
    return 0;
}


int reversi_exist_moves(reversi_t *r, disc_t d)
{
	move_t m;
	if (r->n_moves == 0) return 0;

	for (m.x = 0; m.x < reversi_size; ++m.x)
		for (m.y = 0; m.y < reversi_size; ++m.y)
			if (reversi_is_possible(r, d, &m))
				return 1;
	return 0;
}

void reversi_put(reversi_t *r, disc_t d, move_t *m)
{
	const int cpos = position(m->x, m->y);
	int i;

	disc_t op = d == WHITE? BLACK : WHITE;
	r->array[cpos] = d;

	/*horizontal1*/
    if (!end_left(cpos)) {
        for (i = cpos - 1; !end_left(i) && r->array[i] == op; --i);
        if (r->array[i] == d)
            for (; i < cpos; r->array[++i] = d);
    }

    /*horizontal2*/
    if (!end_right(cpos)) {
        for (i = cpos + 1; !end_right(i) && r->array[i] == op; ++i);
        if (r->array[i] == d)
            for (; i > cpos; r->array[--i] = d);
    }


    /*vertical1*/
    if (!end_up(cpos)) {
        for (i = cpos - reversi_size; !end_up(i) && r->array[i] == op; i -= reversi_size);
        if (r->array[i] == d)
            for (; i < cpos; r->array[i += reversi_size] = d);
    }

    /*vertical2*/
    if (!end_down(cpos)) {
        for (i = cpos + reversi_size; !end_down(i) && r->array[i] == op; i += reversi_size);
        if (r->array[i] == d)
            for (; i > cpos; r->array[i -= reversi_size] = d);
    }

    /*diagonal1*/
    if (!end_left(cpos) && !end_up(cpos)) {
        for (i = cpos - reversi_size - 1; !end_left(i) && !end_up(i) &&
                r->array[i] == op; i -= reversi_size + 1);

        if (r->array[i] == d)
            for (; i < cpos; r->array[i += reversi_size + 1] = d);
    }

    /*diagonal2*/
    if (!end_right(cpos) && !end_down(cpos)) {
        for (i = cpos + reversi_size + 1; !end_right(i) && !end_down(i) &&
                r->array[i] == op; i += reversi_size + 1);

        if (r->array[i] == d)
            for (; i > cpos; r->array[i -= reversi_size + 1] = d);
    }

	 /*diagonal3*/
    if (!end_left(cpos) && !end_down(cpos)) {
        for (i = cpos + reversi_size - 1; !end_left(i) && !end_down(i) &&
                r->array[i] == op; i += reversi_size - 1);

        if (r->array[i] == d)
            for (; i > cpos; r->array[i -= reversi_size - 1] = d);
    }

    /*diagonal4*/
    if (!end_right(cpos) && !end_up(cpos)) {
        for (i = cpos - reversi_size + 1; !end_right(i) && !end_up(i) &&
                r->array[i] == op; i -= reversi_size - 1);

        if (r->array[i] == d)
            for (; i < cpos; r->array[i += reversi_size - 1] = d);
    }

}

