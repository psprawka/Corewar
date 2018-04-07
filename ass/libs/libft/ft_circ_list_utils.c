/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circ_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:41:59 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/02/10 15:59:01 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_circlist		*ft_circlstnew(void *content, long long int content_size)
{
	t_circlist		*list;

	if (!(list = (t_circlist *)ft_memalloc(sizeof(t_circlist))))
		return (NULL);
	if (content)
	{
		ft_memcpy(list->content, content, sizeof(content));
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

void			ft_circlstadd(t_circlist **alst, t_circlist *new)
{
	t_circlist	*previous;

	if (alst && new)
	{
		if (!(*alst))
			*alst = new;
		previous = (*alst)->previous;
		new->next = *alst;
		new->previous = previous;
		previous->next = new;
		(*alst)->previous = new;
		*alst = new;
	}
}

void			ft_circlstdel(t_circlist *node)
{
	t_circlist		*previous;
	t_circlist		*next;

	if (node)
	{
		previous = node->previous;
		next = node->next;
		if (previous)
			previous->next = next;
		if (next)
			next->previous = previous;
		ft_memdel(&(node->content));
		ft_memdel((void **)&(node));
	}
}
