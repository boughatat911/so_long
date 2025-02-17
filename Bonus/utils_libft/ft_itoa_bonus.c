/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:36:05 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/17 15:51:26 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	ft_itoa(int n, char *src)
{
	long	num;
	int		len;
	char	*str;

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
	putstr(src, 1);
	putstr(str, 1);
	putstr("\n", 1);
	free(str);
}
