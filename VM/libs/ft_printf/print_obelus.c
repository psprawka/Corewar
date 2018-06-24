/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obelus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:21:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/22 10:36:55 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		prt_width(t_options *opt)
{
	if (opt->zero)
		ft_putnchar('0', ft_max(1, opt->width) - 1);
	else
		ft_putnchar(' ', ft_max(1, opt->width) - 1);
}

int				print_obelus(va_list *args, t_options *opt)
{
	if (args)
		ft_putnchar(' ', 0);
	if (opt->minus)
	{
		ft_putnchar('%', 1);
		ft_putnchar(' ', ft_max(1, opt->width) - 1);
	}
	else
	{
		prt_width(opt);
		ft_putnchar('%', 1);
	}
	return (ft_max(1, opt->width));
}
