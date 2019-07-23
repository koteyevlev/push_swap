/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:30:49 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/23 21:00:21 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

void	ft_five_sort(t_intl **a, t_intl **b, int argc)
{
	if (argc == 5 || (ft_is_sort(*a) && (!*b || ft_num_el(*a) == 5)))
		return ;
	if (argc == 1 || argc == 0)
		ft_print_op(a, b, 'p', 'a');
	if (argc == 0)
		ft_print_op(a, b, 'r', 'a');
}

int		*ft_massiv(t_intl *a, int argc)
{
	int		*res;
	int		i;

	res = (int *)malloc(sizeof(int) * (argc));
	i = 0;
	while (a)
	{
		res[i] = a->nbr;
		i++;
		a = a->next;
	}
	return (res);
}

int		ft_median(t_intl *a, int x, int y, int argc)
{
	int		*sorted;
	int		key;

	sorted = ft_massiv(a, argc);
	while (x < argc)
	{
		y = x - 1;
		key = sorted[x];
		while (y >= 0 && sorted[y] > key)
		{
			sorted[y + 1] = sorted[y];
			y--;
		}
		sorted[y + 1] = key;
		x++;
	}
	free(sorted);
	return (sorted[argc / 2]);
}

int		ft_num_el(t_intl *b)
{
	int		res;

	res = 0;
	while (b)
	{
		res++;
		b = b->next;
	}
	return (res);
}
