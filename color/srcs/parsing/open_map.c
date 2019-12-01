/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:51:16 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 01:32:54 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_map(void)
{
	int		len;

	len = ft_strlen(g_data.pathmap);
	if ((g_data.fd = open(g_data.pathmap, O_RDWR)) == -1)
	{
		g_data.iserrno = 1;
		return (error_msg("openmap"));
	}
	else if (len <= 4 || ft_strcmp(g_data.pathmap + len - 4, ".cub") != 0)
		return (error_msg("openmap"));
	return (1);
}
