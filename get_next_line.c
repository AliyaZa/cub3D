/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:17:36 by nhill             #+#    #+#             */
/*   Updated: 2021/02/26 22:24:03 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		get_mem_free(char **str, int exit)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (exit);
}

static char		*get_str_fill(int bytes, char *str, char *buf)
{
	char	*str_temp;

	str_temp = str;
	*(buf + bytes) = '\0';
	str = ft_strjoin(str, buf);
	free(str_temp);
	str_temp = NULL;
	return (str);
}

static void		get_line_create(char **str, char **line)
{
	char	*n;

	if ((n = ft_strchr(*str, '\n')))
	{
		*line = ft_substr(*str, 0, n - *str);
		*str = ft_strdup(n + 1);
	}
	else
	{
		*line = ft_strdup(*str);
		*str = ft_strdup("");
	}
}

int				get_next_line(int fd, char **line)
{
	int				bytes;
	char			*buf;
	char			*str_temp;
	static char		*str;

	bytes = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || !(line) ||
			(!str && !(str = ft_strdup(""))))
		return (-1);
	if (!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while (!(ft_strchr(str, '\n')) && (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		str = get_str_fill(bytes, str, buf);
	free(buf);
	if (bytes < 0 || !str)
		return (get_mem_free(&str, -1));
	str_temp = str;
	get_line_create(&str, line);
	free(str_temp);
	if (!bytes && (!*str))
		return (get_mem_free(&str, 0));
	return (1);
}
