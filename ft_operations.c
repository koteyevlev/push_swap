/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:37:35 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/11 20:12:20 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_sa(t_intl **a)
{
	int		nbr;

	if (!(*a) || !((*a)->next))
		return ;
	nbr = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = nbr;
}

void	ft_rra(t_intl **a)
{
	if (!(*a) || !((*a)->next))
		return ;
	ft_push_first(a, ft_del_last(a));
}

void	ft_ra(t_intl **a)
{
	if (!(*a) || !((*a)->next))
		return ;
	ft_push_last(a, ft_del_first(a));
}

void	ft_pa(t_intl **a, t_intl **b)
{
	if (!((*b)))
		return ;
	ft_push_first(a, ft_del_first(b));
}
