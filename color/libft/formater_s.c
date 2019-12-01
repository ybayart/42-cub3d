/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:32:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:39:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	formater_s_init(t_printf *data, t_string *string, va_list ap)
{
	if ((*data).len == 0)
		if (((*data).len = va_arg(ap, int)) < 0)
		{
			(*data).neg = -1;
			(*data).len *= -1;
		}
	if ((*data).pre == 0)
	{
		(*data).pre = va_arg(ap, int);
		if ((*data).pre < 0)
			(*data).pre = -1;
	}
	(*string).s = va_arg(ap, const char *);
	if ((*string).s == NULL)
		(*string).s = "(null)";
	(*string).len = ft_strlen((*string).s);
	if ((*data).pre > (int)(*string).len || (*data).pre == -1)
		(*data).pre = (*string).len;
	else if ((*data).pre == -2)
		(*data).pre = 0;
	if ((*data).len < (*data).pre)
		(*data).len = (*data).pre;
}

void	formater_s(t_printf data, va_list ap)
{
	t_string	string;

	formater_s_init(&data, &string, ap);
	if (data.neg == -1)
	{
		write_char(' ', data.pre - string.len);
		ft_putnstr_fd((char*)string.s, 1, data.pre);
		write_char(' ', data.len - data.pre);
	}
	else if (data.neg >= 0)
	{
		write_char(' ', data.len - data.pre);
		ft_putnstr_fd((char*)string.s, 1, data.pre);
	}
	printed(data.pre);
}
