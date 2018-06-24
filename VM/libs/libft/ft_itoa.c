/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:14:42 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/22 11:52:40 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(long long int n)
{
	char		*fresh;
	int			i;
	int			len;

	len = int_length(n, 10);
	if ((fresh = ft_strnew(len)))
	{
		i = len - 1;
		fresh[i + 1] = 0;
		if (n < 0)
		{
			fresh[i--] = -(n % 10) + 48;
			fresh[0] = '-';
			n = -(n / 10);
		}
		while (i >= 0 && fresh[i] != '-')
		{
			fresh[i--] = n % 10 + 48;
			n /= 10;
		}
		return (fresh);
	}
	else
		return (NULL);
}

char			*ft_unsigned_itoa(unsigned long long int n)
{
	char		*fresh;
	int			i;
	int			len;

	len = uns_int_length(n, 10);
	if ((fresh = ft_strnew(len)))
	{
		i = len - 1;
		fresh[i + 1] = 0;
		while (i >= 0 && fresh[i] != '-')
		{
			fresh[i--] = n % 10 + 48;
			n /= 10;
		}
		return (fresh);
	}
	else
		return (NULL);
}
