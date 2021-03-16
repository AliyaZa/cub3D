/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:21:38 by nhill             #+#    #+#             */
/*   Updated: 2021/03/13 18:58:06 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_text(char *s)
{
	int i;

	i = 0;
	while (ft_isalpha(s[i]))
		i++;
	while (s[i] != '.')
	{
		if (ft_isascii(s[i]) && s[i] != ' ')
			return (WRONG_INPUT);
		i++;
	}
	return (SUCCESS);
}

static int		check_text_path(t_info *info)
{
	if (check_text(info->data.n) == WRONG_INPUT)
		return (WRONG_INPUT);
	if (check_text(info->data.s) == WRONG_INPUT)
		return (WRONG_INPUT);
	if (check_text(info->data.w) == WRONG_INPUT)
		return (WRONG_INPUT);
	if (check_text(info->data.e) == WRONG_INPUT)
		return (WRONG_INPUT);
	if (check_text(info->data.sp) == WRONG_INPUT)
		return (WRONG_INPUT);
	return (SUCCESS);
}

static int		get_start_path(char *s)
{
	int i;

	i = 0;
	while (s[i] != '.')
		i++;
	return (i);
}

static void		fn_free_path(char *s)
{
	free(s);
	s = NULL;
}

int				path_fix(t_info *info)
{
	int i;

	if (check_text_path(info) == WRONG_INPUT)
		return (WRONG_INPUT);
	i = get_start_path(info->data.n);
	if (!(info->data.no = ft_strtrim(info->data.n + i, " ")))
		return (MALLOC_FAIL);
	fn_free_path(info->data.n);
	i = get_start_path(info->data.s);
	if (!(info->data.so = ft_strtrim(info->data.s + i, " ")))
		return (MALLOC_FAIL);
	fn_free_path(info->data.s);
	i = get_start_path(info->data.w);
	if (!(info->data.we = ft_strtrim(info->data.w + i, " ")))
		return (MALLOC_FAIL);
	fn_free_path(info->data.w);
	i = get_start_path(info->data.e);
	if (!(info->data.ea = ft_strtrim(info->data.e + i, " ")))
		return (MALLOC_FAIL);
	fn_free_path(info->data.e);
	i = get_start_path(info->data.sp);
	if (!(info->data.spr = ft_strtrim(info->data.sp + i, " ")))
		return (MALLOC_FAIL);
	fn_free_path(info->data.sp);
	return (SUCCESS);
}
