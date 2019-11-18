/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 01:43:26 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 01:43:38 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		verif_map_matrix(void)
{
	int		i;
	int		j;

	if (g_data.map == NULL)
		return (0);
	i = -1;
	while (g_data.map[++i])
	{
		if (g_data.map[i][0] != '1' ||
			g_data.map[i][ft_strlen(g_data.map[i]) - 1] != '1')
			return (0);
	}
	j = -1;
	i -= 1;
	while (g_data.map[i][++j])
		if (g_data.map[i][j] != '1')
			return (0);
	j = -1;
	while (g_data.map[0][++j])
		if (g_data.map[0][j] != '1')
			return (0);
	return (1);
}

int		verif_map(void)
{
	if (g_data.window.height == -1 || g_data.window.width == -1 ||
		g_data.texture.north == NULL || g_data.texture.south == NULL ||
		g_data.texture.west == NULL || g_data.texture.east == NULL ||
		g_data.texture.floor.r == -1 || g_data.texture.ceiling.r == -1 ||
		g_data.map == NULL || g_data.posx == -1 || g_data.posy == -1 ||
		verif_map_matrix() == 0)
		return (error_msg("missinfo"));
	return (1);
}