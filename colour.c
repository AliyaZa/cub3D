/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:05:06 by nhill             #+#    #+#             */
/*   Updated: 2021/03/16 16:30:16 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pixel_textur(t_textur *textur, t_info *info)
{
	info->colour = textur->textur_data[64 *
	info->rc.textur.y + info->rc.textur.x];
}

void		pixel_colour(t_info *info)
{
	if (info->rc.textur.id == 0)
		pixel_textur(info->textur3, info);
	else if (info->rc.textur.id == 1)
		pixel_textur(info->textur4, info);
	else if (info->rc.textur.id == 2)
		pixel_textur(info->textur1, info);
	else if (info->rc.textur.id == 3)
		pixel_textur(info->textur2, info);
}

static int	check_tab(char *tab)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(tab);
	while (i < size && tab[i] == ' ')
		i++;
	while (i < size && ft_isdigit(tab[i]))
		i++;
	while (i < size)
	{
		if (ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_colour(char **tab)
{
	int r;
	int g;
	int b;
	int i;

	i = -1;
	if (tab_size(tab) == 3)
	{
		while (++i < 3)
		{
			if (check_tab(tab[i]) == 0)
				return (WRONG_INPUT);
		}
		r = ft_atoi(tab[0]);
		g = ft_atoi(tab[1]);
		b = ft_atoi(tab[2]);
	}
	else
	{
		ft_tabdel((void **)tab);
		return (WRONG_INPUT);
	}
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (WRONG_INPUT);
	return (SUCCESS);
}

int			get_colour(t_colour *colour, char *s)
{
	int		i;
	char	**tab;

	i = 0;
	while (!ft_isdigit(s[i]) && s[i] != '-')
		i++;
	if (look_for_alpha(s, i) != SUCCESS)
		return (WRONG_INPUT);
	if (!(tab = ft_split(s + i, ',')))
		return (MALLOC_FAIL);
	if (check_colour(tab) == WRONG_INPUT)
		return (WRONG_INPUT);
	colour->rgb.r = ft_atoi(tab[0]);
	colour->rgb.g = ft_atoi(tab[1]);
	colour->rgb.b = ft_atoi(tab[2]);
	colour->rgb.a = 0x00;
	ft_tabdel((void **)tab);
	return (SUCCESS);
}
