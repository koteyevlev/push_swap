/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:14:03 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:29:28 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static long int		ft_step(int n)
{
	long int final;

	final = 1;
	while (n > 0)
	{
		final *= 10;
		n--;
	}
	return (final);
}

static int			modul(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

static void			kostil(int razmer, int n)
{
	while (razmer != 0)
	{
		razmer--;
		ft_putchar('0' + modul(((n % ft_step(razmer + 1))
					/ ft_step(razmer))));
	}
}

void				ft_putnbr(int n)
{
	int		razmer;

	razmer = 0;
	while (n / ft_step(razmer) != 0)
		razmer++;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	kostil(razmer, n);
}
