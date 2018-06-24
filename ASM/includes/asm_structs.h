/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 10:19:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:21:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCTS_H
# define ASM_STRUCTS_H

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

#endif
