/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:22:37 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/30 20:22:38 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_map(void)
{
	char	*argv[3];

	ft_printf("-------------------------------------------\nNext level...\n");
	if (g_data.next != NULL)
	{
		argv[0] = g_data.exec;
		argv[1] = g_data.next;
		argv[2] = 0;
		execv(g_data.exec, argv);
	}
	endofprog();
}
