/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:52:05 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:16:21 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int					jumptofromacb(t_game *game, t_process *process)
{
	int				jumpto;
	unsigned char	acb;

	acb = game->arena.map[modulo(process->pc + 1)];
	jumpto = 1;
	jumpto += size_param((acb >> 6) % 4, process->opcode);
	if (g_op_tab[process->opcode - 1].nb_params >= 2)
		jumpto += size_param((acb >> 4) % 4, process->opcode);
	if (g_op_tab[process->opcode - 1].nb_params >= 3)
		jumpto += size_param((acb >> 2) % 4, process->opcode);
	jumpto++;
	return (jumpto);
}

void				read_opcode(t_game *game, t_process *process)
{
	int	opcode;

	opcode = game->arena.map[modulo(process->pc)];
	if (opcode && opcode <= NB_OP)
	{
		process->opcode = g_op_tab[opcode - 1].opcode;
		process->cycles = game->cycle_so_far + g_op_tab[opcode - 1].cycles;
	}
	else
	{
		process->opcode = NB_OP + 1;
		process->cycles++;
	}
}

void				replace(t_game *game)
{
	t_list		*head;
	t_process	*process;
	t_list		*areplace;

	head = game->processes_stack;
	process = ((t_process *)head->content);
	while (head && process->cycles == game->cycle_so_far)
	{
		read_opcode(game, process);
		areplace = ft_lst_pop(&game->processes_stack);
		ft_push_sorted(&game->processes_stack, areplace);
		head = game->processes_stack;
		if (head)
			process = ((t_process *)head->content);
	}
}

int					exec_process(t_game *game, t_process *process)
{
	if (process->opcode <= NB_OP && param_good(game, process))
		g_op_tab[process->opcode - 1].f(game, process);
	else if (process->cycles == game->cycle_so_far && process->opcode <= NB_OP)
		process->pc = modulo(process->pc + jumptofromacb(game, process));
	else
		process->pc = modulo(process->pc + 1);
	return (1);
}
