/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:07:59 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/23 21:00:47 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

void	ft_end_des_sort(t_intl **a, t_intl **b, int total, int med)
{
	while (total > 0)
	{
		while (total > 0 && (*a)->nbr < (*b)->nbr)
		{
			ft_print_op(a, b, 'r', 'b');
			med++;
		}
		if (total-- > 0)
			ft_print_op(a, b, 'p', 'b');
		while (med)
		{
			if (total > 0 && (*a)->nbr <= (*b)->nbr)
				break ;
			ft_print_op(a, b, 'R', 'b');
			if (ft_check_to_pb(*a, *b) && total-- > 0)
			{
				ft_print_op(a, b, 'p', 'b');
			}
			med--;
		}
	}
}

void	ft_descending_sort(t_intl **b, t_intl **a, int stackb, int med)
{
	int		arg;
	int		total;

	total = stackb;
	arg = stackb;
	if (ft_is_des_sort(*b) || ((med = ft_median(*b, 1, 0, stackb)) && NULL))
		return ;
	while ((*b)->next)
	{
		if ((*b)->nbr >= med && arg--)
			ft_print_op(a, b, 'p', 'a');
		else
			ft_print_op(a, b, 'r', 'b');
		if ((*a)->nbr > (*a)->next->nbr &&
		(*b)->next && (*b)->nbr < (*b)->next->nbr)
			ft_print_op(a, b, 's', 's');
		else if ((*a)->nbr > (*a)->next->nbr)
			ft_print_op(a, b, 's', 'a');
		if (arg <= stackb / 2)
		{
			stackb = arg;
			med = ft_median(*b, 1, 0, arg);
		}
	}
	ft_end_des_sort(a, b, total - arg, 0);
}

void	ft_end_asc_sort(t_intl **a, t_intl **b, int med)
{
	ft_medium_sort(a, b, 6, 0);
	while (*b)
	{
		while ((*b) && (*b)->nbr > (*a)->nbr)
		{
			ft_print_op(a, b, 'r', 'a');
			med++;
		}
		if (*b && (*b)->nbr < (*a)->nbr)
			ft_print_op(a, b, 'p', 'a');
		while (med)
		{
			if ((*b) && (*b)->nbr >= (*a)->nbr)
				break ;
			ft_print_op(a, b, 'R', 'a');
			if (ft_check_to_pa(*a, *b))
			{
				ft_print_op(a, b, 'p', 'a');
			}
			med--;
		}
	}
}

void	ft_hard_sort(t_intl **a, t_intl **b, int argc, int tmp)
{
	int		med;
	int		stacka;
	int		des;

	if (ft_is_sort(*a) || (des = 1) == 0)
		return ;
	stacka = argc;
	med = ft_median(*a, 1, 0, argc);
	while ((*a)->next->next->next->next->next)
	{
		if ((*a)->nbr <= med && ft_optimize(a, b, argc, med) && stacka--)
			ft_print_op(a, b, 'p', 'b');
		if (!(tmp = ft_check_r(a, b, med)) || tmp != -1)
			ft_print_op(a, b, 'r', 'a');
		else if (tmp == 1)
			ft_print_op(a, b, 'r', 'r');
		if (stacka <= argc / 2)
		{
			if (des-- > 0)
				ft_descending_sort(b, a, ft_num_el(*b), 0);
			argc = argc - stacka;
			med = ft_median(*a, 1, 0, ft_num_el(*a));
		}
	}
	ft_end_asc_sort(a, b, 0);
}
