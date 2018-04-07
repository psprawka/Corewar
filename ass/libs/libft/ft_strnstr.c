/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:05:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/14 14:57:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		j;
	int			end;

	end = (int)ft_strlen(haystack) - (int)ft_strlen(needle);
	i = 0;
	j = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (i < n && (int)i <= end && end >= 0)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j])
			j++;
		if (i + j > n)
			return (NULL);
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
