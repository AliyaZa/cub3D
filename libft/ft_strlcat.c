/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:28:58 by nhill             #+#    #+#             */
/*   Updated: 2020/11/10 15:15:23 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lens;
	size_t	lend;

	i = 0;
	lens = 0;
	while (dst[i])
		i++;
	lend = i;
	if (dstsize > i)
		while (src[lens] && dstsize - i > 1)
			dst[i++] = src[lens++];
	dst[i] = '\0';
	while (src[lens])
		lens++;
	return ((lend < dstsize ? lend : dstsize) + lens);
}
