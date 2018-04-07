# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 14:30:55 by tle-huu-          #+#    #+#              #
#    Updated: 2018/03/08 07:03:22 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRCS_DIR = srcs/

SRCS =	$(SRCS_DIR)assembler.c							\
		$(SRCS_DIR)assembler_aux.c						\
		$(SRCS_DIR)assembler_aux2.c						\
		$(SRCS_DIR)ft_libft.c							\
		$(SRCS_DIR)ft_libft_aux.c						\
		$(SRCS_DIR)ft_libft_aux2.c						\
		$(SRCS_DIR)ft_libft_aux3.c						\
		$(SRCS_DIR)header.c								\
		$(SRCS_DIR)op.c								\
		$(SRCS_DIR)prog_size.c								\
		$(SRCS_DIR)lables.c								\
		$(SRCS_DIR)tools.c								\
		$(SRCS_DIR)utils_general.c								\

CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = includes/
HEADERS = $(INCLUDES)*
OBJS = $(SRCS:.c=.o)

LIBFT = libftprintf.a

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HEADERS)
	@printf "\r\033[K\033[1;33m[COREWAR ASSEMBLER] \033[0;32mLinking...\033[0m\n"
	@echo "tle-huu-\npaulina" > author
	@gcc $(CFLAGS) -I$(INCLUDES) $(OBJS) $(LIBFT) -lncurses -o $(NAME)
	@printf "\r\033[K\033[1;33m[COREWAR ASSEMBLER] \033[0;32mDone !\033[0m\n"

$(LIBFT):
	@make -C libs/
	@cp libs/ft_printf/libft.h $(INCLUDES)
	@cp libs/ft_printf/libftprintf.a .

%.o: %.c
	@printf "\r\033[K\033[1;33m[COREWAR ASSEMBLER] \033[0;32mBuilding $<\033[0m\n"
	@gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C libs/ clean
	@rm -f $(OBJS)
	@printf "\033[1;32m[COREWAR ASSEMBLER] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@$(MAKE) -C libs/ fclean
	@rm -f $(NAME)
	@rm -f libftprintf.a
	@printf "\033[1;32m[COREWAR ASSEMBLER] \033[1;31mCleaned all!\033[0m\n"

re: fclean all
