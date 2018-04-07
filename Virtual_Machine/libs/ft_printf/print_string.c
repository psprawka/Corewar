/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:12:00 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 14:20:48 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		norm(t_options *opt, char *str, int precision)
{
	if (opt->minus)
	{
		ft_putnstr(str, precision);
		if (opt->width > precision)
			ft_putnchar(' ', opt->width - precision);
	}
	else
	{
		if (opt->width > precision)
		{
			(opt->zero) ? ft_putnchar('0', opt->width - precision) :
				ft_putnchar(' ', opt->width - precision);
		}
		ft_putnstr(str, precision);
	}
}

int				print_string(va_list *args, t_options *opt)
{
	char	*str;
	int		precision;
	int		leak;

	str = va_arg(*args, char *);
	if (opt->dot && !opt->precision)
	{
		ft_putnchar(' ', opt->width);
		return (opt->width);
	}
	if ((leak = str == NULL))
	{
		ft_putstr(str);
		return (6);
	}
	if (opt->dot && !opt->precision)
		return (0);
	opt->precision *= opt->precision < 0 ? 0 : 1;
	precision = opt->precision ? ft_min(opt->precision,
			(int)ft_strlen(str)) : (int)ft_strlen(str);
	norm(opt, str, precision);
	return (ft_max(opt->width, precision) + 6 * leak);
}
