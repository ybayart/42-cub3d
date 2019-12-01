/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:31:32 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 02:31:48 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TP_H
# define LIBFT_TP_H

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	char			str[((BUFFER_SIZE > 0) ? BUFFER_SIZE + 1 : 1)];
	int				fd;
	int				i;
	int				len;
	int				l_line;
	int				tmp;
}				t_gnl;

typedef struct	s_printf
{
	int					neg;
	int					len;
	int					pre;
	char				type;
}				t_printf;

typedef struct	s_decimal
{
	long				n;
	int					neg;
	int					decalage;
	size_t				len;
}				t_decimal;

typedef struct	s_udecimal
{
	unsigned int		n;
	int					neg;
	size_t				len;
	int					init_pre;
}				t_udecimal;

typedef struct	s_xdecimal
{
	unsigned int		n;
	int					neg;
	size_t				len;
	char				*base;
	int					init_pre;
}				t_xdecimal;

typedef struct	s_char
{
	unsigned char		c;
	int					neg;
}				t_char;

typedef struct	s_string
{
	const char			*s;
	int					neg;
	size_t				len;
}				t_string;

typedef struct	s_pointer
{
	unsigned long long	addr;
	int					neg;
	size_t				len;
}				t_pointer;

#endif
