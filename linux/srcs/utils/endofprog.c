/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endofprog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:58:08 by ybayart           #+#    #+#             */
/*   Updated: 2020/05/04 15:49:18 by hexa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_xpm *xpm)
{
	if ((*xpm).path != NULL)
	{
		free((*xpm).path);
		mlx_destroy_image(g_data.window.mlx, (*xpm).img.ptr);
	}
}

int		endofprog(void)
{
	free_img(&(g_data.texture.south));
	free_img(&(g_data.texture.north));
	free_img(&(g_data.texture.west));
	free_img(&(g_data.texture.east));
	free_img(&(g_data.texture.sprite));
	free_img(&(g_data.texture.floor));
	free_img(&(g_data.texture.ceiling));
	if (g_data.next != NULL)
		free(g_data.next);
	if (g_data.map != NULL)
		free_2d((void**)g_data.map);
	mlx_destroy_image(g_data.window.mlx, g_data.img.ptr);
	free(g_data.window.win);
	free(g_data.window.mlx);
	ft_printf("End at state %d\n", updstate());
	exit(EXIT_SUCCESS);
}
