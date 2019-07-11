/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:31:09 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char				*ft_strjoin(char const *dest, char const *src)
{
	size_t		index;
	size_t		index2;
	char		*newstr;

	index = 0;
	index2 = 0;
	if (!dest || !src)
		return (NULL);
	newstr = (char *)malloc(sizeof(*newstr) * (ft_strlen(dest) +
				ft_strlen(src) + 1));
	if (!newstr)
		return (NULL);
	while (dest[index] != '\0')
	{
		newstr[index] = dest[index];
		index++;
	}
	while (src[index2] != '\0')
	{
		newstr[index] = src[index2];
		index++;
		index2++;
	}
	newstr[index] = '\0';
	return (newstr);
}
