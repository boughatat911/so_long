/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/05 19:11:31 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*initialize_mlx(void)
void	*create_window(void	*mlx, char	**map, int	*win_width, int	*win_height)






void	*initialize_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		putstr("Error", 2);
	return (mlx);
}

void	*create_window(void	*mlx, char	**map, int	*win_width, int	*win_height)
{
	int	map_width;
	int	map_height;

	map_width = ft_strlen(map[0]);
	map_height = 0;
	while (map[map_height])
		map_height++;
	*win_width = map_width * TILE_SIZE;
	*win_height = map_height * TILE_SIZE;
	return (mlx_new_window(mlx, *win_width, *win_height, "GTA San Andreas"));
}

void	load_textures(void	*mlx, void	**wall, void	**floor, void	**player, void	**collectible, void	**e_xit, char **map)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	*wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &w, &h);
	if (!(*wall))
		(putstr("Error", 2), ft_free2d(map), exit (1));
	*floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &w, &h);
	if (!(*floor))
		(putstr("Error", 2), ft_free2d(map), exit (1));
	*player = mlx_xpm_file_to_image(mlx, "player.xpm", &w, &h);
	if (!(*player))
		(putstr("Error", 2), ft_free2d(map), exit (1));
	*collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &w, &h);
	if (!(*e_xit))
		(putstr("Error", 2), ft_free2d(map), exit (1));
	*e_xit = mlx_xpm_file_to_image(mlx, "exit.xpm", &w, &h);
}

void	render_tile(void	*mlx, void	*win, void	*texture, int x, int y)
{
	if (texture)
		mlx_put_image_to_window(mlx, win, texture,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(void *mlx, void *win, char **map, void *textures[5])
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
				render_tile(mlx, win, textures[0], x, y);
			else if (map[y][x] == '0')
				render_tile(mlx, win, textures[1], x, y);
			else if (map[y][x] == 'P')
				render_tile(mlx, win, textures[2], x, y);
			else if (map[y][x] == 'C')
				render_tile(mlx, win, textures[3], x, y);
			else if (map[y][x] == 'E')
				render_tile(mlx, win, textures[4], x, y);
			x++;
		}
		y++;
	}
}
