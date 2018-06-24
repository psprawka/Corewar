/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 06:00:36 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:59:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_indirect(void)
{
	int		value;
	char	*number;

	value = 0;
	number = ft_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == LABEL_CHAR)
		write_label(2);
	else
	{
		value = ft_atoi(number) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
		write(g_file.fd, (char *)&value, 2);
		g_file.header->prog_size += 2;
	}
}