/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:32:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:39:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	formater_c_init(t_printf *data, t_char *charact, va_list ap)
{
	if ((*data).len == 0)
		if (((*data).len = va_arg(ap, int)) < 0)
		{
			(*data).neg = -1;
			(*data).len *= -1;
		}
	if ((*data).pre == 0)
		(*data).pre = va_arg(ap, int);
	(*charact).c = va_arg(ap, int);
	if ((*data).len < 1)
		(*data).len = 1;
	if ((*data).pre < 1)
		(*data).pre = 1;
}

void	formater_c(t_printf data, va_list ap)
{
	t_char	charact;

	formater_c_init(&data, &charact, ap);
	if (data.neg == -1)
	{
		write_char(' ', data.pre - 1);
		uwriter((unsigned char)charact.c);
		write_char(' ', data.len - data.pre);
	}
	else if (data.neg >= 0)
	{
		write_char(' ', data.len - 1);
		uwriter((unsigned char)charact.c);
	}
}
