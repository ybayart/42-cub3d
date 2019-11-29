/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:03:37 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/28 15:03:39 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook_move(int key)
{
	t_draw	*d;
	char	x;
	char	y;

	d = &g_data.draw;
	if (key == 13)
	{
		if ((x = g_data.map[(int)(d->pos_x + d->dir_x *
			MOV * COL)][(int)d->pos_y]) == '0')
			d->pos_x += d->dir_x * MOV;
		if ((y = g_data.map[(int)d->pos_x][(int)(d->pos_y + d->dir_y *
			MOV * COL)]) == '0')
			d->pos_y += d->dir_y * MOV;
	}
	else
	{
		if ((x = g_data.map[(int)(d->pos_x - d->dir_x *
			MOV * COL)][(int)d->pos_y]) == '0')
			d->pos_x -= d->dir_x * MOV;
		if ((y = g_data.map[(int)d->pos_x][(int)(d->pos_y - d->dir_y *
			MOV * COL)]) == '0')
			d->pos_y -= d->dir_y * MOV;
	}
	if (x == '4' || y == '4')
		next_map();
}

void	hook_translate(int key)
{
	t_draw	*d;
	char	x;
	char	y;

	d = &g_data.draw;
	if (key == 0)
	{
		if ((x = g_data.map[(int)(d->pos_x - d->dir_y *
			MOV * COL)][(int)d->pos_y]) == '0')
			d->pos_x -= d->dir_y * MOV;
		if ((y = g_data.map[(int)d->pos_x][(int)(d->pos_y + d->dir_x *
			MOV * COL)]) == '0')
			d->pos_y += d->dir_x * MOV;
	}
	else
	{
		if ((x = g_data.map[(int)(d->pos_x + d->dir_y *
			MOV * COL)][(int)d->pos_y]) == '0')
			d->pos_x += d->dir_y * MOV;
		if ((y = g_data.map[(int)d->pos_x][(int)(d->pos_y - d->dir_x *
			MOV * COL)]) == '0')
			d->pos_y -= d->dir_x * MOV;
	}
	if (x == '4' || y == '4')
		next_map();
}

void	hook_action(void)
{
	t_draw	*d;
	int		i;
	int		j;

	d = &g_data.draw;
	i = -2;
	while (++i <= 1)
	{
		j = -2;
		while (++j <= 1)
		{
			if (g_data.map[(int)d->pos_x + i][(int)d->pos_y + j] == '3')
			{
				g_data.map[(int)d->pos_x + i][(int)d->pos_y + j] = '0';
				draw();
				break ;
			}
		}
	}
}
