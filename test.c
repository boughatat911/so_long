/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:22:33 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/05 20:06:27 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_textures {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
} t_textures;

void	*initialize_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		printf("Error: Failed to initialize MLX\n");
	return (mlx);
}

void	*create_window(void *mlx, char **map, int *win_width, int *win_height)
{
	int	map_width;
	int	map_height;

	map_width = strlen(map[0]);  // Use strlen for calculating map width
	map_height = 0;
	while (map[map_height])  // Count rows of the map
		map_height++;
	
	*win_width = map_width * TILE_SIZE;
	*win_height = map_height * TILE_SIZE;
	return (mlx_new_window(mlx, *win_width, *win_height, "so_long"));
}

void	load_textures(void *mlx, t_textures *textures)
{
	int	w;
	int	h;

	textures->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &w, &h);
	textures->floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &w, &h);
	textures->player = mlx_xpm_file_to_image(mlx, "player.xpm", &w, &h);
	textures->collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &w, &h);
	textures->exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &w, &h);
}

void	render_tile(void *mlx, void *win, void *texture, int x, int y)
{
	if (texture)
		mlx_put_image_to_window(mlx, win, texture, 
		                        x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(void *mlx, void *win, char **map, t_textures *textures)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				render_tile(mlx, win, textures->wall, x, y);
			else if (map[y][x] == '0')
				render_tile(mlx, win, textures->floor, x, y);
			else if (map[y][x] == 'P')
				render_tile(mlx, win, textures->player, x, y);
			else if (map[y][x] == 'C')
				render_tile(mlx, win, textures->collectible, x, y);
			else if (map[y][x] == 'E')
				render_tile(mlx, win, textures->exit, x, y);
			x++;
		}
		y++;
	}
}

void	free_resources(void *mlx, void *win, t_textures *textures)
{
	// mlx_destroy_image(mlx, textures->wall);
	// mlx_destroy_image(mlx, textures->floor);
	// mlx_destroy_image(mlx, textures->player);
	// mlx_destroy_image(mlx, textures->collectible);
	// mlx_destroy_image(mlx, textures->exit);
	mlx_destroy_window(mlx, win);
}

void	mlx_map(char **map)
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_textures	textures;

	mlx = initialize_mlx();
	if (!mlx)
		return;
	win = create_window(mlx, map, &win_width, &win_height);
	if (!win)
		return;
	load_textures(mlx, &textures);
	render_map(mlx, win, map, &textures);
	mlx_loop(mlx);
	free_resources(mlx, win, &textures);
}
