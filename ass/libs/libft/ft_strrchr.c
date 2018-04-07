/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:54:39 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/10/23 20:59:09 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cpy;
	int		last;

	i = 0;
	last = -1;
	cpy = (char *)s;
	while (cpy[i])
	{
		if (cpy[i] == c)
			last = i;
		i++;
	}
	if (cpy[i] == c)
		return (cpy + i);
	if (last >= 0)
		return (cpy + last);
	else
		return (NULL);
}
