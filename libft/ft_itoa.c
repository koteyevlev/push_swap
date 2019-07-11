/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:14:03 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:36:29 by skrystin         ###   ########.fr       */
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

static void			kostil(int razmer, char **str, int index, int n)
{
	if (n < 0)
	{
		razmer--;
		n = -n;
	}
	while (razmer != 0)
	{
		razmer--;
		(*str)[index] = '0' + modul(((n % ft_step(razmer + 1))
					/ ft_step(razmer)));
		index++;
	}
	(*str)[index] = '\0';
}

static int			ft_razmer(int n)
{
	if (n <= 0)
		return (1);
	return (0);
}

char				*ft_itoa(int n)
{
	char	*str;
	size_t	razmer;
	size_t	index;

	razmer = ft_razmer(n);
	while ((n / ft_step(razmer) != 0 && n > 0) ||
			(n / ft_step(razmer - 1) != 0 && n <= 0))
		razmer++;
	str = ft_strnew(razmer);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	index = 0;
	if (n < 0)
	{
		str[0] = '-';
		index++;
	}
	kostil(razmer, &str, index, n);
	return (str);
}
