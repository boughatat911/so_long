/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:08:40 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/21 15:24:21 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int	ft_lstsize(t_list	*lst)
{
	int		count;
	t_list	*sin;

	if (!lst)
		return (0);
	sin = lst;
	count = 0;
	while (sin)
	{
		count++;
		sin = sin->next;
	}
	return (count);
}

void	ft_indexing(t_list *stack)
{
	t_list	*tmp;
	t_list	*check;
	int		indix;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		indix = 0;
		check = stack;
		while (check)
		{
			if (check->content < tmp->content)
				indix++;
			check = check->next;
		}
		tmp->index = indix;
		tmp = tmp->next;
	}
}

int	ft_check_indix(t_list	*stack, int len)
{
	int	i;

	i = ft_lstsize(stack) / 2;
	while (i--)
	{
		if (stack->index == len)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_free2darray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}
