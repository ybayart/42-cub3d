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

# include <stdio.h>

# include "libft.h"
# include "cub3d_tp.h"

# define ROT 0.050
# define MOV 0.1
# define COL 2.5

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
int		parse_map_opts_c(char **opts, int nbopts, char pos);
int		parse_map_matrix(char *line);
int		verif_map(void);
void	free_2d(void **arg);
int		error_msg(char *context);
int		endofprog(void);
void	display_info(void);
t_draw	init_draw(t_draw draw, int state);
void	img_set_pixel(t_color color, t_img img, int x, int y);
void	create_background(void);
t_color	create_tcolor(int color);
void	draw(void);
int		key_hook(int key);
int		start_mlx(void);

#endif
