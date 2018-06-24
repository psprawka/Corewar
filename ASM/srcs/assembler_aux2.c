/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 05:53:29 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/24 07:21:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	get_name(void)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;

	index = 0;
	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] != '\0' &&
	ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
		tmp[index++] = TOKEN->line[TOKEN->pos++];
	tmp[index] = '\0';
	if (TOKEN->line[TOKEN->pos] == '\0')
		TOKEN->op_offset = -1;
	if (TOKEN->line[TOKEN->pos] == ':')
	{
		TOKEN->pos++;
		get_name();
	}
	else
	{
		TOKEN->name = ft_strdup(tmp);
		TOKEN->icode = g_file.header->prog_size + 1;
	}
}

void	write_label_aux(int size, int *position, int i)
{
	char	*number;

	number = ft_strsub(g_file.labels[i],
		ft_strlen_chr(g_file.labels[i], ':') + 1, 100);
	*position = ft_atoi(number) - TOKEN->icode;
	if (size == 2 && (g_file.header->prog_size += 2))
	{
		*position = (*position >> 8 & 0xff) | (*position << 8 & 0xff00);
		write(g_file.fd, (char *)&(*position), 2);
	}
	else if (size == 4 && (g_file.header->prog_size += 4))
	{
		*position = (*position >> 24 & 0xff) | (*position >> 8 & 0xff00) |
		(*position << 8 & 0xff0000) | (*position << 24 & 0xff000000);
		write(g_file.fd, (char *)&(*position), 4);
	}
}

void	write_label(int size)
{
	char	*label;
	char	*array_label;
	int		position;
	int		i;

	i = 0;
	position = TOKEN->pos + 1;
	label = ft_strnew(LABEL_MAX_SIZE);
	while (TOKEN->line[position] != '\0' && TOKEN->line[position] != ',' &&
	TOKEN->line[position] != '\t' && TOKEN->line[position] != ' ')
		label[i++] = TOKEN->line[position++];
	i = 0;
	while (i < g_file.labels_nb)
	{
		array_label = ft_strsub(g_file.labels[i], 0,
			ft_strlen_chr(g_file.labels[i], ':'));
		if (ft_strcmp(array_label, label) == 0)
		{
			write_label_aux(size, &position, i);
			return ;
		}
		i++;
	}
	//printf("No such label %s while attempting to dereference\n", label);
	exit(0);
}

void	dir(void)
{
	int		value;
	char	*token;

	value = 0;
	token = ft_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == ':')
		g_op_tab[TOKEN->op_offset].dir_size == 1 ? write_label(2) :
		write_label(4);
	else if (g_op_tab[TOKEN->op_offset].dir_size == 1)
	{
		value = ft_atoi(token) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
		write(g_file.fd, (char *)&value, 2);
		g_file.header->prog_size += 2;
	}
	else
	{
		value = ft_atoi(token) % 4294967296;
		value = (value >> 24 & 0xff) | (value >> 8 & 0xff00) |
		(value << 8 & 0xff0000) | (value << 24 & 0xff000000);
		write(g_file.fd, (char *)&value, 4);
		g_file.header->prog_size += 4;
	}
	free(token);
}

void	reg(void)
{
	int		value;
	char	*number;

	value = 0;
	number = ft_strsub(TOKEN->line, TOKEN->pos, 4);
	if ((value = ft_atoi(number)) > 99 || value < 0)
	{
		// printf("Syntax error INSTRUCTION \"r\"\n");
		exit(0);
	}
	write(g_file.fd, (char *)&value, 1);
	g_file.header->prog_size += 1;
	free(number);
}

void	indir(void)
{
	int		value;
	char	*number;

	value = 0;
	number = ft_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == LABEL_CHAR)
		write_label(2);
	else
	{
		value = ft_atoi(number) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
		write(g_file.fd, (char *)&value, 2);
		g_file.header->prog_size += 2;
	}
}

void	get_args(void)
{
	while (TOKEN->line[TOKEN->pos] != '\0')
	{
		while (TOKEN->line[TOKEN->pos] == ' ' ||
		TOKEN->line[TOKEN->pos] == '\t')
			TOKEN->pos++;
		if (TOKEN->line[TOKEN->pos] == 'r' && ++TOKEN->pos)
			reg();
		else if (TOKEN->line[TOKEN->pos] == DIRECT_CHAR && ++TOKEN->pos)
			dir();
		else if (TOKEN->line[TOKEN->pos] == LABEL_CHAR ||
			IS_DIGIT(TOKEN->line[TOKEN->pos]) ||
				TOKEN->line[TOKEN->pos] == '-')
			indir();
		while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
			TOKEN->line[TOKEN->pos] != '\0')
			;
		while (TOKEN->line[TOKEN->pos] == ' ' ||
		TOKEN->line[TOKEN->pos] == '\t')
			TOKEN->pos++;
	}
}

void	handle_instructions(void)
{
	static int	line;

	while (g_file.data[g_file.offset] != '\0')
	{
		TOKEN->pos = 0;
		gnl();
		if (line < 2 && ft_strcmp(TOKEN->line, "\0") && line++)
			line == 1 ? parse_name(0) : parse_comment(0);
		else if (ft_strcmp(TOKEN->line, "\0"))
		{
			get_name();
			op_offset();
			TOKEN->bytecode = 0;
			if (TOKEN->op_offset != -1)
				write(g_file.fd, (char *)&(g_op_tab[TOKEN->op_offset].op_code),
				1);
			if (g_op_tab[TOKEN->op_offset].coding_byte)
				bytecode(TOKEN->pos);
			get_args();
		}
	}
}


void	bytecode(int pos)
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
		else if (TOKEN->line[pos] == ':' || IS_DIGIT(TOKEN->line[pos]) ||
			TOKEN->line[pos] == '-')
			TOKEN->bytecode |= IND_CODE;
		TOKEN->bytecode <<= 2;
		bits += 2;
		while (TOKEN->line[pos++] != ',' && TOKEN->line[pos] != '\0')
			;
	}
	while (bits++ < 6)
		TOKEN->bytecode <<= 1;
	write(g_file.fd, &(TOKEN->bytecode), 1);
}

