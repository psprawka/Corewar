/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:11:49 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:05:03 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ldi(t_game *game, t_process *process)
{
	int				offset;
	int				indexes[2];
	int				registre;
	int				address;
	unsigned char	acb;

	offset = 1;
	acb = game->arena.map[modulo(process->pc + offset)];
	offset++;
	if ((acb >> 6) % 4 == DIR_CODE)
		indexes[0] = get_index(game, (acb >> 6) % 4, process,
		modulo(process->pc + offset));
	else
		indexes[0] = get_value(game, process, (acb >> 6) % 4,
		modulo(process->pc + offset));
	offset += size_param((acb >> 6) % 4, process->opcode);
	indexes[1] = get_index(game, (acb >> 4) % 4, process,
	modulo(process->pc + offset));
	offset += size_param((acb >> 4) % 4, process->opcode);
	address = modulo(process->pc + (indexes[0] + indexes[1]) % IDX_MOD);
	registre = game->arena.map[modulo(process->pc + offset)];
	process->registers[registre] = read_4_bytes(game, address);
	offset++;
	process->pc = modulo(process->pc + offset);
	ft_printf("ldi %d %d r%d\n", indexes[0], indexes[1], registre);
}
