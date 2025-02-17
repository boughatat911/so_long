/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:50:05 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/17 13:06:24 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

#define MAX_ENEMIES 5

void find_enemies(t_game *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g->num_enemies = 0;

	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'B')
			{
				if (g->num_enemies < MAX_ENEMIES)
				{
					g->enemies[g->num_enemies].x = j;
					g->enemies[g->num_enemies].y = i; 
					g->num_enemies++;
				}
			}
			j++;
		}
		i++;
	}
}


static void	check_and_move_enemy(t_game *game, t_enemy *enemy, int new_x, int new_y)
{
	player_p(game);
	if (new_y == game->y && new_x == game->x)
	{
		putstr("|  Mission Failed! momo |", 2);
		// ft_exit(g, 2, "\n",911);
		exit(1);
	}
	printf("<%d  %d> == <%d  %d>\n", game->y, game->x,new_y, new_x );
	// int x  = 
	if (new_x >= 0 && new_x < game->map_width
		&& new_y >= 0 && new_y < game->map_height
		&& game->map[new_y][new_x] == '0')
	{
	
		game->map[enemy->y][enemy->x] = '0';
		game->map[new_y][new_x] = 'B';
		enemy->x = new_x;
		enemy->y = new_y;
	}
}

static void	calculate_enemy_move(t_game *game, int i)
{
	int	direction;
	int	new_x;
	int	new_y;

	direction = rand() % 16;
	new_x = game->enemies[i].x;
	new_y = game->enemies[i].y;
	if (direction == 0)
		new_y--;
	else if (direction == 1)
		new_y++;
	else if (direction == 2)
		new_x--;
	else if (direction == 3)
		new_x++;
	check_and_move_enemy(game, &game->enemies[i], new_x, new_y);
}

void	move_enemies(t_game *game)
{
	static int	frame_counter = 0;
	int			i;

	if (!game || !game->map)
		return ;
	find_enemies(game);
	frame_counter++;
	if (frame_counter % 100 != 0)
		return ;
	i = 0;
	while (i < game->num_enemies)
	{
		calculate_enemy_move(game, i);
		i++;
	}
}

int	game_loop(t_game *game)
{
	if (!game)
		return (-1);
	move_enemies(game);
	render_map(game, game->map);
	return (0);
}

