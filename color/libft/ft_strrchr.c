/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:06:14 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/05 19:32:17 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ptr2;
	int		i;

	ptr = (char*)s;
	ptr2 = 0;
	i = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == c)
			ptr2 = ptr + i;
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (ptr2);
}
