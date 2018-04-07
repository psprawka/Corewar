/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 05:53:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 06:59:33 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

void	get_name(t_file *file)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;

	index = 0;
	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] != '\0' &&
	ftt_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
		tmp[index++] = TOKEN->line[TOKEN->pos++];
	tmp[index] = '\0';
	if (TOKEN->line[TOKEN->pos] == '\0')
		TOKEN->op_offset = -1;
	if (TOKEN->line[TOKEN->pos] == ':')
	{
		TOKEN->pos++;
		get_name(file);
	}
	else
	{
		TOKEN->name = ftt_strdup(tmp);
		TOKEN->icode = file->header->prog_size + 1;
	}
}

void	write_label_aux(t_file *file, int size, int *position, int i)
{
	char	*number;

	number = ftt_strsub(file->labels[i],
		ftt_strlen_chr(file->labels[i], ':') + 1, 100);
	*position = ftt_atoi(number) - TOKEN->icode;
	if (size == 2 && (file->header->prog_size += 2))
	{
		*position = (*position >> 8 & 0xff) | (*position << 8 & 0xff00);
		write(file->fd, (char *)&(*position), 2);
	}
	else if (size == 4 && (file->header->prog_size += 4))
	{
		*position = (*position >> 24 & 0xff) | (*position >> 8 & 0xff00) |
		(*position << 8 & 0xff0000) | (*position << 24 & 0xff000000);
		write(file->fd, (char *)&(*position), 4);
	}
}

void	write_label(t_file *file, int size)
{
	char	*label;
	char	*array_label;
	int		position;
	int		i;

	i = 0;
	position = TOKEN->pos + 1;
	label = ftt_strnew(LABEL_MAX_SIZE);
	while (TOKEN->line[position] != '\0' && TOKEN->line[position] != ',' &&
	TOKEN->line[position] != '\t' && TOKEN->line[position] != ' ')
		label[i++] = TOKEN->line[position++];
	i = 0;
	while (i < file->labels_nb)
	{
		array_label = ftt_strsub(file->labels[i], 0,
			ftt_strlen_chr(file->labels[i], ':'));
		if (ftt_strcmp(array_label, label) == 0)
		{
			write_label_aux(file, size, &position, i);
			return ;
		}
		i++;
	}
	ft_printf("No such label %s while attempting to dereference\n", label);
	exit(0);
}
