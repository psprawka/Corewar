/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:15:52 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 16:33:53 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		norm(t_options *opt, int param)
{
	if (opt->width)
	{
		if (opt->minus)
		{
			ft_putchar(param);
			ft_putnchar(' ', opt->width - 1);
		}
		else
		{
			(opt->zero) ? ft_putnchar('0', opt->width - 1) :
			ft_putnchar(' ', opt->width - 1);
			ft_putchar(param);
		}
	}
	else
		ft_putchar(param);
}

int			print_char(va_list *args, t_options *opt)
{
	int		param;

	param = va_arg(*args, int);
	if (opt->zero && !param)
	{
		ft_putnchar('0', opt->width - 1);
		return (opt->width);
	}
	norm(opt, param);
	return (ft_max(1, opt->width));
}

int			print_wchar(va_list *args, t_options *opt)
{
	int		param;

	param = va_arg(*args, int);
	if (opt->width)
	{
		if (opt->minus)
		{
			ft_putwchar(param);
			ft_putnchar(' ', opt->width - 1);
		}
		else
		{
			ft_putnchar(' ', opt->width - 1);
			ft_putwchar(param);
		}
	}
	else
		ft_putwchar(param);
	return (ft_max(1, opt->width));
}
