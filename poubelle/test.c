/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:25:33 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/07 15:32:36 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test(int keycode, t_img *image)
{
	/*
	if (keycode == UP)
		printf("UP\n");
	else if (keycode == DOWN)
		printf("DOWN\n");
	else if (keycode == LEFT)
		printf("LEFT\n");
	else if (keycode == RIGHT)
		printf("RIGHT\n");
	else
		printf("INVALID MOVE\n");*/
	printf("%d\n", keycode);
	return (0);
}

int main(void)
{
	t_img	image;

	int	a;
	int	b;
	image.mlx = mlx_init();
	image.win = mlx_new_window(image.mlx, 38 * 32, 20 * 32, "TEST");
	image.bg = mlx_xpm_file_to_image(image.mlx, "../../img/map2-32.xpm", &a, &b);
	//mlx_put_image_to_window(image.mlx, image.window, image.bg, 70, 70);
	//mlx_mouse_hook(image.win, &test, &image);
	mlx_loop(image.mlx);
}
