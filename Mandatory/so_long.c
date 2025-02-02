/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:06:54 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/02 12:08:55 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int *player_p(char **map)
{
	int 		i;
	int 		j;
	static int	pos[2];

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] == 'P')
			{
				pos[0] = i;
				pos[1] = j;
				return(pos);
			}
			j++;
		}
		
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	char **map;
	char **tmp_map;
	int *pp;
	int i;

	i = 0;
	if (ac != 2)
		return (write(2, "Error_ac\n", 9), 2);
	map_name(av[1]);
	map = read_map(av);
	check_map(map);
	while(map[i])
		i++;
	tmp_map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
		(tmp_map[i] = ft_strdup(map[i]), i++);
	tmp_map[i] = NULL;
	pp =  player_p(map);
	flood(tmp_map,pp[0],pp[1]);
	exit_map(tmp_map, map);
	ft_free2d(tmp_map);
	ft_free2d(map);
	return(0);
}
