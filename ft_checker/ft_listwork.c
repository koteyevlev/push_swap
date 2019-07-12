/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listwork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:54:59 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/11 18:58:14 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_print_l(t_intl *a)
{
	while (a)
	{
		ft_putnbr(a->nbr);
		ft_putchar(' ');
		a = a->next;
	}
}

t_intl	*ft_del_last(t_intl **a)
{
	t_intl	*begin;
	t_intl	*tmpfree;

	if (!(*a))
		return (NULL);
	begin = *a;
	while (*a && (*a)->next && (*a)->next->next)
		(*a) = (*a)->next;
	tmpfree = (*a)->next;
	(*a)->next = 0;
	*a = begin;
	return (tmpfree);
}

t_intl	*ft_del_first(t_intl **a)
{
	t_intl	*tmpfree;

	tmpfree = *a;
	if (!(*a))
		return (NULL);
	(*a) = (*a)->next;
	tmpfree->next = NULL;
	return (tmpfree);
}

void	ft_push_first(t_intl **a, t_intl *el)
{
	if (!(*a))
		*a = el;
	else
	{
		el->next = *a;
		*a = el;
	}
}

void	ft_push_last(t_intl **a, t_intl *el)
{
	t_intl	*begin;

	if (!(*a))
		*a = el;
	else
	{
		begin = *a;
		while (*a && (*a)->next)
			(*a) = (*a)->next;
		(*a)->next = el;
		*a = begin;
	}
}
