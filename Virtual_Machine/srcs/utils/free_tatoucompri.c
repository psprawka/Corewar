/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tatoucompri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 09:34:02 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:19:08 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_player(t_player *player)
{
	if (player)
	{
		if (player->warrior_file)
			free(player->warrior_file);
		free(player);
	}
}

void		free_game(t_game *game)
{
	if (game)
		ft_lstdel(&game->processes_stack, NULL);
}

void		free_op(t_op *op)
{
	if (op)
	{
		if (op->mnemonic)
			free(op->mnemonic);
		if (op->description)
			free(op->description);
		if (op->f)
			free(op->f);
	}
}

void		free_process(void *process)
{
	if (process)
		free(process);
}
