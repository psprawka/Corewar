/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 10:43:20 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Get_op_offset(), based on instruction's name, finds an offset in g_op_tab
**	table, assigns it to TOKEN->op_offset and increases program's size.
*/
void	get_op_offset(void)
{
	int		i;

	i = 0;
	if (ft_strcmp(TOKEN->name, "\0") == 0)
		return ;
	while (g_op_tab[i].name != NULL)
	{
		if (!ft_strcmp(g_op_tab[i].name, TOKEN->name))
		{
			TOKEN->op_offset = i;
			g_file.header->prog_size += (g_op_tab[i].coding_byte == 1) ? 2 : 1;
			return ;
		}
		i++;
	}
	error(7, TOKEN->line, true);
	exit(0);
}

/*
**	An error function just handles all error messages based on the number
**	sent in function call. If number is not found, strerror mesage is sent.
**	I bool flag (ifailure) is set to true func returns EXIT_FAILURE,
**	otherwise EXIT_SUCCESS.
*/
int		error(int errnb, char *msg, bool ifailure)
{
	if (errnb == 1)
		ft_printf("Usage: ./asm <sourceg_file.s>\n");
	else if (errnb == 2)
		ft_printf("Invalid parameter for instruction %s\n", msg);
	else if (errnb == 3)
		ft_printf("No such label %s while attempting to dereference\n", msg);
	else if (errnb == 4)
		ft_printf("Lexical error\n");
	else if (errnb == 5)
		ft_printf("Invalid parameter for instruction %s\n", msg);
	else if (errnb == 6)
		ft_printf("Syntax error INSTRUCTION \"r\"\n");
	else if (errnb == 7)
		ft_printf("Invalid instruction [%s][%s]\n", msg);
	else
		ft_printf("%s%s: %s%s\n", RED, msg, strerror(errno), NORMAL);
	return (ifailure == true ? EXIT_FAILURE : EXIT_SUCCESS);
}