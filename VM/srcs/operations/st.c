/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:08:13 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:23:02 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		st(t_game *game, t_process *process)
{
	int				param;
	int				registre_value;
	int				offset;
	unsigned char	acb;

	offset = 1;
	acb = game->arena.map[modulo(process->pc + offset)];
	offset++;
	registre_value = get_value(game, process, REG_CODE,
		modulo(process->pc + offset));
	offset++;
	if ((acb >> 4) % 4 == IND_CODE)
	{
		param = get_index(game, IND_CODE, process,
			modulo(process->pc + offset));
		put_param(registre_value, game, modulo(process->pc + param % IDX_MOD));
	}
	else if ((acb >> 4) % 4 == REG_CODE)
		process->registers[game->arena.map[modulo(process->pc + offset)]] = \
		registre_value;
	offset += size_param((acb >> 4) % 4, process->opcode);
	process->pc = modulo(process->pc + offset);
	// ft_printf("Process %u has executed a st r%d %d\n", process->id,
	// game->arena.map[modulo(process->pc - offset + 2)], param);
}
