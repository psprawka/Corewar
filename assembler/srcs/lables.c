/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lables.c	                                        :+:      :+:    :+:   */
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

void	add_label(t_file *file, char *label)
{
	int	current;
	
	current = 0;
	label = ft_strjoin(label, ":");
	label = ft_strjoin(label, ft_itoa(file->header->prog_size + 1));
	file->labels[file->labels_nb] = ft_strnew(ft_strlen(label));
	file->labels[file->labels_nb] = label;
	//	printf("%sIM ADDING A LABEL! [%s]%s\n", MAGNETA, label, NORMAL);
	file->labels_nb++;
}

void	vargs(t_file *file) //validate args
{
	int		cycle;
	
	cycle = 0;
	while (cycle < op_tab[TOKEN->op_offset].arg_nb)
	{
		//		printf("%sCYCLE %d, MAX ARGS %d\n%s", CYAN, cycle, op_tab[TOKEN->op_offset].arg_nb, NORMAL);
		while (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			   TOKEN->line[TOKEN->pos] == '\n')
			TOKEN->pos++;
		//		printf("%sLine: [%s], char: [%c]\n%s", CYAN, TOKEN->line, TOKEN->line[TOKEN->pos], NORMAL);
		if (ft_strchr("r%:123456789", TOKEN->line[TOKEN->pos]))
		{
			prog_size(file, cycle);
			while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR && TOKEN->line[TOKEN->pos] != '\0') ;
		}
		else
		{
			printf("Invalid parameter for instruction %s\n", TOKEN->name);
			exit (0);
		}
		cycle++;
	}
}

void	vname(t_file *file) //validate name
{
	char	tmp[LINE_MAX_SIZE];
	int		index;
	
	index = 0;
//		printf("HERE3.1\n");
//		printf("BEFORE: %sTOKEN->pos: [%c]\n%s", GREEN, TOKEN->line[TOKEN->pos], NORMAL);
	
	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
		TOKEN->pos++;
	
//		printf("AFTER: %sTOKEN->pos: [%c]\n%s", GREEN, TOKEN->line[TOKEN->pos], NORMAL);
	
	while (TOKEN->line[TOKEN->pos] != ' ' && TOKEN->line[TOKEN->pos] != '\t' &&
		   TOKEN->line[TOKEN->pos] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
			tmp[index++] = TOKEN->line[TOKEN->pos++];
		else if (TOKEN->line[TOKEN->pos] == ':')
			break ;
		else
		{
			printf("Lexical error\n");
			exit(0);
		}
	}
//	printf("HELLO\n");
	tmp[index] = '\0';
//	printf("HELLO\n");
	if (TOKEN->line[TOKEN->pos] == ':')
	{
//		printf("HELLO       efsfs \n");
		add_label(file, tmp);
		TOKEN->pos++;
//		printf("HELLOadsdsa\n");
		vname(file);
	}
	else
//	{
//		printf("HELLO1\n");
		TOKEN->name = ft_strdup(tmp);
//				printf("%stmp: [%s], TOKEN->name: [%s]%s\n",GREEN, tmp, TOKEN->name, NORMAL);
//	}
}

void	handle_labels(t_file *file)
{
	file->token = (t_token *)malloc(sizeof(t_token));
	file->labels = (char **)malloc(sizeof(char *) * 300);
	TOKEN->name = ft_strnew(5);
	while (file->data[file->offset] != '\0')
	{
		TOKEN->pos = 0;
		printf("HERE2\n");
//		if (!gnl(file))
//		{
			printf("RETURN\n");
//			return ;
//		}
		gnl(file);
		
		if (ft_strcmp(TOKEN->line, "\0"))
		{
		
			vname(file);
			printf("HERE3\n");
			op_offset(file);
			printf("HERE3\n");
			vargs(file);
			printf("HERE3\n");
		}
		printf("HERE6\n");
//		printf("%sfile->data[%d]: [%c]%s\n", RED, file->offset, file->data[file->offset],  NORMAL);
	}
}

