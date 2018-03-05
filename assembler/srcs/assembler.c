/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/02/19 10:12:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
//typedef struct	s_op
//{
//	char	*name;
//	int		arg_nb;
//	int		args[4];
//	int		op_code;
//	int		cycle;
//	char	*des;
//	int		coding_byte;
//	int		dir_size;
//}				t_op;

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


void	get_name(t_file *file)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;
	
	
	printf("GET NAMEEEEE NAMEEEE\n");
//		printf("BEFORE: %sTOKEN->pos: [%c]\n%s", GREEN, TOKEN->line[TOKEN->pos], NORMAL);
//	printf("%stmp: [%s], TOKEN->name: [%s]%s\n",YELLOW, tmp, TOKEN->name, NORMAL);
	index = 0;
	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
		TOKEN->pos++;
//	printf("%sBEFORE tmp: [%s], TOKEN->name: [%s]%s\n",YELLOW, tmp, TOKEN->name, NORMAL);
//		printf("AFTER: %sTOKEN->pos: [%c]\n%s", GREEN, TOKEN->line[TOKEN->pos], NORMAL);
	while (TOKEN->line[TOKEN->pos] != '\0' && ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
			tmp[index++] = TOKEN->line[TOKEN->pos++];
	tmp[index] = '\0';
	if (TOKEN->line[TOKEN->pos] == '\0')
		TOKEN->op_offset = -1;
	printf("up to hereee\n");
	if (TOKEN->line[TOKEN->pos] == ':')
	{
		TOKEN->pos++;
		get_name(file);
//		printf("%sAFTER tmp: [%s], TOKEN->name: [%s]%s\n",YELLOW, tmp, TOKEN->name, NORMAL);
	}
	else
	{
		TOKEN->name = ft_strdup(tmp);
//		op_tab[TOKEN->op_offset].op_code <<= 16;
//		printf("%stmp: [%s], TOKEN->name: [%s], op_code: [%d]%s\n",GREEN, tmp, TOKEN->name, NORMAL);
	}
}




void	write_label(t_file *file, int size, char *token)
{
	char	*label;
	char	*array_label;
	char	*number;
	int		position;
	int		i;

	i = 0;
	position = TOKEN->pos + 1;
	label = ft_strnew(LABEL_MAX_SIZE);
	while (TOKEN->line[position] != '\0' && TOKEN->line[position] != ',' && TOKEN->line[position] != '\t' && TOKEN->line[position] != ' ')
		label[i++] = TOKEN->line[position++];
	i = 0;
	while (i < file->labels_nb)
	{
		
		array_label = ft_strsub(file->labels[i], 0, ft_strlen_chr(file->labels[i], ':'));
		printf("%sLABEL SENT: [%s], LABEL in an array: [%s]\n%s", MAGNETA, label, array_label, NORMAL);
		if (ft_strcmp(array_label, label) == 0)
		{
			number = ft_strsub(file->labels[i], ft_strlen_chr(file->labels[i], ':') + 1, 100);
			position = ft_atoi(number) - file->header->prog_size;
//			printf("%spositions: array %ld, current %d\n", MAGNETA, ft_atoi(number),file->header->prog_size);
			if (size == 2 && (file->header->prog_size += 2))
			{
				position = (position >> 8 & 0xff) | (position << 8 & 0xff00);
				write(file->fd, (char *)&position, 2);
			}
			else if (size == 4 && (file->header->prog_size += 4))
			{
				position = (position >> 24 & 0xff) | (position >> 8 & 0xff00) |
				(position << 8 & 0xff0000) | (position << 24 & 0xff000000);
				write(file->fd, (char *)&position, 4);
			}
			return ;
		}
		i++;
	}
	
	printf("No such label %s while attempting to dereference\n", label);
	exit (0);
}


void	reg(t_file *file)
{
	int		value;
	char	*number;
	
	value = 0;
	number = ft_strsub(TOKEN->line, TOKEN->pos, 4);
	if ((value = ft_atoi(number)) > 99 || value < 0)
	{
		printf("Syntax error INSTRUCTION \"r\"\n");
		exit (0);
	}
//	printf("REG!\n");
//	if (ft_strcmp(TOKEN->name,"st") == 0)
	write(file->fd, (char *)&value, 1);
	file->header->prog_size += 1;
	free(number);
}


void	dir(t_file *file)
{
	int		value;
	char	*token;
	
	value = 0;
	token = ft_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == ':')
		op_tab[TOKEN->op_offset].dir_size == 1 ? write_label(file, 2, token) : write_label(file, 4, token);
	else if (op_tab[TOKEN->op_offset].dir_size == 1)
	{
		value = ft_atoi(token) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
//		if (ft_strcmp(TOKEN->name,"sti") == 0)
			write(file->fd, (char *)&value, 2);
		file->header->prog_size += 2;
	}
	else
	{
		value = ft_atoi(token) % 4294967296;
		value = (value >> 24 & 0xff) | (value >> 8 & 0xff00) |
				(value << 8 & 0xff0000) | (value << 24 & 0xff000000);
//		if (ft_strcmp(TOKEN->name,"sti") == 0)
		write(file->fd, (char *)&value, 4);
		file->header->prog_size += 4;
		printf("prog_size: %d\n)", file->header->prog_size);
	}
	free(token);
}

void	indir(t_file *file)
{
	int		value;
	char	*number;
	
	value = 0;
	number = ft_strsub(TOKEN->line, TOKEN->pos, 64);
	if (TOKEN->line[TOKEN->pos] == ':')
		write_label(file, 2, number);
	else
	{
		value = ft_atoi(number) % 65536;
		value = (value >> 8 & 0xff) | (value << 8 & 0xff00);
//		value <<= 16;
		write(file->fd, (char *)&value, 2);
		file->header->prog_size += 2;
	}
}



void	get_args(t_file *file)
{
	while (TOKEN->line[TOKEN->pos] != '\0')
	{
		while (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t')
			TOKEN->pos++;

		if (TOKEN->line[TOKEN->pos] == 'r' && ++TOKEN->pos)
		{
			reg(file);
		}
		else if (TOKEN->line[TOKEN->pos] == '%' && ++TOKEN->pos)
		{
			dir(file);
		}
		else if (TOKEN->line[TOKEN->pos] == ':' || ft_isdigit(TOKEN->line[TOKEN->pos]))
		{
			indir(file);
		}
		
		while (TOKEN->line[TOKEN->pos++] != ',' && TOKEN->line[TOKEN->pos] != '\0')
			;
	}
}


void	bytecode(t_file *file, int pos)
{
	int		bits;
	
	bits = 0;
	while (TOKEN->line[pos] != '\0')
	{
//		printf("%s\n\nBEFORE TOKEN->line[pos]: [%c]%s\n", CYAN, TOKEN->line[pos], NORMAL);
		while (TOKEN->line[pos] == ' ' || TOKEN->line[pos] == '\t')
			pos++;
//		printf("%sAFTER TOKEN->line[pos]: [%c]%s\n", CYAN, TOKEN->line[pos], NORMAL);
//		printf("%sBYTECODE!!!!!!\n%s", CYAN, NORMAL);
		if (TOKEN->line[pos] == 'r')
			TOKEN->bytecode |= REG_CODE;
		else if (TOKEN->line[pos] == '%')
			TOKEN->bytecode |= DIR_CODE;
		else if (TOKEN->line[pos] == ':' || ft_isdigit(TOKEN->line[pos]))
			TOKEN->bytecode |= IND_CODE;
		
		TOKEN->bytecode <<= 2;
		bits += 2;
//		printf("%sSUMMARY bytecode = [%d] bits = %d\n%s", CYAN, TOKEN->bytecode, bits, NORMAL);
		while (TOKEN->line[pos++] != ',' && TOKEN->line[pos] != '\0') ;
	}
//	printf("%sFINAL BEFORE bytecode = [%d] bits = %d\n%s", CYAN, TOKEN->bytecode, bits, NORMAL);
	while (bits++ < 6)
		TOKEN->bytecode <<= 1;
	
//	printf("%sFINAL AFTER bytecode = [%d] bits = %d\n%s", CYAN, TOKEN->bytecode, bits, NORMAL);
//	if (ft_strcmp(TOKEN->name,"live") == 0)
		write(file->fd, &(TOKEN->bytecode), 1);
	
//	file->header->prog_size += 1;
	
//	printf("BYTE: prog_size: %d\n)", file->header->prog_size);
}


void	handle_instructions(t_file *file)
{
	
//	printf("BEG: prog_size: %d\n)", file->header->prog_size);
	while (file->data[file->offset] != '\0')
	{
		printf("HEREE\n");
		
		TOKEN->pos = 0;
//		printf("HERE2\n");
//		if (!gnl(file))
//		{
//			printf("RETURN\n");
//			return ;
//		}
		gnl(file);
		
//		printf("GET: prog_size: %d\n)", file->header->prog_size);
		if (ft_strcmp(TOKEN->line, "\0"))
		{
			printf("HERE3\n");
			get_name(file);
			printf("POLA\n");
			printf("TOKEN->name [%s]\n", TOKEN->name);
//			printf("GET_NAME: prog_size: %d\n)", file->header->prog_size);
			op_offset(file);
			printf("TOKEN->line [%s]\n", TOKEN->line);
			TOKEN->bytecode = 0;
//			if (ft_strcmp(TOKEN->name,"live") == 0)
			if (TOKEN->op_offset != -1)
			{
				printf("TOKEN->name [%s]\n", TOKEN->name);
				write(file->fd, (char *)&(op_tab[TOKEN->op_offset].op_code), 1);
//				printf("NAME: prog_size: %d\n)", file->header->prog_size);
			}
			if (op_tab[TOKEN->op_offset].coding_byte)
				bytecode(file, TOKEN->pos);
	//		printf("HERE4\n");
			
	//		printf("HERE5\n");
	//		if (TOKEN->name != "\0")
	//		{
	//			printf("HERE\n");
			get_args(file);
		}
	//		}
//		printf("HERE6\n");
//		printf("%sfile->data[%d]: [%c]%s\n", RED, file->offset, file->data[file->offset],  NORMAL);
}
}


void	assembler(char *data, char *filename)
{
	t_file	*file;
	
	file = (t_file *)malloc(sizeof(t_file));
	file->data = data;
	file->offset = 0;
	handle_header(file);
	file->name = ft_strncpy(filename, ft_strlen(filename) - 2);
	file->fd = open(ft_strjoin(file->name, ".corx"), O_CREAT | O_WRONLY, 0644);
	printf("HERE\n");
	handle_labels(file);
		printf("prog_size [%d]\n", file->header->prog_size);
	write_header(file);
	file->header->prog_size = 0;
	TOKEN->op_offset = -1;
	file->offset = 0;
	printf("%s\n\n\n\nINSTRUCTIONS:\n%s", CYAN, NORMAL);
	handle_instructions(file);
}


int		main(int ac, char **av)
{
	char *data;
	
	if (ac == 1)
	{
		printf("Usage: ./asm <sourcefile.s>\n");
		return (1);
	}
	else
	{
		data = readandstore(av[1]);
		assembler(data, av[1]);
		
	
	}
	return (0);
}
