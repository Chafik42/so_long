/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:02:32 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/05 20:47:42 by cmarouf          ###   ########.fr       */
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

typedef struct	s_player
{
	int	x;
	int	y;
	int	pos;
	int	enemy_x;
	int	enemy_y;
	int	enemy_pos;
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
	t_player	user;
}				t_map;

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

int	ft_checkfile(char *filename);
t_map init_map(t_map map); // Initialise les valeur de la struct map et user.
int	check_parse(char *str, t_map map); //Retourne 1 si la map est bonne, exit si invalide et malloc les tab user.
|-> int	parse_ber(char *str, t_map map);
|->	void	parse_item(char *str, t_player user); //Donne les positions au tableaux correspondant (collectible et exit) et du joueur
void	init_img(t_map map, t_img image); // Place les images au coordonnees de chaque variable.
void	gameplay(t_map map, t_img image);
|->	int	get_userinput(mlx);
|-> int	valid_move(int	input, t_map map); // Verifie AVANT le deplacement du joueur si la case est disponible.
|-> void	move_player(int	input, t_map map, t_img image);
|->	void	check_collectibles(t_map map, t_img image); //Quand un item est ramasser, sa POS devient negatif dans le tableaux, et on change les pixels pour la rendre transparente et donc faire disparaitre l'items.
|-> int	check_enemy(t_map map); // Check si l'on est rentrer en colision avec l'ennemi.
|-> int enemy_turns(t_map map); // Calcule le meilleur mouvement a faire pour se rapprocher du joueur.
|->|-> int valid_move(int	input, t_map map); // On verifie que le move de l'ennemi est valide, sinon on choisi une autre solutions.
|->|-> void	move_enemy(int	input, t_map map, t_img image); // On deplace l'ennemi.
|->|-> int	check_mate(t_map map, t_img image); // Verifie si l'ennemi a tuer le joueur.

#endif

