/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:13:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:30:02 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (char)c)
			return ((char*)&str[index]);
		index++;
	}
	if ((char)c == '\0')
		return ((char*)&str[index]);
	return (0);
}
