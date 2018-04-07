/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 21:34:03 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 07:21:19 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		aff(t_game *game, t_process *process)
{
	unsigned char	c;

	process->pc = modulo(process->pc + 2);
	c = (unsigned char)(process->registers[modulo(process->pc)]) % 256;
	process->pc = modulo(process->pc + 1);
	ft_printf("(c%d) Aff %c\n", game->cycle_so_far, c);
}
