/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:36:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/14 15:04:36 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned	char		*s1;
	unsigned	char		*s2;
	size_t					index;

	if (!n)
		return (NULL);
	index = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	while (index < n)
	{
		s1[index] = s2[index];
		if (s1[index] == (unsigned char)c)
			return (s1 + index + 1);
		index++;
	}
	return (NULL);
}
