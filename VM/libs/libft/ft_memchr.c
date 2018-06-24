/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:55:49 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/09 20:27:46 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n && temp[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	if (temp[i] == (unsigned char)c)
		return (temp + i);
	else
		return (NULL);
}
