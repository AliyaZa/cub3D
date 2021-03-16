/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:20:08 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:58:19 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (count * size))))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
