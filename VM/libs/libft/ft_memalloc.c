/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:23:58 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/13 11:17:01 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(sizeof(size_t) * size)))
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	else
		return (NULL);
}
