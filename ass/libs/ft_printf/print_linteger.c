/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_linteger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:59:56 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/23 15:38:36 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		prt_width(char *str, t_options *opt, int precision)
{
	int sign;

	sign = str[0] == '-';
	if (opt->zero && !opt->dot)
	{
		ft_putnchar('-', str[0] == '-');
		ft_putnchar(' ', opt->space);
		ft_putnchar('+', opt->plus);
		ft_putnchar('0', opt->width - precision - opt->plus
				- opt->space - sign);
	}
	else
	{
		ft_putnchar(' ', opt->width - precision - opt->plus
				- opt->space - sign);
		ft_putnchar('+', opt->plus);
		ft_putnchar('-', str[0] == '-');
	}
}

static	void		ignore(char *str, t_options *opt)
{
	int		sign;

	sign = str[0] == '-';
	opt->plus *= !sign;
	opt->zero *= !opt->minus;
	opt->space *= !opt->plus * !sign;
}

static void			handle_minux(t_options *opt,
		int precision, int len, char *str)
{
	ft_putnchar('+', opt->plus && ft_isdigit(str[0]));
	ft_putnchar(' ', opt->space);
	ft_putnchar('-', str[0] == '-');
	(precision - len > 0) ? ft_putnchar('0', precision - len) :
		ft_putnchar('0', 0);
	ft_putnstr(str + (str[0] == '-'), precision);
	if (opt->width > precision)
		ft_putnchar(' ', opt->width - precision - opt->plus -
				opt->space - (str[0] == '-'));
}

static void			handle(t_options *opt,
		int precision, int len, char *str)
{
	if (opt->width > precision)
		prt_width(str, opt, precision);
	else
		ft_putnchar('-', str[0] == '-');
	(precision - len > 0) ? ft_putnchar('0', precision - len)
		: ft_putnchar('0', 0);
	ft_putnstr(str + (str[0] == '-'), precision);
}

int					print_linteger(va_list *args, t_options *opt)
{
	char	*str;
	int		len;
	int		precision;
	int		leak;

	str = ft_itoa(va_arg(*args, long int));
	leak = str[0] == '-';
	if (str[0] == '0' && !opt->precision && opt->dot)
		return (0);
	ignore(str, opt);
	len = ft_strlen(str) - (str[0] == '-');
	precision = opt->precision ? ft_max(opt->precision, len) : len;
	if (opt->minus)
	{
		opt->zero = 0;
		handle_minux(opt, precision, len, str);
	}
	else
		handle(opt, precision, len, str);
	return (ft_max(opt->width, precision) + leak);
}
