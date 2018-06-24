/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:54:37 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 16:43:18 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			prt_width(char *str, int len)
{
	ft_putnchar(' ', len - ft_strlen(str) - 2);
}

static void			norm(char *str, t_options *opt, int leak, int len)
{
	if (opt->minus)
	{
		ft_putstr("0x");
		if (!(!opt->precision && leak && opt->dot))
			ft_putstr(str);
		ft_putnchar('0', opt->precision * (str[0] == '0') - 1);
		ft_putnchar(' ', len - ft_strlen(str) - 2);
	}
	else
	{
		prt_width(str, len);
		ft_putstr("0x");
		ft_putnchar('0', opt->precision - ft_strlen(str));
		if (!(!opt->precision && str[0] == '0' && opt->dot))
			ft_putstr(str);
	}
}

int					print_pointer(va_list *args, t_options *opt)
{
	char	*str;
	int		len;
	int		leak;

	str = ft_unsigned_itoa_base((unsigned long long)va_arg(*args, void *), 16);
	len = ft_max(opt->width, ft_strlen(str) + 2);
	leak = str[0] == '0';
	norm(str, opt, leak, len);
	ft_memdel((void **)&str);
	return (ft_max(len, opt->precision + 2) * !(!opt->precision && leak &&
		opt->dot)) + (2 * (!opt->precision && leak && opt->dot) * opt->dot);
}
