/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:03:08 by skrystin          #+#    #+#             */
/*   Updated: 2019/07/23 21:05:53 by skrystin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_mas_len(char **argv)
{
	int	res;

	res = 0;
	while (argv[res])
		res++;
	return (res);
}

void	ft_check_flags(int *argc, char ***argv, int *flag)
{
	char	*str;

	if (*argc == 2)
	{
		if ((*argv)[1][0] != '-' || !((*argv)[1][1] == 'p'
		|| (*argv)[1][1] != 'f'))
			str = ft_strjoin("-/to_free ", (*argv)[1]);
		else
			str = ft_strjoin(" ", (*argv)[1]);
		*argv = ft_strsplit(str, ' ');
		*argc = ft_mas_len(*argv);
		free(str);
		if ((*argv)[0][0] == '-')
		{
			if ((*argv)[0][1] == 'p')
				*flag = 1;
		}
	}
}
