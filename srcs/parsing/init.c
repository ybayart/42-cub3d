/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:12 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/15 20:36:25 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(void)
{
	g_data.window.height = -1;
	g_data.window.width = -1;
	g_data.texture.north.path = NULL;
	g_data.texture.south.path = NULL;
	g_data.texture.west.path = NULL;
	g_data.texture.east.path = NULL;
	g_data.texture.sprite.path = NULL;
	g_data.texture.floor.r = -1;
	g_data.texture.ceiling.r = -1;
	g_data.next = NULL;
	g_data.map = NULL;
	g_data.error = NULL;
	g_data.posx = -1;
	g_data.posy = -1;
}
