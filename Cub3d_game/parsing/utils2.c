/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:36:44 by aech-chi          #+#    #+#             */
/*   Updated: 2025/05/03 10:37:12 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_d;
	unsigned char	*p_s;
	size_t			i;

	i = 0;
	p_d = (unsigned char *)dest;
	p_s = (unsigned char *)src;
	while (i < n)
	{
		p_d[i] = p_s[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*result;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		return (ft_strdup(""));
	}
	if (len > slen - start)
		len = slen - start;
	result = (char *)malloc(len + 1 * sizeof(char));
	if (!result)
		return (NULL);
	ft_memcpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}
