/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 06:59:22 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

void	op_offset(t_file *file)
{
	int		i;

	i = 0;
	if (ftt_strcmp(TOKEN->name, "\0") == 0)
		return ;
	while (g_op_tab[i].name != NULL)
	{
		if (ftt_strcmp(g_op_tab[i].name, TOKEN->name) == 0)
		{
			TOKEN->op_offset = i;
			file->header->prog_size += (g_op_tab[i].coding_byte == 1) ? 2 : 1;
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
	buff = ftt_strnew(BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		final = ftt_strjoin(final, buff);
		ftt_bzero(buff, BUFF_SIZE);
	}
	return (final);
}

void	rm_comment(t_file *file)
{
	int i;

	i = 0;
	while (TOKEN->line[i] != COMMENT_CHAR && TOKEN->line[i] != '\0')
		i++;
	TOKEN->line[i] = '\0';
}

int		gnl(t_file *file)
{
	int		size;
	char	*temp;

	temp = ftt_strnew(BUFF_SIZE);
	TOKEN->line = ftt_strnew(1);
	while ((file->data[file->offset] == ' ' || file->data[file->offset] == '\n'
	|| file->data[file->offset] == '\t') && file->data[file->offset] != '\0')
		file->offset++;
	while (file->data[file->offset] != '\n' && file->data[file->offset] != '\0')
	{
		size = 0;
		while (size < BUFF_SIZE && file->data[file->offset] != '\n' &&
		file->data[file->offset] != '\0')
			temp[size++] = file->data[file->offset++];
		TOKEN->line = ftt_strjoin(TOKEN->line, temp);
	}
	rm_comment(file);
	if (ftt_strcmp(TOKEN->line, "\0") == 0)
		return (0);
	return (1);
}
