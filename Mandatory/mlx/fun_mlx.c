/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/14 10:24:09 by nbougrin         ###   ########.fr       */
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
				g->x = i;
				g->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_player(t_game *g, int new_x, int new_y)
{
	if (g->map[new_x][new_y] == '0')
	{
		g->map[g->x][g->y] = '0';
		g->map[new_x][new_y] = 'P';
		g->n++;
	}
	if (g->map[new_x][new_y] == 'C')
	{
		g->n++;
		g->map[g->x][g->y] = '0';
		g->map[new_x][new_y] = 'P';
		g->c--;
	}
	if (g->map[new_x][new_y] == 'E' && g->c == 0)
		ft_exit(g, 1, "| Mission passed!|\n|    RESPECT +   |\n", 911);
	if (g->map[new_x][new_y] == 'E' && g->c != 0)
		return ;
	if (g->map[new_x][new_y] == '1')
		return ;
	render_map(g, g->map);
	putstr("Move number: ", 1);
	ft_itoa(g->n);
	putstr("\n", 1);
}

void	action_player(int key, t_game *g)
{
	player_p(g);
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
		ft_exit(g, 1, "|  You are exit   |\n| Mission Failed! |\n", 911);
	if (key == W || key == S || key == A || key == D)
		action_player(key, g);
	return (0);
}

int	handle_close(t_game *g)
{
	ft_exit(g, 1, "| You are close window |\n|    Mission Failed!   |\n", 911);
	return (0);
}
