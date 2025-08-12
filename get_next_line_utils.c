/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlavared <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:11:36 by tlavared          #+#    #+#             */
/*   Updated: 2025/08/12 19:03:53 by tlavared         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	size_t	i;

	ptr = (char *) s;
	str = malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (ptr[i] != '\0')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = len_s1 + len_s2 + 1;
	str = malloc (len * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		str[i] = s2[i - len_s1];
		i++;
	}
	str[i - 1] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_chr;
	char			*str;

	str = (char *) s;
	c_chr = (unsigned char) c;
	while (*str)
	{
		if ((unsigned char ) *str == c_chr)
			return (str);
		str++;
	}
	if (c_chr == '\0')
		return (str);
	return ((void *) 0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	len_sub;
	unsigned int	len_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	len_sub = len_s - start;
	if (len_sub > len)
		len_sub = len;
	sub = malloc ((len_sub + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
