/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:32:29 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/12 19:58:28 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_vivod(t_intl **b)
{
	if (!*b)
	{
		ft_putstr("OK\n");
		return ; //exit
	}
	else
	{
		ft_putstr("KO\n");
		return ;
	}
}

void	ft_checkwork(t_intl **a, t_intl **b)
{
	char	*str;

	while(get_next_line(0, &str) > 0)
	{
		if(!str || !(*str) || !(*(str + 1)))
			continue ;
		if (*str == 'r' && (*(str + 1) == 'a' || *(str + 1) == 'r') && !*(str + 2))
			ft_ra(a);
		if (*str == 'r' && (*(str + 1) == 'b' || *(str + 1) == 'r') && !*(str + 2))
			ft_ra(b);
		if (*str == 's' && (*(str + 1) == 'a' || *(str + 1) == 's'))
			ft_sa(a);
		if (*str == 's' && (*(str + 1) == 'b' || *(str + 1) == 's'))
			ft_sa(b);
		if (*str == 'p' && (*(str + 1) == 'a' || *(str + 1) == 'p'))
			ft_pa(a, b);
		if (*str == 'p' && (*(str + 1) == 'b' || *(str + 1) == 'p'))
			ft_pa(b, a);
		if (*str == 'r' && *(str + 1) == 'r' && (*(str + 2) == 'a' || *(str + 2) == 'r'))
			ft_rra(a);
		if (*str == 'r' && *(str + 1) == 'r' && (*(str + 2) == 'b' || *(str + 2) == 'r'))
			ft_rra(b);
	}
	ft_vivod(b);
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
		ft_checkwork(&a, &b);
	//	ft_print_l(a);
	//	ft_putstr(" - a\nb - ");
	//	ft_print_l(b);	
		ft_del_all(&a, &b);
	}
	return (0);
}
