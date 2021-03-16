/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:59:45 by nhill             #+#    #+#             */
/*   Updated: 2020/11/06 16:59:08 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1)) +
					(ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}
