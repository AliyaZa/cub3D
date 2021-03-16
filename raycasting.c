/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:00:29 by nhill             #+#    #+#             */
/*   Updated: 2021/03/13 17:55:45 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_info *info, int x)
{
	info->rc.camera = 2 * x / (double)(info->width) - 1;
	info->rc.rpos.x = info->pos.x;
	info->rc.rpos.y = info->pos.y;
	info->rc.rdir.x = info->rc.dir.x + info->rc.plane.x * info->rc.camera;
	info->rc.rdir.y = info->rc.dir.y + info->rc.plane.y * info->rc.camera;
	info->rc.rmap.x = (int)info->rc.rpos.x;
	info->rc.rmap.y = (int)info->rc.rpos.y;
	info->rc.rdisd.x = fabs(1 / info->rc.rdir.x);
	info->rc.rdisd.y = fabs(1 / info->rc.rdir.y);
	info->rc.hit = 0;
}

void	direction_ray(t_info *info)
{
	if (info->rc.rdir.x < 0)
	{
		info->rc.step.x = -1;
		info->rc.rdist.x = (info->rc.rpos.x - info->rc.rmap.x) *
		info->rc.rdisd.x;
	}
	else
	{
		info->rc.step.x = 1;
		info->rc.rdist.x = (info->rc.rmap.x + 1.0 - info->rc.rpos.x) *
		info->rc.rdisd.x;
	}
	if (info->rc.rdir.y < 0)
	{
		info->rc.step.y = -1;
		info->rc.rdist.y = (info->rc.rpos.y - info->rc.rmap.y) *
		info->rc.rdisd.y;
	}
	else
	{
		info->rc.step.y = 1;
		info->rc.rdist.y = (info->rc.rmap.y + 1.0 - info->rc.rpos.y) *
			info->rc.rdisd.y;
	}
}

void	hit_ray(t_info *info)
{
	while (info->rc.hit == 0)
	{
		if (info->rc.rdist.x < info->rc.rdist.y)
		{
			info->rc.rdist.x += info->rc.rdisd.x;
			info->rc.rmap.x += info->rc.step.x;
			if (info->rc.rdir.x < 0)
				info->rc.wall = 0;
			else
				info->rc.wall = 2;
		}
		else
		{
			info->rc.rdist.y += info->rc.rdisd.y;
			info->rc.rmap.y += info->rc.step.y;
			if (info->rc.rdir.y < 0)
				info->rc.wall = 1;
			else
				info->rc.wall = 3;
		}
		if (my_check_rc(info) == 1)
			info->rc.hit = 1;
	}
}

void	size_ray(t_info *info)
{
	if (info->rc.wall == 0 || info->rc.wall == 2)
		info->rc.dist = (info->rc.rmap.x - info->rc.rpos.x
					+ (1 - info->rc.step.x) / 2) / info->rc.rdir.x;
	else
		info->rc.dist = (info->rc.rmap.y - info->rc.rpos.y
					+ (1 - info->rc.step.y) / 2) / info->rc.rdir.y;
	info->rc.rh = ((info->height / info->rc.dist));
	info->rc.wstart = ((-info->rc.rh)) / 2 + info->height / 2;
	if (info->rc.wstart < 0)
		info->rc.wstart = 0;
	info->rc.wend = info->rc.rh / 2 + info->height / 2;
	if (info->rc.wend >= info->height)
		info->rc.wend = info->height - 1;
	info->rc.textur.id = (info->map.tab_map[info->rc.rmap.y]
	[info->rc.rmap.x] - '0') - 1;
}

void	wall_textur(t_info *info)
{
	double wallx;

	if (info->rc.wall == 0 || info->rc.wall == 2)
		wallx = info->rc.rpos.y + info->rc.dist * info->rc.rdir.y;
	else
		wallx = info->rc.rpos.x + info->rc.dist * info->rc.rdir.x;
	wallx -= floor((wallx));
	info->rc.textur.x = (int)(wallx * 64.0);
	if ((info->rc.wall == 0 || info->rc.wall == 2) && info->rc.rdir.x > 0)
		info->rc.textur.x = 64 - info->rc.textur.x - 1;
	if ((info->rc.wall == 1 || info->rc.wall == 3) && info->rc.rdir.y < 0)
		info->rc.textur.x = 64 - info->rc.textur.x - 1;
	if ((info->rc.wall == 0 || info->rc.wall == 2) && info->rc.rdir.x >= 0)
		info->rc.textur.id = 1;
	else if ((info->rc.wall == 0 || info->rc.wall == 2) && info->rc.rdir.x < 0)
		info->rc.textur.id = 0;
	else if ((info->rc.wall == 1 || info->rc.wall == 3) && info->rc.rdir.y < 0)
		info->rc.textur.id = 2;
	else
		info->rc.textur.id = 3;
	info->rc.step_textur = 1.0 * 64 / info->rc.rh;
	info->rc.textur_pos = (info->rc.wstart - info->height / 2 +
	info->rc.rh / 2) * info->rc.step_textur;
}
