/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:38:58 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 00:20:10 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		test_args(int argc, char **argv)
{
	g_data.iserrno = 0;
	if (argc >= 2)
	{
		g_data.pathmap = argv[1];
		if (argc >= 3)
			g_data.save = 1;
		else
			g_data.save = 0;
		return (1);
	}
	return (error_msg("entrymap"));
}
