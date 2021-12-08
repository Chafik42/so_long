/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:08:50 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/08 17:25:22 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

t_img	*put_game(int *tab, t_map *map, int c)
{
	int		b;
	int		a;
	int		i;
	int		xpos;
	t_img	*img;

	xpos = map->x * map->px;
	i = -1;
	img = (t_img *)malloc(sizeof(t_img));
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, xpos, map->y * map->py, "So_long");
	img->player = mlx_xpm_file_to_image(img->mlx, "img/tear-32.xpm", &a, &b);
	img->wall = mlx_xpm_file_to_image(img->mlx, "img/map2-32.xpm", &a, &b);
	img->bg = mlx_xpm_file_to_image(img->mlx, "img/map-32.xpm", &a, &b);
	img->col = mlx_xpm_file_to_image(img->mlx, "img/coin-32.xpm", &a, &b);
	img->exit1 = mlx_xpm_file_to_image(img->mlx, "img/exit-32.xpm", &a, &b);
	while (tab[++i])
		put_entities(tab[i], img, map, i);
	return (img);
}

void	put_entities(int tab, t_img *img, t_map *map, int i)
{
	int	xpos;
	int	ypos;

	xpos = ((i % map->x) * map->px);
	ypos = ((i / map->x) * map->py);
	if (tab == '0')
		mlx_put_image_to_window(img->mlx, img->window, img->bg, xpos, ypos);
	else if (tab == '1')
		mlx_put_image_to_window(img->mlx, img->window, img->wall, xpos, ypos);
	else if (tab == 'C')
	{
		mlx_put_image_to_window(img->mlx, img->window, img->col, xpos, ypos);
		map->cmax++;
	}
	else if (tab == 'P')
	{
		mlx_put_image_to_window(img->mlx, img->window, img->player, xpos, ypos);
		map->pmax++;
	}
	else if (tab == 'E')
	{
		mlx_put_image_to_window(img->mlx, img->window, img->exit1, xpos, ypos);
		map->emax++;
	}
}
