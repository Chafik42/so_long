/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 03:17:59 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/05 21:27:04 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	put_surrounding(t_map mapi, t_img image)
{
	int	i;
	int	a;
	int	b;
	
	a = 32;
	b = 32;
	i = -1;
	image->wall = mlx_xpm_file_to_image(mlx, "rock_owo.xpm", &a, &b);
	while (++i < LONGUEUR) //GAUCHE ET DROITE
	{
		mlx_put_image_to_window(mlx, mlx_win, image->wall, 0, map->py / map->x * i);//cote gauche
		mlx_put_image_to_window(mlx, mlx_win, image->wall, map->px - (map->px / map->y), map->py / map->x * i);//cote droit
	}

	int	j;

	j = -1;
	while (++j < LARGEUR) //HAUT ET BAS 
	{
		mlx_put_image_to_window(mlx, mlx_win, image->wall, map->px / map->y * j, 0);
		mlx_put_image_to_window(mlx, mlx_win, image->wall, map->px / map->y * j, map->py - (map->py / map->x));
	}
}

void	init_img(t_map map, t_img image)
{
	int	a;
	int	b;

	a = 32;
	b = 32;
	image->mlx = mlx_init();
	image->window = = mlx_new_window(mlx, map->px, map->py, "So_long");
	image->bg = mlx_xpm_file_to_image(mlx, "backgrounddirt.xpm", &a, &b);
	mlx_put_image_to_window(mlx, mlx_win, image->bg, 0, 0);
	put_surrounding(map, image);
}

