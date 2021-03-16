/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:26:59 by nhill             #+#    #+#             */
/*   Updated: 2020/11/04 16:15:48 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*fir;

	if (!lst || !f)
		return (NULL);
	if (!(res = ft_lstnew(f(lst->content))))
		return (NULL);
	fir = res;
	while (lst->next)
	{
		lst = lst->next;
		if (!(res->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&fir, del);
			return (NULL);
		}
		res = res->next;
	}
	return (fir);
}
