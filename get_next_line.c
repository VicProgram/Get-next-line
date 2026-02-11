/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:03:13 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/11 17:42:58 by vabad-ro         ###   ########.fr       */
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
		stash = "NULL";
	}
	else
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		temp = "NULL";
	}
	bytesread = read(fd, buffer, BUFFER_SIZE);
	buffer[bytesread] =  '\0';
	if (bytesread <= 0)
		return (NULL);
	while (bytesread > 0)
	{
		temp = ft_strjoin(temp, buffer);
		if (ft_strchr(temp, '\n'))
		{
			stash = temp;
			return (ft_cleantemp(temp));
		}
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}

int	main(void)
{
	int	fd;
	char	*linea;

	fd = open("naufrago.txt", O_RDONLY);
	if (fd == -1)
	 	return (1);
	linea = get_next_line(fd);
	while (linea)
	{
		printf("%s", linea);
		free(linea);
		linea = get_next_line(fd);
	}
	free  (linea);
 /* 	linea = get_next_line(fd);
	printf("%s\n", linea); */
	
	close(fd);
	return (0);
}
