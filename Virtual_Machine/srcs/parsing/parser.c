/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 10:03:05 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 02:16:39 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	void	check_players(t_game *game)
{
	int i;
	int	j;

	if (!game->nb_players || game->nb_players > MAX_PLAYERS)
	{
		ft_printf("Wrong number of players\nMax players authorized: %d\n",
		MAX_PLAYERS);
		exit(1);
	}
	i = -1;
	while (++i < game->nb_players)
	{
		j = i;
		while (++j < game->nb_players)
		{
			if (game->players[i].number == game->players[j].number)
			{
				ft_printf("Error same numbers\n");
				exit(1);
			}
		}
	}
}

static void		handle_dump_option(int argc, char **argv, int *i, t_game *game)
{
	uint32_t dump;

	if (ft_strequ(argv[*i], "-dump"))
	{
		(*i)++;
		if ((*i) >= argc || (!(dump = ft_atoi(argv[*i])) && argv[*i][0] != '0'))
		{
			usage();
			exit(2);
		}
		game->dump = dump;
		(*i)++;
	}
}

static void		set_player_nbr(int argc, char **argv, t_game *game, int *i)
{
	long long	number;
	static int	j = 0;

	if ((*i) + 3 > argc)
	{
		usage();
		exit(1);
	}
	(*i)++;
	number = ft_atoi(argv[*i]);
	if (number <= 0 || number > 4)
		usage();
	game->players[j].number = number;
	(*i)++;
	game->players[j].warrior_file = argv[*i];
	j++;
	(*i)++;
}

static void		set_player_normal(t_game *game, char *warrior_file)
{
	static int	j = 1;

	game->players[j - 1].number = j;
	game->players[j - 1].warrior_file = warrior_file;
	j++;
}

void			parse_options(int argc, char **argv, t_game *game)
{
	int		i;
	int		nb_players;

	i = 1;
	nb_players = 0;
	handle_dump_option(argc, argv, &i, game);
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			set_player_nbr(argc, argv, game, &i);
		else
			set_player_normal(game, argv[i++]);
		nb_players++;
	}
	game->nb_players = nb_players;
	game->nb_id = nb_players;
	i = -1;
	while (++i < game->nb_players)
	{
		game->players[i].first_pc = (game->players[i].number - 1) *
		(MEM_SIZE / game->nb_players);
		load_warrior(game, game->players[i].warrior_file, i);
	}
	load_first_processes(game);
	check_players(game);
}
