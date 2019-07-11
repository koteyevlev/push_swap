/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:37:25 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:33:16 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char		*ft_kostil2(char *newstr)
{
	newstr = ft_strnew(0);
	newstr[0] = '\0';
	return (newstr);
}

static char		*ft_kostil(char const *s, char *newstr,
		size_t index, size_t index2)
{
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_kostil2(newstr));
	while (s[index] != '\0')
		index++;
	index--;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index--;
	newstr = ft_strnew(index + 1);
	if (!newstr)
		return (NULL);
	newstr[index + 1] = '\0';
	while (index2 <= index)
	{
		newstr[index2] = s[index2];
		index2++;
	}
	return (newstr);
}

char			*ft_strtrim(char const *s)
{
	char	*newstr;
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 0;
	newstr = NULL;
	return (ft_kostil(s, newstr, index, index2));
}
