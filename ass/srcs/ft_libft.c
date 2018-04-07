/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 06:19:31 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

char	*ftt_itoa(int nbr)
{
	int		sign;
	int		count;
	char	*str;

	count = 1;
	sign = nbr;
	while (sign /= 10)
		count++;
	sign = nbr < 0 ? 1 : 0;
	count = nbr < 0 ? count += 1 : count;
	if (nbr == -2147483648)
		return (str = ftt_strdup("-2147483648"));
	if (!(str = ftt_strnew(count)))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	nbr = nbr < 0 ? nbr *= -1 : nbr;
	while (--count >= sign)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	str[ftt_strlen(str)] = '\0';
	return (str);
}
