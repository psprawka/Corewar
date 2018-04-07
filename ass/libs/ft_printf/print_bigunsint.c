/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigunsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:33:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 01:16:41 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		prt_width(t_options *opt, int precision)
{
	if (opt->zero && !opt->dot)
	{
		ft_putnchar(' ', opt->space);
		ft_putnchar('+', opt->plus);
		ft_putnchar('0', opt->width - precision - opt->plus - opt->space);
	}
	else
	{
		ft_putnchar(' ', opt->width - precision - opt->plus - opt->space);
		ft_putnchar('+', opt->plus);
	}
}

static void		ignore(t_options *opt)
{
	opt->zero *= !opt->minus;
	opt->space *= !opt->plus;
}

static void		handle_minus(t_options *opt, int precision, int len, char *str)
{
	ft_putnchar('+', opt->plus && ft_isdigit(str[0]));
	ft_putnchar(' ', opt->space);
	(precision - len > 0) ? ft_putnchar('0', precision - len)
		: ft_putnchar('0', 0);
	ft_putnstr(str, precision);
	if (opt->width > precision)
		ft_putnchar(' ', opt->width - precision - opt->plus - opt->space);
}

static void		handle(t_options *opt, int precision, int len, char *str)
{
	if (opt->width > precision)
		prt_width(opt, precision);
	(precision - len > 0) ? ft_putnchar('0', precision - len)
		: ft_putnchar('0', 0);
	ft_putnstr(str, precision);
}

int				print_bigunsint(va_list *args, t_options *opt)
{
	char	*str;
	int		len;
	int		precision;

	str = ft_unsigned_itoa(va_arg(*args, unsigned long int));
	if (str[0] == '0' && !opt->precision && opt->dot)
	{
		ft_memdel((void **)&str);
		return (0);
	}
	ignore(opt);
	len = ft_strlen(str);
	precision = opt->precision ? ft_max(opt->precision, len) : len;
	if (opt->minus)
	{
		opt->zero = 0;
		handle_minus(opt, precision, len, str);
	}
	else
		handle(opt, precision, len, str);
	ft_memdel((void**)&str);
	return (ft_max(opt->width, precision));
}
