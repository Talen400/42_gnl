/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/15 10:42:44 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_indexnewline(char *str)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	return (n);
}

static char	*ft_str(int fd, char *buffer, ssize_t *nbyte, char **rest)
{
	char		*str;
	char		*tmp;
	char		*ptr;

	str = ft_strdup("");
	while (*nbyte > 0 && !ft_strchr(buffer, '\n'))
	{
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		*nbyte = read(fd, buffer, BUFFER_SIZE);
		buffer[*nbyte] = '\0';
	}
	ptr = ft_substr(buffer, 0, ft_indexnewline(buffer) + 1);
	tmp = str;
	str = ft_strjoin(tmp, ptr);
	*rest = ft_substr(buffer, ft_indexnewline(buffer) + 1, *nbyte);
	free(tmp);
	free(ptr);
	return (str);
}

static char	*ft_buffering(int fd)
{
	static char	*rest;
	ssize_t		nbyte;
	char		*buffer;
	char		*str;

	if (!(rest == NULL || *rest == '\0'))
	{
		nbyte = ft_strlen(rest);
		str = ft_str(fd, rest, &nbyte, &rest);
		return (str);
	}
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char ));
	if (!buffer)
		return (NULL);
	nbyte = read(fd, buffer, BUFFER_SIZE);
	if (nbyte <= 0)
	{
		free(buffer);
		free(rest);
		rest = NULL;
		return (NULL);
	}
	buffer[nbyte] = '\0';
	str = ft_str(fd, buffer, &nbyte, &rest);
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_buffering(fd);
	return (str);
}
