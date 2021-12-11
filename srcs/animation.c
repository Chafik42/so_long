/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 01:49:16 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/12 00:34:01 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	get_firstpos(t_body *body, int *tab)
{
	int	i;

	i = 0;
	while (i < body->map->len)
	{
		if (tab[i] == 'E')
		{
			tab[i] = '0';
			return (i);
		}
		i++;
	}
	return (0);
}

void	put_back(t_body *body, int *tab, int movex, int movey)
{
	void	*mlx;
	void	*win;

	win = body->image->window;
	mlx = body->image->mlx;
	if (tab[body->nuagepos - 1] == '1')
		mlx_put_image_to_window(mlx, win, body->image->wall, movex, movey);
	if (tab[body->nuagepos - 1] == 'C')
		mlx_put_image_to_window(mlx, win, body->image->col, movex, movey);
	else if (tab[body->nuagepos - 1] == '0' || tab[body->nuagepos - 1] == 'P')
		mlx_put_image_to_window(mlx, win, body->image->bg, movex, movey);
}

void	move(t_body *body, int *tab, int decalage, void *win)
{
	int		nuagex;
	int		nuagey;
	int		movex;
	int		movey;
	void	*mlx;

	mlx = body->image->mlx;
	body->nuagepos++;
	nuagex = body->nuagepos % body->map->x * body->map->px;
	nuagey = body->nuagepos / body->map->x * body->map->py;
	movex = (body->nuagepos - decalage) % body->map->x * body->map->px;
	movey = (body->nuagepos - decalage) / body->map->x * body->map->py;
	if (tab[body->nuagepos] == '1' && body->nuagepos != body->map->len - 1)
		mlx_put_image_to_window(mlx, win, body->image->exit2, nuagex, nuagey);
	if (tab[body->nuagepos] == 'C')
		mlx_put_image_to_window(mlx, win, body->image->exit3, nuagex, nuagey);
	else if (tab[body->nuagepos] == '0' || tab[body->nuagepos] == 'P')
		mlx_put_image_to_window(mlx, win, body->image->exit1, nuagex, nuagey);
	else if (tab[body->nuagepos] == 'E')
		put_back(body, tab, movex, movey);
	put_back(body, tab, movex, movey);
	if (body->nuagepos == body->map->len - 1)
		body->nuagepos = 0;
}

void	init_cloud(t_body *body, int *tab, void *mlx, void *win)
{
	int		posx;
	int		posy;

	posx = (body->map->x - 1) * 64;
	posy = (body->map->y - 1) * 64 - 64;
	mlx_put_image_to_window(mlx, win, body->image->wall, posx, posy);
	move(body, tab, 1, win);
}

void	bonus(t_body *body, void *mlx, void *win, int *tab)
{
	int	midx;
	int	midy;

	midx = body->map->x * body->map->px / 2;
	midy = body->map->y * body->map->px / 2;
	if (body->nuagepos == -1)
		body->nuagepos = get_firstpos(body, tab);
	if (tab[body->nuagepos] == 'P' && body->user->c < body->map->cmax)
	{
		mlx_clear_window(mlx, win);
		mlx_string_put(mlx, win, midx, midy, RED, "GAMEOVER");
		body->end = 1;
		return ;
	}
	if (tab[body->nuagepos] == 'P' && body->user->c == body->map->cmax)
	{
		mlx_clear_window(mlx, body->image->window);
		mlx_string_put(mlx, win, midx, midy, GREEN, "YOU WIN");
		body->end = 1;
		return ;
	}
	usleep(100000);
	init_cloud(body, tab, mlx, win);
}
