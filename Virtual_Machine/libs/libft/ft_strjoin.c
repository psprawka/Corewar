/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:25:57 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/13 12:55:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (dest)
	{
		dest = ft_strcat(dest, s1);
		dest = ft_strcat(dest, s2);
	}
	return (dest);
}
