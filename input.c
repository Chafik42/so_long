/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:44:17 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/10 18:19:52 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	animation(t_body *body, int userx, int usery)
{
	int	 a;
	int  b;
	t_img img;

	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, body->map->x * body->map->px, body->map->y * body->map->py, "So_long");
	img.player = mlx_xpm_file_to_image(img.mlx, "img/Goku1.xpm", &a, &b);
	img.player2 = mlx_xpm_file_to_image(img.mlx, "img/Goku2.xpm", &a, &b);

	mlx_put_image_to_window(img.mlx, img.window, img.player, userx, usery);
	mlx_put_image_to_window(img.mlx, img.window, img.player2, userx, usery);
	//mlx_put_image_to_window(img->mlx, img->window, img->player3, userx, usery);
	//mlx_put_image_to_window(img->mlx, img->window, img->player4, userx, usery);
}

int	voidloop(t_body *body)
{
	int	userx;
	int	usery;
	if (body->end == 1)
	{
		mlx_destroy_window(body->image->mlx, body->image->window);
		return (0);
	}
	userx = body->user->pos % body->map->x * body->map->px;
	usery = body->user->pos / body->map->x * body->map->py;
	//mlx_get_data_addr(body->image->player, body)
	animation(body, userx, usery);
	return (0);
}

int	check_valid(int decalage, t_map *map, t_player *user, int max)
{
	if (user->pos + decalage < 0 || user->pos + decalage >= map->x * map->y)
		return (0);
	if (map->tab[user->pos + decalage] == '1')
		return (0);
	if (map->tab[user->pos + decalage] == 69 && user->c != max)
		return (0);
	return (1);
}

int	move_player(int decalage, t_map *map, t_player *user, t_img *img)
{
	int	userx;
	int	usery;
	int	movex;
	int	movey;

	if (map->tab[user->pos + decalage] == 'C')
		user->c++;
	if (map->tab[user->pos + decalage] == 'E' && user->c == map->cmax)
		return (42);
	map->tab[user->pos + decalage] = 'P';
	map->tab[user->pos] = 0;
	user->pos += decalage;
	userx = user->pos % map->x * map->px;
	usery = user->pos / map->x * map->py;
	movex = (user->pos - decalage) % map->x * map->px;
	movey = (user->pos - decalage) / map->x * map->py;
	mlx_put_image_to_window(img->mlx, img->window, img->player, userx, usery);
	mlx_put_image_to_window(img->mlx, img->window, img->bg, movex, movey);
	return (0);
}

int	key_handle(int keycode, t_body *body)
{
	int	i;

	i = 0;
	if (keycode == UP)
		if (check_valid(-body->map->x, body->map, body->user, body->map->cmax))
			i = move_player(-body->map->x, body->map, body->user, body->image);
	if (keycode == DOWN)
		if (check_valid(body->map->x, body->map, body->user, body->map->cmax))
			i = move_player(body->map->x, body->map, body->user, body->image);
	if (keycode == LEFT)
		if (check_valid(-1, body->map, body->user, body->map->cmax))
			i = move_player(-1, body->map, body->user, body->image);
	if (keycode == RIGHT)
		if (check_valid(1, body->map, body->user, body->map->cmax))
			i = move_player(1, body->map, body->user, body->image);
	if (keycode == ESC || i == 42)
		mlx_destroy_window(body->image->mlx, body->image->window);
	return (65);
}
