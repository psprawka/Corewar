/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terence <terence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 06:38:07 by terence           #+#    #+#             */
/*   Updated: 2018/01/21 16:57:42 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			len++;
		else if (*str <= 0x7FF)
			len += 2;
		else if (*str <= 0xFFFF)
			len += 3;
		else if (*str <= 0x10FFFF)
			len += 4;
		str++;
	}
	return (len);
}
