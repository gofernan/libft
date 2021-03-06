/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:31:32 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 19:35:55 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include <fcntl.h>
# define BUFF_SIZE 4

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_listfd
{
	char			*content;
	int				fdnum;
	struct s_listfd	*next;
}					t_listfd;

void				ft_bzero(void *s, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *restrict dst,
					const void *restrict src, size_t n);
void				*ft_memccpy(void *restrict dst,
const void			*restrict src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strdup(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1,
					const char *restrict s2, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *restrict dst,
					const char *restrict src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
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
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
char				*ft_itoa(intmax_t n);
int					ft_atoi(const char *str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_strsplit(char const *s, char c);
void				ft_div_mod(int a, int b, int *div, int *mod);
int					ft_iterative_factoial(int b);
int					*ft_range(int min, int max);
void				ft_swap(int *a, int *b);
void				ft_is_negative(int n);
int					ft_nlen(long nb);
size_t				ft_wcslen(const wchar_t *s);
char				*ft_ltoa(long nb);
char				*ft_lltoa(long long nb);
char				*ft_uitoa(uintmax_t nb);
char				*ft_itoa_base(intmax_t nb, int base, int alt);
char				*ft_uitoab(uintmax_t nb, unsigned int base, int alt);
char				*ft_strncpynp(char *dst, const char *src, size_t len);
char				*ft_binary(intmax_t nb);
int					ft_abs(int nb);
int					ft_countwords(char const *s, char c);
int					get_next_line(const int fd, char **line);

#endif
