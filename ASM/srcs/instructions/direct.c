/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 06:04:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:59:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_direct(void)
{
	int		value;
	char	*token;

	value = 0;
	token = ft_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == ':')
		g_op_tab[TOKEN->op_offset].dir_size == 1 ? write_label(2) : write_label(4);
	else if (g_op_tab[TOKEN->op_offset].dir_size == 1)
	{
		value = ft_atoi(token) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
		write(g_file.fd, (char *)&value, 2);
		g_file.header->prog_size += 2;
	}
	else
	{
		value = ft_atoi(token) % 4294967296;
		value = (value >> 24 & 0xff) | (value >> 8 & 0xff00) |
		(value << 8 & 0xff0000) | (value << 24 & 0xff000000);
		write(g_file.fd, (char *)&value, 4);
		g_file.header->prog_size += 4;
	}
	free(token);
}