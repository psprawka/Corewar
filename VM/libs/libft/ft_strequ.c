/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:11:05 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/09 17:19:06 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (*s1 == 0 && *s2 == 0)
			return (1);
		return (ft_strcmp(s1, s2) == 0);
	}
	else if ((!s1 && s2) || (s1 && !s2))
		return (0);
	else if (!s1 && !s2)
		return (1);
	else
		return (1);
}
