/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:43:51 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/06 17:05:14 by cmarouf          ###   ########.fr       */
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

void	check_item(char c, t_map *map)
{
	if (c == 'C')
		map->Cmax++;
	if (c == 'P')
		map->Pmax++;
	if (c == 'E')
		map->Emax++;
	if (c == '\n')
		map->y++;
}

int	parse_ber(char *str, t_map *map)
{
	int	i;
	int	j;
	int	linecount;

	i = 0;
	j = 0;
	linecount = 0;
	while (str[j] != '\n')
		j++;
	while (str[i])
	{
		if (str[i] != '1' && linecount == 0 && i != j)
		{
			printf("KO1 - %d\n", i);
			return (0);
		}
		if (i) 
			if (str[i - 1] == '\n' && str[i] != '1')
			{
				printf("KO2 -%d\n", i);
				return (0);
			}
		if (i && map->x && linecount)
			if (str[i] == '\n' && str[i - 1] != '1')
			{
				printf("\n\nKO3 %c\n", str[i]);
				return (i);
			}
		if (str[i] == '\n')
			linecount++;
		if (str[i] == '\n' && linecount == 1)
			map->x = i - 1;
		if (!valid_item("01CPE\n", str[i]))
		{
			printf("KO6 - %d\n", i);
			return (0);
		}
		else
			check_item(str[i], map);
		printf("%c", str[i]);
		i++;
	}
	printf("\n%d > %d > %d\n", map->Pmax, map->Cmax, map->Emax);
	if (map->Pmax != 1 || map->Cmax < 1 || map->Emax < 1)
	{
		printf("KO7");
		return (0);
	}
	i -= 2;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != '1')
		{

			printf("KO4 - %d > %c\n", i, str[i]);
			return (0);
		}
		i--;
	}
	map->x = j;
	map->y = linecount;
	return (j * linecount);
}

void	put_negative(int index, t_entities *entities)
{
	entities->Ctab[index] = -1;
	entities->Ptab[index] = -1;
	entities->Etab[index] = -1;
	entities->Otab[index] = -1;
	entities->Ztab[index] = -1;
}

void	get_value(t_map *map, t_entities *entities, int i, int flag)
{
	put_negative(i, entities);
	if (flag == 0)
		entities->Ztab[i] = i;
	if (flag == 1)
		entities->Otab[i] = i;
	if (flag == 'C')
		entities->Ctab[i] = i;
	if (flag == 'P')
		entities->Ptab[i] = i;
	if (flag == 'E')
		entities->Etab[i] = i;
}

void	parse_data(char *str, t_map *map, t_entities *entities)
{
	int	i;

	i = 0;
	while (str[i])
	{
		get_value(map, entitites, i, str[i]);
		i++;
	}
}

void	init_pos(t_map *map, t_entities *entities)
{
	entities->Ctab = malloc(sizeof(int) * (map->x * map->y));
	entities->Ptab = malloc(sizeof(int) * (map->x * map->y));
	entities->Etab = malloc(sizeof(int) * (map->x * map->y));
	entities->Otab = malloc(sizeof(int) * (map->x * map->y));
	entities->Ztab = malloc(sizeof(int) * (map->x * map->y));
}

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int	main(int ac, char **av)
{
	char	*str;
	int	fd = open(av[1], O_RDONLY);
	int	i;

	i = 0;
	str = malloc(500);
	while (read(fd, str + i, 1) > 0)
		i++;
	printf("%d\n\n", i);
	t_map *map;
	map = init_map();
	str[i] = '\0';
	i = parse_ber(str, map);
	printf("MAP = %d > %d > %d > %d > %d", map->x, map->y, map->Cmax, map->Emax, map->Pmax);
	//	printf("\033[1;31m");
	//	printf("%s", str + i);
}

