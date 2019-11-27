/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:07:11 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 05:07:13 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color	create_tcolor(int color)
{
	t_color		newcolor;

	newcolor.b = color % 1000;
	color /= 1000;
	newcolor.g = color % 1000;
	color /= 1000;
	newcolor.r = color % 1000;
	return (newcolor);
}
