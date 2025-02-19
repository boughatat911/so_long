/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 11:27:36 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_status(t_game *game)
{
	if (game->c == 0)
		render_tile(game, game->textures.exit_open);
	else
		render_tile(game, game->textures.exit_close);
}

void	ins(t_game	*game)
{
	int	i;
	game->c = 0;
	game->p = 0;
	game->e = 0;
	game->j = 0;
	game->b = 0;
	i = 0;
	while (i < 5)
	{
		game->textures.coin[i] = NULL;
		i++;
	}
}

void	wall_check_2(t_game	*g, int i)
{
	if (g->p != 1 || g->e != 1 || g->c < 0 || g->b <= 0 || g->b >= 6)
		ft_exit(g, 2, "Error map\n", 0);
	wall(g->map[i], 2, g);
	wall(g->map[0], 2, g);
}

void	find_enemies(t_game	*g)
{
	int	i;
	int	j;

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

void	render_tile(t_game *game, void *texture)
{
	if (texture)
		mlx_put_image_to_window(game->mlx,
			game->win, texture, game->x * TILE_SIZE, game->y * TILE_SIZE);
}
