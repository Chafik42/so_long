/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:08:50 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/08 00:15:19 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

t_img	*put_game(int *tab, t_map *map, int c)
{
	int	b;
	int	a;
	int	i;
	t_img	*image;

	i = -1;
	image = (t_img *)malloc(sizeof(t_img));
	image->mlx = mlx_init();
	image->window = mlx_new_window(image->mlx, map->x * map->px, map->y * map->py, "So_long");
	image->player1 = mlx_xpm_file_to_image(image->mlx, "image/tear-32.xpm", &a, &b);
	image->wall = mlx_xpm_file_to_image(image->mlx, "image/map2-32.xpm", &a, &b);
	image->bg = mlx_xpm_file_to_image(image->mlx, "image/map-32.xpm", &a, &b);
	image->col = mlx_xpm_file_to_image(image->mlx, "image/coin-32.xpm", &a, &b);
	image->exit1 = mlx_xpm_file_to_image(image->mlx, "image/exit-32.xpm", &a, &b);
	while (tab[++i])
		put_entities(tab[i], image, map, i);
	return (image);
}

void	put_entities(int tab, t_img *image, t_map *map, int i)
{
	if (tab == '0')
		mlx_put_image_to_window(image->mlx, image->window, image->bg, (i % map->x) * map->px, (i / map->x) * map->py);
	else if (tab == '1')
		mlx_put_image_to_window(image->mlx, image->window, image->wall, (i % map->x) * map->px, (i / map->x) * map->py);
	else if (tab == 'C')
	{
		mlx_put_image_to_window(image->mlx, image->window, image->col, (i % map->x) * map->px, (i / map->x) * map->py);
		map->Cmax++;
	}
	else if (tab == 'P')
	{
		mlx_put_image_to_window(image->mlx, image->window, image->player1, (i % map->x) * map->px, (i / map->x) * map->py);
		map->Pmax++;
	}
	else if (tab == 'E')
	{
		mlx_put_image_to_window(image->mlx, image->window, image->exit1, (i % map->x) * map->px, (i / map->x) * map->py);
		map->Emax++;
	}
}
