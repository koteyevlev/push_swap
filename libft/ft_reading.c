/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:41:44 by skrystin          #+#    #+#             */
/*   Updated: 2019/06/25 16:07:55 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_file	*ft_filenew(t_file **file)
{
	t_file *tmp;

	tmp = (t_file *)malloc(sizeof(t_file));
	if (tmp && file)
	{
		(*tmp).previous = *file;
		(*tmp).next = NULL;
		(*file)->next = tmp;
		((*tmp).content)[20] = '\0';
	}
	else if (!file)
	{
		(*tmp).previous = NULL;
		(*tmp).next = NULL;
		((*tmp).content)[20] = '\0';
	}
	return (tmp);
}

static t_file	*ft_tobegin(t_file *file)
{
	t_file	*forfree;

	forfree = file;
	file = file->previous;
	free(forfree);
	file->next = NULL;
	while (file->previous)
		file = (file)->previous;
	return (file);
}

static t_file	*ft_reading2(int i, int fd, int ret, t_file *file)
{
	while (ret > 0 && (ret = read(fd, (*file).content, 20)) > 0)
	{
		i = 0;
		while (i < 20)
		{
			if ((((*file).content[i] == '.' || (*file).content[i] == '#')
			&& (i + 1) % 5 != 0) || ((i + 1) % 5 == 0 &&
			(*file).content[i] == '\n'))
				i++;
			else
				return (0);
		}
		if ((ret = read(fd, (*file).newstr, 1)) >= 0)
		{
			if ((*file).newstr[0] != '\n' && (*file).newstr[0] != '\0'
			&& (*file).newstr[0] != 127)
				return (0);
			file = ft_filenew(&file);
		}
	}
	if (i == 1 || ((file->previous->newstr)[0] != '\0'
	&& file->previous->previous))
		return (0);
	return (ft_tobegin(file));
}

t_file			*ft_reading(char *namefile)
{
	int		fd;
	int		ret;
	t_file	*file;
	int		i;

	if (!(fd = open(namefile, O_RDONLY)))
		return (NULL);
	file = NULL;
	file = ft_filenew(NULL);
	ret = 1;
	i = 1;
	return (ft_reading2(i, fd, ret, file));
}

void			ft_copykord(t_file **file, t_kord kord[4])
{
	int	index;

	index = 0;
	while (index < 4)
	{
		(*file)->kord[index].x = kord[index].x;
		(*file)->kord[index].y = kord[index].y;
		index++;
	}
}
