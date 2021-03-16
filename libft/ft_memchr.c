/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:38:31 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:53:42 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char*)arr;
	while (n > 0)
	{
		if (*a == (unsigned char)c)
			return (a);
		n--;
		a++;
	}
	return (NULL);
}
