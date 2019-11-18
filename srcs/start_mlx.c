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
	t_window	win;

	win = g_data.window;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.width, win.height, "Ta soeur");
	
	mlx_loop(win.mlx);
	return (1);
}
