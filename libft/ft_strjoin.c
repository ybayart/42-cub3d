/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:08:20 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/06 22:27:27 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((dst = ft_calloc(sizeof(char), size)) == NULL)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dst + i) = *(s1 + i);
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(dst + i + j) = *(s2 + j);
		j++;
	}
	*(dst + i + j) = '\0';
	return (dst);
}

char	*ft_strjoin_free(const char *s1, const char *s2)
{
	int		size;
	int		i;
	int		j;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((dst = ft_calloc(sizeof(char), size)) == NULL)
		return (NULL);
	i = -1;
	while (*(s1 + ++i))
		*(dst + i) = *(s1 + i);
	j = -1;
	while (*(s2 + ++j))
		*(dst + i + j) = *(s2 + j);
	*(dst + i + j) = '\0';
	free((char*)s1);
	return (dst);
}
