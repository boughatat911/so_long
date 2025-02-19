/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/18 20:53:28 by nbougrin         ###   ########.fr       */
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
	game->c = 0;
	game->p = 0;
	game->e = 0;
	game->j = 0;
	game->b = 0;
	game->textures.coin[0] = NULL;
	game->textures.coin[1] = NULL;
	game->textures.coin[2] = NULL;
	game->textures.coin[3] = NULL;
	game->textures.coin[4] = NULL;
}

void	wall_check_2(t_game	*g, int i)
{
	if (g->p != 1 || g->e != 1 || g->c < 0 || g->b <= 0 || g->b >= 6)
		ft_exit(g, 2, "Error map14\n", 0);
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

void	return_chek(t_game *game)
{
	if (!game->textures.wall)
		ft_exit(game, 2, "Error: Wall texture not loaded\n", 911);
	if (!game->textures.floor)
		ft_exit(game, 2, "Error: Floor texture not loaded\n", 911);
	if (!game->textures.player)
		ft_exit(game, 2, "Error: Player texture not loaded\n", 911);
	if (!game->textures.exit_close)
		ft_exit(game, 2, "Error: Exit (closed) texture not loaded\n", 911);
	if (!game->textures.exit_open)
		ft_exit(game, 2, "Error: Exit (open) texture not loaded\n", 911);
	if (!game->textures.enemy)
		ft_exit(game, 2, "Error: Enemy texture not loaded\n", 911);

}