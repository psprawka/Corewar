/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 06:43:05 by terence           #+#    #+#             */
/*   Updated: 2018/01/25 16:46:08 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 127)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0b00111111) + 0b10000000);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar((c >> 6 & 0x3F) + 0xC0);
		ft_putchar((c & 0b00111111) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

void	ft_putnwstr(wchar_t *str, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && i < len)
	{
		if (str[j] <= 0x7F)
			i++;
		else if (str[j] <= 0x7FF)
			i += 2;
		else if (str[j] <= 0xFFFF)
			i += 3;
		else if (str[j] <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(str[j++]);
	}
}
