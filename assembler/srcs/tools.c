/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/02/19 10:12:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"

static t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	op_offset(t_file *file)
{
	int		i;
	
	i = 0;
	//	printf("%sTOKEN->name: [%s]%s\n", RED, TOKEN->name, NORMAL);
	if (ft_strcmp(TOKEN->name, "\0") == 0)
		return ;
	while (op_tab[i].name != NULL)
	{
		if (ft_strcmp(op_tab[i].name, TOKEN->name) == 0)
		{
			TOKEN->op_offset = i;
			file->header->prog_size += (op_tab[i].coding_byte == 1) ? 2 : 1;
			return ;
		}
		//		printf("op_tab[%d].name: [%s], line: [%s]\n", i, op_tab[i].name, TOKEN->name);
		i++;
	}
	printf("Invalid instruction [%s][%s]\n", TOKEN->line, TOKEN->name);
	exit(0);
}



char 	*readandstore(char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *buff;
	char *final = "\0";
	
	buff = ft_strnew(BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		final = ft_strjoin(final, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
//	printf("%sfile->data: [%s]%s\n", YELLOW, final, NORMAL);
	return (final);
}


void	rm_comment(t_file *file)
{
	int i;
	int	empty;
	
	i = 0;
//	empty= 0;
//	printf("%sBEFORE: LINE: [%s]\n%s", CYAN, TOKEN->line, NORMAL);
	while (TOKEN->line[i] != COMMENT_CHAR && TOKEN->line[i] != '\0')
//	{
//		if (TOKEN->line[i] != ' ' && TOKEN->line[i] != '\t')
//			empty++;
		i++;
//	}
	TOKEN->line[i] = '\0';
	
//	return (empty == 0 ? 1 : 0);
//	printf("%sAFTER: LINE: [%s]\n%s", CYAN, TOKEN->line, NORMAL);
}



int	gnl(t_file *file)
{
	int		size;
	char	*temp;
//	printf("GNL printf\n");
	temp = ft_strnew(BUFF_SIZE);
	TOKEN->line = ft_strnew(1);
	while ((file->data[file->offset] == ' ' || file->data[file->offset] == '\n'
		   || file->data[file->offset] == '\t') && file->data[file->offset] != '\0')
		file->offset++;
//	printf("file->offset: %d\n", file->offset);
//	printf("size = %d\n", size);
	while (file->data[file->offset] != '\n' && file->data[file->offset] != '\0')
	{
		size = 0;
		while (size < BUFF_SIZE && file->data[file->offset] != '\n' && file->data[file->offset] != '\0')
			temp[size++] = file->data[file->offset++];
		TOKEN->line = ft_strjoin(TOKEN->line, temp);
	}
	
//	if (rm_comment(file) == 1)
//		gnl(file);
	rm_comment(file);
	printf("%sLINE: [%s]\n%s", YELLOW, TOKEN->line, NORMAL);
	if (ft_strcmp(TOKEN->line, "\0") == 0)
		return (0);
//	printf("POLAAAA\n");
	return (1);
}






