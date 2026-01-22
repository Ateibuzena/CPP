#include "bsq.h"

void	free_map(char **map)
{
	if (!map)
		return ;
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		map_error(char *line, char **map)
{
	free(line);
	free_map(map);
	return (-1);
}

char	*strdup_len(char *str, int len)
{
	char *res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	int i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		min3(int a, int b, int c)
{
	if (a <= b && a <= c) return (a);
	if (b <= a && b <= c) return (b);
	return (c);
}

int		load_elements(FILE *fd, t_tiles *tiles)
{
	if (fscanf(fd, "%d %c %c %c\n", &(tiles->n_lines), &(tiles->empty), &(tiles->obstacle), &(tiles->full)) != 4)
		return (-1);

	//write (1, "D\n", 2);

	if (tiles->n_lines <= 0)
		return (-1);
	if (tiles->empty == tiles->obstacle
		|| tiles->empty == tiles->full
		|| tiles->obstacle == tiles->full)
		return (-1);
	
	return (0);
}

int		load_map(FILE *fd, t_map *map, t_tiles *tiles)
{
	char 	*line = NULL;
	size_t	len = 0;
	int		read;

	//rellenar altura mapa
	map->height = tiles->n_lines;
	map->grid = (char **)calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		return (-1);

	int i = 0;
	while (i < map->height)
	{
		int j = 0;

		// obtener linea de fd
		read = getline(&line, &len, fd);
		if (read <= 1 || line[read - 1] != '\n')
			return (map_error(line, map->grid));
		read--;

		if (i == 0)
			map->width = read;
		else if (read != map->width)
			return (map_error(line, map->grid));

		// parseo de linea
		while (j < read)
		{
			if (line[j] != tiles->empty && line[j] != tiles->obstacle)
				return (map_error(line, map->grid));
			j++;
		}

		// rellenar width map
		map->grid[i] = strdup_len(line, read);
		if (!map->grid[i])
			return (map_error(line, map->grid));
		
		i++;
	}
	free(line);
	return (0);
}

void	find_square(t_map *map, t_tiles *tiles, t_box *box)
{
	int** dp = (int **)malloc(sizeof(int *) * (map->height));
	if (!dp)
		return ;
	int i = 0;
	while (i < map->height)
	{
		dp[i] = (int *)calloc(map->width, sizeof(int));
		if (!dp[i])
			return;
		i++;
	}

	i = 0;
	while (i < map->height)
	{
		int j = 0;
		while (j < map->width)
		{
			// buscar cuadrados
			if (map->grid[i][j] == tiles->obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);

			// cuadrado mas grande
			if (dp[i][j] > box->size)
			{
				box->size = dp[i][j];
				box->x = i;
				box->y = j;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < map->height)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

void	draw_square(t_map *map, t_tiles *tiles, t_box *box)
{
	int i = box->x - box->size + 1;

	while (i <= box->x)
	{
		int j = box->y - box->size + 1;
		while (j <= box->y)
		{
			map->grid[i][j] = tiles->full;
			j++;
		}
		i++;
	}

	i = 0;
	while (i < map->height)
	{
		fputs(map->grid[i], stdout);
		fputc('\n', stdout);
		i++;
	}
}

int		execute_bsq(FILE *fd)
{
	t_tiles	tiles;
	t_map	map;
	t_box	box = {0, 0, 0};
	//write (1, "C\n", 2);

	if (load_elements(fd, &tiles))
		return (-1);
	//write (1, "A\n", 2);
	
	if (load_map(fd, &map, &tiles))
	{
		free_map(map.grid);
		return (-1);
	}
	//write (1, "B\n", 2);
	find_square(&map, &tiles, &box);
	draw_square(&map, &tiles, &box);
	free_map(map.grid);
	return (0);
}

int		convert_file_pointer(char *name)
{
	FILE *fd;
	int	status;

	fd = fopen(name, "r");
	if (!fd)
		return (-1);

	status = execute_bsq(fd);
	fclose(fd);
	return (status);
}
