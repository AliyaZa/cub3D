/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 22:45:29 by nhill             #+#    #+#             */
/*   Updated: 2021/03/16 16:18:54 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		add_to_list_map(t_info *info, char *line, int *i, t_list *tmp)
{
	if (!(tmp->content = ft_strdup(line + *i)))
		return (MALLOC_FAIL);
	tmp->next = 0;
	ft_lstadd_back(&info->map.list, tmp);
	return (SUCCESS);
}

static int		stock_data(char *line, t_info *info, int *i, int *flag_map)
{
	t_list	*tmp;

	if (ft_isalpha(line[*i]))
	{
		if ((info->error = get_data(info, line, *i, flag_map)) != SUCCESS)
			return (info->error);
	}
	else if (ft_isdigit(line[*i]))
	{
		(*flag_map)++;
		*i = 0;
		if (!(tmp = malloc(sizeof(t_list))))
			return (MALLOC_FAIL);
		if ((info->error = add_to_list_map(info, line, i, tmp)) != SUCCESS)
			return (info->error);
	}
	return (SUCCESS);
}

static int		fn_read(t_info *info, int fd)
{
	int		ret;
	char	*line;
	int		i;
	int		flag_map;

	ret = 1;
	flag_map = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		i = 0;
		while ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
		if ((info->error = stock_data(line, info, &i, &flag_map)) != SUCCESS)
		{
			free(line);
			return (info->error);
		}
		free(line);
	}
	if ((info->error = check_data(info)) != SUCCESS)
		return (info->error);
	if ((info->error = path_fix(info)) != SUCCESS)
		return (info->error);
	return (SUCCESS);
}

int				get_map(t_info *info, char *file)
{
	int		fd;
	t_list	*tmp;
	int		i;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (OPEN_ERR);
	if ((info->error = fn_read(info, fd)) != SUCCESS)
		return (info->error);
	close(fd);
	if (!(info->map.tab_map = (char**)malloc(sizeof(char *) *
		ft_lstsize(info->map.list) + 1)))
		return (MALLOC_FAIL);
	i = 0;
	tmp = info->map.list;
	while (tmp)
	{
		if (!(info->map.tab_map[i] = ft_strdup(tmp->content)))
			return (MALLOC_FAIL);
		tmp = tmp->next;
		i++;
	}
	info->map.tab_map[i] = 0;
	info->map.kol_line = i;
	return (SUCCESS);
}
