/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 10:43:43 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:50:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	count_byte_code(int pos)
{
	int		bits;

	bits = 0;
	while (TOKEN->line[pos])
	{
		while (TOKEN->line[pos] && IS_WHITE(TOKEN->line[pos]))
			pos++;
		if (TOKEN->line[pos] == 'r')
			TOKEN->bytecode |= REG_CODE;
		else if (TOKEN->line[pos] == '%')
			TOKEN->bytecode |= DIR_CODE;
		else if (TOKEN->line[pos] == ':' || IS_DIGIT(TOKEN->line[pos]) || TOKEN->line[pos] == '-')
			TOKEN->bytecode |= IND_CODE;
		TOKEN->bytecode <<= 2;
		bits += 2;
		while (TOKEN->line[pos++] != ',' && TOKEN->line[pos])
			;
	}
	while (bits++ < 6)
		TOKEN->bytecode <<= 1;
	write(g_file.fd, &(TOKEN->bytecode), 1);
}

void		count_prog_size(int cycle)
{
	if (TOKEN->line[TOKEN->pos] == 'r')
	{
		g_file.header->prog_size += 1;
		if (valid_instr_types('r', cycle) == 0)
			exit(0);
	}
	else if (TOKEN->line[TOKEN->pos] == '%')
	{
		g_file.header->prog_size += (g_op_tab[TOKEN->op_offset].dir_size == 1 ? 2 : 4);
		if (valid_instr_types('%', cycle) == 0)
			exit(0);
	}
	else if (IS_DIGIT(TOKEN->line[TOKEN->pos]) ||
	TOKEN->line[TOKEN->pos] == '-' || TOKEN->line[TOKEN->pos] == ':')
	{
		if (valid_instr_types(' ', cycle) == 0)
			exit(0);
		g_file.header->prog_size += 2;
	}
}
