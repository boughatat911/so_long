/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:37:00 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 14:11:11 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*create_window(t_game *game, int *win_width, int *win_height)
{
	int	map_width;
	int	map_height;

	map_width = ft_strlen(game->map[0]);
	map_height = 0;
	while (game->map[map_height])
		map_height++;
	*win_width = map_width * TILE_SIZE;
	*win_height = map_height * TILE_SIZE;
	return (mlx_new_window(game->mlx, *win_width, *win_height, "GTA"));
}

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->textures.wall = mlx_xpm_file_to_image
		(game->mlx, "textures/wall.xpm", &w, &h);
	game->textures.floor = mlx_xpm_file_to_image
		(game->mlx, "textures/floor.xpm", &w, &h);
	game->textures.player = mlx_xpm_file_to_image
		(game->mlx, "textures/player.xpm", &w, &h);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->textures.exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit_open.xpm", &w, &h);
	return_chek(game);
}

void	render_tile(t_game *game, void *texture)
{
	if (texture)
		mlx_put_image_to_window(game->mlx,
			game->win, texture, game->x * TILE_SIZE, game->y * TILE_SIZE);
}

void	render_map(t_game *game, char **map)
{
	game->y = 0;
	while (map[game->y])
	{
		game->x = 0;
		while (map[game->y][game->x])
		{
			if (map[game->y][game->x] == '1')
				render_tile(game, game->textures.wall);
			else if (map[game->y][game->x] == '0')
				render_tile(game, game->textures.floor);
			else if (map[game->y][game->x] == 'P')
				render_tile(game, game->textures.player);
			else if (map[game->y][game->x] == 'C')
				render_tile(game, game->textures.collectible);
			else if (map[game->y][game->x] == 'E')
				render_tile(game, game->textures.exit_open);
			game->x++;
		}
		game->y++;
	}
}

void	mlx_map(t_game *game)
{
	int		win_width;
	int		win_height;

	game->n = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game, 1, "Error\n", 911);
	game->win = create_window(game, &win_width, &win_height);
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_exit(game, 1, "Error\n", 0);
	}
	load_textures(game);
	render_map(game, game->map);
	mlx_hook(game->win, 2, 1L << 0, action_player, game);
	mlx_hook(game->win, 17, 1L << 17, handle_close, game);
	mlx_loop(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
}
