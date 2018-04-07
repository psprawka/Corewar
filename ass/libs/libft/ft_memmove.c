/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:45:45 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/09 19:38:44 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cpy1;
	char	*cpy2;

	cpy1 = (char *)dest;
	cpy2 = (char *)src;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		cpy1[n] = cpy2[n];
	return (dest);
}
