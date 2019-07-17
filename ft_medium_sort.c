/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:09:18 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/15 19:22:16 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

int		ft_min(t_intl **a, t_intl **b)
{
	t_intl	*begin;
	int		nbr;

	begin = *a;
	if (!*a)
		return (0);
	nbr = (*a)->nbr;
	while (begin->next)
	{
		begin = begin->next;
		if (nbr > begin->nbr)
			nbr = begin->nbr;
	}
	if (nbr == (*a)->nbr || nbr == (*a)->next->nbr
	|| nbr == begin->nbr)
	{
		if (nbr == begin->nbr)
			ft_print_op(a, b, 'R', 'a');
		else if (nbr == (*a)->next->nbr)
			ft_print_op(a, b, 's', 'a');
		ft_print_op(a, b, 'p', 'b');
		return (1);
	}
	else
		return (0);
}

int		min_max(t_intl **a, t_intl **b, t_intl *begin, int nbr)
{
	if (!ft_min(a, b))
	{
		if (!*a)
			return (-1);
		nbr = (*a)->nbr;
		while (begin->next)
		{
			begin = begin->next;
			if (nbr < begin->nbr)
				nbr = begin->nbr;
		}
		if (nbr == (*a)->nbr || nbr == (*a)->next->nbr
		|| nbr == begin->nbr)
		{
			if (nbr == begin->nbr)
				ft_print_op(a, b, 'R', 'a');
			else if (nbr == (*a)->next->nbr)
				ft_print_op(a, b, 's', 'a');
			ft_print_op(a, b, 'p', 'b');
			return (0);
		}
		else
			return (-1);
	}
	return (1);
}

void	ft_medium_sort(t_intl **a, t_intl **b, int argc, int x)
{
	if (argc == 6)
	{
		if (!ft_is_sort(*a) && (x = min_max(a, b, *a, 0)) == -1)
		{
			ft_print_op(a, b, 'R', 'a');
			x = min_max(a, b, *a, 0);
		}
		argc = x;
	}
	if (argc == 5 || argc == x)
	{
		if (!ft_is_sort(*a) && (x = min_max(a, b, *a, 0)) > 0)
		{
			ft_simple_sort(a, 4);
			ft_print_op(a, b, 'p', 'a');
		}
		else if (!ft_is_sort(*a) && x != -1)
		{
			ft_simple_sort(a, 4);
			ft_print_op(a, b, 'p', 'a');
			ft_print_op(a, b, 'r', 'a');
		}
	}
	ft_five_sort(a, b, argc);
}
