/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endofprog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:58:08 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/15 23:03:27 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		endofprog(void)
{
	if (g_data.texture.north != NULL)
		free(g_data.texture.north);
	if (g_data.texture.south != NULL)
		free(g_data.texture.south);
	if (g_data.texture.west != NULL)
		free(g_data.texture.west);
	if (g_data.texture.east != NULL)
		free(g_data.texture.east);
	if (g_data.texture.sprite != NULL)
		free(g_data.texture.sprite);
	if (g_data.map != NULL)
		free_2d((void**)g_data.map);
	printf("[%d]\n", updstate());
	return (0);
}
