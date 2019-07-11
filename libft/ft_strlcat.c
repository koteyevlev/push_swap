/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:31:25 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t				ft_strlcat(char *dest,
		const char *src, size_t nb)
{
	size_t index;
	size_t index2;

	index = 0;
	index2 = 0;
	while (dest[index] != '\0' && index < nb)
		index++;
	while (src[index2] != '\0' && index + index2 + 1 < nb)
	{
		dest[index + index2] = src[index2];
		index2++;
	}
	if (index < nb)
		dest[index + index2] = '\0';
	return (ft_strlen(src) + index);
}
