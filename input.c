/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:44:17 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/08 00:34:07 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	voidloop(void *data)
{
	return (0);
}

int	check_valid(int decalage, t_map *map, t_player *user, int max)
{
//	printf("ma pos = %d, decalage = %d\n", user->pos, decalage);
	if (user->pos + decalage < 0 || user->pos + decalage >= map->x * map->y)
		return (0);
	if (map->tab[user->pos + decalage] == '1')
		return (0);
	if (map->tab[user->pos + decalage] == 69 && user->C != max)
		return (0);
	printf("pos = %d > decalage = %d, tab[pos] = %c, tab[pos + decal] = %c\n", user->pos, decalage, map->tab[user->pos], map->tab[user->pos + decalage]);
	return (1);
}

int	move_player(int decalage, t_map *map, t_player *user, t_img *image)
{
	//printf("MOVE\n");
	if (map->tab[user->pos + decalage] == 'C')
		user->C++;
	if (map->tab[user->pos + decalage] == 'E' && user->C == map->Cmax)
		mlx_destroy_window(image->mlx, image->window);
	map->tab[user->pos + decalage] = 'P';
	map->tab[user->pos] = 0;
	user->pos += decalage;
	printf("test x = %d >>> test y = %d\n", user->pos % map->x * map->px, user->y / map->x * map->py);
//	mlx_put_image_to_window(image->mlx, image->window, image->player1, user->x * map->px, user->y * map->py);
	mlx_put_image_to_window(image->mlx, image->window, image->player1, user->pos % map->x * map->px, user->pos / map->x * map->py);
//	mlx_put_image_to_window(image->mlx, image->window, image->bg, (user->x - decalage) * map->px, (user->y - decalage) * map->py);
	mlx_put_image_to_window(image->mlx, image->window, image->bg, (user->pos - decalage) % map->x * map->px, (user->pos - decalage) / map->x * map->py);
}

int	key_handle(int keycode, t_body *body)
{
	if (keycode == UP)
	{
		if (check_valid(0 - body->map->x, body->map, body->user, body->map->Cmax))
		{
			move_player(0 - body->map->x, body->map, body->user, body->image);
			printf("UP\n");
		}
		else
			printf("UPn\n");
	}
	if (keycode == DOWN)
	{
		if (check_valid(body->map->x, body->map, body->user, body->map->Cmax))
		{
			move_player(body->map->x, body->map, body->user, body->image);
			printf("DOWN\n");
		}
		else
			printf("DOWNn\n");
	}
	if (keycode == LEFT)
	{
		if (check_valid(-1, body->map, body->user, body->map->Cmax))
		{
			move_player(-1, body->map, body->user, body->image);
			printf("LEFT\n");
		}
		else
			printf("LEFTn\n");
	}
	if (keycode == RIGHT)
	{
		if (check_valid(1, body->map, body->user, body->map->Cmax))
		{
			move_player(1, body->map, body->user, body->image);
			printf("RIGHT\n");
		}
		else
			printf("RIGHTn\n");
	}
	if (keycode == ESC)
	{
		mlx_destroy_window(body->image->mlx, body->image->window);
	}
	return (1);
}
