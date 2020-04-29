/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:56:13 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 02:56:25 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/X.h>

void	set_start_orient(void)
{
	char	pos;
	int		deg;

	pos = g_data.orient;
	g_data.map[(int)g_data.posx][(int)g_data.posy] = '0';
	deg = 0;
	if (pos == 'E')
		deg = 90;
	else if (pos == 'W')
		deg = -90;
	else if (pos == 'S')
		deg = 180;
	if (deg != 0)
		hook_rotate(0, (deg) * M_PI / 180.0);
}

int		mouse_hook(int x, int y)
{
	if (x != g_data.window.width / 2 || y != g_data.window.height / 2)
	{
		printf("%.3d %.3d\n", x - g_data.window.width / 2, y - g_data.window.height / 2);
		sleep(0.5);
		mlx_mouse_move(g_data.window.mlx, g_data.window.win, g_data.window.width / 2, g_data.window.height / 2);
	}
}

int		start_mlx(void)
{
	g_data.window.mlx = mlx_init();
	g_data.window.win = mlx_new_window(g_data.window.mlx, g_data.window.width,
		g_data.window.height, "Cub3D");
	if (open_textures() == 0)
		return (error_msg("opentext"));
	updstate();
	g_data.img = create_img();
	g_data.orient = g_data.map[(int)g_data.posx][(int)g_data.posy];
	g_data.draw = init_draw(g_data.draw, 0);
	set_start_orient();
	if (g_data.save == 1)
		ft_printf("Saving image...\n");
	draw();
	if (g_data.save == 0)
	{
		int	x, y;
		mlx_get_screen_size(g_data.window.mlx, &x, &y);
		printf("size: %dx%d\n", x, y);
//		mlx_mouse_hide(g_data.window.mlx, g_data.window.win);
		mlx_hook(g_data.window.win, KeyPress, KeyPressMask, key_hook, g_data.window.mlx);
		mlx_hook(g_data.window.win, DestroyNotify, StructureNotifyMask, close_hook, g_data.window.mlx);
//		mlx_hook(g_data.window.win, MotionNotify, PointerMotionMask, mouse_hook, g_data.window.mlx);
		mlx_loop(g_data.window.mlx);
	}
	else
		ft_printf("Saved !\n");
	return (1);
}
