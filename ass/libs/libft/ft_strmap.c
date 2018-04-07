/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:53:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/10/24 13:10:51 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*cpy;

	i = 0;
	if (s && f && (cpy = ft_strdup(s)))
	{
		while (s[i])
		{
			cpy[i] = f(s[i]);
			i++;
		}
		return (cpy);
	}
	else
		return (NULL);
}
