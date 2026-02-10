/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:03:13 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/10 22:17:35 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t			bytesread;
	char			*temp;
	char			buffer[BUFFER_SIZE + 1];
	static char		*stash;

	
	if (stash)
	{
		temp = (ft_strchr(stash, '\n') +1);
		stash = NULL;
	}
	else
	{
		stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	//bytesread = 1;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread > 0)
	{
		// bytesread = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
		{
			stash = temp;
			return (ft_cleantemp(temp));
		}
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	stash = NULL;
	return (temp);
}

int	main(void)
{
	int	fd;
	char	*linea;

	fd = open("naufrago.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	 while ((linea = get_next_line(fd))!= NULL)
		printf("%s\n", linea);
	close(fd);
	return (0);
}
