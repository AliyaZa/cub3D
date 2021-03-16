/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:31:43 by nhill             #+#    #+#             */
/*   Updated: 2020/11/09 19:03:22 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c && ((c == 32) || ((c >= 9) && (c <= 13))))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	ch;
	unsigned int	l_ch;
	int				i;
	int				zn;

	ch = 0;
	i = 0;
	zn = 1;
	while (str[i] && (ft_isspace(str[i])))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			zn = -zn;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		l_ch = ch;
		ch = ch * 10 + (unsigned int)(str[i++] - '0');
		if (l_ch > ch)
			return (zn > 0 ? -1 : 0);
	}
	return (ch * zn);
}
