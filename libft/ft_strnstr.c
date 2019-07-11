/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:32:19 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static const char	*ft_putstr2(const char *str,
		const char *to_find, size_t index, size_t finder)
{
	size_t flag;

	flag = 0;
	if (str[index] == to_find[0])
	{
		finder = index;
		while (flag != ft_strlen(to_find))
		{
			if (str[index] == to_find[index - finder])
				flag++;
			else
				break ;
			index++;
		}
		if (flag == ft_strlen(to_find))
			return (str + finder);
		else
		{
			flag = 0;
			index = finder;
		}
	}
	return (NULL);
}

char				*ft_strnstr(const char *str,
		const char *to_find, size_t len)
{
	size_t		index;
	size_t		finder;
	size_t		lenh;
	const char	*vivod;

	lenh = len;
	finder = 0;
	index = 0;
	vivod = str;
	if (to_find[0] == '\0')
		return ((char *)vivod);
	if (len == 0)
		return (NULL);
	lenh -= ft_strlen(to_find) - 1;
	while (index < ft_strlen(str) && ft_strlen(to_find) <= len && lenh > 0)
	{
		vivod = ft_putstr2(str, to_find, index, finder);
		index++;
		if (vivod != NULL)
			return ((char *)vivod);
		vivod = str;
		lenh--;
	}
	return (NULL);
}
