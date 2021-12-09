/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:43:51 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/09 14:39:51 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

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

int	check_object(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		if (map->tab[i] == 'C')
			map->cmax++;
		if (map->tab[i] == 'P')
			map->pmax++;
		if (map->tab[i] == 'E')
			map->emax++;
		i++;
	}
	if (map->pmax != 1)
		return (0);
	if (map->cmax < 1)
		return (0);
	if (map->emax < 1)
		return (0);
	return (1);
}

int	parse_loop(t_map *map, int i, int linecount, char *str)
{
	while (str[++i])
	{
		if (str[i] == '\n' && i + 1 == '\0' && linecount < 2)
			return (0);
		if (str[i] != '1' && linecount == 0 && i != map->x)
			return (0);
		if (i)
			if (str[i - 1] == '\n' && str[i] != '1')
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

int	parse_ber(t_map *map, int i, int linecount, int fd)
{
	char	*str;
	int		end;

	str = malloc(sizeof(char) * (map->size) + 1);
	if (!str)
		return (0);
	end = read(fd, str, map->size);
	str[end] = '\0';
	linecount = parse_loop(map, i, linecount, str);
	if (!linecount)
	{
		printf("Error\n");
		free(str);
		return (0);
	}
	if (map->x == linecount)
	{
		printf("Error\n");
		free(str);
		return (0);
	}
	free(str);
	return (linecount);
}
