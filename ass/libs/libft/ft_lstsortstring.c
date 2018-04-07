/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:42:51 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/02/12 12:07:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		split(t_list *source, t_list **a, t_list **b)
{
	t_list *left;
	t_list *right;

	if (!source || !source->next)
	{
		*a = source;
		*b = NULL;
	}
	else
	{
		left = source;
		right = source->next;
		while (right)
		{
			right = right->next;
			if (right)
			{
				right = right->next;
				left = left->next;
			}
		}
		*a = source;
		*b = left->next;
		left->next = NULL;
	}
}

static t_list	*fusion(t_list *a, t_list *b, long int
	(*f)(char *, char *))
{
	t_list *list;

	list = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (f(a->content, b->content) <= 0)
	{
		list = a;
		list->next = fusion(a->next, b, f);
	}
	else
	{
		list = b;
		list->next = fusion(a, b->next, f);
	}
	return (list);
}

static t_list	*fusion_r(t_list *a, t_list *b, long int
	(*f)(char *, char *))
{
	t_list *list;

	list = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (f(a->content, b->content) > 0)
	{
		list = a;
		list->next = fusion_r(a->next, b, f);
	}
	else
	{
		list = b;
		list->next = fusion_r(a, b->next, f);
	}
	return (list);
}

void			ft_lst_merge_sort(t_list **list, long int
	(*f)(char *, char *))
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *list;
	if (head && head->next)
	{
		split(head, &a, &b);
		ft_lst_merge_sort(&a, f);
		ft_lst_merge_sort(&b, f);
		*list = fusion(a, b, f);
	}
}

void			ft_lst_merge_sort_r(t_list **list, long int
	(*f)(char *, char *))
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *list;
	if (head && head->next)
	{
		split(head, &a, &b);
		ft_lst_merge_sort_r(&a, f);
		ft_lst_merge_sort_r(&b, f);
		*list = fusion_r(a, b, f);
	}
}
