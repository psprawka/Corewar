/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lives.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:13:18 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:12:23 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		check_die_proc(t_game *game, t_process *process)
{
	if (!process->live)
	{
		ft_printf("Process %u (%s)has died\n", process->id,
		get_player(game, process->champ_numb).name);
		return (1);
	}
	process->live = 0;
	return (0);
}

int				check_die_list(t_game *game)
{
	t_list		*gothrough;
	t_list		*previous;
	t_list		*next;
	t_process	*process;

	gothrough = game->processes_stack;
	previous = NULL;
	while (gothrough)
	{
		process = ((t_process *)gothrough->content);
		next = gothrough->next;
		if (check_die_proc(game, process))
			ft_delsup(&game->processes_stack, gothrough, previous);
		else
			previous = gothrough;
		gothrough = next;
	}
	if (!game->processes_stack)
		end_game(game);
	return (1);
}
