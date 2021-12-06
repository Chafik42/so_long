/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:55:28 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/06 01:15:21 by cmarouf          ###   ########.fr       */
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

void	check_item(char c, t_map map)
{
	if (c == 'C')
		map.Cmax++;
	if (c == 'P')
		map.Pmax++;
	if (c == 'E')
		map.Emax++;
	if (c == '\n')
		map.y++;
}

int	parse_ber(char *str, t_map map)
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
		if (i && map.x && linecount)
			if (i % j == 0 && str[i] != '1')
			{
				//printf("\n\nKO3 %c\n", str[i]);
				return (i);
			}
		if (str[i] == '\n')
			linecount++;
		if (str[i] == '\n' && linecount == 1)
			map.x = i - 1;
		if (str[i] == '\0')
		{
			while (str[--i])
			{
				if (str[i] != '1')
				{

					printf("KO4 - %d\n", i);
					return (0);
				}
				if (i % map.x == 0 && str[i + 1] == '\n')
					return (1);
			}
		}
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
	if (map.Pmax != 1 || map.Cmax < 1 || map.Emax < 1)
	{
		printf("KO7");
		return (0);
	}
	return (1);
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
	t_map map;
	map = init_map();
	i = parse_ber(str, map);
	printf("\033[1;31m");
	printf("%s", str + i);
}
