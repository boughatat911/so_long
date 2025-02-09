/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/09 20:04:24 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


// // int key_action(int key,void *param)
// // {
// // 	t_game *game = (t_game *)param;
// // 	int t_x;
// // 	int t_y;

// // 	player_p(game->map, &game->y,&game->x);
// // 		// printf("y => {%d} x => {%d}\n", game->y, game->x);
// // 	t_y = game->y;
// // 	t_x = game->x;
// // 	if (key == W)
// // 		t_y--;
// // 	else if (key == S)
// // 		t_y++;
// // 	else if (key == A)
// // 		t_x--;
// // 	else if (key == D)
// // 		t_x++;
// // 	else if(key == ESC)
// // 		exit(1);
// // 	// if (game->map[t_y][t_x] == '0')
// // 	// {
// // 	// 		game->map[game->y][game->x] = '0';
// // 	// 	    game->map[t_x][t_y] = 'P';
// // 	// 		game->y = t_y;
// // 	// 		game->x = t_x;
// // 	// }
// // 	// if (game->map[t_y][t_x] == 'E')
// // 	// 	return (0);
// // 	// if (game->map[t_y][t_x] == '1')
// // 	// 	return (0);
	
// // 		// mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, game->y * TILE_SIZE, game->x * TILE_SIZE);
// // 		// mlx_put_image_to_window(game->mlx, game->win, game->textures.player, t_y * TILE_SIZE, t_x * TILE_SIZE);
// // 	if (game->map[t_y][t_x] != '1' && game->map[t_y][t_x] == '0')
// // 	{
// // 		printf("y => {%d} x => {%d}\n", game->y, game->x);
// // 		game->n++;
// // 		game->map[game->y][game->x] = '0';
// // 		game->map[t_x][t_y] = 'P';
// // 		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, game->y * TILE_SIZE, game->x * TILE_SIZE);
// // 		mlx_put_image_to_window(game->mlx, game->win, game->textures.player, t_y * TILE_SIZE, t_x * TILE_SIZE);
// // 		// game->y = t_y;
// // 		// game->x = t_x;
// // 		printf("move number is : %d\n", game->n);
		
// // 	}
// // }
// // 	// game->map = param;
// // 		return (0);
	

// // }

// // int key_action(int key, void *param)
// // {
// //     int t_x, t_y;
    
// //     // Use param directly as t_game pointer
// //     t_game *game = (t_game *)param; 

// //     t_x = game->x;
// //     t_y = game->y;

// //     // ✅ Debugging output
// //     printf("Key pressed: %d\n", key);
// //     printf("Before move: x = %d, y = %d\n", game->x, game->y);

// //     // ✅ Move logic
// //     if (key == W)
// //         t_y--;
// //     else if (key == S)
// //         t_y++;
// //     else if (key == A)
// //         t_x--;
// //     else if (key == D)
// //         t_x++;
// //     else if (key == ESC)
// //         exit(0);

// //     // ✅ Check if new position is not a wall
// //     if (game->map[t_y][t_x] != '1')
// //     {
// //         game->n++; // Move counter
// //         game->map[game->y][game->x] = '0';  // Clear old position
// //         game->map[t_y][t_x] = 'P';  // Set new position

// //         // ✅ Update window only where necessary
// //         mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, game->x * TILE_SIZE, game->y * TILE_SIZE);
// //         mlx_put_image_to_window(game->mlx, game->win, game->textures.player, t_x * TILE_SIZE, t_y * TILE_SIZE);

// //         // ✅ Update player's coordinates
// //         game->x = t_x;
// //         game->y = t_y;

// //         // ✅ Debugging output
// //         printf("After move: x = %d, y = %d\n", game->x, game->y);
// //         printf("Move number: %d\n", game->n);
// //     }
// //     return (0);
// // }

// // int key_action(int key, void *param)
// // {
// //     if (!param)
// //         return (0); // Prevent segfault if game is NULL

// //     t_game *game = (t_game *)param;
// //     int t_x = game->x;
// //     int t_y = game->y;

// //     // ✅ Handle movement keys
// //     if (key == W)
// //         t_y--;
// //     else if (key == S)
// //         t_y++;
// //     else if (key == A)
// //         t_x--;
// //     else if (key == D)
// //         t_x++;
// //     else if (key == ESC)
// //         exit(0);

// //     // ✅ Check if the new position is not a wall
// //     if (game->map[t_y][t_x] != '1')
// //     {
// //         game->n++; // Move counter
// //         game->map[game->y][game->x] = '0';  // Clear old position
// //         game->map[t_y][t_x] = 'P';  // Set new position


// //         printf("Move number: %d\n", game->n);
// //     }
// //         render_map(game, game->map);
// //     return (0);
// // }
//  void	find_player(t_game *g)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (g->map[i])
// 	{
// 		j = 0;
// 		while (g->map[i][j])
// 		{
// 			if (g->map[i][j] == 'P')
// 			{
// 				g->x = i;
// 				g->y = j;
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	move_player(t_game *game, int new_x, int new_y)
// {
// 	if (game->map[new_x][new_y] == '0')
// 	{
// 		game->map[game->x][game->y] = '0';
// 		game->map[new_x][new_y] = 'P';
// 		game->n++;
// 	}
// 	// if (game->map[new_x][new_y] == 'C')
// 	// {
// 	// 	game->n++;
// 	// 	game->map[game->x][game->y] = '0';
// 	// 	game->map[new_x][new_y] = 'P';
// 	// 	// game->count_c--;
// 	// }
// 	// if (game->map[new_x][new_y] == 'E' && game->count_c == 0)
// 	// {
// 	// 	write (1, "You won!\n", 10);
// 	// 	exit_window(game);
// 	// }
// 	// if (game->map[new_x][new_y] == 'E' && game->count_c != 0)
// 	// 	return ;
// 	if (game->map[new_x][new_y] == '1')
// 		return ;
// 	render_map(game, game->map);
// 	// display_move_count(game);
// }
// // static void	move_player(t_game *game, int new_x, int new_y)
// // {
// // 	if (game->map[new_x][new_y] == '1') // Prevent moving into walls
// // 		return ;

// // 	game->map[game->x][game->y] = '0';  // Clear old position
// // 	game->map[new_x][new_y] = 'P';  // Move player
// // 	game->x = new_x; // ✅ Update player's actual position
// // 	game->y = new_y;
// // 	game->n++; // Increase move count

// // 	render_map(game, game->map); // Refresh map
// // }

// static void	action_player(int key, t_game *g)
// {
// 	find_player(g);
// 	if (key == W)
// 		move_player(g, g->x - 1, g->y);
// 	if (key == S)
// 		move_player(g, g->x + 1, g->y);
// 	if (key == A)
// 		move_player(g, g->x, g->y - 1);
// 	if (key == D)
// 		move_player(g, g->x, g->y + 1);
// }

// int	handle_keypress(int key, t_game *g)
// {
// 	if (key == ESC)
// 		exit(1);
// 	if (key == W || key == S || key == A || key == D)
// 		action_player(key, g);
// 	return (0);
// // }

void	find_player(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->x = i;
				g->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	move_player(t_game *g, int new_x, int new_y)
{
	if (g->map[new_x][new_y] == '0')
	{
		g->map[g->x][g->y] = '0';
		g->map[new_x][new_y] = 'P';
		g->n++;
	}
	// if (g->map[new_x][new_y] == 'C')
	// {
	// 	g->move++;
	// 	g->map[g->x][g->y] = '0';
	// 	g->map[new_x][new_y] = 'P';
	// 	g->count_c--;
	// }
	// if (g->map[new_x][new_y] == 'E' && g->count_c == 0)
	// {
	// 	write (1, "You won!\n", 10);
	// 	exit_window(g);
	// }
	// if (g->map[new_x][new_y] == 'E' && g->count_c != 0)
	// 	return ;
	if (g->map[new_x][new_y] == '1')
		return ;
	render_map(g, g->map);
	// display_move_count(g);
}

static void	action_player(int key, t_game *g)
{
	find_player(g);
	if (key == W)
		move_player(g, g->x - 1, g->y);
	if (key == S)
		move_player(g, g->x + 1, g->y);
	if (key == A)
		move_player(g, g->x, g->y - 1);
	if (key == D)
		move_player(g, g->x, g->y + 1);
}

int	handle_keypress(int key, t_game *g)
{
	if (key == ESC)
		exit(1);
	if (key == W || key == S || key == A || key == D)
		action_player(key, g);
	return (0);
}