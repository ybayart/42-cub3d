/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:44:13 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/29 15:44:23 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	next_map(void)
{
	char	*argv[3];

	if (g_data.next != NULL)
	{
		argv[0] = g_data.exec;
		argv[1] = g_data.next;
		argv[2] = 0;
		execv(g_data.exec, argv);
	}
	endofprog();
}
