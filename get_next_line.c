/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/07 09:35:06 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buffering(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	nbyte;
	char	*str;
	int		len;

	nbyte = read(fd, buf, BUFFER_SIZE);
	if (nbyte == 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	len = 0;
	while (buf[len] != '\n' && buf[len] != '\0')
		len++;
	str = malloc ((len + 1) * sizeof(char ));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
		str[len] = buf[len];
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;

	if (fd < -1 && BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_buffering(fd);
	return (str);
}
