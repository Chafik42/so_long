/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:59:20 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/12 00:40:25 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	putnbstr(char *str, long n, int i)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	i--;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int			i;
	long		nbr;
	char		*str;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1) + (n == 0));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[i] = '\0';
	putnbstr(str, (long)n, i);
	return (str);
}

void	player_animation(t_body *body)
{
	int		userx;
	int		usery;
	void	*mlx;
	void	*win;

	mlx = body->image->mlx;
	win = body->image->window;
	userx = body->user->pos % body->map->x * body->map->px;
	usery = body->user->pos / body->map->x * body->map->py;
	if (body->p)
	{
		mlx_put_image_to_window(mlx, win, body->image->player, userx, usery);
		mlx_put_image_to_window(mlx, win, body->image->player2, userx, usery);
		mlx_put_image_to_window(mlx, win, body->image->player3, userx, usery);
		mlx_put_image_to_window(mlx, win, body->image->player4, userx, usery);
	}
}

void	count_move(t_body *body, void *mlx, void *win)
{
	char	*count;

	count = ft_itoa(body->user->moves);
	mlx_string_put(mlx, win, 10, 10, RED, "MOVES");
	mlx_string_put(mlx, win, 25, 25, RED, count);
	free(count);
}
