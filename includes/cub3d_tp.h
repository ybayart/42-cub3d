/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D_tp.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:29:49 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 02:36:11 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TP_H
# define CUB3D_TP_H

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	t_color		floor;
	t_color		ceiling;
}				t_texture;

typedef struct	s_window
{
	int			*mlx;
	int			*win;
	int			height;
	int			width;
}				t_window;

typedef struct	s_data
{
	int			posx;
	int			posy;
	int			fd;
	char		*pathmap;
	char		**map;
	char		save;
	char		*error;
	char		iserrno;
	t_window	window;
	t_texture	texture;
}				t_data;

#endif
