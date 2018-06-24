/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:08:25 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:00:33 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		zjmp(t_game *game, t_process *process)
{
	short		param;
	int			offset;

	offset = 1;
	param = (short)get_index(game, IND_CODE, process,
		modulo(process->pc + offset));
	offset += 2;
	if (process->carry)
	{
		ft_printf("Process %u executed a zjump to %d\n", process->id, param);
		process->pc = modulo(process->pc + (param % IDX_MOD));
	}
	else
	{
		ft_printf("zjmp %d FAILED\n", param);
		process->pc = modulo(process->pc + offset);
	}
}
