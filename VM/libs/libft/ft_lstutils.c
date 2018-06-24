/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 10:11:04 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/05 23:47:14 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_lstmaxsize(t_list *list)
{
	long long int max;

	max = list ? list->content_size : INT_MIN;
	while (list)
	{
		max = ft_max(max, list->content_size);
		list = list->next;
	}
	return (max);
}

long long int		ft_lstminsize(t_list *list)
{
	long long int min;

	min = list ? list->content_size : INT_MAX;
	while (list)
	{
		min = ft_min(min, list->content_size);
		list = list->next;
	}
	return (min);
}

t_list				*ft_lst_pop(t_list **list)
{
	t_list		*tmp;

	tmp = NULL;
	if (*list)
	{
		tmp = *list;
		(*list) = (*list)->next;
		tmp->next = NULL;
	}
	return (tmp);
}

int					ft_lst_is_sorted(t_list *stack)
{
	if (!stack || !(stack->next))
		return (1);
	return (stack->content_size <= stack->next->content_size
		&& ft_lst_is_sorted(stack->next));
}
