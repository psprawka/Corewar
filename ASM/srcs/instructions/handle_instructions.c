/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 06:04:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 09:53:18 by psprawka         ###   ########.fr       */
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

/*
**	Function get_instruction_name() takes one line (TOKEN->line) and gets
**	instruction's name. In case of a label, function calls itself again on
**	an offset behind a label. Instruction's name is stored in TOKEN->name
*/ 

static void		get_instruction_name(void)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;
	
	index = 0;
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] && ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
		tmp[index++] = TOKEN->line[TOKEN->pos++];
	tmp[index] = '\0';
	
	if (!TOKEN->line[TOKEN->pos])
		TOKEN->op_offset = -1;
		
	if (TOKEN->line[TOKEN->pos] == ':')
	{
		TOKEN->pos++;
		get_instruction_name();
	}
	else
	{
		TOKEN->name = ft_strdup(tmp);
		TOKEN->icode = g_file.header->prog_size + 1;
	}
}

static void		get_instruction_values(void)
{
	while (TOKEN->line[TOKEN->pos] != '\0')
	{
		while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
			TOKEN->pos++;
		if (TOKEN->line[TOKEN->pos] == 'r' && ++TOKEN->pos)
			get_register();
		else if (TOKEN->line[TOKEN->pos] == DIRECT_CHAR && ++TOKEN->pos)
			get_direct();
		else if (TOKEN->line[TOKEN->pos] == LABEL_CHAR ||
			IS_DIGIT(TOKEN->line[TOKEN->pos]) || TOKEN->line[TOKEN->pos] == '-')
			get_indirect();
		while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR && TOKEN->line[TOKEN->pos])
			;
		while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
			TOKEN->pos++;
	}
}

void			handle_instructions(void)
{
	while (g_file.data[g_file.offset])
	{
		TOKEN->pos = 0;
		gnl();
		
		if (!ft_strcmp(TOKEN->line, "\0"))
			continue; 
			
		get_instruction_name();
		get_op_offset();
		TOKEN->bytecode = 0;
		if (TOKEN->op_offset != -1)
			write(g_file.fd, (char *)&(g_op_tab[TOKEN->op_offset].op_code), 1);
		if (g_op_tab[TOKEN->op_offset].coding_byte)
			get_byte_code(TOKEN->pos);
		get_instruction_values();
	}
}

