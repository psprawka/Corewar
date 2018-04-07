/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:35:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 06:38:52 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

int		varg(t_file *file, char t, int arg)
{
	int bits;
	int type;

	bits = g_op_tab[TOKEN->op_offset].args[arg];
	if (t == 'r')
		type = T_REG;
	else
		type = t == '%' ? T_DIR : T_IND;
	if (bits & type)
		return (1);
	ft_printf("Invalid parameter for instruction %s\n", TOKEN->name);
	return (0);
}

void	prog_size(t_file *file, int cycle)
{
	if (TOKEN->line[TOKEN->pos] == 'r')
	{
		file->header->prog_size += 1;
		if (varg(file, 'r', cycle) == 0)
			exit(0);
	}
	else if (TOKEN->line[TOKEN->pos] == '%')
	{
		file->header->prog_size += (g_op_tab[TOKEN->op_offset].dir_size == 1 ?
			2 : 4);
		if (varg(file, '%', cycle) == 0)
			exit(0);
	}
	else if (ftt_isdigit(TOKEN->line[TOKEN->pos]) ||
	TOKEN->line[TOKEN->pos] == '-' || TOKEN->line[TOKEN->pos] == ':')
	{
		if (varg(file, ' ', cycle) == 0)
			exit(0);
		file->header->prog_size += 2;
	}
}
