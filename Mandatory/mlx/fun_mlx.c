/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 10:56:29 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_p(t_game	*g)
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
				g->x = j;
				g->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_player(t_game *g, int new_y, int new_x)
{
	if (g->map[new_y][new_x] == '0')
	{
		g->map[g->y][g->x] = '0';
		g->map[new_y][new_x] = 'P';
		g->n++;
	}
	if (g->map[new_y][new_x] == 'C')
	{
		g->n++;
		g->map[g->y][g->x] = '0';
		g->map[new_y][new_x] = 'P';
		g->c--;
	}
	if (g->map[new_y][new_x] == 'E' && g->c == 0)
		ft_exit(g, 1, "| Mission passed!|\n|    RESPECT +   |\n", 911);
	if (g->map[new_y][new_x] == 'E' && g->c != 0)
		return ;
	if (g->map[new_y][new_x] == '1')
		return ;
	render_map(g, g->map);
	putstr("Number Of Movements: ", 1);
	ft_itoa(g->n, g);
	putstr("\n", 1);
}

void	action_player(int key, t_game *g)
{
	player_p(g);
	if (key == W)
		move_player(g, g->y - 1, g->x);
	if (key == S)
		move_player(g, g->y + 1, g->x);
	if (key == A)
		move_player(g, g->y, g->x - 1);
	if (key == D)
		move_player(g, g->y, g->x + 1);
}

int	handle_keypress(int key, t_game *g)
{
	if (key == ESC)
		ft_exit(g, 1, "| You left the game |\n|  Mission Failed!  |\n", 911);
	if (key == W || key == S || key == A || key == D)
		action_player(key, g);
	return (0);
}

int	handle_close(t_game *g)
{
	ft_exit(g, 1, "| You closed window |\n|  Mission Failed!  |\n", 911);
	return (0);
}
