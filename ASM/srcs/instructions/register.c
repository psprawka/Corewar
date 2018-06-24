/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 05:53:00 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:13:24 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_register(void)
{
	int		value;
	char	*number;

	value = 0;
	number = ft_strsub(TOKEN->line, TOKEN->pos, 4);
	if ((value = ft_atoi(number)) > 99 || value < 0)
	{
		error(6, NULL, true);
		exit(0);
	}
	write(g_file.fd, (char *)&value, 1);
	g_file.header->prog_size += 1;
	free(number);
}
