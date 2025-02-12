/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/12 15:26:36 by nbougrin         ###   ########.fr       */
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

static void	handle_exit_pos(t_game *g, int new_x, int new_y)
{
	if (*g->ex == -1 && *g->ey == -1 && g->map[new_x][new_y] == 'E')
	{
		*g->ex = new_x;
		*g->ey = new_y;
	}
	if (g->x == *g->ex && g->y == *g->ey)
		g->map[g->x][g->y] = 'E';
	else
		g->map[g->x][g->y] = '0';
	if (g->map[new_x][new_y] == 'E' && g->c == 0)
		ft_exit(g, 1, "| Mission passed!|\n|    RESPECT +   |", 911);
}

void	move_player(t_game *g, int new_x, int new_y)
{
	static int	exit_x = -1;
	static int	exit_y = -1;

	if (g->map[new_x][new_y] == '1')
		return ;
	g->ex = &exit_x;
	g->ey = &exit_y;
	handle_exit_pos(g, new_x, new_y);
	if (g->map[new_x][new_y] == 'C')
		g->c--;
	g->map[new_x][new_y] = 'P';
	g->x = new_x;
	g->y = new_y;
	g->n++;
	render_map(g, g->map);
	printf("move => [%d] <<=>> coins => [%d]\n", g->n, g->c);
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
		ft_exit(g, 1, "Mission Failed!", 911);
	if (key == W || key == S || key == A || key == D)
		action_player(key, g);
	return (0);
}
