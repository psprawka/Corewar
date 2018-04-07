/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:25:20 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/14 16:30:22 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int length)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	if (tab && length)
	{
		while (i < length - 1)
		{
			j = 0;
			while (j < length - 1)
			{
				if (tab[j + 1] < tab[j])
				{
					tmp = tab[j];
					tab[j] = tab[j + 1];
					tab[j + 1] = tmp;
				}
				j++;
			}
			i++;
		}
	}
}
