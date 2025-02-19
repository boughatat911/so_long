/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:36:05 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/19 10:56:52 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_length(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_itoa(int n, t_game *game)
{
	long	num;
	int		len;
	char	*str;

	if (n > 2147483647 ||  n < -2147483648)
		ft_exit(game, 2, "Error itoa\n", 911);
	num = n;
	len = get_length(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len-- && str[len] != '-')
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	putstr(str, 1);
	free(str);
}
