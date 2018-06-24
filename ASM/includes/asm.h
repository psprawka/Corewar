/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:20:44 by psprawka         ###   ########.fr       */
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
# include "asm_structs.h"

# define LABEL_MAX_SIZE 		300
# define LINE_MAX_SIZE 			300
# define INSTRUCTION_MAX_SIZE 	5
# define TOKEN 					g_file.token
# define DATA					g_file.data
# define BUFF_SIZE				1000

extern t_op						g_op_tab[17];
extern t_file					g_file;


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