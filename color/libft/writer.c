/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:53:58 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/12 06:30:20 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	printed(int inc)
{
	static size_t	n = 0;

	n += inc;
	return (n);
}

void	write_char(char c, int n)
{
	while (n-- > 0)
		writer(c);
}

void	writer(char c)
{
	write(1, &c, 1);
	printed(1);
}

void	uwriter(unsigned char c)
{
	write(1, &c, 1);
	printed(1);
}
