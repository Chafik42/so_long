/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:29:04 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/09 13:14:49 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	get_len(int fd, char *str, t_map *map)
{
	char	c;
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (flag++ == 0)
				map->x = len;
			continue ;
		}
		len++;
	}
	close(fd);
	return (len);
}

int	get_size(int fd, char *str)
{
	char	c;
	int		len;

	len = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	return (len);
}

int	*oned_map(int fd, int len, char *str)
{
	int		*tab;
	char	c;
	int		i;

	i = 0;
	c = 0;
	fd = open(str, O_RDONLY);
	tab = malloc(sizeof(int) * (len));
	if (!tab)
		return (0);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			continue ;
		tab[i] = c;
		i++;
	}
	close(fd);
	return (tab);
}
