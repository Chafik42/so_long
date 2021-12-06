/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:04 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/06 00:27:27 by cmarouf          ###   ########.fr       */
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
	int		pix = 32;

	a = 0;
	b = 0;
	i = -1;
	void *wall = mlx_xpm_file_to_image(mlx, "map-32.xpm", &a, &b);
	void    *bg = mlx_xpm_file_to_image(mlx, "map2-32.xpm", &a, &b);
	while (++i < y) //GAUCHE ET DROITE
	{
		mlx_put_image_to_window(mlx, mlx_win, wall, 0, pix * i);//cote gauche
		mlx_put_image_to_window(mlx, mlx_win, wall, (x - 1) * pix, pix * i);//cote droit
	}
	int     j;

	j = -1;
	while (++j < x) //HAUT ET BAS
	{
		mlx_put_image_to_window(mlx, mlx_win, wall, pix * j, 0);
		mlx_put_image_to_window(mlx, mlx_win, wall, pix * j, (y - 1) * pix);
	}
	int	f;
	int	g;

	f = 1;
	while (f < x - 1)
	{
		g = 1;
		while (g < y - 1)
		{
			mlx_put_image_to_window(mlx, mlx_win, bg, pix * f, pix * g);
			g++;
		}
		f++;
	}
}

void    init_img(void)
{
	int     a;
	int     b;
	
	a = 96;
	b = 96;
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, 32 * 32, 32 * 32, "So_long");
	put_surrounding(mlx, window, 32, 32);
	mlx_loop(mlx);
}

int	main(void)
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
	init_img();
}