/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:54:06 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 01:15:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		prt_width(char *str, t_options *opt, int precision)
{
	if (opt->zero && !opt->dot)
	{
		ft_putnchar(' ', opt->space);
		if (opt->pound && str[0] != '0')
			ft_putstr("0x");
		ft_putnchar('0', opt->width - precision - opt->space - 2 * opt->pound);
		opt->pound = 0;
	}
	else
	{
		ft_putnchar(' ', opt->width - precision - opt->space - 2 * opt->pound);
		if (opt->pound && str[0] != '0')
		{
			ft_putstr("0x");
			opt->pound = 0;
		}
	}
}

static void			handle(t_options *opt, int precision, char *str)
{
	if (opt->width > precision)
		prt_width(str, opt, precision);
	ft_putnstr("0x", 2 * opt->pound);
	ft_putnchar('0', precision - ft_strlen(str));
	ft_putnstr(str, precision);
}

static void			handle_min(t_options *opt, int precision, char *str)
{
	if (opt->minus)
	{
		opt->zero = 0;
		ft_putnchar(' ', opt->space);
		if (opt->pound && str[0] != '0')
			ft_putstr("0x");
		ft_putnstr(str, precision);
		if (opt->width > precision)
			ft_putnchar(' ', opt->width - precision - opt->space - 2 *
			opt->pound);
	}
	else
		handle(opt, precision, str);
}

static void			moche(t_options **opt, int *len, int *precision, char *str)
{
	(*opt)->zero *= !(*opt)->minus;
	*len = ft_strlen(str);
	*precision = (*opt)->precision ? ft_max((*opt)->precision, *len) : *len;
}

int					print_hex(va_list *args, t_options *opt)
{
	char	*str;
	int		len;
	int		precision;
	int		leak;

	str = ft_unsigned_itoa_base(uns_castor(args, opt->length), 16);
	leak = str[0] == '0';
	if (str[0] == '0' && !opt->precision && opt->dot)
	{
		ft_putnchar(' ', opt->width);
		return (opt->width);
	}
	else if (str[0] == '0')
	{
		ft_putchar('0');
		return (1);
	}
	moche(&opt, &len, &precision, str);
	handle_min(opt, precision, str);
	ft_memdel((void **)&str);
	return (ft_max(opt->width, precision) + 2 * opt->pound * !leak *
			!(opt->width > (len + 2)));
}
