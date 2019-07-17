/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:53:12 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/16 14:58:15 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

int		ft_check_to_pa(t_intl *a, t_intl *b)
{
	t_intl	*tmp;

	tmp = a;
	if (!b)
		return (0);
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!a || (b->nbr >= tmp->nbr && b->nbr <= a->nbr))
		return (0);
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
	return (0);
}

int		ft_check_r(t_intl **a, t_intl **b, int med)
{
	int		nbr;
	t_intl	*tmpb;
	t_intl	*tmpa;

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
	if (tmpb->nbr <= nbr)
		return (1);
	else
		return (0);
}

int		ft_optimize(t_intl **a, t_intl **b, int x, int med)
{
	t_intl	*tmpa;
	t_intl	*tmpb;

	if ((x / 2) * 2 == x && (*a)->nbr == med)
		return (0);
	tmpa = *a;
	tmpb = *b;
	while (tmpa && tmpa->next)
		tmpa = tmpa->next;
	while (tmpb && tmpb->next)
		tmpb = tmpb->next;
	if (!*b || !(*b)->next)
		return (1);
	else if (((*b)->nbr < (*b)->next->nbr &&
	(*b)->next->nbr > tmpb->nbr) && (*b)->nbr < tmpb->nbr)
		ft_print_op(a, b, 'r', 'b');
	else if ((*b)->nbr < (*b)->next->nbr && (*b)->next->nbr < tmpb->nbr)
		ft_print_op(a, b, 's', 'b');
	else
		return (1);
	return (ft_optimize(a, b, x, med));
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
