/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:58:48 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 15:52:26 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free2d(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_exit(t_game	*game, int fd, char	*str, int mlx)
{
	(ft_free2d(game->map), ft_free2d(game->tmp_map));
	if (mlx == 911)
	{	
		if (game->textures.wall)
			mlx_destroy_image(game->mlx, game->textures.wall);
		if (game->textures.floor)
			mlx_destroy_image(game->mlx, game->textures.floor);
		if (game->textures.player)
			mlx_destroy_image(game->mlx, game->textures.player);
		if (game->textures.collectible)
			mlx_destroy_image(game->mlx, game->textures.collectible);
		if (game->textures.exit_open)
			mlx_destroy_image(game->mlx, game->textures.exit_open);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	(putstr(str, fd), free(game));
	if (fd == 1)
		exit(0);
	exit(1);
}

void	read_map(char **av, t_game *game)
{
	char	*line;
	char	*tmp;

	game->str_map = NULL;
	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		ft_exit(game, 2, "fd error\n", 0);
	line = get_next_line(game->fd);
	if (!line)
		ft_exit(game, 2, "Empty map\n", 0);
	while (line)
	{
		tmp = game->str_map;
		game->str_map = ft_strjoin(game->str_map, line);
		(free(line), free(tmp));
		line = get_next_line (game->fd);
	}
	close(game->fd);
	check_new_line(game->str_map, game);
	if (game->str_map[ft_strlen(game->str_map) - 1] == '\n')
		ft_exit(game, 2, "Error finding new line in end of map\n", 0);
	game->map = ft_split(game->str_map, '\n');
	free(game->str_map);
	if (!game->map)
		ft_exit(game, 2, "Error\n", 0);
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
				ft_exit(game, 2, "Error Player\n", 0);
			j++;
		}
		i++;
	}
}

void	flood(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		map[y][x] = 'X';
	else if (map[y][x] != '1' && map[y][x] != 'X')
	{
		map[y][x] = 'X';
		flood(map, y + 1, x);
		flood(map, y, x + 1);
		flood(map, y - 1, x);
		flood(map, y, x - 1);
	}
}
