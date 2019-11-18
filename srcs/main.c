/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:26:51 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 02:10:51 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	updstate();
	init_data();
	if (test_args(argc, argv) == 0)
		return (print_error());
	updstate();
	if (open_map() == 0)
		return (print_error());
	updstate();
	if (parse_map() == 0)
		return (print_error());
	updstate();
	if (verif_map() == 0)
		return (print_error());
	updstate();
	display_info();
	updstate();
	return (endofprog());
}
