/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/10 16:25:13 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


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
	if (g->map[new_x][new_y] == 'C')
	{
		g->n++;
		g->map[g->x][g->y] = '0';
		g->map[new_x][new_y] = 'P';
		g->c--;
	}
	if (g->map[new_x][new_y] == 'E' && g->c == 0)
	{
		write (1, "You won!\n", 10);
		exit(1);
	}
	if (g->map[new_x][new_y] == 'E' && g->c != 0)
		return ;
	if (g->map[new_x][new_y] == '1')
		return ;
	render_map(g, g->map);
	printf("move => [%d] <<=>> coins => [%d]\n",g->n,  g->c);
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