/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 13:22:06 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/25 14:48:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		uns_castor(va_list *ap, int length)
{
	long long	n;

	if (length == 2 * 'h')
		n = (unsigned char)va_arg(*ap, int);
	else if (length == 'h')
		n = (unsigned short)va_arg(*ap, int);
	else if (length == 'l')
		n = (unsigned long)va_arg(*ap, long);
	else if (length == 2 * 'l')
		n = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (length == 'j')
		n = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (length == 'z')
		n = (size_t)va_arg(*ap, size_t);
	else
		n = (unsigned long int)va_arg(*ap, unsigned int);
	return (n);
}

long long				castor(va_list *ap, int length)
{
	long long n;

	if (length == 2 * 'h')
		n = (signed char)va_arg(*ap, int);
	else if (length == 'h')
		n = (short)va_arg(*ap, int);
	else if (length == 'l')
		n = va_arg(*ap, long);
	else if (length == 2 * 'l')
		n = va_arg(*ap, long long);
	else if (length == 'j')
		n = (intmax_t)va_arg(*ap, uintmax_t);
	else if (length == 'z')
		n = (ssize_t)va_arg(*ap, ssize_t);
	else
		n = (int)va_arg(*ap, int);
	return (n);
}
