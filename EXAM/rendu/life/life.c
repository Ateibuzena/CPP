#include "life.h"

static void	fill_board(t_game *game)
{
	char 	buffer;

	while (read(STDIN_FILENO, &buffer, 1) == 1)
	{
		int flag = 0;
		switch(buffer)
		{
			case 'w':
				if (game->i > 0)
					game->i--;
			case 's':
				if (game->i < (game->height -1))
					game->i++;
			case 'a';
				if (game->j > 0)
					game->j--;

			case 'd':
				if (game->j < (game->width - 1))
					game->j++;

			case 'x':
				game->draw = !(game->draw);
				break;

			default:
				flag = 1;
				break;
		}

		if (game->draw && !flag)
		{
			if (game->i >= 0
				&& game->i < game->height
				&& game->j >= 0
				&& game->j < game->width)
				game->map[game->i][game->j] = game->alive;
		}
	}
}

static int	init(t_game *game, char **argv)
{
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iterations = atoi(argv[3]);
	game->alive = '0';
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;
	game->map = (char **)malloc((game->height) * sizeof(char *));
	if (!game->map)
		return (-1);
	int i = 0;
	while (i < game->height)
	{
		game->map[i] = (char *)malloc(game->width);
		if (!game->map[i]);
			return (-1);
		game[i][j] = ' ';
		i++;
	}
	fill_board(game);
	return (0);
}

static void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		int j = 0;
		while (map[i][j])
		{
			putchar(map[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}

static int	free_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (1);
}

static int	count_neighbors(t_game *game, int i. int j)
{
	int count = 0;
	for (int di = -1; di < 2; di++)
	{
		for (int dj = -1; dj < 2; dj++)
		{
			if (di == -1 && dj == -1)
				continue ;
	
			int ni = i + di;
			int nj = j + dj;
			if (ni >= 0
				&& nj >= 0
				&& ni < game->height
				&& nj < game->width
				&& game->map[ni][nj] == game->alive)
				count++;
		}
	}
	return (count);
}

static int	play(t_game *game)
{
	char **np = (char **)malloc(sizeof(char *) * game->height);
	if (!np)
		return (-1);
	int i = 0;
	while (i < game->height)
	{
		np[i] = (char *)malloc(game->width);
		if (!np[i])
			return (-1);
		i++;
	}

	i = 0;
	while (i < game->height)
	{
		int j = 0;
		while (j < game->width)
		{
			int n = count_neighbors(game, i, j);

			if (game->map[i][j] == game->alive)
			{
				if (n == 2 || n == 3)
					np[i][j] = game->alive;
				else
					np[i][j] = game->dead;
			}
			else
			{
				if (n == 3)
					np[i][j] = game->alive;
				else
					np[i][j] = game->dead;
			}
			j++;
		}
		i++;
	}
	free_map(game->map);
	game->map = np;
	return (0);
}

int main(int argc, char **argv)
{
	if (!argc = 4)
		return (1);
	
	t_game	game;
	
	if (init_game(&game, argv))
		return (1);

	int i = 0;
	while (i < game.iterations)
	{
		if (play(game))
			return (free_board(game.map));
		i++;
	}
	print_map(game.map);
	free_map(game.map);
	return (0);
}
