/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:42:36 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:28:16 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		if (((unsigned char *)ptr)[index] == (unsigned char)value)
			return (&((unsigned char *)ptr)[index]);
		index++;
	}
	return (NULL);
}
