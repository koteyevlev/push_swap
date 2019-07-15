/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:51:16 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/15 18:07:47 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LIBFT_H
# define __FT_LIBFT_H
# define BUFF_SIZE 3

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_intar
{
	int				*nbr;
	int				count;
}					t_intar;

typedef struct		s_intl
{
	int				nbr;
	struct s_intl	*next;
}					t_intl;

typedef	struct		s_kord
{
	int				x;
	int				y;
}					t_kord;

typedef	struct		s_file
{
	struct s_file	*previous;
	char			content[21];
	char			newstr[1];
	struct s_kord	kord[4];
	struct s_file	*next;
}					t_file;

typedef	struct		s_figure
{
	char			**fig;
	int				height;
	int				width;
	struct s_figure	*next;
	struct s_figure	*previous;
}					t_figure;

typedef	struct		s_printf
{
	long int		index;
	long int		end;
	char			razmer;
	char			main;
	char			min;
	char			plus;
	char			space;
	char			sharp;
	char			zero;
	char			quote;
	int				width;
	int				precision;
	char			error;
	va_list			ap;
	char			*format;
}					t_printf;

int					ft_num_el(t_intl *b);
int					ft_median(t_intl *a, int x, int y, int argc);
int					*ft_massiv(t_intl *a, int argc);
void				ft_medium_sort(t_intl **a, t_intl **b, int argc);
void				ft_five_sort(t_intl **a, t_intl **b, int argc);
int					ft_is_sort(t_intl *a);
int					min_max(t_intl **a, t_intl **b);
int					ft_min(t_intl **a, t_intl **b);
void				ft_simple_sort(t_intl **a, int argc);
void				ft_choose_op(t_intl **a, int f, int s, int t);
void				ft_print_op(t_intl **a, t_intl **b, char name, char who);
void				ft_print_opt(t_intl **a, t_intl **b, char name, char who);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst,
		const void *src, size_t n);
void				*ft_memccpy(void *dst,
		const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst,
		const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
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
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_modul(int nmr);
int					get_next_line(const int fd, char **line);
t_figure			*ft_fit(t_file *file);
size_t				ft_w_count(char const *s, char c);
t_file				*ft_reading(char *namefile);
void				ft_strjoin2(char **str, char **str2);
void				ft_strjoin3(char **line, char **str, char **str2);
t_file				*ft_figure(t_file **file);
int					ft_strindex(const char *str, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_strindex(const char *str, int c);
void				fillit(t_figure **tetr, int size);
void				ft_freetetr(t_figure **fig);
void				ft_freemap(char **mas);
void				ft_copykord(t_file **file, t_kord kord[4]);
t_kord				*new_kord(int x, int y);
void				print_figures(char **mas);
char				**ft_create(int size);
void				ft_add(char **mas, t_figure **tetr, int y, int x);
void				ft_print_l(t_intl *a);
t_intl				*ft_del_last(t_intl **a);
t_intl				*ft_del_first(t_intl **a);
void				ft_push_first(t_intl **a, t_intl *el);
void				ft_push_last(t_intl **a, t_intl *el);
void				ft_create_int(t_intl **a, t_intl **b,
char **argv, int argc);
int					ft_isint(char *str);
void				ft_create_int(t_intl **a, t_intl **b,
char **argv, int argc);
void				ft_del_all(t_intl **a, t_intl **b);
void				ft_sa(t_intl **a);
void				ft_rra(t_intl **a);
void				ft_ra(t_intl **a);
void				ft_pa(t_intl **a, t_intl **b);

#endif
