/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:26:08 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 10:26:38 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
