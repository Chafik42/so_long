/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:17:20 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/06 13:32:03 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void    put_surrounding(t_img img, t_map map, int x, int y)
{
	int     i;
	int     a;
	int     b;
	int        pix = 32;

	a = 0;
	b = 0;
	i = -1;
	void *wall = mlx_xpm_file_to_image(img.mlx, "../img/map-32.xpm", &a, &b);
	void    *bg = mlx_xpm_file_to_image(img.mlx, "../img/map2-32.xpm", &a, &b);
	while (++i < y) //GAUCHE ET DROITE
	{
		mlx_put_image_to_window(img.mlx, img.window, wall, 0, pix * i);//cote gauche
		mlx_put_image_to_window(img.mlx, img.window, wall, (x - 1) * pix, pix * i);//cote droit
	}
	int     j;

	j = -1;
	while (++j < x) //HAUT ET BAS
	{
		mlx_put_image_to_window(img.mlx, img.window, wall, pix * j, 0);
		mlx_put_image_to_window(img.mlx, img.window, wall, pix * j, (y - 1) * pix);
	}
	int    f;
	int    g;

	f = 1;
	while (f < x - 1)
	{
		g = 1;
		while (g < y - 1)
		{
			mlx_put_image_to_window(img.mlx, img.window, bg, pix * f, pix * g);
			g++;
		}
		f++;
	}
}

void    init_img(t_map map, t_img image)
{
	int     a;
	int     b;

	a = 96;
	b = 96;

	image.mlx = mlx_init();
	image.window = mlx_new_window(image.mlx, map.x * map.px, map.y * map.py, "So_long");
	put_surrounding(image, map, map.x, map.y);
	mlx_loop(image.mlx);
}

#include <stdlib.h>
int    main(int ac, char **av)
{
	/*if (ac != 2)
	  {
	  write(1, "Input Error", 11);
	  return (0);
	  }*/
	/*if (ft_checkfile(av[1]) == 0)
	  {
	  printf("(Input Errror : File is not a .ber)\n");
	  return (0);
	  }*/
	t_map    map;
	t_img    image;

	map.x = atoi(av[1]);
	map.y = atoi(av[2]);
	map.px = atoi(av[3]);
	map.py = atoi(av[4]);
	init_img(map, image);
}
