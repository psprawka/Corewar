/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:33:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 05:05:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *str, int start, size_t len)
{
	char	*new;
	size_t	i;
	
	if (!str || !(new = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len && str[start])
		new[i++] = str[start++];
	return (new);
}

