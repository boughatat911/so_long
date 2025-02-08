/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:07:42 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/08 18:39:24 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (n < 0)
	{
		i = ft_putchar ('-');
		n *= -1;
		i += ft_putnbr(n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr (n / 10);
		i += ft_putchar (n % 10 + '0');
	}
	else if (n >= 0 && n < 10)
		i += ft_putchar (n % 10 + '0');
	return (i);
}
void key_action(int key, char **map)
{
	int x;
	int y;
	int t_x;
	int t_y;

	x = 0;
	y = 0;
	player_p(map, &x, &y);
	t_x = x;
	t_y = y;
	if (key == 'W')
		t_y--;
	else if (key == 'S')
		t_y++;
	else if (key == 'A')
		t_x--;
	else if (key == 'D')
		t_x++;
	if (map[t_x][t_y] != '1')
	{
		map[x][y] = '0';
		map[t_x][t_y] = 'P';
		// puts
	}
}
void	hook_key(void	*mlx, void *win)
{
	void	*key;

	
	mlx_key_hook(win, key_action, NULL);
	mlx_loop(mlx);
}
