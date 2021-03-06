/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/23 21:05:25 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void		ft_vivod(t_intl **b, t_intl *a)
{
	if (!*b && ft_is_sort(a))
	{
		ft_putstr("OK\n");
		return ;
	}
	else
	{
		ft_putstr("KO\n");
		return ;
	}
}

void		ft_check_do(char *s, t_intl **a, t_intl **b)
{
	if (ft_strlen(s) > 3 || ft_strlen(s) < 2)
	{
		ft_putstr("Error\n");
		ft_del_all(a, b);
		exit(0);
	}
	else if (ft_strlen(s) == 3 && (s[0] != 'r' || s[1] != 'r'
	|| !(s[2] == 'a' || s[2] == 'b' || s[2] == 'r')))
	{
		ft_putstr("Error\n");
		ft_del_all(a, b);
		exit(0);
	}
	else if (s[1] == 'p' || ft_strindex("rsp", s[0]) < 0 ||
	!(s[1] == s[0] || s[1] == 'a' || s[1] == 'b'))
	{
		ft_putstr("Error\n");
		ft_del_all(a, b);
		exit(0);
	}
}

void		ft_checkwork(t_intl **a, t_intl **b, char *s)
{
	while (get_next_line(0, &s) > 0)
	{
		if (!s)
			continue ;
		ft_check_do(s, a, b);
		if (*s == 'r' && (*(s + 1) == 'a' || *(s + 1) == 'r') && !*(s + 2))
			ft_ra(a);
		if (*s == 'r' && (*(s + 1) == 'b' || *(s + 1) == 'r') && !*(s + 2))
			ft_ra(b);
		if (*s == 's' && (*(s + 1) == 'a' || *(s + 1) == 's'))
			ft_sa(a);
		if (*s == 's' && (*(s + 1) == 'b' || *(s + 1) == 's'))
			ft_sa(b);
		if (*s == 'p' && (*(s + 1) == 'a' || *(s + 1) == 'p'))
			ft_pa(a, b);
		if (*s == 'p' && (*(s + 1) == 'b' || *(s + 1) == 'p'))
			ft_pa(b, a);
		if (*s == 'r' && *(s + 1) == 'r' &&
		(*(s + 2) == 'a' || *(s + 2) == 'r'))
			ft_rra(a);
		if (*s == 'r' && *(s + 1) == 'r' &&
		(*(s + 2) == 'b' || *(s + 2) == 'r'))
			ft_rra(b);
		free(s);
	}
	ft_vivod(b, *a);
}

int			main(int argc, char **argv)
{
	int		i;
	t_intl	*a;
	t_intl	*b;
	int		flag;

	flag = 0;
	if (argc >= 2)
		ft_check_flags(&argc, &argv, &flag);
	if (argc >= 2 && ft_check_nbr(argv, argc - 1, 1))
	{
		i = 1;
		ft_create_int(&a, &b, argv, argc);
		ft_checkwork(&a, &b, 0);
		ft_del_all(&a, &b);
	}
	if (argv[0][0] == '-' && (i = 0) == 0)
	{
		while(argv[i])
			free(argv[i++]);
		free(argv);
	}
	return (0);
}
