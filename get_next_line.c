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

static ssize_t	ft_indexln(char *str)
{
	ssize_t	n;

	n = 0;
	if (!str)
		return (-1);
	while (str[n] && str[n] != '\n')
		n++;
	if (str[n] == '\n')
		return (n);
	return (-1);
}

static char	*ft_buffering(int fd, char **buffer)
{
	ssize_t		nbyte;

	*buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char ));
	if (!(*buffer))
		return (NULL);
	nbyte = read(fd, *buffer, BUFFER_SIZE);
	if (nbyte <= 0)
	{
		free(*buffer);
		return (NULL);
	}
	(*buffer)[nbyte] = '\0';
	return (*buffer);
}

static char	*ft_rest(char **rest)
{
	return (NULL);
}

static char *ft_str(int fd)
{
	static char	*rest;
	char		*line;

	if (rest)
	{
		line = ft_rest(&rest);
		return (line);
	}
	line = NULL;
	while (!line)
	{
		if ()
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_str(fd);
	return (line);
}
