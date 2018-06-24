/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:16:25 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_label(char *label)
{
	int	current;
	
	current = 0;
	label = ft_strjoin(label, ":", 0);
	label = ft_strjoin(label, ft_itoa(g_file.header->prog_size + 1), 0);
	g_file.labels[g_file.labels_nb] = ft_strnew(ft_strlen(label));
	g_file.labels[g_file.labels_nb] = label;
	g_file.labels_nb++;
}

// void	add_label(char *label)
// {
// 	char	*buff;

// 	buff = ft_strnew(1000);
// 	ft_strcpy(buff, label);
// 	ft_strcat(buff, ":");
// 	ft_strcat(buff, ft_itoa(g_file.header->prog_size + 1));
// 	g_file.labels[g_file.labels_nb] = ft_strdup(label);
// 	g_file.labels_nb++;
// }

void	vargs(void)
{
	int		cycle;

	cycle = 0;
	while (cycle < g_op_tab[TOKEN->op_offset].arg_nb)
	{
		while (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'
		|| TOKEN->line[TOKEN->pos] == '\n')
			TOKEN->pos++;
		if (ft_strchr("r%:-123456789", TOKEN->line[TOKEN->pos]))
		{
			prog_size(cycle);
			while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
				TOKEN->line[TOKEN->pos] != '\0')
				;
		}
		else
		{
			// ft_printf("Invalid parameter for instruction %s\n", TOKEN->name);
			exit(0);
		}
		cycle++;
	}
}

void	vname_aux(void)
{
	// ft_printf("Lexical error\n");
	exit(0);
}

void	vname(void)
{
	char	tmp[LINE_MAX_SIZE];
	int		index;

	index = 0;
	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] != ' ' && TOKEN->line[TOKEN->pos] != '\t' &&
		TOKEN->line[TOKEN->pos] != '\0')
		if (ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
			tmp[index++] = TOKEN->line[TOKEN->pos++];
		else if (TOKEN->line[TOKEN->pos] == ':')
			break ;
		else
			vname_aux();
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
	
	while (g_file.data[g_file.offset] != '\0')
	{
		TOKEN->pos = 0;
		gnl();
		if (line < 2 && ft_strcmp(TOKEN->line, "\0"))
			line++ == 0 ? parse_name(0) : parse_comment(0);
		else if (ft_strcmp(TOKEN->line, "\0"))
		{
			vname();
			op_offset();
			vargs();
		}
	}
}

// void	add_label(char *label)
// {
// 	int	current;

// 	current = 0;
// 	label = ft_strjoin(label, ":", 0);
// 	label = ft_strjoin(label, ft_itoa(g_file.header->prog_size + 1), 0);
// 	g_file.labels[g_file.labels_nb] = ft_strnew(ft_strlen(label));
// 	g_file.labels[g_file.labels_nb] = label;
// 	g_file.labels_nb++;
// }

// void	vargs()
// {
// 	int		cycle;

// 	cycle = 0;
// 	while (cycle < g_op_tab[TOKEN->op_offset].arg_nb)
// 	{
// 		while (TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t'
// 		|| TOKEN->line[TOKEN->pos] == '\n')
// 			TOKEN->pos++;
// 		if (ft_strchr("r%:-123456789", TOKEN->line[TOKEN->pos]))
// 		{
// 			prog_size(cycle);
// 			while (TOKEN->line[TOKEN->pos++] != SEPARATOR_CHAR &&
// 				TOKEN->line[TOKEN->pos] != '\0')
// 				;
// 		}
// 		else
// 		{
// 			//printf("Invalid parameter for instruction %s\n", TOKEN->name);
// 			exit(0);
// 		}
// 		cycle++;
// 	}
// }

// void	vname_aux(void)
// {
// 	//printf("Lexical error\n");
// 	exit(0);
// }

// void	vname()
// {
// 	char	tmp[LINE_MAX_SIZE];
// 	int		index;

// 	index = 0;
// 	while ((TOKEN->line[TOKEN->pos] == ' ' || TOKEN->line[TOKEN->pos] == '\t' ||
// 			TOKEN->line[TOKEN->pos] == '\n') && TOKEN->line[TOKEN->pos] != '\0')
// 		TOKEN->pos++;
// 	while (TOKEN->line[TOKEN->pos] != ' ' && TOKEN->line[TOKEN->pos] != '\t' &&
// 		TOKEN->line[TOKEN->pos] != '\0')
// 		if (ft_strchr(LABEL_CHARS, TOKEN->line[TOKEN->pos]))
// 			tmp[index++] = TOKEN->line[TOKEN->pos++];
// 		else if (TOKEN->line[TOKEN->pos] == ':')
// 			break ;
// 		else
// 			vname_aux();
// 	tmp[index] = '\0';
// 	if (TOKEN->line[TOKEN->pos] == ':')
// 	{
// 		add_label(tmp);
// 		TOKEN->pos++;
// 		vname();
// 	}
// 	else
// 		TOKEN->name = ft_strdup(tmp);
// }

// void	handle_labels()
// {
// 	static int	line;

// 	g_file.token = ft_memalloc(sizeof(t_token));
// 	g_file.labels = ft_memalloc(sizeof(char *) * 300);
// 	TOKEN->name = ft_strnew(5);
// 	while (g_file.data[g_file.offset] != '\0')
// 	{
// 		TOKEN->pos = 0;
// 		gnl();
// 		if (line < 2 && ft_strcmp(TOKEN->line, "\0"))
// 			line++ == 0 ? parse_name(0) : parse_comment(0);
// 		else if (ft_strcmp(TOKEN->line, "\0"))
// 		{
// 			vname();
// 			op_offset();
// 			vargs();
// 		}
// 	}
// }