/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:00:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/13 11:32:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	while (needle[i] && haystack[i] == needle[i])
		i++;
	if (!needle[i])
		return ((char *)haystack);
	else if (haystack[i])
		return (ft_strstr(haystack + 1, needle));
	else
		return (NULL);
}
