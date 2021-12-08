/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:55:32 by anremiki          #+#    #+#             */
/*   Updated: 2021/12/07 22:59:23 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_inputt(int keysym, t_data *data)
{
	if (keysym == ESC)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (keysym == UP) 
		printf("UP\n");
	else if (keysym == DOWN) 
		printf("DOWN\n");
	else if (keysym == LEFT) 
		printf("LEFT\n");
	else if (keysym == RIGHT) 
		printf("RIGHT\n");
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1280, 1000,
			"My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (0);
	}

	/* Setup hooks */
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_inputt, &data);

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
