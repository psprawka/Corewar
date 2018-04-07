/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 06:40:12 by terence           #+#    #+#             */
/*   Updated: 2018/01/25 16:43:50 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_wchar(wchar_t c)
{
	if ((MB_CUR_MAX == 1 && c > 127) || (MB_CUR_MAX == 2 && c > 0x7FF)
	|| (MB_CUR_MAX == 3 && c > 0xFFFF) || (MB_CUR_MAX == 4 && c > 0x1FFFFF) ||
			c > 0x10FFF)
		return (0);
	return (1);
}

int				valide(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_wchar(str[i]))
			return (-1);
		i++;
	}
	return (1);
}

static void		norm(wchar_t *str, t_options *opt, int precision)
{
	if (opt->minus)
	{
		ft_putnwstr(str, precision);
		if (opt->width > precision)
			ft_putnchar(' ', opt->width - precision);
	}
	else
	{
		if (opt->width > precision)
		{
			ft_putnchar('0', opt->zero * (opt->width - precision));
			ft_putnchar(' ', !opt->zero * (opt->width - precision));
		}
		ft_putnwstr(str, precision * !opt->zero);
	}
}

int				print_wstring(va_list *args, t_options *opt)
{
	wchar_t		*str;
	int			precision;

	str = va_arg(*args, wchar_t *);
	if (!str)
	{
		ft_putstr(NULL);
		return (6);
	}
	if (!opt->precision && valide(str) == -1)
		return (opt->precision ? opt->precision : -1);
	precision = !opt->precision && !opt->dot ? (int)ft_wstrlen(str)
	: ft_min(opt->precision, (int)ft_wstrlen(str));
	norm(str, opt, precision);
	return (!opt->precision && !opt->dot ? ft_wstrlen(str) :
	ft_max(opt->width, opt->precision));
}
