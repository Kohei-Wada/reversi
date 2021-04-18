#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 
#include "disc.h"
#include "move.h"


static const int board_size = 8;


static int __is_a_valid_str(char *buf) 
{   
  char eval[2]; 
  char *p, c = 0, l = 0; 
  
  /* Parcours du buffer, on recherche exactement une lettre et un chiffre. */ 
  for(p = buf; *p != '\0'; p++) 
  { 
    if(*p >= '1' && *p <= '0' + board_size) 
    { 
      if(c++) return -1; /* Un Chiffre déjà trouvé. */ 
      eval[1] = *p; 
    } 
    else if((*p >= 'A' && *p < 'A' + board_size) || 
            (*p >= 'a' && *p < 'a' + board_size)) 
    { 
      if(l++) return -1; /* Une lettre déjà trouvée. */ 
      eval[0] = toupper(*p); 
    } 
    else if(!isspace(*p)) 
      return -1; 
  } 
 
  if(c && l) 
  { 
    buf[0] = eval[0] - 'A'; 
    buf[1] = eval[1] - '0' - 1; 
 
    return 0; /* Format respecté. */ 
  } 
 
  return -1; 
} 


move_t command_get(void)
{
	move_t move = {.x = -1, .y = -1};
	char cmd[10];
	printf("enter command : ");
	fgets(cmd, sizeof(cmd), stdin);
	cmd[strlen(cmd) - 1] = '\0';

	if (strcmp(cmd, "quit") == 0 || strcmp(cmd, "q") == 0) 
		exit(0);
	if (__is_a_valid_str(cmd) == 0) {
		move.x = cmd[0]; move.y = cmd[1];
		return move;
	}
	return move;
}



