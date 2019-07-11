/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:44:49 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/24 20:28:21 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char			g_alpha;

static void		ft_findkord(t_kord kord[4], int (minmaxx[2]),
int (minmaxy[2]), int index)
{
	while (index < 4)
	{
		if ((minmaxx)[0] > kord[index].x)
			(minmaxx)[0] = kord[index].x;
		if ((minmaxx)[1] < kord[index].x)
			(minmaxx)[1] = kord[index].x;
		if ((minmaxy)[0] > kord[index].y)
			(minmaxy)[0] = kord[index].y;
		if ((minmaxy)[1] < kord[index].y)
			(minmaxy)[1] = kord[index].y;
		index++;
	}
}

static void		ft_shape(t_figure **tmp, char *content,
int minmaxx[2], int minmaxy[2])
{
	int	i;
	int x;

	x = 0;
	i = 0;
	while (i < (*tmp)->height)
	{
		((*tmp)->fig)[i] = (char *)malloc(sizeof(char) * ((*tmp)->width + 1));
		if (((*tmp)->fig)[i])
		{
			((*tmp)->fig)[i][(*tmp)->width] = '\0';
			while (x < (*tmp)->width)
			{
				if (content[x + minmaxx[0] + (minmaxy[0] + i) * 5] == '.')
					((*tmp)->fig)[i][x] =
					content[x + minmaxx[0] + (minmaxy[0] + i) * 5];
				else
					((*tmp)->fig)[i][x] = g_alpha;
				x++;
			}
			x = 0;
		}
		i++;
	}
	g_alpha++;
}

static t_figure	*ft_createfig(t_figure **tetr, int minmaxx[2],
int minmaxy[2], t_file *file)
{
	t_figure *tmp;

	tmp = (t_figure *)malloc(sizeof(t_figure));
	if (tmp)
	{
		(*tmp).previous = *tetr;
		(*tmp).next = NULL;
		(*tetr)->next = tmp;
		((*tmp).height) = minmaxy[1] - minmaxy[0] + 1;
		tmp->width = minmaxx[1] - minmaxx[0] + 1;
		tmp->fig = (char **)malloc(sizeof(char *) * (tmp->height + 1));
		tmp->fig[tmp->height] = NULL;
		ft_shape(&tmp, file->content, minmaxx, minmaxy);
	}
	*tetr = tmp;
	return (tmp);
}

t_figure		*ft_fit(t_file *file)
{
	int			index;
	int			minmaxx[2];
	int			minmaxy[2];
	t_figure	*tetr;

	g_alpha = 'A';
	while (file)
	{
		index = 0;
		(minmaxx)[0] = 4;
		(minmaxx)[1] = 0;
		(minmaxy)[0] = 4;
		(minmaxy)[1] = 0;
		ft_findkord(file->kord, minmaxx, minmaxy, index);
		tetr = ft_createfig(&tetr, minmaxx, minmaxy, file);
		file = file->next;
	}
	return (tetr);
}
