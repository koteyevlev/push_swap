/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/17 16:27:17 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker/libft/libft.h"

int		ft_mas_len(char **argv)
{
	int	res;

	res = 0;
	while (argv[res])
		res++;
	return (res);
}

void	ft_check_flags(int *argc, char ***argv, int *flag)
{
	char	*str;

	if (*argc == 2)
	{
		if ((*argv)[1][0] != '-' || !((*argv)[1][1] == 'p'
		|| (*argv)[1][1] != 'f'))
			str = ft_strjoin("-/to_free ", (*argv)[1]);
		else
			str = ft_strjoin(" ", (*argv)[1]);
		*argv = ft_strsplit(str, ' ');
		*argc = ft_mas_len(*argv);
		free(str);
		if ((*argv)[0][0] == '-')
		{
			if ((*argv)[0][1] == 'p')
				*flag = 1;
		}
	}
}

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
	if (argv[0][0] == '-')
		free(argv);
	return (0);
}
