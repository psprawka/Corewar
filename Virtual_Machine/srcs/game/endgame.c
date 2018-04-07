/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:20:13 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:12:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		end_game(t_game *game)
{
	t_player	winner;

	winner = get_player(game, game->last_alive);
	ft_printf("Player %d(\"%s\") has won !\n", winner.number, winner.name);
	if (game->dump)
		print_map(game);
	exit(1);
}
