/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 13:28:57 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/07 23:26:14 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		introduction(t_game *game)
{
	int			i;
	t_player	player;

	i = 0;
	ft_printf("____________________________________________________________\n");
	ft_printf("|               Welcome to the Corewar Arena !             |\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\nWarriors today fighting are :\n\n");
	while (i < game->nb_players)
	{
		player = get_player(game, i + 1);
		ft_printf("* Player %u, weighting %u bytes, \"%s\" (\"%s\")\n\n", \
		player.number, player.size, player.name, player.comment);
		i++;
	}
	ft_printf("------------------------------------------------------------\
	\n\n");
}

int				main(int argc, char **argv)
{
	t_game		*game;

	if (argc <= 1)
		usage();
	else
	{
		if (!(game = (t_game *)ft_memalloc(sizeof(t_game))))
		{
			ft_printf("Error game malloc\n");
			exit(1);
		}
		init_game_env(game);
		parse_options(argc, argv, game);
		introduction(game);
		run_vm(game);
	}
	return (0);
}
