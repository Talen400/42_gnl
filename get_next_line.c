/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/07 18:57:46 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(int fd, ssize_t *nbyte, char **buff)
{
	char	*str;
	char	*min_buf;

	str = ft_strdup("");
	while (!ft_strchr(*buff, '\n'))
	{
		min_buf = str;
		str = ft_strjoin(min_buf, *buff);
		free(min_buf);
		*nbyte = read(fd, *buff, BUFFER_SIZE);
		(*buff)[BUFFER_SIZE] = '\0';
	}
	return (str);
}

static char	*ft_buffering(int fd)
{
	char	*str;
	ssize_t	nbyte;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char ));
	if (buff == NULL)
		return (NULL);
	nbyte = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	if (nbyte <= 0)
	{
		free(buff);
		return (NULL);
	}
	str = ft_line(fd, &nbyte, &buff);
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = NULL;
	if (fd < -1 || BUFFER_SIZE == 0)
		return (str);
	str = ft_buffering(fd);
	return (str);
}
