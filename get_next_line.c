/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:03:13 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/12 17:13:26 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		bytesread;
	char		*temp;
	char		*buffer;
	static char	*stash;

	buffer = malloc(BUFFER_SIZE +1);
	if (stash)
	{
		temp = (ft_strchr(stash, '\n') + 1);
		stash = NULL;
	}
	else
		temp = "";
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread <= 0 && temp[0] == '\0')
		return (NULL);
	while (bytesread > 0)
	{
		buffer[bytesread] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
		{
			stash = temp;
			return (ft_cleantemp(temp));
		}
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
			return (temp);
	}
	free(buffer);
	return (temp);
}

int	main(void)
{
	int	fd;
	char	*linea;

	fd = open("naufrago.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((linea = get_next_line(fd)) != NULL)
	{
		printf("%s", linea);
		// free(linea);
	}
	
	close(fd);
	return (0);
}
