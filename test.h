/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:32 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/08 00:20:11 by anremiki         ###   ########.fr       */
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

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

typedef struct	s_player
{
	int	x;
	int	y;
	int	pos;
	int	input;
	//int	enemy_x;
	//int	enemy_y;
	//int	enemy_pos;
	int	C;
	int	moves;
	int	*Cpos;
	int	*Epos;
}				t_player;

typedef struct	s_map
{
	int	x;
	int	y;
	int	px;
	int	py;
	int	Cmax;
	int	Pmax;
	int	Emax;
	int	len;
	int	*tab;
	//t_player	user;
}				t_map;

typedef struct    s_entities
{
    int    *Ctab;
    int    *Ptab;
    int    *Etab;
    int    *Otab;
    int    *Ztab;
}                t_entities;

typedef struct	s_img
{
	void	*mlx;
	void	*window;
	void	*start;
	void	*win;
	void	*lose;
	void	*bg;
	void	*wall;
	void	*player1;
	void	*player2;
	void	*enemy1;
	void	*enemy2;
	void	*exit1;
	void	*exit2;
	void	*col;
}				t_img;

typedef struct s_body
{
	t_img	*image;
	t_map	*map;
	t_player *user;
}				t_body;

t_map		*init_map(void); // Initialise les valeur de la struct map et user.
t_player	*init_player(t_map *map, int *tab, int c);
void		init_img(t_map *map, t_img *image); // Place les images au coordonnees de chaque variable.
t_img		*put_game(int *tab, t_map *map, int c);
void		put_entities(int tab, t_img *image, t_map *map, int i);
int			parse_ber(t_map *map, int i, int linecount, int fd);
int			get_len(int fd, char *str, t_map *map);
int			*oned_map(int fd, int len, char *str);
int			ft_checkfile(char *filename);
int			voidloop(void *data);
int			check_valid(int decalage, t_map *map, t_player *user, int max);
int			move_player(int decalage, t_map *map, t_player *user, t_img *image);
int			key_handle(int keycode, t_body *body);

#endif
