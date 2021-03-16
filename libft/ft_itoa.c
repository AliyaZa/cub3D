/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:29:59 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 17:00:33 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long ch)
{
	int		i;

	i = 0;
	while (ch > 0)
	{
		i++;
		ch = ch / 10;
	}
	return (i);
}

static char	*ft_create_str(char *str, int i, long nn, int zn)
{
	str[--i] = '\0';
	if (nn == 0)
	{
		str[--i] = '0';
		return (str);
	}
	while (i > 0)
	{
		str[--i] = nn % 10 + '0';
		nn = nn / 10;
	}
	if (zn < 0)
		str[i] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		zn;
	int		i;
	long	ch;
	long	nn;

	zn = 1;
	i = 0;
	nn = n;
	if (nn <= 0)
	{
		i++;
		zn = -zn;
		nn = -nn;
	}
	ch = nn;
	i = i + ft_len(ch);
	if (!(str = (char *)malloc((++i) * sizeof(char))))
		return (NULL);
	return (str = ft_create_str(str, i, nn, zn));
}
