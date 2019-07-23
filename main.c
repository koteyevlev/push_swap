/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/23 21:06:35 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

int		main(int argc, char **argv)
{
	int		i;
	int		flag;
	t_intl	*a;
	t_intl	*b;

	flag = 0;
	if (argc >= 2)
		ft_check_flags(&argc, &argv, &flag);
	if (argc >= 2 && ft_check_nbr(argv, argc - 1, 1))
	{
		i = 1;
		ft_create_int(&a, &b, argv, argc);
		if (argc <= 4)
			ft_simple_sort(&a, argc);
		else if (argc <= 6)
			ft_medium_sort(&a, &b, argc, 0);
		else
			ft_hard_sort(&a, &b, argc - 1, 0);
		if (flag == 1)
			ft_print_l(a);
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
