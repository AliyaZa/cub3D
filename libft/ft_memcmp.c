/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:52:55 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:54:15 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	a = (unsigned char*)arr1;
	b = (unsigned char*)arr2;
	i = 0;
	while (n > 0)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		else
			i++;
		n--;
	}
	return (0);
}
