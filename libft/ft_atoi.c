/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:25:43 by qmartina          #+#    #+#             */
/*   Updated: 2019/06/21 12:27:46 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_kostil2(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

static int	ft_kostil(const char *str, int i, long int nb, int **sumsav)
{
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (0);
		if (str[i] == '-')
			(*sumsav)[1] = -1;
		i++;
	}
	while (*str != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			(*sumsav)[0] = (*sumsav)[0] * 10 + (str[i] - '0');
		}
		else
			return ((*sumsav)[0] * (*sumsav)[1]);
		if ((nb * 10) / 10 != nb)
			return (ft_kostil2((*sumsav)[1]));
		i++;
	}
	return ((*sumsav)[0] * (*sumsav)[1]);
}

int			ft_atoi(const char *str)
{
	int			i;
	long int	nb;
	int			*sumsav;

	sumsav = (int *)malloc(sizeof(int) * 2);
	if (!sumsav)
		return (0);
	i = 0;
	nb = 0;
	sumsav[0] = 0;
	sumsav[1] = 1;
	i = ft_kostil(str, i, nb, &sumsav);
	free(sumsav);
	return (i);
}
