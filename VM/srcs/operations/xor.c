/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:03:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 10:52:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_xor(t_game *game, t_process *process)
{
	int				param[2];
	int				offset;
	int				registre;
	unsigned char	type;
	unsigned char	acb;

	offset = 1;
	acb = game->arena.map[modulo(process->pc + offset)];
	offset++;
	type = (acb >> 6) % 4;
	param[0] = get_value(game, process, type, modulo(process->pc + offset));
	offset += size_param(type, process->opcode);
	type = (acb >> 4) % 4;
	param[1] = get_value(game, process, type, modulo(process->pc + offset));
	offset += size_param(type, process->opcode);
	registre = game->arena.map[modulo(process->pc + offset)];
	offset++;
	process->registers[registre] = param[0] ^ param[1];
	process->carry = process->registers[registre] == 0;
	process->pc = modulo(process->pc + offset);
	ft_printf("Process %u has executed an xor\n", process->id);
}
