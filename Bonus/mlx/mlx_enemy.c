/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:50:05 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 19:52:31 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	display_move(t_game *g)
{
	g->num_move = ft_itoa(g->n, g);
	mlx_string_put(g->mlx, g->win, 10, 20, 0xFFFFFF, "Number Of Movements: ");
	mlx_string_put(g->mlx, g->win, 5, 50, 0xFFFFFF, g->num_move);
	free(g->num_move);
}

static void	check_move_enemy(t_game *game, t_enemy *enemy, int new_x, int new_y)
{
	player_p(game);
	if (new_y == game->y && new_x == game->x)
	{
		putstr("| Mission Failed! |\n", 2);
		ft_exit(game, 2, "|      WASTED     |\n", 911);
	}
	if (game->map[new_y][new_x] == '0')
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
	check_move_enemy(game, &game->enemies[i], new_x, new_y);
}

void	move_enemies(t_game *game)
{
	static int	frame_counter = 0;
	int			i;

	if (!game || !game->map)
		ft_exit(game, 2, "Error\n", 911);
	find_enemies(game);
	frame_counter++;
	if (frame_counter % 30 != 0)
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
	static int	frame_counter = 0;

	if (!game)
		ft_exit(game, 2, "Error\n", 911);
	frame_counter++;
	if (frame_counter % 50 == 0)
	{
		game->coin_frame = (game->coin_frame + 1) % 5;
		render_map(game, game->map);
	}
	move_enemies(game);
	render_map(game, game->map);
	return (0);
}
