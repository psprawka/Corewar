/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 18:20:09 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/02/12 12:07:28 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

# define BUFF_SIZE 1000

typedef struct		s_list
{
	void			*content;
	long long int	content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_circlist
{
	void				*content;
	long long int		content_size;
	struct s_circlist	*next;
	struct s_circlist	*previous;
}					t_circlist;

long long int		ft_atoi(const char *nptr);
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isnumber(char *str);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					int_length(long long int n, int base);
int					uns_int_length(unsigned long long int n, int base);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *h, const char *nee);
char				*ft_strnstr(const char *h, const char *nee, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_sort_int_tab(int *tab, int length);
void				ft_sort_string_tab(char **tab, int length);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
int					ft_strsearch(char *str, char x);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(long long int n);
char				*ft_itoa_base(long long int n, int base);
char				*ft_itoa_base_m(long long int n, int base);
char				*ft_unsigned_itoa(unsigned long long int n);
char				*ft_unsigned_itoa_base(unsigned long long int n, int base);
char				*ft_unsigned_itoa_base_m(unsigned long long int n,
		int base);
void				ft_freestr(char *s);
void				ft_putchar(char c);
size_t				ft_putnchar(char c, int n);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, size_t n);
void				ft_putendl(char const *s);
void				ft_putnbr(long long int n);
void				ft_putnbr_uns(unsigned long long int n);
void				ft_putwchar(wchar_t c);
void				ft_putnwstr(wchar_t *str, int len);
void				ft_putnbr_base(long long int n, int base);
void				ft_uns_putnbr_base(unsigned long long int n, int base);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_free_tab(int **tab, int size);
void				ft_free_char_tab(char **tab, int size);
int					ft_open(char *file_name);
int					ft_nb_lines(char *file_name);
int					ft_tab_length(char **tab);
long				ft_atol(const char *nptr);
int					ft_open(char *file_name);
void				ft_free(char *str);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_lst_is_sorted(t_list *stack);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstadd_end(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlength(t_list *list);
long long int		ft_lstmaxsize(t_list *list);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
long long int		ft_lstminsize(t_list *list);
t_list				*ft_lstnew(void const *content, long long int content_size);
t_list				*ft_lst_pop(t_list **list);
void				ft_lst_merge_sort(t_list **list, long int
	(*f)(char *, char *));
void				ft_lst_merge_sort_r(t_list **list, long int
	(*f)(char *, char *));
size_t				ft_wstrlen(wchar_t *str);
void				ft_capitalize(char *str);
void				ft_power(int n, int pow);
void				ft_tolower_str(char *str);

#endif
