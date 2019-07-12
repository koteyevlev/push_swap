/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:13:37 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/12 20:36:34 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int		tmp_not_empty(const int fd, char **line, char **tmp)
{
	char		*tmpfree;

	if (ft_strindex((tmp)[fd], '\n') == -1)
	{
		if (ft_strlen(*line) > 0)
			ft_strdel(line);
		if (ft_strlen(tmp[fd]) > 0)
			*line = ft_strdup((tmp)[fd]);
		ft_strdel(&(tmp[fd]));
	}
	else
	{
		*line = ft_strsub((tmp)[fd], 0, ft_strindex((tmp)[fd], '\n'));
		tmpfree = ft_strsub((tmp)[fd], ft_strindex((tmp)[fd], '\n') + 1,
				ft_strlen((tmp)[fd]) - ft_strindex((tmp)[fd], '\n'));
		ft_strdel(&(tmp[fd]));
		tmp[fd] = tmpfree;
		return (1);
	}
	return (0);
}

static int		ending(char **line, int fd, char *buf, char **tmp)
{
	int			index;
	int			ret;
	char		*tmpfree;
	char		*tmpbuf;

	ret = ft_strlen(buf);
	index = 0;
	while (buf[index] != '\0' && buf[index] != '\n')
		index++;
	tmpbuf = ft_strsub(buf, 0, index);
	tmpfree = *line;
	*line = ft_strjoin(tmpfree, tmpbuf);
	if (ft_strlen(tmpfree) > 0)
		ft_strdel(&tmpfree);
	ft_strdel(&tmpbuf);
	tmp[fd] = ft_strsub(buf, index + 1, ret - index - 1);
	return (1);
}

static void		joining(char **line, char *buf, int *index)
{
	char		*tmpline;

	tmpline = *line;
	*line = ft_strjoin(tmpline, buf);
	if (ft_strlen(tmpline))
		ft_strdel(&tmpline);
	*index = 0;
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	int			index;
	char		buf[BUFF_SIZE + 1];
	static char	*tmp[10240];

	index = 0;
	if (fd < 0 || !line || fd > 10240)
		return (-1);
	*line = "";
	if (tmp[fd] && tmp_not_empty(fd, line, tmp) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		while (buf[index] != '\0' && buf[index] != '\n')
			index++;
		if (index != ret && ending(line, fd, buf, tmp) == 1)
			break ;
		joining(line, buf, &index);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (!line[0] || line[0][0] == '\0'))
		return (0);
	return (1);
}
