/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:47:10 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:35:59 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*src;
	int				i;

	i = 0;
	src = (unsigned char*)dest;
	while (n > 0)
	{
		src[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (dest);
}
