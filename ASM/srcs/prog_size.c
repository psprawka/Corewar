/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:35:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:00:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		varg(char t, int arg)
{
	int bits;
	int type;

	bits = g_op_tab[TOKEN->op_offset].args[arg];
	if (t == 'r')
		type = T_REG;
	else
		type = (t == '%' ? T_DIR : T_IND);
	if (bits & type)
		return (1);
	error(2, TOKEN->name, true);
	return (0);
}

void	prog_size(int cycle)
{
	if (TOKEN->line[TOKEN->pos] == 'r')
	{
		g_file.header->prog_size += 1;
		if (varg('r', cycle) == 0)
			exit(0);
	}
	else if (TOKEN->line[TOKEN->pos] == '%')
	{
		g_file.header->prog_size += (g_op_tab[TOKEN->op_offset].dir_size == 1 ?
			2 : 4);
		if (varg('%', cycle) == 0)
			exit(0);
	}
	else if (IS_DIGIT(TOKEN->line[TOKEN->pos]) ||
	TOKEN->line[TOKEN->pos] == '-' || TOKEN->line[TOKEN->pos] == ':')
	{
		if (varg(' ', cycle) == 0)
			exit(0);
		g_file.header->prog_size += 2;
	}
}
