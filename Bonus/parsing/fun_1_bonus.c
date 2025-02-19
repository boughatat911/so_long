/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:09:37 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 10:38:55 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	wall(char *str, int flag, t_game *game)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (flag == 1)
	{
		if (str[i] != '1' || str[0] != '1')
			return (911);
	}
	else if (flag == 2)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != '1')
				ft_exit(game, 2, "Error wall\n", 0);
			i++;
		}
	}
	return (0);
}

void	wall_check(t_game	*g)
{
	int	i;

	i = 0;
	while (g->map[g->j])
	{
		g->s = g->map[g->j];
		i = 0;
		while (g->s[i])
		{
			if ((g->s[i] != '1') && (g->s[i] != '0') && (g->s[i] != 'C')
				&& (g->s[i] != 'P') && (g->s[i] != 'E') && (g->s[i] != 'B'))
				ft_exit(g, 2, "Error map1\n", 0);
			if (g->s[i] == 'C')
				g->c++;
			else if (g->s[i] == 'P')
				g->p++;
			else if (g->s[i] == 'E')
				g->e++;
			else if (g->s[i] == 'B')
				g->b++;
			i++;
		}
		g->j++;
	}
	wall_check_2(g, g->j - 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	check_map(t_game *game)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = game->map;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (tmp[j])
		{
			if ((ft_strlen(game->map[i]) != ft_strlen(tmp[j]))
				|| (wall(tmp[j], 1, game) == 911))
				ft_exit(game, 2, "Error_map_len\n", 0);
			j++;
		}
		i++;
	}
	i = 0;
	while (game->map[0][i])
		i++;
	if (i > 38)
		ft_exit(game, 2, "Error map len\n", 0);
	wall_check(game);
}

void	map_name(char *str)
{
	if (ft_strlen(str) < 4 || ft_strcmp(".ber", &str[ft_strlen(str) - 4]))
	{
		write(2, "Error_map_name\n", 15);
		exit(1);
	}
}
