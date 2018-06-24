/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:06:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/06 20:01:50 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*copy;

	if (n == 0)
		return (s);
	i = 0;
	copy = (unsigned char *)s;
	while (i < n)
	{
		copy[i] = c;
		i++;
	}
	return (s);
}
