/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:54:16 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:02:22 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		live(t_game *game, t_process *process)
{
	int			param;
	t_player	player;

	process->pc = modulo(process->pc + 1);
	param = read_4_bytes(game, process->pc);
	game->nb_lives++;
	process->live++;
	if (is_champ_number(game, param) > 0)
	{
		player = get_player(game, param);
		game->last_alive = ft_abs(param);
		player.last_live = game->cycle_so_far;
		player.total_lives_period++;
		ft_printf("Le processus (%d)(%s)(pc %d) dit que le joueur %d(%s)\
		est en vie (cycle : %d)\n",
		process->id, get_player(game, process->registers[1]).name, process->pc,
		player.number, player.name, game->cycle_so_far);
	}
	process->pc = modulo(process->pc + 4);
}
