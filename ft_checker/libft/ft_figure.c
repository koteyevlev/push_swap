/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:52:24 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/24 20:27:20 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_count(t_file *file)
{
	int		count;
	char	*word;

	while (file)
	{
		count = 0;
		word = ft_strstr(file->content, "#");
		while (word)
		{
			count++;
			word = ft_strstr(word + 1, "#");
		}
		if (count != 4)
			return (0);
		file = file->next;
	}
	return (1);
}

static int		ft_sosed(t_kord one, t_kord two)
{
	if (((one).x == two.x && ft_modul((one).y - (two).y) == 1)
	|| ((one).y == two.y && ft_modul((one).x - (two).x) == 1))
		return (1);
	return (0);
}

static int		ft_koord(t_kord kord[4], int one, int two, int thr)
{
	while (one != 4)
	{
		while (two != 4 && thr != 4)
		{
			if (two != one && ft_sosed(kord[one], kord[two]) == 1)
			{
				while (thr != 4)
				{
					if (two != thr && thr != one && (ft_sosed(kord[one],
					kord[thr]) || ft_sosed(kord[two], kord[thr])))
						break ;
					thr++;
				}
				break ;
			}
			two++;
		}
		if (two == 4 || thr == 4)
			return (0);
		thr = 0;
		two = 0;
		one++;
	}
	return (1);
}

static int		ft_neighbour(t_file **file)
{
	t_kord	kord[4];
	int		i;
	int		nbr;

	while (*file)
	{
		i = 0;
		nbr = 0;
		while (((*file)->content)[i])
		{
			if (((*file)->content)[i] == '#')
			{
				(kord[nbr]).x = i % 5;
				(kord[nbr]).y = i / 5;
				nbr++;
			}
			i++;
		}
		if (ft_koord(kord, 0, 1, 0) == 0)
			return (0);
		ft_copykord(file, kord);
		(*file) = (*file)->next;
	}
	return (1);
}

t_file			*ft_figure(t_file **file)
{
	t_file	*filebegin;

	filebegin = *file;
	if (ft_count(*file) == 0 || ft_neighbour(file) == 0)
		return (NULL);
	*file = filebegin;
	return (*file);
}
