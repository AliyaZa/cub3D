/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:26:09 by nhill             #+#    #+#             */
/*   Updated: 2021/02/26 23:31:41 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		init_pos(t_info *info)
{
	if (info->map.player == 'N')
	{
		info->rc.dir.y = -1;
		info->rc.plane.x = -0.80;
	}
	if (info->map.player == 'S')
	{
		info->rc.dir.y = 1;
		info->rc.plane.x = 0.80;
	}
	if (info->map.player == 'E')
	{
		info->rc.dir.x = 1;
		info->rc.plane.y = -0.80;
	}
	if (info->map.player == 'W')
	{
		info->rc.dir.x = -1;
		info->rc.plane.y = 0.80;
	}
	return (SUCCESS);
}

int				init_info_pos(t_info *info)
{
	if (!(info->mlx_ptr = mlx_init()))
		return (MLX_FAIL);
	if ((info->img = fn_new_image(info, info->width, info->height)) == NULL)
		return (IMG_FAIL);
	if ((info->error = init_pos(info)) != SUCCESS)
		return (info->error);
	return (SUCCESS);
}
