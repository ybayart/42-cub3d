/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:03:29 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 03:03:30 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** 123: LEFT
** 124: RIGHT
** 125: DOWN
** 126: UP
*/

void	rotate(int key)
{
	t_draw	*d;

	d = &g_data.draw;
	if (key == 123)
	{
		d->old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(ROT) - d->dir_y * sin(ROT);
		d->dir_y = d->old_dir_x * sin(ROT) + d->dir_y * cos(ROT);
		d->old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(ROT) - d->plane_y * sin(ROT);
		d->plane_y = d->old_plane_x * sin(ROT) + d->plane_y * cos(ROT);
	}
	else
	{
		d->old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(-ROT) - d->dir_y * sin(-ROT);
		d->dir_y = d->old_dir_x * sin(-ROT) + d->dir_y * cos(-ROT);
		d->old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(-ROT) - d->plane_y * sin(-ROT);
		d->plane_y = d->old_plane_x * sin(-ROT) + d->plane_y * cos(-ROT);
	}
}

void	move(int key)
{
	t_draw	*d;

	d = &g_data.draw;
	if (key == 13)
	{
		if (g_data.map[(int)(d->pos_x + d->dir_x * MOV * COL)][(int)d->pos_y]
																		!= '1')
			d->pos_x += d->dir_x * MOV;
		if (g_data.map[(int)d->pos_x][(int)(d->pos_y + d->dir_y * MOV * COL)]
																		!= '1')
			d->pos_y += d->dir_y * MOV;
	}
	else if (key == 1)
	{
		if (g_data.map[(int)(d->pos_x - d->dir_x * MOV * COL)][(int)d->pos_y]
																		!= '1')
			d->pos_x -= d->dir_x * MOV;
		if (g_data.map[(int)d->pos_x][(int)(d->pos_y - d->dir_y * MOV * COL)]
																		!= '1')
			d->pos_y -= d->dir_y * MOV;
	}
}

void	translate(int key)
{
	t_draw	*d;

	d = &g_data.draw;
	if (key == 0)
	{
		if (g_data.map[(int)(d->pos_x - d->dir_y * MOV * COL)][(int)d->pos_y]
																		!= '1')
			d->pos_x -= d->dir_y * MOV;
		if (g_data.map[(int)d->pos_x][(int)(d->pos_y + d->dir_x * MOV * COL)]
																		!= '1')
			d->pos_y += d->dir_x * MOV;
	}
	else if (key == 2)
	{
		if (g_data.map[(int)(d->pos_x + d->dir_y * MOV * COL)][(int)d->pos_y]
																		!= '1')
			d->pos_x += d->dir_y * MOV;
		if (g_data.map[(int)d->pos_x][(int)(d->pos_y - d->dir_x * MOV * COL)]
																		!= '1')
			d->pos_y -= d->dir_x * MOV;
	}
}

void	vertical(int key)
{
	t_draw	*d;

	d = &g_data.draw;
	if (key == 126)
	{
		if (d->vertical < g_data.window.height / 3)
			d->vertical += g_data.window.height / 50;
	}
	else if (key == 125)
	{
		if (d->vertical > -g_data.window.height / 3)
			d->vertical -= g_data.window.height / 50;
	}
}

int		key_hook(int key)
{
	if (key == 123 || key == 124)
		rotate(key);
	else if (key == 1 || key == 13)
		move(key);
	else if (key == 0 || key == 2)
		translate(key);
	else if (key == 125 || key == 126)
		vertical(key);
	else
		return (1);
	draw();
	return (1);
}
