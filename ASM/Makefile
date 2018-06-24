# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/09 23:21:55 by psprawka          #+#    #+#              #
#    Updated: 2018/06/24 09:40:53 by psprawka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= asm
FLAGS			= -g -Wall -Wextra -Werror
FLAGS			+=  -fsanitize=address

HEADERS			= includes/
SRCS_DIR		= srcs/
INSTRUCTIONS	= instructions/

SRCS = $(SRCS_DIR)main.c \
	$(SRCS_DIR)lables.c \
	$(SRCS_DIR)header.c \
	$(SRCS_DIR)prog_size.c \
	$(SRCS_DIR)read_data.c \
	$(SRCS_DIR)tools.c \
	$(SRCS_DIR)parse.c \
	$(SRCS_DIR)$(INSTRUCTIONS)direct.c \
	$(SRCS_DIR)$(INSTRUCTIONS)indirect.c \
	$(SRCS_DIR)$(INSTRUCTIONS)register.c \
	$(SRCS_DIR)$(INSTRUCTIONS)handle_instructions.c

OBJS		= $(SRCS:.c=.o)
LIBFT		= libft/libft.a

BUILD_PRINT = @echo "\r\033[K\033[0;38;5;206m[asm] \033[38;5;80mBuilding $<"
DONE		 = @echo "\033[K\033[1;38;5;44m[asm]\033[K\033[1;38;5;200m ready to use!"
CLEAN_O		= @echo "\033[38;5;246mObject files removed! [asm]"
CLEAN_A		= @echo "\033[38;5;246mExecutable removed! [asm]"

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HEADERS)
		@gcc $(FLAGS) -I $(HEADERS) $(OBJS) $(LIBFT) -lncurses -o $(NAME)
		$(DONE)

$(LIBFT):
	@make -C libft
	@echo ""

%.o: %.c
	$(BUILD_PRINT)
	@gcc -g $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	$(CLEAN_O)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	$(CLEAN_A)

re: fclean all
