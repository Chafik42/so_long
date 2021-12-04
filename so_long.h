/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:32 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/04 14:10:34 by cmarouf          ###   ########.fr       */
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

typedef struct s_img
{
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*player_left;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*background;
}						t_img;

typedef struct s_map
{
	int	x;
	int	y;
}					t_map;


#endif

