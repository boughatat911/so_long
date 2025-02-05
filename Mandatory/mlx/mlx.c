/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:37:00 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/05 15:30:49 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "/home/nbougrin/boughatat/so_long/Mandatory/so_long.h"
// void mlx_map(char **map)
// {
// 	void* mlx;
// 	void* win;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return  ;
// 	win = mlx_new_window(mlx, 1920, 1080, "GTA");
// 	if (!win)
// 		return ;
// 	mlx_loop(mlx);

// //////////Textures/////////////////////////
// 	void	*wall;
// 	void	*floor;
// 	void	*player;
// 	void	*collectible;
// 	void	*exit;

// 	int width;
// 	int height;
	
// 	width = 32;
// 	height = 32;
	
// 	wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
// 	floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &width, &height);
// 	player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height);
// 	collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &width, &height);
// 	exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height);
// //////////////render  the map///////////////////
// 	int x = 0;
// 	int y = 0;
// 	while (map[x])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if (map[x][y] == '1')
// 				mlx_put_image_to_window(mlx, win, wall,x * 32, y * 32);
// 			else if (map[x][y] == '0')
// 				mlx_put_image_to_window(mlx, win, floor,x * 32, y * 32);
// 			else if (map[x][y] == 'P')
// 				mlx_put_image_to_window(mlx, win, player, x * 32, y * 32);
// 			else if (map[x][y] == 'E')
// 				mlx_put_image_to_window(mlx, win, exit,x * 32, y * 32);
// 			else if (map[x][y] == 'C')
// 				mlx_put_image_to_window(mlx, win, collectible,x * 32, y * 32);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_loop(mlx);

// }

///////////////////////////////////////////////////////////////////////////////

// void mlx_map(char **map)
// {
// 	void *mlx;
// 	void *win;
	
// 	// Initialize MLX
// 	mlx = mlx_init();
// 	if (!mlx)
// 		return;
	
// 	// Calculate map size
// 	int map_width = ft_strlen(map[0]);  // Number of columns
// 	int map_height = 0;              // Number of rows

// 	while (map[map_height])
// 		map_height++;

// 	// Create window based on map size
// 	int win_width = map_width * TILE_SIZE;
// 	int win_height = map_height * TILE_SIZE;
// 	win = mlx_new_window(mlx, win_width, win_height, "so_long");
// 	if (!win)
// 		return;

// 	// Load textures
// 	void *wall, *floor, *player, *collectible, *exit;
// 	int w_wall, h_wall, w_floor, h_floor, w_player, h_player, w_coll, h_coll, w_exit, h_exit;
	
// 	wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &w_wall, &h_wall);
// 	floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &w_floor, &h_floor);
// 	player = mlx_xpm_file_to_image(mlx, "player.xpm", &w_player, &h_player);
// 	collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &w_coll, &h_coll);
// 	exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &w_exit, &h_exit);

// 	if (!wall || !floor || !player || !collectible || !exit)
// 	{
// 		printf("Error: Failed to load textures\n");
// 		return;
// 	}

// 	// Render the map
// 	int y = 0;
// 	while (map[y])
// 	{
// 		int x = 0;
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == '1')
// 				mlx_put_image_to_window(mlx, win, wall, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (map[y][x] == '0')
// 				mlx_put_image_to_window(mlx, win, floor, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (map[y][x] == 'P')
// 				mlx_put_image_to_window(mlx, win, player, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (map[y][x] == 'E')
// 				mlx_put_image_to_window(mlx, win, exit, x * TILE_SIZE, y * TILE_SIZE);
// 			else if (map[y][x] == 'C')
// 				mlx_put_image_to_window(mlx, win, collectible, x * TILE_SIZE, y * TILE_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}

// 	// Start MLX loop
// 	mlx_loop(mlx);

// 	// Free images (this should be in a function when quitting the game)
// 	mlx_destroy_image(mlx, wall);
// 	mlx_destroy_image(mlx, floor);
// 	mlx_destroy_image(mlx, player);
// 	mlx_destroy_image(mlx, collectible);
// 	mlx_destroy_image(mlx, exit);
// 	mlx_destroy_window(mlx, win);
// }

///////////////////////////////////////////////////
void putstr(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i],1);
		i++;
	}
	write(fd, "\n", 1);
	
}
void	*initialize_mlx(void)
{
    void	*mlx = mlx_init();
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
	return (mlx_new_window(mlx, *win_width, *win_height, "GTA"));
}

void	load_textures(void	*mlx, void	**wall, void	**floor, void	**player, void	**collectible, void	**exit)
{
	int w;
	int h;

	w = 0;
	h = 0;
	*wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &w, &h);
	*floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &w, &h);
	*player = mlx_xpm_file_to_image(mlx, "player.xpm", &w, &h);
	*collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &w, &h);
	*exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &w, &h);
}

void	render_tile(void	*mlx, void	*win, void	*texture, int x, int y)
{
    if (texture)
        mlx_put_image_to_window(mlx, win, texture, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(void	*mlx, void	*win, char **map, void	*textures[5])
{
    int	y;
	int	x;

	y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1') render_tile(mlx, win, textures[0], x, y);
            else if (map[y][x] == '0') render_tile(mlx, win, textures[1], x, y);
            else if (map[y][x] == 'P') render_tile(mlx, win, textures[2], x, y);
            else if (map[y][x] == 'C') render_tile(mlx, win, textures[3], x, y);
            else if (map[y][x] == 'E') render_tile(mlx, win, textures[4], x, y);
            x++;
        }
        y++;
    }
}

void	free_resources(void	*mlx, void	*win, void *textures[5])
{
	int i;

	i = 0;
	while(i > 5)
	{
        mlx_destroy_image(mlx, textures[i]);
		i++;
	}
    mlx_destroy_window(mlx, win);
}

void mlx_map(char **map)
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	void	*textures[5];

	win_width = 0;
	win_height = 0;
	mlx = initialize_mlx();
	if (!mlx)
		return;
	win = create_window(mlx, map, &win_width, &win_height);
	if (!win)
		return;
	load_textures(mlx, &textures[0], &textures[1], &textures[2], &textures[3], &textures[4]);
	render_map(mlx, win, map, textures);
	mlx_loop(mlx);
	free_resources(mlx, win, textures);
}
