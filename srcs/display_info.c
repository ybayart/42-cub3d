/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:12:58 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 02:13:17 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_info(void)
{
	t_color	color;
	int		i;

	ft_printf("Dimensions: %dx%d\n", g_data.window.width, g_data.window.height);
	ft_printf("Textures:\n");
	ft_printf(" - north:  %s\n", g_data.texture.north);
	ft_printf(" - south:  %s\n", g_data.texture.south);
	ft_printf(" - west:   %s\n", g_data.texture.west);
	ft_printf(" - east:   %s\n", g_data.texture.east);
	ft_printf(" - sprite: %s\n", g_data.texture.sprite);
	ft_printf("Colors:\n");
	color = g_data.texture.floor;
	ft_printf(" - floor:   %-3d - %-3d - %-3d\n", color.r, color.g, color.b);
	color = g_data.texture.ceiling;
	ft_printf(" - ceiling: %-3d - %-3d - %-3d\n", color.r, color.g, color.b);
	ft_printf("Map:\n");
	i = -1;
	while (g_data.map[++i])
		ft_printf(" | %s\n", g_data.map[i]);
}
