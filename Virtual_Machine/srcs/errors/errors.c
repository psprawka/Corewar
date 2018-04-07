/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:19:55 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/08 02:48:04 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			usage(void)
{
	ft_printf("Usage: ./corewar [-dump nbr_cycles]");
	ft_printf(" [[-n number] champion1.cor] ...\n");
	ft_printf("(only use -n with 4 players and numbers in {0, 1, 2, 3})\n");
	exit(1);
}
