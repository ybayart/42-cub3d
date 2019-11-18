/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:23:08 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 02:24:41 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d(void **arg)
{
	int		i;

	if (arg != NULL)
	{
		i = -1;
		while (arg[++i])
			free(arg[i]);
		free(arg);
		arg = NULL;
	}
}