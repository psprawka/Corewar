/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:55:46 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/02/10 18:29:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_abs(long long int n)
{
	return (n >= 0 ? n : -n);
}

char					*ft_itoa_base(long long int n, int base)
{
	char	*str;
	int		i;
	int		len;
	char	*hex;

	hex = ft_strdup("0123456789abcdef");
	if (base != 10 && n < 0)
		return (NULL);
	len = int_length(n, base);
	str = (char *)ft_memalloc(len + 1);
	str[len] = '\0';
	i = len - 1;
	if (n < 0)
		str[0] = '-';
	while (str[i] != '-' && i >= 0)
	{
		str[i] = hex[ft_abs(n % base)];
		n /= base;
		i--;
	}
	free(hex);
	return (str);
}

char					*ft_unsigned_itoa_base(unsigned long long int n,
		int base)
{
	char		*str;
	int			i;
	int			len;
	char		*hex;

	hex = ft_strdup("0123456789abcdef");
	len = uns_int_length(n, base);
	str = (char *)ft_memalloc(len + 1);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i] = hex[n % base];
		n /= base;
		i--;
	}
	free(hex);
	return (str);
}

char					*ft_itoa_base_m(long long int n, int base)
{
	char	*str;
	int		i;
	int		len;
	char	*hex;

	hex = ft_strdup("0123456789ABCDEF");
	if (base != 10 && n < 0)
		return (NULL);
	len = int_length(n, base);
	str = (char *)ft_memalloc(len + 1);
	str[len] = '\0';
	i = len - 1;
	if (n < 0)
		str[0] = '-';
	while (str[i] != '-' && i >= 0)
	{
		str[i] = hex[ft_abs(n % base)];
		n /= base;
		i--;
	}
	free(hex);
	return (str);
}

char					*ft_unsigned_itoa_base_m(unsigned long long int n,
		int base)
{
	char		*str;
	int			i;
	int			len;
	char		*hex;

	hex = ft_strdup("0123456789ABCDEF");
	len = uns_int_length(n, base);
	str = (char *)ft_memalloc(len + 1);
	str[len] = '\0';
	i = len - 1;
	while (i >= 0)
	{
		str[i] = hex[n % base];
		n /= base;
		i--;
	}
	free(hex);
	return (str);
}
