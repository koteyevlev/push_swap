/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:26:38 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:27:55 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_cleaner(t_list *begin)
{
	t_list	*buf;

	while (begin)
	{
		buf = begin->next;
		ft_memdel((void **)&begin);
		begin = buf;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*cplst;

	if (!lst || !f)
		return (0);
	cplst = ft_lstnew(lst->content, lst->content_size);
	if (!cplst)
		return (0);
	cplst = (*f)(cplst);
	begin = cplst;
	while (lst->next)
	{
		lst = lst->next;
		cplst->next = ft_lstnew(lst->content, lst->content_size);
		if (cplst->next == 0)
			return (ft_cleaner(begin));
		if (!(cplst->next = (*f)(cplst->next)))
			return (ft_cleaner(begin));
		cplst = cplst->next;
	}
	return (begin);
}
