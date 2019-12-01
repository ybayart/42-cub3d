/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:09:34 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/10 21:44:08 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ((void)NULL);
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnstr_fd(char *s, int fd, int n)
{
	if (s == NULL)
		return ((void)NULL);
	while (*s && n-- > 0)
		write(fd, s++, 1);
}
