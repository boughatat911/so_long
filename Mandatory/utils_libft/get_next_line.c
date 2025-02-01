/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:49 by nbougrin          #+#    #+#             */
/*   Updated: 2025/02/01 18:35:17 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_read_new_line(int fd, char *new_line)
{
	char	*buffer;
	int		size_buff;
	char	*tmp;

	size_buff = 1;
	buffer = malloc(((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(new_line), NULL);
	while (!ft_strchr(new_line, '\n') && size_buff != 0)
	{
		size_buff = read(fd, buffer, BUFFER_SIZE);
		if (size_buff < 0)
			return (free(buffer), free(new_line), NULL);
		buffer[size_buff] = '\0';
		tmp = new_line;
		new_line = ft_strjoin(new_line, buffer);
		free(tmp);
	}
	free(buffer);
	return (new_line);
}

static char	*ft_write_new_line(char *new_line)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!new_line || !(*new_line))
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	line = ft_substr(new_line, 0, i);
	if (!line)
		return (free(new_line), NULL);
	return (line);
}

static char	*ft_get_new_line(char *new_line)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	if (!new_line)
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	if (new_line[i] == '\0')
		return (free(new_line), NULL);
	j = i;
	while (new_line[j] != '\0')
		j++;
	new = ft_substr(new_line, i, j - i);
	if (!new)
		return (free(new_line), NULL);
	free (new_line);
	new_line = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*new_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	new_line = ft_read_new_line(fd, new_line);
	if (!new_line)
		return (NULL);
	line = ft_write_new_line(new_line);
	if (!line)
		return (free(new_line), new_line = NULL, NULL);
	new_line = ft_get_new_line(new_line);
	return (line);
}
