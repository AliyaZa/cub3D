/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:11:52 by nhill             #+#    #+#             */
/*   Updated: 2021/03/07 18:56:40 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_name_cub(char *str)
{
	int length;

	length = ft_strlen(str) - 1;
	if (length < 4)
		return (INVALID_ARG);
	if (str[length] != 'b')
		return (INVALID_ARG);
	if (str[length - 1] != 'u')
		return (INVALID_ARG);
	if (str[length - 2] != 'c')
		return (INVALID_ARG);
	if (str[length - 3] != '.')
		return (INVALID_ARG);
	return (SUCCESS);
}

int			main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	if ((argc != 2 && argc != 3) || check_name_cub(argv[1]) == INVALID_ARG)
		return (re_errors(INVALID_ARG, &info));
	if ((info.error = init_save(&info, argc, argv[2])) != SUCCESS)
		return (re_errors(info.error, &info));
	if ((info.error = init_var(&info, argv[1])) != SUCCESS)
		return (re_errors(info.error, &info));
	if (info.flag_save == 1)
	{
		if ((info.error = launch_save(&info)) != SUCCESS)
			return (re_errors(info.error, &info));
		return (SUCCESS);
	}
	if ((info.error = events(&info)) != SUCCESS)
		return (re_errors(info.error, &info));
	return (SUCCESS);
}
