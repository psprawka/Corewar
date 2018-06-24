/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:42:19 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/10/24 17:48:37 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*queue;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	head = ft_lstnew(temp->content, temp->content_size);
	queue = ft_lstmap(lst->next, f);
	head->next = queue;
	return (head);
}
