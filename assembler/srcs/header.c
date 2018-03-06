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


int 	pname(t_file *file, int i)
{
	char *name;
	printf("IN NAME\n");
	name = ft_strnew(PROG_NAME_LENGTH);
	printf("1: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == '\n' ||
					TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
	TOKEN->pos++;
	printf("2: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	if (ft_strncmp(&(TOKEN->line[TOKEN->pos]), NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		printf("HERE11111\n");
		return (-1);
	}
	TOKEN->pos += ft_strlen(NAME_CMD_STRING);
	
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	printf("3: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	if (DATA[TOKEN->pos++] != '"')
	{
		printf("HERE22222\n");
		return (-1);
	}
	printf("4: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	while (TOKEN->line[TOKEN->pos] != '"')
		name[i++] = file->data[TOKEN->pos++];
	TOKEN->pos++;
	printf("5: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	printf("6: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	if (DATA[TOKEN->pos++] != '\n')
	{
		printf("HERE33333\n");
		return (-1);
	}
	printf("7: [%c] BEFORE NAME name = [%s]\n", TOKEN->line[TOKEN->pos], name);
	ft_strcpy(file->header->prog_name, name);
//	free(name);
	printf("8: [%c] BEFORE NAME name = [%s]\n", TOKEN->line[TOKEN->pos], file->header->prog_name);
	return (0);
}


int		pcomment(t_file *file, int i)
{
	char *com;
	printf("IN COMMENT\n");
	com = ft_strnew(COMMENT_LENGTH);
	printf("1: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == '\n' || TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	printf("2: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	if (ft_strncmp(&(TOKEN->line[TOKEN->pos]), COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		printf("HERE44444\n");
		return (-1);
	}
	
	TOKEN->pos += ft_strlen(COMMENT_CMD_STRING);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	printf("3: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	
	if (file->data[TOKEN->pos++] != '"')
		return (-1);
	printf("4: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	while(TOKEN->line[TOKEN->pos] != '"')
		com[i++] = file->data[TOKEN->pos++];
	TOKEN->pos++;
	printf("5: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	while (TOKEN->line[TOKEN->pos] != '\0' && (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'))
		TOKEN->pos++;
	printf("6: [%c] BEFORE NAME\n", TOKEN->line[TOKEN->pos]);
	if (TOKEN->line[TOKEN->pos] != '\n')
	{
		printf("HERE55555\n");
		return (-1);
	}
//	if (DATA[TOKEN->pos+] != '"')
//	{
//		printf("HERE22222\n");
//		return (-1);
//	}
	printf("7: [%c] BEFORE NAME name = [%s]\n", TOKEN->line[TOKEN->pos], com);
	ft_strcpy(file->header->comment, com);
	printf("8: [%c] BEFORE NAME name = [%s]\n", TOKEN->line[TOKEN->pos], file->header->comment);
	return (0);
}



void	handle_header(t_file *file)
{
	file->header = (header_t *)malloc(sizeof(header_t));
	file->header->magic = COREWAR_EXEC_MAGIC;
	file->header->prog_size = 0;
	printf("BEFORE NAME\n");
//	if (pname(file, 0) || pcomment(file, 0))
//	{
//		printf("Lexical error\n");
//		exit (0);
//	}
}

void	write_header(t_file *file)
{
	int		l_endian;
	int		instr_size;
	char	nulls[4];
	
	bzero(nulls, 4);
	l_endian = file->header->magic;
	instr_size = file->header->prog_size;
	printf("instr: [%d]\n", instr_size);
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
