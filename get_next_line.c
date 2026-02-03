/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:44:11 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/03 14:16:27 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*temp;
	size_t	bytesread;
	
	temp = malloc(BUFFER_SIZE);
	bytesread = read(fd, temp, BUFFER_SIZE);
	return (temp);
}
int	main(void)
{
	int	fd;
	
	fd = open("naufrago.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	
	close(fd);

	return (0);
}