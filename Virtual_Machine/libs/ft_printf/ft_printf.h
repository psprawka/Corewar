/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:15:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/01 15:41:39 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"
# define LENG "hljz"

typedef struct		s_options
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		pound;
	int		width;
	int		precision;
	int		dot;
	int		length;
}					t_options;

typedef struct		s_spec
{
	char	c;
	int		(*f)(va_list *args, t_options *opt);
}					t_spec;

int					ft_print_specifier(char **format, va_list
		*args, t_options *opt);
int					apply_fun(char *format, va_list *args, t_options *opt);
int					handle_fun(char *format, va_list *args, t_options *opt);
unsigned long long	uns_castor(va_list *ap, int length);
long long			castor(va_list *ap, int length);
int					print_char(va_list *args, t_options *opt);
int					print_wchar(va_list *args, t_options *opt);
int					print_obelus(va_list *args, t_options *opt);
int					print_string(va_list *args, t_options *opt);
int					print_wstring(va_list *args, t_options *opt);
int					print_integer(va_list *args, t_options *opt);
int					print_linteger(va_list *args, t_options *opt);
int					print_oct(va_list *args, t_options *opt);
int					print_loct(va_list *args, t_options *opt);
int					print_unsint(va_list *args, t_options *opt);
int					print_bigunsint(va_list *args, t_options *opt);
int					print_lunsint(va_list *args, t_options *opt);
int					print_hex(va_list *args, t_options *opt);
int					print_mhex(va_list *args, t_options *opt);
int					print_pointer(va_list *args, t_options *opt);
int					print_char(va_list *args, t_options *opt);
int					handle_h(char *format, va_list *args, t_options *opt);
int					handle_l(char *format, va_list *args, t_options *opt);
int					handle_j(char *format, va_list *args, t_options *opt);
int					handle_z(char *format, va_list *args, t_options *opt);
t_options			*new_options();
int					parse_flags(char **format, t_options **opt);
int					parse_width(char **format, t_options **opt, va_list *args);
int					parse_precision(char **format, t_options **opt,
						va_list *args);
int					parse_length(char **format, t_options **opt);

#endif
