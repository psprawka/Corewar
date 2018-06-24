/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:04:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:05:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		sti(t_game *game, t_process *process)
{
	int				indexes[2];
	int				registre_value;
	int				address;
	int				offset;
	unsigned char	acb;

	offset = 1;
	acb = game->arena.map[modulo(process->pc + offset)];
	offset++;
	registre_value = get_value(game, process, REG_CODE,
		modulo(process->pc + offset));
	offset++;
	if (((acb >> 4) % 4) == DIR_CODE)
		indexes[0] = read_2_bytes(game, modulo(process->pc + offset));
	else
		indexes[0] = get_value(game, process, (acb >> 4) % 4,
		modulo(process->pc + offset));
	offset += size_param((acb >> 4) % 4, process->opcode);
	indexes[1] = get_index(game, (acb >> 2) % 4, process,
	modulo(process->pc + offset));
	offset += size_param((acb >> 2) % 4, process->opcode);
	address = modulo(process->pc + (indexes[0] + indexes[1]) % IDX_MOD);
	put_param(registre_value, game, address);
	process->pc = modulo(process->pc + offset);
	ft_printf("Process %u has executed a sti r%d %d\n", process->id);
}
