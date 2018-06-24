/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:12:23 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_label(char *label)
{
	char	*buff;

	buff = ft_strnew(1000);
	ft_strcpy(buff, label);
	ft_strcat(buff, ":");
	ft_strcat(buff, ft_itoa(g_file.header->prog_size + 1));
	g_file.labels[g_file.labels_nb] = ft_strdup(buff);
	g_file.labels_nb++;
}

void	vargs(void)
{
	int		cycle;

	cycle = 0;
	while (cycle < g_op_tab[TOKEN->op_offset].arg_nb)
	{
		while (IS_WHITE(TOKEN->line[TOKEN->pos]))
			TOKEN->pos++;
		if (ft_strchr("r%:-123456789", TOKEN->line[TOKEN->pos]))
		{
			prog_size(cycle);
			while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
				TOKEN->line[TOKEN->pos])
				;
		}
		else
		{
			error(5, TOKEN->name, true);
			exit(0);
		}
		cycle++;
	}
}

void	vname(void)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;

	index = 0;
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] && !IS_WHITE(TOKEN->line[TOKEN->pos]))
	{
		if (ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
			tmp[index++] = TOKEN->line[TOKEN->pos++];
		else if (TOKEN->line[TOKEN->pos] == ':')
			break ;
		else
		{
			error(4, NULL, true);
			exit(0);
		}
	}
	tmp[index] = '\0';
	if (TOKEN->line[TOKEN->pos] == ':')
	{
		add_label(tmp);
		TOKEN->pos++;
		vname();
	}
	else
		TOKEN->name = ft_strdup(tmp);
}

void	handle_labels(void)
{
	static int	line;

	g_file.token = ft_memalloc(sizeof(t_token));
	g_file.labels = ft_memalloc(sizeof(char *) * 300);
	TOKEN->name = ft_strnew(5);
	
	while (g_file.data[g_file.offset])
	{
		TOKEN->pos = 0;
		gnl();
		if (line < 2 && ft_strcmp(TOKEN->line, "\0"))
			line++ == 0 ? parse_name() : parse_comment();
		else if (ft_strcmp(TOKEN->line, "\0"))
		{
			vname();
			get_op_offset();
			vargs();
		}
	}
}


void	write_label_aux(int size, int *position, int i)
{
	char	*number;

	number = ft_strsub(g_file.labels[i], ft_strlen_chr(g_file.labels[i], ':') + 1, 100);
	*position = ft_atoi(number) - TOKEN->icode;
	if (size == 2 && (g_file.header->prog_size += 2))
	{
		*position = (*position >> 8 & 0xff) | (*position << 8 & 0xff00);
		write(g_file.fd, (char *)&(*position), 2);
	}
	else if (size == 4 && (g_file.header->prog_size += 4))
	{
		*position = (*position >> 24 & 0xff) | (*position >> 8 & 0xff00) |
		(*position << 8 & 0xff0000) | (*position << 24 & 0xff000000);
		write(g_file.fd, (char *)&(*position), 4);
	}
}

void	write_label(int size)
{
	char	*label;
	char	*array_label;
	int		position;
	int		i;

	i = 0;
	position = TOKEN->pos + 1;
	label = ft_strnew(LABEL_MAX_SIZE);
	while (TOKEN->line[position] && TOKEN->line[position] != ',' &&
		!IS_WHITE(TOKEN->line[position]))
		label[i++] = TOKEN->line[position++];
	i = 0;
	while (i < g_file.labels_nb)
	{
		array_label = ft_strsub(g_file.labels[i], 0,
			ft_strlen_chr(g_file.labels[i], ':'));
		if (ft_strcmp(array_label, label) == 0)
		{
			write_label_aux(size, &position, i);
			return ;
		}
		i++;
	}
	error(3, label, true);
	exit(0);
}