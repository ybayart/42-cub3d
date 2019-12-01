/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 05:31:49 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/12 05:39:37 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(long long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_nbrlen_base(long long n, int base)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}
