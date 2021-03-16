/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:08:17 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:56:23 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*s;
	char	res;

	s = (char *)str;
	res = (char)ch;
	while (*s)
	{
		if (*s == res)
			return (s);
		s++;
	}
	if (res == '\0')
		return (s);
	return (NULL);
}
