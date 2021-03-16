/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <nhill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:04:47 by nhill             #+#    #+#             */
/*   Updated: 2021/03/16 15:01:41 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*prev;
	t_list	*ls;

	if (!lst)
		return ;
	if (!(ls = *lst))
		return ;
	while (ls->next)
	{
		prev = ls;
		ls = ls->next;
		if (del)
			del(prev->content);
		free(prev);
	}
	if (del)
		del(ls->content);
	free(ls);
	*lst = NULL;
}
