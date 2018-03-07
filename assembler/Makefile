# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liamprior <liamprior@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 00:37:00 by liamprior         #+#    #+#              #
#    Updated: 2018/03/07 00:37:57 by liamprior        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = asm
SRC_DIR = srcs/
FILES = *.c

CFLAGS = -Wall -Wextra -Werror
HEAD = ./includes
SRC	:= $(addprefix $(SRC_DIR)/, $(FILES))


BUILD = @echo "\033[0;33mBuilding \"$<\"..."
DONE = @echo "\033[0;32mAssembler ready to use!"
CLEAN_O = @echo "\033[0;32mObject files removed!"
CLEAN_A = @echo "\033[0;32mExecutable removed!"
LIBS = ft_printf/libftprintf.a


all: $(NAME)

$(LIBS):
	@make -C ft_printf

$(NAME): $(LIBS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBS) -I. -o $(NAME)

clean:
	@make -C libft clean
	$(CLEAN_O)

fclean: clean
	@rm -rf $(NAME)
	@make -C libft
	$(CLEAN_A)

re: fclean all

.PHONY = all clean fclean re
