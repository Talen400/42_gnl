/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/12 18:54:57 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_indexNewLine(char *buffer)
{
	int	n;

	n = 0;
	while (buffer[n] && buffer[n] != '\n')
		n++;
	return (n);
}

static char	*ft_rest(char ****rest)
{
	char	*str;
	char	*temp;
	int		len;

	if (!(***rest))
		return (ft_strdup(""));
	str = ft_substr(***rest, 0, ft_indexNewLine(***rest) + 1);
	temp = ***rest;
	len = ft_strlen(temp);
	***rest = ft_substr(temp, ft_indexNewLine(***rest) + 1, len);
	free(temp);
	return (str);
}

static char	*ft_strrest(int fd, char **buffer, int *nbyte, char ***rest)
{
	char	*str;
	char	*temp;
	char	*ptr;

	str = ft_rest(&rest);
	if (!ft_strchr(str, '\n'))
	{
	while (*nbyte >= 0 && !ft_strchr(*buffer, '\n'))
		{
			temp = str;
			str = ft_strjoin(temp, *buffer);
			free(temp);
			*nbyte = read(fd, *buffer, BUFFER_SIZE);
			(*buffer)[*nbyte] = '\0';
		}
		ptr = ft_substr(*buffer, 0, ft_indexNewLine(*buffer) + 1);
		temp = str;
		str = ft_strjoin(temp, ptr);
		free(**rest);
		**rest = ft_substr(*buffer, ft_indexNewLine(*buffer) + 1, *nbyte);
		free(temp);
		free(ptr);
	}
	else
	{
		temp = **rest;
		**rest = ft_strjoin(temp, *buffer);
		free(temp);
	}
	return (str);
}

static char	*ft_buffering(int fd, char **rest)
{
	int		nbyte;
	char	*buffer;
	char	*str;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char ));
	if (!buffer)
		return (NULL);
	nbyte = read(fd, buffer, BUFFER_SIZE);
	if (nbyte <= 0)
	{
		free(buffer);
		free(*rest);
		return (NULL);
	}
	buffer[nbyte] = '\0';
	str = ft_strrest(fd, &buffer, &nbyte, &rest);
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*str;

	if (fd < -1 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_buffering(fd, &rest);
	return (str);
}
