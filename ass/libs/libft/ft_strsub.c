/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:18:20 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/13 12:54:42 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || ((start + len) > ft_strlen(s)) ||
			!(sub = ft_strnew(len)))
		return (NULL);
	sub = ft_strncpy(sub, s + start, len);
	return (sub);
}
