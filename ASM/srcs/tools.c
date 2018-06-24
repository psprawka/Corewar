/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:14:47 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	op_offset(void)
{
	int		i;

	i = 0;
	if (ft_strcmp(TOKEN->name, "\0") == 0)
		return ;
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(g_op_tab[i].name, TOKEN->name) == 0)
		{
			TOKEN->op_offset = i;
			g_file.header->prog_size += (g_op_tab[i].coding_byte == 1) ? 2 : 1;
			return ;
		}
		i++;
	}
	ft_printf("Invalid instruction [%s][%s]\n", TOKEN->line, TOKEN->name);
	exit(0);
}

char	*readandstore(char *filename)
{
	int		fd;
	char	*buff;
	char	*final;

	fd = open(filename, O_RDONLY);
	final = "\0";
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
	while (TOKEN->line[i] != COMMENT_CHAR && TOKEN->line[i] != '\0')
		i++;
	TOKEN->line[i] = '\0';
}

int		gnl(void)
{
	int		size;
	char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	TOKEN->line = ft_strnew(1);
	while ((g_file.data[g_file.offset] == ' ' || g_file.data[g_file.offset] == '\n'
	|| g_file.data[g_file.offset] == '\t') && g_file.data[g_file.offset] != '\0')
		g_file.offset++;
	while (g_file.data[g_file.offset] != '\n' && g_file.data[g_file.offset] != '\0')
	{
		size = 0;
		while (size < BUFF_SIZE && g_file.data[g_file.offset] != '\n' &&
		g_file.data[g_file.offset] != '\0')
			temp[size++] = g_file.data[g_file.offset++];
		TOKEN->line = ft_strjoin(TOKEN->line, temp, 0);
	}
	rm_comment();
	if (ft_strcmp(TOKEN->line, "\0") == 0)
		return (0);
	return (1);
}