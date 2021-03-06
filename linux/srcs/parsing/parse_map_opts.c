/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_opts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:04:36 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 02:52:40 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_map_opts_r(char **opts, int nbopts)
{
	int		n1;
	int		n2;

	if (nbopts == 3 && g_data.window.width == -1 && g_data.window.height == -1)
	{
		n1 = ft_str_to_int(opts[1]);
		n2 = ft_str_to_int(opts[2]);
		if ((g_data.window.width = (n1 > SCREEN_W ? SCREEN_W : n1)) == -1)
			return (0);
		if ((g_data.window.height = (n2 > SCREEN_H ? SCREEN_H : n2)) == -1)
			return (0);
	}
	else
		return (0);
	return (1);
}

int		parse_map_opts_t(char **opts, int nbopts, char texture)
{
	if (nbopts == 2)
	{
		if (texture == 'N' && g_data.texture.north.path == NULL)
			g_data.texture.north.path = ft_strdup(opts[1]);
		else if (texture == 'S' && g_data.texture.south.path == NULL)
			g_data.texture.south.path = ft_strdup(opts[1]);
		else if (texture == 'W' && g_data.texture.west.path == NULL)
			g_data.texture.west.path = ft_strdup(opts[1]);
		else if (texture == 'E' && g_data.texture.east.path == NULL)
			g_data.texture.east.path = ft_strdup(opts[1]);
		else if (texture == 'O' && g_data.texture.sprite.path == NULL)
			g_data.texture.sprite.path = ft_strdup(opts[1]);
		else if (texture == 'F' && g_data.texture.floor.path == NULL)
			g_data.texture.floor.path = ft_strdup(opts[1]);
		else if (texture == 'C' && g_data.texture.ceiling.path == NULL)
			g_data.texture.ceiling.path = ft_strdup(opts[1]);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int		parse_map_opts_n(char **opts, int nbopts)
{
	if (nbopts == 2 && g_data.next == NULL)
	{
		g_data.next = ft_strdup(opts[1]);
		return (1);
	}
	return (0);
}

int		parse_map_opts_l(char **opts, int nbopts)
{
	if (nbopts == 5 && g_data.life.life == -1)
	{
		g_data.life.life = ft_str_to_int(opts[1]);
		g_data.life.health = ft_str_to_int(opts[2]);
		g_data.life.inithealth = ft_str_to_int(opts[3]);
		g_data.life.sub = ft_str_to_int(opts[4]);
		return (1);
	}
	return (0);
}
