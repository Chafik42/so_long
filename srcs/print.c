/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:08:50 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/12 00:40:38 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	set_img(t_img *img)
{
	int	a;
	int	b;

	img->player = mlx_xpm_file_to_image(img->mlx, "img/Goku.xpm", &a, &b);
	img->player2 = mlx_xpm_file_to_image(img->mlx, "img/Goku1.xpm", &a, &b);
	img->player3 = mlx_xpm_file_to_image(img->mlx, "img/Goku2.xpm", &a, &b);
	img->player4 = mlx_xpm_file_to_image(img->mlx, "img/Goku3.xpm", &a, &b);
	img->player5 = mlx_xpm_file_to_image(img->mlx, "img/Goku4.xpm", &a, &b);
	img->wall = mlx_xpm_file_to_image(img->mlx, "img/Wall.xpm", &a, &b);
	img->bg = mlx_xpm_file_to_image(img->mlx, "img/bg.xpm", &a, &b);
	img->col = mlx_xpm_file_to_image(img->mlx, "img/DS.xpm", &a, &b);
	img->exit1 = mlx_xpm_file_to_image(img->mlx, "img/KintoUn.xpm", &a, &b);
	img->exit2 = mlx_xpm_file_to_image(img->mlx, "img/KintoUnWall.xpm", &a, &b);
	img->exit3 = mlx_xpm_file_to_image(img->mlx, "img/KintoUnDS.xpm", &a, &b);
}

t_img	*put_game(int *tab, t_map *map)
{
	int		i;
	int		xpos;
	t_img	*img;

	xpos = map->x * map->px;
	i = -1;
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, xpos, map->y * map->py, "So_long");
	set_img(img);
	while (++i < map->len)
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
		mlx_put_image_to_window(img->mlx, img->window, img->col, xpos, ypos);
	else if (tab == 'P')
		mlx_put_image_to_window(img->mlx, img->window, img->player, xpos, ypos);
	else if (tab == 'E')
		mlx_put_image_to_window(img->mlx, img->window, img->exit1, xpos, ypos);
}
