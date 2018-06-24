/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 10:39:17 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:49:42 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

int		valid_instr_types(char t, int arg)
{
	int bits;
	int type;

	bits = g_op_tab[TOKEN->op_offset].args[arg];
	if (t == 'r')
		type = T_REG;
	else
		type = (t == '%' ? T_DIR : T_IND);
	if (bits & type)
		return (1);
	error(2, TOKEN->name, true);
	return (0);
}

void	valid_instr_values(void)
{
	int		cycle;

	cycle = 0;
	while (cycle < g_op_tab[TOKEN->op_offset].arg_nb)
	{
		while (IS_WHITE(TOKEN->line[TOKEN->pos]))
			TOKEN->pos++;
		if (ft_strchr("r%:-123456789", TOKEN->line[TOKEN->pos]))
		{
			count_prog_size(cycle);
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

void	valid_instr_name(void)
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
		valid_instr_name();
	}
	else
		TOKEN->name = ft_strdup(tmp);
}