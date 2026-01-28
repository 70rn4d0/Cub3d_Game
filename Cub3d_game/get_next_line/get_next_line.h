/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:54:56 by aech-chi          #+#    #+#             */
/*   Updated: 2025/05/03 13:45:08 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define MAX_FD 1024
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	read_and_append(char **line, int fd);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *line, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strsub(char const *line, unsigned int start, size_t len, int flag);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dest, char *src);
#endif