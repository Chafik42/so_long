/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:04 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/07 18:05:15 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

void    put_surrounding(t_img *img, t_map *map, int x, int y)
{
	int     i;
	int     a;
	int     b;

	a = 0;
	b = 0;
	i = -1;
	img->wall = mlx_xpm_file_to_image(img->mlx, "image/map-32.xpm", &a, &b);
	img->bg = mlx_xpm_file_to_image(img->mlx, "image/map2-32.xpm", &a, &b);
	img->player1 = mlx_xpm_file_to_image(img->mlx, "image/tear.xpm", &a, &b);
	while (++i < y) //GAUCHE ET DROITE
	{
		mlx_put_image_to_window(img->mlx, img->window, img->wall, 0, map->px * i);//cote gauche
		mlx_put_image_to_window(img->mlx, img->window, img->wall, (x - 1) * map->px, map->px * i);//cote droit
	}
	int     j;

	j = -1;
	while (++j < x) //HAUT ET BAS
	{
		mlx_put_image_to_window(img->mlx, img->window, img->wall, map->px * j, 0);
		mlx_put_image_to_window(img->mlx, img->window, img->wall, map->px * j, (y - 1) * map->px);
	}
	int	f;
	int	g;

	f = 1;
	while (f < x - 1)
	{
		g = 1;
		while (g < y - 1)
		{
			mlx_put_image_to_window(img->mlx, img->window, img->bg, map->px * f, map->px * g);
			g++;
		}
		f++;
	}
	mlx_put_image_to_window(img->mlx, img->window, img->player1, map->px * (x / 2), map->px * (y / 2));
}

void	init_img(t_map *map, t_img *image)
{
	int     a;
	int     b;
	//t_img	*image;
	
	a = 96;
	b = 96;
	//image = (t_img *)malloc(sizeof(t_img));
	image->mlx = mlx_init();
	image->window = mlx_new_window(image->mlx, map->x * map->px, map->y * map->py, "So_long");
	//put_surrounding(image, map, map->x, map->y);
	//return (image);
}
