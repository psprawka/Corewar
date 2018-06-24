/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 06:04:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:19:25 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// t_op	g_op_tab[17] =
// {
// 	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
// 	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
// 	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
// 	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
// 	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
// 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
// 		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
// 	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
// 		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
// 	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
// 		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
// 	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
// 	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
// 		"load index", 1, 1},
// 	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
// 		"store index", 1, 1},
// 	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
// 	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
// 	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
// 		"long load index", 1, 1},
// 	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
// 	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
// 	{0, 0, {0}, 0, 0, 0, 0, 0}
// };

// void	get_commands_values(void)
// {
// 	while (TOKEN->line[TOKEN->pos] != '\0')
// 	{
// 		while (TOKEN->line[TOKEN->pos] == ' ' ||
// 		TOKEN->line[TOKEN->pos] == '\t')
// 			TOKEN->pos++;
// 		if (TOKEN->line[TOKEN->pos] == 'r' && ++TOKEN->pos)
// 			get_register();
// 		else if (TOKEN->line[TOKEN->pos] == DIRECT_CHAR && ++TOKEN->pos)
// 			get_direct();
// 		else if (TOKEN->line[TOKEN->pos] == LABEL_CHAR ||
// 			IS_DIGIT(TOKEN->line[TOKEN->pos]) ||
// 				TOKEN->line[TOKEN->pos] == '-')
// 			get_indirect();
// 		while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
// 			TOKEN->line[TOKEN->pos] != '\0')
// 			;
// 		while (TOKEN->line[TOKEN->pos] == ' ' ||
// 		TOKEN->line[TOKEN->pos] == '\t')
// 			TOKEN->pos++;
// 	}
// }

// void	handle_instructions(void)
// {
// 	static int	line = 2;

// 	while (g_file.data[g_file.offset] != '\0')
// 	{
// 		TOKEN->pos = 0;
// 		gnl();
// 		if (line < 2 && ft_strcmp(TOKEN->line, "\0"))
// 			line++;
// 		else if (ft_strcmp(TOKEN->line, "\0"))
// 		{
// 			get_name();
// 			op_offset();
// 			TOKEN->bytecode = 0;
// 			if (TOKEN->op_offset != -1)
// 				write(g_file.fd, (char *)&(g_op_tab[TOKEN->op_offset].op_code), 1);
// 			if (g_op_tab[TOKEN->op_offset].coding_byte)
// 				bytecode(TOKEN->pos);
// 			get_commands_values();
// 		}
// 	}
// }

