/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:14:42 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/05 00:53:49 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_checkfile(char *filename)
{
	int	index;

	index = ft_strlen(filename);
	if (filename[index - 1] == '\\' || filename[index - 1] == '/')
		return (0);
	if (filename[index - 1] != 'r')
		return (0);
	if (filename[index - 2] != 'e')
		return (0);
	if (filename[index - 3] != 'b')
		return (0);
	if (filename[index - 4] != '.')
		return (0);
	return (1);
}
