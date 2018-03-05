/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:35:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/04 14:35:49 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"


static t_op    op_tab[17] =
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

int		varg(t_file *file, char t, int arg)
{
	int bits;
	int type;
	
	bits = op_tab[TOKEN->op_offset].args[arg];
	//	printf("%stype = %c\n%s", MAGNETA, t, NORMAL);
	type = (t == 'r' ? T_REG : (t == '%' ? T_DIR : (t == ':' ? T_LAB : T_IND)));
	//	printf("%sBITS %d\nTYPE %d%s\n", YELLOW, bits, type, NORMAL);
	if (bits & type)
	{
		//		printf("%sMATCHES!\n%s", MAGNETA, NORMAL);
		return (1);
	}
	printf("Invalid parameter for instruction %s\n", TOKEN->name);
	return (0);
}

void	prog_size(t_file *file, int cycle)
{
	if (TOKEN->line[TOKEN->pos] == 'r')
	{
		file->header->prog_size += 1;
		if (varg(file, 'r', cycle) == 0)
			exit (0);
		//		printf("Adding 1 cause of register!\nprog_size = %d\n%s", file->header->prog_size, NORMAL);
	}
	else if (TOKEN->line[TOKEN->pos] == '%')
	{
		file->header->prog_size += (op_tab[TOKEN->op_offset].dir_size == 1 ? 2 : 4);
		if (varg(file, '%', cycle) == 0)
			exit (0);
		//		printf("Adding %d cause of dir!\nprog_size = %d\n%s", (op_tab[TOKEN->op_offset].dir_size == 1 ? 2 : 4), file->header->prog_size, NORMAL);
	}
	else if (TOKEN->line[TOKEN->pos] == ':')
	{
		if (varg(file, ':', cycle) == 0)
			exit (0);
		file->header->prog_size += 2;
		//		printf("Adding 2 cause of label!\nprog_size = %d\n%s", file->header->prog_size, NORMAL);
	}
	else if (ft_isdigit(TOKEN->line[TOKEN->pos]))
	{
		if (varg(file, ' ', cycle) == 0)
			exit (0);
		file->header->prog_size += 2;
		//		printf("Adding 2 cause of indirect!\nprog_size = %d\n%s", file->header->prog_size, NORMAL);
	}
}
