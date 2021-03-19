/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:39:42 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/12 11:52:23 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_slen(const char *str);
char	*ft_schr(const char *s, int c);
char	*ft_sjoin(char const *s1, char const *s2);
char	*ft_sdup(const char *s);
int		del_str(char **str, int ret);
char	*loop_buf(int fd, int *ret, char *tmp);
char	*get_line(char *tmp);
char	*get_tmp(char *tmp);
int		get_next_line(int fd, char **line);

#endif
