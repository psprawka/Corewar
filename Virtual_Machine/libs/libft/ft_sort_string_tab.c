/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:32:50 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/02/05 11:35:28 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_string_tab(char **tab, int length)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (tab && length)
	{
		while (i < length - 1)
		{
			j = 0;
			while (j < length - 1)
			{
				if (ft_strcmp(tab[j + 1], tab[j]) < 0)
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
