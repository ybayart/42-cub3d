/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 00:18:25 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 00:18:27 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_msg(char *context)
{
	if (ft_strcmp(context, "parsemap") == 0)
		g_data.error = "Couldn't parse map file";
	else if (ft_strcmp(context, "openmap") == 0)
		g_data.error = "Couldn't open map file";
	else if (ft_strcmp(context, "entrymap") == 0)
		g_data.error = "No entry for map";
	else if (ft_strcmp(context, "saveopt") == 0)
		g_data.error = "Save flag are incorrect";
	else if (ft_strcmp(context, "missinfo") == 0)
		g_data.error = "Some informations are missing into map file";
	else if (ft_strcmp(context, "opentext") == 0)
		g_data.error = "Couldn't open texture file";
	else
		g_data.error = "Unknown error";
	return (0);
}
