/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:17:14 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/11 01:38:29 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	*check(int ac, char **av, t_map *map)
{
	int	fd;
	int	*tab;

	fd = 0;
	if (ac != 2)
		return (0);
	if (!ft_checkfile(av[1]))
	{
		printf("Error\n");
		return (0);
	}
	map->len = get_len(fd, av[1], map);
	map->size = get_size(fd, av[1]);
	tab = oned_map(fd, map->len, av[1]);
	if (!tab)
		return (0);
	fd = open(av[1], O_RDONLY);
	map->y = parse_ber(map, -1, 0, fd);
	if (map->y < 3)
	{
		free(tab);
		return (0);
	}
	return (tab);
}

int	create_body(t_body *body, int ac, char **av)
{
	body->map = init_map();
	body->map->tab = check(ac, av, body->map);
	if (!body->map->tab)
	{
		free(body->map);
		free(body);
		return (0);
	}
	if (!check_object(body->map))
	{
		free(body->map->tab);
		free(body->map);
		free(body);
		printf("Error\n");
		return (0);
	}
	body->user = init_player(body->map, body->map->tab, body->map->x);
	if (!body->user)
		return (0);
	body->image = put_game(body->map->tab, body->map);
	if (!body->image)
		return (0);
	body->end = 0;
	return (1);
}

void	destroy_body(t_body *body)
{
	free(body->user);
	free(body->map->tab);
	free(body->map);
	mlx_destroy_image(body->image->mlx, body->image->bg);
	mlx_destroy_image(body->image->mlx, body->image->wall);
	mlx_destroy_image(body->image->mlx, body->image->player);
	mlx_destroy_image(body->image->mlx, body->image->player2);
	mlx_destroy_image(body->image->mlx, body->image->player3);
	mlx_destroy_image(body->image->mlx, body->image->player4);
	mlx_destroy_image(body->image->mlx, body->image->exit1);
	mlx_destroy_image(body->image->mlx, body->image->col);
}

int	quit(t_body *body)
{
	body->end = 1;
	return (0);
}

int	main(int ac, char **av)
{
	t_body	*body;

	body = (t_body *)malloc(sizeof(t_body));
	if (!body)
		return (0);
	body->p = 1;
	if (!create_body(body, ac, av))
		return (0);
	mlx_loop_hook(body->image->mlx, &voidloop, body);
	mlx_hook(body->image->window, 17, (1L << 17), &quit, body);
	mlx_key_hook(body->image->window, &key_handle, body);
	mlx_loop(body->image->mlx);
	destroy_body(body);
	mlx_destroy_display(body->image->mlx);
	free(body->image->mlx);
	free(body->image);
	free(body);
	return (0);
}
