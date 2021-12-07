/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:17:07 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/07 18:58:20 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	get_next_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	fd;
	int	*tab;
	int	i;
	int	len;
	char	c;

	len = 0;
	i = 0;
	fd = open("map.ber", O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			continue ;
		len++;
	}
	close(fd);
	fd = open("map.ber", O_RDONLY);
	tab = malloc(sizeof(int) * len);
	while (read(fd, &c, 1) > 0)
	{
		if (c == 0)
			tab[i] = 1;
		else if (c == 1)
			tab[i] = 2;
		else if (c == '\n')
			continue ;
		else
			tab[i] = c;
		i++;
	}
	/////////////////////////////////////////////
	t_map *map;
	t_player *user;
	t_img image;

	map = init_map(tab, len, 13);
	////////////////////////////////////////////
	user = init_player(map, tab, 13);
	////////////////////////////////////////////
	init_img(map, &image);
	///////////////////////////////////////////
	put_game(tab, &image, map, 13);
	i = 0;
	while (tab[i])
	{
		put_entities(tab[i], &image, map, 13, i);
		i++;
	}
	mlx_loop(image.mlx);
	return (0);
}














