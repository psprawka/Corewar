/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:07:26 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/06 03:42:27 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		do_cycle(t_game *game)
{
	t_list		*gothrough;
	t_process	*process;

	gothrough = game->processes_stack;
	if (gothrough)
		process = ((t_process *)gothrough->content);
	while (gothrough && process->cycles == game->cycle_so_far)
	{
		exec_process(game, process);
		gothrough = gothrough->next;
		if (gothrough)
			process = ((t_process *)gothrough->content);
	}
	return (1);
}
