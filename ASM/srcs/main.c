/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 07:15:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_file	g_file;

// int		init_file(char *filename)
// {
// 	g_file.data = readandstore(filename);
// 	g_file.name = ft_strncpy(filename, ft_strlen(filename) - 2);
// 	g_file.fd = open(ft_strjoin(g_file.name, ".corx", 0), O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	return (EXIT_SUCCESS);
// }

// int		main(int ac, char **av)
// {
// 	if (ac != 2 || ft_strlen(av[1]) < 3)
// 	{
// 		printf("Usage: ./asm <sourceg_file.s>\n");
// 		return (EXIT_FAILURE);
// 	}

// 	init_file(av[1]);
// 	handle_header();
// 	handle_labels();
// 	write_header();
// 	g_file.header->prog_size = 0;
// 	TOKEN->op_offset = -1;
// 	g_file.offset = 0;
// 	handle_instructions();
// 	printf("Writing the output to %s.cor file\n", g_file.name);
	
// 	return (EXIT_SUCCESS);
// }

void	assembler(char *data, char *filename)
{
	g_file.data = data;
	g_file.offset = 0;
	handle_header();
	g_file.name = ft_strncpy(filename, ft_strlen(filename) - 2);
	g_file.fd = open(ft_strjoin(g_file.name, ".corx", 0), O_CREAT | O_WRONLY | O_TRUNC, 0644);
	handle_labels();
	write_header();
	g_file.header->prog_size = 0;
	TOKEN->op_offset = -1;
	g_file.offset = 0;
	handle_instructions();
	// ft_printf("Writing the output to %s.cor file\n", g_file.name);
}

int		main(int ac, char **av)
{
	char *data;

	if (ac != 2)
	{
		// ft_printf("Usage: ./asm <sourcefile.s>\n");
		return (1);
	}
	else
	{
		data = readandstore(av[1]);
		assembler(data, av[1]);
	}
	return (0);
}