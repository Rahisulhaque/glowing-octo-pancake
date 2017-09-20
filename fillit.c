

#include "fillit.h"

static int		test_position(t_shape *start, char **grid, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->shape[i][j] == '#' && (start->x + j >= square_size \
						|| start->y + i >= square_size))
				return (0);
			if (start->shape[i][j] == '#' && \
					ft_isalpha(grid[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static char		**placement(t_shape *start, char **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->shape[i][j] == '#')
				grid[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (grid);
}

static char		**remove_shape(t_shape *start, char **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (grid[i] != NULL)
	{
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == start->letter)
				grid[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (grid);
}

int				valid_solution(t_shape *start, int square_size, char **grid)
{
	if (start != NULL)
	{
		while (start->y * start->x < square_size * square_size)
		{
			if ((test_position(start, grid, square_size)) == 1)
			{
				grid = placement(start, grid);
				if (valid_solution(start->next, square_size, grid) == 1)
					return (1);
				grid = remove_shape(start, grid);
			}
			if (start->x < square_size)
				start->x++;
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}

char			**solve(t_shape *start, int square_size, char **sol_grid)
{
	position_arrange(start);
	sol_grid = create_grid(sol_grid, square_size);
	while (valid_solution(start, square_size, sol_grid) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		free_grid(sol_grid, square_size);
		sol_grid = create_grid(sol_grid, square_size);
	}
	return (sol_grid);
}
