/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:07:53 by terence           #+#    #+#             */
/*   Updated: 2018/01/25 00:57:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_l(char *format, va_list *args, t_options *opt)
{
	if (*format == 'c')
		return (print_wchar(args, opt));
	if (*format == 's')
		return (print_wstring(args, opt));
	return (apply_fun(format, args, opt));
}
