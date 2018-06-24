/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 09:36:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 09:49:03 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*readandstore(char *filename)
{
	int		fd;
	char	*buff;
	char	*final;

	fd = open(filename, O_RDONLY);
	final = ft_strnew(1);
	buff = ft_strnew(BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		final = ft_strjoin(final, buff, 0);
		ft_bzero(buff, BUFF_SIZE);
	}
	return (final);
}

void	rm_comment(void)
{
	int i;

	i = 0;
	while (TOKEN->line[i] && TOKEN->line[i] != COMMENT_CHAR)
		i++;
	TOKEN->line[i] = '\0';
}

int		gnl(void)
{
	int		size;
	char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	TOKEN->line = ft_strnew(1);
	while (g_file.data[g_file.offset] && (IS_WHITE(g_file.data[g_file.offset]) ||
		g_file.data[g_file.offset] == '\n'))
		g_file.offset++;
	while (g_file.data[g_file.offset] && g_file.data[g_file.offset] != '\n')
	{
		size = 0;
		while (size < BUFF_SIZE && g_file.data[g_file.offset] &&
			g_file.data[g_file.offset] != '\n')
			temp[size++] = g_file.data[g_file.offset++];
		TOKEN->line = ft_strjoin(TOKEN->line, temp, 0);
	}
	rm_comment();
	if (!ft_strcmp(TOKEN->line, "\0"))
		return (0);
	return (1);
}

