/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:26:16 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/07 22:54:27 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	handle_no_event(t_img *img)
{
	return (0);
}

int	key_test(int keycode, t_img *img)
{
	if (keycode == UP) 
		printf("UP\n");
	else if (keycode == DOWN) 
		printf("DOWN\n");
	else if (keycode == LEFT) 
		printf("LEFT\n");
	else if (keycode == RIGHT) 
		printf("RIGHT\n");
	else if (keycode == ESC)
		printf("ESC\n");
	else
		printf("L2P\n");
	return (0);
}

int main(int ac, char **av)
{
	t_map		*map;
	t_player	*user;
	t_img		img;

	int a;
	int b;
	//if (ac != 5)
	//	return (0);
	img.mlx = mlx_init();
	img.window = mlx_new_window(img.mlx, 38 * 32, 20 * 32, "test fenetre");
	img.player1 = mlx_xpm_file_to_image(img.mlx, "image/tear.xpm", &a, &b);
	mlx_loop_hook(img.mlx, &handle_no_event, &img);
	mlx_key_hook(img.win, key_test, &img);
	mlx_loop(img.mlx);
}
