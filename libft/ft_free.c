/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:48:13 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/24 19:23:05 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_freetetr(t_figure **fig)
{
	t_figure	*tmp2;
	int			index;

	while ((*fig)->next)
	{
		index = 0;
		tmp2 = (*fig)->next;
		while (((*fig)->fig)[index])
		{
			ft_strdel(&(((*fig)->fig)[index]));
			index++;
		}
		free(((*fig)->fig));
		free((*fig));
		(*fig) = tmp2;
	}
	index = 0;
	while (((*fig)->fig)[index])
	{
		ft_strdel(&(((*fig)->fig)[index]));
		index++;
	}
	free(((*fig)->fig));
	free((*fig));
}

void	ft_freemap(char **mas)
{
	int index;

	index = 0;
	while (mas[index])
	{
		ft_strdel(&(mas[index]));
		index++;
	}
	free(mas);
}
