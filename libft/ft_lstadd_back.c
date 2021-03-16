/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:40:52 by nhill             #+#    #+#             */
/*   Updated: 2020/11/04 16:22:17 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ls;

	if (!new)
		return ;
	ls = *lst;
	if (!ls)
		*lst = new;
	else
	{
		while (ls->next)
			ls = ls->next;
		ls->next = new;
	}
}
