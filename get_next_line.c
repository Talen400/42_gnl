/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:31:12 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/05 21:02:22 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_buffering(int fd, ssize_t *nbyte)
{
	char	*buffer;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char ));
	if (buffer == NULL)
		return (NULL);
	*nbyte = read(fd, buffer, BUFFER_SIZE);
	if (*nbyte <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*nbyte] = '\0';
	return (buffer);
}

static int	ft_line(char *buffer, char **str)
{
	int	len;
	int	i;

	len = 0;
	while (buffer[len] != '\n' && buffer[len])
		len++;
	*str = malloc ((len + 1) * sizeof(char ));
	if (!(*str))
		return (0);
	i = 0;
	while (i < len)
	{
		(*str)[i] = buffer[i];
		i++;
	}
	(*str)[i] = '\0';
	return (len);
}

static char	*ft_buffer_rest(char **buffer, int *len, ssize_t *nbyte)
{
	int		i;
	char	*temp;
	char	*new_buffer;

	temp = *buffer;
	new_buffer = malloc (((*nbyte) - (*len)) * sizeof(char ));
	if (new_buffer == NULL)
	{
		free(temp);
		return (NULL);
	}
	i = 0;
	while (i < (*nbyte) - (*len) - 1)
	{
		new_buffer[i] = temp[(*len) + 1 + i];
		i++;
	}
	free(temp);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		nbyte;
	char		*str;
	int			len;

	nbyte = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_buffering(fd, &nbyte);
	str = NULL;
	len = ft_line(buffer, &str);
	if (len == 0)
		return (NULL);
	if (buffer[len] == '\n')
	{
		buffer = ft_buffer_rest(&buffer, &len, &nbyte);
		if (!buffer)
			return (NULL);
	}
	else
	{
		free(buffer);
		buffer = NULL;
	}
	return (str);
}
