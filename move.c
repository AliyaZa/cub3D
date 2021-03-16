/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:21:19 by nhill             #+#    #+#             */
/*   Updated: 2021/03/12 20:17:57 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fn_rotate(t_info *info, int advance)
{
	double	dir;
	double	plane;

	dir = info->rc.dir.x;
	plane = info->rc.plane.x;
	info->rc.dir.x = info->rc.dir.x * cos(advance * 0.05)
		- info->rc.dir.y * sin(advance * 0.05);
	info->rc.dir.y = dir * sin(advance * 0.05)
		+ info->rc.dir.y * cos(advance * 0.05);
	info->rc.plane.x = info->rc.plane.x * cos(advance * 0.05)
		- info->rc.plane.y * sin(advance * 0.05);
	info->rc.plane.y = plane * sin(advance * 0.05)
		+ info->rc.plane.y * cos(advance * 0.05);
}

static void	up_down(t_info *info)
{
	if (info->move.up == 1)
	{
		if (info->map.tab_map[(int)(info->pos.y)][(int)(info->pos.x +
		info->rc.dir.x * info->rc.speed)] == '0')
			info->pos.x += info->rc.dir.x * info->rc.speed;
		if (info->map.tab_map[(int)(info->pos.y + info->rc.dir.y *
			info->rc.speed)][(int)(info->pos.x)] == '0')
			info->pos.y += info->rc.dir.y * info->rc.speed;
	}
	if (info->move.down == 1)
	{
		if (info->map.tab_map[(int)(info->pos.y)][(int)(info->pos.x -
		info->rc.dir.x * info->rc.speed)] == '0')
			info->pos.x -= info->rc.dir.x * info->rc.speed;
		if (info->map.tab_map[(int)(info->pos.y - info->rc.dir.y *
			info->rc.speed)][(int)(info->pos.x)] == '0')
			info->pos.y -= info->rc.dir.y * info->rc.speed;
	}
}

static void	straf(t_info *info)
{
	if (info->move.strafr == 1)
	{
		if (info->map.tab_map[(int)(info->pos.y - info->rc.dir.x *
			info->rc.speed)][(int)(info->pos.x)] == '0')
			info->pos.y -= info->rc.dir.x * info->rc.speed;
		if (info->map.tab_map[(int)(info->pos.y)][(int)(info->pos.x
			+ info->rc.dir.y * info->rc.speed)] == '0')
			info->pos.x += info->rc.dir.y * info->rc.speed;
	}
	if (info->move.strafl == 1)
	{
		if (info->map.tab_map[(int)(info->pos.y + info->rc.dir.x *
			info->rc.speed)][(int)(info->pos.x)] == '0')
			info->pos.y -= -info->rc.dir.x * info->rc.speed;
		if (info->map.tab_map[(int)(info->pos.y)][(int)(info->pos.x -
			info->rc.dir.y * info->rc.speed)] == '0')
			info->pos.x -= info->rc.dir.y * info->rc.speed;
	}
}

void		fn_move(t_info *info)
{
	if (info->move.up == 1 || info->move.down == 1)
		up_down(info);
	if (info->move.strafr == 1 || info->move.strafl == 1)
		straf(info);
	if (info->move.left == 1)
		fn_rotate(info, 1);
	if (info->move.right == 1)
		fn_rotate(info, -1);
}
