/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:40:47 by terence           #+#    #+#             */
/*   Updated: 2018/01/25 15:25:08 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_h(char *format, va_list *args, t_options *opt)
{
	if (*format == 'i' || *format == 'd')
		return (print_integer(args, opt));
	else if (ft_strsearch("uoxX", *format))
		return (apply_fun(format, args, opt));
	else if (*format == 'O' || *format == 'D' || *format == 'U')
	{
		if (opt->length == 'h' * 2)
			opt->length /= 2;
		return (apply_fun(format, args, opt));
	}
	else if (*format == 'C')
		return (-1);
	else
		return (-7);
}
