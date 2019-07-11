/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:42:36 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:28:22 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		if (((unsigned char *)ptr1)[index] != ((unsigned char *)ptr2)[index])
		{
			return (((unsigned char *)ptr1)[index]
					- ((unsigned char *)ptr2)[index]);
		}
		index++;
	}
	return (0);
}
