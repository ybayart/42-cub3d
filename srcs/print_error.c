/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:58:13 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 01:33:37 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(g_data.error, 1);
	if (g_data.iserrno == 1)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(strerror(errno), 1);
	}
	ft_putchar_fd('\n', 1);
	return (1);
}
