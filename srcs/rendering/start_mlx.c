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

static void	set_orient(void)
{
	char	pos;
	int		deg;

	pos = g_data.map[(int)g_data.posx][(int)g_data.posy];
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

int			start_mlx(void)
{
	g_data.window.mlx = mlx_init();
	g_data.window.win = mlx_new_window(g_data.window.mlx, g_data.window.width,
		g_data.window.height, "Cub3D");
	if (open_textures() == 0)
		return (error_msg("opentext"));
	updstate();
	g_data.img = create_img();
	g_data.draw = init_draw(g_data.draw, 0);
	set_orient();
	if (g_data.save == 1)
		ft_printf("Saving image...\n");
	draw();
	if (g_data.save == 0)
	{
		mlx_hook(g_data.window.win, 2, 1L << 0, key_hook, g_data.window.mlx);
		mlx_hook(g_data.window.win, 17, 1L << 0, close_hook, g_data.window.mlx);
		mlx_loop(g_data.window.mlx);
	}
	else
		ft_printf("Saved !\n");
	return (1);
}
