/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:29:38 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/15 19:15:03 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

void	ft_choose_op(t_intl **a, int f, int s, int t)
{
	if (s <= f && f <= t)
		ft_print_op(a, 0, 's', 'a');
	else if (t <= s && s <= f)
	{
		ft_print_op(a, 0, 's', 'a');
		ft_print_op(a, 0, 'R', 'a');
	}
	else if (s <= t && t <= f)
		ft_print_op(a, 0, 'r', 'a');
	else if (f <= t && t <= s)
	{
		ft_print_op(a, 0, 's', 'a');
		ft_print_op(a, 0, 'r', 'a');
	}
	else if (t <= f && f <= s)
		ft_print_op(a, 0, 'R', 'a');
}

void	ft_simple_sort(t_intl **a, int argc)
{
	if (argc == 2 || (argc == 3 && (*a)->nbr <= (*a)->next->nbr))
		return ;
	else if (argc == 3 && (*a)->nbr > (*a)->next->nbr)
		ft_print_op(a, 0, 's', 'a');
	else if (argc == 4)
	{
		if ((*a)->nbr <= (*a)->next->nbr &&
		(*a)->next->nbr <= (*a)->next->next->nbr)
			return ;
		else
			ft_choose_op(a, (*a)->nbr, (*a)->next->nbr,
			(*a)->next->next->nbr);
	}
}

int		ft_is_sort(t_intl *a)
{
	int	nbr;

	nbr = a->nbr;
	while (a && nbr <= a->nbr)
	{
		nbr = a->nbr;
		a = a->next;
	}
	if (!a)
		return (1);
	else
		return (0);
}
