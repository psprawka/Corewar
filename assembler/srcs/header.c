/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/02/19 10:12:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"

void	handle_header(t_file *file)
{
	static int i;
	char *com;
	char *name;
	name = ft_strnew(PROG_NAME_LENGTH + 1);
	com = ft_strnew(COMMENT_LENGTH + 1);
	file->header = (header_t *)malloc(sizeof(header_t));
	file->header->magic = COREWAR_EXEC_MAGIC;
	file->header->prog_size = 0;
	while(file->data[file->offset++] != '"') ;
	while(file->data[file->offset] != '"')
		name[i++] = file->data[file->offset++];
	i = 0;
	file->offset++;
	while(file->data[file->offset++] != '"') ;
	while(file->data[file->offset] != '"')
		com[i++] = file->data[file->offset++];
	file->offset++;
	strcpy(file->header->prog_name, name);
	strcpy(file->header->comment, com);
}

void	write_header(t_file *file)
{
	int		l_endian;
	int		instr_size;
	char	nulls[4];
	
	bzero(nulls, 4);
	l_endian = file->header->magic;
	instr_size = file->header->prog_size;
	l_endian = (l_endian >> 24 & 0xff) | (l_endian >> 8 & 0xff00)|
	(l_endian << 8 & 0xff0000) | (l_endian << 24 & 0xff000000);
	instr_size = (instr_size >> 24 & 0xff) | (instr_size >> 8 & 0xff00)|
	(instr_size << 8 & 0xff0000) | (instr_size << 24 & 0xff000000);
	write(file->fd, (char *)&l_endian, 4);
	write(file->fd, file->header->prog_name, PROG_NAME_LENGTH);
	write(file->fd, nulls, 4);
	write(file->fd, (char *)&instr_size, 4);
	write(file->fd, file->header->comment, COMMENT_LENGTH);
	write(file->fd, nulls, 4);
}
