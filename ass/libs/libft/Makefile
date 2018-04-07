
NAME = libft.a

SRC =	ft_atoi.c				\
		ft_bzero.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_itoa.c				\
		ft_itoa_base.c			\
		ft_circ_list_utils.c	\
		ft_lstadd.c				\
		ft_lstdel.c				\
		ft_lstdelone.c			\
		ft_lstiter.c			\
		ft_lstlength.c			\
		ft_lstmap.c				\
		ft_lstnew.c				\
		ft_lstsortstring.c 		\
		ft_lstutils.c			\
		ft_memalloc.c			\
		ft_memccpy.c	\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memdel.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_putchar.c			\
		ft_putnchar.c			\
		ft_putchar_fd.c			\
		ft_putendl.c			\
		ft_putendl_fd.c			\
		ft_putnbr.c				\
		ft_putnbr_fd.c			\
		ft_putstr.c				\
		ft_putnstr.c			\
		ft_putstr_fd.c			\
		ft_putnwstr.c			\
		ft_sort_int_tab.c 		\
		ft_sort_string_tab.c 	\
		ft_strlen.c				\
		ft_strdup.c				\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strlcat.c			\
		ft_strchr.c				\
		ft_strsearch.c			\
		ft_strrchr.c			\
		ft_strstr.c				\
		ft_strnstr.c			\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strnew.c				\
		ft_strdel.c				\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_strsplit.c			\
		ft_tolower_str.c		\
		ft_power.c				\
		ft_minimax.c			\
		ft_nblen.c				\
		ft_wstrlen.c			\
		get_next_line.c			\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\r\033[32m>>>   Building lib $(NAME)...   <<<\033[0m"
	@gcc -c -Wall -Wextra -Werror $(SRC) libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r\033[33m>>>   $(NAME) build !   <<<\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@printf "\033[1;33m[LIBFT] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[1;33m[LIBFT] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
