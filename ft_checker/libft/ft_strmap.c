/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:19:30 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:31:37 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*strcp;
	int		counter;

	counter = 0;
	if (!s || !f)
		return (0);
	while (s[counter])
		counter++;
	strcp = (char *)malloc((counter + 1) * sizeof(*strcp));
	if (!strcp)
		return (0);
	while (*s)
	{
		*strcp = *s;
		*strcp = f(*strcp);
		s++;
		strcp++;
	}
	*strcp = '\0';
	return (strcp - counter);
}
