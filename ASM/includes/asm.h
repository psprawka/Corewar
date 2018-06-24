/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 09:58:45 by psprawka         ###   ########.fr       */
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
# include <errno.h>
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
	char		*name;				/* instruction's name */
	int			op_offset;			/* position in g_op_table */ 
	char		*line;				/* one line from a file at the time */
	int			bytecode;			/* if exists, bytecode number */
	int			icode;				/* something I use for label's position, I wish I knew for what */
	int			pos;				/* line[pos] <- current offset */
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


/*
**	tools.c
*/
void		get_op_offset(void);
void		get_byte_code(int pos);
int			error(int errnb, char *msg, bool ifailure);



/*
**	read_data.c
*/
char 		*readandstore(char *filename);
int			gnl(void);


/* labels */
void	add_label(char *label);
void	vargs(void);
void	vname_aux(void);
void	vname(void);
void	handle_labels(void);

/* header */
int 	parse_name(void);
int		parse_comment(void);
void	handle_header(void);
void	write_header(void);

/* prog_size */
int		varg(char t, int arg);
void	prog_size(int cycle);

/* terence norm */
void	write_label_aux(int size, int *position, int i);
void	write_label(int size);

void	bytecode(int pos);


/*
**	instructions/
*/
void			get_register(void);
void			get_indirect(void);
void			get_direct(void);
static void		get_instruction_name(void);
static void		get_instruction_values(void);
void			handle_instructions(void);

#endif