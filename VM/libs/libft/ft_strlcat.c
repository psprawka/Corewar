/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:34:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/13 12:36:26 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		index;
	size_t		reader;
	size_t		len;

	index = 0;
	reader = 0;
	if (!size)
		return (ft_strlen(src));
	while (dest[index] && index < size)
		index++;
	while (index < size - 1 && src[reader])
	{
		dest[index] = src[reader];
		index++;
		reader++;
	}
	if (reader)
	{
		dest[index] = '\0';
		return (index + ft_strlen(src) - reader);
	}
	len = index + ft_strlen(src);
	return (len);
}
