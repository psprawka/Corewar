# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 15:29:45 by tle-huu-          #+#    #+#              #
#    Updated: 2018/03/03 20:21:57 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libs

all : $(NAME)

$(NAME):
	@$(MAKE) -C libft libft.a
	@$(MAKE) -C ft_printf libftprintf.a

clean:
	@$(MAKE) -C ft_printf clean

fclean:
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean

re: fclean all

.PHONY: all fclean clean re
