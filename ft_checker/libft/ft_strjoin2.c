/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:44:50 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:31:15 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strjoin2(char **str, char **str2)
{
	char	*tmpline;

	tmpline = *str;
	*str = ft_strjoin(tmpline, *str2);
	if (ft_strlen(tmpline) > 0)
		ft_strdel(&tmpline);
	if (ft_strlen(*str2) > 0)
		ft_strdel(str2);
}
