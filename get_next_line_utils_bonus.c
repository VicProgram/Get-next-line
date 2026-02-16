/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:16:37 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/16 16:54:29 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_makestash_bonus(char *stash)
{
	int		i;
	int		j;
	char	*newstash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newstash = malloc(ft_strlen_bonus(stash) - i + 1);
	if (!newstash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		newstash[j++] = stash[i++];
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}

int	ft_strlen_bonus(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_bonus(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_cleanstash_bonus(char *stash)
{
	int		i;
	char	*newstash;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	newstash = malloc(i + 2);
	if (!newstash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		newstash[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		newstash[i++] = '\n';
	newstash[i] = '\0';
	return (newstash);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	result = malloc(ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	return (result);
}
