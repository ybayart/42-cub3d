/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 02:05:29 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 02:05:31 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_set_pixel(t_color color, t_img img, int x, int y)
{
	*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
	*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
	*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
}

t_color	img_get_pixel(t_img img, int x, int y)
{
	t_color	color;

	color.r = (unsigned)*(img.data + (x * 4 + 2) + (img.size * y));
	color.g = (unsigned)*(img.data + (x * 4 + 1) + (img.size * y));
	color.b = (unsigned)*(img.data + (x * 4 + 0) + (img.size * y));
	return (color);
}

void	create_background(void)
{
	t_img		img;
	t_window	win;
	int			x;
	int			y;

	win = g_data.window;
	img.ptr = mlx_new_image(win.mlx, win.width, win.height);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);
	x = -1;
	while (++x < win.width)
	{
		y = -1;
		while (++y < win.height)
			if (y < win.height / 2 + g_data.draw.vertical)
				img_set_pixel(g_data.texture.ceiling, img, x, y);
			else
				img_set_pixel(g_data.texture.floor, img, x, y);
	}
	g_data.texture.background = img;
}

t_img	create_hud(t_img img)
{
	int		x;
	int		y;
	t_color	color;

	color.r = 255;
	color.g = 0;
	color.b = 0;
	x = g_data.window.width / 2 - (g_data.window.width / 50) - 1;
	y = g_data.window.height / 2 - (g_data.window.height / 50) - 1;
	while (++x < g_data.window.width / 2 + (g_data.window.width / 50))
		img_set_pixel(color, img, x, g_data.window.height / 2);
	while (++y < g_data.window.height / 2 + (g_data.window.height / 50))
		img_set_pixel(color, img, g_data.window.width / 2, y);
	return (img);
}
