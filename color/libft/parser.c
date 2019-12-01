/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:13:14 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/12 23:19:15 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_converter(char c)
{
	char	*charset;

	charset = __CONVERTER;
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int			getdigit(const char *s, int *n)
{
	int		i;
	int		ntmp;

	i = 0;
	ntmp = 0;
	while (ft_isdigit(*(s + i)))
		ntmp = (ntmp * 10) + (*(s + i++) - '0');
	if (ntmp != 0)
		*n = ntmp;
	else if (*n == -1)
		*n = -2;
	return (i);
}

t_printf	init_struct(void)
{
	t_printf	data;

	data.neg = 1;
	data.len = -1;
	data.pre = -1;
	return (data);
}

int			opts(const char *s, va_list ap)
{
	int			i;
	t_printf	data;

	i = 1;
	data = init_struct();
	if (*(s + i) == '0' && i++ != 0)
		data.neg = 0;
	while (*(s + i) == '-' && i++ != 0)
		data.neg = -1;
	if (*(s + i) == '*' && i++ != 0)
		data.len = 0;
	else if (ft_isdigit(*(s + i)))
		i += getdigit(s + i, &data.len);
	else if (*(s + i) != '.' && !is_converter(*(s + i)))
		return (0);
	while (*(s + i) == '.' && i++ != 0)
		if (*(s + i) == '*' && i++ != 0)
			data.pre = 0;
		else
			i += getdigit(s + i, &data.pre);
	if (is_converter(*(s + i)) && (data.type = *(s + i)) != 0)
		formater(data, ap);
	else
		return (0);
	return (i);
}

void		parser(const char *s, va_list ap)
{
	int		i;
	int		n;
	int		ntmp;

	i = 0;
	n = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == '%')
		{
			if ((ntmp = opts(s + i, ap)) == 0)
				writer('%');
			i += ntmp;
		}
		else
		{
			writer(*(s + i));
		}
		i++;
	}
}
