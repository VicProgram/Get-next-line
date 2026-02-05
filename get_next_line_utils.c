/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:34:37 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/05 17:39:55 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
char	*ft_strchr(const char *s, int c)
{
	char	*s_new;

	s_new = (char *)s;
	if ((unsigned char)c == '\0')
	{
		while (*s_new)
			s_new++;
		return (s_new);
	}
	while (*s_new)
	{
		if (*s_new == (unsigned char)c)
			return (s_new);
		s_new++;
	}
	return (NULL);
}
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
