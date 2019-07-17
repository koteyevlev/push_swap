/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 18:59:16 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/17 15:06:42 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_del_all(t_intl **a, t_intl **b)
{
	t_intl	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
}

int		ft_isint(char *str)
{
	int		nbr;
	char	*check;
	int		i;

	nbr = ft_atoi(str);
	if (!(check = ft_itoa(nbr)))
		exit(0);
	i = 0;
	while (str[i] && str[i] == check[i])
		i++;
	ft_strdel(&check);
	if (!str[i])
		return (1);
	else
		return (0);
}

void	ft_create_int(t_intl **a, t_intl **b, char **argv, int argc)
{
	int		i;
	t_intl	*tmp;
	t_intl	*begin;

	*b = 0;
	i = 1;
	tmp = 0;
	while (i < argc)
	{
		if (!ft_isint(argv[i]))
		{
			ft_putstr("Error\n");
			exit(0);
		}
		if (!(*a = (t_intl *)malloc(sizeof(t_intl))))
			exit(0);
		if (i == 1)
			begin = *a;
		if (tmp)
			tmp->next = (*a);
		(*a)->nbr = ft_atoi(argv[i++]);
		(*a)->next = 0;
		tmp = *a;
	}
	*a = begin;
}

void	ft_print_opt(t_intl **a, t_intl **b, char name, char who)
{
	if (name == 'p')
	{
		if (who == 'a')
			ft_pa(a, b);
		if (who == 'b')
			ft_pa(b, a);
	}
	if (name == 'R')
		ft_putstr("rr");
	else
		ft_putchar(name);
	ft_putchar(who);
	ft_putchar('\n');
}

int		ft_check_nbr(char **argv, int argc, int i)
{
	int	x;
	int	mas[argc];

	while (i <= argc)
	{
		mas[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	x = 0;
	while (x < argc - 1)
	{
		i = x + 1;
		while (i < argc)
		{
			if (mas[x] == mas[i])
			{
				ft_putstr("Error\n");
				return (0);
			}
			i++;
		}
		x++;
	}
	return (1);
}
