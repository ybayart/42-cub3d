/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 05:03:29 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/13 21:34:57 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	formater(t_printf data, va_list ap)
{
	if (data.type == 'd' || data.type == 'i')
		formater_d(data, ap);
	else if (data.type == 'u')
		formater_u(data, ap);
	else if (data.type == 'x' || data.type == 'X')
		formater_x(data, ap);
	else if (data.type == 'c')
		formater_c(data, ap);
	else if (data.type == 's')
		formater_s(data, ap);
	else if (data.type == 'p')
		formater_p(data, ap);
	else if (data.type == '%')
		formater_pe(data, ap);
}

/*
** printf("\n--------------------\n
** -> neg: %d\n-> len: %d\n-> pre: %d\n-> typ: %c\n
** --------------------\n", data.neg, data.len, data.pre, data.type);
*/
