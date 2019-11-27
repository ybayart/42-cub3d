/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 02:07:26 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 02:07:42 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_draw	init_draw(t_draw draw, int state)
{
	if (state == 0)
	{
		draw.pos_x = g_data.posx;
		draw.pos_y = g_data.posy;
		draw.dir_x = -1;
		draw.dir_y = 0;
		draw.plane_x = 0;
		draw.plane_y = 0.65;
		draw.x = -1;
		draw.w = g_data.window.width;
		draw.h = g_data.window.height;
		draw.vertical = 0;
	}
	else if (state == 2)
	{
		draw.camera_x = 2 * draw.x / (double)draw.w - 1;
		draw.ray_dir_x = draw.dir_x + draw.plane_x * draw.camera_x;
		draw.ray_dir_y = draw.dir_y + draw.plane_y * draw.camera_x;
		draw.map_x = (int)draw.pos_x;
		draw.map_y = (int)draw.pos_y;
		draw.delta_dist_x = fabs(1 / draw.ray_dir_x);
		draw.delta_dist_y = fabs(1 / draw.ray_dir_y);
		draw.hit = 0;
	}
	return (draw);
}

t_draw	get_orient(t_draw draw)
{
	if (draw.ray_dir_x < 0)
	{
		draw.step_x = -1;
		draw.side_dist_x = (draw.pos_x - draw.map_x) * draw.delta_dist_x;
		draw.color = 0255000000;
	}
	else
	{
		draw.step_x = 1;
		draw.side_dist_x = (draw.map_x + 1.0 - draw.pos_x) * draw.delta_dist_x;
		draw.color = 0000255000;
	}
	if (draw.ray_dir_y < 0)
	{
		draw.step_y = -1;
		draw.side_dist_y = (draw.pos_y - draw.map_y) * draw.delta_dist_y;
		draw.color = 0255000000;
	}
	else
	{
		draw.step_y = 1;
		draw.side_dist_y = (draw.map_y + 1.0 - draw.pos_y) * draw.delta_dist_y;
		draw.color = 0000255000;
	}
	return (draw);
}

t_draw	get_dist(t_draw draw)
{
	while (draw.hit == 0)
	{
		if (draw.side_dist_x < draw.side_dist_y)
		{
			draw.side_dist_x += draw.delta_dist_x;
			draw.map_x += draw.step_x;
			draw.side = 0;
		}
		else
		{
			draw.side_dist_y += draw.delta_dist_y;
			draw.map_y += draw.step_y;
			draw.side = 1;
		}
		if (g_data.map[draw.map_x][draw.map_y] == '1')
			draw.hit = 1;
	}
	if (draw.side == 0)
		draw.perp_wall_dist = (draw.map_x - draw.pos_x + (1 - draw.step_x) / 2)
			/ draw.ray_dir_x + fabs(draw.vertical / (252 * 6.66));
	else
		draw.perp_wall_dist = (draw.map_y - draw.pos_y + (1 - draw.step_y) / 2)
			/ draw.ray_dir_y + fabs(draw.vertical / (252 * 6.66));
	draw.line_height = (int)(draw.h / (draw.perp_wall_dist));
	return (draw);
}

t_draw	get_drawpos(t_draw draw)
{
	draw.draw_start = (-draw.line_height / 2 + draw.h / 2) + draw.vertical;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = (draw.line_height / 2 + draw.h / 2) + draw.vertical;
	if (draw.draw_end >= draw.h)
		draw.draw_end = draw.h - 1;
	if (draw.side == 0)
		draw.color = 0255255000;
	return (draw);
}

void	draw(void)
{
	t_draw	draw;
	t_img	img;

	draw = g_data.draw;
	create_background();
	img = g_data.texture.background;
	while (++draw.x < draw.w)
	{
		draw = init_draw(draw, 2);
		draw = get_orient(draw);
		draw = get_dist(draw);
		draw = get_drawpos(draw);
		while (draw.draw_start < draw.draw_end)
			img_set_pixel(create_tcolor(draw.color),
				img, draw.x, draw.draw_start++);
	}
	mlx_put_image_to_window(
		g_data.window.mlx, g_data.window.win, img.ptr, 0, 0);
}
