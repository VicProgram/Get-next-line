/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:15:08 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/16 17:19:15 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_and_stash_bonus(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytesread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr_bonus(stash, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytesread] = '\0';
		stash = ft_strjoin_bonus(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	stash[FD_LIMIT];
	char		*line;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_and_stash_bonus(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_cleanstash_bonus(stash[fd]);
	if (!line || *line == '\0')
	{
		free(line);
		return(NULL);
	}
	stash[fd] = ft_makestash_bonus(stash[fd]);
	return (line);
}

int	main(void)
{
	int	fd, fd2, fd3;
	char	*linea;

	fd = open("texto.txt", O_RDONLY);
	fd2 = open("texto copy.txt", O_RDONLY);
	fd3 = open("texto copy 2.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((linea = get_next_line(fd)))
	{
		printf("%s", linea);
		free(linea);
	}
	while ((linea = get_next_line(fd2)))
	{
		printf("%s", linea);
		free(linea);
	}
	while ((linea = get_next_line(fd3)))
	{
		printf("%s", linea);
		free(linea);
	}
	// linea = get_next_line(fd);
	// printf("%s", linea);
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
/* int	main()
{
	char	*line;
	int	fd;
	
	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return(0);
} */