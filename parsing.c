/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:43:51 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/07 22:32:06 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	valid_item(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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

int	parse_ber(t_map *map, int i, int linecount, int fd)
{
	char	*str;

	str = malloc(sizeof(char) * (map->len) + 1);
	read(fd, str, map->len);
	while (str[++i])
	{
		if (str[i] != '1' && linecount == 0 && i != map->x)
			return (0);
		if (i)
			if (str[i - 1] == '\n' && str[i] != '1')
				return (0);
		if (i && linecount)
			if (str[i] == '\n' && str[i - 1] != '1')
				return (0);
		if (str[i] == '\n')
			linecount++;
		if (!valid_item("01CPE\n", str[i]))
			return (0);
	}
	i -= 1;
	while (str[--i] && str[i] != '\n')
		if (str[i] != '1')
			return (0);
	return (linecount);
}
