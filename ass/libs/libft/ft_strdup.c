/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 19:08:01 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/14 15:25:24 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(cpy, s));
}
