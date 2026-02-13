/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:15:08 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/13 19:40:01 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytesread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(stash, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_cleanstash(stash);
	stash = ft_makestash(stash);
	return (line);
}

/* int	main(void)
{
	int	fd;
	char	*linea;

	fd = open("texto.txt", O_RDONLY);
	// fd[1] = open("texto2.txt", O_RDONLY);
	// fd[2] = open("texto1.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((linea = get_next_line(fd)))
	{
		printf("%s", linea);
		free(linea);
	}
	// linea = get_next_line(fd);
	// printf("%s", linea);
	close(fd);
	return (0);
} */
