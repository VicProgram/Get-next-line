/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:44:11 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/04 18:12:37 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*temp;
	ssize_t		byread;
	static char	*nextl;

	nextl = "";
	temp = malloc(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	byread = read(fd, temp, BUFFER_SIZE);
	// strchr
	nextl = ft_strlcpy(nextl, temp, BUFFER_SIZE);
	printf("%s", nextl);
	free(temp);
	return (nextl);
}
int	main(void)
{
	int	fd;
	int	i;

	i = 4;
	fd = open("naufrago.txt", O_RDONLY);
	printf("------------------MAIN------\n");
	while (i > 0)
	{
		printf("%s\n", get_next_line(fd));
		i--;
	}
	printf("------------------MAIN------\n");
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
