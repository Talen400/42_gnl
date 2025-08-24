/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/15 18:48:49 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buffering(int fd, char *rest)
{
	ssize_t		nbyte;
	char		*tmp;
	char		*buffer;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (rest);
}

static char	*ft_rest(char **rest)
{
	char	*line;
	char	*tmp;
	char	*nl;

	if (!*rest || !**rest)
		return (NULL);
	nl = ft_strchr(*rest, '\n');
	if (nl)
	{
		line = ft_substr(*rest, 0, nl - *rest + 1);
		tmp = ft_strdup(nl + 1);
		free(*rest);
		*rest = tmp;
	}
	else
	{
		line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_buffering(fd, rest);
	if (!rest || !*rest)
		return (NULL);
	line = ft_rest(&rest);
	return (line);
}
