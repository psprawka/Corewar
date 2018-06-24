/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 18:07:48 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:18:57 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t	modulo(int nb)
{
	while (nb < 0)
		nb += MEM_SIZE;
	return (nb % MEM_SIZE);
}

uint32_t	change_endianness(uint32_t value)
{
	uint32_t result;

	result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}

int			search_instruction(uint32_t opcode)
{
	int i;

	i = 0;
	while (i < NB_OP && g_op_tab[i].opcode != opcode)
		i++;
	return (i);
}

int			is_pc(t_game *game, int j)
{
	t_list		*proute;
	t_process	*process;

	proute = game->processes_stack;
	while (proute)
	{
		process = ((t_process *)proute->content);
		if (process->pc == (uint32_t)j && process->id == 21)
			return (21);
		if (process->pc == (uint32_t)j && process->id == 2)
			return (2);
		if (process->pc == (uint32_t)j && process->id == 3)
			return (3);
		if (process->pc == (uint32_t)j)
			return (1);
		proute = proute->next;
	}
	return (0);
}

void		print_map(t_game *game)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i && i % 64 == 0)
			ft_printf("\n");
		if (game->arena.map[i] == 0 && is_pc(game, i) == 3)
			ft_printf("%s00\033[0m ", RED, game->arena.map[i]);
		else if (game->arena.map[i] == 0 && i == 3386)
			ft_printf("%s00\033[0m ", CYAN, game->arena.map[i]);
		else if (game->arena.map[i] == 0)
			ft_printf("00 ");
		else if (is_pc(game, i) == 2)
			ft_printf("%s%02x\033[0m ", GREEN, game->arena.map[i]);
		else if (is_pc(game, i) == 3)
			ft_printf("%s%02x\033[0m ", RED, game->arena.map[i]);
		else if (is_pc(game, i) == 1)
			ft_printf("%s%02.2x\033[0m ", BLUE, game->arena.map[i]);
		else
			ft_printf("\033[1;33m%02.2x\033[0m ", game->arena.map[i]);
		i++;
	}
	ft_printf("\n");
}
