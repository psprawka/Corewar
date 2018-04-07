/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:43:09 by terence           #+#    #+#             */
/*   Updated: 2018/01/23 16:33:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_z(char *format, va_list *args, t_options *opt)
{
	if (ft_strsearch("di", *format))
		return (print_integer(args, opt));
	else if (ft_strsearch("ouxX", *format))
		return (apply_fun(format, args, opt));
	else
		return (-7);
}
