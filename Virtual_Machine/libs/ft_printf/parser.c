/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:12:10 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 16:35:53 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				parse_flags(char **format, t_options **opt)
{
	if (!*format || !opt)
		return (0);
	while (**format == '-' || **format == '+' || **format == '0'
	|| **format == ' ' || **format == '#')
	{
		(*opt)->minus += **format == '-' && !(*opt)->minus ? 1 : 0;
		(*opt)->plus += **format == '+' && !(*opt)->plus ? 1 : 0;
		(*opt)->space += **format == ' ' && !(*opt)->space ? 1 : 0;
		(*opt)->zero += **format == '0' && !(*opt)->zero ? 1 : 0;
		(*opt)->pound += **format == '#' && !(*opt)->pound ? 1 : 0;
		(*format)++;
	}
	return (1);
}

static void		wildcard_trick(char **format, va_list *args, int *width)
{
	*width = ft_isdigit(**format) ? 0 : *width;
	while (ft_isdigit(**format))
	{
		*width = *width * 10 + **format - 48;
		(*format)++;
	}
	if (**format == '*')
	{
		*width = va_arg(*args, int);
		(*format)++;
	}
	*width = ft_isdigit(**format) ? 0 : *width;
	while (ft_isdigit(**format))
	{
		if (!(*width))
			*width = 0;
		*width = *width * 10 + **format - 48;
		(*format)++;
	}
	*width = *width >= 0 ? *width : -(*width);
}

int				parse_width(char **format, t_options **opt, va_list *args)
{
	int		width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(*args, int);
		(*opt)->width = width >= 0 ? width : -width;
		(*opt)->minus += width < 0 && !(*opt)->minus ? 1 : 0;
		(*format)++;
	}
	wildcard_trick(format, args, &width);
	parse_flags(format, opt);
	(*opt)->width = width;
	return (1);
}

int				parse_precision(char **format, t_options **opt, va_list *args)
{
	int		precision;

	if (**format == '.')
	{
		(*opt)->dot = 1;
		precision = 0;
		(*format)++;
		if (**format == '*')
		{
			precision = va_arg(*args, int);
			(*opt)->precision = precision;
			(*format)++;
			return (2);
		}
		while (ft_isdigit(**format))
		{
			precision = precision * 10 + **format - 48;
			(*format)++;
		}
		(*opt)->precision = precision;
		return (1);
	}
	else
		return (-1);
}

int				parse_length(char **format, t_options **opt)
{
	if (ft_strsearch(LENG, **format))
		(*opt)->length = **format;
	else
		return (-1);
	(*format)++;
	if (**format == (*opt)->length)
	{
		(*opt)->length *= 2;
		(*format)++;
	}
	return (1);
}
