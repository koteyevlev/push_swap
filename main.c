/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/13 20:30:38 by skrystin         ###   ########.fr       */
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

int		min_max(t_intl **a, t_intl **b)
{
	t_intl	*begin;
	int		nbr;
	
	if (ft_min(a, b))
		return (1);
	else
	{
		begin = *a;
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
}

int		ft_is_sort(t_intl *a)
{
	int	nbr;

	nbr = a->nbr;
	while (a && nbr <= a->nbr)
		a = a->next;
	if (!a)
		return (1);
	else
		return (0);

}

void	ft_five_sort(t_intl **a, t_intl **b, int argc)
{
	if (argc == 5 || (ft_is_sort(*a) && !*b))
		return ;
	if (argc == 1 || argc == 0)
		ft_print_op(a, b, 'p', 'a');
	if (argc == 0)
		ft_print_op(a, b, 'r', 'a');
}

void	ft_medium_sort(t_intl **a, t_intl **b, int argc)
{
	int x;

	x = 0;
	if (argc == 6)
	{
		if (!ft_is_sort(*a) && (x = min_max(a, b)) == -1)
		{
			ft_print_op(a, b, 'R', 'a');
			x = min_max(a, b);
		}
		argc = x;
	}
	if (argc == 5 || argc == x)
	{
		if (!ft_is_sort(*a) && (x = min_max(a, b)) > 0)
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

/* int		ft_median(int *a, int argc, int x, int y)
{
	int i;
	int index;
	int	*less;
	int	*more;

	less = (int *)malloc(sizeof(int) * (argc));
	more = (int *)malloc(sizeof(int) * (argc));
	i = a[0];
	index = 0;
	while (index < argc)
	{
		ft_putnbr(i);
		ft_putnbr(a[index]);
		ft_putchar('\n');
		if (i > a[index])
			more[x++] = a[index];
		else if (i < a[index])
			less[y++] = a[index];
		index++;
	}
	free(a);
	//ft_putnbr(y);
	if (x > y && x != 1)
	{
		free(less);
		return (ft_median(more, x, 0, 0));
	}
	else if (y > x && y != 1)
	{
		free(more);
		return (ft_median(less, y, 0, 0));
	}
	else
	{
		x = (more[0]);
		if (x == y)
			x = i;
		free(more);
		free(less);
		return (x);
	}
} */

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

void	ft_hard_sort(t_intl **a, t_intl **b, int argc)
{
	int		med;
	int		stacka;

	if (ft_is_sort(*a))
		return ;
	stacka = argc;
	med = ft_median(*a, 1, 0, argc);
	while ((*a)->next->next->next)
	{
		if ((*a)->nbr <= med && stacka--)
			ft_print_op(a, b, 'p', 'b');
		else
			ft_print_op(a, b, 'R', 'a');
		if (stacka <= argc / 2)
			med = ft_median(*a, 1, 0, stacka);
	}
	ft_simple_sort(a, 4);
	while (*b)
	{
		med = 0;
	//	ft_putchar('\n');
		while ((*b) && (*b)->nbr > (*a)->nbr) // maybe bug
		{
			ft_print_op(a, b, 'r', 'a');
			med++;
		}
		if (*b)
			ft_print_op(a, b, 'p', 'a');
		while (med)
		{
			ft_print_op(a, b, 'R', 'a');
			med--;
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
		else if (argc <= 6)
			ft_medium_sort(&a, &b, argc);
		else
			ft_hard_sort(&a, &b, argc);
		//	ft_putnbr(ft_median(a, 1, 0, argc));
		/*  ft_print_l(a);
		ft_putstr(" - a\nb - ");
		ft_print_l(b); */
		
		ft_del_all(&a, &b);
	}
	return (0);
}
