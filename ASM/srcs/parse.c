/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 03:52:01 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/24 09:17:55 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parse_name(void)
{
	char	*name;
	int		i;

	i = 0;
	name = ft_strnew(PROG_NAME_LENGTH);
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	if (ft_strncmp(&(TOKEN->line[TOKEN->pos]), NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (-1);
	TOKEN->pos += ft_strlen(NAME_CMD_STRING);
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	if (TOKEN->line[TOKEN->pos++] != '"')
		return (-1);
	while (TOKEN->line[TOKEN->pos] != '"')
		name[i++] = TOKEN->line[TOKEN->pos++];
	if (TOKEN->line[TOKEN->pos])
		TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	if (TOKEN->line[TOKEN->pos])
		return (-1);
	ft_strcpy(g_file.header->prog_name, name);
	return (0);
}

int		parse_comment(void)
{
	char	*com;
	int		i;

	i = 0;
	com = ft_strnew(COMMENT_LENGTH);
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	if (ft_strncmp(&(TOKEN->line[TOKEN->pos]), COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (-1);
	TOKEN->pos += ft_strlen(COMMENT_CMD_STRING);
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	if (TOKEN->line[TOKEN->pos++] != '"')
		return (-1);
	while (TOKEN->line[TOKEN->pos] != '"')
		com[i++] = TOKEN->line[TOKEN->pos++];
	TOKEN->pos++;
	while (TOKEN->line[TOKEN->pos] && IS_WHITE(TOKEN->line[TOKEN->pos]))
		TOKEN->pos++;
	ft_strcpy(g_file.header->comment, com);
	return (0);
}
