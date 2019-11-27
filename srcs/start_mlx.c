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

int		start_mlx(void)
{
	g_data.window.mlx = mlx_init();
	g_data.window.win = mlx_new_window(g_data.window.mlx, g_data.window.width,
		g_data.window.height, "Cub3D");
	create_background();
	g_data.draw = init_draw(g_data.draw, 0);
	draw();
	mlx_hook(g_data.window.win, 2, 1L << 0, key_hook, g_data.window.mlx);
	mlx_loop(g_data.window.mlx);
	return (1);
}
