/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:58:48 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/10 17:49:47 by nbougrin         ###   ########.fr       */
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

void ft_exit(t_game	*game, int fd, char	*str)
{
	ft_free2d(game->map);
	ft_free2d(game->tmp_map);
	free(game);
	putstr(str,fd);
	if (fd == 1)
		exit(0);
	else
	exit (1);
}

void	read_map(char **av, t_game *game)
{
	char	*line;
	int		fd;
	char	*str;
	char	*tmp;

	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit(game, 2, "fd error");
	line = get_next_line(fd);
	if (!line)
		(close(fd), ft_exit(game, 2, "Empty map"));
	while (line)
	{
		tmp = str;
		str = ft_strjoin(str, line);
		(free(line), free(tmp));
		line = get_next_line (fd);
	}
	if (str[ft_strlen(str) - 1] == '\n')
		ft_exit(game, 2, "Error finding new line in end of map");
	game->map = ft_split(str, '\n');
	if (!game->map)
		(close(fd), free(str), ft_exit(game, 2, "Error"));
	free(str), close(fd);
}

void exit_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if(game->map[i][j] != '1' && game->map[i][j] != 'X')
				ft_exit(game, 2, "Error Player");
			j++;
		}
		i++;
	}
}

void	flood(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		map[y][x] = 'X';
	else if (map[y][x] != '1' && map[y][x] != 'X')
	{
		map[y][x] = 'X';
		flood(map, y + 1, x);
		flood(map, y, x + 1);
		flood(map, y - 1, x);
		flood(map, y, x - 1);
	}
}
