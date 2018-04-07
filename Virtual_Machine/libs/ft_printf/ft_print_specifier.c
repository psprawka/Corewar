/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:12:10 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 16:26:57 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		no_opt(t_options *opt)
{
	return (!opt->minus && !opt->plus && !opt->space && !opt->zero &&
		!opt->pound && !opt->width && !opt->precision &&
		!opt->dot && !opt->length);
}

static int		norm(char **format, t_options *opt)
{
	if (!(**format) || (no_opt(opt) && **format != '%'))
		return (0);
	if (!ft_strsearch("+-. #dDioOxX", **format))
	{
		ft_putnchar(**format, opt->minus);
		ft_putnchar(' ', opt->width - 1);
		ft_putnchar(**format, !opt->minus);
	}
	(*format)++;
	return (ft_max(1, opt->width));
}

int				ft_print_specifier(char **format, va_list *args, t_options *opt)
{
	int		len;

	len = 0;
	while (ft_strsearch(LENG, **format))
		(*format)++;
	if (**format == 'O')
		opt->length = 'l' * 2;
	if (opt->length)
	{
		if ((len = handle_fun(*format, args, opt)) == -1)
		{
			ft_memdel((void **)&opt);
			return (-1);
		}
	}
	else if ((len = apply_fun(*format, args, opt)) == -1)
	{
		ft_memdel((void **)&opt);
		return (-1);
	}
	if (len != -7)
		(*format)++;
	return (len == -7 ? norm(format, opt) : len);
}
