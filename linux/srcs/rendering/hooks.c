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
** ft_printf("key: %d\n", key);
*/

int		key_hook(int key)
{
	if (key == ARROW_LEFT || key == ARROW_RIGHT)
		hook_rotate(key, 0);
	else if (key == UP || key == DOWN)
		hook_move(key);
	else if (key == LEFT || key == RIGHT)
		hook_translate(key);
	else if (key == 49)
		hook_action();
	else if (key == ESC)
		endofprog();
	else if (key == 65289)
		mlx_mouse_show(g_data.window.mlx, g_data.window.win);
	else
		return (1);
	draw();
	return (1);
}

int		close_hook(int key)
{
	(void)key;
	endofprog();
	return (1);
}
