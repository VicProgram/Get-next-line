/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabad-ro <vabad-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:48:19 by vabad-ro          #+#    #+#             */
/*   Updated: 2026/02/16 16:58:00 by vabad-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef FD_LIMIT
#  define FD_LIMIT 1024
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_bonus(const char *s);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*ft_strchr_bonus(const char *s, int c);
char	*ft_cleanstash_bonus(char *stash);
char	*ft_makestash_bonus(char *stash);
char	*get_next_line(int fd);

#endif