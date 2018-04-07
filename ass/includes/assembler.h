/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 07:00:38 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../includes/op.h"
# include <stdio.h>
# include <string.h>

# define LABEL_MAX_SIZE 		300
# define LINE_MAX_SIZE 			300
# define INSTRUCTION_MAX_SIZE 	5
# define TOKEN 					file->token
# define DATA					file->data

# define NORMAL		"\x1B[0m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGNETA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"


typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;

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
	header_t 	*header;
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

//extern t_op op_tab[17];

t_op			g_op_tab[17];

/* ft_libft */
char		*ftt_strsub(char *s, int start, size_t len);
int			ftt_strncmp(char *s1, char *s2, int n);
void		*ftt_memset(void *s, int c, size_t n);
char		*ftt_strchr(char *str, char to_find);
int			ftt_strlen_chr(char *str, char c);
void		ftt_strcpy(char *dest, char *src);
char 		*ftt_strncpy(char *str, int size);
char		*ftt_strjoin(char *s1, char *s2);
int			ftt_strcmp(char *s1, char *s2);
void		ftt_bzero(void *s, size_t n);
char		*ftt_strnew(size_t size);
char		*ftt_strdup(char *src);
int 		ftt_strlen(char *str);
int			ftt_isdigit(char c);
char    	*ftt_itoa(int nbr);
long int	ftt_atoi(char *s);

/* tools */
char 	*readandstore(char *filename);
void	op_offset(t_file *file);
int		gnl(t_file *file);

/* labels */
void	handle_labels(t_file *file);
void	vname(t_file *file);
void	vargs(t_file *file);
void	add_label(t_file *file, char *label);

/* header */
int 	pname(t_file *file, int i);
int		pcomment(t_file *file, int i);
void	handle_header(t_file *file);
void	write_header(t_file *file);

/* prog_size */
int		varg(t_file *file, char t, int arg);
void	prog_size(t_file *file, int cycle);

/* terence norm */

void	get_name(t_file *file);
void	write_label_aux(t_file *file, int size, int *position, int i);
void	write_label(t_file *file, int size);
void	dir(t_file *file);
void	indir(t_file *file);
void	handle_instructions(t_file *file);
void	get_args(t_file *file);
void	bytecode(t_file *file, int pos);
void	reg(t_file *file);
