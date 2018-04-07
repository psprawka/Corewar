/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:24:45 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/18 17:38:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_length(long long int n, int base)
{
	int		len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

int		uns_int_length(unsigned long long int n, int base)
{
	int		len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
