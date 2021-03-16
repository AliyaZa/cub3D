/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:22:53 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:56:35 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;
	char	res;

	s = (char *)str;
	while (*s)
		s++;
	res = (char)ch;
	while (s >= str)
	{
		if (*s == res)
			return (s);
		s--;
	}
	return (NULL);
}
