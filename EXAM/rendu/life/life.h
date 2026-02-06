#ifndef LIFE_H
# define LIFE_H

# include <stdlib.h>
# include <unistd.>
# include <stdio.h>

typedef struct s_game
{
	int height;
	int width;
	int iterations;
	char alive;
	char dead;
	int i;
	int j;
	int draw;
	char **map;
}	t_game;

#endif
