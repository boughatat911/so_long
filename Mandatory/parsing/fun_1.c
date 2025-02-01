/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:09:37 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/01 19:09:54 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int wall(char *str, int flag, char **ss)
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
				if(str[i] != '1')
					(write(2, "error_1_wall\n", 13),ft_free2d(ss), exit(1));
				i++;
			}
		}
	return (0);
}
void wall_check(char **ss)
{
	char *str;
	int i;
	int c;
	int p;
	int e;
	int j;

	(1) && (i = 0, c = 0, p = 0, e = 0, j = 0);
	while (ss[j])
	{
		(str = ss[j], i = 0);
		while (str[i])
		{
			if(!((str[i] == '1') || (str[i] == '0') || (str[i] == 'C') || (str[i] == 'P') || (str[i] == 'E')))
				(write (1, "error_wall\n", 8), ft_free2d(ss), exit(1));
			if(str[i] == 'C')
				c++;
			else if(str[i] == 'P')
				p++;
			else if(str[i] == 'E')
				e++;
			i++;
		}
		j++;
	}
	if(p != 1 || e != 1 || c < 0)
		(write (1, "error_<\n", 8), ft_free2d(ss), exit(1));
	(wall(ss[j-1], 2, ss), wall(ss[0], 2, ss));	
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
void check_map(char **str)
{
	char **tmp;
	int i; 
	int j;
	
	tmp = str;
	i = 0;
	while(str[i])
	{
		j = 0;
		while(tmp[j])
		{
			if((ft_strlen(str[i]) != ft_strlen(tmp[j])) || (wall(tmp[j], 1, str) == 911))
			{
				write(2, "Error_map_len\n", 14);
				ft_free2d(str);
				exit(1);
			}
			j++;
		}
		i++;
	}
	wall_check(str);
}

void map_name(char *str)
{
	if (ft_strlen(str) < 4 || ft_strcmp(".ber", &str[ft_strlen(str) - 4]))
		(write(2, "Error_map_name\n", 15), exit(1));
}
