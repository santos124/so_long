#include "so_long.h"

void pers_find(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == 'P')
			{
				game->pY = y;
				game->pX = x;
			}
			x++;
		}
		y++;
	}
}

void	valid_map(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (ft_strlen(game->map[y]) != (size_t)game->w || (game->map[y][x]
			!= '1' && game->map[y][x] != '0'&& game->map[y][x] != 'C' &&
			game->map[y][x] != 'P' && game->map[y][x] != 'E'))
				game_close(4, game);
			if (game->map[y][x] == 'P')
				game->persCnt++;
			if (game->map[y][x] == 'C')
				game->foodCnt++;
			if (game->map[y][x] == 'E')
				game->exitCnt++;
			x++;
		}
		y++;
	}
	if (game->exitCnt == 0 || game->foodCnt == 0 || game->persCnt != 1)
		game_close(4, game);
	x = 0;
	while (x < game->w)
	{
		if (game->map[0][x] != '1' || game->map[game->h - 1][x] != '1')
			game_close(4, game);
		x++;
	}
	y = 0;
	while (y < game->h)
	{
		if (game->map[y][0] != '1' || game->map[y][game->w - 1] != '1')
			game_close(4, game);
		y++;
	}
}

void read_map(t_game *game, char *map_name)
{
	int fd;
	int ret;
	int cnt;
	char *line;
	char **oldMap = NULL;;
	
	int i = -1;
	cnt = 0;
	ret = 1;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		game_close(1, game);
	game->map = (char**)ft_calloc(sizeof(char*), cnt + 1);
	if (!game->map)
		game_close(3, game);	
	while (ret > 0)
	{
		ret = gnl(fd, &line);
		if (ret == -1)
			game_close(2, game);
		cnt++;
		oldMap = game->map;
		game->map = (char**)ft_calloc(sizeof(char*), cnt + 1);
		if (!game->map)
			game_close(3, game);
		while (oldMap[++i])
			game->map[i] = oldMap[i];
		game->map[i] = line;
		game->map[i + 1] = NULL;
		i = -1;
		free(oldMap);
	}
	close(fd);
	game->h = cnt;
	game->w = ft_strlen(game->map[0]);
	valid_map(game);
	pers_find(game);
}