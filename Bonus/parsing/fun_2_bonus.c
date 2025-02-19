/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:58:48 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 10:40:14 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_mlx(t_game	*game)
{
	int	i;

	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.enemy)
		mlx_destroy_image(game->mlx, game->textures.enemy);
	if (game->textures.exit_close)
		mlx_destroy_image(game->mlx, game->textures.exit_close);
	if (game->textures.exit_open)
		mlx_destroy_image(game->mlx, game->textures.exit_open);
	i = 0;
	while (i < 5)
	{
		if (game->textures.coin[i])
			mlx_destroy_image(game->mlx, game->textures.coin[i]);
		i++;
	}
}

void	ft_exit(t_game	*game, int fd, char	*str, int mlx)
{
	ft_free2d(game->map);
	ft_free2d(game->tmp_map);
	if (mlx == 911)
	{
		free_mlx(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	putstr(str, fd);
	free(game);
	if (fd == 1)
		exit(0);
	exit(1);
}

void	read_map(char **av, t_game *game)
{
	char	*line;
	char	*str;
	char	*tmp;

	str = NULL;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		ft_exit(game, 2, "fd error\n", 0);
	line = get_next_line(game->fd);
	if (!line)
		(ft_exit(game, 2, "Empty map\n", 0));
	while (line)
	{
		tmp = str;
		str = ft_strjoin(str, line);
		(free(line), free(tmp));
		line = get_next_line (game->fd);
	}
	close(game->fd);
	if (str[ft_strlen(str) - 1] == '\n')
		ft_exit(game, 2, "Error finding new line in end of map\n", 0);
	game->map = ft_split(str, '\n');
	if (!game->map)
		(free(str), ft_exit(game, 2, "Error\n", 0));
	free(str);
}

void	exit_map(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->tmp_map[i])
	{
		j = 0;
		while (game->tmp_map[i][j])
		{
			if (game->tmp_map[i][j] != '1' && game->tmp_map[i][j] != 'X'
				&& game->tmp_map[i][j] != '0')
				ft_exit(game, 2, "Error map\n", 0);
			j++;
		}
		i++;
	}
}

void	flood(char **map, int y, int x)
{
	if (map[y][x] == 'E' || map[y][x] == 'B')
		map[y][x] = '1';
	else if (map[y][x] != '1')
	{
		map[y][x] = '1';
		flood(map, y, x + 1);
		flood(map, y, x - 1);
		flood(map, y + 1, x);
		flood(map, y - 1, x);
	}
}
