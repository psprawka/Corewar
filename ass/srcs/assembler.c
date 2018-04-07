/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:12:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/03/08 06:03:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"
#include "../includes/op.h"
#include "../includes/libft.h"

#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

void	reg(t_file *file)
{
	int		value;
	char	*number;

	value = 0;
	number = ftt_strsub(TOKEN->line, TOKEN->pos, 4);
	if ((value = ftt_atoi(number)) > 99 || value < 0)
	{
		ft_printf("Syntax error INSTRUCTION \"r\"\n");
		exit(0);
	}
	write(file->fd, (char *)&value, 1);
	file->header->prog_size += 1;
	free(number);
}

void	assembler(char *data, char *filename)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	file->data = data;
	file->offset = 0;
	handle_header(file);
	file->name = ftt_strncpy(filename, ftt_strlen(filename) - 2);
	file->fd = open(ftt_strjoin(file->name, ".cor"), O_CREAT | O_WRONLY, 0644);
	handle_labels(file);
	write_header(file);
	file->header->prog_size = 0;
	TOKEN->op_offset = -1;
	file->offset = 0;
	handle_instructions(file);
	ft_printf("Writing the output to %s.cor file\n", file->name);
}

int		main(int ac, char **av)
{
	char *data;

	if (ac == 1)
	{
		printf("Usage: ./asm <sourcefile.s>\n");
		return (1);
	}
	else
	{
		data = readandstore(av[1]);
		assembler(data, av[1]);
	}
	return (0);
}
