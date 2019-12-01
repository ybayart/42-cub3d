/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:36:18 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 01:44:24 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <math.h>

# include "libft.h"
# include "cub3d_tp.h"
# include "libbmp.h"

# define SCREEN_W 2560
# define SCREEN_H 1440
# define ROT 0.050
# define MOV 0.1
# define COL 2.5
# define MMP_DECA g_data.window.width / 100
# define MMP_SIZE g_data.window.width / 10
# define FOG 7

t_data	g_data;

int		main(int argc, char **argv);
int		updstate(void);
void	init_data(void);
int		test_args(int argc, char **argv);
int		open_map(void);
int		print_error(void);
int		parse_map(void);
int		parse_map_opts_r(char **opts, int nbopts);
int		parse_map_opts_t(char **opts, int nbopts, char texture);
int		parse_map_opts_n(char **opts, int nbopts);
int		parse_map_opts_l(char **opts, int nbopts);
int		parse_map_matrix(char *line);
int		verif_map(void);
void	free_2d(void **arg);
int		error_msg(char *context);
int		endofprog(void);
void	display_info(void);
t_draw	init_draw(t_draw draw, int state);
t_img	create_img(void);
void	img_set_px(t_color color, t_img img, int x, int y);
t_color	img_get_px(t_img img, int x, int y);
t_img	create_hud(t_img img, t_draw draw);
t_img	hud_cross(t_img img);
t_img	hud_minimap(t_img img, t_draw draw);
t_img	hud_life(t_img img);
t_color	create_tcolor(int color);
t_color	create_rgbcolor(char c);
t_color	color_fog(t_color color, t_draw draw);
int		open_textures(void);
void	draw(void);
int		draw_get_dist(t_draw draw);
t_draw	draw_get_perpdist(t_draw draw);
t_img	draw_extern(t_draw draw, t_img img);
t_draw	get_drawpos(t_draw draw);
int		key_hook(int key);
int		close_hook(int key);
void	hook_move(int key);
void	hook_translate(int key);
void	hook_rotate(int key, double initrot);
void	hook_vertical(int key);
void	hook_action(void);
int		start_mlx(void);
void	set_start_orient(void);
void	next_map(void);
void	sub_life(void);
int		writebmp(int w, int h, char *img);

#endif
