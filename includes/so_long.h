/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:32 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/12 21:40:28 by cmarouf          ###   ########.fr       */
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
# include "../minilibx/mlx.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define GREEN 0x22780f
# define RED 0xff0000

typedef struct s_player
{
	int	x;
	int	y;
	int	pos;
	int	input;
	int	c;
	int	moves;
}				t_player;

typedef struct s_map
{
	int	x;
	int	y;
	int	px;
	int	py;
	int	cmax;
	int	pmax;
	int	emax;
	int	len;
	int	size;
	int	*tab;
}				t_map;

typedef struct s_nuage
{
	int	pos;
}				t_nuage;

typedef struct s_img
{
	void	*mlx;
	void	*window;
	void	*start;
	void	*win;
	void	*lose;
	void	*bg;
	void	*wall;
	void	*player;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*player5;
	void	*enemy1;
	void	*enemy2;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*col;
}				t_img;

typedef struct s_body
{
	t_img		*image;
	t_map		*map;
	t_player	*user;
	int			end;
	int			p;
	int			nuagepos;
}				t_body;

t_map		*init_map(void);
t_player	*init_player(t_map *map, int *tab, int c);
void		init_img(t_map *map, t_img *image);
t_img		*put_game(int *tab, t_map *map);
void		put_entities(int tab, t_img *image, t_map *map, int i);
int			parse_ber(t_map *map, int i, int linecount, int fd);
int			get_len(int fd, char *str, t_map *map);
int			get_size(int fd, char *str);
int			*oned_map(int fd, int len, char *str);
int			ft_checkfile(char *filename);
int			voidloop(t_body *body);
int			check_valid(int decalage, t_map *map, t_player *user, int max);
int			move_player(int decalage, t_map *map, t_player *user, t_img *image);
int			key_handle(int keycode, t_body *body);
int			check_object(t_map *map);
void		destroy_body(t_body *body);
void		player_animation(t_body *body);
void		bonus(t_body *body, void *mlx, void *win, int *tab);
void		count_move(t_body *body, void *mlx, void *win);
int			ft_error(char *str);
int			*ft_error2(char *str);

#endif
