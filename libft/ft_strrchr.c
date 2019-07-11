/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:13:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:32:53 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int index;

	index = ft_strlen(str);
	while (index >= 0)
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index--;
	}
	return (0);
}
