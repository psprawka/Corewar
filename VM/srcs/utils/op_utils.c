/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 13:44:19 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:17:32 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t		size_param(unsigned char type, uint32_t opcode)
{
	int i;

	i = search_instruction(opcode);
	if (type == REG_CODE)
		return (1);
	if (type == DIR_CODE)
		return (2 + !g_op_tab[i].trunc_direct * 2);
	if (type == IND_CODE)
		return (IND_SIZE);
	return (0);
}

static int		is_register(t_game *game, int position)
{
	uint32_t	registre;

	registre = game->arena.map[position];
	return (registre > 0 && registre <= REG_NUMBER);
}

void			put_param(int param, t_game *game, uint32_t pos)
{
	game->arena.map[modulo(pos + 0)] = param >> 24;
	game->arena.map[modulo(pos + 1)] = ((param << 8) >> 24);
	game->arena.map[modulo(pos + 2)] = ((param << 16) >> 24);
	game->arena.map[modulo(pos + 3)] = ((param << 24) >> 24);
}

static int		check_params(t_game *game, t_process *process)
{
	unsigned char	acb;
	int				nb_param;
	int				i;
	int				jumpto;
	unsigned char	type;

	acb = game->arena.map[modulo(process->pc + 1)];
	nb_param = g_op_tab[process->opcode - 1].nb_params;
	i = 0;
	jumpto = 2;
	while (i < nb_param)
	{
		type = ((acb >> (2 * (3 - i))) % 4);
		type = (type == IND_CODE) ? T_IND : type;
		if (!(g_op_tab[process->opcode - 1].params_types[i] & type))
			return (0);
		if (type == REG_CODE && !is_register(game,
			modulo(process->pc + jumpto)))
			return (0);
		jumpto += size_param(((acb >> (2 * (3 - i))) % 4), process->opcode);
		i++;
	}
	return (1);
}

int				param_good(t_game *game, t_process *process)
{
	if (!g_op_tab[process->opcode - 1].coding_byte)
		return (1);
	return (check_params(game, process));
}
