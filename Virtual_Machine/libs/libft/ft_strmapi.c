/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:08:07 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/06 20:03:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	if (s && f && (cpy = ft_strdup(s)))
	{
		while (s[i])
		{
			cpy[i] = f(i, s[i]);
			i++;
		}
		return (cpy);
	}
	else
		return (NULL);
}
