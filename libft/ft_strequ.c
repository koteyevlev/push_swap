/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:30:45 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	while (index <= ft_strlen(s1) && index <= ft_strlen(s2))
	{
		if (s1[index] < s2[index])
			return (0);
		if (s2[index] < s1[index])
			return (0);
		index++;
	}
	return (1);
}
