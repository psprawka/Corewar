/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:59:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/28 16:36:30 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlength(t_list *list)
{
	int length;

	length = 0;
	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}
