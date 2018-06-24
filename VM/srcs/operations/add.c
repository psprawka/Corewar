/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:18:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:01:47 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add(t_game *game, t_process *process)
{
	int				registre1;
	int				registre2;
	int				registre3;
	int				offset;
	unsigned char	acb;

	offset = 1;
	acb = game->arena.map[process->pc];
	offset++;
	registre1 = get_value(game, process, REG_CODE,
		modulo(process->pc + offset));
	offset++;
	registre2 = get_value(game, process, REG_CODE,
		modulo(process->pc + offset));
	offset++;
	registre3 = game->arena.map[modulo(process->pc + offset)];
	offset++;
	process->registers[registre3] = registre1 + registre2;
	process->carry = process->registers[registre3] == 0;
	process->pc = modulo(process->pc + offset);
	ft_printf("Process %u has executed an Add\n", process->id);
}
