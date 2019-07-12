/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:24:44 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:31:56 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n != 0)
		n--;
	else
		return (0);
	while (index < n && s1[index] && s2[index] && s1[index] == s2[index])
	{
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
