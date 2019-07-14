/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:37:35 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/14 14:13:39 by skrystin         ###   ########.fr       */
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

void	ft_print_op(t_intl **a, t_intl **b, char name, char who)
{
	count++;
	if (name == 's')
	{
		if (who == 'a' || who == 's')
			ft_sa(a);
		if (who == 'b' || who == 's')
			ft_sa(b);
	}
	else if (name == 'r')
	{
		if (who == 'a' || who == 'r')
			ft_ra(a);
		if (who == 'b' || who == 'r')
			ft_ra(b);
	}
	else if (name == 'R')
	{
		if (who == 'a' || who == 'r')
			ft_rra(a);
		if (who == 'b' || who == 'r')
			ft_rra(b);
	}
	ft_print_opt(a, b, name, who);
}
