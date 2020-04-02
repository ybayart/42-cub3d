/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater_pe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:32:30 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:39:21 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	formater_pe(t_printf data, va_list ap)
{
	if (data.len == 0)
		if ((data.len = va_arg(ap, int)) < 0)
		{
			data.neg = -1;
			data.len *= -1;
		}
	if (data.len < 1)
		data.len = 1;
	if (data.neg == -1)
	{
		writer('%');
		write_char(' ', data.len - 1);
	}
	else if (data.neg >= 0)
	{
		if (data.neg == 0)
			write_char('0', data.len - 1);
		else
			write_char(' ', data.len - 1);
		writer('%');
	}
}
