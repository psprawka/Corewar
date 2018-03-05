/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* 	 ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/02/19 10:12:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"


int		ft_isdigit(char c)
{
	return (c > 47 && c < 58) ? 1 : 0;
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	
	ptr = s;
	while (n--)
		*ptr++ = '\0';
}


int 	ft_strlen(char *str)
{
	int		i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char to_find)
{
	while (*str && *str != to_find)
		str++;
	if (*str == to_find)
		return (str);
	else
		return ((char *)'\0');
}

int		ft_strcmp(char *s1, char *s2)
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

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;
	
	ptr = s;
	i = 0;
	while (i < n)
	ptr[i++] = c;
	return (s);
}

int		ft_strlen_chr(char *str, char c)
{
	int		i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}


char	*ft_strnew(size_t size)
{
	char	*tab;
	
	if (!(tab = (char *)malloc(size + 1)))
	return (NULL);
	ft_memset(tab, '\0', size + 1);
	return (tab);
}

char 	*ft_strncpy(char *str, int size)
{
	char *new;
	int i;
	
	i = 0;
	new = ft_strnew(size + 1);
	while (i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*f;
	int		i;
	
	if (!s1 || !s2)
		return (NULL);
	if (!(f = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		f[i] = s1[i];
	while (*s2)
		f[i++] = *s2++;
	f[i] = '\0';
	return (f);
}

long int	ft_atoi(char *s)
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


char	*ft_strsub(char *s, int start, size_t len)
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


char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	
	i = 0;
	copy = (char*)malloc(ft_strlen(src) + 1);
	
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


char    *ft_itoa(int nbr)
{
	int     sign;
	int     count;
	char    *str;
	count = 1;
	sign = nbr;
	while (sign /= 10)
		count++;
	sign = nbr < 0 ? 1 : 0;
	count = nbr < 0 ? count += 1 : count;
	if (nbr == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (!(str = ft_strnew(count)))
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	nbr = nbr < 0 ? nbr *= -1 : nbr;
	while (--count >= sign)
	{
		str[count] = nbr >= 10 ? (nbr % 10) + 48 : nbr + 48;
		nbr /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
