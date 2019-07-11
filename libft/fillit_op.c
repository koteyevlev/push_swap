/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmanie <gmanie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:26:50 by gmanie            #+#    #+#             */
/*   Updated: 2019/06/25 17:33:14 by gmanie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_kord		*new_kord(int x, int y)
{
	t_kord	*k;

	k = ft_memalloc(sizeof(t_kord));
	k->x = x;
	k->y = y;
	return (k);
}

void		print_figures(char **mas)
{
	int		i;

	i = 0;
	while (mas[i])
	{
		ft_putendl(mas[i]);
		ft_strdel(&(mas[i]));
		i++;
	}
	free(mas);
}

char		**ft_create(int size)
{
	char	**mas;
	int		i;

	i = 0;
	mas = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		mas[i] = (char *)malloc(sizeof(char) * (size + 1));
		ft_memset(mas[i], '.', size);
		mas[i][size] = '\0';
		i++;
	}
	mas[i] = NULL;
	return (mas);
}

void		ft_add(char **mas, t_figure **tetr, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < (*tetr)->height)
	{
		j = 0;
		while (j < (*tetr)->width)
		{
			if ((*tetr)->fig[i][j] != '.')
				mas[y + i][x + j] = (*tetr)->fig[i][j];
			j++;
		}
		i++;
	}
}
