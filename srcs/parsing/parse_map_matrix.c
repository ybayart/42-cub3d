/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 20:14:15 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/17 20:14:27 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_pos(int n)
{
	static int	i = 0;

	i += n;
	return (i);
}

int		parse_map_matrix_is_ok(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S' || (c >= '0' && c <= '6'))
		return (1);
	return (0);
}

int		parse_map_matrix_update(char *parsed)
{
	char	**map;
	char	**maptmp;
	int		i;
	int		j;

	j = get_pos(1);
	if ((map = malloc(sizeof(char*) * (j + 1))) == NULL)
		return (0);
	i = -1;
	maptmp = g_data.map;
	map[j - 1] = parsed;
	map[j] = 0;
	while (++i < j - 1)
		map[i] = g_data.map[i];
	g_data.map = map;
	free(maptmp);
	return (1);
}

int		parse_map_matrix_check(char **map, int i)
{
	if (ft_strlen(map[i]) != 1 || parse_map_matrix_is_ok(map[i][0]) == 0)
	{
		free_2d((void**)map);
		free_2d((void**)g_data.map);
		return (0);
	}
	else if (map[i][0] == 'N' || map[i][0] == 'S' ||
			map[i][0] == 'E' || map[i][0] == 'W')
	{
		if (g_data.posx == -1 && g_data.posy == -1)
		{
			g_data.posx = get_pos(0) + 0.5;
			g_data.posy = i + 0.5;
		}
		else
			return (0);
	}
	return (1);
}

int		parse_map_matrix(char *line)
{
	char	**map;
	char	*parsed;
	int		i;

	if ((map = ft_split(line, ' ')) == NULL)
		return (0);
	i = -1;
	while (map[++i] != 0)
		if (parse_map_matrix_check(map, i) == 0)
			return (0);
	if ((parsed = malloc(sizeof(char) * (i + 1))) == NULL)
		return (0);
	parsed[i] = '\0';
	while (i--)
		parsed[i] = map[i][0];
	free_2d((void**)map);
	if ((parse_map_matrix_update(parsed)) == 0)
		return (0);
	return (1);
}
