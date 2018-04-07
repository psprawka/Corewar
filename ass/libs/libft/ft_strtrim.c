/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tlehuu@hotmail.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 13:39:43 by tle-huu-          #+#    #+#             */
/*   Updated: 2017/11/14 16:10:46 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_strtrim(char const *s)
{
	int		i;
	int		tab[2];
	char	*result;

	i = 0;
	while (s && s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	tab[0] = i;
	tab[1] = i;
	while (s && s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			tab[1] = i + 1;
		i++;
	}
	if (!s || !(result = (char *)malloc(sizeof(char) * (tab[1] - tab[0] + 1))))
		return (NULL);
	i = 0;
	while (i < tab[1] - tab[0])
	{
		result[i] = s[tab[0] + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
