/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:42:34 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/05 14:22:36 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	render_map(void	*mlx, void	*win, char	**map, void	*textures[5])
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1') render_tile(mlx, win, textures[0], x, y);
			else if (map[y][x] == '0') render_tile(mlx, win, textures[1], x, y);
			else if (map[y][x] == 'P') render_tile(mlx, win, textures[2], x, y);
			else if (map[y][x] == 'E') render_tile(mlx, win, textures[3], x, y);
			else if (map[y][x] == 'C') render_tile(mlx, win, textures[4], x, y);
			x++;
		}
		y++;
	}
}