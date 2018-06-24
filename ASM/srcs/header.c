/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:13:26 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void	handle_header(void)
{
	g_file.header = ft_memalloc(sizeof(t_header));
	g_file.header->magic = COREWAR_EXEC_MAGIC;
	g_file.header->prog_size = 0;
}

void	write_header(void)
{
	int		l_endian;
	int		instr_size;
	char	nulls[4];

	bzero(nulls, 4);
	l_endian = g_file.header->magic;
	instr_size = g_file.header->prog_size;
	l_endian = (l_endian >> 24 & 0xff) | (l_endian >> 8 & 0xff00) |
	(l_endian << 8 & 0xff0000) | (l_endian << 24 & 0xff000000);
	instr_size = (instr_size >> 24 & 0xff) | (instr_size >> 8 & 0xff00) |
	(instr_size << 8 & 0xff0000) | (instr_size << 24 & 0xff000000);
	write(g_file.fd, (char *)&l_endian, 4);
	write(g_file.fd, g_file.header->prog_name, PROG_NAME_LENGTH);
	write(g_file.fd, nulls, 4);
	write(g_file.fd, (char *)&instr_size, 4);
	write(g_file.fd, g_file.header->comment, COMMENT_LENGTH);
	write(g_file.fd, nulls, 4);
}
