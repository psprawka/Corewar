/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 05:51:00 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 06:59:11 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

void	dir(t_file *file)
{
	int		value;
	char	*token;

	value = 0;
	token = ftt_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == ':')
		g_op_tab[TOKEN->op_offset].dir_size == 1 ? write_label(file, 2) :
		write_label(file, 4);
	else if (g_op_tab[TOKEN->op_offset].dir_size == 1)
	{
		value = ftt_atoi(token) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
		write(file->fd, (char *)&value, 2);
		file->header->prog_size += 2;
	}
	else
	{
		value = ftt_atoi(token) % 4294967296;
		value = (value >> 24 & 0xff) | (value >> 8 & 0xff00) |
		(value << 8 & 0xff0000) | (value << 24 & 0xff000000);
		write(file->fd, (char *)&value, 4);
		file->header->prog_size += 4;
	}
	free(token);
}

void	indir(t_file *file)
{
	int		value;
	char	*number;

	value = 0;
	number = ftt_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == LABEL_CHAR)
		write_label(file, 2);
	else
	{
		value = ftt_atoi(number) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
		write(file->fd, (char *)&value, 2);
		file->header->prog_size += 2;
	}
}

void	handle_instructions(t_file *file)
{
	static int	line;

	while (file->data[file->offset] != '\0')
	{
		TOKEN->pos = 0;
		gnl(file);
		if (line < 2 && ftt_strcmp(TOKEN->line, "\0") && line++)
			line == 1 ? pname(file, 0) : pcomment(file, 0);
		else if (ftt_strcmp(TOKEN->line, "\0"))
		{
			get_name(file);
			op_offset(file);
			TOKEN->bytecode = 0;
			if (TOKEN->op_offset != -1)
				write(file->fd, (char *)&(g_op_tab[TOKEN->op_offset].op_code),
				1);
			if (g_op_tab[TOKEN->op_offset].coding_byte)
				bytecode(file, TOKEN->pos);
			get_args(file);
		}
	}
}

void	get_args(t_file *file)
{
	while (TOKEN->line[TOKEN->pos] != '\0')
	{
		while (TOKEN->line[TOKEN->pos] == ' ' ||
		TOKEN->line[TOKEN->pos] == '\t')
			TOKEN->pos++;
		if (TOKEN->line[TOKEN->pos] == 'r' && ++TOKEN->pos)
			reg(file);
		else if (TOKEN->line[TOKEN->pos] == DIRECT_CHAR && ++TOKEN->pos)
			dir(file);
		else if (TOKEN->line[TOKEN->pos] == LABEL_CHAR ||
			ftt_isdigit(TOKEN->line[TOKEN->pos]) ||
				TOKEN->line[TOKEN->pos] == '-')
			indir(file);
		while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
			TOKEN->line[TOKEN->pos] != '\0')
			;
		while (TOKEN->line[TOKEN->pos] == ' ' ||
		TOKEN->line[TOKEN->pos] == '\t')
			TOKEN->pos++;
	}
}

void	bytecode(t_file *file, int pos)
{
	int		bits;

	bits = 0;
	while (TOKEN->line[pos] != '\0')
	{
		while (TOKEN->line[pos] == ' ' || TOKEN->line[pos] == '\t')
			pos++;
		if (TOKEN->line[pos] == 'r')
			TOKEN->bytecode |= REG_CODE;
		else if (TOKEN->line[pos] == '%')
			TOKEN->bytecode |= DIR_CODE;
		else if (TOKEN->line[pos] == ':' || ftt_isdigit(TOKEN->line[pos]) ||
			TOKEN->line[pos] == '-')
			TOKEN->bytecode |= IND_CODE;
		TOKEN->bytecode <<= 2;
		bits += 2;
		while (TOKEN->line[pos++] != ',' && TOKEN->line[pos] != '\0')
			;
	}
	while (bits++ < 6)
		TOKEN->bytecode <<= 1;
	write(file->fd, &(TOKEN->bytecode), 1);
}
