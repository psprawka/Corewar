/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:58:32 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:16:25 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_magic(int fd)
{
	unsigned char	buff[4];
	int				reader;

	reader = read(fd, buff, 4);
	if (reader < 0 || reader < 4 || change_endianness(COREWAR_EXEC_MAGIC) !=
	((uint32_t *)buff)[0])
	{
		ft_printf("Wrong magic number\n");
		exit(1);
	}
}

void	read_name(t_game *game, int fd, int player)
{
	char			buff[PROG_NAME_LENGTH + 1 + 4];
	int				reader;
	int				i;

	reader = read(fd, buff, PROG_NAME_LENGTH + 4);
	buff[reader] = 0;
	if (reader < 0 || reader < (PROG_NAME_LENGTH + 4) || ft_strequ(buff, ""))
	{
		ft_printf("Error in player %d warrior's name\n", player);
		exit(1);
	}
	i = 0;
	while (buff[i])
	{
		game->players[player].name[i] = buff[i];
		i++;
	}
	game->players[player].name[i] = 0;
}

void	read_prog_size(t_game *game, int fd, int player)
{
	unsigned char		buff[5];
	int					reader;
	uint32_t			size;

	reader = read(fd, buff, 4);
	buff[reader] = 0;
	if (reader < 0 || reader < 4)
	{
		ft_printf("Error in reading %d prog_size\n", player);
		exit(1);
	}
	if ((size = change_endianness(((int *)buff)[0])) > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: Champ size too big (%d > %d)", size, CHAMP_MAX_SIZE);
		exit(1);
	}
	game->players[player].size = size;
}

void	read_comment(t_game *game, int fd, int player)
{
	char			buff[COMMENT_LENGTH + 1 + 4];
	int				reader;
	int				i;

	reader = read(fd, buff, COMMENT_LENGTH + 4);
	buff[reader] = 0;
	if (reader < 0 || reader < COMMENT_LENGTH + 4 || ft_strequ(buff, ""))
	{
		ft_printf("Error in player %d warrior's comment\n", player);
		exit(1);
	}
	i = 0;
	while (buff[i])
	{
		game->players[player].comment[i] = buff[i];
		i++;
	}
}
