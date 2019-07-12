/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:44:50 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:31:20 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strjoin3(char **line, char **str, char **str2)
{
	*line = ft_strjoin(*str, *str2);
	if (ft_strlen(*str) > 0)
		ft_strdel(str);
	if (ft_strlen(*str2) > 0)
		ft_strdel(str2);
}
