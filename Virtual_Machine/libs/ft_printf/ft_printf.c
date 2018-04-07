/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:36:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 16:52:47 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			parse(char **format, va_list *args)
{
	t_options		*opt;
	int				len;

	len = 0;
	if (!(**format))
		return (0);
	opt = new_options();
	if (!parse_flags(format, &opt) || !parse_width(format, &opt, args)
	|| !parse_precision(format, &opt, args) || !parse_length(format, &opt))
	{
		ft_memdel((void **)&opt);
		return (-1);
	}
	if ((len = ft_print_specifier(format, args, opt)) == -1)
		return (-1);
	ft_memdel((void **)&opt);
	return (len);
}

static	int			aux(char *format, va_list *args, size_t size, char **modulo)
{
	int				modulo_len;

	*modulo = ft_strchr(format, '%');
	if (!(*format))
		return (size);
	if (!(*modulo))
	{
		ft_putstr(format);
		return (size + ft_strlen(format));
	}
	if (*modulo > format)
	{
		ft_putnstr(format, *modulo - format);
		return (aux(*modulo, args, size + ft_strlen(format) -
		ft_strlen(*modulo), modulo));
	}
	else
	{
		format++;
		if ((modulo_len = parse(&format, args)) == -1)
			return (-1);
		return (aux(format, args, size + modulo_len, modulo));
	}
}

int					ft_printf(const char *format, ...)
{
	va_list		args;
	int			res;
	char		*modulo;

	if (!format)
		return (0);
	va_start(args, format);
	res = aux((char *)format, &args, 0, &modulo);
	va_end(args);
	return (res);
}
