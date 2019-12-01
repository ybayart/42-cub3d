/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 18:18:01 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/04 19:23:04 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int tmp;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			i = 0;
			tmp = 0;
			while (needle[i] != '\0')
			{
				if (haystack[i] != needle[i])
					tmp = 1;
				i++;
			}
			if (tmp == 0)
				return ((char*)haystack);
		}
		haystack++;
	}
	return (0);
}
