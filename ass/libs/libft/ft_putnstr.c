/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:12:01 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/21 16:10:06 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	size_t len;

	len = 0;
	if (s)
	{
		len = ft_min(ft_strlen(s), n);
		write(1, s, len);
	}
	else
		ft_putstr(s);
}
