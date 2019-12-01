/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:57:11 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/28 09:57:13 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_textures_file(t_xpm *xpm)
{
	if ((xpm->img.ptr = mlx_xpm_file_to_image(g_data.window.mlx,
			xpm->path, &xpm->width, &xpm->height)) == NULL)
		return (0);
	xpm->img.data = mlx_get_data_addr(xpm->img.ptr, &xpm->img.bpp,
		&xpm->img.size, &xpm->img.endian);
	return (1);
}

int		open_textures(void)
{
	if (open_textures_file(&g_data.texture.north) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_data.texture.east) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_data.texture.west) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_data.texture.south) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_data.texture.sprite) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_data.texture.floor) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_data.texture.ceiling) == 0)
		return (error_msg("opentextures"));
	return (1);
}
