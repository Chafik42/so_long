/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:17:14 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/08 00:19:46 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	*check(int ac, char **av, t_map *map)
{
	int	fd;
	int	*tab;

	if (ac != 2)
		return (0);
	if (!ft_checkfile(av[1]))
		return (0);
	map->len = get_len(fd, av[1], map);
	tab = oned_map(fd, map->len, av[1]);
	fd = open(av[1], O_RDONLY);
	map->y = parse_ber(map, -1, 0, fd);
	if (map->y < 2)
	{
		free(tab);
		return (0);
	}
	map->y++;
	return (tab);
}

int	key_test(int keycode, t_img *img)
{
	if (keycode == UP) 
		printf("UP\n");
	else if (keycode == DOWN) 
		printf("DOWN\n");
	else if (keycode == LEFT) 
		printf("LEFT\n");
	else if (keycode == RIGHT) 
		printf("RIGHT\n");
	else if (keycode == ESC)
		printf("ESC\n");
	else
		printf("L2P\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_body	*body;

	body = (t_body *)malloc(sizeof(t_body));
	body->map = init_map();
	body->map->tab = check(ac, av, body->map);
	if (!body->map->tab)
		return (0);
	body->user = init_player(body->map, body->map->tab, body->map->x);
	if (!body->user)
		return (0);
	body->image = put_game(body->map->tab, body->map, body->map->x);
	if (!body->image)
		return (0);
	mlx_loop_hook(body->image->mlx, &voidloop, body);
	mlx_key_hook(body->image->window, &key_handle, body);
	mlx_loop(body->image->mlx);
	mlx_destroy_display(body->image->mlx);
	free(body->image->mlx);
	return (0);
}
