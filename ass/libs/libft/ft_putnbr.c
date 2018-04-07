/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:35:09 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/19 16:55:54 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int n)
{
	ft_putstr(ft_itoa_base(n, 10));
}

void	ft_putnbr_uns(unsigned long long int n)
{
	ft_putstr(ft_unsigned_itoa_base(n, 10));
}

void	ft_putnbr_base(long long int n, int base)
{
	ft_putstr(ft_itoa_base(n, base));
}

void	ft_uns_putnbr_base(unsigned long long int n, int base)
{
	ft_putstr(ft_unsigned_itoa_base(n, base));
}
