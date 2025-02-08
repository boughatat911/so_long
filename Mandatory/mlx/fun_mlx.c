/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/08 20:11:37 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void key_action(int key, char **map)
{
	int t_x;
	int t_y;
	t_game game;
	t_game game;

	player_p(map, &game.y,&game.x);
	t_y = game.y;
	t_x = game.x;
	if (key == 'W')
		t_y--;
	else if (key == 'S')
		t_y++;
	else if (key == 'A')
		t_x--;
	else if (key == 'D')
		t_x++;
	if (map[t_x][t_y] != '1')
	{
		game.n++;
		map[game.y][game.x] = '0';
		map[t_x][t_y] = 'P';
		mlx_put_image_to_window(game.mlx, game.win, game.textures.floor, game.y * TILE_SIZE, game.x * TILE_SIZE);
		mlx_put_image_to_window(game.mlx, game.win, game.textures.floor, t_y * TILE_SIZE, t_x * TILE_SIZE);
		game.y = t_y;
		game.x = t_x;
		printf("move number is : %d\n", game.n);
	}
}

