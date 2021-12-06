/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:32 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/05 00:32:19 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_img
{
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*player;
	void	*background;
}						t_img;

typedef struct s_map
{
	int	x;
	int	y;
}					t_map;

int	ft_checkfile(char *filename);

#endif

