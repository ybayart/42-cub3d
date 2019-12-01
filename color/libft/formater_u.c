/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:32:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:39:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		formater_u_init(t_printf *data, t_udecimal *number, va_list ap)
{
	if ((*data).len == 0)
		if (((*data).len = va_arg(ap, int)) < 0)
		{
			(*data).neg = -1;
			(*data).len *= -1;
		}
	if ((*data).pre == 0)
		(*data).pre = va_arg(ap, int);
	(*number).n = va_arg(ap, unsigned int);
	if ((*data).pre == -2 && (unsigned int)(*number).n == 0)
	{
		if ((*data).len > 0)
			write_char(' ', (*data).len);
		return (0);
	}
	if ((*data).len < (int)((*number).len = ft_nbrlen((*number).n)))
		(*data).len = (*number).len;
	(*number).init_pre = (*data).pre;
	if ((*data).pre < (int)(*number).len)
		(*data).pre = (*number).len;
	return (1);
}

void	formater_u(t_printf data, va_list ap)
{
	t_udecimal	number;

	if (formater_u_init(&data, &number, ap) == 0)
		return ;
	if (data.neg == -1)
	{
		write_char('0', data.pre - number.len);
		ft_putunbr_fd((unsigned int)number.n, 1);
		write_char(' ', data.len - data.pre);
	}
	else if (data.neg >= 0)
	{
		if (data.neg == 0 && number.init_pre == -1)
			write_char('0', data.len - data.pre);
		else
			write_char(' ', data.len - data.pre);
		write_char('0', data.pre - number.len);
		ft_putunbr_fd((unsigned int)number.n, 1);
	}
	printed(number.len);
}
