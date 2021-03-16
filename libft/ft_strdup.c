/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:54:53 by nhill             #+#    #+#             */
/*   Updated: 2021/03/06 19:04:54 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_w_ls(const char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			flag = 1;
		i++;
	}
	if (flag == 1 && str[i] == ' ')
	{
		while (str[i] != ' ')
			i--;
	}
	return (i);
}

char		*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen_w_ls(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
