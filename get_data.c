/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 22:55:38 by nhill             #+#    #+#             */
/*   Updated: 2021/03/16 15:36:13 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_data_part4(t_info *info, char *line, int i, int *flag_map)
{
	if (line[i] == 'F' && line[i + 1] == ' ' && *flag_map == 0 &&
		info->data.f == NULL)
	{
		if (!(info->data.f = ft_strtrim(line + i, " ")))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'F' && line[i + 1] == ' ' && (flag_map != 0 ||
		info->data.f != NULL))
		return (WRONG_INPUT);
	if (line[i] == 'C' && line[i + 1] == ' ' && *flag_map == 0 &&
		info->data.c == NULL)
	{
		if (!(info->data.c = ft_strtrim(line + i, " ")))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ' && (flag_map != 0 ||
		info->data.c != NULL))
		return (WRONG_INPUT);
	else if (line[i] != 'R' && (line[i] != 'N' && line[i + 1] != 'O') &&
		(line[i] != 'S' && line[i + 1] != 'O') && (line[i] != 'W' && line[i + 1]
		!= 'E') && (line[i] != 'E' && line[i + 1] != 'A') && line[i] != 'S' &&
		line[i] != 'F' && line[i] != 'C')
		return (WRONG_INPUT);
	return (SUCCESS);
}

static	int		get_data_part3(t_info *info, char *line, int i, int *flag_map)
{
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '
	&& *flag_map == 0 && info->data.e == NULL)
	{
		if (!(info->data.e = ft_strdup(line + i)))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'E' && (flag_map != 0 ||
		info->data.e != NULL || line[i + 1] == ' ' || line[i + 1] != 'A'))
		return (WRONG_INPUT);
	if (line[i] == 'S' && line[i + 1] == ' ' && *flag_map == 0 &&
		info->data.sp == NULL)
	{
		if (!(info->data.sp = ft_strdup(line + i)))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'S' && line[i + 1] == ' ' && (flag_map != 0 ||
		info->data.sp != NULL))
		return (WRONG_INPUT);
	if ((info->error = get_data_part4(info, line, i, flag_map)) != SUCCESS)
		return (info->error);
	return (SUCCESS);
}

static int		get_data_part2(t_info *info, char *line, int i, int *flag_map)
{
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' '
	&& *flag_map == 0 && info->data.s == NULL)
	{
		if (!(info->data.s = ft_strdup(line + i)))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O' && (*flag_map != 0 ||
		info->data.s != NULL || line[i + 2] != ' '))
		return (WRONG_INPUT);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' '
	&& *flag_map == 0 && info->data.w == NULL)
	{
		if (!(info->data.w = ft_strdup(line + i)))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'W' && (flag_map != 0 ||
		info->data.w != NULL || line[i + 2] != ' ' || line[i + 1] != 'E'))
		return (WRONG_INPUT);
	if ((info->error = get_data_part3(info, line, i, flag_map)) != SUCCESS)
		return (info->error);
	return (SUCCESS);
}

int				get_data(t_info *info, char *line, int i, int *flag_map)
{
	if (line[i] == 'R' && line[i + 1] == ' ' && *flag_map == 0
	&& info->data.r == NULL)
	{
		if (!(info->data.r = ft_strdup(line + i)))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'R' && (*flag_map != 0 ||
	info->data.r != NULL || line[i + 1] != ' '))
		return (WRONG_INPUT);
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' '
	&& *flag_map == 0 && info->data.n == NULL)
	{
		if (!(info->data.n = ft_strdup(line + i)))
			return (MALLOC_FAIL);
	}
	else if (line[i] == 'N' && (*flag_map != 0 ||
		info->data.n != NULL || line[i + 2] != ' ' || line[i + 1] != 'O'))
		return (WRONG_INPUT);
	if ((info->error = get_data_part2(info, line, i, flag_map)) != SUCCESS)
		return (info->error);
	return (SUCCESS);
}
