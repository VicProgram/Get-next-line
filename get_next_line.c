/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:44:11 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/05 17:42:39 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	ssize_t		byread;
	static char	*nextl;

	nextl = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	byread = read(fd, temp, BUFFER_SIZE);
	if (byread == 0)
	{
		free(nextl);
		return (NULL);
	}
	while (byread > 0)
	{
		nextl = ft_strjoin(nextl, temp);
		if (ft_strchr(nextl, '\n'))
			break;
		byread = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	return (nextl);
}
int	main(void)
{
	int	fd;
	char	*line;

	fd = open("naufrago.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	
	while ((line = get_next_line(fd)))
		printf("%s\n", line);
	close(fd);
	return (0);
}
