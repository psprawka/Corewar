/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:52:12 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 01:53:14 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		fresh_reg(t_process *process)
{
	int i;

	i = 0;
	while (i < REG_NUMBER + 1)
	{
		process->registers[i] = 0;
		i++;
	}
}

t_process		*new_proc(uint32_t pc, int champ_numb, int id)
{
	t_process	*process;

	if (!(process = (t_process *)ft_memalloc(sizeof(*process))))
	{
		ft_printf("Error malloc process\n");
		exit(1);
	}
	fresh_reg(process);
	process->registers[1] = -1 * champ_numb;
	process->champ_numb = champ_numb;
	process->pc = pc;
	process->id = id;
	process->carry = 0;
	process->live = 0;
	process->opcode = 0;
	process->last_live = 0;
	return (process);
}

void			load_first_processes(t_game *game)
{
	int			i;
	int			ch_nb;
	t_process	*newb;
	t_list		*newb_list;

	i = 0;
	while (i < game->nb_players)
	{
		ch_nb = game->players[i].number;
		game->players[i].color = i;
		newb = new_proc((ch_nb - 1) * (MEM_SIZE / game->nb_players),
		ch_nb, i + 1);
		read_opcode(game, newb);
		game->players[i].first_pc = (ch_nb - 1) * (MEM_SIZE / game->nb_players);
		newb_list = ft_lstnew(newb, sizeof(t_process));
		ft_push_sorted(&game->processes_stack, newb_list);
		i++;
	}
}

void			init_game_env(t_game *game)
{
	game->processes_stack = NULL;
	game->cycle_so_far = 0;
	game->cycle_to_die = CYCLE_TO_DIE;
	game->cycle_delta = CYCLE_DELTA;
	game->cycle_to_check = CYCLE_TO_DIE;
	game->nb_lives = 0;
	game->max_checks = MAX_CHECKS;
	game->winner = 0;
	game->nb_id = 0;
	ft_bzero(game->arena.map, MEM_SIZE + 1);
}
