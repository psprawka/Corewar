/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:59:46 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/06 20:03:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		index;
	size_t		j;

	index = 0;
	j = 0;
	while (s1[index])
		index++;
	while (s2[j] && j < n)
	{
		s1[index] = s2[j];
		index++;
		j++;
	}
	s1[index] = '\0';
	return (s1);
}
