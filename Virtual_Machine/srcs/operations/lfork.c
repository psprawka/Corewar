/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:40:21 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:20:28 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			lfork(t_game *game, t_process *process)
{
	int			index;
	int			newpc;
	int			offset;
	t_process	*child;

	offset = 1;
	index = get_index(game, DIR_CODE, process, process->pc + 1);
	newpc = modulo(process->pc + index);
	child = clone_process(game, process);
	child->pc = newpc;
	read_opcode(game, child);
	ft_push_sorted(&game->processes_stack, ft_lstnew(child, sizeof(*child)));
	process->pc = modulo(process->pc + offset + 2);
	ft_printf("Process %u has executed a fork\n", process->id);
}
