/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/14 23:25:50 by skrystin         ###   ########.fr       */
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
	{
		nbr = a->nbr;
		a = a->next;
	}
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

/* int		ft_s_or_r(t_intl **a, t_intl **b)
{
	t_intl	*tmpa;
	t_intl	*tmpb;

	if ((*b)->nbr >= (*b)->next->nbr && (*a)->nbr <= (*a)->next->nbr)
		return (0);
	tmpa = *a;
	tmpb = *b;
	while (tmpa->next)
		tmpa = tmpa->next;
	while (tmpb->next)
		tmpb = tmpb->next;
	// check with r
} */

int		ft_check_to_pa(t_intl *a, t_intl *b)
{
	t_intl	*tmp;

	tmp = a;
	if (!b)
		return (0);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!a || (b->nbr >= tmp->nbr && b->nbr <= a->nbr))
		return(0);
	return (0);
}

int		ft_check_to_pb(t_intl *a, t_intl *b)
{
	t_intl	*tmp;

	tmp = b;
	if (!a || !b || !b->next)
		return (0);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (a->nbr < tmp->nbr && a->nbr > b->nbr)
		return (1);
	//	printf("a - %d   tmp - %d   b - %d\n", a->nbr, tmp->nbr, b->nbr);
	return (0);
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

int		ft_check_r(t_intl **a, t_intl **b, int med)
{
	int		nbr;
	t_intl	*tmpb;
	t_intl	*tmpa;
	
	// ft_putstr("\n\n");
	// ft_print_l(*a);
	// ft_putstr(" - a\nb - ");
	// ft_print_l(*b);
	// ft_putstr("\n\n");
	tmpa = *a;
	while (tmpa->next)
		tmpa = tmpa->next;
	if (tmpa->nbr > (*a)->nbr && med > (*a)->nbr)
		return (-1);
	if (!*b || !(*b)->next)
		return (1);
	tmpb = *b;
	nbr = (*b)->nbr;
	while (tmpb->next)
		tmpb = tmpb->next;
	// ft_putnbr(tmpb->nbr);
	// ft_putstr("vs");
	// ft_putnbr(nbr);
	if (tmpb->nbr <= nbr)
		return (1);
	else
		return (0);
}

int		ft_optimize(t_intl **a, t_intl **b, int x, int med)
{
	t_intl	*tmpa;
	t_intl	*tmpb;

	// ft_putstr("\n\n");
	// ft_print_l(*a);
	// ft_putstr(" - a\nb - ");
	// ft_print_l(*b);
	// ft_putstr("\n\n");
	tmpa = *a;
	tmpb = *b;
	while (tmpa && tmpa->next)
		tmpa = tmpa->next;
	while (tmpb && tmpb->next)
		tmpb = tmpb->next;
	if ((!*b || !(*b)->next || (*b)->nbr >= (*b)->next->nbr)
	&& (*a)->nbr > (*a)->next->nbr)
		ft_print_op(a, b, 's', 'a');
	else if (!*b || !(*b)->next)
		return (1);
	else if (((*b)->nbr < (*b)->next->nbr && (*b)->next->nbr > tmpb->nbr)
	 && (*a)->nbr > (*a)->next->nbr)
		ft_print_op(a, b, 's', 's');
	else if (((*b)->nbr < (*b)->next->nbr && (*b)->next->nbr > tmpb->nbr) && (*b)->nbr < tmpb->nbr)
		ft_print_op(a, b, 'r', 'b');
	else if ((*b)->nbr < (*b)->next->nbr && (*b)->next->nbr < tmpb->nbr)
	{
		// ft_putnbr((*b)->nbr);
		// ft_putchar(' ');
		// ft_putnbr((*b)->next->nbr);
		// ft_putchar(' ');
		// ft_putnbr(tmpb->nbr);
		ft_print_op(a, b, 's', 'b');
	}
	else
		return (1);
	return (ft_optimize(a, b, x, med));
}

void	ft_check_R(t_intl **a, t_intl **b, int med, int r)
{
	t_intl	*tmpa;
	t_intl	*tmpb;
	int		x;
	int		l;

	l = (*a)->nbr;
	// ft_putnbr(l);
	// ft_putstr("\n");
	tmpa = *a;
	tmpb = *b;
	x = 0;
	if (*b)
		x = (*b)->nbr;
	while (tmpa && tmpa->next)
		tmpa = tmpa->next;
	while (tmpb && tmpb->next)
		tmpb = tmpb->next;
	//ft_putnbr(tmpa->nbr);
	//ft_putchar('\n');
	if (tmpa->nbr < (*a)->next->nbr && tmpa->nbr <= med)
	{
		if (*b && (*b)->next && l > tmpa->nbr && (r < tmpb->nbr && tmpb->nbr < (*b)->next->nbr))
		{
			ft_print_op(a, b, 'R', 'r');
			ft_check_R(a, b, (*a)->nbr, x);
		}
		else if (l > tmpa->nbr && (!*b || !((*b)->next) || r >= tmpb->nbr || tmpb->nbr >= (*b)->next->nbr))
		{
			ft_print_op(a, b, 'R', 'a');
			ft_check_R(a, b, (*a)->nbr, x);
		}
	}
	else if (*b && (*b)->next && (r < tmpb->nbr && tmpb->nbr < (*b)->next->nbr))
	{
		ft_print_op(a, b, 'R', 'b');
		ft_check_R(a, b, (*a)->nbr, x);
	}
}

int		ft_is_des_sort(t_intl *b)
{
	int	nbr;

	if (!b)
		return (1);
	nbr = b->nbr;
	while (b && nbr >= b->nbr)
	{
		nbr = b->nbr;
		b = b->next;
	}
	if (!b)
		return (1);
	else
		return (0);
}

void	ft_descending_sort(t_intl **b, t_intl **a, int stackb, int med)
{
	int		arg;
	int		total;

	total = stackb;
	arg = stackb;
	if (ft_is_des_sort(*b))
		return ;
	med = ft_median(*b, 1, 0, stackb);
	while ((*b)->next)
	{
		if ((*b)->nbr >= med && arg--)
			ft_print_op(a, b, 'p', 'a');
		else
			ft_print_op(a, b, 'r', 'b');
		if (arg <= stackb / 2)
		{
			stackb = arg;
			med = ft_median(*b, 1, 0, arg);
			// ft_putstr("\n\n");
			// ft_putnbr(arg);
			// ft_putstr("\n\n");
			// break ;
		}
	}
	total -= arg;
	med = 0;
	while (total)
	{
	//	ft_putchar('\n');
		while (total && (*a)->nbr < (*b)->nbr) // maybe bug
		{
			ft_print_op(a, b, 'r', 'b');
			med++;
		}
		if (total--)
			ft_print_op(a, b, 'p', 'b');
		while (med)
		{
			ft_print_op(a, b, 'R', 'b');
			//if (ft_check_to_pb(*a, *b) && total--)
			{
			//	ft_print_op(a, b, 'p', 'b');
			//	break ;
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

	des = 1;
	if (ft_is_sort(*a))
		return ;
	stacka = argc;
	med = ft_median(*a, 1, 0, argc);
	while ((*a)->next->next->next)
	{
	 	// if (*b)
		// 	ft_check_R(a, b, med, (*b)->nbr);
		// else
		// 	ft_check_R(a, b, (*a)->nbr, 0);
		// if (stacka == 24)
		// 	break ;
		if ((*a)->nbr <= med && ft_optimize(a, b, 0, med) && stacka--)
		{
			ft_print_op(a, b, 'p', 'b');
			//break ;
		}
		else if (!(tmp = ft_check_r(a, b, med)) || tmp != -1)
			ft_print_op(a, b, 'r', 'a');
		else if (tmp == 1)
			ft_print_op(a, b, 'r', 'r');
		if (stacka <= argc / 2)
		{
			// ft_putnbr(med);
			// ft_putstr("\n\n");
			// ft_print_l(*a);
			// ft_putstr(" - a\nb - ");
			// ft_print_l(*b);
			// ft_putstr("\n\n");
			// ft_putnbr(med);
			// ft_putstr("\n\n");
			if (des-- >0)
				ft_descending_sort(b, a, ft_num_el(*b), 0); // nmr of element not right
			//break ;
			argc = argc - stacka;
			med = ft_median(*a, 1, 0, stacka);
		}
		//ft_putnbr((*a)->nbr);
	}
	ft_simple_sort(a, 4);
	med = 0;
	while (*b)
	{
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
			if (ft_check_to_pa(*a, *b))
			{
				ft_print_op(a, b, 'p', 'a');
				break ;
			}
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
			ft_hard_sort(&a, &b, argc - 1, 0);
			//ft_putnbr(ft_median(a, 1, 0, argc));
		ft_print_l(a);
		ft_putstr(" - a\nb - ");
		ft_print_l(b);
		ft_putstr("\n action -");
		ft_putnbr(count);
		ft_del_all(&a, &b);
	}
	return (0);
}
