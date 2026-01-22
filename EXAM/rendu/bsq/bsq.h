#ifndef	BSQ_H
# define BSQ_H

# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_tiles
{
	int		n_lines;
	char	empty;
	char	obstacle;
	char	full;
}	t_tiles;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_box
{
	int size;
	int x;
	int y;
}	t_box;

void	free_map(char **map);

int		map_error(char *line, char **map);

char	*strdup_len(char *str, int len);

int		min3(int a, int b, int c);

int		load_elements(FILE *fd, t_tiles *tiles);

int		load_map(FILE *fd, t_map *map, t_tiles *tiles);

void	find_square(t_map *map, t_tiles *tiles, t_box *box);

void	draw_square(t_map *map, t_tiles *tiles, t_box *box);

int		execute_bsq(FILE *fd);

int		convert_file_pointer(char *name);

#endif
