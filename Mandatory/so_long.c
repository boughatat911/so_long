/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:06:54 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/08 18:46:57 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_p(char **map, int *y, int *x)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void ft_map(char	**av, char	**map, char	**tmp_map)
{
	int i;
	int x;
	int y;
	t_game game;

	x = 0;
	y = 0;
	map = NULL;
	i = 0;
	map = read_map(av, map);
	check_map(map);
	while(map[i])
		i++;
	tmp_map = malloc(sizeof(char *) * (i + 1));
	if (!tmp_map)
		(write(2, "Errort\n", 6), ft_free2d(map), exit(1));
	i = 0;
	while (map[i])
		(tmp_map[i] = ft_strdup(map[i]), i++);
	tmp_map[i] = NULL;
	player_p(map, &game.y,&game.x);
	mlx_map(map);
	flood(tmp_map, x, y);
	exit_map(tmp_map, map);
	(ft_free2d(tmp_map), ft_free2d(map));
}
int main(int ac, char **av)
{
	char **map;
	char **tmp_map;

	map = NULL;
	tmp_map  = NULL;
	if (ac != 2)
		return (write(2, "Error_ac\n", 9), 2);
	map_name(av[1]);
	ft_map(av, map, tmp_map);
	return(0);
}