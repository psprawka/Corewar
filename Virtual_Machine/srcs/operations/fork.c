/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:15:17 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:20:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process		*clone_process(t_game *game, t_process *process)
{
	t_process	*clone;
	int			i;

	if (!(clone = (t_process *)ft_memalloc(sizeof(t_process))))
	{
		ft_printf("Error malloc clone process\n");
		exit(1);
	}
	i = -1;
	while (++i < REG_NUMBER)
		clone->registers[i] = process->registers[i];
	clone->id = ++game->nb_id;
	clone->carry = process->carry;
	clone->live = process->live;
	clone->last_live = process->last_live;
	clone->opcode = NB_OP + 1;
	clone->champ_numb = process->champ_numb;
	clone->cycles = game->cycle_so_far;
	return (clone);
}

void			ft_fork(t_game *game, t_process *process)
{
	int			index;
	int			newpc;
	int			offset;
	t_process	*child;

	offset = 1;
	index = get_index(game, DIR_CODE, process, process->pc + 1);
	newpc = modulo(process->pc + (index % IDX_MOD));
	child = clone_process(game, process);
	child->pc = newpc;
	read_opcode(game, child);
	ft_push_sorted(&game->processes_stack, ft_lstnew(child, sizeof(*child)));
	offset += 2;
	process->pc = modulo(process->pc + offset);
	ft_printf("naissance du process %d\n", child->id);
	ft_printf("Process %d has executed a fork %d (%d)\n",
	process->id, index, newpc);
}
