/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:42:08 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:15:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		read_header(t_game *game, int fd, int player)
{
	read_magic(fd);
	read_name(game, fd, player);
	read_prog_size(game, fd, player);
	read_comment(game, fd, player);
}

static void		read_instructions(t_game *game, int fd, int player)
{
	unsigned char	buff[game->players[player].size + 2];
	int				reader;
	int				i;

	reader = read(fd, buff, game->players[player].size + 1);
	buff[reader] = 0;
	if (reader != (int)game->players[player].size)
	{
		ft_printf("Error: %s instructions size don't match prog_size\n",
			game->players[player].warrior_file);
		exit(1);
	}
	i = 0;
	while (i < reader)
	{
		game->arena.map[game->players[player].first_pc + i] = buff[i];
		i++;
	}
	i = 0;
}

void			load_warrior(t_game *game, char *warrior_file, int player)
{
	int		fd;

	if ((fd = open(warrior_file, O_RDONLY)) < 0)
	{
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
	read_header(game, fd, player);
	read_instructions(game, fd, player);
	if ((close(fd) < 0))
	{
		ft_printf("%s\n", strerror(errno));
		exit(1);
	}
}
