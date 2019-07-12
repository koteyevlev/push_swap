/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmanie <gmanie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:25:38 by gmanie            #+#    #+#             */
/*   Updated: 2019/06/25 17:30:48 by gmanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int				g_n;
int				g_res;

static int		ft_check(char **mas, t_figure **tetr, int y, int x)
{
	int			i;
	int			j;

	if (((x + (*tetr)->width) <= g_n) && (y + (*tetr)->height <= g_n))
	{
		i = 0;
		while (i < (*tetr)->height)
		{
			j = 0;
			while (j < (*tetr)->width)
			{
				if (mas[y + i][x + j] != '.' && (*tetr)->fig[i][j] != '.')
					return (1);
				j++;
			}
			i++;
		}
	}
	else
		return (1);
	return (0);
}

static void		ft_remove(char **mas, t_figure **tetr, t_kord *k)
{
	int			i;
	int			j;

	i = 0;
	while (i < (*tetr)->height)
	{
		j = 0;
		while (j < (*tetr)->width)
		{
			if ((*tetr)->fig[i][j] != '.')
				mas[k->y + i][k->x + j] = '.';
			j++;
		}
		i++;
	}
}

static int		tetris(char **mas, t_figure **tetr, int size, int y)
{
	int			x;

	if (*tetr)
	{
		while (y + (*tetr)->height < size + 1)
		{
			x = 0;
			while (x + (*tetr)->width < size + 1)
			{
				if (!ft_check(mas, tetr, y, x))
				{
					ft_add(mas, tetr, y, x);
					if (!tetris(mas, &(*tetr)->next, size, 0))
						return (0);
					else
						ft_remove(mas, tetr, new_kord(x, y));
				}
				x++;
			}
			y++;
		}
		return (1);
	}
	return (0);
}

void			fillit2(t_figure **tetr, int size, int x, int y)
{
	char		**mas;

	while (size < 17 || (y = 0) != 1)
	{
		while (y < size)
		{
			x = 0;
			while (x < size)
			{
				mas = ft_create(size);
				g_n = size;
				if (!(g_res = tetris(mas, tetr, size, 0)))
					break ;
				x++;
			}
			if (!g_res)
				break ;
			y++;
		}
		if (!g_res)
			break ;
		ft_freemap(mas);
		size++;
	}
	print_figures(&*mas);
}

void			fillit(t_figure **tetr, int size)
{
	fillit2(tetr, size, 0, 0);
}
