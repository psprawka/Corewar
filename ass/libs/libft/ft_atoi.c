/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:14:41 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/26 15:48:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi(const char *nptr)
{
	int					i;
	long long int		res;

	i = 0;
	res = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	i += (nptr[i] == '+' || nptr[i] == '-') ? 1 : 0;
	while (nptr[i] <= '9' && nptr[i] >= '0')
		res = res * 10 + nptr[i++] - 48;
	return (res);
}
