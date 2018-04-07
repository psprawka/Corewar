/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:21:36 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:02:16 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		lld(t_game *game, t_process *process)
{
	int				param;
	int				registre;
	int				jumpto;
	unsigned char	acb;

	jumpto = 1;
	acb = game->arena.map[modulo(process->pc + jumpto)];
	jumpto++;
	param = get_value_nomod(game, process, (acb >> 6) % 4,
	modulo(process->pc + jumpto));
	jumpto += size_param((acb >> 6) % 4, process->opcode);
	registre = game->arena.map[modulo(process->pc + jumpto)];
	jumpto++;
	process->registers[registre] = param;
	process->carry = process->registers[registre] == 0;
	process->pc = modulo(process->pc + jumpto);
	ft_printf("Process %u has executed a long load %d r%d\n", process->id,
	param, game->arena.map[modulo(process->pc - 1)]);
}
