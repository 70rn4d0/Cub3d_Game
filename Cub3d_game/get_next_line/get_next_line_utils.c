/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:23:03 by aech-chi          #+#    #+#             */
/*   Updated: 2025/05/03 10:35:15 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!line)
		line = ft_strnew(0);
	if (!line || !buff)
		return (NULL);
	i = -1;
	j = -1;
	size = ft_strlen(line) + ft_strlen(buff);
	str = ft_strnew(size);
	if (!str)
	{
		free (line);
		return (NULL);
	}
	while (line[++i])
		str[i] = line[i];
	while (buff[++j])
		str[i++] = buff[j];
	free (line);
	return (str);
}

char	*ft_strsub(char const *line, unsigned int start, size_t len, int flag)
{
	char	*sub;
	size_t	i;
	size_t	size;

	if (!line)
		return (NULL);
	i = 0;
	size = ft_strlen(line);
	if (size == 0)
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	while (i < len && start < size)
		sub[i++] = line[start++];
	if (flag == 1)
		free((char *)line);
	return (sub);
}

char	*ft_strchr(const char *line, int c)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == (char)c)
			return ((char *)line + i);
		if (line[i + 1] == (char)c)
			return ((char *)line + i + 1);
		i++;
	}
	return (0);
}
