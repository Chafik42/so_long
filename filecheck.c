/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:14:42 by cmarouf           #+#    #+#             */
/*   Updated: 2021/12/07 20:16:35 by cmarouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
