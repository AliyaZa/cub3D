/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:05:11 by nhill             #+#    #+#             */
/*   Updated: 2021/03/13 18:15:20 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		pos_from_map(t_info *info, int i, int j)
{
	if (info->map.flag_n == 0 && (info->map.tab_map[i][j] == 'N' ||
		info->map.tab_map[i][j] == 'S' || info->map.tab_map[i][j] == 'E'
		|| info->map.tab_map[i][j] == 'W'))
	{
		info->map.flag_n = 1;
		info->map.player = info->map.tab_map[i][j];
		info->pos.x = j + 0.5;
		info->pos.y = i + 0.5;
		info->map.tab_map[i][j] = '0';
	}
	if (info->map.tab_map[i][j] == '2')
		info->kol_sprite++;
}

static int		wrong_char(t_info *info, int i, int j)
{
	if (!(info->map.tab_map[i][j] == '1' || info->map.tab_map[i][j] == '0' ||
		info->map.tab_map[i][j] == '2' || info->map.tab_map[i][j] == 'N' ||
		info->map.tab_map[i][j] == 'S' || info->map.tab_map[i][j] == 'E' ||
		info->map.tab_map[i][j] == 'W' || info->map.tab_map[i][j] == ' '))
		return (WRONG_MAP);
	if (info->map.flag_n == 1 && (info->map.tab_map[i][j] == 'N'
		|| info->map.tab_map[i][j] == 'S' || info->map.tab_map[i][j] == 'E' ||
		info->map.tab_map[i][j] == 'W'))
		return (WRONG_MAP);
	return (SUCCESS);
}

static int		loop(t_info *info)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 1;
	while (info->map.tab_map[i] && i < info->map.kol_line)
	{
		k = ft_strlen(info->map.tab_map[i]);
		info->map.k_total += k;
		j = 1;
		while (info->map.tab_map[i][j])
		{
			if ((info->error = wrong_char(info, i, j)) != SUCCESS)
				return (info->error);
			pos_from_map(info, i, j);
			j++;
		}
		i++;
	}
	info->map.place_char = k;
	return (SUCCESS);
}

int				parse_map(t_info *info)
{
	if ((info->error = closed_map(info)) != SUCCESS)
		return (info->error);
	info->map.k_total = ft_strlen(info->map.tab_map[0]) +
		ft_strlen(info->map.tab_map[info->map.kol_line - 1]);
	if ((info->error = loop(info)) != SUCCESS)
		return (info->error);
	if (info->map.flag_n == 0)
		return (WRONG_MAP);
	return (SUCCESS);
}
