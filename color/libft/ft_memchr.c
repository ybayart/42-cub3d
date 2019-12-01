/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:26:35 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/08 11:57:41 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	cs;
	size_t			i;

	ptr = (unsigned char*)s;
	cs = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(ptr + i) == cs)
		{
			return (ptr + i);
		}
		i++;
	}
	return (0);
}
