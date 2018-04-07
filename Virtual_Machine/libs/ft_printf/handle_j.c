/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_j.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 21:29:04 by terence           #+#    #+#             */
/*   Updated: 2018/01/25 15:20:07 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_j(char *format, va_list *args, t_options *opt)
{
	if (ft_strsearch("diouxX", *format))
		return (apply_fun(format, args, opt));
	else if (*format == 'O' || *format == 'D' || *format == 'U')
	{
		return (apply_fun(format, args, opt));
	}
	else
		return (-7);
}
