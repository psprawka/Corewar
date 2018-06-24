/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 20:10:04 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:17:18 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		no_winner(t_game *game)
{
	if (game->dump && game->cycle_so_far == game->dump)
	{
		print_map(game);
		exit(0);
	}
	return (game->processes_stack == NULL);
}

static void		checker(t_game *game)
{
	if (game->nb_lives >= NBR_LIVE)
	{
		game->cycle_to_die -= game->cycle_delta;
		game->nb_lives = 0;
		game->nb_checks = 0;
	}
	else if (game->nb_checks == MAX_CHECKS - 1)
	{
		game->cycle_to_die -= (int)game->cycle_delta;
		game->nb_lives = 0;
		game->nb_checks = 0;
	}
	else
	{
		game->nb_checks++;
		game->nb_lives = 0;
	}
	game->cycle_to_check += (uint32_t)game->cycle_to_die;
}

void			run_vm(t_game *game)
{
	while (!no_winner(game) && game->cycle_to_die > 0)
	{
		game->cycle_so_far++;
		do_cycle(game);
		replace(game);
		if (game->cycle_to_check <= game->cycle_so_far)
		{
			ft_printf("Attention, je check ! (cycle %d)\n", game->cycle_so_far);
			check_die_list(game);
			checker(game);
		}
	}
	end_game(game);
}
