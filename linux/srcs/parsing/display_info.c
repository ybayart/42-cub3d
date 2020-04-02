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

static void		print_map(void)
{
	int		i;
	int		j;

	ft_printf("Map:\n");
	i = -1;
	while (g_data.map[++i])
	{
		ft_printf(" | ");
		j = -1;
		while (g_data.map[i][++j])
			if (g_data.map[i][j] >= '0' && g_data.map[i][j] <= '7')
			{
				ft_printf((g_data.map[i][j] == '0') ? "  " : "");
				ft_printf((g_data.map[i][j] == '1') ? "x " : "");
				ft_printf((g_data.map[i][j] == '2') ? "* " : "");
				ft_printf((g_data.map[i][j] == '3') ? "- " : "");
				ft_printf((g_data.map[i][j] == '4') ? "o " : "");
				ft_printf((g_data.map[i][j] == '5') ? "= " : "");
				ft_printf((g_data.map[i][j] == '6') ? "+ " : "");
				ft_printf((g_data.map[i][j] == '7') ? "! " : "");
			}
			else
				ft_printf("%c ", g_data.map[i][j]);
		ft_printf("\n");
	}
}

void			display_info(void)
{
	ft_printf("Dimensions: %dx%d\n", g_data.window.width, g_data.window.height);
	ft_printf("Textures:\n");
	ft_printf(" - north:   %s\n", g_data.texture.north.path);
	ft_printf(" - south:   %s\n", g_data.texture.south.path);
	ft_printf(" - west:    %s\n", g_data.texture.west.path);
	ft_printf(" - east:    %s\n", g_data.texture.east.path);
	ft_printf(" - sprite:  %s\n", g_data.texture.sprite.path);
	ft_printf(" - floor:   %s\n", g_data.texture.floor.path);
	ft_printf(" - ceiling: %s\n", g_data.texture.ceiling.path);
	print_map();
	ft_printf("Player pos:\n - x: %3d.5\n - y: %3d.5\n",
		(int)g_data.posx, (int)g_data.posy);
	ft_printf("Lives:\n");
	ft_printf(" - Life:       %d\n", g_data.life.life);
	ft_printf(" - health:     %d%%\n", g_data.life.health);
	ft_printf(" - InitHealth: %d%%\n", g_data.life.inithealth);
	ft_printf(" - Damage:     %d%%\n", g_data.life.sub);
}
