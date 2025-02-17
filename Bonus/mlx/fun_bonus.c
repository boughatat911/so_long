/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:29:29 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/17 19:49:04 by nbougrin         ###   ########.fr       */
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
	game->B = 0;
}
void	wall_check_2(t_game	*g, int i)
{
	if (g->p != 1 || g->e != 1 || g->c < 0 || g->B <= 0 || g->B >= 6)
		ft_exit(g, 2, "Error map14\n", 0);
	wall(g->map[i], 2, g);
	wall(g->map[0], 2, g);
	
}
