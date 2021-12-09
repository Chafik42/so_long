/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:27:30 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/09 05:34:16 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_player	*init_player(t_map *map, int *tab, int c)
{
	t_player	*user;
	int			i;

	i = 0;
	user = (t_player *)malloc(sizeof(t_player));
	if (!user)
		return (NULL);
	while (tab[i] != 'P')
		i++;
	user->y = i / c * map->py;
	user->x = i % c * map->px;
	user->pos = i;
	user->c = 0;
	user->moves = 0;
	return (user);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->x = 0;
	map->y = 0;
	map->px = 64;
	map->py = 64;
	map->cmax = 0;
	map->pmax = 0;
	map->emax = 0;
	return (map);
}
