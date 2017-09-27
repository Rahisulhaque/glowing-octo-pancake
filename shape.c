/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhaque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:11:45 by rhaque            #+#    #+#             */
/*   Updated: 2017/09/20 16:11:49 by rhaque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_num_shapes(char *block)
{
	int i;
	int nb_shapes;

	i = 0;
	nb_shapes = 0;
	while (block[i] != '\0')
	{
		if (block[i] == '\n' && (block[i + 1] == '\n' || block[i + 1] == '\0'))
			nb_shapes++;
		i++;
	}
	return (nb_shapes);
}

int				width_grid(char *grid)
{
	int row;
	int width;
	int line;

	row = 0;
	width = 0;
	line = 0;
	while (row < 4)
	{
		if (grid[row] == '#' || grid[row + 5] == '#' ||
				grid[row + 10] == '#' || grid[row + 15] == '#')
		{
			width++;
			if (line > 0)
				return (0);
		}
		else if (width > 0)
			line++;
		row++;
	}
	return (width);
}

int				height_grid(char *grid)
{
	int i;
	int height;
	int line;

	i = 0;
	height = 0;
	line = 0;
	while (i < 19)
	{
		if (grid[i] == '#' || grid[i + 1] == '#' || grid[i + 2] == '#' ||\
				grid[i + 3] == '#')
		{
			height++;
			if (line > 0)
				return (0);
		}
		else if (height > 0)
			line++;
		i = i + 5;
	}
	return (height);
}

int				check_void_int(char *grid)
{
	int i;
	int h;
	int v;

	v = 0;
	i = 0;
	h = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '#')
			h++;
		if (h == 2 && grid[i] == '#')
		{
			while (grid[i + 1 + v] != '#' && grid[i + v] != '\0')
				v++;
			if (v > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

int				check_shape(char *grid)
{
	int height;
	int width;

	height = height_grid(grid);
	width = width_grid(grid);
	if (is_alone(grid) == 0)
		return (0);
	if (check_void_int(grid) == 0 || width == 0 || height == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if (height == 2 && width == 3)
		return (1);
	else if (height == 3 && width == 2)
		return (1);
	else if (height == 1 && width == 4)
		return (1);
	else if (height == 4 && width == 1)
		return (1);
	else
		return (0);
}
