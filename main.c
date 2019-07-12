/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/12 20:50:45 by skrystin         ###   ########.fr       */
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

int		min(int nbr, t_intl *a)
{
	t_intl	*begin;

	begin = a;
	nbr--;
	while (nbr--)
		a = a->next;
	nbr = a->nbr;
	while (begin && nbr <= begin->nbr)
		begin = begin->next;
	if (begin)
		return (1);
	else
		return (0);
}

int		min_max(t_intl **a, t_intl **b)
{
	if (ft_min(4, *a))
		ft_print_op(a, b, 'R', 'a');
	if (ft_min(2, *a))
		ft_print_op(a, b, 's', 'a');
	if (ft_min(1, *a))
	{
		ft_print_op(a, b, 'p', 'b');
		return (1);
	}
	
}

void	ft_medium_sort(t_intl **a, t_intl **b, int argc)
{
	if (argc == 4)
	{
		if (min_max(a, b))
		{
			ft_simple_sort(a, 3);
			ft_print_op(a, b, 'p', 'a');
		}
		else
		{
			ft_simple_sort(a, 3);
			ft_print_op(a, b, 'p', 'a');
			ft_print_op(a, b, 'r', 'a');
		}
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_intl	*a;
	t_intl	*b;

	if (argc >= 2)
	{
		i = 1;
		ft_create_int(&a, &b, argv, argc);
		if (argc <= 4)
			ft_simple_sort(&a, argc);
		if (argc <= 6)
			ft_medium_sort(&a, &b, argc);
		ft_print_l(a);
		ft_putstr(" - a\nb - ");
		ft_print_l(b);
		
		ft_del_all(&a, &b);
	}
	return (0);
}
