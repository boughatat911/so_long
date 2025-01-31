/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:09:02 by nbougrin          #+#    #+#             */
/*   Updated: 2025/01/21 15:24:13 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

static	size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static	size_t	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static	char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

static	void	free2darray(char **array, int n)
{
	while (n--)
		free(array[n]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t		count;
	size_t		i;
	char		**res;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		res[i] = malloc(sizeof (char) * (word_len(s, c) + 1));
		if (!res[i])
			return (free2darray(res, i), NULL);
		ft_strncpy(res[i], s, word_len(s, c));
		res[i++][word_len(s, c)] = '\0';
		s = s + word_len(s, c);
	}
	res[i] = NULL;
	return (res);
}
