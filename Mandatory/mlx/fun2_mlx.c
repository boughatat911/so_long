/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:28:31 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 11:29:53 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	return_chek(t_game *game)
{
	if (!game->textures.wall)
		ft_exit(game, 2, "Error: Wall texture not loaded\n", 911);
	if (!game->textures.floor)
		ft_exit(game, 2, "Error: Floor texture not loaded\n", 911);
	if (!game->textures.player)
		ft_exit(game, 2, "Error: Player texture not loaded\n", 911);
	if (!game->textures.exit_open)
		ft_exit(game, 2, "Error: Exit (open) texture not loaded\n", 911);
}

