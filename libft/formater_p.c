/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:32:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:39:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	formater_p_init(t_printf *data, t_pointer *pointer, va_list ap)
{
	if ((*data).len == 0)
		if (((*data).len = va_arg(ap, int)) < 0)
		{
			(*data).neg = -1;
			(*data).len *= -1;
		}
	if ((*data).pre == 0)
		(*data).pre = va_arg(ap, int);
	(*pointer).addr = va_arg(ap, unsigned long long);
	if ((*data).len <
			(int)((*pointer).len = ft_nbrlen_base((*pointer).addr, 16) + 2))
		(*data).len = (*pointer).len;
	if ((*data).pre < (int)(*pointer).len)
		(*data).pre = (*pointer).len;
}

void	formater_p(t_printf data, va_list ap)
{
	t_pointer	pointer;

	formater_p_init(&data, &pointer, ap);
	if (data.neg == -1)
	{
		write_char(' ', data.pre - pointer.len);
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(pointer.addr, 1, "0123456789abcdef");
		write_char(' ', data.len - data.pre);
	}
	else if (data.neg >= 0)
	{
		write_char(' ', data.len - pointer.len);
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(pointer.addr, 1, "0123456789abcdef");
	}
	printed(pointer.len);
}
