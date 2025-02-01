/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:58:48 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/01 19:06:24 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free2d(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void ft_error(char **map, char **tmp_map)
{
	ft_free2d(map);
	ft_free2d(tmp_map);
	write(2, "Error\n", 6);
	exit(1);
}

char	**read_map(char **av)
{
	char	*line;
	int		fd;
	char	**map;
	char	*str;
	int		i;
	char	*tmp;

	(1) && (str = NULL, i = 0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		(write(2, "Error_fd\n", 9), exit (1));
	line = get_next_line(fd);
	if (!line)
		(write(2, "Error_empty\n", 9), exit (1));
	while (line)
	{
		tmp = str;
		str = ft_strjoin(str, line);
		(free(line), free(tmp));
		line = get_next_line (fd);
	}
	if (str[ft_strlen(str) - 1] == '\n')
		(write(2, "Error_\\n\n", 9), free(str), exit(1));
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

void exit_map(char **map, char **map1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] != '1' && map[i][j] != 'X')
				ft_error(map, map1);
			j++;
		}
		i++;
	}
}

void	flood(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		map[x][y] = 'X';
	else if (map[x][y] != '1' && map[x][y] != 'X')
	{
		map[x][y] = 'X';
		flood(map, x + 1, y);
		flood(map, x, y + 1);
		flood(map, x - 1, y);
		flood(map, x, y - 1);
	}
}
