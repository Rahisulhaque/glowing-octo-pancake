

#include "fillit.h"

int		check_character(char *grid)
{
	int row;
	int hash;
	int dot;
	int endl;

	row = 0;
	hash = 0;
	dot = 0;
	endl = 0;
	while (grid[row] != '\0')
	{
		if (grid[row] == '#')
			hash++;
		if (grid[row] == '.')
			dot++;
		if (grid[row] == '\n')
			endl++;
		if (grid[row] != '#' && grid[row] != '.' && grid[row] != '\n')
			return (0);
		row++;
	}
	if (hash != 4 || dot != 12 || endl != 4)
		return (0);
	return (1);
}

int		check_line(char *grid)
{
	int row;
	int count;
	int next_line;

	row = 0;
	count = 0;
	next_line = 4;
	while (grid[row] != '\0')
	{
		if (grid[row] == '.' || grid[row] == '#')
			count++;
		if (count > 4)
			return (0);
		if (grid[row] == '\n' && row == next_line)
		{
			count = 0;
			next_line += 5;
		}
		row++;
	}
	return (1);
}

int		is_alone(char *grid)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '#')
		{
			if (grid[i + 1] == '#' || grid[i - 1] == '#'
					|| grid[i + 5] == '#' || grid[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_grid(char **grid)
{
	int i;

	i = 0;
	if (grid[0] == NULL)
		return (0);
	while (i < g_num_shapes)
	{
		if (check_character(grid[i]) != 1)
			return (0);
		if (check_line(grid[i]) != 1)
			return (0);
		if (check_shape(grid[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int		first_test(char *grid)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (grid[x] != '\0')
	{
		if (grid[x] == '\n')
			y++;
		if (y == 4)
		{
			if (grid[x + 1] != '\n' && grid[x + 1] != '\0')
				return (0);
			if (grid[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
