/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:57:27 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:17:47 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			read_4_bytes(t_game *game, int pc)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = (game->arena.map[modulo(pc)] << 24);
	b = (game->arena.map[modulo(pc + 1)] << 16);
	c = (game->arena.map[modulo(pc + 2)] << 8);
	d = (game->arena.map[modulo(pc + 3)]);
	return (a | b | c | d);
}

short		read_2_bytes(t_game *game, int pc)
{
	int		a;
	int		b;

	a = (game->arena.map[modulo(pc)] << 8);
	b = (game->arena.map[modulo(pc + 1)]);
	return ((short)(a | b));
}

int			is_champ_number(t_game *game, int nbr)
{
	int i;

	i = 0;
	while (i < game->nb_players)
	{
		if (ft_abs(nbr) == game->players[i].number)
			return (1);
		i++;
	}
	return (-1);
}

int			get_value(t_game *game, t_process *process, unsigned char type,
	int position)
{
	int		address;

	if (type == REG_CODE)
		return (process->registers[game->arena.map[modulo(position)]]);
	else if (type == DIR_CODE)
	{
		return (read_4_bytes(game, modulo(position)));
	}
	address = read_2_bytes(game, modulo(position));
	address = modulo(process->pc + (address % IDX_MOD));
	return (read_4_bytes(game, address));
}

int			get_value_nomod(t_game *game, t_process *process,
	unsigned char type, int position)
{
	int		address;

	if (type == REG_CODE)
		return (process->registers[game->arena.map[modulo(position)]]);
	else if (type == DIR_CODE)
	{
		return (read_4_bytes(game, modulo(position)));
	}
	address = read_2_bytes(game, modulo(position));
	address = modulo(process->pc + address);
	return (read_4_bytes(game, address));
}
