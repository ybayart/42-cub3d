/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:14:45 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/08 18:20:12 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
}

void	ft_putlnbr_fd(long n, int fd)
{
	long long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putlnbr_fd(ln / 10, fd);
		ft_putlnbr_fd(ln % 10, fd);
	}
}

void	ft_putnbr_base_fd(int n, int fd, char *base)
{
	long	ln;
	int		lenbase;

	lenbase = ft_strlen(base);
	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln < lenbase)
		ft_putchar_fd(base[ln], fd);
	else
	{
		ft_putnbr_base_fd(ln / lenbase, fd, base);
		ft_putnbr_base_fd(ln % lenbase, fd, base);
	}
}

void	ft_putunbr_fd(unsigned long long n, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
}

void	ft_putunbr_base_fd(unsigned long long n, int fd, char *base)
{
	unsigned int	lenbase;

	lenbase = ft_strlen(base);
	if (n < lenbase)
		ft_putchar_fd(base[n], fd);
	else
	{
		ft_putunbr_base_fd(n / lenbase, fd, base);
		ft_putunbr_base_fd(n % lenbase, fd, base);
	}
}
