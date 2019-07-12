/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:37:52 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:32:08 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while (index < n - 1 && s1[index] == s2[index]
			&& s1[index] && s2[index])
		index++;
	if (index < n && s1[index] == s2[index])
		return (1);
	else
		return (0);
}
