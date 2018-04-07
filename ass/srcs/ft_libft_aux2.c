/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_aux2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 06:17:19 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 06:59:17 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

int		ftt_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] < s2[i]) || (s1[i] > s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int		ftt_strncmp(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if ((s1[i] < s2[i]) || (s1[i] > s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)'\0');
}

void	*ftt_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (s);
}

int		ftt_strlen_chr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*ftt_strnew(size_t size)
{
	char	*tab;

	if (!(tab = (char *)malloc(size + 1)))
		return (NULL);
	ftt_memset(tab, '\0', size + 1);
	return (tab);
}
