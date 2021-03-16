/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:20:49 by nhill             #+#    #+#             */
/*   Updated: 2021/03/09 19:37:18 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		place_sprite(t_info *info)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < info->map.kol_line)
	{
		x = 0;
		while (x < info->map.place_char)
		{
			if (info->map.tab_map[y][x] == '2')
			{
				info->tab_sprite[i].pos_x = x + 0.5;
				info->tab_sprite[i].pos_y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void		sort_sprite(int *order, double *dist, int num)
{
	int		i;
	int		temp;
	double	temp2;

	i = 0;
	while (i < num - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			temp2 = dist[i + 1];
			dist[i + 1] = dist[i];
			dist[i] = temp2;
			temp = order[i + 1];
			order[i + 1] = order[i];
			order[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

static void		order_sprite(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->kol_sprite)
	{
		info->rc.sp_order[i] = i;
		info->rc.sp_distance[i] = ((info->pos.x - info->tab_sprite[i].pos_x) *
			(info->pos.x - info->tab_sprite[i].pos_x) +
			(info->pos.y - info->tab_sprite[i].pos_y) *
			(info->pos.y - info->tab_sprite[i].pos_y));
		i++;
	}
	sort_sprite(info->rc.sp_order, info->rc.sp_distance, info->kol_sprite);
	add_sprite(info);
}

int				init_sprite(t_info *info)
{
	int		i;

	i = 0;
	if (!(info->tab_sprite = malloc(sizeof(t_sprite) * info->kol_sprite)))
		return (MALLOC_FAIL);
	if (!(info->rc.sp_order = malloc(sizeof(int) * info->kol_sprite)))
		return (MALLOC_FAIL);
	if (!(info->rc.sp_distance = malloc(sizeof(double) * info->kol_sprite)))
		return (MALLOC_FAIL);
	place_sprite(info);
	order_sprite(info);
	if (info->tab_sprite)
		free(info->tab_sprite);
	if (info->rc.sp_order)
		free(info->rc.sp_order);
	if (info->rc.sp_distance)
		free(info->rc.sp_distance);
	return (SUCCESS);
}
