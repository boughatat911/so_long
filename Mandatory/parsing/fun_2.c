/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:58:48 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/11 16:22:54 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free2d(char **array)
{
	int	i;

	i = 0;
	if (!array || !array[i])
		return ;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void	ft_exit(t_game	*game, int fd, char	*str)
{
	ft_free2d(game->map);
	ft_free2d(game->tmp_map);
	putstr(str, fd);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	close(game->fd);
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
		ft_exit(game, 2, "fd error");
	line = get_next_line(game->fd);
	if (!line)
		(ft_exit(game, 2, "Empty map"));
	while (line)
	{
		tmp = str;
		str = ft_strjoin(str, line);
		(free(line), free(tmp));
		line = get_next_line (game->fd);
	}
	if (str[ft_strlen(str) - 1] == '\n')
		ft_exit(game, 2, "Error finding new line in end of map");
	game->map = ft_split(str, '\n');
	if (!game->map)
		(free(str), ft_exit(game, 2, "Error"));
	free(str);
}

void	exit_map(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'X')
				ft_exit(game, 2, "Error Player");
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
