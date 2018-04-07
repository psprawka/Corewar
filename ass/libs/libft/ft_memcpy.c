/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:32:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/09 19:21:26 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	if (n == 0 || dest == src)
		return (dest);
	s1 = (char *)dest;
	s2 = (char *)src;
	while (--n)
	{
		if (*s1 != *s2)
			*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = *s2;
	return (dest);
}
