/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:39:22 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:33:11 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	index;

	index = 0;
	newstr = (char *)malloc(sizeof(*newstr) * (len + 1));
	if (newstr == NULL || !s)
		return (NULL);
	ft_strncpy(newstr, &s[start], len);
	newstr[len] = '\0';
	return (newstr);
}
