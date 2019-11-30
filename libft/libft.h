/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:41:48 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 02:32:00 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define FT_MAX_UI      (unsigned int)(~0L)
# define FT_MAX_I       (int)(FT_MAX_UI >> 1)
# define FT_MIN_I       (int)(~FT_MAX_I)

# define FT_MAX_UL	(unsigned long)(~0L)
# define FT_MAX_L	(long)(FT_MAX_UL >> 1)
# define FT_MIN_L	(long)(~FT_MAX_L)

# define BUFFER_SIZE 32
# define __CONVERTER "cspdiuxX%"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft_tp.h"

void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *x1, const void *s2, size_t n);
size_t		ft_strlen(const char *x);
size_t		ft_nbrlen(long long n);
size_t		ft_nbrlen_base(long long n, int base);
size_t		ft_tablen(void **tab);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t n);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free(char const *s1, char const *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnstr_fd(char *s, int fd, int n);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putlnbr_fd(long n, int fd);
void		ft_putunbr_fd(unsigned long long n, int fd);
void		ft_putnbr_base_fd(int n, int fd, char *base);
void		ft_putunbr_base_fd(unsigned long long n, int fd, char *base);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
int			ft_nbwords(char **line);
int			ft_strcmp(char *s1, char *s2);
int			ft_str_to_int(char *str);
int			get_next_line(int fd, char **line);

int			ft_printf(const char *s, ...);
void		parser(const char *s, va_list ap);
void		writer(char c);
void		uwriter(unsigned char c);
void		write_char(char c, int n);
size_t		printed(int inc);
void		formater(t_printf data, va_list ap);
void		formater_d(t_printf data, va_list ap);
void		formater_u(t_printf data, va_list ap);
void		formater_x(t_printf data, va_list ap);
void		formater_c(t_printf data, va_list ap);
void		formater_s(t_printf data, va_list ap);
void		formater_p(t_printf data, va_list ap);
void		formater_pe(t_printf data, va_list ap);

#endif
