/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:21:43 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/01/26 17:30:24 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

t_list		*get_fd(t_list **list, int fd)
{
	t_list		*tmp;

	tmp = *list;
	if (list)
	{
		while (tmp)
		{
			if ((int)tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = ft_lstnew("\0", fd);
		ft_lstadd(list, tmp);
		return (tmp);
	}
	return (NULL);
}

int			check(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

void		update(t_list **curr, char **line)
{
	int		index;
	char	*test;

	index = 0;
	index = (check((*curr)->content) == -1) ? (int)ft_strlen((*curr)->content)
	: check((*curr)->content);
	*line = ft_strsub((char *)(*curr)->content, 0, index);
	if (index == (int)(ft_strlen((*curr)->content)))
		ft_strclr((*curr)->content);
	else
	{
		test = (*curr)->content;
		(*curr)->content = ft_strsub(test, index + 1, (int)ft_strlen(test)
				- index - 1);
		ft_strdel(&test);
	}
}

int			get_next_line(const int fd, char **line)
{
	static	t_list		*list = NULL;
	t_list				*curr;
	int					reader;
	char				buff[BUFF_SIZE + 1];
	char				*test;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	curr = get_fd(&list, fd);
	while ((reader = read(fd, buff, BUFF_SIZE)))
	{
		buff[reader] = 0;
		test = curr->content;
		if (!(curr->content = ft_strjoin(curr->content, buff)))
			return (-1);
		ft_strdel(&test);
		if (check(buff) >= 0)
			break ;
	}
	if (reader < BUFF_SIZE && !ft_strlen(curr->content))
		return (0);
	update(&curr, line);
	return (1);
}
