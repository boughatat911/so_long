/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:06:54 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/14 16:54:35 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	putstr(char	*str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_map(char	**av, t_game	*game)
{
	int	i;

	i = 0;
	game->map = NULL;
	game->tmp_map = NULL;
	read_map(av, game);
	check_map(game);
	while (game->map[i])
		i++;
	if (i > 21)
		ft_exit(game, 2, "Error map\n", 0);
	game->tmp_map = malloc(sizeof(char *) * (i + 1));
	if (!game->tmp_map)
		ft_exit(game, 2, "Error map not valid \n", 0);
	i = 0;
	while (game->map[i])
	{
		game->tmp_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->tmp_map[i] = NULL;
	player_p(game);
	flood(game->tmp_map, game->y, game->x);
	exit_map(game);
	mlx_map(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		write(2, "Error_ac\n", 9);
		return (2);
	}
	map_name(av[1]);
	game = malloc(sizeof(t_game));
	ft_map(av, game);
	return (0);
}
