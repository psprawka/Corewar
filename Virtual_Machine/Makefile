# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 14:30:55 by tle-huu-          #+#    #+#              #
#    Updated: 2018/03/08 07:14:00 by tle-huu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
SRCS_DIR = srcs/

SRCS =	$(SRCS_DIR)main.c									\
		$(SRCS_DIR)parsing/parser.c							\
		$(SRCS_DIR)initialisation/init.c					\
		$(SRCS_DIR)initialisation/load_players.c			\
		$(SRCS_DIR)initialisation/op.c						\
		$(SRCS_DIR)initialisation/handle_header.c			\
		$(SRCS_DIR)game/run_game.c							\
		$(SRCS_DIR)game/endgame.c							\
		$(SRCS_DIR)game/process_execution.c					\
		$(SRCS_DIR)game/check_lives.c						\
		$(SRCS_DIR)game/do_cycle.c						\
		$(SRCS_DIR)utils/op_utils.c							\
		$(SRCS_DIR)utils/read_param.c						\
		$(SRCS_DIR)utils/stack_utils.c						\
		$(SRCS_DIR)utils/utils_general.c					\
		$(SRCS_DIR)utils/utils_general2.c					\
		$(SRCS_DIR)utils/free_tatoucompri.c					\
		$(SRCS_DIR)operations/live.c						\
		$(SRCS_DIR)operations/ld.c							\
		$(SRCS_DIR)operations/st.c							\
		$(SRCS_DIR)operations/add.c							\
		$(SRCS_DIR)operations/sub.c							\
		$(SRCS_DIR)operations/and.c							\
		$(SRCS_DIR)operations/or.c							\
		$(SRCS_DIR)operations/xor.c							\
		$(SRCS_DIR)operations/zjmp.c						\
		$(SRCS_DIR)operations/ldi.c							\
		$(SRCS_DIR)operations/sti.c							\
		$(SRCS_DIR)operations/fork.c						\
		$(SRCS_DIR)operations/lld.c							\
		$(SRCS_DIR)operations/lldi.c						\
		$(SRCS_DIR)operations/lfork.c						\
		$(SRCS_DIR)operations/aff.c							\
		$(SRCS_DIR)errors/errors.c							\


CFLAGS = -g -Wall -Wextra -Werror
INCLUDES = includes/
HEADERS = $(INCLUDES)*
OBJS = $(SRCS:.c=.o)

LIBFT = libftprintf.a

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HEADERS)
	@printf "\r\033[K\033[1;33m[COREWAR] \033[0;32mLinking...\033[0m\n"
	@echo "tle-huu-" > author
	@gcc $(CFLAGS) -I$(INCLUDES) $(OBJS) $(LIBFT) -lncurses -o $(NAME)
	@printf "\r\033[K\033[1;33m[COREWAR] \033[0;32mDone !\033[0m\n"

$(LIBFT):
	@make -C libs/
	@cp libs/ft_printf/libft.h $(INCLUDES)
	@cp libs/ft_printf/libftprintf.a .

%.o: %.c
	@printf "\r\033[K\033[1;33m[COREWAR] \033[0;32mBuilding $<\033[0m\n"
	@gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C libs/ clean
	@rm -f $(OBJS)
	@printf "\033[1;32m[COREWAR] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@$(MAKE) -C libs/ fclean
	@rm -f $(NAME)
	@rm -f libftprintf.a
	@printf "\033[1;32m[COREWAR] \033[1;31mCleaned all!\033[0m\n"

re: fclean all
