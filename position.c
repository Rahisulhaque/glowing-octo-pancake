/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhaque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:12:58 by rhaque            #+#    #+#             */
/*   Updated: 2017/09/20 16:13:00 by rhaque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**upper_position(int row_min, char **grid)
{
	int row;

	row = 0;
	while (row + row_min < 4)
	{
		grid[row] = grid[row + row_min];
		row++;
	}
	while (row < 4 && row_min > 0)
	{
		grid[row] = "....\0";
		row++;
	}
	return (grid);
}

static char		**left_position(int col_min, char **grid)
{
	int tmp;
	int row;
	int col;

	tmp = 0;
	row = 0;
	col = 0;
	while (row < 4)
	{
		while (grid[row][col + col_min] != '\0')
		{
			grid[row][col] = grid[row][col + col_min];
			col++;
		}
		tmp = col_min;
		while (tmp > 0)
		{
			grid[row][4 - tmp] = '.';
			tmp--;
		}
		col = 0;
		row++;
	}
	return (grid);
}

static int		get_y_min(char **grid)
{
	int x;
	int y;
	int y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (grid[x][y] != '#' && grid[x][y] != '\0')
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

static int		get_x_min(char **grid)
{
	int x;
	int y;
	int x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (grid[x][y] != '#' && grid[x][y] != '\0')
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

t_shape			*position_arrange(t_shape *start)
{
	t_shape *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->shape = left_position(get_x_min(tmp->shape),\
				tmp->shape);
		tmp->shape = upper_position(get_y_min(tmp->shape), tmp->shape);
		tmp = tmp->next;
	}
	return (start);
}
