/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:20:06 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "op.h"
# include "libft.h"

# define LABEL_MAX_SIZE 		300
# define LINE_MAX_SIZE 			300
# define INSTRUCTION_MAX_SIZE 	5
# define TOKEN 					g_file.token
# define DATA					g_file.data

# define NORMAL		"\x1B[0m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGNETA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"

# define BUFF_SIZE	1000

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct	s_token
{
	char		*name;
	int			op_offset;
	char		*line;
	int			bytecode;
	int			icode;
	int			pos;
}				t_token;

typedef struct	s_file
{
	int			fd;
	t_header 	*header;
	char		*data;
	char		*name;
	int			cur_line;
	int			offset;
	int			op_offset;
	char		*line;
	char		**labels;
	int			labels_nb;
	t_token		*token;

}				t_file;

typedef struct	s_op
{
	char	*name;
	int		arg_nb;
	int		args[4];
	int		op_code;
	int		cycle;
	char	*des;
	int		coding_byte;
	int		dir_size;
}				t_op;

t_op			g_op_tab[17];
t_file			g_file;

/* tools */
char 	*readandstore(char *filename);
void	op_offset(void);
int		gnl(void);

/* labels */
void	add_label(char *label);
void	vargs(void);
void	vname_aux(void);
void	vname(void);
void	handle_labels(void);

/* header */
int 	parse_name(int i);
int		parse_comment(int i);
void	handle_header(void);
void	write_header(void);

/* prog_size */
int		varg(char t, int arg);
void	prog_size(int cycle);

/* terence norm */

void	get_name(void);
void	write_label_aux(int size, int *position, int i);
void	write_label(int size);

void	bytecode(int pos);
void	reg(void);
void	indir(void);
void	dir(void);
void	handle_instructions(void);



/*
**	instructions/
*/
void	get_register(void);
void	get_indirect(void);
void	get_direct(void);
// void	get_commands_values(void);
void	get_args(void);
void	handle_instructions(void);

#endif