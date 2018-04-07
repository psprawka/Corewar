/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:00:37 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 00:53:45 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

t_options			*new_options(void)
{
	t_options	*opt;

	opt = (t_options *)malloc(sizeof(t_options));
	opt->minus = 0;
	opt->plus = 0;
	opt->dot = 0;
	opt->space = 0;
	opt->zero = 0;
	opt->pound = 0;
	opt->width = 0;
	opt->precision = 0;
	opt->length = 0;
	return (opt);
}

static t_spec		new_spec(char c, int (*f)(va_list *a, t_options *opt))
{
	t_spec	spec;

	spec.c = c;
	spec.f = f;
	return (spec);
}

int					apply_fun(char *format, va_list *args, t_options *opt)
{
	t_spec		tab[16];
	int			i;

	i = 0;
	tab[0] = new_spec('%', print_obelus);
	tab[1] = new_spec('s', print_string);
	tab[2] = new_spec('S', print_wstring);
	tab[3] = new_spec('p', print_pointer);
	tab[4] = new_spec('d', print_integer);
	tab[5] = new_spec('D', print_linteger);
	tab[6] = new_spec('i', print_integer);
	tab[7] = new_spec('o', print_oct);
	tab[8] = new_spec('O', print_oct);
	tab[9] = new_spec('u', print_unsint);
	tab[10] = new_spec('U', print_bigunsint);
	tab[11] = new_spec('x', print_hex);
	tab[12] = new_spec('X', print_mhex);
	tab[13] = new_spec('c', print_char);
	tab[14] = new_spec('C', print_char);
	tab[15] = new_spec('\0', NULL);
	while (i < 15 && (*format != tab[i].c))
		i++;
	return (i < 15 ? (tab[i].f)(args, opt) : -7);
}

int					handle_fun(char *format, va_list *args, t_options *opt)
{
	char			length;

	length = ft_strsearch("hljz", opt->length) ? (char)opt->length
		: opt->length / 2;
	if (length == 'h')
		return (handle_h(format, args, opt));
	if (length == 'l')
		return (handle_l(format, args, opt));
	if (length == 'j')
		return (handle_j(format, args, opt));
	if (length == 'z')
		return (handle_h(format, args, opt));
	return (-7);
}
