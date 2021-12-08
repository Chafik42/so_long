/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:43:51 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/08 17:41:36 by cmarouf          ###   ########.fr       */
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

int	check_last_line(char *str, int i)
{
	while (str[--i] != '\n')
	{
		if (str[i] != '1')
			return (0);
	}
	return (1);
}

int	parse_ber(t_map *map, int i, int linecount, int fd)
{
	char	*str;

	str = malloc(sizeof(char) * (map->size) + 1);
	if (!str)
		return (0);
	read(fd, str, map->size);
	while (str[++i])
	{
		if (str[i] != '1' && linecount == 0 && i != map->x)
			return (0);
		if (i && str[i - 1] == '\n' && str[i] != '1')
			return (0);
		if (i && linecount)
			if (str[i] == '\n' && str[i - 1] != '1')
				return (0);
		if (str[i] == '\n' && (i - linecount) % map->x == 0)
			linecount++;
		if (!valid_item("01CPE\n", str[i]))
			return (0);
	}
	if (((map->x * (linecount) + linecount)) != i)
		return (0);
	if (!check_last_line(str, i - 1))
		return (0);
	return (linecount);
}
