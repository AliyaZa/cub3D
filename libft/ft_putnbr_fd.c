/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:33:12 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 17:02:15 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long n, int fd)
{
	char		c;

	if (n > 9)
		ft_putnbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	nn;

	nn = n;
	if (n < 0)
	{
		nn = -nn;
		write(fd, "-", 1);
	}
	ft_putnbr(nn, fd);
}
