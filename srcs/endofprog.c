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
	if (g_data.texture.north.path != NULL)
		free(g_data.texture.north.path);
	if (g_data.texture.south.path != NULL)
		free(g_data.texture.south.path);
	if (g_data.texture.west.path != NULL)
		free(g_data.texture.west.path);
	if (g_data.texture.east.path != NULL)
		free(g_data.texture.east.path);
	if (g_data.texture.sprite.path != NULL)
		free(g_data.texture.sprite.path);
	if (g_data.map != NULL)
		free_2d((void**)g_data.map);
	ft_printf("End at state %d\n", updstate());
	exit(0);
}
