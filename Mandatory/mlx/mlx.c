/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:37:00 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/09 19:51:38 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "/home/nbougrin/boughatat/so_long/Mandatory/so_long.h"

void	*create_window(void *mlx, char **map, int *win_width, int *win_height)
{
	int	map_width;
	int	map_height;
	t_game game;
	map_width = ft_strlen(map[0]);
	map_height = 0;
	
	while (map[map_height])
		map_height++;
		game.map_height = map_height;
		game.map_width = map_width;
	*win_width = map_width * TILE_SIZE;
	*win_height = map_height * TILE_SIZE;
	return (mlx_new_window(mlx, *win_width, *win_height, "GTA"));
}

void	load_textures(void *mlx, t_game *game)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	game->textures.wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &w, &h);
	game->textures.floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &w, &h);
	game->textures.player = mlx_xpm_file_to_image(mlx, "player.xpm", &w, &h);
	game->textures.collectible = mlx_xpm_file_to_image(mlx,
			"collectible.xpm", &w, &h);
	game->textures.exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &w, &h);
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
				render_tile(game, game->textures.exit);
			game->x++;
		}
		game->y++;
	}
}

void	mlx_map(char **map)
{
	t_game	game;
	int		win_width;
	int		win_height;

	game.n = 0;
	game.mlx = mlx_init();
	if (!game.mlx)
		return ;
	game.win = create_window(game.mlx, map, &win_width, &win_height);
	if (!game.win)
	{
		free(game.mlx);
		return ;
	}
	game.map = map;
	load_textures(game.mlx, &game);
	render_map(&game, map);
	//mlx_key_hook(game.win, key_action, &game);
	// mlx_hook_(game.win, 2, 1L << 0, key_action, &game);
	// mlx_hook (game.mlx,2, 0, handle_keypress, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	printf("<====>\n");
	mlx_loop(game.mlx);
	// mlx_destroy_window(game.mlx, game.win);
	
}
