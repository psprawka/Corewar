/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 06:38:43 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

void	add_label(t_file *file, char *label)
{
	int	current;

	current = 0;
	label = ftt_strjoin(label, ":");
	label = ftt_strjoin(label, ftt_itoa(file->header->prog_size + 1));
	file->labels[file->labels_nb] = ftt_strnew(ftt_strlen(label));
	file->labels[file->labels_nb] = label;
	file->labels_nb++;
}

void	vargs(t_file *file)
{
	int		cycle;

	cycle = 0;
	while (cycle < g_op_tab[TOKEN->op_offset].arg_nb)
	{
		while (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'
		|| TOKEN->line[TOKEN->pos] == '\n')
			TOKEN->pos++;
		if (ftt_strchr("r%:-123456789", TOKEN->line[TOKEN->pos]))
		{
			prog_size(file, cycle);
			while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
				TOKEN->line[TOKEN->pos] != '\0')
				;
		}
		else
		{
			ft_printf("Invalid parameter for instruction %s\n", TOKEN->name);
			exit(0);
		}
		cycle++;
	}
}

void	vname_aux(void)
{
	ft_printf("Lexical error\n");
	exit(0);
}

void	vname(t_file *file)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;

	index = 0;
	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] != ' ' && TOKEN->line[TOKEN->pos] != '\t' &&
		TOKEN->line[TOKEN->pos] != '\0')
		if (ftt_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
			tmp[index++] = TOKEN->line[TOKEN->pos++];
		else if (TOKEN->line[TOKEN->pos] == ':')
			break ;
		else
			vname_aux();
	tmp[index] = '\0';
	if (TOKEN->line[TOKEN->pos] == ':')
	{
		add_label(file, tmp);
		TOKEN->pos++;
		vname(file);
	}
	else
		TOKEN->name = ftt_strdup(tmp);
}

void	handle_labels(t_file *file)
{
	static int	line;

	file->token = (t_token *)malloc(sizeof(t_token));
	file->labels = (char **)malloc(sizeof(char *) * 300);
	TOKEN->name = ftt_strnew(5);
	while (file->data[file->offset] != '\0')
	{
		TOKEN->pos = 0;
		gnl(file);
		if (line < 2 && ftt_strcmp(TOKEN->line, "\0"))
			line++ == 0 ? pname(file, 0) : pcomment(file, 0);
		else if (ft_strcmp(TOKEN->line, "\0"))
		{
			vname(file);
			op_offset(file);
			vargs(file);
		}
	}
}
