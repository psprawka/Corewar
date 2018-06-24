/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 13:32:37 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:26:37 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_abs(int number)
{
	return (number < 0 ? -number : number);
}

t_player	get_player(t_game *game, int champ_number)
{
	int i;

	i = 0;
	while (i < game->nb_players)
	{
		if (game->players[i].number == champ_number)
			return (game->players[i]);
		i++;
	}
	return (game->players[0]);
}

void		afficher_stack(t_game *game)
{
	t_list			*gothrough;
	t_process		*process;

	gothrough = game->processes_stack;
	if (!gothrough)
		ft_printf("No process in the stack\n");
	while (gothrough)
	{
		process = ((t_process *)gothrough->content);
		ft_printf("------------------------\n\
		Champion: %s\n", get_player(game, process->champ_numb).name);
		ft_printf("process champ number : %d\n", process->champ_numb);
		ft_printf("id: %d\n", process->id);
		ft_printf("carry: %d\n", process->carry);
		ft_printf("opcode: %d\n", process->opcode);
		ft_printf("pc: %d\n", process->pc);
		ft_printf("live: %d\n", process->live);
		ft_printf("last_live: %d\n", process->last_live);
		ft_printf("cycle: %d\n", process->cycles);
		ft_printf("registre 1 : %d\n", process->registers[1]);
		ft_printf("-------------------------\n");
		gothrough = gothrough->next;
	}
}

int			get_index(t_game *game, unsigned char type,\
	t_process *process, uint32_t pos)
{
	if (type == REG_CODE)
		return (process->registers[game->arena.map[modulo(pos)]]);
	return (read_2_bytes(game, pos));
}
