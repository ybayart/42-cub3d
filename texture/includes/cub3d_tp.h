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

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_xpm
{
	char		*path;
	t_img		img;
	int			height;
	int			width;
}				t_xpm;

typedef struct	s_texture
{
	t_xpm		north;
	t_xpm		south;
	t_xpm		west;
	t_xpm		east;
	t_xpm		sprite;
	t_xpm		floor;
	t_xpm		ceiling;
}				t_texture;

typedef struct	s_window
{
	int			*mlx;
	int			*win;
	int			height;
	int			width;
}				t_window;

typedef struct	s_draw
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			h;
	int			w;
	int			x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		init_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	t_color		color;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		old_dir_x;
	double		old_plane_x;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		floor_x_w;
	double		floor_y_w;
	double		dist_w;
	double		dist_player;
	double		dist_current;
	double		weight;
	double		floor_x;
	double		floor_y;
	int			ftex_x;
	int			ftex_y;
	int			checker_board_pattern;
	int			floor_texture;
	char		fog;
	t_xpm		xpm;

}				t_draw;

typedef struct	s_life
{
	int			life;
	int			health;
	int			inithealth;
	int			sub;
}				t_life;

typedef struct	s_data
{
	double		posx;
	double		posy;
	char		orient;
	int			fd;
	char		*pathmap;
	char		**map;
	char		save;
	char		*error;
	char		iserrno;
	char		*exec;
	char		*next;
	t_img		img;
	t_window	window;
	t_texture	texture;
	t_draw		draw;
	t_life		life;
}				t_data;

#endif
