/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:12:06 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/21 12:28:04 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memal;

	if (size == (size_t)(-1) || size == 0)
		return (NULL);
	memal = (void *)malloc(size * sizeof(*memal));
	if (!memal)
		return (NULL);
	ft_bzero(memal, size);
	return (memal);
}
