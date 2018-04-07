/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 06:39:23 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

int		pname(t_file *file, int i)
{
	char *name;

	name = ftt_strnew(PROG_NAME_LENGTH);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' '
	|| TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	if (ftt_strncmp(&(TOKEN->line[TOKEN->pos]), NAME_CMD_STRING,
	ftt_strlen(NAME_CMD_STRING)))
		return (-1);
	TOKEN->pos += ftt_strlen(NAME_CMD_STRING);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' '
	|| TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	if (TOKEN->line[TOKEN->pos++] != '"')
		return (-1);
	while (TOKEN->line[TOKEN->pos] != '"')
		name[i++] = TOKEN->line[TOKEN->pos++];
	TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' '
	|| TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	if (DATA[TOKEN->pos++] != '\n')
		return (-1);
	ftt_strcpy(file->header->prog_name, name);
	return (0);
}

int		pcomment(t_file *file, int i)
{
	char	*com;

	com = ftt_strnew(COMMENT_LENGTH);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == '\n'
	|| TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	if (ftt_strncmp(&(TOKEN->line[TOKEN->pos]), COMMENT_CMD_STRING,
	ftt_strlen(COMMENT_CMD_STRING)))
		return (-1);
	TOKEN->pos += ftt_strlen(COMMENT_CMD_STRING);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' '
	|| TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	if (TOKEN->line[TOKEN->pos++] != '"')
		return (-1);
	while (TOKEN->line[TOKEN->pos] != '"')
		com[i++] = TOKEN->line[TOKEN->pos++];
	TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' '
	|| TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	if (TOKEN->line[TOKEN->pos] != '\0')
		return (-1);
	ftt_strcpy(file->header->comment, com);
	return (0);
}

void	handle_header(t_file *file)
{
	file->header = (header_t *)malloc(sizeof(header_t));
	file->header->magic = COREWAR_EXEC_MAGIC;
	file->header->prog_size = 0;
}

void	write_header(t_file *file)
{
	int		l_endian;
	int		instr_size;
	char	nulls[4];

	bzero(nulls, 4);
	l_endian = file->header->magic;
	instr_size = file->header->prog_size;
	l_endian = (l_endian >> 24 & 0xff) | (l_endian >> 8 & 0xff00) |
	(l_endian << 8 & 0xff0000) | (l_endian << 24 & 0xff000000);
	instr_size = (instr_size >> 24 & 0xff) | (instr_size >> 8 & 0xff00) |
	(instr_size << 8 & 0xff0000) | (instr_size << 24 & 0xff000000);
	write(file->fd, (char *)&l_endian, 4);
	write(file->fd, file->header->prog_name, PROG_NAME_LENGTH);
	write(file->fd, nulls, 4);
	write(file->fd, (char *)&instr_size, 4);
	write(file->fd, file->header->comment, COMMENT_LENGTH);
	write(file->fd, nulls, 4);
}
