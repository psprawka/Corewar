/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:44:14 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 16:43:56 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		prt_width(t_options *opt, int precision)
{
	if (opt->zero && !opt->dot)
	{
		ft_putnchar(' ', opt->space);
		ft_putnchar('0', opt->width - precision - opt->space - opt->pound);
	}
	else
		ft_putnchar(' ', opt->width - precision - opt->space - opt->pound);
}

static	void		print_nbr(char *str, int precision, int sharp)
{
	if (sharp && str[0] != '0')
		ft_putstr("0");
	ft_putnstr(str, precision);
}

static void			handle_minux(t_options *opt,
		int precision, int len, char *str)
{
	opt->zero = 0;
	ft_putnchar(' ', opt->space);
	(precision - len > 0) ? ft_putnchar('0', precision - len)
		: ft_putnchar('0', 0);
	print_nbr(str, precision, opt->pound);
	if (opt->width > precision)
		ft_putnchar(' ', opt->width - precision - opt->space - opt->pound);
}

static void			handle(t_options *opt,
		int precision, int len, char *str)
{
	if (opt->width > precision)
		prt_width(opt, precision);
	(precision - len > 0) ? ft_putnchar('0', precision - len)
		: ft_putnchar('0', 0);
	print_nbr(str, precision, opt->pound);
}

int					print_oct(va_list *args, t_options *opt)
{
	char	*str;
	int		len;
	int		precision;
	int		leak;

	str = ft_unsigned_itoa_base(uns_castor(args, opt->length), 8);
	len = ft_strlen(str);
	if (opt->precision >= len)
		opt->pound = 0;
	if ((leak = str[0] == '0') && !opt->precision && opt->dot && !opt->pound)
	{
		ft_putnchar(' ', opt->width);
		return (opt->width);
	}
	opt->zero *= !opt->minus;
	precision = opt->precision ? ft_max(opt->precision, len) : len;
	if (opt->minus)
		handle_minux(opt, precision, len, str);
	else
		handle(opt, precision, len, str);
	ft_memdel((void **)&str);
	return (ft_max(opt->width, precision) +
	opt->pound * !leak * (opt->width <= len));
}
