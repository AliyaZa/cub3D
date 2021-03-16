/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:46:16 by nhill             #+#    #+#             */
/*   Updated: 2021/03/16 15:33:47 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_info *info)
{
	if (info->img)
	{
		mlx_destroy_image(info->mlx_ptr, info->img->img_ptr);
		free(info->img);
		info->img = NULL;
	}
}

void	free_textur(t_info *info, t_textur *textur)
{
	if (textur)
	{
		mlx_destroy_image(info->mlx_ptr, textur->textur_ptr);
		free(textur);
		textur = NULL;
	}
}

void	ft_tabdel(void **tab)
{
	int i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

void	free_tab(t_info *info)
{
	if (info->rc.zbuffer)
		free(info->rc.zbuffer);
	if (info->map.tab_map)
		ft_tabdel((void *)info->map.tab_map);
	if (info->data.r)
		free(info->data.r);
	if (info->data.no)
		free(info->data.no);
	if (info->data.so)
		free(info->data.so);
	if (info->data.we)
		free(info->data.we);
	if (info->data.ea)
		free(info->data.ea);
	if (info->data.f)
		free(info->data.f);
	if (info->data.c)
		free(info->data.c);
	if (info->data.spr)
		free(info->data.spr);
}
