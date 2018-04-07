/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_aux3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 06:18:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 06:19:07 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

char		*ftt_strncpy(char *str, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = ftt_strnew(size + 1);
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char		*ftt_strjoin(char *s1, char *s2)
{
	char	*f;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(f = (char *)malloc(ftt_strlen(s1) + ftt_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		f[i] = s1[i];
	while (*s2)
		f[i++] = *s2++;
	f[i] = '\0';
	return (f);
}

long int	ftt_atoi(char *s)
{
	long int	nb;
	int			i;

	i = 0;
	nb = 0;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	s[i] == '-' || s[i] == '+' ? i++ : i;
	while (s[i] > 47 && s[i] < 58)
	{
		nb *= 10;
		nb += s[i++] - 48;
	}
	nb = s[0] == '-' ? nb * -1 : nb;
	return (nb);
}

char		*ftt_strsub(char *s, int start, size_t len)
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len-- && s[start] != '\0')
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char		*ftt_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char*)malloc(ftt_strlen(src) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
