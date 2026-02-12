/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:34:46 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/12 17:13:11 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_cleantemp(char *temp)
{
	int		i;
	char	*newtemp;:;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	newtemp = malloc(i + 1);
	if (!newtemp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		newtemp[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		newtemp[i] = '\n';
	return (newtemp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	return (result);
}
