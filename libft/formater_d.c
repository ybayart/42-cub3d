/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:32:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:39:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		formater_d_init(t_printf *data, t_decimal *decimal, va_list ap)
{
	if ((*data).len == 0)
		if (((*data).len = va_arg(ap, int)) < 0)
		{
			(*data).neg = -1;
			(*data).len *= -1;
		}
	if ((*data).pre == 0)
		(*data).pre = va_arg(ap, int);
	(*decimal).n = va_arg(ap, int);
	if ((*data).pre == -2 && (*decimal).n == 0)
	{
		if ((*data).len > 0)
			write_char(' ', (*data).len);
		return (0);
	}
	if ((*data).len < (int)((*decimal).len = ft_nbrlen((*decimal).n)))
		(*data).len = (*decimal).len;
	if ((*data).pre < (int)(*decimal).len)
		(*data).pre = (*decimal).len;
	(*decimal).decalage = 0;
	return (1);
}

void	formater_d_print_neg(t_printf data, t_decimal *decimal)
{
	if ((*decimal).n < 0)
	{
		(*decimal).n *= -1;
		writer('-');
		(*decimal).decalage -= 1;
	}
	write_char('0', data.pre - (*decimal).len);
	ft_putlnbr_fd((*decimal).n, 1);
	write_char(' ', data.len - data.pre);
}

void	formater_d_print_pos(t_printf data, t_decimal *decimal)
{
	if (data.neg == 0 && (data.pre == -1 || data.pre == (int)(*decimal).len))
	{
		if ((*decimal).n < 0)
		{
			(*decimal).n *= -1;
			writer('-');
			(*decimal).decalage -= 1;
		}
		write_char('0', data.len - data.pre);
	}
	else
		write_char(' ', data.len - data.pre);
	if ((*decimal).n < 0)
	{
		(*decimal).n *= -1;
		writer('-');
		if (data.pre - (*decimal).len > 0)
			(*decimal).len -= 1;
		else
			(*decimal).decalage -= 1;
	}
	write_char('0', data.pre - (*decimal).len);
	ft_putlnbr_fd((*decimal).n, 1);
}

void	formater_d(t_printf data, va_list ap)
{
	t_decimal	decimal;

	if (formater_d_init(&data, &decimal, ap) == 0)
		return ;
	if (data.neg == -1)
	{
		formater_d_print_neg(data, &decimal);
	}
	else if (data.neg >= 0)
	{
		formater_d_print_pos(data, &decimal);
	}
	printed(decimal.len + decimal.decalage);
}
