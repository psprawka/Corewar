/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:35:53 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:17:58 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			my_cmp(t_list *a, t_list *b)
{
	t_process	*pa;
	t_process	*pb;

	pa = ((t_process *)a->content);
	pb = ((t_process *)b->content);
	if (pa->cycles < pb->cycles)
		return (1);
	if (pa->cycles > pb->cycles)
		return (0);
	return (pa->id >= pb->id);
}

void		ft_push_sorted(t_list **list, t_list *newb)
{
	t_list *tmp;
	t_list *previous;

	if (list && newb)
	{
		tmp = *list;
		previous = NULL;
		while (tmp && my_cmp(tmp, newb))
		{
			previous = tmp;
			tmp = tmp->next;
		}
		if (previous)
		{
			previous->next = newb;
			newb->next = tmp;
		}
		else
		{
			*list = newb;
			newb->next = tmp;
		}
	}
}

void		ft_delsup(t_list **list, t_list *bye, t_list *previous)
{
	if (!(*list) || !bye)
		return ;
	if (!previous)
		*list = bye->next;
	else
		previous->next = bye->next;
	if (bye->content)
		free(bye->content);
	bye->content = NULL;
	free(bye);
	bye = NULL;
}
